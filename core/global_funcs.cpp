#include <wx/xml/xml.h>

namespace ISHCAP_API
{

wxXmlNode* xml_GetNode( wxXmlNode* pNode_parent, wxString strNodeName )
{
    if (NULL == pNode_parent )
    {
        return nullptr;
    }

    wxXmlNode* pNode_ret = NULL;
    wxXmlNode* pNode = pNode_parent->GetChildren();
    while( pNode )
    {
        if( strNodeName == pNode->GetName() )
        {
            pNode_ret = pNode;
            break;
        }
        pNode = pNode->GetNext();
    }//while( pNode )

    return pNode_ret;
}

/***/
wxString xml_GetNodeValueS( wxXmlNode* pNode_parent, wxString strNodeName, wxString default_value )
{
    if ( NULL == pNode_parent )
    {
        return default_value;
    }

    wxString strVal = default_value;

    wxXmlNode* pNode1 = pNode_parent->GetChildren();
    while( pNode1 )
    {
        if( strNodeName == pNode1->GetName() )
        {
            wxXmlNode* pNode2 = pNode1->GetChildren();
            if( pNode2 )
            {
                strVal = pNode2->GetContent();
            }
            break;
        }
        pNode1 = pNode1->GetNext();
    }//while( pNode1 )

    return strVal;
}

double    xml_GetNodeValueF( wxXmlNode* pNode_parent, wxString strNodeName, double default_value )
{
    if ( NULL == pNode_parent )
    {
        return default_value;
    }

    double dfVal = default_value;
    wxString strVal = wxEmptyString;

    wxXmlNode* pNode1 = pNode_parent->GetChildren();
    while( pNode1 )
    {
        if( strNodeName == pNode1->GetName() )
        {
            wxXmlNode* pNode2 = pNode1->GetChildren();
            if( pNode2 )
            {
                strVal = pNode2->GetContent();
                strVal.ToDouble( &dfVal );
            }
            break;
        }
        pNode1 = pNode1->GetNext();
    }//while( pNode1 )

    return dfVal;
}

long    xml_GetNodeValueL( wxXmlNode* pNode_parent, wxString strNodeName, long default_value )
{
    if ( NULL == pNode_parent )
    {
        return default_value;
    }

    long lVal = default_value;
    wxString strVal = wxEmptyString;

    wxXmlNode* pNode1 = pNode_parent->GetChildren();
    while( pNode1 )
    {
        if( strNodeName == pNode1->GetName() )
        {
            wxXmlNode* pNode2 = pNode1->GetChildren();
            if( pNode2 )
            {
                strVal = pNode2->GetContent();
                strVal.ToLong( &lVal );
            }
            break;
        }
        pNode1 = pNode1->GetNext();
    }//while( pNode1 )

    return lVal;
}

bool xml_SetNodeValueS( wxXmlNode* pNode_parent,
                        wxString strNodeName,
                        wxString strVal,
                        wxString comment)
{
    bool isNode_find = false;
    wxXmlNode* pNode1 = pNode_parent->GetChildren();
    wxXmlNode* pNode2 = NULL;
    while( pNode1 )
    {
        if( strNodeName == pNode1->GetName() )
        {
            isNode_find = true;
            break;
        }
        pNode1 = pNode1->GetNext();
    }//while( pNode1 )

    if( isNode_find )
    {
        pNode1->SetContent( strVal );
    }
    else
    {
        pNode1 = new wxXmlNode( wxXML_ELEMENT_NODE, strNodeName );
        pNode2 = new wxXmlNode( wxXML_TEXT_NODE, strNodeName, strVal );
        pNode1->AddChild( pNode2 );
        pNode_parent->AddChild( pNode1 );
    }
    return true;
}

bool xml_SetNodeValueF( wxXmlNode* pNode_parent,
                        wxString strNodeName,
                        double   dfVal,
                        wxString comment)
{
    bool isNode_find = false;
    wxXmlNode* pNode1 = pNode_parent->GetChildren();
    wxXmlNode* pNode2 = NULL;
    while( pNode1 )
    {
        if( strNodeName == pNode1->GetName() )
        {
            isNode_find = true;
            break;
        }
        pNode1 = pNode1->GetNext();
    }//while( pNode1 )

    if( isNode_find )
    {
        pNode1->SetContent( wxString::Format(wxT("%.3f"), dfVal) );
    }
    else
    {
        pNode1 = new wxXmlNode( wxXML_ELEMENT_NODE, strNodeName );
        pNode2 = new wxXmlNode( wxXML_TEXT_NODE, strNodeName, wxString::Format(wxT("%.3f"), dfVal) );
        pNode1->AddChild( pNode2 );
        pNode_parent->AddChild( pNode1 );
    }
    return true;
}

bool xml_SetNodeValueL( wxXmlNode* pNode_parent,
                        wxString strNodeName,
                        long     lVal,
                        wxString comment )
{
    bool isNode_find = false;
    wxXmlNode* pNode1 = pNode_parent->GetChildren();
    wxXmlNode* pNode2 = NULL;
    while( pNode1 )
    {
        if( strNodeName == pNode1->GetName() )
        {
            isNode_find = true;
            break;
        }
        pNode1 = pNode1->GetNext();
    }//while( pNode1 )

    if( isNode_find )
    {
        pNode1->SetContent( wxString::Format(wxT("%d"), lVal) );
    }
    else
    {
        pNode1 = new wxXmlNode( wxXML_ELEMENT_NODE, strNodeName );
        pNode2 = new wxXmlNode( wxXML_TEXT_NODE, strNodeName, wxString::Format(wxT("%d"), lVal) );
        pNode1->AddChild( pNode2 );
        pNode_parent->AddChild( pNode1 );
    }
    return true;
}
}

