#include "gvVisionTask_black.h"
#include "core\gvVisionROI.h"

gvVisionTask_black::gvVisionTask_black( E_ROI_TYPE type )
:gvVisionTask(type)
{
	m_typeTask = TASKTYPE_BLACK;

}

gvVisionTask_black::~gvVisionTask_black()
{
    //dtor
}

bool gvVisionTask_black::gvTask_inspect( Hobject image_src, Hobject *outRegion_defects )
{
	// Local iconic variables
	Hobject  TMP_Region, Region1, RegionErosion1,ImageReduced;
	Hobject  Image_meanSmall, Image_meanLarge, RegionDynThresh;
	Hobject  ConnectedRegions, RegionFillUp, RegionErosion, ConnectedRegions1;
	Hobject  SelectedRegions, RegionDilation1, RegionDilation;
	Hobject  RegionDifference, obj_selected;


	// Local control variables
	HTuple  Meancenter, Deviation, Meanouter, Deviation1;
	HTuple  Index, Number;

//	reduce_domain(image_src, gvTask_GetROI()->gvROI_GetROI(), &ImageReduced);
	reduce_domain(image_src, gvTask_GetROI()->gvROI_GetROI(), &ImageReduced);
	threshold(ImageReduced, &Region1, 100, 255);
	fill_up(Region1, &Region1);
	erosion_circle(Region1, &RegionErosion1, 20);
	mean_image(ImageReduced, &Image_meanSmall, 2, 2);
	mean_image(ImageReduced, &Image_meanLarge, 20, 20);
	dyn_threshold(Image_meanSmall, Image_meanLarge, &RegionDynThresh, 5, "dark");
	connection(RegionDynThresh, &ConnectedRegions);
	fill_up(ConnectedRegions, &RegionFillUp);


	erosion_circle(RegionFillUp, &RegionErosion, 1.5);
	connection(RegionErosion, &ConnectedRegions1);

	select_shape(ConnectedRegions1, &SelectedRegions, "area", "and", m_minBlackSpotArea, 5000);
	dilation_circle(SelectedRegions, &RegionDilation1, 2.5);
	intensity(RegionDilation1, Image_meanSmall, &Meancenter, &Deviation);
	dilation_circle(SelectedRegions, &RegionDilation, 5);
	difference(RegionDilation, SelectedRegions, &RegionDifference);
	intensity(RegionDifference, Image_meanSmall, &Meanouter, &Deviation1);
	gen_empty_obj(&(*outRegion_defects));
	for (Index=0; Index<=(Meancenter.Num())-1; Index+=1)
	{
		select_obj(SelectedRegions, &obj_selected, Index+1);
		if (0 != ((HTuple(Meancenter[Index])-HTuple(Meanouter[Index]))<-30))
		{
		  concat_obj((*outRegion_defects), obj_selected, &(*outRegion_defects));

		}
	}
	count_obj((*outRegion_defects), &Number);
	if(Number>m_maxBlackSpotCnt||Number<m_minBlackSpotCnt )
	{
		return FALSE;
	}
	return TRUE;
}

void gvVisionTask_black::gvTask_ReadParam( wxXmlNode* pNode_parent )
{
    gvVisionTask::gvTask_ReadParam(pNode_parent);

	m_minBlackSpotArea=ISHCAP_API::xml_GetNodeValueL(pNode_parent,wxT("黑点最小面积"),0);

	m_minBlackSpotCnt=ISHCAP_API::xml_GetNodeValueL(pNode_parent,wxT("黑点最小个数"),0);
	m_maxBlackSpotCnt =ISHCAP_API::xml_GetNodeValueL(pNode_parent,wxT("黑点最大个数"),0);


}

void gvVisionTask_black::gvTask_SaveParam( wxXmlNode* pNode_parent )
{
    gvVisionTask::gvTask_SaveParam(pNode_parent);
		ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("黑点最小面积"),m_minBlackSpotArea);

		ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("黑点最小个数"),m_minBlackSpotCnt );
		ISHCAP_API::xml_SetNodeValueL(pNode_parent,wxT("黑点最大个数"),m_maxBlackSpotCnt);
}


