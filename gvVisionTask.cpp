#include "gvVisionTask.h"
#include "gvVisionROI_circle.h"
#include "gvVisionROI_rect.h"
#include "core\gvVisionROI.h"

gvVisionTask::gvVisionTask( E_ROI_TYPE type )
{
	e_ROIType = type;
		switch(e_ROIType)
	{
	case ROITYPE_CIRCLE:
		c_pgvVisionROI = new gvVisionROI_circle();
		break;
	case ROITYPE_RECT:
		c_pgvVisionROI = new gvVisionROI_rect();
	break;
	default:break;
	}
}

gvVisionTask::~gvVisionTask()
{
    //dtor
}

void gvVisionTask::gvTask_ReadParam( wxXmlNode* pNode_parent )
{
		switch(e_ROIType)
	{
	case ROITYPE_CIRCLE:
		c_pgvVisionROI = new gvVisionROI_circle();
		break;
	case ROITYPE_RECT:
		c_pgvVisionROI = new gvVisionROI_rect();
	break;
	default:break;
	}
	if( c_pgvVisionROI )
	{
		c_pgvVisionROI->gvROI_ReadParam(pNode_parent);
	}
}

void gvVisionTask::gvTask_SaveParam( wxXmlNode* pNode_parent )
{
	ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("tasktype"),m_typeTask);
	ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("ROITYPE"),e_ROIType);

	if(c_pgvVisionROI)
	{
		c_pgvVisionROI->gvROI_SaveParam(pNode_parent);
	}
}




