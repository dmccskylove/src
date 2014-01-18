#include "thread_rejcProc.h"
#include "gvVisionManager.h"
#include "gvVisionCCD.h"
#include "gvVisionImage_botcap.h"

thread_rejcProc::thread_rejcProc( gvVisionManager* pgvVisionManager, unsigned int idxCam, E_PROGRAM_STATUS eStatus )
{
    wxASSERT(NULL != pgvVisionManager);
    wxASSERT(NULL != pgvVisionManager->gvMgr_getVisionCCD(idxCam));
    c_pgvVisionManager = pgvVisionManager;
    m_idxCam = idxCam;
    e_ProgramStatus = eStatus;
}

thread_rejcProc::~thread_rejcProc(void)
{
}

void* thread_rejcProc::Entry()
{
    bool isSuccessed = false;
	int rejectDelay = 0;
    gvVisionCCD		*pgVisionCCD = c_pgvVisionManager->gvMgr_getVisionCCD(m_idxCam);
    gvVisionImage_botcap 	*pgvVisionImage =(gvVisionImage_botcap 	*)pgVisionCCD->get_VisionImage();
    std::vector<Result >  *vec_pResult  =&pgVisionCCD->vec_Result;

    while( !TestDestroy() )
    {
    	if(e_ProgramStatus== PSTATUS_Inspecting)
		{
			wxMutexLocker lock(pgvVisionImage->m_Mutex);
			if(pgvVisionImage->m_Mutex.IsOk() )
			{
				if(!vec_pResult->empty())
				{
					for(itr_Rejct=vec_pResult->begin();itr_Rejct!=vec_pResult->end();itr_Rejct++)
					{
						(*itr_Rejct).Rejctdelay--;
					}
					if(0>=vec_pResult->at(0).Rejctdelay)
					{
						wxMutexLocker lock(c_pgvVisionManager->m_Mutex);
						if(c_pgvVisionManager->m_Mutex.IsOk())
						{
							c_pgvVisionManager->m_bReject[m_idxCam]=vec_pResult->at(0).Pass;
						vec_pResult->erase(vec_pResult->begin());
						}
					}
				}//if(!vec_pResult->empty())
			}//if( e_ProgramStatus== PSTATUS_Inspecting)
		}

        wxThread::Sleep(5);
    }//while(!pthis->m_isThread_NeedStop)

    return NULL;
}
