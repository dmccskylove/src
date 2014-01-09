#ifndef GVVISIONIMAGE_SIDE_H
#define GVVISIONIMAGE_SIDE_H

#include "gvVisionImage_botcap.h"

class gvVisionImage_botcap_side : public gvVisionImage_botcap
{
    public:
        gvVisionImage_botcap_side(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight);
        virtual ~gvVisionImage_botcap_side();

        void gvIMG_ReadParam( wxXmlNode* pNode_parent );
        void gvIMG_SaveParam( wxXmlNode* pNode_parent );
        void gvIMG_ShowConfig( wxWindow *parent );
    protected:
    private:
    	bool _insp_loc( Hobject image_src, Hobject *outRegion_loc);
};

#endif // GVVISIONIMAGE_SIDE_H
