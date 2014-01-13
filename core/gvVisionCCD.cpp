#include "gvVisionManager.h"
#include "gvVisionCCD.h"
#include "gvVisionCam_acA.h"
#include "gvVisionImage.h"
#include "gvVisionImage_botcap_front.h"
#include "gvVisionImage_botcap_obverse.h"
#include "gvVisionImage_botcap_side.h"

gvVisionCCD::gvVisionCCD( unsigned int id,
                          gvVisionManager* pgvVisionManager )
{
    wxASSERT(pgvVisionManager);
    m_idxCam = id;
    c_pgvVisionManager = pgvVisionManager;
    //////////////////////////////////////////////////////////////////////////
    c_pgvVisionImage = nullptr;
    c_pgvVisionCam = nullptr;
    m_isMemory_Ready = false;
    e_Role = CCDROLE_FRONT;
    m_isUsing =true;
}


gvVisionCCD::~gvVisionCCD(void)
{
    if( c_pgvVisionImage )
    {
        delete c_pgvVisionImage;
        c_pgvVisionImage = nullptr;
    }

    if ( c_pgvVisionCam )
    {
        delete c_pgvVisionCam;
        c_pgvVisionCam = nullptr;
    }
}

bool gvVisionCCD::gvCCD_LoadConfig( wxXmlNode* pNode_parent, bool isfSettings )
{
    bool bRetval = true;
    int iIndex = 0;

    wxXmlNode   *pNode_ccd = ISHCAP_API::xml_GetNode( pNode_parent, wxString::Format(wxT("CCD%d"),m_idxCam+1) );

    if( isfSettings )
    {
		switch(m_idxCam)
		{
		case 0:
			e_Role = (E_CCD_ROLE)ISHCAP_API::xml_GetNodeValueL(pNode_ccd, wxT("role"), CCDROLE_FRONT );
			break;
		case 1:
			e_Role = (E_CCD_ROLE)ISHCAP_API::xml_GetNodeValueL(pNode_ccd, wxT("role"), CCDROLE_OBVERSE );
			break;
		case 2:
			e_Role = (E_CCD_ROLE)ISHCAP_API::xml_GetNodeValueL(pNode_ccd, wxT("role"), CCDROLE_SIDE );
			break;
		case 3:
			e_Role = (E_CCD_ROLE)ISHCAP_API::xml_GetNodeValueL(pNode_ccd, wxT("role"), CCDROLE_SIDE );
			break;
		case 4:
			e_Role = (E_CCD_ROLE)ISHCAP_API::xml_GetNodeValueL(pNode_ccd, wxT("role"), CCDROLE_SIDE );
			break;
		case 5:
			e_Role = (E_CCD_ROLE)ISHCAP_API::xml_GetNodeValueL(pNode_ccd, wxT("role"), CCDROLE_SIDE );
			break;
		default:break;
		}

        /**<  创建相机实例*/
        c_pgvVisionCam = new gvVisionCam_acA(m_idxCam);
        c_pgvVisionCam->cam_LoadConfig(pNode_ccd, true );
		c_pgvVisionCam->cam_Init( (ImageGrabbedCallback)cam_imgAcq_callback, this );
		if( !c_pgvVisionCam->isInit() )
		{
			wxMessageBox( wxString::Format(wxT("相机%d打开失败！"),m_idxCam+1) );
		}

        /**<  图像图像管理实例*/
		init_gvVisionImage();
    }
    else
    {
		m_isUsing = ISHCAP_API::xml_GetNodeValueL(pNode_ccd, wxT("isUsing"), true ) > 0;
        c_pgvVisionCam->cam_LoadConfig(pNode_ccd, false );
        c_pgvVisionImage->gvIMG_LoadConfig(pNode_ccd,false);
    }


    return bRetval;
}

bool gvVisionCCD::gvCCD_SaveConfig( wxXmlNode *pNode_parent, bool isfSettings)
{
    wxXmlNode* pNode_ccd = new wxXmlNode( wxXML_ELEMENT_NODE, wxString::Format(wxT("CCD%d"),m_idxCam+1) );
    pNode_parent->AddChild( pNode_ccd );

    if( isfSettings )
    {
		ISHCAP_API::xml_SetNodeValueL(pNode_ccd,wxT("role"),e_Role);
		c_pgvVisionCam->cam_SaveConfig( pNode_ccd, true );
    }
    else
    {
		ISHCAP_API::xml_SetNodeValueL(pNode_ccd,wxT("isUsing"),m_isUsing);
    	c_pgvVisionCam->cam_SaveConfig( pNode_ccd, false );
    	c_pgvVisionImage->gvIMG_SaveConfig(pNode_ccd,false);
    }

    return true;
}

void gvVisionCCD::init_gvVisionImage()
{
    switch(e_Role)
    {
    case CCDROLE_FRONT:
        c_pgvVisionImage = new gvVisionImage_botcap_front(this,c_pgvVisionCam->getWidth(),c_pgvVisionCam->getHeight());
        break;
    case CCDROLE_OBVERSE:
        c_pgvVisionImage = new gvVisionImage_botcap_obverse(this,c_pgvVisionCam->getWidth(),c_pgvVisionCam->getHeight());
        break;
    case CCDROLE_SIDE:
        c_pgvVisionImage = new gvVisionImage_botcap_side(this,c_pgvVisionCam->getWidth(),c_pgvVisionCam->getHeight());
        break;
    default:break;
    }
}

bool gvVisionCCD::cam_GetImage()
{
    if ( m_isMemory_Ready )
    {
        c_pgvVisionImage->gvIMG_ConvertImage();
        m_isMemory_Ready = false;
        return true;
    }
    return false;
}

DWORD gvVisionCCD::cam_imgAcq_callback(LPVOID pContext, BYTE* buffer, int width, int height)
{
    gvVisionCCD* pthis = (gvVisionCCD*)pContext;

    if ( !pthis->m_isMemory_Ready )
    {
        pthis->c_pgvVisionImage->gvIMG_GetBits(buffer,width,height);
        //pthis->c_pgvVisionImage->gvIMG_TransferErrorCode();
        pthis->m_isMemory_Ready = true;

        /**<  */
        if( 3 == pthis->m_idxCam )
        {
            if ( PSTATUS_Inspecting == pthis->get_VisionManager()->gvMgr_getStatus() )
            {
                pthis->c_pgvVisionManager->com_Write();
                pthis->c_pgvVisionManager->m_isNeed_UpdateInterface = true;
                wxWakeUpIdle();
            }
        }//if( 3 == pthis->m_idxCam )
    }
    else if( PSTATUS_Inspecting == pthis->get_VisionManager()->gvMgr_getStatus()  )
    {
        pthis->get_VisionManager()->m_isEMG = true;
        pthis->get_VisionManager()->m_uiEMGId = pthis->m_idxCam;
        wxWakeUpIdle();
    }

    return 0;
}
