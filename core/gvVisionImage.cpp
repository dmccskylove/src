#include "gvVisionManager.h"
#include "gvVisionCCD.h"
#include "gvVisionImage.h"
#include "gvVisionROI.h"

gvVisionImage::gvVisionImage(gvVisionCCD* pgvVisionCCD, int imageWidth,  int imageHeight)
{
    wxASSERT(pgvVisionCCD);
    c_pgvVisionCCD = pgvVisionCCD;
    m_imgWidth = imageWidth;
    m_imgHeight = imageHeight;
    m_isSaveNGImages = false;
    c_pBitsR = new BYTE[imageWidth*imageHeight];
    c_pBitsG = new BYTE[imageWidth*imageHeight];
    c_pBitsB = new BYTE[imageWidth*imageHeight];

    m_idxActiveROI = -1;
}

gvVisionImage::~gvVisionImage(void)
{
    if( c_pBitsR )
    {
        delete c_pBitsR;
        c_pBitsR = nullptr;
    }
    if( c_pBitsG )
    {
        delete c_pBitsG;
        c_pBitsG = nullptr;
    }
    if( c_pBitsB )
    {
        delete c_pBitsB;
        c_pBitsB = nullptr;
    }
}

bool gvVisionImage::gvIMG_LoadConfig( wxXmlNode* pNode_parent, bool isfSettings )
{
    wxXmlNode   *pNode_Img = ISHCAP_API::xml_GetNode( pNode_parent, wxT("IMAGE") );

    m_isSaveNGImages = ISHCAP_API::xml_GetNodeValueL(pNode_Img, wxT("imgSaveNGs"), 0) > 0;
    gvIMG_ReadParam( pNode_Img );

    return true;
}

bool gvVisionImage::gvIMG_SaveConfig( wxXmlNode* pNode_parent, bool isfSettings )
{
    wxXmlNode* pNode_Img = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("IMAGE"));
    pNode_parent->AddChild( pNode_Img );

    if( isfSettings )
    {
    }
    else
    {
        ISHCAP_API::xml_SetNodeValueL(pNode_Img, wxT("imgSaveNGs"), 0 );
        gvIMG_SaveParam( pNode_Img );
    }

    return true;
}

unsigned int	gvVisionImage::gvIMG_getROISum()
{
    int retVal = 0;

    switch( c_pgvVisionCCD->get_idxCam() )
    {
    case 0:
        retVal = 3;
        break;
    case 1:
        retVal = 3;
        break;
    case 2:
        retVal = 2;
        break;
    case 3:
        retVal = 2;
        break;
    case 4:
        retVal = 3;
        break;
    default:
        break;
    }//switch( g_FactorySettings[idxCam].cam_Function )

    return retVal;
}

void gvVisionImage::gvIMG_GetBits( BYTE* imgBuffer, int imgWidth, int imgHeight)
{
    int iIndex, jIndex;

    int idxCam = c_pgvVisionCCD->get_idxCam();
    switch(idxCam)
    {
    case 0:
    case 1:
        //memcpy( c_pBitsR, imgBuffer, imgWidth * imgHeight );
        //break;
    case 2:
    case 3:
    case 4:
        for ( iIndex=0; iIndex<imgHeight; iIndex++)
        {
            for ( jIndex=0; jIndex<imgWidth; jIndex++)
            {
                int pixel_Index = iIndex*imgWidth+jIndex;
                c_pBitsR[pixel_Index] = imgBuffer[3*pixel_Index + 0 ];
                c_pBitsG[pixel_Index] = imgBuffer[3*pixel_Index + 1 ];
                c_pBitsB[pixel_Index] = imgBuffer[3*pixel_Index + 2 ];
            }//for ( jIndex=0;jIndex<imgWidth;jIndex++)
        }//for ( iIndex=0; iIndex<imgHeight; iIndex++)
        break;
    default:
        break;
    }
}
