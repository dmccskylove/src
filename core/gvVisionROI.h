#ifndef GVVISIONROI_H
#define GVVISIONROI_H

#include "ISHCAPDef.h"

class gvVisionImage;
class gvVisionROI
{
    friend class gvVisionImage;
public:
    gvVisionROI( );
    virtual ~gvVisionROI();

    virtual bool gvROI_ReadParam( wxXmlNode* pNode_parent )=0;
    virtual bool gvROI_SaveParam( wxXmlNode* pNode_parent )=0;
    void 			   gvROI_SetROI(Hobject roi){ m_roi = roi;}
    Hobject         gvROI_GetROI(){return m_roi;}
protected:
private:
	Hobject	m_roi;
};

#endif // GVVISIONROI_H
