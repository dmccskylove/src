/////////////////////////////////////////////////////////////////////////////
// Name:        dlgarticleedit.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     06/01/2014 09:02:19
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLGARTICLEEDIT_H_
#define _DLGARTICLEEDIT_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/spinctrl.h"
#include "wx/notebook.h"
#include "wx/filepicker.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxSpinCtrl;
class wxNotebook;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DLGARTICLEEDIT 10005
#define ID_CHOICE 10011
#define ID_RADIOBOX 10062
#define ID_BTN_ADD 10031
#define ID_BTN_DEL 10066
#define ID_LISTBOX 10032
#define ID_SPINCTRL5 10047
#define ID_NOTEBOOK5 10063
#define ID_DIRPICKERCTRL 10064
#define ID_CHECKBOX 10065
#define ID_CHECKBOX1 10072
#define ID_Apply 10074
#define SYMBOL_DLGARTICLEEDIT_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_DLGARTICLEEDIT_TITLE _("ArticleEdit")
#define SYMBOL_DLGARTICLEEDIT_IDNAME ID_DLGARTICLEEDIT
#define SYMBOL_DLGARTICLEEDIT_SIZE wxSize(400, 300)
#define SYMBOL_DLGARTICLEEDIT_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * dlgArticleEdit class declaration
 */
class gvVisionImage_botcap;
class gvVisionTask;
class gvVisionManager;
class gvVisionCCD;
class dlgArticleEdit: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( dlgArticleEdit )
    DECLARE_EVENT_TABLE()
private:
	void add_task(  gvVisionTask* pgvTask,E_TASK_TYPE_ALL taskType );
	void del_task(unsigned int idxtask);
	void params_Write();
	gvVisionImage_botcap	*c_pgvVisionImage;
	gvVisionManager *c_pgvVisionManager;
public:
    /// Constructors
    dlgArticleEdit();
    dlgArticleEdit(gvVisionManager *pgvVisionManager, gvVisionImage_botcap *pgvVisionImage, wxWindow* parent, wxWindowID id = SYMBOL_DLGARTICLEEDIT_IDNAME, const wxString& caption = SYMBOL_DLGARTICLEEDIT_TITLE, const wxPoint& pos = SYMBOL_DLGARTICLEEDIT_POSITION, const wxSize& size = SYMBOL_DLGARTICLEEDIT_SIZE, long style = SYMBOL_DLGARTICLEEDIT_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DLGARTICLEEDIT_IDNAME, const wxString& caption = SYMBOL_DLGARTICLEEDIT_TITLE, const wxPoint& pos = SYMBOL_DLGARTICLEEDIT_POSITION, const wxSize& size = SYMBOL_DLGARTICLEEDIT_SIZE, long style = SYMBOL_DLGARTICLEEDIT_STYLE );

    /// Destructor
    ~dlgArticleEdit();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin dlgArticleEdit event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ADD
    void OnBtnAddClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_ADD
    void OnBtnAddUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_DEL
    void OnBtnDelClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_DEL
    void OnBtnDelUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL5
    void OnSpinctrl5Updated( wxSpinEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_SPINCTRL5
    void OnSpinctrl5TextUpdated( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_NOTEBOOK5
    void OnNotebook5Update( wxUpdateUIEvent& event );

    /// wxEVT_DIRPICKER_CHANGED event handler for ID_DIRPICKERCTRL
    void OnDirpickerctrlDirPickerChanged( wxFileDirPickerEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_Apply
    void OnApplyClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_Apply
    void OnApplyUpdate( wxUpdateUIEvent& event );

////@end dlgArticleEdit event handler declarations

////@begin dlgArticleEdit member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dlgArticleEdit member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin dlgArticleEdit member variables
    wxChoice* m_typeList;
    wxRadioBox* m_RoiType;
    wxListBox* m_taskList;
    wxSpinCtrl* m_minarea;
    wxNotebook* m_noteBook;
    wxCheckBox* m_chkSngTest;
    wxCheckBox* m_chkModifyStd;
////@end dlgArticleEdit member variables

		/**< 图像列表 */
	wxArrayString 	m_arrJPGs;
	unsigned int 	m_idxJPGs;
	int m_imgCnt;
};

#endif
    // _DLGARTICLEEDIT_H_
