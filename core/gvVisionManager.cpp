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
        //m_hEvent_io[iIndex] = nullptr;
    }//for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM;iIndex++ )

    m_lTotalNum = 0;
    m_lFailNum = 0;
    m_isNeed_UpdateInterface = false;
    m_isEMG = false;
	m_idxActiveCCD =1;
    e_ProgramStatus = PSTATUS_unLoad;
    m_bReject =false;
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

bool gvVisionManager::com_Write()
{
    return false;
}

bool gvVisionManager::com_Read( long *lFailNum )
{
    *lFailNum = 0;
    if( c_pSerialPort )
    {
        char* buf;
        size_t szBuf = 0;
        int readed1 = c_pSerialPort->ReadUntilEOS( buf,&szBuf,(char*)("n"),10);
        if ( readed1 > 0 )
        {
            *lFailNum = 1;
            return true;
        }
    }//if( c_pSerialPort )
    return true;
}

void gvVisionManager::gvMgr_Reject()
{
	c_pgvVisionIO->set_OutputBit(m_idxPort,TRUE);
}

char gvVisionManager::getAscii( unsigned char ascii )
{
    char ch = '0';
    switch(ascii)
    {
    case 0x30:
        ch =  '0';
        break;
    case 0x31:
        ch =  '1';
        break;
    case 0x32:
        ch =  '2';
        break;
    case 0x33:
        ch =  '3';
        break;
    case 0x34:
        ch =  '4';
        break;
    case 0x35:
        ch =  '5';
        break;
    case 0x36:
        ch =  '6';
        break;
    case 0x37:
        ch =  '7';
        break;
    case 0x38:
        ch =  '8';
        break;
    case 0x39:
        ch =  '9';
        break;
    case 0x3A:
        ch =  ':';
        break;
    case 0x3B:
        ch =  ';';
        break;
    case 0x3C:
        ch =  '<';
        break;
    case 0x3D:
        ch =  '=';
        break;
    case 0x3E:
        ch =  '>';
        break;
    case 0x3F:
        ch =  '?';
        break;
    case 0x40:
        ch =  '@';
        break;
    case 0x41:
        ch =  'A';
        break;
    case 0x42:
        ch =  'B';
        break;
    case 0x43:
        ch =  'C';
        break;
    case 0x44:
        ch =  'D';
        break;
    case 0x45:
        ch =  'E';
        break;
    case 0x46:
        ch =  'F';
        break;
    case 0x47:
        ch =  'G';
        break;
    case 0x48:
        ch =  'H';
        break;
    case 0x49:
        ch =  'I';
        break;
    case 0x4A:
        ch =  'J';
        break;
    case 0x4B:
        ch =  'K';
        break;
    case 0x4C:
        ch =  'L';
        break;
    case 0x4D:
        ch =  'M';
        break;
    case 0x4E:
        ch =  'N';
        break;
    case 0x4F:
        ch =  'O';
        break;
    case 0x50:
        ch =  'P';
        break;
    case 0x51:
        ch =  'Q';
        break;
    case 0x52:
        ch =  'R';
        break;
    case 0x53:
        ch =  'S';
        break;
    case 0x54:
        ch =  'T';
        break;
    case 0x55:
        ch =  'U';
        break;
    case 0x56:
        ch =  'V';
        break;
    case 0x57:
        ch =  'W';
        break;
    case 0x58:
        ch =  'X';
        break;
    case 0x59:
        ch =  'Y';
        break;
    case 0x5A:
        ch =  'Z';
        break;
    case 0x5B:
        ch =  '[';
        break;
    case 0x5C:
        ch =  '\\';
        break;
    case 0x5D:
        ch =  ']';
        break;
    case 0x5E:
        ch =  '^';
        break;
    case 0x5F:
        ch =  '_';
        break;
    case 0x60:
        ch =  '`';
        break;
    case 0x61:
        ch =  'a';
        break;
    case 0x62:
        ch =  'b';
        break;
    case 0x63:
        ch =  'c';
        break;
    case 0x64:
        ch =  'd';
        break;
    case 0x65:
        ch =  'e';
        break;
    case 0x66:
        ch =  'f';
        break;
    case 0x67:
        ch =  'g';
        break;
    case 0x68:
        ch =  'h';
        break;
    case 0x69:
        ch =  'i';
        break;
    case 0x6A:
        ch =  'j';
        break;
    case 0x6B:
        ch =  'k';
        break;
    case 0x6C:
        ch =  'l';
        break;
    case 0x6D:
        ch =  'm';
        break;
    case 0x6E:
        ch =  'n';
        break;
    case 0x6F:
        ch =  'o';
        break;
    case 0x70:
        ch =  'p';
        break;
    case 0x71:
        ch =  'q';
        break;
    case 0x72:
        ch =  'r';
        break;
    case 0x73:
        ch =  's';
        break;
    case 0x74:
        ch =  't';
        break;
    default:
        wxMessageBox(wxT("ERROR"));
        break;
    }

    return ch;
}

