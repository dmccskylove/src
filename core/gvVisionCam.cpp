#include "gvVisionCam.h"
#include "SNList.h"

gvVisionCam::gvVisionCam(unsigned int idxCam )
{
    m_idxCam = idxCam;
    m_pCallback = nullptr;
    m_pContext = nullptr;
}


gvVisionCam::~gvVisionCam(void)
{
}

bool gvVisionCam::isAuthorized( unsigned long serialNo )
{
    bool isAuthorized = false;

    unsigned int iIndex = 0;
    for(iIndex=0; iIndex<CONST_REGISTERED_CAMERA_NUM; iIndex++)
    {
        if ( serialNo  == atol(g_pchSNList[iIndex]) )
        {
            isAuthorized = true;
        }
    }//for(iIndex=0;iIndex<CONST_REGISTERED_CAMERA_NUM;iIndex++)
    return isAuthorized;
}
