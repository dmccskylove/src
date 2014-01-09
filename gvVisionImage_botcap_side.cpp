#include "gvVisionImage_botcap_side.h"

gvVisionImage_botcap_side::gvVisionImage_botcap_side(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight)
:gvVisionImage_botcap(pgvVisionCCD, imageWidth, imageHeight)
{
    //ctor
}

gvVisionImage_botcap_side::~gvVisionImage_botcap_side()
{
    //dtor
}

void gvVisionImage_botcap_side::gvIMG_ReadParam( wxXmlNode* pNode_parent )
{
	gvVisionImage_botcap::gvIMG_ReadParam(pNode_parent);
}

void gvVisionImage_botcap_side::gvIMG_SaveParam( wxXmlNode* pNode_parent )
{
	gvVisionImage_botcap::gvIMG_SaveParam(pNode_parent);
}

void gvVisionImage_botcap_side::gvIMG_ShowConfig( wxWindow *parent )
{

}

bool gvVisionImage_botcap_side::_insp_loc( Hobject image_src, Hobject *outRegion_loc)
{
	return false;
}
