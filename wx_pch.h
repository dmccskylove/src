/***************************************************************
 * Name:      wx_pch.h
 * Purpose:   Header to create Pre-Compiled Header (PCH)
 * Author:    史明忠 (shimingzhong518@163.com)
 * Created:   2013-12-19
 * Copyright: 史明忠 (www.machine-vision.com.cn)
 * License:
 **************************************************************/

#ifndef WX_PCH_H_INCLUDED
#define WX_PCH_H_INCLUDED

// basic wxWidgets headers
#include <wx/wxprec.h>

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef WX_PRECOMP
// put here all your rarely-changing header files
    #include <vector>
    #include "core/ISHCAPDef.h"
    #include <HalconCpp.h>
#endif // WX_PRECOMP

using namespace Halcon;

#endif // WX_PCH_H_INCLUDED
