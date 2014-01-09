#ifndef GVVISIONTASK_FRONT_BLACK_H
#define GVVISIONTASK_FRONT_BLACK_H

#include "gvVisionTask.h"


class gvVisionTask_black : public gvVisionTask
{
    public:
        gvVisionTask_black( E_ROI_TYPE type );
        virtual ~gvVisionTask_black();

        /**<  */
		int gvTask_GetGraySense()
		{
			return m_BlackGrayDiff;
		}
		void gvTask_SetGarySense(int gray)
		{
			m_BlackGrayDiff = gray;
		}
    protected:
        void gvTask_ReadParam( wxXmlNode* pNode_parent );
        void gvTask_SaveParam( wxXmlNode* pNode_parent );
        bool gvTask_inspect( Hobject image_src, Hobject *outRegion_defects );
    private:
    	int m_minBlackSpotArea;		//黑点最小面积
    	int m_BlackGrayDiff;			//黑点灰度敏感度
    	int m_minBlackSpotCnt ;	//黑点最小个数
    	int m_maxBlackSpotCnt ;	//黑点最大个数
};

#endif // GVVISIONTASK_FRONT_BLACK_H
