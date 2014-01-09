/////////////////////////////////////////////////////////////////////////////
// Name:        pentasklogo.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     08/01/2014 16:12:25
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

#include "pantasklogo.h"
#include "gvVisionTask_logo.h"
#include "gvVisionImage_botcap.h"
#include "core\gvVisionROI.h"
////@begin XPM images
////@end XPM images


/*
 * panTaskLogo type definition
 */

IMPLEMENT_DYNAMIC_CLASS( panTaskLogo, wxPanel )


/*
 * panTaskLogo event table definition
 */

BEGIN_EVENT_TABLE( panTaskLogo, wxPanel )

////@begin panTaskLogo event table entries
    EVT_SPINCTRL( ID_SPINCTRL4, panTaskLogo::OnSpinctrl4Updated )
    EVT_TEXT( ID_SPINCTRL4, panTaskLogo::OnSpinctrl4TextUpdated )

    EVT_BUTTON( ID_BUTTON, panTaskLogo::OnButtonClick )
    EVT_UPDATE_UI( ID_BUTTON, panTaskLogo::OnButtonUpdate )

    EVT_FILEPICKER_CHANGED( ID_FILECTRL, panTaskLogo::OnFilectrlFilePickerChanged )

////@end panTaskLogo event table entries

END_EVENT_TABLE()


/*
 * panTaskLogo constructors
 */

panTaskLogo::panTaskLogo()
{
    Init();
}

panTaskLogo::panTaskLogo( gvVisionImage_botcap* pgvVisionImage,gvVisionTask* gvTask,wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    c_pgvTask = (gvVisionTask_logo*)gvTask;
    c_pgvVisionImage = pgvVisionImage;
    Init();
    Create(parent, id, pos, size, style);
}


/*
 * penTaskLogo creator
 */

bool panTaskLogo::Create( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
////@begin panTaskLogo creation
    wxPanel::Create( parent, id, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end panTaskLogo creation

	ReadParam();
	m_isloadImage =false;
    return true;
}


/*
 * panTaskLogo destructor
 */

panTaskLogo::~panTaskLogo()
{
////@begin panTaskLogo destruction
////@end panTaskLogo destruction
}


/*
 * Member initialisation
 */

void panTaskLogo::Init()
{
////@begin panTaskLogo member initialisation
    m_minsocre = NULL;
////@end panTaskLogo member initialisation
}


/*
 * Control creation for penTaskLogo
 */

void panTaskLogo::CreateControls()
{
////@begin panTaskLogo content construction
    panTaskLogo* itemPanel1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemPanel1->SetSizer(itemBoxSizer2);

    wxStaticBox* itemStaticBoxSizer3Static = new wxStaticBox(itemPanel1, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x53C2 + (wxChar) 0x6570 + (wxChar) 0x8BBE + (wxChar) 0x7F6E));
    wxStaticBoxSizer* itemStaticBoxSizer3 = new wxStaticBoxSizer(itemStaticBoxSizer3Static, wxVERTICAL);
    itemBoxSizer2->Add(itemStaticBoxSizer3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxGridSizer* itemGridSizer4 = new wxGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer3->Add(itemGridSizer4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

    wxStaticText* itemStaticText5 = new wxStaticText( itemStaticBoxSizer3->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x6700 + (wxChar) 0x5C0F + (wxChar) 0x5339 + (wxChar) 0x914D + (wxChar) 0x5206 + (wxChar) 0x6570), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridSizer4->Add(itemStaticText5, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_minsocre = new wxSpinCtrl( itemStaticBoxSizer3->GetStaticBox(), ID_SPINCTRL4, _T("0"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0 );
    itemGridSizer4->Add(m_minsocre, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    itemGridSizer4->Add(5, 5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton8 = new wxButton( itemStaticBoxSizer3->GetStaticBox(), ID_BUTTON, wxGetTranslation(wxString() + (wxChar) 0x6A21 + (wxChar) 0x7248 + (wxChar) 0x5B66 + (wxChar) 0x4E60), wxDefaultPosition, wxDefaultSize, 0 );
    itemGridSizer4->Add(itemButton8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxFilePickerCtrl* itemFilePickerCtrl9 = new wxFilePickerCtrl( itemStaticBoxSizer3->GetStaticBox(), ID_FILECTRL, wxEmptyString, wxEmptyString, _T("*.jpg"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_OPEN );
    itemStaticBoxSizer3->Add(itemFilePickerCtrl9, 0, wxGROW|wxALL, 5);

////@end panTaskLogo content construction
}


/*
 * Should we show tooltips?
 */

bool panTaskLogo::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap panTaskLogo::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin panTaskLogo bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end panTaskLogo bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon panTaskLogo::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin panTaskLogo icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end panTaskLogo icon retrieval
}


/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL4
 */

void panTaskLogo::OnSpinctrl4Updated( wxSpinEvent& event )
{
	SaveParam();
}


/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_SPINCTRL4
 */

void panTaskLogo::OnSpinctrl4TextUpdated( wxCommandEvent& event )
{
	SaveParam();
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
 */

void panTaskLogo::OnButtonClick( wxCommandEvent& event )
{
	Hobject  region_loc, Image, TemplateImage, ModelContours;
	Hobject roi_loc;
	HTuple  WindowHandle, ModelId, ModelRow, ModelColumn;
	HTuple  ModelAngle, ModelScore, MatchingObjIdx, HomMat;

	roi_loc = c_pgvTask->gvTask_GetROI()->gvROI_GetROI();
	Image = c_pgvVisionImage->gvIMG_GetImage();
	if(c_pgvVisionImage->_insp_loc(Image,&region_loc))
	{
		set_system("border_shape_models", "false");
		reduce_domain(Image, roi_loc, &TemplateImage);

		  create_shape_model(TemplateImage, 4, HTuple(0).Rad(), HTuple(360).Rad(), HTuple(0.6824).Rad(),
      (HTuple("point_reduction_high").Append("no_pregeneration")), "use_polarity",
      ((HTuple(15).Append(19)).Append(6)), 4, &ModelId);
		get_shape_model_contours(&ModelContours, ModelId, 1);
		c_pgvTask->gvTask_SetModeId(ModelId);
	}
	else
	{
		wxMessageBox(wxT("未检测到产品，请调整产品位置后重新学习！"));
	}

}

void panTaskLogo::ReadParam()
{
	m_minsocre->SetValue(c_pgvTask->gvTask_GetMinScore()) ;
}
void panTaskLogo::SaveParam()
{
	c_pgvTask->gvTask_SetMinScore(m_minsocre->GetValue());
}

/*
 * wxEVT_UPDATE_UI event handler for ID_BUTTON
 */

void panTaskLogo::OnButtonUpdate( wxUpdateUIEvent& event )
{
	event.Enable(c_pgvVisionImage->gvIMG_GetisLoadImage());
}


/*
 * wxEVT_FILEPICKER_CHANGED event handler for ID_FILECTRL
 */

void panTaskLogo::OnFilectrlFilePickerChanged( wxFileDirPickerEvent& event )
{
	c_pgvVisionImage->gvIMG_LoadImage(event.GetPath());
}

