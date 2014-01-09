#include "gvVisionROI_circle.h"

gvVisionROI_circle::gvVisionROI_circle():gvVisionROI()
{
		m_uiX = 250;
		m_uiY = 300;
		m_outRadius =100;
		m_inRadius = 50;
		m_isUsing = FALSE;
}

gvVisionROI_circle::~gvVisionROI_circle()
{
	//dtor
}

bool gvVisionROI_circle::gvROI_ReadParam( wxXmlNode* pNode_parent )
{
    wxXmlNode   *pNode_roi = ISHCAP_API::xml_GetNode( pNode_parent, wxT("ROI") );
    m_uiX = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_x"), 250 );
    m_uiY = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_y"), 300 );
    m_outRadius = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_outRadius"), 100 );
    m_inRadius = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_inRadius"), 50 );
    m_isUsing = ISHCAP_API::xml_GetNodeValueL(pNode_roi, wxT("roi_isUsing"), 1 ) > 0;

    return true;
}

bool gvVisionROI_circle::gvROI_SaveParam( wxXmlNode* pNode_parent )
{
    wxXmlNode* pNode_roi = new wxXmlNode( wxXML_ELEMENT_NODE, wxT("ROI") );
    pNode_parent->AddChild( pNode_roi );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_x"), m_uiX );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_y"), m_uiY );
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_outRadius"), m_outRadius );
	ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_inRadius"), m_inRadius);
    ISHCAP_API::xml_SetNodeValueL(pNode_roi, wxT("roi_isUsing"), (long)m_isUsing );
    return true;
}


