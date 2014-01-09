#ifndef GVVISIONTASK_FRONT_LOGO_H
#define GVVISIONTASK_FRONT_LOGO_H

#include "gvVisionTask.h"


class gvVisionTask_logo : public gvVisionTask
{
    public:
        gvVisionTask_logo( E_ROI_TYPE type );
        virtual ~gvVisionTask_logo();
        void gvTask_SetMinScore(int  minscore){m_minscore = minscore;}
        int  gvTask_GetMinScore(){return m_minscore;}
        void gvTask_SetModeId(HTuple ModelId){m_ModelId = ModelId;}
        void  gvTask_SetModelname(wxString modelname)
        {
        	m_modelname = modelname;
        }
    protected:
		void gvTask_ReadParam( wxXmlNode* pNode_parent );
        void gvTask_SaveParam( wxXmlNode* pNode_parent );
        bool gvTask_inspect( Hobject image_src, Hobject *outRegion_defects );
    private:
    	int  m_minscore;
    	HTuple m_ModelId;
    	Hobject m_ModelContours;
    	wxString m_modelname;
};

#endif // GVVISIONTASK_FRONT_LOGO_H
