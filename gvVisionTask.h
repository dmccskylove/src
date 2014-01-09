#ifndef GVVISIONTASK_H
#define GVVISIONTASK_H


class gvVisionROI;

class gvVisionTask
{
    public:
        gvVisionTask( E_ROI_TYPE type );
        virtual ~gvVisionTask();

        virtual bool gvTask_inspect( Hobject image_src, Hobject *outRegion_defects) = 0;
        /**< 参数读取和保存 */
        bool gvTask_LoadConfig( wxXmlNode* pNode_parent, bool isfSettings = false );
        bool gvTask_SaveConfig( wxXmlNode* pNode_parent, bool isfSettings = false );
        virtual void gvTask_ReadParam( wxXmlNode* pNode_parent );
        virtual void gvTask_SaveParam( wxXmlNode* pNode_parent );

        E_TASK_TYPE_ALL	gvTask_GetType(){ return m_typeTask;}
        E_ROI_TYPE 			gvTask_GetRoiType(){return e_ROIType;}
        gvVisionROI* 			gvTask_GetROI(){return c_pgvVisionROI;}
    protected:
		int m_isusing;
		int m_NGCount;

		E_TASK_TYPE_ALL	m_typeTask;
		E_ROI_TYPE		e_ROIType;
		gvVisionROI *		c_pgvVisionROI;
    private:
};

#endif // GVVISIONTASK_H
