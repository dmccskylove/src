#ifndef GVVISIONIMAGE_OBVERSE_H
#define GVVISIONIMAGE_OBVERSE_H

#include "gvVisionImage_botcap.h"

class gvVisionImage_botcap_obverse : public gvVisionImage_botcap
{
    public:
        gvVisionImage_botcap_obverse(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight);
        virtual ~gvVisionImage_botcap_obverse();

        void gvIMG_ReadParam( wxXmlNode* pNode_parent );
        void gvIMG_SaveParam( wxXmlNode* pNode_parent );
        void gvIMG_ShowConfig( wxWindow *parent );
    protected:
    private:
    	bool _insp_loc( Hobject image_src, Hobject *outRegion_loc);
};

#endif // GVVISIONIMAGE_OBVERSE_H
