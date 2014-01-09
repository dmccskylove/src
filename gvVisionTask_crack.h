#ifndef GVVISIONTASK_FRONT_CRACK_H
#define GVVISIONTASK_FRONT_CRACK_H

#include "gvVisionTask.h"


class gvVisionTask_crack : public gvVisionTask
{
    public:
        gvVisionTask_crack( E_ROI_TYPE type );
        virtual ~gvVisionTask_crack();
    protected:
        bool gvTask_inspect( Hobject image_src, Hobject *outRegion_defects );
    private:
};

#endif // GVVISIONTASK_FRONT_CRACK_H
