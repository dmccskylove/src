#include "gvVisionROI_rect.h"

gvVisionROI_rect::gvVisionROI_rect():gvVisionROI()
{
		m_uiX = 0;
		m_uiY = 0;
		m_uiWidth = 100;
		m_uiHeight = 200;
		m_uiOffset= 0;
		m_isUsing = FALSE;
}

gvVisionROI_rect::~gvVisionROI_rect()
{
	//dtor
}

bool gvVisionROI_rect::gvROI_ReadParam( wxXmlNode* pNode_parent )
{
    wxXmlNode   *pNode_roi = ISHCAP_API::xml_GetNode( pNode_parent, wxT("ROI") );
    m_uiX = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_x"), 0 );
    m_uiY = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_y"), 0 );
    m_uiWidth = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_width"), 100 );
    m_uiHeight = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_height"), 200 );
    m_uiOffset = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_offset"), 0 );
    m_isUsing = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_isUsing"), 1 ) > 0;

    return true;
}

bool gvVisionROI_rect::gvROI_SaveParam( wxXmlNode* pNode_parent )
{
    wxXmlNode* pNode_roi = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("ROI") );
    pNode_parent->AddChild( pNode_roi );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_x"), m_uiX );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_y"), m_uiY );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_width"), m_uiWidth );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_height"), m_uiHeight );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_offset"), m_uiOffset );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_isUsing"), (long)m_isUsing );

    return true;
}
