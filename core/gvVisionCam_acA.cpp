#include "gvVisionCam_acA.h"

using namespace Pylon;
using namespace GenApi;

gvVisionCam_acA::gvVisionCam_acA( unsigned int idxCam ): gvVisionCam( idxCam )
{
    m_isInit = false;
    m_isColor = false;
    m_hEvent = NULL;
    m_hThread = NULL;
}


gvVisionCam_acA::~gvVisionCam_acA(void)
{
    if ( m_hEvent )
    {
        CloseHandle(m_hEvent);
    }
    if ( m_hThread )
    {
        CloseHandle(m_hThread);
    }

}

void gvVisionCam_acA::cam_Init( ImageGrabbedCallback pCallback, LPVOID pContext )
{
    unsigned int iIndex = 0;
    DeviceInfoList_t devices;

    m_isInit = false;

    CTlFactory& tlFactory = CTlFactory::GetInstance();
    tlFactory.EnumerateDevices(devices);
    bool isFind = false;
    for ( iIndex=0; iIndex<devices.size(); iIndex++)
    {
        if ( m_uiSerial == atol(devices[iIndex].GetSerialNumber()) )
        {
            isFind = true;
            break;
        }
    }//for ( iIndex=0;iIndex<devices.size();iIndex++)
    if( !isFind )
        return;

    if ( !isAuthorized( m_uiSerial ) )
    {
        wxMessageBox(wxT("相机未注册!"));
        exit(0);
    }

    c_InstCam.Attach( tlFactory.CreateDevice( devices[ iIndex ]) );
    c_InstCam.Open();
    INodeMap& iNodemap = c_InstCam.GetNodeMap();

    //////////////////////////////////////////////////////////////////////////
    //AOI

    CIntegerPtr offsetX( iNodemap.GetNode( "OffsetX"));
    CIntegerPtr offsetY( iNodemap.GetNode( "OffsetY"));
    CIntegerPtr width( iNodemap.GetNode( "Width"));
    CIntegerPtr height( iNodemap.GetNode( "Height"));

    //为成功设置X、Y，先把宽度和高度设置为最小。
    width->SetValue(width->GetMin());
    height->SetValue(height->GetMin());

    offsetX->SetValue( m_uiPosX );
    offsetY->SetValue( m_uiPosY );

    int64_t newWidth = Adjust(m_uiPosWidth, width->GetMin(), width->GetMax(), width->GetInc());
    int64_t newHeight = Adjust(m_uiPosHeight, height->GetMin(), height->GetMax(), height->GetInc());

    width->SetValue(newWidth);
    height->SetValue(newHeight);

    //////////////////////////////////////////////////////////////////////////
    CEnumerationPtr gainAuto( iNodemap.GetNode( "GainAuto"));
    if ( IsWritable( gainAuto))
    {
        gainAuto->FromString("Off");
    }
    cam_SetGain(m_uiGain);
    CEnumerationPtr ExposureTimeAuto( iNodemap.GetNode( "ExposureTimeAuto"));
    if ( IsWritable( ExposureTimeAuto))
    {
        ExposureTimeAuto->FromString("Off");
    }
    cam_SetExpo(m_uiExpo);

    //////////////////////////////////////////////////////////////////////////
    CEnumerationPtr pixelFormat( iNodemap.GetNode( "PixelFormat"));
    if ( IsAvailable( pixelFormat->GetEntryByName( "BayerBG8")))
    {
        m_isColor = true;

        CEnumerationPtr brSelector( iNodemap.GetNode( "BalanceRatioSelector"));
        CIntegerPtr brRaw( iNodemap.GetNode( "BalanceRatioRaw"));
        brSelector->SetIntValue(0);
        brRaw->SetValue(m_uiVR);
        brSelector->SetIntValue(1);
        brRaw->SetValue(m_uiWG);
        brSelector->SetIntValue(2);
        brRaw->SetValue(m_uiUB);

        c_fmtConverter.OutputPixelFormat = PixelType_RGB8packed;
        c_fmtConverter.OutputBitAlignment = OutputBitAlignment_MsbAligned;
        c_PylonImage.Reset(PixelType_RGB8packed,newWidth,newHeight,ImageOrientation_TopDown);
    }
    else
    {
        m_isColor = false;
    }

    //////////////////////////////////////////////////////////////////////////
    CIntegerPtr GevSCPSPacketSize( iNodemap.GetNode( "GevSCPSPacketSize"));
    GevSCPSPacketSize->SetValue(1500);
    //////////////////////////////////////////////////////////////////////////
    CEnumerationPtr TriggerSelector( iNodemap.GetNode( "TriggerSelector"));
    TriggerSelector->SetIntValue(1);
    CEnumerationPtr TriggerMode( iNodemap.GetNode( "TriggerMode"));
    TriggerMode->SetIntValue(0);
    CEnumerationPtr TriggerSource( iNodemap.GetNode( "TriggerSource"));
    TriggerSource->SetIntValue(1);
    CEnumerationPtr TriggerActivation( iNodemap.GetNode( "TriggerActivation"));
    //TriggerActivation->SetIntValue(0);//上升沿
    TriggerActivation->SetIntValue(1);//下降沿
    ///////////////////////////////////////////////////////////////////
    m_pCallback = pCallback;
    m_pContext = pContext;

    m_isInit = true;
}


bool gvVisionCam_acA::cam_Start( bool isExtTrigger )
{
    if ( !c_InstCam.IsOpen() )
    {
        return false;
    }
    if ( c_InstCam.IsGrabbing() )
    {
        return false;
    }
    GenApi::INodeMap *iNodemap = &(c_InstCam.GetNodeMap());
    CEnumerationPtr  ptrTrigger = iNodemap->GetNode ("TriggerMode");
    ptrTrigger->SetIntValue( isExtTrigger ? 1 : 0 );
    c_InstCam.StartGrabbing(GrabStrategy_OneByOne);
    m_hEvent = CreateEvent( NULL, TRUE, FALSE, NULL);
    m_hThread = CreateThread( NULL, 0 ,(LPTHREAD_START_ROUTINE)_thread_imgAcq, this, 0, NULL );

    return true;
}

void gvVisionCam_acA::cam_Stop()
{
    if ( !c_InstCam.IsGrabbing() )
    {
        return;
    }//if ( !c_InstCam.IsGrabbing() )
    m_isThread_Continous = false;
    WaitForSingleObject(m_hEvent,INFINITE);
    c_InstCam.StopGrabbing();
    CloseHandle(m_hEvent);
    CloseHandle(m_hThread);
    m_hEvent = NULL;
    m_hThread = NULL;
}

void gvVisionCam_acA::cam_LoadConfig( wxXmlNode* pNode_parent, bool isfSettings )
{
    wxXmlNode   *pNode_cam = ISHCAP_API::xml_GetNode( pNode_parent, wxT("Cam") );
    if(isfSettings)
    {
        m_uiSerial = ISHCAP_API::xml_GetNodeValueL(pNode_cam, wxT("cam_serial"), 0 );
        m_uiPosX = ISHCAP_API::xml_GetNodeValueL(pNode_cam, wxT("cam_posX"), 0 );
        m_uiPosY = ISHCAP_API::xml_GetNodeValueL(pNode_cam, wxT("cam_posY"), 0 );
        m_uiPosWidth = ISHCAP_API::xml_GetNodeValueL(pNode_cam, wxT("cam_imgWidth"), 658 );
        m_uiPosHeight = ISHCAP_API::xml_GetNodeValueL(pNode_cam, wxT("cam_imgHeight"), 492 );
        m_uiVR = ISHCAP_API::xml_GetNodeValueL(pNode_cam, wxT("cam_VR"), 160 );
        m_uiUB = ISHCAP_API::xml_GetNodeValueL(pNode_cam, wxT("cam_UB"), 140 );
        m_uiWG = ISHCAP_API::xml_GetNodeValueL(pNode_cam, wxT("cam_WG"), 96 );

        m_uiExpo = ISHCAP_API::xml_GetNodeValueL( pNode_cam, wxT("cam_Expo"), 700 );
        m_uiGain = ISHCAP_API::xml_GetNodeValueL( pNode_cam, wxT("cam_Gain"), 100 );
    }
    else
    {
        m_uiExpo = ISHCAP_API::xml_GetNodeValueL( pNode_cam, wxT("cam_Expo"), 700 );
        if (isInit())
        {
            cam_SetExpo(m_uiExpo);
        }//if (isInit())
        m_uiGain = ISHCAP_API::xml_GetNodeValueL( pNode_cam, wxT("cam_Gain"), 100 );
        if (isInit())
        {
            cam_SetGain(m_uiGain);
        }//if (isInit())
    }
}

void gvVisionCam_acA::cam_SaveConfig( wxXmlNode* pNode_parent, bool isfSettings )
{
    wxXmlNode* pNode_cam = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("Cam") );
    pNode_parent->AddChild( pNode_cam );

    if(isfSettings)
    {
        ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_serial"),m_uiSerial);
        ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_posX"),m_uiPosX);
        ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_posY"),m_uiPosY);
        ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_imgWidth"),m_uiPosWidth);
        ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_imgHeight"),m_uiPosHeight);
        /**< 当相机序号大于1，即从第3个相机开始，都是彩色相机，需要设置白平衡参数 */
//        if( m_idxCam > 1 )
//        {
            ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_VR"),m_uiVR);
            ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_UB"),m_uiUB);
            ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_WG"),m_uiWG);
//        }
    }
    else
    {
        ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_Expo"),m_uiExpo);
        ISHCAP_API::xml_SetNodeValueL(pNode_cam,wxT("cam_Gain"),m_uiGain);
    }
}

bool gvVisionCam_acA::cam_SetExpo( unsigned int expo )
{
    INodeMap *iNodemap = &(c_InstCam.GetNodeMap());

    CIntegerPtr ExposureTimeRaw( iNodemap->GetNode( "ExposureTimeRaw"));
    if ( ExposureTimeRaw.IsValid() )
    {
        // Make sure the calculated value is valid.
        int64_t newExpoRaw = Adjust(expo, ExposureTimeRaw->GetMin(), ExposureTimeRaw->GetMax(), ExposureTimeRaw->GetInc());
        ExposureTimeRaw->SetValue(newExpoRaw);
        m_uiExpo = newExpoRaw;

        return true;
    }

    return false;
}

bool gvVisionCam_acA::cam_SetGain( unsigned int gain )
{
    INodeMap *iNodemap = &(c_InstCam.GetNodeMap());

    CIntegerPtr gainRaw( iNodemap->GetNode( "GainRaw"));
    if ( gainRaw.IsValid() )
    {
        // Make sure the calculated value is valid.
        int64_t newGainRaw = Adjust(gain, gainRaw->GetMin(), gainRaw->GetMax(), gainRaw->GetInc());
        gainRaw->SetValue(newGainRaw);
        m_uiGain = newGainRaw;

        return true;
    }
    return false;
}

int64_t gvVisionCam_acA::Adjust(int64_t val, int64_t minimum, int64_t maximum, int64_t inc)
{
    // Check the input parameters.
    if (inc <= 0)
    {
        // Negative increments are invalid.
        throw LOGICAL_ERROR_EXCEPTION("Unexpected increment %d", inc);
    }
    if (minimum > maximum)
    {
        // Minimum must not be bigger than or equal to the maximum.
        throw LOGICAL_ERROR_EXCEPTION("minimum bigger than maximum.");
    }

    // Check the lower bound.
    if (val < minimum)
    {
        return minimum;
    }

    // Check the upper bound.
    if (val > maximum)
    {
        return maximum;
    }

    // Check the increment.
    if (inc == 1)
    {
        // Special case: all values are valid.
        return val;
    }
    else
    {
        // The value must be min + (n * inc).
        // Due to the integer division, the value will be rounded down.
        return minimum + ( ((val - minimum) / inc) * inc );
    }
}

UINT  gvVisionCam_acA::_thread_imgAcq(LPVOID lParam)
{
    gvVisionCam_acA* pthis = (gvVisionCam_acA*)lParam;
    CGrabResultPtr	        ptrGrabResult ;

    pthis->m_isThread_Continous = true;
    while(pthis->m_isThread_Continous)
    {
        bool bRetval = pthis->c_InstCam.RetrieveResult( 100, ptrGrabResult, TimeoutHandling_Return );
        if ( bRetval )
        {
            int iWidth = ptrGrabResult->GetWidth();
            int iHeight = ptrGrabResult->GetHeight();
            if ( pthis->m_isColor )
            {
                pthis->c_fmtConverter.Convert(pthis->c_PylonImage,ptrGrabResult);
                pthis->m_pCallback(pthis->m_pContext,(BYTE*)pthis->c_PylonImage.GetBuffer(),iWidth,iHeight);
            }
            else
            {
                pthis->m_pCallback(pthis->m_pContext,(BYTE*)ptrGrabResult->GetBuffer(),iWidth,iHeight);
            }
        }

        wxMilliSleep(10);
    }//while(pthis->m_isThread_Continous)
    SetEvent(pthis->m_hEvent);

    return 0;
}
