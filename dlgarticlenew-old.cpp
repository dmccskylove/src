/////////////////////////////////////////////////////////////////////////////
// Name:        dlgarticlenew.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     30/12/2013 15:28:02
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

    EVT_UPDATE_UI( ID_CHOICE_CAM1, dlgArticleNew::OnChoiceCam1Update )

    EVT_UPDATE_UI( ID_CHOICE_CAM2, dlgArticleNew::OnChoiceCam2Update )

    EVT_UPDATE_UI( ID_CHOICE_CAM3, dlgArticleNew::OnChoiceCam3Update )

    EVT_CHECKBOX( ID_CHK_CAM4, dlgArticleNew::OnChkCam4Click )
    EVT_UPDATE_UI( ID_CHK_CAM4, dlgArticleNew::OnChkCam4Update )

    EVT_UPDATE_UI( ID_CHOICE_CAM4, dlgArticleNew::OnChoiceCam4Update )

    EVT_UPDATE_UI( ID_CHOICE_CAM5, dlgArticleNew::OnChoiceCam5Update )

    EVT_UPDATE_UI( ID_CHOICE_CAM6, dlgArticleNew::OnChoiceCam6Update )

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

dlgArticleNew::dlgArticleNew( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
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
////@begin dlgArticleNew member initialisation
    m_chkcam1 = NULL;
    m_chkcam2 = NULL;
    m_chkcam3 = NULL;
    m_typecam1 = NULL;
    m_typecam2 = NULL;
    m_typecam3 = NULL;
    m_chkcam4 = NULL;
    m_chkcam5 = NULL;
    m_chkcam6 = NULL;
    m_typecam4 = NULL;
    m_typecam5 = NULL;
    m_typecam6 = NULL;
    m_txtColorA = NULL;
    m_txtTitle = NULL;
////@end dlgArticleNew member initialisation

	m_usingcamcount =0;
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

    m_chkcam1 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM1, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("1")), wxDefaultPosition, wxSize(-1, 27), 0 );
    m_chkcam1->SetValue(false);
    itemBoxSizer4->Add(m_chkcam1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    m_chkcam2 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM2, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("2")), wxDefaultPosition, wxSize(-1, 28), 0 );
    m_chkcam2->SetValue(false);
    m_chkcam2->Enable(false);
    itemBoxSizer4->Add(m_chkcam2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    m_chkcam3 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM3, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("3")), wxDefaultPosition, wxSize(-1, 28), 0 );
    m_chkcam3->SetValue(false);
    m_chkcam3->Enable(false);
    itemBoxSizer4->Add(m_chkcam3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer3->Add(itemBoxSizer8, 0, wxGROW|wxALL, 5);

    wxArrayString m_typecam1Strings;
    m_typecam1Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    m_typecam1Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    m_typecam1Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam1 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM1, wxDefaultPosition, wxDefaultSize, m_typecam1Strings, 0 );
    m_typecam1->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    itemBoxSizer8->Add(m_typecam1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxArrayString m_typecam2Strings;
    m_typecam2Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    m_typecam2Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    m_typecam2Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam2 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM2, wxDefaultPosition, wxDefaultSize, m_typecam2Strings, 0 );
    m_typecam2->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam2->Enable(false);
    itemBoxSizer8->Add(m_typecam2, 0, wxGROW|wxALL, 2);

    wxArrayString m_typecam3Strings;
    m_typecam3Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    m_typecam3Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    m_typecam3Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam3 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM3, wxDefaultPosition, wxDefaultSize, m_typecam3Strings, 0 );
    m_typecam3->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam3->Enable(false);
    itemBoxSizer8->Add(m_typecam3, 0, wxGROW|wxALL, 2);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer3->Add(itemBoxSizer12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_chkcam4 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM4, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("4")), wxDefaultPosition, wxSize(-1, 28), 0 );
    m_chkcam4->SetValue(false);
    m_chkcam4->Enable(false);
    itemBoxSizer12->Add(m_chkcam4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    m_chkcam5 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM5, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("5")), wxDefaultPosition, wxSize(-1, 28), 0 );
    m_chkcam5->SetValue(false);
    m_chkcam5->Enable(false);
    itemBoxSizer12->Add(m_chkcam5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    m_chkcam6 = new wxCheckBox( itemStaticBoxSizer3->GetStaticBox(), ID_CHK_CAM6, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("6")), wxDefaultPosition, wxSize(-1, 28), 0 );
    m_chkcam6->SetValue(false);
    m_chkcam6->Enable(false);
    itemBoxSizer12->Add(m_chkcam6, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer16 = new wxBoxSizer(wxVERTICAL);
    itemStaticBoxSizer3->Add(itemBoxSizer16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_typecam4Strings;
    m_typecam4Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    m_typecam4Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    m_typecam4Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam4 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM4, wxDefaultPosition, wxDefaultSize, m_typecam4Strings, 0 );
    m_typecam4->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    m_typecam4->Enable(false);
    itemBoxSizer16->Add(m_typecam4, 0, wxGROW|wxALL, 2);

    wxArrayString m_typecam5Strings;
    m_typecam5Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    m_typecam5Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    m_typecam5Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam5 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM5, wxDefaultPosition, wxDefaultSize, m_typecam5Strings, 0 );
    m_typecam5->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam5->Enable(false);
    itemBoxSizer16->Add(m_typecam5, 0, wxGROW|wxALL, 2);

    wxArrayString m_typecam6Strings;
    m_typecam6Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x6B63 + (wxChar) 0x9762));
    m_typecam6Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x53CD + (wxChar) 0x9762));
    m_typecam6Strings.Add(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam6 = new wxChoice( itemStaticBoxSizer3->GetStaticBox(), ID_CHOICE_CAM6, wxDefaultPosition, wxDefaultSize, m_typecam6Strings, 0 );
    m_typecam6->SetStringSelection(wxGetTranslation(wxString() + (wxChar) 0x4FA7 + (wxChar) 0x9762));
    m_typecam6->Enable(false);
    itemBoxSizer16->Add(m_typecam6, 0, wxGROW|wxALL, 2);

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
	if(m_chkcam1->IsChecked()){
		m_chkcam2->Enable(TRUE);
		m_typecam2->Enable(TRUE);
		m_usingcamcount++;
	}
	else{
		if(m_chkcam2->IsChecked()){
			wxMessageBox(wxT("请按照从后到前的顺序取消相机应用"));
			m_chkcam1->SetValue(TRUE);
		}
		else{
			m_chkcam2->Enable(FALSE);
			m_typecam2->Enable(FALSE);
			m_usingcamcount--;
		}
	}
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM1
 */

void dlgArticleNew::OnChkCam1Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHK_CAM1 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHK_CAM1 in dlgArticleNew.
}


/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM2
 */

void dlgArticleNew::OnChkCam2Click( wxCommandEvent& event )
{
	if(m_chkcam2->IsChecked()){
		m_chkcam3->Enable(TRUE);
		m_typecam3->Enable(TRUE);
		m_usingcamcount++;
	}
	else{
		if(m_chkcam3->IsChecked()){
			wxMessageBox(wxT("请按照从后到前的顺序取消相机应用"));
			m_chkcam2->SetValue(TRUE);
		}
		else{
			m_chkcam3->Enable(FALSE);
			m_typecam3->Enable(FALSE);
			m_usingcamcount--;
		}
	}
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM2
 */

void dlgArticleNew::OnChkCam2Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHK_CAM2 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHK_CAM2 in dlgArticleNew.
}


/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM3
 */

void dlgArticleNew::OnChkCam3Click( wxCommandEvent& event )
{
	if(m_chkcam3->IsChecked()){
		m_chkcam4->Enable(TRUE);
		m_typecam4->Enable(TRUE);
		m_usingcamcount++;
	}
	else{
		if(m_chkcam4->IsChecked()){
			wxMessageBox(wxT("请按照从后到前的顺序取消相机应用"));
			m_chkcam3->SetValue(TRUE);
		}
		else{
			m_chkcam4->Enable(FALSE);
			m_typecam4->Enable(FALSE);
			m_usingcamcount--;
		}
	}
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM3
 */

void dlgArticleNew::OnChkCam3Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHK_CAM3 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHK_CAM3 in dlgArticleNew.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM1
 */

void dlgArticleNew::OnChoiceCam1Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM1 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM1 in dlgArticleNew.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM2
 */

void dlgArticleNew::OnChoiceCam2Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM2 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM2 in dlgArticleNew.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM3
 */

void dlgArticleNew::OnChoiceCam3Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM3 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM3 in dlgArticleNew.
}


/*
 * wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM4
 */

void dlgArticleNew::OnChkCam4Click( wxCommandEvent& event )
{
	if(m_chkcam4->IsChecked()){
		m_chkcam5->Enable(TRUE);
		m_typecam5->Enable(TRUE);
		m_usingcamcount++;
	}
	else{
		if(m_chkcam5->IsChecked()){
			wxMessageBox(wxT("请按照从后到前的顺序取消相机应用"));
			m_chkcam4->SetValue(TRUE);
		}
		else{
			m_chkcam5->Enable(FALSE);
			m_typecam5->Enable(FALSE);
			m_usingcamcount--;
		}
	}
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHK_CAM4
 */

void dlgArticleNew::OnChkCam4Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHK_CAM4 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHK_CAM4 in dlgArticleNew.
}










/*
 * wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM4
 */

void dlgArticleNew::OnChoiceCam4Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM4 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM4 in dlgArticleNew.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM5
 */

void dlgArticleNew::OnChoiceCam5Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM5 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM5 in dlgArticleNew.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM6
 */

void dlgArticleNew::OnChoiceCam6Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM6 in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM6 in dlgArticleNew.
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
	wxDateTime locdate=wxDateTime::Now();
	m_txtTitle->SetValue(wxString::Format(wxT("#%d_%s_%d_%d.xml"),
									m_usingcamcount,m_txtColorA->GetValue(),
										locdate.GetDay(),locdate.GetMonth()) );
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
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in dlgArticleNew.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK in dlgArticleNew.
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
