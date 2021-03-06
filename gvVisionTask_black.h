#ifndef GVVISIONTASK_FRONT_BLACK_H
#define GVVISIONTASK_FRONT_BLACK_H

#include "gvVisionTask.h"


class gvVisionTask_black : public gvVisionTask
{
    public:
        gvVisionTask_black( E_ROI_TYPE type );
        virtual ~gvVisionTask_black();

        /**<  */
		int gvTask_GetminBlackSpotArea()
		{
			return m_minBlackSpotArea;
		}
		void gvTask_SetminBlackSpotArea(int minBlackSpotArea)
		{
			m_minBlackSpotArea = minBlackSpotArea;
		}

				int gvTask_GetminBlackSpotCnt()
		{
			return m_minBlackSpotCnt;
		}
		void gvTask_SetminBlackSpotCnt(int minBlackSpotCnt)
		{
			m_minBlackSpotCnt= minBlackSpotCnt;
		}

				int gvTask_GetmaxBlackSpotCnt()
		{
			return m_maxBlackSpotCnt;
		}
		void gvTask_SetmaxBlackSpotCnt(int maxBlackSpotCnt)
		{
			m_maxBlackSpotCnt = maxBlackSpotCnt;
		}
    protected:
        void gvTask_ReadParam( wxXmlNode* pNode_parent );
        void gvTask_SaveParam( wxXmlNode* pNode_parent );
        bool gvTask_inspect( Hobject image_src, Hobject *outRegion_defects );
    private:
    	int m_minBlackSpotArea;		//黑点最小面积
//    	int m_BlackGrayDiff;			//黑点灰度敏感度
    	int m_minBlackSpotCnt ;	//黑点最小个数
    	int m_maxBlackSpotCnt ;	//黑点最大个数
};

#endif // GVVISIONTASK_FRONT_BLACK_H
