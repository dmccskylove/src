#pragma once
#include "ISHCAPDef.h"

class gvVisionManager;
class thread_rejcProc : public wxThread
{
public:
    thread_rejcProc(gvVisionManager* pgvVisionManager, unsigned int idxCam, E_PROGRAM_STATUS eStatus );
    ~thread_rejcProc(void);
protected:
    virtual void *Entry();
private:
    gvVisionManager		*c_pgvVisionManager;
    unsigned int		m_idxCam;
     std::vector<int>::iterator itr_Rejct;
    E_PROGRAM_STATUS	e_ProgramStatus;
	wxMutex				m_Mutex;
};

