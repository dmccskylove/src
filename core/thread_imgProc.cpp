#include "thread_imgProc.h"
#include "gvVisionManager.h"
#include "gvVisionCCD.h"
#include "gvVisionImage.h"

thread_imgProc::thread_imgProc( gvVisionManager* pgvVisionManager, unsigned int idxCam, E_PROGRAM_STATUS eStatus )
{
    wxASSERT(NULL != pgvVisionManager);
    wxASSERT(NULL != pgvVisionManager->gvMgr_getVisionCCD(idxCam));
    c_pgvVisionManager = pgvVisionManager;
    m_idxCam = idxCam;
    e_ProgramStatus = eStatus;
}

thread_imgProc::~thread_imgProc(void)
{
}

void* thread_imgProc::Entry()
{
    MSG message;
    bool isSuccessed = false;

    gvVisionCCD		*pgVisionCCD = c_pgvVisionManager->gvMgr_getVisionCCD(m_idxCam);
    gvVisionImage	*pgvVisionImage = pgVisionCCD->get_VisionImage();

    while( !TestDestroy() )
    {
        switch( e_ProgramStatus )
        {
        case PSTATUS_Inspecting:
            isSuccessed = pgVisionCCD->cam_GetImage();
            if( isSuccessed )
            {
                pgvVisionImage->gvIMG_TriggerInspection(false);

                isSuccessed = false;
            }//if( pgVisionCCD->gvCCD_camSnap() )
            break;
        case PSTATUS_Displaying:
            isSuccessed = pgVisionCCD->cam_GetImage();
            if( isSuccessed )
            {
                pgvVisionImage->gvIMG_DrawImage(true);
                isSuccessed = false;
            }//if( pgVisionCCD->gvCCD_camSnap() )
            break;
        case PSTATUS_ImgSaving:
            isSuccessed = pgVisionCCD->cam_GetImage();
            if( isSuccessed )
            {
                pgvVisionImage->gvIMG_DrawImage(true);
                pgvVisionImage->gvIMG_SaveImage(wxEmptyString);
                isSuccessed = false;
            }//if( pgVisionCCD->gvCCD_camSnap() )
            break;
        default:
            break;
        }//switch(e_ProgramStatus)

        if( ::PeekMessage(&message,NULL,0,0,PM_NOREMOVE) )
        {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }
        wxThread::Sleep( 1 );
    }//while(!pthis->m_isThread_NeedStop)

    return NULL;
}
