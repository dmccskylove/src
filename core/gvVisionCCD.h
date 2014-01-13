#pragma once

#include "ISHCAPDef.h"

class gvVisionManager;
class gvVisionImage;
class gvVisionCam;
class gvVisionCCD
{
public:
    gvVisionCCD( unsigned int id, gvVisionManager* pgvVisionManager );
    ~gvVisionCCD(void);

    bool gvCCD_LoadConfig( wxXmlNode* pNode_parent, bool isfSettings = false );
    bool gvCCD_SaveConfig( wxXmlNode* pNode_parent, bool isfSettings = false );
    /************************************************************************/
    /*                                                                      */
    /************************************************************************/
    gvVisionManager	    *get_VisionManager()
    {
        return c_pgvVisionManager;
    }
    gvVisionImage	    *get_VisionImage()
    {
        return c_pgvVisionImage;
    }
    gvVisionCam			*get_VisionCam()
    {
        return c_pgvVisionCam;
    }
    unsigned int	    get_idxCam()
    {
        return m_idxCam;
    }

    bool cam_GetImage();
    bool get_using()
    {
    	return m_isUsing;
    }
	E_CCD_ROLE get_role()
	{
		return e_Role;
	}


		void set_Rejectdelay(int rejectdelay)
		{
			m_rejectdelay = rejectdelay;
		}

		int get_Rejectdelay()
		{
			return m_rejectdelay;
		}
	std::vector<int>		vec_Result;
protected:
    bool				m_isMemory_Ready;
    static DWORD WINAPI cam_imgAcq_callback(LPVOID pContext, BYTE* buffer, int width, int height);
private:
    unsigned int		m_idxCam;
    E_CCD_ROLE          e_Role;
	bool						m_isUsing;

	int 	m_rejectdelay;

    gvVisionManager		*c_pgvVisionManager;
    gvVisionImage		*c_pgvVisionImage;
    gvVisionCam			*c_pgvVisionCam;
    /************************************************************************/
    /*                                                                      */
    /************************************************************************/
    void init_gvVisionImage();
};


