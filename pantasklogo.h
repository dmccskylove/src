/////////////////////////////////////////////////////////////////////////////
// Name:        pentasklogo.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     08/01/2014 16:12:25
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _PENTASKLOGO_H_
#define _PENTASKLOGO_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/spinctrl.h"
#include "wx/filepicker.h"
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
#define ID_PENTASKLOGO 10075
#define ID_SPINCTRL4 10076
#define ID_BUTTON 10077
#define ID_FILECTRL 10078
#define SYMBOL_PANTASKLOGO_STYLE wxTAB_TRAVERSAL
#define SYMBOL_PANTASKLOGO_TITLE _("penTaskLogo")
#define SYMBOL_PANTASKLOGO_IDNAME ID_PENTASKLOGO
#define SYMBOL_PANTASKLOGO_SIZE wxSize(400, 300)
#define SYMBOL_PANTASKLOGO_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * panTaskLogo class declaration
 */

class gvVisionTask_logo;
class gvVisionTask;
class gvVisionImage_botcap;
class panTaskLogo: public wxPanel
{
    DECLARE_DYNAMIC_CLASS( panTaskLogo )
    DECLARE_EVENT_TABLE()

public:
	void ReadParam();
	void SaveParam();
    /// Constructors
    panTaskLogo();
    panTaskLogo(gvVisionImage_botcap* pgvVisionImage, gvVisionTask* gvTask,wxWindow* parent, wxWindowID id = SYMBOL_PANTASKLOGO_IDNAME, const wxPoint& pos = SYMBOL_PANTASKLOGO_POSITION, const wxSize& size = SYMBOL_PANTASKLOGO_SIZE, long style = SYMBOL_PANTASKLOGO_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_PANTASKLOGO_IDNAME, const wxPoint& pos = SYMBOL_PANTASKLOGO_POSITION, const wxSize& size = SYMBOL_PANTASKLOGO_SIZE, long style = SYMBOL_PANTASKLOGO_STYLE );

    /// Destructor
    ~panTaskLogo();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin panTaskLogo event handler declarations

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL4
    void OnSpinctrl4Updated( wxSpinEvent& event );

    /// wxEVT_COMMAND_TEXT_UPDATED event handler for ID_SPINCTRL4
    void OnSpinctrl4TextUpdated( wxCommandEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON
    void OnButtonClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BUTTON
    void OnButtonUpdate( wxUpdateUIEvent& event );

    /// wxEVT_FILEPICKER_CHANGED event handler for ID_FILECTRL
    void OnFilectrlFilePickerChanged( wxFileDirPickerEvent& event );

////@end panTaskLogo event handler declarations

////@begin panTaskLogo member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end panTaskLogo member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin panTaskLogo member variables
    wxSpinCtrl* m_minsocre;
////@end panTaskLogo member variables

	gvVisionTask_logo*			c_pgvTask;
	gvVisionImage_botcap* 	c_pgvVisionImage;
	bool 								m_isloadImage;
};

#endif
    // _PENTASKLOGO_H_
