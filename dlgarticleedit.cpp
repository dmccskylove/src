/////////////////////////////////////////////////////////////////////////////
// Name:        dlgarticleedit.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     06/01/2014 09:02:19
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

#include "dlgarticleedit.h"

#include "pantaskblack.h"
#include "pantasklogo.h"
#include "pantaskcolor.h"
#include "gvVisionImage_botcap.h"
#include "core/gvVisionManager.h"
#include "core/gvVisionCCD.h"
////@begin XPM images
////@end XPM images


/*
 * dlgArticleEdit type definition
 */

IMPLEMENT_DYNAMIC_CLASS( dlgArticleEdit, wxDialog )


/*
 * dlgArticleEdit event table definition
 */

BEGIN_EVENT_TABLE( dlgArticleEdit, wxDialog )

////@begin dlgArticleEdit event table entries
    EVT_BUTTON( ID_BTN_ADD, dlgArticleEdit::OnBtnAddClick )
    EVT_UPDATE_UI( ID_BTN_ADD, dlgArticleEdit::OnBtnAddUpdate )

    EVT_BUTTON( ID_BTN_DEL, dlgArticleEdit::OnBtnDelClick )
    EVT_UPDATE_UI( ID_BTN_DEL, dlgArticleEdit::OnBtnDelUpdate )

    EVT_SPINCTRL( ID_SPINCTRL5, dlgArticleEdit::OnSpinctrl5Updated )
    EVT_TEXT( ID_SPINCTRL5, dlgArticleEdit::OnSpinctrl5TextUpdated )

    EVT_UPDATE_UI( ID_NOTEBOOK5, dlgArticleEdit::OnNotebook5Update )

    EVT_DIRPICKER_CHANGED( ID_DIRPICKERCTRL, dlgArticleEdit::OnDirpickerctrlDirPickerChanged )

    EVT_BUTTON( wxID_OK, dlgArticleEdit::OnOkClick )

    EVT_BUTTON( wxID_CANCEL, dlgArticleEdit::OnCancelClick )

    EVT_BUTTON( wxID_APPLY, dlgArticleEdit::OnApplyClick )
    EVT_UPDATE_UI( wxID_APPLY, dlgArticleEdit::OnApplyUpdate )

////@end dlgArticleEdit event table entries

END_EVENT_TABLE()


/*
 * dlgArticleEdit constructors
 */

dlgArticleEdit::dlgArticleEdit()
{
    Init();
}

dlgArticleEdit::dlgArticleEdit( gvVisionManager *pgvVisionManager,gvVisionImage_botcap *pgvVisionImage, wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
	wxASSERT(pgvVisionImage);
	c_pgvVisionImage = pgvVisionImage;
	c_pgvVisionManager = pgvVisionManager;
	m_imgCnt= 0;
	/**<  */
    Init();
    Create(parent, id, caption, pos, size, style);
}


/*
 * dlgArticleEdit creator
 */

bool dlgArticleEdit::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin dlgArticleEdit creation
    SetExtraStyle(wxWS_EX_BLOCK_EVENTS);
    wxDialog::Create( parent, id, caption, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
////@end dlgArticleEdit creation

	unsigned int iIndex = 0;

	for(iIndex=0;iIndex<TASK_TYPE_NUM;iIndex++)
	{
		m_typeList->AppendString(g_pchTask_ALL[iIndex]);
	}


/**<  */
	unsigned int uiTaskCnt = c_pgvVisionImage->gvIMG_GetTaskCnt();
	for( iIndex=0; iIndex<uiTaskCnt; iIndex++ )
	{
		gvVisionTask* pgvTask = c_pgvVisionImage->gvIMG_GetTask(iIndex);
		add_task(pgvTask,pgvTask->gvTask_GetType());

		int idxType = pgvTask->gvTask_GetType();

	}

/**< 获取定位最小面积 */
	m_minarea->SetValue(c_pgvVisionImage->gvIMG_GetMinarea()) ;

    return true;
}


/*
 * dlgArticleEdit destructor
 */

dlgArticleEdit::~dlgArticleEdit()
{
////@begin dlgArticleEdit destruction
////@end dlgArticleEdit destruction
}


/*
 * Member initialisation
 */

void dlgArticleEdit::Init()
{
////@begin dlgArticleEdit member initialisation
    m_typeList = NULL;
    m_RoiType = NULL;
    m_taskList = NULL;
    m_minarea = NULL;
    m_noteBook = NULL;
    m_chkSngTest = NULL;
    m_chkModifyStd = NULL;
////@end dlgArticleEdit member initialisation
}


/*
 * Control creation for dlgArticleEdit
 */

void dlgArticleEdit::CreateControls()
{
////@begin dlgArticleEdit content construction
    dlgArticleEdit* itemDialog1 = this;

    this->SetFont(wxFont(10, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("微软雅黑")));
    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemDialog1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW|wxALL, 0);

    wxBoxSizer* itemBoxSizer4 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer4, 0, wxGROW|wxALL, 0);

    wxStaticBox* itemStaticBoxSizer5Static = new wxStaticBox(itemDialog1, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x65B9 + (wxChar) 0x6848 + (wxChar) 0x7BA1 + (wxChar) 0x7406));
    wxStaticBoxSizer* itemStaticBoxSizer5 = new wxStaticBoxSizer(itemStaticBoxSizer5Static, wxVERTICAL);
    itemBoxSizer4->Add(itemStaticBoxSizer5, 0, wxGROW|wxALL, 5);

    wxArrayString m_typeListStrings;
    m_typeList = new wxChoice( itemStaticBoxSizer5->GetStaticBox(), ID_CHOICE, wxDefaultPosition, wxDefaultSize, m_typeListStrings, 0 );
    itemStaticBoxSizer5->Add(m_typeList, 0, wxGROW|wxALL, 5);

    wxArrayString m_RoiTypeStrings;
    m_RoiTypeStrings.Add(wxGetTranslation(wxString() + (wxChar) 0x5706 + (wxChar) 0x5F62));
    m_RoiTypeStrings.Add(wxGetTranslation(wxString() + (wxChar) 0x65B9 + (wxChar) 0x5F62));
    m_RoiType = new wxRadioBox( itemStaticBoxSizer5->GetStaticBox(), ID_RADIOBOX, wxGetTranslation(wxString(wxT("ROI")) + (wxChar) 0x7C7B + (wxChar) 0x578B), wxDefaultPosition, wxDefaultSize, m_RoiTypeStrings, 1, wxRA_SPECIFY_ROWS );
    m_RoiType->SetSelection(0);
    itemStaticBoxSizer5->Add(m_RoiType, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer5->Add(itemBoxSizer8, 0, wxALIGN_CENTER_HORIZONTAL, 5);

    wxButton* itemButton9 = new wxButton( itemStaticBoxSizer5->GetStaticBox(), ID_BTN_ADD, wxGetTranslation(wxString() + (wxChar) 0x6DFB + (wxChar) 0x52A0 + (wxChar) 0x4EFB + (wxChar) 0x52A1), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(itemButton9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxButton* itemButton10 = new wxButton( itemStaticBoxSizer5->GetStaticBox(), ID_BTN_DEL, wxGetTranslation(wxString() + (wxChar) 0x5220 + (wxChar) 0x9664 + (wxChar) 0x4EFB + (wxChar) 0x52A1), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer8->Add(itemButton10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxArrayString m_taskListStrings;
    m_taskList = new wxListBox( itemStaticBoxSizer5->GetStaticBox(), ID_LISTBOX, wxDefaultPosition, wxSize(100, 250), m_taskListStrings, wxLB_SINGLE );
    m_taskList->SetStringSelection(_("0"));
    itemStaticBoxSizer5->Add(m_taskList, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer12 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer3->Add(itemBoxSizer12, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    wxBoxSizer* itemBoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer12->Add(itemBoxSizer13, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText14 = new wxStaticText( itemDialog1, wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x5B9A + (wxChar) 0x4F4D + (wxChar) 0x6700 + (wxChar) 0x5C0F + (wxChar) 0x9762 + (wxChar) 0x79EF), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer13->Add(itemStaticText14, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_minarea = new wxSpinCtrl( itemDialog1, ID_SPINCTRL5, _T("70000"), wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 10000, 999999, 70000 );
    itemBoxSizer13->Add(m_minarea, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxRIGHT, 5);

    m_noteBook = new wxNotebook( itemDialog1, ID_NOTEBOOK5, wxDefaultPosition, wxSize(300, 280), wxBK_DEFAULT );

    itemBoxSizer12->Add(m_noteBook, 0, wxGROW|wxALL, 5);

    wxStaticBox* itemStaticBoxSizer17Static = new wxStaticBox(itemDialog1, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x6D4B + (wxChar) 0x8BD5 + (wxChar) 0x56FE + (wxChar) 0x50CF + (wxChar) 0x8DEF + (wxChar) 0x5F84));
    wxStaticBoxSizer* itemStaticBoxSizer17 = new wxStaticBoxSizer(itemStaticBoxSizer17Static, wxVERTICAL);
    itemBoxSizer12->Add(itemStaticBoxSizer17, 0, wxGROW|wxALL, 5);

    wxDirPickerCtrl* itemDirPickerCtrl18 = new wxDirPickerCtrl( itemStaticBoxSizer17->GetStaticBox(), ID_DIRPICKERCTRL, wxEmptyString, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDIRP_DEFAULT_STYLE );
    itemStaticBoxSizer17->Add(itemDirPickerCtrl18, 0, wxGROW|wxALL, 5);

    wxBoxSizer* itemBoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer17->Add(itemBoxSizer19, 0, wxGROW|wxALL, 5);

    m_chkSngTest = new wxCheckBox( itemStaticBoxSizer17->GetStaticBox(), ID_CHECKBOX, wxGetTranslation(wxString() + (wxChar) 0x5355 + (wxChar) 0x5E45 + (wxChar) 0x56FE + (wxChar) 0x50CF + (wxChar) 0x6D4B + (wxChar) 0x8BD5), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkSngTest->SetValue(false);
    itemBoxSizer19->Add(m_chkSngTest, 0, wxGROW|wxALL, 5);

    m_chkModifyStd = new wxCheckBox( itemStaticBoxSizer17->GetStaticBox(), ID_CHECKBOX1, wxGetTranslation(wxString() + (wxChar) 0x6D4B + (wxChar) 0x8BD5 + (wxChar) 0x65F6 + (wxChar) 0x6539 + (wxChar) 0x53D8 + (wxChar) 0x6807 + (wxChar) 0x51C6 + (wxChar) 0x503C), wxDefaultPosition, wxDefaultSize, 0 );
    m_chkModifyStd->SetValue(false);
    itemBoxSizer19->Add(m_chkModifyStd, 0, wxGROW|wxALL, 5);

    wxStaticText* itemStaticText22 = new wxStaticText( itemStaticBoxSizer17->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x81EA + (wxChar) 0x52A8 + (wxChar) 0x8BFB + (wxChar) 0x53D6 + wxT("<") + (wxChar) 0x6D4B + (wxChar) 0x8BD5 + (wxChar) 0x56FE + (wxChar) 0x50CF + (wxChar) 0x8DEF + (wxChar) 0x5F84 + wxT(">") + (wxChar) 0x4E0B + (wxChar) 0x7684 + (wxChar) 0x6240 + (wxChar) 0x6709 + wxT("JPG") + (wxChar) 0x56FE + (wxChar) 0x50CF + (wxChar) 0x6587 + (wxChar) 0x4EF6 + wxT("\n") + (wxChar) 0x5F53 + (wxChar) 0x672A + (wxChar) 0x9009 + (wxChar) 0x62E9 + wxT("<") + (wxChar) 0x5355 + (wxChar) 0x5E45 + (wxChar) 0x56FE + (wxChar) 0x50CF + (wxChar) 0x6D4B + (wxChar) 0x8BD5 + wxT(">") + (wxChar) 0x65F6 + (wxChar) 0xFF0C + (wxChar) 0x6BCF + (wxChar) 0x6B21 + (wxChar) 0x70B9 + (wxChar) 0x51FB + (wxChar) 0x6D4B + (wxChar) 0x8BD5 + (wxChar) 0x4F1A + (wxChar) 0x81EA + (wxChar) 0x52A8 + (wxChar) 0x6D4B + (wxChar) 0x8BD5 + (wxChar) 0x4E0B + (wxChar) 0x4E00 + (wxChar) 0x5E45 + (wxChar) 0x56FE + (wxChar) 0x50CF), wxDefaultPosition, wxSize(300, -1), 0 );
    itemStaticText22->SetForegroundColour(wxColour(192, 192, 192));
    itemStaticBoxSizer17->Add(itemStaticText22, 0, wxGROW|wxALL, 5);

    wxStdDialogButtonSizer* itemStdDialogButtonSizer23 = new wxStdDialogButtonSizer;

    itemStaticBoxSizer17->Add(itemStdDialogButtonSizer23, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 0);
    wxButton* itemButton24 = new wxButton( itemStaticBoxSizer17->GetStaticBox(), wxID_OK, wxGetTranslation(wxString() + (wxChar) 0x4FDD + (wxChar) 0x5B58), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer23->AddButton(itemButton24);

    wxButton* itemButton25 = new wxButton( itemStaticBoxSizer17->GetStaticBox(), wxID_CANCEL, wxGetTranslation(wxString() + (wxChar) 0x53D6 + (wxChar) 0x6D88), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer23->AddButton(itemButton25);

    wxButton* itemButton26 = new wxButton( itemStaticBoxSizer17->GetStaticBox(), wxID_APPLY, _("&Apply"), wxDefaultPosition, wxDefaultSize, 0 );
    itemStdDialogButtonSizer23->AddButton(itemButton26);

    itemStdDialogButtonSizer23->Realize();

////@end dlgArticleEdit content construction
}

/*
 * Should we show tooltips?
 */

bool dlgArticleEdit::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap dlgArticleEdit::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin dlgArticleEdit bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end dlgArticleEdit bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon dlgArticleEdit::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin dlgArticleEdit icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end dlgArticleEdit icon retrieval
}

void dlgArticleEdit::add_task( gvVisionTask* pgvTask,E_TASK_TYPE_ALL taskType )
{
	wxPanel* panel = nullptr;
	E_ROI_TYPE type=(E_ROI_TYPE)(m_RoiType->GetSelection());
	switch(taskType)
	{
	case TASKTYPE_BLACK:
		if(!pgvTask)
		{
			pgvTask= new gvVisionTask_black(type);
			c_pgvVisionImage->gvIMG_AddTask(pgvTask);
		}
		panel = new panTaskBlack(pgvTask,m_noteBook);
		break;
	case TASKTYPE_LOGO:
		if(!pgvTask)
		{
			pgvTask= new gvVisionTask_logo(type);
			c_pgvVisionImage->gvIMG_AddTask(pgvTask);
			wxString modelname = wxString::Format(wxT("CCD%03dTASK%03d"),c_pgvVisionManager->get_idxActiveCCD(),m_taskList->GetCount()+1);

			((gvVisionTask_logo*)pgvTask)->gvTask_SetModelname(modelname);
		}
		panel = new panTaskLogo(c_pgvVisionImage,pgvTask,m_noteBook);
		break;
	case TASKTYPE_COLOR:
		if(!pgvTask)
		{
			pgvTask= new gvVisionTask_color(type);
			c_pgvVisionImage->gvIMG_AddTask(pgvTask);
		}
		panel = new panTaskColor(c_pgvVisionImage,pgvTask,m_noteBook);

	}
	if(panel)
	{
		m_noteBook->AddPage(panel,g_pchTask_ALL[taskType],true);
		m_taskList->AppendString(g_pchTask_ALL[taskType]);
	}
}
void dlgArticleEdit::del_task(unsigned int idxtask)
{

	m_noteBook->DeletePage(idxtask);
	m_taskList->Delete(idxtask);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ADD
 */

void dlgArticleEdit::OnBtnAddClick( wxCommandEvent& event )
{
	int idxType = m_typeList->GetSelection();
	add_task(nullptr,(E_TASK_TYPE_ALL)idxType);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_ADD
 */

void dlgArticleEdit::OnBtnAddUpdate( wxUpdateUIEvent& event )
{
	event.Enable(m_typeList->GetSelection()>=0);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_DEL
 */

void dlgArticleEdit::OnBtnDelClick( wxCommandEvent& event )
{
	int idxtask = m_taskList->GetSelection();
	del_task(idxtask);
	c_pgvVisionImage->gvIMG_DeletTask(idxtask);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_DEL
 */

void dlgArticleEdit::OnBtnDelUpdate( wxUpdateUIEvent& event )
{
	event.Enable(m_taskList->GetSelection()>=0);
}


void dlgArticleEdit::params_Write()
{
	c_pgvVisionImage->gvIMG_SetMinarea(m_minarea->GetValue());

}

/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
 */

void dlgArticleEdit::OnOkClick( wxCommandEvent& event )
{
		params_Write();
		wxString filename = c_pgvVisionManager->gvMgr_getConfigFile();
		c_pgvVisionManager->gvMgr_SaveConfig(filename,FALSE);
		EndModal(wxID_OK);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
 */

void dlgArticleEdit::OnCancelClick( wxCommandEvent& event )
{
	wxString filename = c_pgvVisionManager->gvMgr_getConfigFile();
	c_pgvVisionManager->gvMgr_LoadConfig(filename);
	EndModal(wxID_OK);
}


/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL5
 */

void dlgArticleEdit::OnSpinctrl5Updated( wxSpinEvent& event )
{
	//c_pgvVisionImage->gvIMG_SetMinarea(m_minarea->GetValue());
}


/*
 * wxEVT_COMMAND_TEXT_UPDATED event handler for ID_SPINCTRL5
 */

void dlgArticleEdit::OnSpinctrl5TextUpdated( wxCommandEvent& event )
{
}


/*
 * wxEVT_UPDATE_UI event handler for ID_NOTEBOOK5
 */

void dlgArticleEdit::OnNotebook5Update( wxUpdateUIEvent& event )
{
	m_noteBook->ChangeSelection(m_taskList->GetSelection());
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_Apply
 */

void dlgArticleEdit::OnApplyClick( wxCommandEvent& event )
{
	params_Write();
	if(m_chkSngTest->IsChecked())
	{
		c_pgvVisionImage->gvIMG_LoadImage(m_arrJPGs[m_idxJPGs-1]);
	}
	else
	{
		if(m_idxJPGs<m_arrJPGs.size())
            m_idxJPGs++;
		else
            m_idxJPGs = 1;
		c_pgvVisionImage->gvIMG_LoadImage(m_arrJPGs[m_idxJPGs-1]);

	}
	c_pgvVisionImage->gvIMG_TriggerInspection(true);
}

/*
 * wxEVT_UPDATE_UI event handler for ID_Apply
 */

void dlgArticleEdit::OnApplyUpdate( wxUpdateUIEvent& event )
{
    event.Enable( 0 >= m_imgCnt ? false : true);
}

/*
 * wxEVT_DIRPICKER_CHANGED event handler for ID_DIRPICKERCTRL
 */

void dlgArticleEdit::OnDirpickerctrlDirPickerChanged( wxFileDirPickerEvent& event )
{
	m_arrJPGs.clear();
	m_imgCnt = wxDir::GetAllFiles(event.GetPath(),&m_arrJPGs,wxT("*.jpg"),wxDIR_DEFAULT);
	if(	m_imgCnt <= 0)
	{
		wxMessageBox(wxT("当前文件夹中没有JPG图像文件！"));
	}
	m_idxJPGs = 0;
}

