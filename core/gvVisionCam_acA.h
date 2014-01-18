#pragma once

#include "gvVisionCam.h"
#include <pylon/PylonIncludes.h>
#include <pylon/PylonGUI.h>

class gvVisionCam_acA : public gvVisionCam
{
public:
    gvVisionCam_acA( unsigned int idxCam );
    ~gvVisionCam_acA(void);

    void cam_Init(  ImageGrabbedCallback pCallback, LPVOID pContext );
    bool cam_Start( bool isExtTrigger );
    void cam_Stop();
    void cam_LoadConfig( wxXmlNode* pNode_parent, bool isfSettings );
    void cam_SaveConfig( wxXmlNode* pNode_parent, bool isfSettings );
    bool cam_SetExpo( unsigned int expo );
    bool cam_SetGain( unsigned int gain );

    unsigned int getExpo()
    {
        return m_uiExpo;
    }
    unsigned int getGain()
    {
        return m_uiGain;
    }
    unsigned int getWidth()
    {
        return m_uiPosWidth;
    }
    unsigned int getHeight()
    {
        return m_uiPosHeight;
    }
    bool isInit()
    {
        return m_isInit;
    }
    bool isColor()
    {
        return m_isColor;
    }
private:
    static  UINT  _thread_imgAcq(LPVOID lParam);
    HANDLE	m_hEvent;
    HANDLE	m_hThread;
    bool	m_isThread_Continous;

    int64_t Adjust(int64_t val, int64_t minimum, int64_t maximum, int64_t inc);
    //////////////////////////////////////////////////////////////////////////
    Pylon::CInstantCamera			c_InstCam;
    Pylon::CImageFormatConverter	c_fmtConverter;
    Pylon::CPylonImage				c_PylonImage;

    bool			m_isInit;
    bool			m_isColor;
    /**<  */
    unsigned int	m_uiExpo;
    unsigned int	m_uiGain;
    unsigned int	m_uiSerial;
    unsigned int	m_uiPosX;
    unsigned int	m_uiPosY;
    unsigned int	m_uiPosWidth;
    unsigned int	m_uiPosHeight;
    unsigned int    m_uiVR;
    unsigned int    m_uiUB;
    unsigned int    m_uiWG;
};

