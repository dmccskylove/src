#ifndef GVVISIONROI_CIRCLE_H
#define GVVISIONROI_CIRCLE_H

#include "core\gvVisionROI.h"


class gvVisionROI_circle : public gvVisionROI
{
	public:
		gvVisionROI_circle();
		virtual ~gvVisionROI_circle();
	bool gvROI_ReadParam( wxXmlNode* pNode_parent );
    bool gvROI_SaveParam( wxXmlNode* pNode_parent );

    bool isUsing()
    {
        return m_isUsing;
    }

    void gvROI_SetX(int x)
    {
    	m_uiX = x;
    }
       void gvROI_SetY(int y)
    {
    	m_uiY = y;
    }
       void gvROI_SetoutRadius(int outRadius)
    {
    	m_outRadius = outRadius;
    }
		void gvROI_SetinRadius(int inRadius)
    {
    	m_inRadius = inRadius;
    }
	int gvROI_GetX(){return m_uiX;}
	int gvROI_GetY(){return m_uiY;}
	int gvROI_GetoutRadius(){return m_outRadius;}
	int gvROI_GetinRadius(){return m_inRadius;}
	protected:
	private:
		int m_uiX;
		int m_uiY;
		int m_outRadius;
		int m_inRadius;
		bool    m_isUsing;
		Hobject	m_outcle;
		Hobject	m_incle;

};

#endif // GVVISIONROI_CIRCLE_H
