/////////////////////////////////////////////////////////////////////////////
// Name:        pantaskblack.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     05/01/2014 13:19:45
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _PANTASKBLACK_H_
#define _PANTASKBLACK_H_


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
#define ID_PANTASKBLACK 10054
#define ID_SPINCTRL 10058
#define ID_SPINCTRL2 10060
#define ID_SPINCTRL3 10061
#define SYMBOL_PANTASKBLACK_STYLE wxTAB_TRAVERSAL
#define SYMBOL_PANTASKBLACK_TITLE _("panTaskBlack")
#define SYMBOL_PANTASKBLACK_IDNAME ID_PANTASKBLACK
#define SYMBOL_PANTASKBLACK_SIZE wxSize(400, 300)
#define SYMBOL_PANTASKBLACK_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * panTaskBlack class declaration
 */
class gvVisionTask_black;
class gvVisionTask;
class panTaskBlack: public wxPanel
{
    DECLARE_DYNAMIC_CLASS( panTaskBlack )
    DECLARE_EVENT_TABLE()

public:


	void ReadParam();
	void SaveParam();

    /// Constructors
    panTaskBlack();
    panTaskBlack( gvVisionTask* gvTask,wxWindow* parent, wxWindowID id = SYMBOL_PANTASKBLACK_IDNAME, const wxPoint& pos = SYMBOL_PANTASKBLACK_POSITION, const wxSize& size = SYMBOL_PANTASKBLACK_SIZE, long style = SYMBOL_PANTASKBLACK_STYLE );

    /// Creation
    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_PANTASKBLACK_IDNAME, const wxPoint& pos = SYMBOL_PANTASKBLACK_POSITION, const wxSize& size = SYMBOL_PANTASKBLACK_SIZE, long style = SYMBOL_PANTASKBLACK_STYLE );

    /// Destructor
    ~panTaskBlack();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin panTaskBlack event handler declarations

////@end panTaskBlack event handler declarations

////@begin panTaskBlack member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end panTaskBlack member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin panTaskBlack member variables
    wxSpinCtrl* m_minBlackSpotArea;
    wxSpinCtrl* m_minBlackSpotCnt;
    wxSpinCtrl* m_maxBlackSpotCnt;
////@end panTaskBlack member variables

	gvVisionTask_black *c_pgvTask;

};

#endif
    // _PANTASKBLACK_H_
