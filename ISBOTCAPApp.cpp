/////////////////////////////////////////////////////////////////////////////
// Name:        ISBOTCAPApp.cpp
// Purpose:     
// Author:      史明忠
// Modified by: 
// Created:     19/12/2013 14:12:51
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

#include "ISBOTCAPApp.h"

////@begin XPM images

////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( ISBOTCAPApp )
////@end implement app


/*
 * ISBOTCAPApp type definition
 */

IMPLEMENT_CLASS( ISBOTCAPApp, wxApp )


/*
 * ISBOTCAPApp event table definition
 */

BEGIN_EVENT_TABLE( ISBOTCAPApp, wxApp )

////@begin ISBOTCAPApp event table entries
////@end ISBOTCAPApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for ISBOTCAPApp
 */

ISBOTCAPApp::ISBOTCAPApp()
{
    Init();
}


/*
 * Member initialisation
 */

void ISBOTCAPApp::Init()
{
////@begin ISBOTCAPApp member initialisation
////@end ISBOTCAPApp member initialisation
}

/*
 * Initialisation for ISBOTCAPApp
 */

bool ISBOTCAPApp::OnInit()
{    
////@begin ISBOTCAPApp initialisation
    // Remove the comment markers above and below this block
    // to make permanent changes to the code.

#if wxUSE_XPM
    wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
    wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
    wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
    wxImage::AddHandler(new wxGIFHandler);
#endif
    ISBOTCAPMain* mainWindow = new ISBOTCAPMain( NULL );
    mainWindow->Show(true);
////@end ISBOTCAPApp initialisation

    return true;
}


/*
 * Cleanup for ISBOTCAPApp
 */

int ISBOTCAPApp::OnExit()
{    
////@begin ISBOTCAPApp cleanup
    return wxApp::OnExit();
////@end ISBOTCAPApp cleanup
}

