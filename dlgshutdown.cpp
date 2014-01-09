/////////////////////////////////////////////////////////////////////////////
// Name:        dlgshutdown.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     19/12/2013 14:22:34
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

#include "dlgshutdown.h"

////@begin XPM images

////@end XPM images


/*
 * dlgShutdown type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dlgShutdown, wxDialog )


/*
 * dlgShutdown event table definition
 */

BEGIN_EVENT_TABLE( dlgShutdown, wxDialog )

////@begin dlgShutdown event table entries
////@end dlgShutdown event table entries

END_EVENT_TABLE()


/*
 * dlgShutdown constructors
 */

dlgShutdown::dlgShutdown()
{
    Init();
}

dlgShutdown::dlgShutdown( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * dlgShutdown creator
 */

bool dlgShutdown::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlgShutdown creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dlgShutdown creation
    return true;
}


/*
 * dlgShutdown destructor
 */

dlgShutdown::~dlgShutdown()
{
////@begin dlgShutdown destruction
////@end dlgShutdown destruction
}


/*
 * Member initialisation
 */

void dlgShutdown::Init()
{
////@begin dlgShutdown member initialisation
    m_typeShut = NULL;
////@end dlgShutdown member initialisation
}


/*
 * Control creation for dlgShutdown
 */

void dlgShutdown::CreateControls()
{
////@begin dlgShutdown content construction
    dlgShutdown* itemDialog1 = this;

    this->SetFont(wxFont(11, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("微软雅黑")));
    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxArrayString m_typeShutStrings;
    m_typeShutStrings.Add(wxGetTranslation(wxString() + (wxChar) 0x5173 + (wxChar) 0x95ED + (wxChar) 0x7535 + (wxChar) 0x8111));
    m_typeShutStrings.Add(wxGetTranslation(wxString() + (wxChar) 0x91CD + (wxChar) 0x542F + (wxChar) 0x7535 + (wxChar) 0x8111));
    m_typeShut = new wxRadioBox( itemDialog1, ID_RADIOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, m_typeShutStrings, 2, wxRA_SPECIFY_ROWS );
    m_typeShut->SetSelection(0);
    itemBoxSizer2->Add(m_typeShut, 0, wxGROW|wxALL, 5);

    wxStaticLine* itemStaticLine4 = new wxStaticLine( itemDialog1, wxID_STATIC, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
    itemBoxSizer2->Add(itemStaticLine4, 0, wxGROW|wxALL, 0);

    wxPanel* itemPanel5 = new wxPanel( itemDialog1, ID_PANEL5, wxDefaultPosition, wxSize(-1, 45), wxTAB_TRAVERSAL );
    itemBoxSizer2->Add(itemPanel5, 0, wxGROW|wxALL, 0);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer6 = new wxStdDialogButtonSizer;

    itemPanel5->SetSizer(itemStdDialogButtonSizer6);

    wxButton* itemButton7 = new wxButton( itemPanel5, wxID_OK, wxGetTranslation(wxString() + (wxChar) 0x786E + (wxChar) 0x5B9A), wxDefaultPosition, wxSize(-1, 30), 0 );
    itemStdDialogButtonSizer6->AddButton(itemButton7);

    wxButton* itemButton8 = new wxButton( itemPanel5, wxID_CANCEL, wxGetTranslation(wxString() + (wxChar) 0x53D6 + (wxChar) 0x6D88), wxDefaultPosition, wxSize(-1, 30), 0 );
    itemStdDialogButtonSizer6->AddButton(itemButton8);

    itemStdDialogButtonSizer6->Realize();

////@end dlgShutdown content construction
}


/*
 * Should we show tooltips?
 */

bool dlgShutdown::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap dlgShutdown::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dlgShutdown bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dlgShutdown bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon dlgShutdown::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dlgShutdown icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dlgShutdown icon retrieval
}
