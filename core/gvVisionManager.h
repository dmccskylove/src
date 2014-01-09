#pragma once

#include "ISHCAPDef.h"

class gvVisionCCD;
class gvVisionManager
{
    friend class thread_imgProc;
public:
    gvVisionManager( );
    ~gvVisionManager(void);

    bool gvMgr_LoadConfig( wxString filename );
    bool gvMgr_SaveConfig( wxString filename, bool isfSettings = false );
    bool gvMgr_Init();

    bool gvMgr_runStart( E_PROGRAM_STATUS eStatus );
    void gvMgr_runStop();

    gvVisionCCD				*gvMgr_getVisionCCD( unsigned int iIndex )
    {
        return c_pgvVisionCCD[iIndex];
    }
    E_PROGRAM_STATUS		gvMgr_getStatus()
    {
        return e_ProgramStatus;
    }
    void					gvMgr_setStatus(E_PROGRAM_STATUS eStatus)
    {
        e_ProgramStatus = eStatus;
    }
    wxString				gvMgr_getImageDir( unsigned int iIndex)
    {
        return m_strImageDir[iIndex];
    }
    wxString				gvMgr_getConfigFile()
    {
        return m_strConfigFile;
    }

    long                    get_PktNum()
    {
        return m_lPktNum;
    }
    void                    set_( long newVal )
    {
        m_lPktNum = newVal;
    }
        int                    get_idxActiveCCD()
    {
        return m_idxActiveCCD;
    }
    void                    set_idxActiveCCD( int idxActiveCCD )
    {
        m_idxActiveCCD = idxActiveCCD;
    }
    long					get_FailNum();
    bool                    com_Write();
    bool                    com_Read( long *lFailNum );
    char                    getAscii( unsigned char ascii );

    bool				m_isNeed_UpdateInterface;
    bool				m_isEMG;
    unsigned int        m_uiEMGId;
    //���±���������س����ڲ�������״̬
    double				m_dfInsptime[HGV_SUPPORT_CAMERANUM];
    long				m_lTotalNum;/**< ��Ʒ�������� */
    long                m_lFailNum;
    //��¼���������ٶ�
    double				m_tFirstGrab;//�����һ�βɼ���ʱ��
    double				m_tInterval;//���2�βɼ��ļ��
protected:
    gvVisionCCD			*c_pgvVisionCCD[HGV_SUPPORT_CAMERANUM];
    thread_imgProc      *c_pthread_imageproc[HGV_SUPPORT_CAMERANUM];
    ctb::SerialPort		*c_pSerialPort;
    //////////////////////////////////////////////////////////////////////////
    E_PROGRAM_STATUS	e_ProgramStatus;
private:
    long        m_lPktNum;/**< �������� */
    wxString	m_strConfigFile;
    wxString	m_strImageDir[HGV_SUPPORT_CAMERANUM];
    void		Init_ImageDir();
	int 		m_idxActiveCCD;
};

