/////////////////////////////////////////////////////////////////////////////
// Name:        pantaskcolor.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     09/01/2014 13:01:38
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

#include "pantaskcolor.h"
#include "gvVisionTask_color.h"
#include "gvVisionImage_botcap.h"
#include "core\gvVisionROI.h"
////@begin XPM images
////@end XPM images


/*
 * panTaskColor type definition
 */

IMPLEMENT_DYNAMIC_CLASS( panTaskColor, wxPanel )


/*
 * panTaskColor event table definition
 */

BEGIN_EVENT_TABLE( panTaskColor, wxPanel )

////@begin panTaskColor event table entries
    EVT_BUTTON( ID_BUTTON1, panTaskColor::OnButton1Click )
    EVT_UPDATE_UI( ID_BUTTON1, panTaskColor::OnButton1Update )

    EVT_BUTTON( ID_BUTTON2, panTaskColor::OnButton2Click )
    EVT_UPDATE_UI( ID_BUTTON2, panTaskColor::OnButton2Update )

////@end panTaskColor event table entries

END_EVENT_TABLE()


/*
 * panTaskColor constructors
 */

panTaskColor::panTaskColor()
{
    Init();
}

panTaskColor::panTaskColor(gvVisionImage_botcap* pgvVisionImage, gvVisionTask* gvTask, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
	c_pgvTask = (gvVisionTask_color*)gvTask;
	c_pgvVisionImage = pgvVisionImage;

    Init();
    Create(parent, id, pos, size, style);
}


/*
 * panTaskColor creator
 */

bool panTaskColor::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin panTaskColor creation
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end panTaskColor creation

	m_meanblue->SetValue(c_pgvTask->gvTask_GetmeanBlue()) ;
	m_meanred->SetValue(c_pgvTask->gvTask_GetmeanRed());
	m_meangreen	->SetValue(c_pgvTask->gvTask_GetmeanGreen());
    return true;
}


/*
 * panTaskColor destructor
 */

panTaskColor::~panTaskColor()
{
////@begin panTaskColor destruction
////@end panTaskColor destruction
}


/*
 * Member initialisation
 */

void panTaskColor::Init()
{
////@begin panTaskColor member initialisation
    m_meanblue = NULL;
    m_actualblue = NULL;
    m_meanred = NULL;
    m_actualred = NULL;
    m_meangreen = NULL;
    m_actualgreen = NULL;
////@end panTaskColor member initialisation
}


/*
 * Control creation for panTaskColor
 */

void panTaskColor::CreateControls()
{
////@begin panTaskColor content construction
    panTaskColor* itemPanel1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemPanel1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText4 = new wxStaticText( itemPanel1, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x6807 + (wxChar) 0x51C6 + (wxChar) 0x84DD + (wxChar) 0x5206 + (wxChar) 0x91CF), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText4, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_meanblue = new wxSpinCtrl( itemPanel1, ID_SPINBLUE, _T("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    m_meanblue->Enable(false);
    itemBoxSizer3->Add(m_meanblue, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText6 = new wxStaticText( itemPanel1, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x5B9E + (wxChar) 0x9645 + (wxChar) 0x84DD + (wxChar) 0x5206 + (wxChar) 0x91CF), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer3->Add(itemStaticText6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_actualblue = new wxSpinCtrl( itemPanel1, ID_SPINBLUE1, _T("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    m_actualblue->Enable(false);
    itemBoxSizer3->Add(m_actualblue, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer8, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText9 = new wxStaticText( itemPanel1, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x6807 + (wxChar) 0x51C6 + (wxChar) 0x7EA2 + (wxChar) 0x5206 + (wxChar) 0x91CF), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(itemStaticText9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_meanred = new wxSpinCtrl( itemPanel1, ID_SPINRED, _T("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    m_meanred->Enable(false);
    itemBoxSizer8->Add(m_meanred, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText11 = new wxStaticText( itemPanel1, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x5B9E + (wxChar) 0x9645 + (wxChar) 0x7EA2 + (wxChar) 0x5206 + (wxChar) 0x91CF), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(itemStaticText11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_actualred = new wxSpinCtrl( itemPanel1, ID_SPINRED1, _T("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    m_actualred->Enable(false);
    itemBoxSizer8->Add(m_actualred, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer13, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText14 = new wxStaticText( itemPanel1, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x6807 + (wxChar) 0x51C6 + (wxChar) 0x7EFF + (wxChar) 0x5206 + (wxChar) 0x91CF), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer13->Add(itemStaticText14, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_meangreen = new wxSpinCtrl( itemPanel1, ID_SPINGREEN, _T("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    m_meangreen->Enable(false);
    itemBoxSizer13->Add(m_meangreen, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText16 = new wxStaticText( itemPanel1, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x5B9E + (wxChar) 0x9645 + (wxChar) 0x7EFF + (wxChar) 0x5206 + (wxChar) 0x91CF), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer13->Add(itemStaticText16, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_actualgreen = new wxSpinCtrl( itemPanel1, ID_SPINGREEN1, _T("0"), wxDefaultPosition, wxSize(60, -1), wxSP_ARROW_KEYS, 0, 1000, 0 );
    m_actualgreen->Enable(false);
    itemBoxSizer13->Add(m_actualgreen, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxBoxSizer* itemBoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer18, 0, wxALIGN_RIGHT|wxALL, 5);

    wxButton* itemButton19 = new wxButton( itemPanel1, ID_BUTTON1, wxGetTranslation(wxString() + (wxChar) 0x6D4B + (wxChar) 0x8BD5 + (wxChar) 0x6A21 + (wxChar) 0x7248), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer18->Add(itemButton19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton20 = new wxButton( itemPanel1, ID_BUTTON2, wxGetTranslation(wxString() + (wxChar) 0x4FDD + (wxChar) 0x5B58 + (wxChar) 0x6A21 + (wxChar) 0x7248), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer18->Add(itemButton20, 0, wxALIGN_BOTTOM|wxALL, 5);

////@end panTaskColor content construction
}


/*
 * Should we show tooltips?
 */

bool panTaskColor::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap panTaskColor::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin panTaskColor bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end panTaskColor bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon panTaskColor::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin panTaskColor icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end panTaskColor icon retrieval
}



/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
 */

void panTaskColor::OnButton1Click( wxCommandEvent& event )
{
	Hobject  image_src,region_loc,ImageReduced, Red, Green, Blue;
	HTuple  Mean_red, Deviation,  Mean_green,Mean_blue;
	image_src = c_pgvVisionImage->gvIMG_GetImage();
	if(c_pgvVisionImage->_insp_loc(image_src,&region_loc))
	{
		reduce_domain(region_loc, c_pgvTask->gvTask_GetROI()->gvROI_GetROI(), &ImageReduced);
		decompose3(ImageReduced, &Red, &Green, &Blue);
		intensity(ImageReduced, Red, &Mean_red, &Deviation);
		intensity(ImageReduced, Green, &Mean_green, &Deviation);
		intensity(ImageReduced, Blue, &Mean_blue, &Deviation);
		m_actualblue->SetValue(Mean_blue[0].L());
		m_actualred->SetValue(Mean_red[0].L());
		m_actualgreen->SetValue(Mean_green[0].L());
	}

}


/*
 * wxEVT_UPDATE_UI event handler for ID_BUTTON1
 */

void panTaskColor::OnButton1Update( wxUpdateUIEvent& event )
{
	event.Enable(c_pgvVisionImage->gvIMG_GetisLoadImage());
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2
 */

void panTaskColor::OnButton2Click( wxCommandEvent& event )
{
	m_meanblue->SetValue(m_actualblue->GetValue());
	m_meanred->SetValue(m_actualred->GetValue());
	m_meangreen->SetValue(m_actualgreen->GetValue());
	c_pgvTask->gvTask_SetmeanBlue(m_meanblue->GetValue());
	c_pgvTask->gvTask_SetmeanGreen(m_meangreen->GetValue());
	c_pgvTask->gvTask_SetmeanRed(m_meanred->GetValue());
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BUTTON2
 */

void panTaskColor::OnButton2Update( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_BUTTON2 in panTaskColor.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_BUTTON2 in panTaskColor.
}

