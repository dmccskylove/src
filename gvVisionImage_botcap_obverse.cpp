#include "gvVisionImage_botcap_obverse.h"

gvVisionImage_botcap_obverse::gvVisionImage_botcap_obverse(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight)
:gvVisionImage_botcap(pgvVisionCCD, imageWidth, imageHeight)
{
    //ctor
}

gvVisionImage_botcap_obverse::~gvVisionImage_botcap_obverse()
{
    //dtor
}

void gvVisionImage_botcap_obverse::gvIMG_ReadParam( wxXmlNode* pNode_parent )
{
	gvVisionImage_botcap::gvIMG_ReadParam(pNode_parent);
}

void gvVisionImage_botcap_obverse::gvIMG_SaveParam( wxXmlNode* pNode_parent )
{
	gvVisionImage_botcap::gvIMG_SaveParam(pNode_parent);
}

void gvVisionImage_botcap_obverse::gvIMG_ShowConfig( wxWindow *parent )
{

}

bool gvVisionImage_botcap_obverse::_insp_loc( Hobject image_src, Hobject *outRegion_loc)
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
		disp_obj(ho_Image,hl_WindowID);
		disp_obj(region_sel,hl_WindowID);
		copy_obj(region_sel, &(*outRegion_loc), 1, 1);
		return true;
	}

	return false;
}
