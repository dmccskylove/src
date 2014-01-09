#ifndef GVVISIONIMAGE_FRONT_H
#define GVVISIONIMAGE_FRONT_H

#include "gvVisionImage_botcap.h"
#include"gvVisionTask_black.h"
#include"gvVisionTask_logo.h"
class gvVisionTask;
class gvVisionImage_botcap_front : public gvVisionImage_botcap
{
    public:
        gvVisionImage_botcap_front(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight);
        virtual ~gvVisionImage_botcap_front();

        void gvIMG_ReadParam( wxXmlNode* pNode_parent );
        void gvIMG_SaveParam( wxXmlNode* pNode_parent );
        void gvIMG_ShowConfig( wxWindow *parent );
    protected:


    private:
    	bool _insp_loc( Hobject image_src, Hobject *outRegion_loc);
};

#endif // GVVISIONIMAGE_FRONT_H
