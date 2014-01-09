/////////////////////////////////////////////////////////////////////////////
// Name:        dlgshutdown.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     19/12/2013 14:22:34
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _DLGSHUTDOWN_H_
#define _DLGSHUTDOWN_H_


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
#define ID_DLGSHUTDOWN 10055
#define ID_RADIOBOX2 10056
#define ID_PANEL5 10057
#define SYMBOL_DLGSHUTDOWN_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX|wxNO_BORDER|wxTAB_TRAVERSAL
#define SYMBOL_DLGSHUTDOWN_TITLE _("Shutdown or Restart")
#define SYMBOL_DLGSHUTDOWN_IDNAME ID_DLGSHUTDOWN
#define SYMBOL_DLGSHUTDOWN_SIZE wxSize(400, 300)
#define SYMBOL_DLGSHUTDOWN_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * dlgShutdown class declaration
 */

class dlgShutdown: public wxDialog
{
    DECLARE_DYNAMIC_CLASS( dlgShutdown )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    dlgShutdown();
    dlgShutdown( wxWindow* parent, wxWindowID id = SYMBOL_DLGSHUTDOWN_IDNAME, const wxString& caption = SYMBOL_DLGSHUTDOWN_TITLE, const wxPoint& pos = SYMBOL_DLGSHUTDOWN_POSITION, const wxSize& size = SYMBOL_DLGSHUTDOWN_SIZE, long style = SYMBOL_DLGSHUTDOWN_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_DLGSHUTDOWN_IDNAME, const wxString& caption = SYMBOL_DLGSHUTDOWN_TITLE, const wxPoint& pos = SYMBOL_DLGSHUTDOWN_POSITION, const wxSize& size = SYMBOL_DLGSHUTDOWN_SIZE, long style = SYMBOL_DLGSHUTDOWN_STYLE );

    /// Destructor
    ~dlgShutdown();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin dlgShutdown event handler declarations
////@end dlgShutdown event handler declarations

////@begin dlgShutdown member function declarations
    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end dlgShutdown member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin dlgShutdown member variables
    wxRadioBox* m_typeShut;
////@end dlgShutdown member variables
};

#endif
// _DLGSHUTDOWN_H_
