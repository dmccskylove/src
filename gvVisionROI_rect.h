#ifndef GVVISIONROI_RECT_H
#define GVVISIONROI_RECT_H

#include "core\gvVisionROI.h"


class gvVisionROI_rect : public gvVisionROI
{
	public:
		gvVisionROI_rect();
		virtual ~gvVisionROI_rect();
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
       void gvROI_SetuiWidth(int uiWidth)
    {
    	m_uiWidth = uiWidth;
    }
		void gvROI_SetuiHeight(int uiHeight)
    {
    	m_uiHeight = uiHeight;
    }
	void gvROI_SetuiOffset(int uiOffset)
    {
    	m_uiOffset = uiOffset;
    }
	int gvROI_GetX(){return m_uiX;}
	int gvROI_GetY(){return m_uiY;}
	int gvROI_GetuiWidth(){return m_uiWidth;}
	int gvROI_GetuiHeight(){return m_uiHeight;}
	int gvROI_GeuiOffset(){return m_uiOffset;}

protected:
private:
		long     m_uiX;
		long     m_uiY;
		long     m_uiWidth;
		long     m_uiHeight;
		int     m_uiOffset;
		bool    m_isUsing;
		Hobject	m_roi;
};

#endif // GVVISIONROI_RECT_H
