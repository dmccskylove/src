/////////////////////////////////////////////////////////////////////////////
// Name:        dlgarticlenew.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     30/12/2013 15:49:11
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes


#include "core/gvVisionManager.h"

#include "dlgarticlenew.h"

////@begin XPM images
////@end XPM images


/*
 * dlgArticleNew type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dlgArticleNew, wxDialog )


/*
 * dlgArticleNew event table definition
 */

BEGIN_EVENT_TABLE( dlgArticleNew, wxDialog )

////@begin dlgArticleNew event table entries
    EVT_CHECKBOX( ID_CHK_CAM1, dlgArticleNew::OnChkCam1Click )
    EVT_UPDATE_UI( ID_CHK_CAM1, dlgArticleNew::OnChkCam1Update )

    EVT_CHECKBOX( ID_CHK_CAM2, dlgArticleNew::OnChkCam2Click )
    EVT_UPDATE_UI( ID_CHK_CAM2, dlgArticleNew::OnChkCam2Update )

    EVT_CHECKBOX( ID_CHK_CAM3, dlgArticleNew::OnChkCam3Click )
    EVT_UPDATE_UI( ID_CHK_CAM3, dlgArticleNew::OnChkCam3Update )

    EVT_CHECKBOX( ID_CHK_CAM4, dlgArticleNew::OnChkCam4Click )
    EVT_UPDATE_UI( ID_CHK_CAM4, dlgArticleNew::OnChkCam4Update )

    EVT_CHECKBOX( ID_CHK_CAM5, dlgArticleNew::OnChkCam5Click )
    EVT_UPDATE_UI( ID_CHK_CAM5, dlgArticleNew::OnChkCam5Update )

    EVT_CHECKBOX( ID_CHK_CAM6, dlgArticleNew::OnChkCam6Click )
    EVT_UPDATE_UI( ID_CHK_CAM6, dlgArticleNew::OnChkCam6Update )

    EVT_TEXT( ID_TEXTCTRL_COLORA, dlgArticleNew::OnTextctrlColoraTextUpdated )

    EVT_UPDATE_UI( ID_TEXTCTRL_ARTICLENAME, dlgArticleNew::OnTextctrlArticlenameUpdate )

    EVT_BUTTON( wxID_CANCEL, dlgArticleNew::OnCancelClick )

    EVT_BUTTON( wxID_OK, dlgArticleNew::OnOkClick )

////@end dlgArticleNew event table entries

END_EVENT_TABLE()


/*
 * dlgArticleNew constructors
 */

dlgArticleNew::dlgArticleNew()
{
    Init();
}

dlgArticleNew::dlgArticleNew( gvVisionManager *pgvVisionManager, wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
	wxASSERT(pgvVisionManager);
	c_pgvVisionManager = pgvVisionManager;
	/**<  */
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * dlgArticleNew creator
 */

bool dlgArticleNew::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlgArticleNew creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dlgArticleNew creation
    return true;
}


/*
 * dlgArticleNew destructor
 */

dlgArticleNew::~dlgArticleNew()
{
////@begin dlgArticleNew destruction
////@end dlgArticleNew destruction
}


/*
 * Member initialisation
 */

void dlgArticleNew::Init()
{
	int iIndex = 0;
	for(iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++)
	{
		m_camIsUsing[iIndex] = 0;
		m_typCam[iIndex ] = CCDROLE_SIDE;
	}
	m_camIsUsing[0] = 1;
	m_typCam[0 ] = CCDROLE_FRONT;
	m_typCam[1 ] = CCDROLE_OBVERSE;
////@begin dlgArticleNew member initialisation
    m_txtColorA = NULL;
    m_txtTitle = NULL;
////@end dlgArticleNew member initialisation

}


/*
 * Control creation for dlgArticleNew
 */

void dlgArticleNew::CreateControls()
{
////@begin dlgArticleNew content construction
    dlgArticleNew* itemDialog1 = this;

    this->SetFont(wxFont(11, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("微软雅黑")));
    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(itemDialog1, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x8BF7 + (wxChar) 0x9009 + (wxChar) 0x62E9 + (wxChar) 0x76F8 + (wxChar) 0x673A + (wxChar) 0x53CA + (wxChar) 0x529F + (wxChar) 0x80FD));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxHORIZONTAL);
    itemBoxSizer2->Add(itemStaticBoxSizer3, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer3->Add(itemBoxSizer4, 0, wxGROW|wxALL, 5);

    wxCheckBox* itemCheckBox5 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM1, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("1")), wxDefaultPosition, wxSize(-1, 27), 0 );
    itemCheckBox5->SetValue(true);
    itemBoxSizer4->Add(itemCheckBox5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxCheckBox* itemCheckBox6 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM2, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("2")), wxDefaultPosition, wxSize(-1, 28), 0 );
    itemCheckBox6->SetValue(false);
    itemCheckBox6->Enable(false);
    itemBoxSizer4->Add(itemCheckBox6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxCheckBox* itemCheckBox7 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM3, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("3")), wxDefaultPosition, wxSize(-1, 28), 0 );
    itemCheckBox7->SetValue(false);
    itemCheckBox7->Enable(false);
    itemBoxSizer4->Add(itemCheckBox7, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer3->Add(itemBoxSizer8, 0, wxGROW|wxALL, 5);

    wxArrayString itemChoice9Strings;
    itemChoice9Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    itemChoice9Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    itemChoice9Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    wxChoice* itemChoice9 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM1, wxDefaultPosition, wxDefaultSize, itemChoice9Strings, 0 );
    itemChoice9->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    itemChoice9->Enable(false);
    itemBoxSizer8->Add(itemChoice9, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxArrayString itemChoice10Strings;
    itemChoice10Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    itemChoice10Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    itemChoice10Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    wxChoice* itemChoice10 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM2, wxDefaultPosition, wxDefaultSize, itemChoice10Strings, 0 );
    itemChoice10->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    itemChoice10->Enable(false);
    itemBoxSizer8->Add(itemChoice10, 0, wxGROW|wxALL, 2);

    wxArrayString itemChoice11Strings;
    itemChoice11Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    itemChoice11Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    itemChoice11Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    wxChoice* itemChoice11 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM3, wxDefaultPosition, wxDefaultSize, itemChoice11Strings, 0 );
    itemChoice11->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    itemChoice11->Enable(false);
    itemBoxSizer8->Add(itemChoice11, 0, wxGROW|wxALL, 2);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer3->Add(itemBoxSizer12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxCheckBox* itemCheckBox13 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM4, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("4")), wxDefaultPosition, wxSize(-1, 28), 0 );
    itemCheckBox13->SetValue(false);
    itemCheckBox13->Enable(false);
    itemBoxSizer12->Add(itemCheckBox13, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxCheckBox* itemCheckBox14 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM5, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("5")), wxDefaultPosition, wxSize(-1, 28), 0 );
    itemCheckBox14->SetValue(false);
    itemCheckBox14->Enable(false);
    itemBoxSizer12->Add(itemCheckBox14, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxCheckBox* itemCheckBox15 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM6, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("6")), wxDefaultPosition, wxSize(-1, 28), 0 );
    itemCheckBox15->SetValue(false);
    itemCheckBox15->Enable(false);
    itemBoxSizer12->Add(itemCheckBox15, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer16 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer3->Add(itemBoxSizer16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString itemChoice17Strings;
    itemChoice17Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    itemChoice17Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    itemChoice17Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    wxChoice* itemChoice17 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM4, wxDefaultPosition, wxDefaultSize, itemChoice17Strings, 0 );
    itemChoice17->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    itemChoice17->Enable(false);
    itemBoxSizer16->Add(itemChoice17, 0, wxGROW|wxALL, 2);

    wxArrayString itemChoice18Strings;
    itemChoice18Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    itemChoice18Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    itemChoice18Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    wxChoice* itemChoice18 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM5, wxDefaultPosition, wxDefaultSize, itemChoice18Strings, 0 );
    itemChoice18->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    itemChoice18->Enable(false);
    itemBoxSizer16->Add(itemChoice18, 0, wxGROW|wxALL, 2);

    wxArrayString itemChoice19Strings;
    itemChoice19Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    itemChoice19Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    itemChoice19Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    wxChoice* itemChoice19 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM6, wxDefaultPosition, wxDefaultSize, itemChoice19Strings, 0 );
    itemChoice19->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    itemChoice19->Enable(false);
    itemBoxSizer16->Add(itemChoice19, 0, wxGROW|wxALL, 2);

    wxStaticBox* itemStaticBoxSizer20Static = new wxStaticBox(itemDialog1, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x540D + (wxChar) 0x79F0 + (wxChar) 0x4E2A + (wxChar) 0x6027 + (wxChar) 0x5316));
    wxStaticBoxSizer* itemStaticBoxSizer20 = new wxStaticBoxSizer(itemStaticBoxSizer20Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer20, 0, wxGROW|wxALL, 5);

    m_txtColorA = new wxTextCtrl( itemStaticBoxSizer20->GetStaticBox(), ID_TEXTCTRL_COLORA, wxEmptyString, wxDefaultPosition, wxSize(300, -1), 0 );
    itemStaticBoxSizer20->Add(m_txtColorA, 0, wxGROW|wxTOP|wxBOTTOM, 5);

    m_txtTitle = new wxTextCtrl( itemDialog1, ID_TEXTCTRL_ARTICLENAME, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    m_txtTitle->Enable(false);
    itemBoxSizer2->Add(m_txtTitle, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine23 = new wxStaticLine( itemDialog1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer2->Add(itemStaticLine23, 0, wxGROW|wxTOP, 10);

    wxPanel* itemPanel24 = new wxPanel( itemDialog1, ID_PANEL3, wxDefaultPosition, wxSize(-1, 45), wxTAB_TRAVERSAL );
    itemBoxSizer2->Add(itemPanel24, 0, wxGROW|wxALL, 0);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer25 = new wxStdDialogButtonSizer;

    itemPanel24->SetSizer(itemStdDialogButtonSizer25);

    wxButton* itemButton26 = new wxButton( itemPanel24, wxID_CANCEL, wxGetTranslation(wxString() + (wxChar) 0x53D6 + (wxChar) 0x6D88), wxDefaultPosition, wxSize(-1, 30), 0 );
    itemStdDialogButtonSizer25->AddButton(itemButton26);

    wxButton* itemButton27 = new wxButton( itemPanel24, wxID_OK, wxGetTranslation(wxString() + (wxChar) 0x521B + (wxChar) 0x5EFA), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer25->AddButton(itemButton27);

    itemStdDialogButtonSizer25->Realize();

////@end dlgArticleNew content construction
}


/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM1
 */

void dlgArticleNew::OnChkCam1Click( wxCommandEvent& event )
{
	int idxCam = 0;
	m_camIsUsing[idxCam] = event.IsChecked();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM1
 */

void dlgArticleNew::OnChkCam1Update( wxUpdateUIEvent& event )
{
	int idxCam = 0;
	event.Enable( !m_camIsUsing[idxCam+1] );
}


/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM2
 */

void dlgArticleNew::OnChkCam2Click( wxCommandEvent& event )
{
	int idxCam = 1;
	m_camIsUsing[idxCam] = event.IsChecked();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM2
 */

void dlgArticleNew::OnChkCam2Update( wxUpdateUIEvent& event )
{
	int idxCam = 1;
	event.Enable( m_camIsUsing[idxCam-1] && !m_camIsUsing[idxCam+1] );
}


/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM3
 */

void dlgArticleNew::OnChkCam3Click( wxCommandEvent& event )
{
	int idxCam = 2;
	m_camIsUsing[idxCam] = event.IsChecked();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM3
 */

void dlgArticleNew::OnChkCam3Update( wxUpdateUIEvent& event )
{
	int idxCam = 2;
	event.Enable( m_camIsUsing[idxCam-1] && !m_camIsUsing[idxCam+1] );
}








/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM4
 */

void dlgArticleNew::OnChkCam4Click( wxCommandEvent& event )
{
	int idxCam = 3;
	m_camIsUsing[idxCam] = event.IsChecked();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM4
 */

void dlgArticleNew::OnChkCam4Update( wxUpdateUIEvent& event )
{
	int idxCam = 3;
	event.Enable( m_camIsUsing[idxCam-1] && !m_camIsUsing[idxCam+1] );
}


/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM5
 */

void dlgArticleNew::OnChkCam5Click( wxCommandEvent& event )
{
	int idxCam = 4;
	m_camIsUsing[idxCam] = event.IsChecked();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM5
 */

void dlgArticleNew::OnChkCam5Update( wxUpdateUIEvent& event )
{
	int idxCam = 4;
	event.Enable( m_camIsUsing[idxCam-1] && !m_camIsUsing[idxCam+1] );
}


/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM6
 */

void dlgArticleNew::OnChkCam6Click( wxCommandEvent& event )
{
	int idxCam = 5;
	m_camIsUsing[idxCam] = event.IsChecked();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM6
 */

void dlgArticleNew::OnChkCam6Update( wxUpdateUIEvent& event )
{
	int idxCam = 5;
	event.Enable( m_camIsUsing[idxCam] );
}


/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL_COLORA
 */

void dlgArticleNew::OnTextctrlColoraTextUpdated( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL_COLORA in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL_COLORA in dlgArticleNew.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TEXTCTRL_ARTICLENAME
 */

void dlgArticleNew::OnTextctrlArticlenameUpdate( wxUpdateUIEvent& event )
{
	int usingcamcount=0;
	for(int iIndex=0;iIndex<HGV_SUPPORT_CAMERANUM;iIndex++)
	{
		usingcamcount+=m_camIsUsing[iIndex];
	}
	wxDateTime locdate=wxDateTime::Now();
	wxString filename=wxString::Format(wxT("#%d_%s_%d_%d.xml"),
										usingcamcount,m_txtColorA->GetValue(),
										locdate.GetDay(),locdate.GetMonth()+1) ;
	m_txtTitle->SetValue(filename);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void dlgArticleNew::OnCancelClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in dlgArticleNew.
    // Before editing this code, remove the block markers.
    EndModal(wxID_CANCEL);
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL in dlgArticleNew.
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void dlgArticleNew::OnOkClick( wxCommandEvent& event )
{
/**< 创建基础结构 */
	wxString filename = wxGetCwd() + wxT("\\tmp.xml");
	wxString title = wxEmptyString;
	wxXmlNode* pNode_ccd = nullptr;

	wxXmlDocument *xmldoc = new wxXmlDocument();

	wxXmlNode* pNode_root = new wxXmlNode( wxXML_ELEMENT_NODE, "ps" );

	xmldoc->SetRoot( pNode_root );


	int iIndex = 0;
	for(iIndex=0;iIndex<HGV_SUPPORT_CAMERANUM;iIndex++)
	{
			title = wxString::Format(wxT("CCD%d"),iIndex+1);

			pNode_ccd = new wxXmlNode( wxXML_ELEMENT_NODE, title );
			pNode_root->AddChild(pNode_ccd);
			ISHCAP_API::xml_SetNodeValueL(pNode_ccd, wxT("isUsing"), m_camIsUsing[iIndex] );
			ISHCAP_API::xml_SetNodeValueL(pNode_ccd, wxT("role"), m_typCam[iIndex] );
	}
	xmldoc->Save(filename);

    delete xmldoc;

	c_pgvVisionManager->gvMgr_LoadConfig(filename);

	wxString filename2 = wxGetCwd()+ wxT("\\articles\\") +m_txtTitle->GetValue();
	 c_pgvVisionManager->gvMgr_SaveConfig(filename2,FALSE);
	 wxString filename3 = wxGetCwd() + wxT("\\fsettings.xml");
	 c_pgvVisionManager->gvMgr_SaveConfig(filename3,TRUE);
	 EndModal(wxID_OK);
}


/*
 * Should we show tooltips?
 */

bool dlgArticleNew::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap dlgArticleNew::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dlgArticleNew bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dlgArticleNew bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon dlgArticleNew::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dlgArticleNew icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dlgArticleNew icon retrieval
}













