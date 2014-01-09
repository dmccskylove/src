#ifndef GVVISIONTASK_FRONT_COLOR_H
#define GVVISIONTASK_FRONT_COLOR_H

#include "gvVisionTask.h"


class gvVisionTask_color : public gvVisionTask
{
    public:
        gvVisionTask_color( E_ROI_TYPE type );
        virtual ~gvVisionTask_color();

		int	gvTask_GetmeanBlue(){return m_meanBlue[0].L();}
		int	gvTask_GetmeanRed(){return m_meanRed[0].L();}
		int	gvTask_GetmeanGreen(){return m_meanGreen[0].L();}
		void 		gvTask_SetmeanBlue(int blue){m_meanBlue = blue;}
		void 		gvTask_SetmeanRed(int red){m_meanRed = red;}
		void 		gvTask_SetmeanGreen(int green){m_meanGreen = green;}

    protected:
    	void gvTask_ReadParam( wxXmlNode* pNode_parent );
        void gvTask_SaveParam( wxXmlNode* pNode_parent );
        bool gvTask_inspect( Hobject image_src, Hobject *outRegion_defects );
    private:
    	HTuple m_meanBlue;
    	HTuple m_meanRed;
    	HTuple  m_meanGreen;

};

#endif // GVVISIONTASK_FRONT_COLOR_H
