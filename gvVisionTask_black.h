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
    	int m_minBlackSpotArea;		//�ڵ���С���
    	int m_BlackGrayDiff;			//�ڵ�Ҷ����ж�
    	int m_minBlackSpotCnt ;	//�ڵ���С����
    	int m_maxBlackSpotCnt ;	//�ڵ�������
};

#endif // GVVISIONTASK_FRONT_BLACK_H
