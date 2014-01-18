#pragma once
#include "ISHCAPDef.h"

class gvVisionManager;
class thread_imgProc : public wxThread
{
public:
    thread_imgProc(gvVisionManager* pgvVisionManager, unsigned int idxCam, E_PROGRAM_STATUS eStatus );
    ~thread_imgProc(void);
protected:
    virtual void *Entry();
private:
    gvVisionManager		*c_pgvVisionManager;
    unsigned int		m_idxCam;
    E_PROGRAM_STATUS	e_ProgramStatus;
};

