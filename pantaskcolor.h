/////////////////////////////////////////////////////////////////////////////
// Name:        pantaskcolor.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     09/01/2014 13:01:38
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _PANTASKCOLOR_H_
#define _PANTASKCOLOR_H_


/*!
 * Includes
 */

////@begin includes
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
#define ID_PANTASKCOLOR 10079
#define ID_SPINBLUE 10080
#define ID_SPINBLUE1 10081
#define ID_SPINRED 10102
#define ID_SPINRED1 10103
#define ID_SPINGREEN 10100
#define ID_SPINGREEN1 10101
#define ID_BUTTON1 10082
#define ID_BUTTON2 10083
#define SYMBOL_PANTASKCOLOR_STYLE wxTAB_TRAVERSAL
#define SYMBOL_PANTASKCOLOR_TITLE _("panTaskColor")
#define SYMBOL_PANTASKCOLOR_IDNAME ID_PANTASKCOLOR
#define SYMBOL_PANTASKCOLOR_SIZE wxSize(300, 280)
#define SYMBOL_PANTASKCOLOR_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * panTaskColor class declaration
 */
class gvVisionTask_color;
class gvVisionTask;
class gvVisionImage_botcap;
class panTaskColor: public wxPanel
{
    DECLARE_DYNAMIC_CLASS( panTaskColor )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    panTaskColor();
    panTaskColor(gvVisionImage_botcap* pgvVisionImage, gvVisionTask* gvTask, wxWindow* parent, wxWindowID id = SYMBOL_PANTASKCOLOR_IDNAME, const wxPoint& pos = SYMBOL_PANTASKCOLOR_POSITION, const wxSize& size = SYMBOL_PANTASKCOLOR_SIZE, long style = SYMBOL_PANTASKCOLOR_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_PANTASKCOLOR_IDNAME, const wxPoint& pos = SYMBOL_PANTASKCOLOR_POSITION, const wxSize& size = SYMBOL_PANTASKCOLOR_SIZE, long style = SYMBOL_PANTASKCOLOR_STYLE );

    /// Destructor
    ~panTaskColor();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin panTaskColor event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON1
    void OnButton1Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BUTTON1
    void OnButton1Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BUTTON2
    void OnButton2Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BUTTON2
    void OnButton2Update( wxUpdateUIEvent& event );

////@end panTaskColor event handler declarations

////@begin panTaskColor member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end panTaskColor member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin panTaskColor member variables
    wxSpinCtrl* m_meanblue;
    wxSpinCtrl* m_actualblue;
    wxSpinCtrl* m_meanred;
    wxSpinCtrl* m_actualred;
    wxSpinCtrl* m_meangreen;
    wxSpinCtrl* m_actualgreen;
////@end panTaskColor member variables

	gvVisionTask_color*			c_pgvTask;
	gvVisionImage_botcap* 	c_pgvVisionImage;
};

#endif
    // _PANTASKCOLOR_H_
