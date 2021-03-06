#pragma once

#include "ISHCAPDef.h"

class gvVisionCCD;
class gvVisionIO_pci7230;
class gvVisionManager
{
    friend class thread_imgProc;
    friend class thread_rejcProc;
public:
    gvVisionManager( );
    ~gvVisionManager(void);

    bool gvMgr_LoadConfig( wxString filename );
    bool gvMgr_SaveConfig( wxString filename, bool isfSettings = false );
    bool gvMgr_Init();

    bool gvMgr_runStart( E_PROGRAM_STATUS eStatus );
    void gvMgr_runStop();

    gvVisionCCD *gvMgr_getVisionCCD( unsigned int iIndex )
    {
        return c_pgvVisionCCD[iIndex];
    }
    E_PROGRAM_STATUS gvMgr_getStatus()
    {
        return e_ProgramStatus;
    }
    void gvMgr_setStatus(E_PROGRAM_STATUS eStatus)
    {
        e_ProgramStatus = eStatus;
    }
    wxString gvMgr_getImageDir( unsigned int iIndex)
    {
        return m_strImageDir[iIndex];
    }
    wxString gvMgr_getConfigFile()
    {
        return m_strConfigFile;
    }

    long get_PktNum()
    {
        return m_lPktNum;
    }
    void set_PktNum( long newVal )
    {
        m_lPktNum = newVal;
    }
    int get_idxActiveCCD()
    {
        return m_idxActiveCCD;
    }
    void set_idxActiveCCD( int idxActiveCCD )
    {
        m_idxActiveCCD = idxActiveCCD;
    }

	unsigned int get_idxPort()
    {
        return m_idxPort;
    }
    void set_idxPort(unsigned int idxPort )
    {
        m_idxPort = idxPort;
    }

	void 					gvMgr_Reject();
    bool 					get_Reject();

    bool				m_isNeed_UpdateInterface;
    bool				m_isEMG;
    unsigned int        m_uiEMGId;
    //以下变量用来监控程序内部的运行状态
    double				m_dfInsptime[HGV_SUPPORT_CAMERANUM];
    long				m_lTotalNum;/**< 产品总数计数 */
    long                m_lFailNum;
    //记录机器运行速度
    double				m_tFirstGrab;//相机第一次采集的时刻
    double				m_tInterval;//相机2次采集的间隔

	bool 				m_bReject[HGV_SUPPORT_CAMERANUM];
	wxMutex				m_Mutex;
protected:
    gvVisionCCD			*c_pgvVisionCCD[HGV_SUPPORT_CAMERANUM];
    thread_imgProc      *c_pthread_imageproc[HGV_SUPPORT_CAMERANUM];
    thread_rejcProc 	*c_pthread_rejcProc[HGV_SUPPORT_CAMERANUM];
    ctb::SerialPort		*c_pSerialPort;
    gvVisionIO_pci7230  *c_pgvVisionIO;
    //////////////////////////////////////////////////////////////////////////
    E_PROGRAM_STATUS	e_ProgramStatus;

private:
    long        m_lPktNum;/**< 单包总数 */
    wxString	m_strConfigFile;
    wxString	m_strImageDir[HGV_SUPPORT_CAMERANUM];
    void		Init_ImageDir();
	int 		m_idxActiveCCD;
	unsigned int 	m_idxPort;
};

