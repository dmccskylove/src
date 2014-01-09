/////////////////////////////////////////////////////////////////////////////
// Name:        choicetasklist.h
// Purpose:     
// Author:      史明忠
// Modified by: 
// Created:     06/01/2014 00:07:24
// RCS-ID:      
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _CHOICETASKLIST_H_
#define _CHOICETASKLIST_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/odcombo.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class ChoiceTaskList;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_OWNERDRAWNCOMBOCTRL 10062
#define SYMBOL_CHOICETASKLIST_STYLE 0
#define SYMBOL_CHOICETASKLIST_IDNAME ID_OWNERDRAWNCOMBOCTRL
#define SYMBOL_CHOICETASKLIST_SIZE wxDefaultSize
#define SYMBOL_CHOICETASKLIST_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * choiceTaskList class declaration
 */

class choiceTaskList: public wxOwnerDrawnComboBox
{    
    DECLARE_DYNAMIC_CLASS( choiceTaskList )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    choiceTaskList();
    choiceTaskList(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxString& value, const wxSize& size, const wxArrayString& choices, long style = 0, const wxValidator& validator = wxDefaultValidator);

    /// Creation
    bool Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxString& value, const wxSize& size, const wxArrayString& choices, long style = 0, const wxValidator& validator = wxDefaultValidator);

    /// Destructor
    ~choiceTaskList();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin choiceTaskList event handler declarations

////@end choiceTaskList event handler declarations

////@begin choiceTaskList member function declarations

////@end choiceTaskList member function declarations

    /// Draws the given item
    virtual void OnDrawItem(wxDC& dc, const wxRect& rect, int item, int flags) const;

    /// Draws the given item's background
    virtual void OnDrawBackground(wxDC& dc, const wxRect& rect, int item, int flags) const;

    /// Measures the given item's height
    virtual wxCoord OnMeasureItem(size_t item) const;

    /// Measures the given item's width
    virtual wxCoord OnMeasureItemWidth(size_t item) const;

////@begin choiceTaskList member variables
////@end choiceTaskList member variables
};

/*!
 * ChoiceTaskList class declaration
 */

class ChoiceTaskList: public wxOwnerDrawnComboBox
{    
    DECLARE_DYNAMIC_CLASS( ChoiceTaskList )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    ChoiceTaskList();
    ChoiceTaskList(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxString& value, const wxSize& size, const wxArrayString& choices, long style = 0, const wxValidator& validator = wxDefaultValidator);

    /// Creation
    bool Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxString& value, const wxSize& size, const wxArrayString& choices, long style = 0, const wxValidator& validator = wxDefaultValidator);

    /// Destructor
    ~ChoiceTaskList();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin ChoiceTaskList event handler declarations

    /// wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_OWNERDRAWNCOMBOCTRL
    void OnOwnerdrawncomboctrlSelected( wxCommandEvent& event );

////@end ChoiceTaskList event handler declarations

////@begin ChoiceTaskList member function declarations

////@end ChoiceTaskList member function declarations

    /// Draws the given item
    virtual void OnDrawItem(wxDC& dc, const wxRect& rect, int item, int flags) const;

    /// Draws the given item's background
    virtual void OnDrawBackground(wxDC& dc, const wxRect& rect, int item, int flags) const;

    /// Measures the given item's height
    virtual wxCoord OnMeasureItem(size_t item) const;

    /// Measures the given item's width
    virtual wxCoord OnMeasureItemWidth(size_t item) const;

////@begin ChoiceTaskList member variables
////@end ChoiceTaskList member variables
};

#endif
    // _CHOICETASKLIST_H_
