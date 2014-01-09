#pragma once

#include "ISHCAPDef.h"

typedef bool (_stdcall *ImageGrabbedCallback)(LPVOID pContext, BYTE* pImgData,int iWidth,int iheight);

class wxXmlNode;
class gvVisionCam
{
public:
    gvVisionCam(unsigned int idxCam );
    ~gvVisionCam(void);

    virtual void cam_Init( ImageGrabbedCallback pCallback, LPVOID pContext ) = 0;
    virtual bool cam_Start( bool isExtTrigger ) = 0;
    virtual void cam_Stop() = 0;
    virtual void cam_LoadConfig( wxXmlNode* pNode_parent, bool isfSettings ) = 0;
    virtual void cam_SaveConfig( wxXmlNode* pNode_parent, bool isfSettings ) = 0;
    virtual bool cam_SetExpo( unsigned int expo ) = 0;
    virtual bool cam_SetGain( unsigned int gain ) = 0;
    virtual unsigned int getExpo() = 0;
    virtual unsigned int getGain() = 0;
    virtual unsigned int getWidth() = 0;
    virtual unsigned int getHeight() = 0;
    virtual bool isInit() = 0;
    virtual bool isColor() = 0;
protected:
    bool	isAuthorized( unsigned long serialNo );

    ImageGrabbedCallback	m_pCallback;
    LPVOID					m_pContext;
    unsigned int			m_idxCam;
};

