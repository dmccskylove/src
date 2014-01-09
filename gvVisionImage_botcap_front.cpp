#include "gvVisionImage_botcap_front.h"


gvVisionImage_botcap_front::gvVisionImage_botcap_front(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight)
:gvVisionImage_botcap(pgvVisionCCD, imageWidth, imageHeight)
{

}

gvVisionImage_botcap_front::~gvVisionImage_botcap_front()
{
    //dtor
}

bool gvVisionImage_botcap_front::_insp_loc( Hobject image_src, Hobject *outRegion_loc)
{
	// Local iconic variables
	Hobject  ImageMean, region_thre, region_fillup;
	Hobject  region_erosion, region_dilation, region_conn, region_sel;

	// Local control variables
	Hlong  numRegions;

	gen_empty_obj(&(*outRegion_loc));

	mean_image(image_src, &ImageMean, 31, 31);
	dyn_threshold(image_src, ImageMean, &region_thre, 5, "light");
	fill_up(region_thre, &region_fillup);
	erosion_circle(region_fillup, &region_erosion, 5.5);
	dilation_circle(region_erosion, &region_dilation, 5.5);
	connection(region_dilation, &region_conn);
	select_shape(region_conn, &region_sel, "area", "and", m_minarea, 999999);
	count_obj(region_sel, &numRegions);
	if ( 1 == numRegions )
	{
		copy_obj(region_sel, &(*outRegion_loc), 1, 1);
		return true;
	}

	return false;
}

void gvVisionImage_botcap_front::gvIMG_ReadParam( wxXmlNode* pNode_parent )
{
		gvVisionImage_botcap::gvIMG_ReadParam(pNode_parent);
}

void gvVisionImage_botcap_front::gvIMG_SaveParam( wxXmlNode* pNode_parent )
{
		gvVisionImage_botcap::gvIMG_SaveParam(pNode_parent);
}

void gvVisionImage_botcap_front::gvIMG_ShowConfig( wxWindow *parent )
{

}



