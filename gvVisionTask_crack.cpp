#include "gvVisionTask_crack.h"

gvVisionTask_crack::gvVisionTask_crack( E_ROI_TYPE type )
:gvVisionTask(type)
{
    //ctor
}

gvVisionTask_crack::~gvVisionTask_crack()
{
    //dtor
}

bool gvVisionTask_crack::gvTask_inspect( Hobject image_src, Hobject *outRegion_defects )
{
	Hobject a;
	return false;
}
