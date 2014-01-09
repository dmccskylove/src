/////////////////////////////////////////////////////////////////////////////
// Name:        dlgarticlenew.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     30/12/2013 15:28:02
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLGARTICLENEW_H_
#define _DLGARTICLENEW_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/statline.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DLGARTICLENEW 10006
#define ID_CHK_CAM1 10001
#define ID_CHK_CAM2 10018
#define ID_CHK_CAM3 10007
#define ID_CHOICE_CAM1 10010
#define ID_CHOICE_CAM2 10025
#define ID_CHOICE_CAM3 10012
#define ID_CHK_CAM4 10014
#define ID_CHK_CAM5 10014
#define ID_CHK_CAM6 10008
#define ID_CHOICE_CAM4 10022
#define ID_CHOICE_CAM5 10022
#define ID_CHOICE_CAM6 10013
#define ID_TEXTCTRL_COLORA 10046
#define ID_TEXTCTRL_ARTICLENAME 10048
#define ID_PANEL3 10052
#define SYMBOL_DLGARTICLENEW_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_DLGARTICLENEW_TITLE wxGetTranslation(wxString() + (wxChar) 0x65B0 + (wxChar) 0x5EFA + (wxChar) 0x4EA7 + (wxChar) 0x54C1 + (wxChar) 0x65B9 + (wxChar) 0x6848)
#define SYMBOL_DLGARTICLENEW_IDNAME ID_DLGARTICLENEW
#define SYMBOL_DLGARTICLENEW_SIZE wxSize(400, 300)
#define SYMBOL_DLGARTICLENEW_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * dlgArticleNew class declaration
 */

class dlgArticleNew: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( dlgArticleNew )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    dlgArticleNew();
    dlgArticleNew( wxWindow* parent, wxWindowID id = SYMBOL_DLGARTICLENEW_IDNAME, const wxString& caption = SYMBOL_DLGARTICLENEW_TITLE, const wxPoint& pos = SYMBOL_DLGARTICLENEW_POSITION, const wxSize& size = SYMBOL_DLGARTICLENEW_SIZE, long style = SYMBOL_DLGARTICLENEW_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DLGARTICLENEW_IDNAME, const wxString& caption = SYMBOL_DLGARTICLENEW_TITLE, const wxPoint& pos = SYMBOL_DLGARTICLENEW_POSITION, const wxSize& size = SYMBOL_DLGARTICLENEW_SIZE, long style = SYMBOL_DLGARTICLENEW_STYLE );

    /// Destructor
    ~dlgArticleNew();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin dlgArticleNew event handler declarations

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM1
    void OnChkCam1Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHK_CAM1
    void OnChkCam1Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM2
    void OnChkCam2Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHK_CAM2
    void OnChkCam2Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM3
    void OnChkCam3Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHK_CAM3
    void OnChkCam3Update( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM1
    void OnChoiceCam1Update( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM2
    void OnChoiceCam2Update( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM3
    void OnChoiceCam3Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_CHECKBOX_CLICKED event handler for ID_CHK_CAM4
    void OnChkCam4Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHK_CAM4
    void OnChkCam4Update( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM4
    void OnChoiceCam4Update( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM5
    void OnChoiceCam5Update( wxUpdateUIEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_CHOICE_CAM6
    void OnChoiceCam6Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_TEXTCTRL_COLORA
    void OnTextctrlColoraTextUpdated( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TEXTCTRL_ARTICLENAME
    void OnTextctrlArticlenameUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

////@end dlgArticleNew event handler declarations

////@begin dlgArticleNew member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dlgArticleNew member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin dlgArticleNew member variables
    wxCheckBox* m_chkcam1;
    wxCheckBox* m_chkcam2;
    wxCheckBox* m_chkcam3;
    wxChoice* m_typecam1;
    wxChoice* m_typecam2;
    wxChoice* m_typecam3;
    wxCheckBox* m_chkcam4;
    wxCheckBox* m_chkcam5;
    wxCheckBox* m_chkcam6;
    wxChoice* m_typecam4;
    wxChoice* m_typecam5;
    wxChoice* m_typecam6;
    wxTextCtrl* m_txtColorA;
    wxTextCtrl* m_txtTitle;
////@end dlgArticleNew member variables

	int m_usingcamcount;
};

#endif
    // _DLGARTICLENEW_H_
