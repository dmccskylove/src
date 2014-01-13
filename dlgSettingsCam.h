/////////////////////////////////////////////////////////////////////////////
// Name:        dlgSettingsCam.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     19/12/2013 14:21:21
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLGSETTINGSCAM_H_
#define _DLGSETTINGSCAM_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/notebook.h"
#include "wx/spinctrl.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxSpinCtrl;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_DLGCAMSETTINGS 10049
#define ID_NOTEBOOK7 10067
#define ID_PANEL22 10068
#define ID_SLIDER_EXPO 10050
#define ID_PANEL23 10069
#define ID_SLIDER_GAIN 10051
#define ID_PANEL 10085
#define ID_SPINCTRL6 10088
#define ID_SPINCTRL1 10059
#define ID_PANEL4 10053
#define SYMBOL_DLGSETTINGSCAM_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxTAB_TRAVERSAL
#define SYMBOL_DLGSETTINGSCAM_TITLE _("Camera Settings")
#define SYMBOL_DLGSETTINGSCAM_IDNAME ID_DLGCAMSETTINGS
#define SYMBOL_DLGSETTINGSCAM_SIZE wxSize(400, 300)
#define SYMBOL_DLGSETTINGSCAM_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * dlgSettingsCam class declaration
 */
class gvVisionCCD;
class gvVisionCam_acA;
class gvVisionManager;
class dlgSettingsCam: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( dlgSettingsCam )
    DECLARE_EVENT_TABLE()

public:
	void ReadParam();
	void SaveParam();
    /// Constructors
    dlgSettingsCam();
    dlgSettingsCam( gvVisionCCD * pgvVisionCCD,wxWindow* parent, wxWindowID id = SYMBOL_DLGSETTINGSCAM_IDNAME, const wxString& caption = SYMBOL_DLGSETTINGSCAM_TITLE, const wxPoint& pos = SYMBOL_DLGSETTINGSCAM_POSITION, const wxSize& size = SYMBOL_DLGSETTINGSCAM_SIZE, long style = SYMBOL_DLGSETTINGSCAM_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DLGSETTINGSCAM_IDNAME, const wxString& caption = SYMBOL_DLGSETTINGSCAM_TITLE, const wxPoint& pos = SYMBOL_DLGSETTINGSCAM_POSITION, const wxSize& size = SYMBOL_DLGSETTINGSCAM_SIZE, long style = SYMBOL_DLGSETTINGSCAM_STYLE );

    /// Destructor
    ~dlgSettingsCam();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin dlgSettingsCam event handler declarations

    /// wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_EXPO
    void OnSliderExpoScrollChanged( wxScrollEvent& event );

    /// wxEVT_SCROLL_CHANGED event handler for ID_SLIDER_GAIN
    void OnSliderGainScrollChanged( wxScrollEvent& event );

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL6
    void OnSpinctrl6Updated( wxSpinEvent& event );

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL1
    void OnSpinctrl1Updated( wxSpinEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_CANCEL
    void OnCancelClick( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for wxID_OK
    void OnOkClick( wxCommandEvent& event );

////@end dlgSettingsCam event handler declarations

////@begin dlgSettingsCam member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dlgSettingsCam member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin dlgSettingsCam member variables
    wxSlider* m_sldExpo;
    wxSlider* m_sldGain;
    wxSpinCtrl* m_rejectdelay;
    wxSpinCtrl* m_idxPort;
////@end dlgSettingsCam member variables

	gvVisionCCD* 		c_pgvVisionCCD;
	gvVisionCam_acA*  c_pgvVisionCam;
	gvVisionManager *  c_pgvVisionManager;
};

#endif
// _DLGSETTINGSCAM_H_
