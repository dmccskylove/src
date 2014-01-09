/////////////////////////////////////////////////////////////////////////////
// Name:        choicetasklist.cpp
// Purpose:     
// Author:      史明忠
// Modified by: 
// Created:     06/01/2014 00:07:24
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

#include "choicetasklist.h"

////@begin XPM images
////@end XPM images


/*
 * choiceTaskList type definition
 */

IMPLEMENT_DYNAMIC_CLASS( choiceTaskList, wxOwnerDrawnComboBox )


/*
 * choiceTaskList event table definition
 */

BEGIN_EVENT_TABLE( choiceTaskList, wxOwnerDrawnComboBox )

////@begin choiceTaskList event table entries
////@end choiceTaskList event table entries

END_EVENT_TABLE()


/*
 * choiceTaskList constructors
 */

choiceTaskList::choiceTaskList()
{
    Init();
}

choiceTaskList::choiceTaskList(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxString& value, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator)
{
    Init();
    Create(parent, id, value, pos, size, choices, style, validator);
}


/*
 * choiceTaskList creator
 */

bool choiceTaskList::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxString& value, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator)
{
////@begin choiceTaskList creation
    wxOwnerDrawnComboBox::Create(parent, id, value, pos, size, choices, style, validator);
    CreateControls();
////@end choiceTaskList creation
    return true;
}


/*
 * choiceTaskList destructor
 */

choiceTaskList::~choiceTaskList()
{
////@begin choiceTaskList destruction
////@end choiceTaskList destruction
}


/*
 * Member initialisation
 */

void choiceTaskList::Init()
{
////@begin choiceTaskList member initialisation
////@end choiceTaskList member initialisation
}


/*
 * Control creation for choiceTaskList
 */

void choiceTaskList::CreateControls()
{    
////@begin choiceTaskList content construction
////@end choiceTaskList content construction
}


/*
 * Draws the given item
 */

void choiceTaskList::OnDrawItem(wxDC& dc, const wxRect& rect, int item, int flags) const
{
    // TODO: implement me
    wxOwnerDrawnComboBox::OnDrawItem(dc, rect, item, flags);
}

/*
 * Draws the given item
 */

void choiceTaskList::OnDrawBackground(wxDC& dc, const wxRect& rect, int item, int flags) const
{
    // TODO: implement me
    wxOwnerDrawnComboBox::OnDrawBackground(dc, rect, item, flags);
}

/*
 * Measures the given item's height
 */

wxCoord choiceTaskList::OnMeasureItem(size_t WXUNUSED(item)) const
{
    // TODO: implement me
    return -1;
}

/*
 * Measures the given item's width
 */

wxCoord choiceTaskList::OnMeasureItemWidth(size_t WXUNUSED(item)) const
{
    // TODO: implement me
    return -1;
}


/*
 * ChoiceTaskList type definition
 */

IMPLEMENT_DYNAMIC_CLASS( ChoiceTaskList, wxOwnerDrawnComboBox )


/*
 * ChoiceTaskList event table definition
 */

BEGIN_EVENT_TABLE( ChoiceTaskList, wxOwnerDrawnComboBox )

////@begin ChoiceTaskList event table entries
    EVT_COMBOBOX( ID_OWNERDRAWNCOMBOCTRL, ChoiceTaskList::OnOwnerdrawncomboctrlSelected )

////@end ChoiceTaskList event table entries

END_EVENT_TABLE()


/*
 * ChoiceTaskList constructors
 */

ChoiceTaskList::ChoiceTaskList()
{
    Init();
}

ChoiceTaskList::ChoiceTaskList(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxString& value, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator)
{
    Init();
    Create(parent, id, value, pos, size, choices, style, validator);
}


/*
 * ChoiceTaskList creator
 */

bool ChoiceTaskList::Create(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxString& value, const wxSize& size, const wxArrayString& choices, long style, const wxValidator& validator)
{
////@begin ChoiceTaskList creation
    wxOwnerDrawnComboBox::Create(parent, id, value, pos, size, choices, style, validator);
    CreateControls();
////@end ChoiceTaskList creation
    return true;
}


/*
 * ChoiceTaskList destructor
 */

ChoiceTaskList::~ChoiceTaskList()
{
////@begin ChoiceTaskList destruction
////@end ChoiceTaskList destruction
}


/*
 * Member initialisation
 */

void ChoiceTaskList::Init()
{
////@begin ChoiceTaskList member initialisation
////@end ChoiceTaskList member initialisation
}


/*
 * Control creation for ChoiceTaskList
 */

void ChoiceTaskList::CreateControls()
{    
////@begin ChoiceTaskList content construction
////@end ChoiceTaskList content construction
}


/*
 * Draws the given item
 */

void ChoiceTaskList::OnDrawItem(wxDC& dc, const wxRect& rect, int item, int flags) const
{
    // TODO: implement me
    wxOwnerDrawnComboBox::OnDrawItem(dc, rect, item, flags);
}

/*
 * Draws the given item
 */

void ChoiceTaskList::OnDrawBackground(wxDC& dc, const wxRect& rect, int item, int flags) const
{
    // TODO: implement me
    wxOwnerDrawnComboBox::OnDrawBackground(dc, rect, item, flags);
}

/*
 * Measures the given item's height
 */

wxCoord ChoiceTaskList::OnMeasureItem(size_t WXUNUSED(item)) const
{
    // TODO: implement me
    return -1;
}

/*
 * Measures the given item's width
 */

wxCoord ChoiceTaskList::OnMeasureItemWidth(size_t WXUNUSED(item)) const
{
    // TODO: implement me
    return -1;
}


/*
 * wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_OWNERDRAWNCOMBOCTRL
 */

void ChoiceTaskList::OnOwnerdrawncomboctrlSelected( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_OWNERDRAWNCOMBOCTRL in ChoiceTaskList.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_COMBOBOX_SELECTED event handler for ID_OWNERDRAWNCOMBOCTRL in ChoiceTaskList. 
}

