/////////////////////////////////////////////////////////////////////////////
// Name:        dlgSettingsCam.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     19/12/2013 14:21:21
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
#include "wx/imaglist.h"
////@end includes

#include "dlgSettingsCam.h"
#include "core\gvVisionCCD.h"
#include "core\gvVisionCam_acA.h"
#include "core\gvVisionManager.h"

////@begin XPM images
////@end XPM images


/*
 * dlgSettingsCam type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dlgSettingsCam, wxDialog )


/*
 * dlgSettingsCam event table definition
 */

BEGIN_EVENT_TABLE( dlgSettingsCam, wxDialog )

////@begin dlgSettingsCam event table entries
    EVT_COMMAND_SCROLL_CHANGED( ID_SLIDER_EXPO, dlgSettingsCam::OnSliderExpoScrollChanged )

    EVT_COMMAND_SCROLL_CHANGED( ID_SLIDER_GAIN, dlgSettingsCam::OnSliderGainScrollChanged )

    EVT_SPINCTRL( ID_SPINCTRL6, dlgSettingsCam::OnSpinctrl6Updated )

    EVT_SPINCTRL( ID_SPINCTRL1, dlgSettingsCam::OnSpinctrl1Updated )

    EVT_BUTTON( wxID_CANCEL, dlgSettingsCam::OnCancelClick )

    EVT_BUTTON( wxID_OK, dlgSettingsCam::OnOkClick )

////@end dlgSettingsCam event table entries

END_EVENT_TABLE()


/*
 * dlgSettingsCam constructors
 */

dlgSettingsCam::dlgSettingsCam()
{
    Init();
}

dlgSettingsCam::dlgSettingsCam(gvVisionCCD * pgvVisionCCD, wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
	c_pgvVisionCCD = pgvVisionCCD;
	c_pgvVisionCam =(gvVisionCam_acA*) pgvVisionCCD->get_VisionCam();
	c_pgvVisionManager =pgvVisionCCD->get_VisionManager();
 /**<  */
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * dlgCamSettings creator
 */

bool dlgSettingsCam::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlgSettingsCam creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dlgSettingsCam creation
	ReadParam();
    return true;
}


/*
 * dlgSettingsCam destructor
 */

dlgSettingsCam::~dlgSettingsCam()
{
////@begin dlgSettingsCam destruction
////@end dlgSettingsCam destruction
}


/*
 * Member initialisation
 */

void dlgSettingsCam::Init()
{
////@begin dlgSettingsCam member initialisation
    m_sldExpo = NULL;
    m_sldGain = NULL;
    m_rejectdelay = NULL;
    m_idxPort = NULL;
////@end dlgSettingsCam member initialisation
}


/*
 * Control creation for dlgCamSettings
 */

void dlgSettingsCam::CreateControls()
{
////@begin dlgSettingsCam content construction
    dlgSettingsCam* itemDialog1 = this;

    this->SetFont(wxFont(11, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("微软雅黑")));
    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxNotebook* itemNotebook3 = new wxNotebook( itemDialog1, ID_NOTEBOOK7, wxDefaultPosition, wxDefaultSize, wxBK_DEFAULT );

    wxPanel* itemPanel4 = new wxPanel( itemNotebook3, ID_PANEL22, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer5 = new wxBoxSizer(wxVERTICAL);
    itemPanel4->SetSizer(itemBoxSizer5);

    m_sldExpo = new wxSlider( itemPanel4, ID_SLIDER_EXPO, 500, 50, 1500, wxDefaultPosition, wxSize(250, -1), wxSL_HORIZONTAL|wxSL_LABELS );
    itemBoxSizer5->Add(m_sldExpo, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemPanel4, wxID_STATIC, wxEmptyString, wxDefaultPosition, wxSize(300, 80), 0 );
    itemStaticText7->SetForegroundColour(wxColour(192, 192, 192));
    itemBoxSizer5->Add(itemStaticText7, 0, wxGROW|wxALL, 5);

    itemNotebook3->AddPage(itemPanel4, wxGetTranslation(wxString() + (wxChar) 0x66DD + (wxChar) 0x5149 + (wxChar) 0x65F6 + (wxChar) 0x95F4));

    wxPanel* itemPanel8 = new wxPanel( itemNotebook3, ID_PANEL23, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer9 = new wxBoxSizer(wxVERTICAL);
    itemPanel8->SetSizer(itemBoxSizer9);

    m_sldGain = new wxSlider( itemPanel8, ID_SLIDER_GAIN, 100, 100, 680, wxDefaultPosition, wxSize(250, -1), wxSL_HORIZONTAL|wxSL_LABELS );
    itemBoxSizer9->Add(m_sldGain, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText11 = new wxStaticText( itemPanel8, wxID_STATIC, wxEmptyString, wxDefaultPosition, wxSize(300, 80), 0 );
    itemStaticText11->SetForegroundColour(wxColour(192, 192, 192));
    itemBoxSizer9->Add(itemStaticText11, 0, wxGROW|wxALL, 5);

    itemNotebook3->AddPage(itemPanel8, wxGetTranslation(wxString() + (wxChar) 0x589E + (wxChar) 0x76CA));

    wxPanel* itemPanel12 = new wxPanel( itemNotebook3, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    wxBoxSizer* itemBoxSizer13 = new wxBoxSizer(wxVERTICAL);
    itemPanel12->SetSizer(itemBoxSizer13);

    wxBoxSizer* itemBoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer13->Add(itemBoxSizer14, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    wxStaticText* itemStaticText15 = new wxStaticText( itemPanel12, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x5254 + (wxChar) 0x9664 + (wxChar) 0x5EF6 + (wxChar) 0x65F6), wxDefaultPosition, wxSize(100, -1), 0 );
    itemBoxSizer14->Add(itemStaticText15, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_rejectdelay = new wxSpinCtrl( itemPanel12, ID_SPINCTRL6, _T("0"), wxDefaultPosition, wxSize(200, -1), wxSP_ARROW_KEYS, 0, 999999, 0 );
    itemBoxSizer14->Add(m_rejectdelay, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer13->Add(itemBoxSizer17, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);
    wxStaticText* itemStaticText18 = new wxStaticText( itemPanel12, wxID_STATIC, wxGetTranslation(wxString(wxT("IO")) + (wxChar) 0x7AEF + (wxChar) 0x53E3), wxDefaultPosition, wxSize(100, -1), 0 );
    itemBoxSizer17->Add(itemStaticText18, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_idxPort = new wxSpinCtrl( itemPanel12, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxSize(200, -1), wxSP_ARROW_KEYS, 0, 100, 0 );
    itemBoxSizer17->Add(m_idxPort, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemNotebook3->AddPage(itemPanel12, wxGetTranslation(wxString() + (wxChar) 0x5254 + (wxChar) 0x9664));

    itemBoxSizer2->Add(itemNotebook3, 0, wxGROW|wxALL, 0);

    wxPanel* itemPanel20 = new wxPanel( itemDialog1, ID_PANEL4, wxDefaultPosition, wxSize(-1, 45), wxTAB_TRAVERSAL );
    itemBoxSizer2->Add(itemPanel20, 0, wxGROW|wxALL, 0);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer21 = new wxStdDialogButtonSizer;

    itemPanel20->SetSizer(itemStdDialogButtonSizer21);

    wxButton* itemButton22 = new wxButton( itemPanel20, wxID_CANCEL, wxGetTranslation(wxString() + (wxChar) 0x53D6 + (wxChar) 0x6D88), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer21->AddButton(itemButton22);

    wxButton* itemButton23 = new wxButton( itemPanel20, wxID_OK, wxGetTranslation(wxString() + (wxChar) 0x4FDD + (wxChar) 0x5B58), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer21->AddButton(itemButton23);

    itemStdDialogButtonSizer21->Realize();

////@end dlgSettingsCam content construction
}


/*
 * wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_EXPO
 */

void dlgSettingsCam::OnSliderExpoScrollChanged( wxScrollEvent& event )
{
	c_pgvVisionCam->cam_SetExpo(m_sldExpo->GetValue());
}


/*
 * wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_GAIN
 */

void dlgSettingsCam::OnSliderGainScrollChanged( wxScrollEvent& event )
{
	c_pgvVisionCam->cam_SetGain(m_sldGain->GetValue());
}


/*
 * Should we show tooltips?
 */

bool dlgSettingsCam::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap dlgSettingsCam::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dlgSettingsCam bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dlgSettingsCam bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon dlgSettingsCam::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dlgSettingsCam icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dlgSettingsCam icon retrieval
}


/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL6
 */

void dlgSettingsCam::OnSpinctrl6Updated( wxSpinEvent& event )
{
	c_pgvVisionCCD->set_Rejectdelay(m_rejectdelay->GetValue());
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void dlgSettingsCam::OnOkClick( wxCommandEvent& event )
{
	SaveParam();
	wxString filename = c_pgvVisionManager->gvMgr_getConfigFile();
	c_pgvVisionManager->gvMgr_SaveConfig(filename,FALSE);
	EndModal(wxID_OK);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void dlgSettingsCam::OnCancelClick( wxCommandEvent& event )
{
	wxString filename = c_pgvVisionManager->gvMgr_getConfigFile();
	c_pgvVisionManager->gvMgr_LoadConfig(filename);
	EndModal(wxID_OK);
}


void dlgSettingsCam::ReadParam()
{
	m_sldExpo->SetValue(c_pgvVisionCam->getExpo());
	m_sldGain->SetValue(c_pgvVisionCam->getGain());
	m_rejectdelay->SetValue(c_pgvVisionCCD->get_Rejectdelay());
	m_idxPort->SetValue(c_pgvVisionManager->get_idxPort());
}
void dlgSettingsCam::SaveParam()
{
	c_pgvVisionCam->cam_SetExpo(m_sldExpo->GetValue());
	c_pgvVisionCam->cam_SetGain(m_sldGain->GetValue());
	c_pgvVisionCCD->set_Rejectdelay(m_rejectdelay->GetValue());
	c_pgvVisionManager->set_idxPort(m_idxPort->GetValue());

}


/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL1
 */

void dlgSettingsCam::OnSpinctrl1Updated( wxSpinEvent& event )
{

}

