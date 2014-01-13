/////////////////////////////////////////////////////////////////////////////
// Name:        pantaskblack.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     05/01/2014 13:19:45
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

#include "pantaskblack.h"
#include "gvVisionTask_black.h"

////@begin XPM images
////@end XPM images


/*
 * panTaskBlack type definition
 */

IMPLEMENT_DYNAMIC_CLASS( panTaskBlack, wxPanel )


/*
 * panTaskBlack event table definition
 */

BEGIN_EVENT_TABLE( panTaskBlack, wxPanel )

////@begin panTaskBlack event table entries
////@end panTaskBlack event table entries

END_EVENT_TABLE()


/*
 * panTaskBlack constructors
 */

panTaskBlack::panTaskBlack()
{
    Init();
}

panTaskBlack::panTaskBlack(gvVisionTask* gvTask, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    c_pgvTask =(gvVisionTask_black*) gvTask;
    /**<  */
    Init();
    Create(parent, id, pos, size, style);

}


/*
 * panTaskBlack creator
 */

bool panTaskBlack::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin panTaskBlack creation
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end panTaskBlack creation
	ReadParam();
	return true;
}


/*
 * panTaskBlack destructor
 */

panTaskBlack::~panTaskBlack()
{
////@begin panTaskBlack destruction
////@end panTaskBlack destruction
}


/*
 * Member initialisation
 */

void panTaskBlack::Init()
{
////@begin panTaskBlack member initialisation
    m_minBlackSpotArea = NULL;
    m_minBlackSpotCnt = NULL;
    m_maxBlackSpotCnt = NULL;
////@end panTaskBlack member initialisation
}


/*
 * Control creation for panTaskBlack
 */

void panTaskBlack::CreateControls()
{
////@begin panTaskBlack content construction
    panTaskBlack* itemPanel1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemPanel1->SetSizer(itemBoxSizer2);

    wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(itemPanel1, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x53C2 + (wxChar) 0x6570 + (wxChar) 0x8BBE + (wxChar) 0x7F6E));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxHORIZONTAL);
    itemBoxSizer2->Add(itemStaticBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxGridSizer* itemGridSizer4 = new wxGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer3->Add(itemGridSizer4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText5 = new wxStaticText( itemStaticBoxSizer3->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x9ED1 + (wxChar) 0x70B9 + (wxChar) 0x6700 + (wxChar) 0x5C0F + (wxChar) 0x9762 + (wxChar) 0x79EF), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridSizer4->Add(itemStaticText5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_minBlackSpotArea = new wxSpinCtrl( itemStaticBoxSizer3->GetStaticBox(), ID_SPINCTRL, _T("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0 );
    itemGridSizer4->Add(m_minBlackSpotArea, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText7 = new wxStaticText( itemStaticBoxSizer3->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x9ED1 + (wxChar) 0x70B9 + (wxChar) 0x6700 + (wxChar) 0x5C0F + (wxChar) 0x4E2A + (wxChar) 0x6570), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridSizer4->Add(itemStaticText7, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_minBlackSpotCnt = new wxSpinCtrl( itemStaticBoxSizer3->GetStaticBox(), ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0 );
    itemGridSizer4->Add(m_minBlackSpotCnt, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemStaticBoxSizer3->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x9ED1 + (wxChar) 0x70B9 + (wxChar) 0x6700 + (wxChar) 0x5927 + (wxChar) 0x4E2A + (wxChar) 0x6570), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridSizer4->Add(itemStaticText9, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_maxBlackSpotCnt = new wxSpinCtrl( itemStaticBoxSizer3->GetStaticBox(), ID_SPINCTRL3, _T("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0 );
    itemGridSizer4->Add(m_maxBlackSpotCnt, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

////@end panTaskBlack content construction
}


/*
 * Should we show tooltips?
 */

bool panTaskBlack::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap panTaskBlack::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin panTaskBlack bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end panTaskBlack bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon panTaskBlack::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin panTaskBlack icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end panTaskBlack icon retrieval
}









void panTaskBlack::ReadParam()
{
	m_minBlackSpotArea->SetValue(c_pgvTask->gvTask_GetminBlackSpotArea());
	m_minBlackSpotCnt->SetValue(c_pgvTask->gvTask_GetminBlackSpotCnt());
	m_maxBlackSpotCnt->SetValue(c_pgvTask->gvTask_GetmaxBlackSpotCnt());
}
void panTaskBlack::SaveParam()
{
	c_pgvTask->gvTask_SetmaxBlackSpotCnt(m_maxBlackSpotCnt->GetValue());
	c_pgvTask->gvTask_SetminBlackSpotArea(m_minBlackSpotArea->GetValue());
	c_pgvTask->gvTask_SetminBlackSpotCnt(m_minBlackSpotCnt->GetValue());
}
