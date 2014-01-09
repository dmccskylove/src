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

////@end dlgSettingsCam event table entries

END_EVENT_TABLE()


/*
 * dlgSettingsCam constructors
 */

dlgSettingsCam::dlgSettingsCam()
{
    Init();
}

dlgSettingsCam::dlgSettingsCam( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
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

    itemBoxSizer2->Add(itemNotebook3, 0, wxGROW|wxALL, 0);

    wxPanel* itemPanel12 = new wxPanel( itemDialog1, ID_PANEL4, wxDefaultPosition, wxSize(-1, 45), wxTAB_TRAVERSAL );
    itemBoxSizer2->Add(itemPanel12, 0, wxGROW|wxALL, 0);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer13 = new wxStdDialogButtonSizer;

    itemPanel12->SetSizer(itemStdDialogButtonSizer13);

    wxButton* itemButton14 = new wxButton( itemPanel12, wxID_CANCEL, wxGetTranslation(wxString() + (wxChar) 0x53D6 + (wxChar) 0x6D88), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer13->AddButton(itemButton14);

    wxButton* itemButton15 = new wxButton( itemPanel12, wxID_OK, wxGetTranslation(wxString() + (wxChar) 0x4FDD + (wxChar) 0x5B58), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer13->AddButton(itemButton15);

    itemStdDialogButtonSizer13->Realize();

////@end dlgSettingsCam content construction
}


/*
 * wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_EXPO
 */

void dlgSettingsCam::OnSliderExpoScrollChanged( wxScrollEvent& event )
{
////@begin wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_EXPO in dlgCamSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_EXPO in dlgCamSettings.
}


/*
 * wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_GAIN
 */

void dlgSettingsCam::OnSliderGainScrollChanged( wxScrollEvent& event )
{
////@begin wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_GAIN in dlgCamSettings.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_GAIN in dlgCamSettings.
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
