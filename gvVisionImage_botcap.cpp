#include "gvVisionImage_botcap.h"
#include "core/gvVisionCCD.h"
#include "gvVisionROI_circle.h"
#include "gvVisionROI_rect.h"
#include<math.h>
gvVisionImage_botcap::gvVisionImage_botcap(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight)
:gvVisionImage(pgvVisionCCD,imageWidth,imageHeight)
{
		m_imgHeight = imageHeight;
		m_imgWidth  = imageWidth;
		c_pgvVisionCCD = pgvVisionCCD;
		m_bROIMoving = false;
		m_bloadimage = false;

}

gvVisionImage_botcap::~gvVisionImage_botcap()
{
    //dtor
}

void gvVisionImage_botcap::gvIMG_LoadImage( wxString filename )
{
    if( !wxFileExists(filename) ) return;

    read_image(&ho_Image,filename);
    m_bloadimage = true;
    gvIMG_DrawImage(true);
}

void gvVisionImage_botcap::gvIMG_SaveImage( wxString filename )
{

}

void gvVisionImage_botcap::gvIMG_DrawImage( bool isDrawRoi/* = false*/ )
{
    disp_obj(ho_Image, hl_WindowID);
    if(isDrawRoi) gvIMG_ShowAllROI();
}

bool gvVisionImage_botcap::gvIMG_ConvertImage()
{
    gen_image3( &ho_Image, "byte", m_imgWidth, m_imgHeight, (Hlong)c_pBitsR, (Hlong)c_pBitsG, (Hlong)c_pBitsB );
    return true;
}


void gvVisionImage_botcap::gvIMG_ReadParam( wxXmlNode* pNode_parent )
{
		int iIndex = 0;

	vec_pTask.clear();

	int taskCnt = ISHCAP_API::xml_GetNodeValueL(pNode_parent,wxT("taskCnt"),1);
	m_minarea = ISHCAP_API::xml_GetNodeValueL(pNode_parent,wxT("m_minarea"),70000);

	for(iIndex=0;	iIndex<taskCnt;iIndex++)
	{
		wxString title = wxString::Format(wxT("Task%d"),iIndex+1);
		wxXmlNode* pNode_task = ISHCAP_API::xml_GetNode( pNode_parent, title );

		E_TASK_TYPE_ALL type = (E_TASK_TYPE_ALL)ISHCAP_API::xml_GetNodeValueL( pNode_task, wxT("tasktype") ,TASKTYPE_BLACK);

		E_ROI_TYPE roitype =(E_ROI_TYPE)ISHCAP_API::xml_GetNodeValueL( pNode_task, wxT("ROITYPE") ,ROITYPE_CIRCLE);


		gvVisionTask *pgvVisionTask = nullptr;
		switch(type)
		{
		case TASKTYPE_BLACK:
			pgvVisionTask = new gvVisionTask_black(roitype);
			break;
		case TASKTYPE_LOGO:
			pgvVisionTask = new gvVisionTask_logo(roitype);
		break;
		case TASKTYPE_COLOR:
			pgvVisionTask = new gvVisionTask_color(roitype);
		default:break;
		}
		pgvVisionTask->gvTask_ReadParam(pNode_task);
		vec_pTask.push_back(pgvVisionTask);
	}
}

void gvVisionImage_botcap::gvIMG_SaveParam( wxXmlNode* pNode_parent )
{
		int iIndex=0;
		int taskCnt = vec_pTask.size();
		ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("taskCnt"),taskCnt);
		ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("m_minarea"),m_minarea);

		for(iIndex=0;iIndex<taskCnt;iIndex++)
		{
			 wxXmlNode* pNode_task_Item= new wxXmlNode(wxXML_ELEMENT_NODE, wxString::Format(wxT("Task%d"),iIndex+1 ));
			pNode_parent->AddChild( pNode_task_Item);

			vec_pTask.at(iIndex)->gvTask_SaveParam(pNode_task_Item);
		}
}

void gvVisionImage_botcap::gvIMG_AddTask( gvVisionTask* pgvTask )
{
	vec_pTask.push_back(pgvTask);
}

void gvVisionImage_botcap::gvIMG_DeletTask( unsigned int idxTask )
{
		if(idxTask<vec_pTask.size())
		{
			vec_pTask.erase(vec_pTask.begin()+idxTask);
		}

}
BOOL gvVisionImage_botcap::gvIMG_OpenWindow(HWND hParentWnd,
	unsigned int left, unsigned int top,
	unsigned int width, unsigned int height)
{
		assert( 0 == hl_WindowID );

	set_check("~father");
	open_window( top,left,width,height,(Hlong)hParentWnd,"visible","",&hl_WindowID );
	set_check("father");
	set_draw( hl_WindowID,"margin" );
	set_colored( hl_WindowID,12 );

	hl_WindowID_rect.x = left;
	hl_WindowID_rect.y = top;
	hl_WindowID_rect.width = width;
	hl_WindowID_rect.height = height;

	set_part( hl_WindowID,0,0,m_imgHeight-1,m_imgWidth-1);
	gen_image_const( &ho_Image, "byte",m_imgWidth,m_imgHeight );
	gvIMG_DrawImage(false);
	return TRUE;
}

void gvVisionImage_botcap::gvIMG_TriggerInspection( bool isTest/* = false*/ )
{
	unsigned int iIndex = 0;
	unsigned int uiTaskCnt = vec_pTask.size();

	Hobject region_concat_defects, region_defects, region_temp1, region_loc;
	Hobject ImageReduced;

	gen_empty_obj(&region_concat_defects);

	/**< 产品定位 */
	bool isSuccess = _insp_loc(ho_Image,&region_loc);
	bool isdefcts 	  = false;
	if( isSuccess )
	{
//		wxMessageBox(wxT("定位！"));
		reduce_domain(ho_Image,region_loc,&ImageReduced);
		for(iIndex=0;iIndex<uiTaskCnt;iIndex++)
		{
			/**< 缺陷检测 */
			if(false == vec_pTask.at(iIndex)->gvTask_inspect(ImageReduced,&region_defects))
			isdefcts =true;

			/**< 缺陷串联 */
			copy_obj(region_concat_defects,&region_temp1,1,-1);
			concat_obj(region_temp1,region_defects,&region_concat_defects);
		}//for(iIndex=0;iIndex<uiTaskCnt;iIndex++)
	}

	Hlong numDefects = 0;
	count_obj(region_concat_defects,&numDefects);
	if( numDefects > 0)
	{
		disp_obj(ho_Image,hl_WindowID);
		disp_obj(region_concat_defects,hl_WindowID);
		isdefcts =true;
	}
	if(isdefcts)
	{
		c_pgvVisionCCD->vec_Result.push_back(c_pgvVisionCCD->get_Rejectdelay());
	}
}


void gvVisionImage_botcap::gvIMG_ShowAllROI()
{
	int taskcnt = vec_pTask.size();
	int iIndex =0;
	E_ROI_TYPE type;
	Hobject temproi1,temproi2;
	for(itr_pTask=vec_pTask.begin();itr_pTask!=vec_pTask.end();itr_pTask ++)
	{
		type = (*itr_pTask)->gvTask_GetRoiType();
		switch(type)
		{
		case ROITYPE_CIRCLE:
			{
				gvVisionROI_circle *pgvROI =(gvVisionROI_circle *) ((*itr_pTask)->gvTask_GetROI());
				gen_circle(&temproi1,pgvROI->gvROI_GetY(),pgvROI->gvROI_GetX(),pgvROI->gvROI_GetoutRadius());
				gen_circle(&temproi2,pgvROI->gvROI_GetY(),pgvROI->gvROI_GetX(),pgvROI->gvROI_GetinRadius());
				difference (temproi1,temproi2,&ho_ROI[iIndex]);
				m_roitype[iIndex] = ROITYPE_CIRCLE;
				pgvROI->gvROI_SetROI(ho_ROI[iIndex]);
				disp_obj( ho_ROI[iIndex], hl_WindowID );
				break;
			}

		case ROITYPE_RECT:
			{
				gvVisionROI_rect *pgvROI =(gvVisionROI_rect *) ((*itr_pTask)->gvTask_GetROI());
				gen_rectangle1(&ho_ROI[iIndex],pgvROI->gvROI_GetY(),pgvROI->gvROI_GetX(),pgvROI->gvROI_GetY()+pgvROI->gvROI_GetuiHeight(),pgvROI->gvROI_GetX()+pgvROI->gvROI_GetuiWidth());
				disp_obj( ho_ROI[iIndex], hl_WindowID );
				pgvROI->gvROI_SetROI(ho_ROI[iIndex]);
				m_roitype[iIndex] = ROITYPE_RECT;
			}
			break;
		default:
			break;
		}
		iIndex++;
	}

}

void gvVisionImage_botcap::gvIMG_FitSize( int left,  int top,  int width,  int height)
{
	float fRatioX, fRatioY, fRatio;

	if( (width > m_imgWidth) && (height > m_imgHeight) )
	{
		fRatio = 1.0f;
	}
	else
	{
		fRatioX = width/(float)m_imgWidth;
		fRatioY = height/(float)m_imgHeight;
		fRatio = (fRatioX > fRatioY) ? fRatioY : fRatioX;
	}

	int row_new = (height - fRatio * m_imgHeight)/2;
	int col_new = (width - fRatio * m_imgWidth )/2;
	int width_new = fRatio * m_imgWidth;
	int height_new = fRatio * m_imgHeight;

	set_window_extents( hl_WindowID,
		row_new, col_new, width_new, height_new );
	gvIMG_DrawImage(true);
}


/**< ROI */
bool gvVisionImage_botcap::gvIMG_ROISelect()
{
	char chCursor[MAX_PATH] = "\0";
	get_mshape( hl_WindowID,chCursor );
	if(0!=strcmp(chCursor,"arrow"))
	{
		m_bROIMoving = true;
		return true;
	}
	else return false;

}
void gvVisionImage_botcap::gvIMG_ROIStop()
{
	set_mshape( hl_WindowID, "arrow" );
	m_bROIMoving = false;
}
void gvVisionImage_botcap::gvIMG_ROIMove()
{
	Hlong uiX,uiY,outradius,inradius;
	Hlong Row1, Column1, Height, Width;
	Hlong Row , Column , button;
	set_check("~give_error");
	if( H_MSG_FAIL == get_mposition( hl_WindowID,&Row1,&Column1,&button ) )
	{
		return;
	}
	set_check("give_error");
	char chCursor[MAX_PATH] = "\0";
	get_mshape( hl_WindowID,chCursor );
	get_mposition( hl_WindowID,&Row,&Column,&button );
//	wxMessageBox(wxString::Format(wxT("%d"),m_idxActiveROI));
	switch(m_roitype[m_idxActiveROI])
	{
	case ROITYPE_CIRCLE:
		{
			 gvVisionROI_circle *pgvROI =(gvVisionROI_circle *) vec_pTask.at(m_idxActiveROI)->gvTask_GetROI();
			 uiX = pgvROI->gvROI_GetX();
			 uiY = pgvROI->gvROI_GetY();
			 outradius = pgvROI->gvROI_GetoutRadius();
			 inradius   = pgvROI->gvROI_GetinRadius() ;
			 if(0 == strcmp(chCursor,"Size All"))
			 {
			 	uiX=uiX+Column-m_colMoving;
			 	uiY =uiY+Row-m_rowMoving;
			 	pgvROI->gvROI_SetX(uiX);
			 	pgvROI->gvROI_SetY(uiY);
				m_rowMoving = Row;
				m_colMoving = Column;
			 }
			 else if((0 == strcmp(chCursor,"Size NWSE"))||
						(0 == strcmp(chCursor,"Size NESW")))
			 {
			 	long  offset = sqrt((double)(
										(uiX-Column)*(uiX-Column)+
										(uiY-Row)*(uiY-Row)));
				if(m_bROISizOut)
				{
					offset = (offset>inradius)?offset:inradius+2;
					pgvROI->gvROI_SetoutRadius(offset);
				}
				else
				{
					offset = (offset<outradius)?offset:outradius-2;
					pgvROI->gvROI_SetinRadius(offset);
				}
			 }
			pgvROI->gvROI_SetROI(ho_ROI[m_idxActiveROI]);
			break;
		}

	case ROITYPE_RECT:
		{
			gvVisionROI_rect *pgvROI =(gvVisionROI_rect *) vec_pTask.at(m_idxActiveROI)->gvTask_GetROI();
			Row1 = pgvROI->gvROI_GetY();
			Column1 = pgvROI->gvROI_GetX();
			Height= pgvROI->gvROI_GetuiHeight();
			Width =pgvROI->gvROI_GetuiWidth();
			if ( 0 == strcmp(chCursor,"Size All") )
			{
				pgvROI->gvROI_SetX(Column1 + (Column - m_colMoving));
				pgvROI->gvROI_SetY(Row1 + (Row - m_rowMoving));
			}
			else if ( 0 == strcmp( chCursor,"Size WE") )
			{
				Hlong x2 = Width + Column - m_colMoving;
				if ( x2 < 0 )
				{
					x2 = 2;
				}
				pgvROI->gvROI_SetuiWidth(x2);

			}
			else if ( 0 == strcmp( chCursor,"Size S") )
			{
				Hlong y2 = Height + Row - m_rowMoving;
				if ( y2 < 0 )
				{
					y2 =2;
				}
				pgvROI->gvROI_SetuiHeight(y2);
			}
			m_rowMoving = Row;
			m_colMoving = Column;
			pgvROI->gvROI_SetROI(ho_ROI[m_idxActiveROI]);
			break;
		}
	default:break;
	}
	gvIMG_DrawImage(true);
}
void gvVisionImage_botcap::gvIMG_SetROImshape(int x,int y)
{
	int iIndex = 0;
	int default_pitch = 10;
	m_idxActiveROI = -1;

	Hlong uiX,uiY,outradius,inradius,Row1, Column1, Row2, Column2, button;
		set_check("~give_error");
	if( H_MSG_FAIL == get_mposition( hl_WindowID,&Row1,&Column1,&button ) )
	{
		return;
	}
	set_check("give_error");
	if ( ( x > hl_WindowID_rect.GetLeft() && x < hl_WindowID_rect.GetRight() ) &&
		( y >hl_WindowID_rect.GetTop() && y <hl_WindowID_rect.GetBottom()) )
	{
		get_mposition( hl_WindowID,&m_rowMoving,&m_colMoving,&button );
		for ( iIndex=0; iIndex<gvIMG_GetTaskCnt(); iIndex++ )
		{
			switch(m_roitype[iIndex])
			{
			case ROITYPE_CIRCLE:
				{

					gvVisionROI_circle *pgvROI =(gvVisionROI_circle *) vec_pTask.at(iIndex)->gvTask_GetROI();
					 uiX = pgvROI->gvROI_GetX();
					 uiY = pgvROI->gvROI_GetY();
					 outradius =pgvROI->gvROI_GetoutRadius();
					 inradius =pgvROI->gvROI_GetinRadius();

					double offset = sqrt((double)(
										(uiX-m_colMoving)*(uiX-m_colMoving)+
										(uiY-m_rowMoving)*(uiY-m_rowMoving)));
					if((offset>inradius+default_pitch&&offset<outradius-default_pitch)||
							(offset<inradius-default_pitch))
					{
						set_mshape( hl_WindowID,"Size All");
						m_idxActiveROI = iIndex;
						break ;
					}
					else if(offset>inradius-default_pitch&&
							offset<inradius+default_pitch)
					{
						if(0<((uiX-m_colMoving)*(uiY-m_rowMoving)))
						{
							set_mshape(hl_WindowID,"Size NWSE");
						}

						else
						{
							set_mshape(hl_WindowID,"Size NESW");
						}
						m_idxActiveROI = iIndex;
						m_bROISizOut = false;
						return  ;
					}
					else if(offset>outradius-default_pitch&&
								offset<outradius+default_pitch)
					{
						if(0<((uiX-m_colMoving)*(uiY-m_rowMoving)))
						{
							set_mshape(hl_WindowID,"Size NWSE");
						}

						else
						{
							set_mshape(hl_WindowID,"Size NESW");
						}
						m_idxActiveROI = iIndex;
						m_bROISizOut = true;
						return  ;
					}

					break;
				}

			case ROITYPE_RECT:
				{

					gvVisionROI_rect *pgvROI =(gvVisionROI_rect *) vec_pTask.at(iIndex)->gvTask_GetROI();

					Row1 = pgvROI->gvROI_GetY();

					Column1 = pgvROI->gvROI_GetX();
					Row2=  pgvROI->gvROI_GetY()+  pgvROI->gvROI_GetuiHeight();
					Column2 = pgvROI->gvROI_GetX()+  pgvROI->gvROI_GetuiWidth();

					if ( ( m_rowMoving > Row1 ) &&
						( m_rowMoving < Row2-default_pitch ) &&
						( m_colMoving > Column1 ) &&
						( m_colMoving < Column2-default_pitch ) )
					{
						set_mshape( hl_WindowID,"Size All");
						m_idxActiveROI = iIndex;
						break  ;
					}
					else if ( ( m_rowMoving > Row1 ) &&
						( m_rowMoving < Row2 - default_pitch ) &&
						( m_colMoving > Column2-default_pitch ) &&
						( m_colMoving < Column2+default_pitch ) )
					{
						set_mshape( hl_WindowID,"Size WE");
						m_idxActiveROI = iIndex;
						return  ;
					}
					else if ( ( m_rowMoving > Row2 - default_pitch ) &&
						( m_rowMoving < Row2 + default_pitch ) &&
						( m_colMoving > Column1 ) &&
						( m_colMoving < Column2 - default_pitch ) )
					{
						set_mshape( hl_WindowID,"Size S");
						m_idxActiveROI = iIndex;
						return  ;
					}
					break;
				}

			default:
				break;
			}
		}//for ( iIndex=0; iIndex<gvIMG_GetTaskCnt(); iIndex++ )
		if(-1==m_idxActiveROI)
		{
			set_mshape( hl_WindowID,"arrow");
		}
	}//在图像框内
}
