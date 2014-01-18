/////////////////////////////////////////////////////////////////////////////
// Name:        ISBOTCAPApp.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     19/12/2013 14:12:51
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _ISBOTCAPAPP_H_
#define _ISBOTCAPAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "ISBOTCAPMain.h"
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
////@end control identifiers

/*!
 * ISBOTCAPApp class declaration
 */

class ISBOTCAPApp: public wxApp
{
    DECLARE_CLASS( ISBOTCAPApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    ISBOTCAPApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin ISBOTCAPApp event handler declarations
////@end ISBOTCAPApp event handler declarations

////@begin ISBOTCAPApp member function declarations
////@end ISBOTCAPApp member function declarations

////@begin ISBOTCAPApp member variables
////@end ISBOTCAPApp member variables
};

/*!
 * Application instance declaration
 */

////@begin declare app
DECLARE_APP(ISBOTCAPApp)
////@end declare app

#endif
// _ISBOTCAPAPP_H_
