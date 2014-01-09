/////////////////////////////////////////////////////////////////////////////
// Name:        ISBOTCAPMain.h
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     19/12/2013 15:35:19
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////

#ifndef _ISBOTCAPMAIN_H_
#define _ISBOTCAPMAIN_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/frame.h"
#include "wx/notebook.h"
#include "wx/spinctrl.h"
#include "wx/listctrl.h"
#include "wx/statusbr.h"
#include "wx/toolbar.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxNotebook;
class wxListCtrl;
class wxStatusBar;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_ISHCAPMAIN 10000
#define ID_NOTEBOOK 10002
#define ID_PANEL_GENERAL 10003
#define ID_SPINCTRL_PKTNUM 10100
#define ID_BTN_ROISTART 10033
#define ID_BTN_ROIEND 10034
#define ID_LISTCTRL_ARTICLES 10028
#define ID_BTN_ARTICLELOAD 10087
#define ID_BTN_ARTICLEVIEW 10073
#define ID_BTN_ARTICLENEW 10029
#define ID_BTN_ARTICLEDEL 10030
#define ID_PANEL_RESULT 10004
#define ID_TEXTCTRL1 10045
#define ID_BTN_FALG1 10036
#define ID_BTN_FALG2 10037
#define ID_BTN_FALG3 10038
#define ID_BTN_FALG4 10039
#define ID_TEXTCTRL2 10040
#define ID_TEXTCTRL3 10041
#define ID_TEXTCTRL4 10042
#define ID_TEXTCTRL5 10043
#define ID_TEXTCTRL6 10044
#define ID_BTN_CLEAR 10035
#define ID_NOTEBOOK1 10015
#define ID_PANEL7 10019
#define ID_NOTEBOOK2 10016
#define ID_PANEL8 10020
#define ID_NOTEBOOK3 10017
#define ID_PANEL9 10021
#define ID_NOTEBOOK4 10070
#define ID_PANEL24 10071
#define ID_PANEL11 10023
#define ID_BTN_INSPSTART 10009
#define ID_STATUSBAR 10027
#define ID_TOOLBAR 10086
#define ID_TOOL_SHUT 10095
#define ID_TOOL_QUIT 10096
#define ID_TOOL_DISP 10124
#define ID_TOOL_SAVEIMGS 10125
#define ID_TOOL_CAM1 10097
#define ID_TOOL_CAM2 10120
#define ID_TOOL_CAM3 10121
#define ID_TOOL_CAM4 10122
#define ID_TOOL_SAVEIMG 10126
#define ID_TOOL_CAMSET 10127
#define ID_TOOL_PARAMSET 10024
#define SYMBOL_ISBOTCAPMAIN_STYLE wxNO_BORDER
#define SYMBOL_ISBOTCAPMAIN_TITLE _("ISHCAPMain")
#define SYMBOL_ISBOTCAPMAIN_IDNAME ID_ISHCAPMAIN
#define SYMBOL_ISBOTCAPMAIN_SIZE wxSize(1024, 768)
#define SYMBOL_ISBOTCAPMAIN_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * ISBOTCAPMain class declaration
 */
class gvVisionManager;
class gvVisionCCD;
class ISBOTCAPMain: public wxFrame
{
    DECLARE_CLASS( ISBOTCAPMain )
    DECLARE_EVENT_TABLE()
private:
    gvVisionManager     *c_pgvVisionManager;

	wxString	m_strArticleName_selected;
protected:
	void ArticlesList_Init();
	void ArticlesList_update();
	void open_hWindow();
public:
    /// Constructors
    ISBOTCAPMain();
    ISBOTCAPMain( wxWindow* parent, wxWindowID id = SYMBOL_ISBOTCAPMAIN_IDNAME, const wxString& caption = SYMBOL_ISBOTCAPMAIN_TITLE, const wxPoint& pos = SYMBOL_ISBOTCAPMAIN_POSITION, const wxSize& size = SYMBOL_ISBOTCAPMAIN_SIZE, long style = SYMBOL_ISBOTCAPMAIN_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_ISBOTCAPMAIN_IDNAME, const wxString& caption = SYMBOL_ISBOTCAPMAIN_TITLE, const wxPoint& pos = SYMBOL_ISBOTCAPMAIN_POSITION, const wxSize& size = SYMBOL_ISBOTCAPMAIN_SIZE, long style = SYMBOL_ISBOTCAPMAIN_STYLE );

    /// Destructor
    ~ISBOTCAPMain();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin ISBOTCAPMain event handler declarations

    /// wxEVT_IDLE event handler for ID_ISHCAPMAIN
    void OnIdle( wxIdleEvent& event );

    /// wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL_PKTNUM
    void OnSpinctrlPktnumUpdated( wxSpinEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_SPINCTRL_PKTNUM
    void OnSpinctrlPktnumUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ROISTART
    void OnBtnRoistartClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_ROISTART
    void OnBtnRoistartUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ROIEND
    void OnBtnRoiendClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_ROIEND
    void OnBtnRoiendUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LISTCTRL_ARTICLES
    void OnListctrlArticlesSelected( wxListEvent& event );

    /// wxEVT_COMMAND_LIST_ITEM_DESELECTED event handler for ID_LISTCTRL_ARTICLES
    void OnListctrlArticlesDeselected( wxListEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLELOAD
    void OnBtnArticleloadClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLELOAD
    void OnBtnArticleloadUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLEVIEW
    void OnBtnArticleviewClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLEVIEW
    void OnBtnArticleviewUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLENEW
    void OnBtnArticlenewClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLENEW
    void OnBtnArticlenewUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLEDEL
    void OnBtnArticledelClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLEDEL
    void OnBtnArticledelUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_CLEAR
    void OnBtnClearClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_CLEAR
    void OnBtnClearUpdate( wxUpdateUIEvent& event );

    /// wxEVT_LEFT_DOWN event handler for ID_PANEL7
    void OnLeftDown( wxMouseEvent& event );

    /// wxEVT_LEFT_UP event handler for ID_PANEL7
    void OnLeftUp( wxMouseEvent& event );

    /// wxEVT_MOTION event handler for ID_PANEL7
    void OnMotion( wxMouseEvent& event );

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_INSPSTART
    void OnBtnInspstartClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_BTN_INSPSTART
    void OnBtnInspstartUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SHUT
    void OnToolShutClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_SHUT
    void OnToolShutUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_QUIT
    void OnToolQuitClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_QUIT
    void OnToolQuitUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_DISP
    void OnToolDispClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_DISP
    void OnToolDispUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SAVEIMGS
    void OnToolSaveimgsClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_SAVEIMGS
    void OnToolSaveimgsUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAM1
    void OnToolCam1Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_CAM1
    void OnToolCam1Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAM2
    void OnToolCam2Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_CAM2
    void OnToolCam2Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAM3
    void OnToolCam3Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_CAM3
    void OnToolCam3Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAM4
    void OnToolCam4Click( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_CAM4
    void OnToolCam4Update( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SAVEIMG
    void OnToolSaveimgClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_SAVEIMG
    void OnToolSaveimgUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAMSET
    void OnToolCamsetClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_CAMSET
    void OnToolCamsetUpdate( wxUpdateUIEvent& event );

    /// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_PARAMSET
    void OnToolParamsetClick( wxCommandEvent& event );

    /// wxEVT_UPDATE_UI event handler for ID_TOOL_PARAMSET
    void OnToolParamsetUpdate( wxUpdateUIEvent& event );

////@end ISBOTCAPMain event handler declarations

////@begin ISBOTCAPMain member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end ISBOTCAPMain member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin ISBOTCAPMain member variables
    wxStaticBitmap* m_logoViewer;
    wxNotebook* m_noteBook_L;
    wxListCtrl* m_lstArticles;
    wxTextCtrl* m_sizeViewer;
    wxButton* m_btnFlag1;
    wxButton* m_btnFlag2;
    wxButton* m_btnFlag3;
    wxButton* m_btnFlag4;
    wxTextCtrl* m_ctlPassCnt;
    wxTextCtrl* m_ctlPassYield;
    wxTextCtrl* m_ctlTotalCnt;
    wxTextCtrl* m_ctlFailedCnt;
    wxTextCtrl* m_ctlMachineSpeed;
    wxPanel* panelCCD1;
    wxPanel* panelCCD2;
    wxPanel* panelCCD3;
    wxPanel* panelCCD4;
    wxButton* m_btnStart;
    wxStatusBar* m_wxStatusBar;
////@end ISBOTCAPMain member variables

    int m_selectCCD;
    bool m_isROIMoving;
};

#endif
    // _ISBOTCAPMAIN_H_
