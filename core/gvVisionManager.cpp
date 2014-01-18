#include "gvVisionManager.h"
#include "gvVisionCCD.h"
#include "gvVisionCam.h"
#include "gvVisionImage.h"
#include "thread_imgProc.h"
#include "thread_rejcProc.h"
#include "gvVisionIO_PCI7230.h"


gvVisionManager::gvVisionManager( )
{
//	Pylon::PylonAutoInitTerm autoInitTerm;
    /**<  */
    unsigned int iIndex = 0;
    for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
        c_pgvVisionCCD[iIndex] = nullptr;
        c_pthread_imageproc[iIndex] = NULL;
        c_pthread_rejcProc[iIndex] = NULL;
        m_bReject[iIndex]=false;
        //m_hEvent_io[iIndex] = nullptr;
    }//for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM;iIndex++ )

    m_lTotalNum = 0;
    m_lFailNum = 0;
    m_isNeed_UpdateInterface = false;
    m_isEMG = false;
	m_idxActiveCCD =1;
    e_ProgramStatus = PSTATUS_unLoad;

}


gvVisionManager::~gvVisionManager(void)
{
    /**<  关闭串口 */
    if ( c_pSerialPort )
    {
        c_pSerialPort->Writev("C", sizeof("C"), 10);
        c_pSerialPort->Close();
        delete c_pSerialPort;
    }//if ( c_pSerialPort )

    /**<  */
    int iIndex = 0;
    for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
        if ( nullptr != c_pgvVisionCCD[iIndex] )
        {
            delete c_pgvVisionCCD[iIndex];
            c_pgvVisionCCD[iIndex] = nullptr;
        }//if ( nullptr != c_pgvVisionCCD[iIndex] )
    }//for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
}

bool gvVisionManager::gvMgr_LoadConfig( wxString filename )
{
    bool bRetval = true;
    if ( filename.IsEmpty() )
    {
        return false;
    }//if ( factoryfile.IsEmpty() )

    /**打开XML文档 */
    wxXmlDocument *xmldoc = new wxXmlDocument();
    wxXmlNode   *pNode_root = NULL;
    if ( wxFileExists(filename) )
    {
        if( !xmldoc->Load( filename ) )
        {
            wxMessageBox( wxT("文件打开失败！"));
            return FALSE;
        }
        pNode_root = xmldoc->GetRoot();
    }
    long lvSize = 0;
    wxString title = filename.AfterLast(wxT('\\')).BeforeFirst(wxT('#'));
    if ( title.IsNumber() )
    {
        title.ToLong( &lvSize );
    }

    int iIndex = 0;
    for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
        c_pgvVisionCCD[iIndex]->gvCCD_LoadConfig( pNode_root,false );
    }//for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )

    delete xmldoc;

    m_strConfigFile = filename;

    e_ProgramStatus = PSTATUS_Loaded;


    Init_ImageDir();

    return bRetval;
}

bool gvVisionManager::gvMgr_SaveConfig( wxString filename, bool isfSettings )
{
    if ( filename.IsEmpty() )
    {
        return false;
    }//if ( filename.IsEmpty() )

    //m_strConfigFile = filename;
    wxXmlDocument *xmldoc = new wxXmlDocument();
    wxString strComment1 = wxT("pls refer to http://www.machine-vison.com.cn for detail infomation\n");
    wxXmlNode *comment1 = new wxXmlNode(wxXML_COMMENT_NODE, wxT("comment"), strComment1 );
    xmldoc->AppendToProlog(comment1);

    wxXmlNode* pNode_root = new wxXmlNode( wxXML_ELEMENT_NODE, "ps" );
    xmldoc->SetRoot( pNode_root );

    /**<  */
    ISHCAP_API::xml_SetNodeValueL(pNode_root, wxT("lPktNum"), m_lPktNum );
    ISHCAP_API::xml_SetNodeValueL(pNode_root, wxT("idxPort"), m_idxPort );
    int iIndex = 0;
    for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
        c_pgvVisionCCD[iIndex]->gvCCD_SaveConfig( pNode_root, isfSettings );

    }//for ( iIndex=0;iIndex<HGV_SUPPORT_CAMERANUM;iIndex++ )

    if(!xmldoc->Save(filename)){
		  wxMessageBox(wxString::Format(wxT("Fail  Save %s"),filename));

    }
    delete xmldoc;
    return true;
}

bool gvVisionManager::gvMgr_Init()
{
//    /**< 打开串口 */
//    c_pSerialPort = new ctb::SerialPort();
//    int iRetVal = c_pSerialPort->Open( wxString("COM1"),
//                                       19200,
//                                       wxString("8N1"),
//                                       ctb::SerialPort::NoFlowControl );
//    if( iRetVal >= 0 )
//    {
//        c_pSerialPort->Writev("C",sizeof("C"),10);
//    }
//    else
//    {
//        c_pSerialPort = nullptr;
//        wxMessageBox(wxT("串口打开失败！"));
//    }

	c_pgvVisionIO = new gvVisionIO_pci7230(this);
	c_pgvVisionIO->gvIO_Init();
    /**< 读取出厂设置文件 */
    wxString filename = wxGetCwd() + wxT("\\fsettings.xml");

    wxXmlDocument *xmldoc = new wxXmlDocument();
    wxXmlNode   *pNode_root = NULL;
    if ( wxFileExists(filename) )
    {
        if( xmldoc->Load( filename ) )
        {
            pNode_root = xmldoc->GetRoot();
        }
    }//if ( wxFileExists(filename) )

    m_lPktNum = ISHCAP_API::xml_GetNodeValueL(pNode_root, wxT("lPktNum"), 50 );
	m_idxPort   =ISHCAP_API::xml_GetNodeValueL(pNode_root, wxT("idxPort"), 19 );
    int iIndex = 0;
    for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
        c_pgvVisionCCD[iIndex] = new gvVisionCCD( iIndex, this );
        c_pgvVisionCCD[iIndex]->gvCCD_LoadConfig( pNode_root,true );
    }//for ( iIndex=0; iIndex<g_uiCameraSum; iIndex++ )

    delete xmldoc;
    if( !wxFileExists(filename) )
    {
        wxSleep(1);
        gvMgr_SaveConfig(filename,true);
    }//if( !wxFileExists(filename) )

    return true;
}

void gvVisionManager::Init_ImageDir()
{
    wxFileName filename(m_strConfigFile);

    wxString dir = wxGetCwd() + wxT("\\images\\");

    dir = dir + filename.GetName();
    wxMkDir( dir );

    wxDateTime date = wxDateTime::Today();
    dir = dir + wxString::Format( wxT("\\%d-%02d-%02d"), date.GetYear(), date.GetMonth()+1, date.GetDay() );
    wxMkDir( dir );

    int iIndex = 0;
    for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
        m_strImageDir[iIndex] = dir + wxString::Format( wxT("\\CCD%d"), iIndex+1 );
        wxMkDir( m_strImageDir[iIndex] );
    }
}

bool gvVisionManager::gvMgr_runStart( E_PROGRAM_STATUS eStatus )
{
    e_ProgramStatus = eStatus;

    unsigned int iIndex = 0;
    //1、其次创建图像处理线程和剔除线程
    for( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
       if(c_pgvVisionCCD[iIndex]->get_using())
		{
			c_pthread_imageproc[iIndex] = new thread_imgProc( this, iIndex, eStatus );
			if( c_pthread_imageproc[iIndex]->Create() != wxTHREAD_NO_ERROR )
			{
				wxLogError( wxT("无法创建图像处理线程！ ") );
				return false;
			}//if( c_pthread_imageproc[iIndex]->Create() != wxTHREAD_NO_ERROR )
			c_pthread_imageproc[iIndex]->SetPriority( WXTHREAD_MAX_PRIORITY );
			c_pthread_imageproc[iIndex]->Run();

			c_pthread_rejcProc[iIndex] = new thread_rejcProc( this, iIndex, eStatus );
			if( c_pthread_rejcProc[iIndex]->Create() != wxTHREAD_NO_ERROR )
			{
				wxLogError( wxT("无法创建剔除线程！ ") );
				return false;
			}//if( c_pthread_imageproc[iIndex]->Create() != wxTHREAD_NO_ERROR )
			c_pthread_rejcProc[iIndex]->SetPriority( WXTHREAD_MAX_PRIORITY );
			c_pthread_rejcProc[iIndex]->Run();
		}
    }//for( iIndex=0; iIndex<c_pgvVisionManager->gvMgr_GetgvVisionCCDSum(); iIndex++ )
    /**< 打开相机 */
    for( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
        if(c_pgvVisionCCD[iIndex]->get_using())
		{
			gvVisionCam* pgvVisionCam = c_pgvVisionCCD[iIndex]->get_VisionCam();
			bool bOpenned = pgvVisionCam->cam_Start( (PSTATUS_Displaying == eStatus) ? false : true );

			if( !bOpenned )
			{
				wxMessageBox( wxString::Format(wxT("相机%d启动失败!"),iIndex+1));
			}
		}

    }
    if( PSTATUS_Inspecting == eStatus )
    {
       // c_pSerialPort->Writev( "R",sizeof("R"),10);
    }
    return true;
}

void gvVisionManager::gvMgr_runStop()
{
    int iIndex = 0;

    /**< 关闭相机 */
    for( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
        gvVisionCam* pgvVisionCam = c_pgvVisionCCD[iIndex]->get_VisionCam();
        pgvVisionCam->cam_Stop();
    }

    wxSleep(1);

    //停止图像处理线程
    for( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
    {
       if(c_pgvVisionCCD[iIndex]->get_using())
	   {
			if( c_pthread_imageproc[iIndex] )
			{
				c_pthread_imageproc[iIndex]->Delete();
				c_pthread_imageproc[iIndex] = NULL;
			}//if( c_pthread_imageproc[iIndex] )
			if( c_pthread_rejcProc[iIndex] )
			{
				c_pthread_rejcProc[iIndex]->Delete();
				c_pthread_rejcProc[iIndex] = NULL;
			}
	   }
    }
    //for( iIndex=0; iIndex<c_pgvVisionManager->gvMgr_GetgvVisionCCDSum(); iIndex++ )
//
//    if( PSTATUS_Inspecting == e_ProgramStatus )
//    {
//        c_pSerialPort->Writev( "C",sizeof("C"),10);
//    }

    e_ProgramStatus = PSTATUS_Loaded;
}

void gvVisionManager::gvMgr_Reject()
{
	c_pgvVisionIO->set_OutputBit(m_idxPort,TRUE);
	wxMutexLocker lock(m_Mutex);
	if(m_Mutex.IsOk())
	{
			for(int iIndex=0;iIndex<HGV_SUPPORT_CAMERANUM;iIndex++)
		{
			if(gvMgr_getVisionCCD(iIndex)->get_using())
			{
				m_bReject[iIndex]=false;
			}
		}
	}
//	wxMessageBox(wxT("reject"));
}


bool gvVisionManager::get_Reject()
{
	int iIndex =0;
	bool reject = true;
	for(iIndex=0;iIndex<HGV_SUPPORT_CAMERANUM;iIndex++)
	{
		if(gvMgr_getVisionCCD(iIndex)->get_using())
		{
			reject = reject&&m_bReject[iIndex];
		}
	}
	return reject;
}
