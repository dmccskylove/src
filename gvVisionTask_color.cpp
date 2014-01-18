#include "gvVisionTask_color.h"
#include "core\gvVisionROI.h"

gvVisionTask_color::gvVisionTask_color( E_ROI_TYPE type )
:gvVisionTask(type)
{
    m_typeTask = TASKTYPE_COLOR;
    m_meanBlue=0;
    m_meanGreen=0;
    m_meanRed=0;
}

gvVisionTask_color::~gvVisionTask_color()
{
    //dtor
}



bool gvVisionTask_color::gvTask_inspect( Hobject image_src, Hobject *outRegion_defects )
{
	// Local iconic variables
	Hobject  ImageReduced, Red, Green, Blue;

	// Local control variables
	HTuple  Mean_red, Deviation, Mean_green, Mean_blue;
	HTuple  temp_sum, temp_plus, Sqrt;

	reduce_domain(image_src, gvTask_GetROI()->gvROI_GetROI(), &ImageReduced);
	decompose3(ImageReduced, &Red, &Green, &Blue);
	intensity(ImageReduced, Red, &Mean_red, &Deviation);
	intensity(ImageReduced, Green, &Mean_green, &Deviation);
	intensity(ImageReduced, Blue, &Mean_blue, &Deviation);
	temp_sum = 0;
	temp_plus = (Mean_blue-m_meanBlue)*(Mean_blue-m_meanBlue);
	tuple_add(temp_sum, temp_plus, &temp_sum);
	temp_plus = (Mean_green-m_meanGreen)*(Mean_green-m_meanGreen);
	tuple_add(temp_sum, temp_plus, &temp_sum);
	temp_plus = (Mean_red-m_meanRed)*(Mean_red-m_meanRed);
	tuple_add(temp_sum, temp_plus, &temp_sum);
	tuple_sqrt(temp_sum, &Sqrt);
	if  (Sqrt>10)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void gvVisionTask_color::gvTask_ReadParam( wxXmlNode* pNode_parent )
{
    gvVisionTask::gvTask_ReadParam(pNode_parent);

	m_meanBlue=ISHCAP_API::xml_GetNodeValueL(pNode_parent,wxT("meanBlue"),0);
	m_meanRed=ISHCAP_API::xml_GetNodeValueL(pNode_parent,wxT("meanRed"),0);
	m_meanGreen=ISHCAP_API::xml_GetNodeValueL(pNode_parent,wxT("meanGreen"),0);
}

void gvVisionTask_color::gvTask_SaveParam( wxXmlNode* pNode_parent )
{
    gvVisionTask::gvTask_SaveParam(pNode_parent);
		ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("meanBlue"),m_meanBlue[0].L());
		ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("meanRed"),m_meanRed[0].L());
		ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("meanGreen"),m_meanGreen[0].L() );

}
