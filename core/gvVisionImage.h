#pragma once

#include "ISHCAPDef.h"

class gvVisionCCD;
class gvVisionImage : wxObject
{
public:
    gvVisionImage(gvVisionCCD* pgvVisionCCD, int imageWidth, int imageHeight);
    ~gvVisionImage(void);


    virtual void gvIMG_TriggerInspection( bool isTest = false ) = 0;
    virtual void gvIMG_ReadParam( wxXmlNode* pNode_parent ) = 0;
    virtual void gvIMG_SaveParam( wxXmlNode* pNode_parent ) = 0;
    virtual void gvIMG_ShowConfig( wxWindow *parent ) = 0;
    virtual void gvIMG_LoadImage( wxString filename ) = 0;
    virtual void gvIMG_SaveImage( wxString filename ) = 0;
    virtual void gvIMG_DrawImage( bool isDrawRoi = false ) = 0;
    virtual bool gvIMG_ConvertImage() = 0;


    /**<  */
    void gvIMG_GetBits( BYTE* imgBuffer, int imgWidth, int imgHeight);
    /**< 当pBitsB的指针不为空时，认为是彩色图像；否则，只使用pBitsR */

    bool gvIMG_LoadConfig( wxXmlNode* pNode_parent, bool isfSettings = false );
    bool gvIMG_SaveConfig( wxXmlNode* pNode_parent, bool isfSettings = false );

    void            gvIMG_TransferErrorCode();
    void            gvIMG_GetGray( int row, int column, double *r, double *g, double *b );
    unsigned int	gvIMG_getROISum();
    void            gvIMG_ShowAllROI();

    int				m_idxActiveROI;
protected:
    gvVisionCCD		*c_pgvVisionCCD;
    BYTE    *c_pBitsR, *c_pBitsG, *c_pBitsB;
    int	    m_imgWidth;
    int	    m_imgHeight;
    bool    m_isSaveNGImages;
};

