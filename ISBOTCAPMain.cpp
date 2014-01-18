/////////////////////////////////////////////////////////////////////////////
// Name:        ISBOTCAPMain.cpp
// Purpose:
// Author:      史明忠
// Modified by:
// Created:     19/12/2013 15:35:18
// RCS-ID:
// Copyright:   (C)2013 上海视谷图像技术有限公司
// Licence:
/////////////////////////////////////////////////////////////////////////////
#include "wx_pch.h"

////@begin includes
#include "wx/imaglist.h"
#include "dlgarticlenew.h"
////@end includes

#include "ISBOTCAPMain.h"
#include "dlgArticleNew.h"
#include "dlgArticleEdit.h"
#include "dlgSettingsCam.h"
#include "dlgShutdown.h"

#include "core/gvVisionManager.h"
#include "core/gvVisionCCD.h"
#include "core/gvVisionImage.h"
#include "core/gvVisionCam.h"

#include "gvVisionImage_botcap.h"
////@begin XPM images
#include "xpm/ISHCAP.xpm"
#include "xpm/gvtec-232-60.xpm"
#include "xpm/shutdown64.xpm"
#include "xpm/quit64.xpm"
#include "xpm/camDisplay.xpm"
#include "xpm/camSave.xpm"
#include "xpm/cam1.xpm"
#include "xpm/cam2.xpm"
#include "xpm/cam3.xpm"
#include "xpm/cam4.xpm"
#include "xpm/imgSave.xpm"
#include "xpm/camSettings.xpm"
#include "xpm/paraSettings.xpm"
////@end XPM images


/*
 * ISBOTCAPMain type definition
 */

IMPLEMENT_CLASS( ISBOTCAPMain, wxFrame )


/*
 * ISBOTCAPMain event table definition
 */

BEGIN_EVENT_TABLE( ISBOTCAPMain, wxFrame )

////@begin ISBOTCAPMain event table entries
    EVT_IDLE( ISBOTCAPMain::OnIdle )

    EVT_SPINCTRL( ID_SPINCTRL_PKTNUM, ISBOTCAPMain::OnSpinctrlPktnumUpdated )
    EVT_UPDATE_UI( ID_SPINCTRL_PKTNUM, ISBOTCAPMain::OnSpinctrlPktnumUpdate )

    EVT_BUTTON( ID_BTN_ROISTART, ISBOTCAPMain::OnBtnRoistartClick )
    EVT_UPDATE_UI( ID_BTN_ROISTART, ISBOTCAPMain::OnBtnRoistartUpdate )

    EVT_BUTTON( ID_BTN_ROIEND, ISBOTCAPMain::OnBtnRoiendClick )
    EVT_UPDATE_UI( ID_BTN_ROIEND, ISBOTCAPMain::OnBtnRoiendUpdate )

    EVT_LIST_ITEM_SELECTED( ID_LISTCTRL_ARTICLES, ISBOTCAPMain::OnListctrlArticlesSelected )
    EVT_LIST_ITEM_DESELECTED( ID_LISTCTRL_ARTICLES, ISBOTCAPMain::OnListctrlArticlesDeselected )

    EVT_BUTTON( ID_BTN_ARTICLELOAD, ISBOTCAPMain::OnBtnArticleloadClick )
    EVT_UPDATE_UI( ID_BTN_ARTICLELOAD, ISBOTCAPMain::OnBtnArticleloadUpdate )

    EVT_BUTTON( ID_BTN_ARTICLEVIEW, ISBOTCAPMain::OnBtnArticleviewClick )
    EVT_UPDATE_UI( ID_BTN_ARTICLEVIEW, ISBOTCAPMain::OnBtnArticleviewUpdate )

    EVT_BUTTON( ID_BTN_ARTICLENEW, ISBOTCAPMain::OnBtnArticlenewClick )
    EVT_UPDATE_UI( ID_BTN_ARTICLENEW, ISBOTCAPMain::OnBtnArticlenewUpdate )

    EVT_BUTTON( ID_BTN_ARTICLEDEL, ISBOTCAPMain::OnBtnArticledelClick )
    EVT_UPDATE_UI( ID_BTN_ARTICLEDEL, ISBOTCAPMain::OnBtnArticledelUpdate )

    EVT_BUTTON( ID_BTN_CLEAR, ISBOTCAPMain::OnBtnClearClick )
    EVT_UPDATE_UI( ID_BTN_CLEAR, ISBOTCAPMain::OnBtnClearUpdate )

    EVT_BUTTON( ID_BTN_INSPSTART, ISBOTCAPMain::OnBtnInspstartClick )
    EVT_UPDATE_UI( ID_BTN_INSPSTART, ISBOTCAPMain::OnBtnInspstartUpdate )

    EVT_MENU( ID_TOOL_SHUT, ISBOTCAPMain::OnToolShutClick )
    EVT_UPDATE_UI( ID_TOOL_SHUT, ISBOTCAPMain::OnToolShutUpdate )

    EVT_MENU( ID_TOOL_QUIT, ISBOTCAPMain::OnToolQuitClick )
    EVT_UPDATE_UI( ID_TOOL_QUIT, ISBOTCAPMain::OnToolQuitUpdate )

    EVT_MENU( ID_TOOL_DISP, ISBOTCAPMain::OnToolDispClick )
    EVT_UPDATE_UI( ID_TOOL_DISP, ISBOTCAPMain::OnToolDispUpdate )

    EVT_MENU( ID_TOOL_SAVEIMGS, ISBOTCAPMain::OnToolSaveimgsClick )
    EVT_UPDATE_UI( ID_TOOL_SAVEIMGS, ISBOTCAPMain::OnToolSaveimgsUpdate )

    EVT_MENU( ID_TOOL_CAM1, ISBOTCAPMain::OnToolCam1Click )
    EVT_UPDATE_UI( ID_TOOL_CAM1, ISBOTCAPMain::OnToolCam1Update )

    EVT_MENU( ID_TOOL_CAM2, ISBOTCAPMain::OnToolCam2Click )
    EVT_UPDATE_UI( ID_TOOL_CAM2, ISBOTCAPMain::OnToolCam2Update )

    EVT_MENU( ID_TOOL_CAM3, ISBOTCAPMain::OnToolCam3Click )
    EVT_UPDATE_UI( ID_TOOL_CAM3, ISBOTCAPMain::OnToolCam3Update )

    EVT_MENU( ID_TOOL_CAM4, ISBOTCAPMain::OnToolCam4Click )
    EVT_UPDATE_UI( ID_TOOL_CAM4, ISBOTCAPMain::OnToolCam4Update )

    EVT_MENU( ID_TOOL_SAVEIMG, ISBOTCAPMain::OnToolSaveimgClick )
    EVT_UPDATE_UI( ID_TOOL_SAVEIMG, ISBOTCAPMain::OnToolSaveimgUpdate )

    EVT_MENU( ID_TOOL_CAMSET, ISBOTCAPMain::OnToolCamsetClick )
    EVT_UPDATE_UI( ID_TOOL_CAMSET, ISBOTCAPMain::OnToolCamsetUpdate )

    EVT_MENU( ID_TOOL_PARAMSET, ISBOTCAPMain::OnToolParamsetClick )
    EVT_UPDATE_UI( ID_TOOL_PARAMSET, ISBOTCAPMain::OnToolParamsetUpdate )

////@end ISBOTCAPMain event table entries

END_EVENT_TABLE()


/*
 * ISBOTCAPMain constructors
 */

ISBOTCAPMain::ISBOTCAPMain()
{
    Init();
}

ISBOTCAPMain::ISBOTCAPMain( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create( parent, id, caption, pos, size, style );
}


/*
 * ISBOTCAPMain creator
 */

bool ISBOTCAPMain::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin ISBOTCAPMain creation
    wxFrame::Create( parent, id, caption, pos, size, style );

    CreateControls();
    SetIcon(GetIconResource(wxT("xpm/ISHCAP.xpm")));
    Centre();
////@end ISBOTCAPMain creation

    m_logoViewer->SetBackgroundColour( GetSysColor(COLOR_BTNFACE));
	ArticlesList_Init();
	ArticlesList_update();
	open_hWindow();

    return true;
}


/*
 * ISBOTCAPMain destructor
 */

ISBOTCAPMain::~ISBOTCAPMain()
{
////@begin ISBOTCAPMain destruction
////@end ISBOTCAPMain destruction
}


/*
 * Member initialisation
 */

void ISBOTCAPMain::Init()
{
////@begin ISBOTCAPMain member initialisation
    m_logoViewer = NULL;
    m_noteBook_L = NULL;
    m_lstArticles = NULL;
    m_sizeViewer = NULL;
    m_btnFlag1 = NULL;
    m_btnFlag2 = NULL;
    m_btnFlag3 = NULL;
    m_btnFlag4 = NULL;
    m_ctlPassCnt = NULL;
    m_ctlPassYield = NULL;
    m_ctlTotalCnt = NULL;
    m_ctlFailedCnt = NULL;
    m_ctlMachineSpeed = NULL;
    panelCCD1 = NULL;
    panelCCD2 = NULL;
    panelCCD3 = NULL;
    panelCCD4 = NULL;
    m_btnStart = NULL;
    m_wxStatusBar = NULL;
////@end ISBOTCAPMain member initialisation

    m_selectCCD=0;

/**< 创建数据接口，并读取厂家配置文件 */
    c_pgvVisionManager = new gvVisionManager();
    if( !c_pgvVisionManager->gvMgr_Init() )
    {
        exit(0);
    }//if( !c_pgvVisionManager->gvMgr_Init() )

/**< 创建相关文件夹 */
    wxMkDir( wxGetCwd() + wxT("\\articles\\") );
    wxMkDir( wxGetCwd() + wxT("\\articles\\Model") );
    wxMkDir( wxGetCwd() + wxT("\\images\\") );
}


/*
 * Control creation for ISBOTCAPMain
 */

void ISBOTCAPMain::CreateControls()
{
////@begin ISBOTCAPMain content construction
    ISBOTCAPMain* itemFrame1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    itemFrame1->SetSizer(itemBoxSizer2);

    wxBoxSizer* itemBoxSizer3 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer3, 0, wxGROW|wxALL, 0);

    m_logoViewer = new wxStaticBitmap( itemFrame1, wxID_STATIC, itemFrame1->GetBitmapResource(wxT("xpm/gvtec-232-60.xpm")), wxDefaultPosition, wxSize(-1, 100), 0 );
    itemBoxSizer3->Add(m_logoViewer, 0, wxGROW|wxALL, 0);

    m_noteBook_L = new wxNotebook( itemFrame1, ID_NOTEBOOK, wxDefaultPosition, wxSize(254, 658), wxBK_DEFAULT );
    m_noteBook_L->SetFont(wxFont(9, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("微软雅黑")));

    wxPanel* itemPanel6 = new wxPanel( m_noteBook_L, ID_PANEL_GENERAL, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    itemPanel6->SetFont(wxFont(11, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("微软雅黑")));
    wxBoxSizer* itemBoxSizer7 = new wxBoxSizer(wxVERTICAL);
    itemPanel6->SetSizer(itemBoxSizer7);

    wxStaticBox* itemStaticBoxSizer8Static = new wxStaticBox(itemPanel6, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x5355 + (wxChar) 0x5305 + (wxChar) 0x603B + (wxChar) 0x6570 + wxT("(") + (wxChar) 0x5355 + (wxChar) 0x4F4D + wxT(": ") + (wxChar) 0x5343 + (wxChar) 0x9897 + wxT(")")));
    wxStaticBoxSizer* itemStaticBoxSizer8 = new wxStaticBoxSizer(itemStaticBoxSizer8Static, wxHORIZONTAL);
    itemBoxSizer7->Add(itemStaticBoxSizer8, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 2);
    wxSpinCtrl* itemSpinCtrl9 = new wxSpinCtrl( itemStaticBoxSizer8->GetStaticBox(), ID_SPINCTRL_PKTNUM, _T("50"), wxDefaultPosition, wxSize(230, -1), wxSP_ARROW_KEYS, 1, 1000, 50 );
    itemStaticBoxSizer8->Add(itemSpinCtrl9, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxStaticBox* itemStaticBoxSizer10Static = new wxStaticBox(itemPanel6, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x68C0 + (wxChar) 0x6D4B + (wxChar) 0x6846));
    wxStaticBoxSizer* itemStaticBoxSizer10 = new wxStaticBoxSizer(itemStaticBoxSizer10Static, wxHORIZONTAL);
    itemBoxSizer7->Add(itemStaticBoxSizer10, 0, wxGROW|wxLEFT|wxRIGHT, 2);
    wxButton* itemButton11 = new wxButton( itemStaticBoxSizer10->GetStaticBox(), ID_BTN_ROISTART, wxGetTranslation(wxString() + (wxChar) 0x5F00 + (wxChar) 0x59CB + (wxChar) 0x79FB + (wxChar) 0x52A8), wxDefaultPosition, wxSize(116, 36), 0 );
    itemStaticBoxSizer10->Add(itemButton11, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* itemButton12 = new wxButton( itemStaticBoxSizer10->GetStaticBox(), ID_BTN_ROIEND, wxGetTranslation(wxString() + (wxChar) 0x505C + (wxChar) 0x6B62 + (wxChar) 0x79FB + (wxChar) 0x52A8), wxDefaultPosition, wxSize(116, 36), 0 );
    itemStaticBoxSizer10->Add(itemButton12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    m_lstArticles = new wxListCtrl( itemPanel6, ID_LISTCTRL_ARTICLES, wxDefaultPosition, wxSize(100, 328), wxLC_REPORT );
    itemBoxSizer7->Add(m_lstArticles, 0, wxGROW|wxALL, 2);

    wxBoxSizer* itemBoxSizer14 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer7->Add(itemBoxSizer14, 0, wxGROW|wxALL, 0);
    wxButton* itemButton15 = new wxButton( itemPanel6, ID_BTN_ARTICLELOAD, wxGetTranslation(wxString() + (wxChar) 0x8F7D + (wxChar) 0x5165 + (wxChar) 0x4EA7 + (wxChar) 0x54C1), wxDefaultPosition, wxSize(240, 36), 0 );
    itemBoxSizer14->Add(itemButton15, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxBoxSizer* itemBoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer7->Add(itemBoxSizer16, 0, wxALIGN_CENTER_HORIZONTAL|wxLEFT|wxRIGHT, 0);
    wxButton* itemButton17 = new wxButton( itemPanel6, ID_BTN_ARTICLEVIEW, wxGetTranslation(wxString() + (wxChar) 0x67E5 + (wxChar) 0x770B), wxDefaultPosition, wxSize(80, 36), 0 );
    itemBoxSizer16->Add(itemButton17, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* itemButton18 = new wxButton( itemPanel6, ID_BTN_ARTICLENEW, wxGetTranslation(wxString() + (wxChar) 0x65B0 + (wxChar) 0x5EFA), wxDefaultPosition, wxSize(80, 36), 0 );
    itemBoxSizer16->Add(itemButton18, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxButton* itemButton19 = new wxButton( itemPanel6, ID_BTN_ARTICLEDEL, wxGetTranslation(wxString() + (wxChar) 0x5220 + (wxChar) 0x9664), wxDefaultPosition, wxSize(80, 36), 0 );
    itemBoxSizer16->Add(itemButton19, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    m_noteBook_L->AddPage(itemPanel6, wxGetTranslation(wxString() + (wxChar) 0x4E00 + (wxChar) 0x822C));

    wxPanel* itemPanel20 = new wxPanel( m_noteBook_L, ID_PANEL_RESULT, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    itemPanel20->SetFont(wxFont(11, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("微软雅黑")));
    wxBoxSizer* itemBoxSizer21 = new wxBoxSizer(wxVERTICAL);
    itemPanel20->SetSizer(itemBoxSizer21);

    m_sizeViewer = new wxTextCtrl( itemPanel20, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxNO_BORDER );
    m_sizeViewer->SetFont(wxFont(36, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("微软雅黑")));
    m_sizeViewer->Enable(false);
    itemBoxSizer21->Add(m_sizeViewer, 0, wxGROW|wxRIGHT|wxTOP|wxBOTTOM, 2);

    wxStaticBox* itemStaticBoxSizer23Static = new wxStaticBox(itemPanel20, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x5B9E + (wxChar) 0x65F6 + (wxChar) 0x7ED3 + (wxChar) 0x679C));
    wxStaticBoxSizer* itemStaticBoxSizer23 = new wxStaticBoxSizer(itemStaticBoxSizer23Static, wxVERTICAL);
    itemBoxSizer21->Add(itemStaticBoxSizer23, 0, wxGROW|wxALL, 2);
    wxBoxSizer* itemBoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer23->Add(itemBoxSizer24, 0, wxGROW|wxALL, 0);
    m_btnFlag1 = new wxButton( itemStaticBoxSizer23->GetStaticBox(), ID_BTN_FALG1, _("1"), wxDefaultPosition, wxSize(58, 50), 0 );
    m_btnFlag1->Enable(false);
    itemBoxSizer24->Add(m_btnFlag1, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    m_btnFlag2 = new wxButton( itemStaticBoxSizer23->GetStaticBox(), ID_BTN_FALG2, _("2"), wxDefaultPosition, wxSize(58, -1), 0 );
    m_btnFlag2->Enable(false);
    itemBoxSizer24->Add(m_btnFlag2, 0, wxGROW|wxALL, 0);

    m_btnFlag3 = new wxButton( itemStaticBoxSizer23->GetStaticBox(), ID_BTN_FALG3, _("3"), wxDefaultPosition, wxSize(58, -1), 0 );
    m_btnFlag3->Enable(false);
    itemBoxSizer24->Add(m_btnFlag3, 0, wxGROW|wxALL, 0);

    m_btnFlag4 = new wxButton( itemStaticBoxSizer23->GetStaticBox(), ID_BTN_FALG4, _("4"), wxDefaultPosition, wxSize(58, -1), 0 );
    m_btnFlag4->Enable(false);
    itemBoxSizer24->Add(m_btnFlag4, 0, wxGROW|wxALL, 0);

    wxStaticBox* itemStaticBoxSizer29Static = new wxStaticBox(itemPanel20, wxID_ANY, wxGetTranslation(wxString() + (wxChar) 0x7EDF + (wxChar) 0x8BA1));
    wxStaticBoxSizer* itemStaticBoxSizer29 = new wxStaticBoxSizer(itemStaticBoxSizer29Static, wxVERTICAL);
    itemBoxSizer21->Add(itemStaticBoxSizer29, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 2);
    wxFlexGridSizer* itemFlexGridSizer30 = new wxFlexGridSizer(0, 2, 0, 0);
    itemStaticBoxSizer29->Add(itemFlexGridSizer30, 0, wxGROW|wxALL, 0);
    wxStaticText* itemStaticText31 = new wxStaticText( itemStaticBoxSizer29->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x5408 + (wxChar) 0x683C + (wxChar) 0x6570 + wxT(":")), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
    itemFlexGridSizer30->Add(itemStaticText31, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ctlPassCnt = new wxTextCtrl( itemStaticBoxSizer29->GetStaticBox(), ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(150, -1), wxTE_READONLY|wxTE_CENTRE );
    m_ctlPassCnt->SetBackgroundColour(wxColour(0, 255, 0));
    m_ctlPassCnt->Enable(false);
    itemFlexGridSizer30->Add(m_ctlPassCnt, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxStaticText* itemStaticText33 = new wxStaticText( itemStaticBoxSizer29->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x5408 + (wxChar) 0x683C + (wxChar) 0x7387 + wxT(":")), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
    itemFlexGridSizer30->Add(itemStaticText33, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ctlPassYield = new wxTextCtrl( itemStaticBoxSizer29->GetStaticBox(), ID_TEXTCTRL3, _("0.00%"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_CENTRE );
    m_ctlPassYield->SetBackgroundColour(wxColour(0, 255, 0));
    m_ctlPassYield->Enable(false);
    itemFlexGridSizer30->Add(m_ctlPassYield, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxStaticText* itemStaticText35 = new wxStaticText( itemStaticBoxSizer29->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x603B + (wxChar) 0x6570 + wxT(" :")), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
    itemFlexGridSizer30->Add(itemStaticText35, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ctlTotalCnt = new wxTextCtrl( itemStaticBoxSizer29->GetStaticBox(), ID_TEXTCTRL4, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_CENTRE );
    m_ctlTotalCnt->SetBackgroundColour(wxColour(255, 255, 0));
    m_ctlTotalCnt->Enable(false);
    itemFlexGridSizer30->Add(m_ctlTotalCnt, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxStaticText* itemStaticText37 = new wxStaticText( itemStaticBoxSizer29->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x4E0D + (wxChar) 0x5408 + (wxChar) 0x683C + (wxChar) 0x6570 + wxT(" :")), wxDefaultPosition, wxSize(70, -1), wxALIGN_RIGHT );
    itemFlexGridSizer30->Add(itemStaticText37, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5);

    m_ctlFailedCnt = new wxTextCtrl( itemStaticBoxSizer29->GetStaticBox(), ID_TEXTCTRL5, _("0"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_CENTRE );
    m_ctlFailedCnt->SetBackgroundColour(wxColour(255, 0, 0));
    m_ctlFailedCnt->Enable(false);
    itemFlexGridSizer30->Add(m_ctlFailedCnt, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 2);

    wxBoxSizer* itemBoxSizer39 = new wxBoxSizer(wxHORIZONTAL);
    itemStaticBoxSizer29->Add(itemBoxSizer39, 0, wxGROW|wxALL, 0);
    wxStaticText* itemStaticText40 = new wxStaticText( itemStaticBoxSizer29->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x901F + (wxChar) 0x5EA6 + wxT(":")), wxDefaultPosition, wxSize(70, -1), wxALIGN_RIGHT );
    itemBoxSizer39->Add(itemStaticText40, 0, wxALIGN_CENTER_VERTICAL|wxLEFT|wxTOP|wxBOTTOM, 5);

    m_ctlMachineSpeed = new wxTextCtrl( itemStaticBoxSizer29->GetStaticBox(), ID_TEXTCTRL6, _("0.00"), wxDefaultPosition, wxSize(60, -1), wxTE_CENTRE );
    m_ctlMachineSpeed->Enable(false);
    itemBoxSizer39->Add(m_ctlMachineSpeed, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5);

    wxStaticText* itemStaticText42 = new wxStaticText( itemStaticBoxSizer29->GetStaticBox(), wxID_STATIC, wxGetTranslation(wxString() + (wxChar) 0x4E07 + (wxChar) 0x9897 + wxT("/") + (wxChar) 0x5C0F + (wxChar) 0x65F6), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer39->Add(itemStaticText42, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5);

    wxButton* itemButton43 = new wxButton( itemPanel20, ID_BTN_CLEAR, wxGetTranslation(wxString() + (wxChar) 0x6E05 + (wxChar) 0x9664 + (wxChar) 0x7EDF + (wxChar) 0x8BA1 + (wxChar) 0x7ED3 + (wxChar) 0x679C), wxDefaultPosition, wxSize(-1, 36), 0 );
    itemBoxSizer21->Add(itemButton43, 0, wxGROW|wxLEFT|wxRIGHT|wxBOTTOM, 5);

    m_noteBook_L->AddPage(itemPanel20, wxGetTranslation(wxString() + (wxChar) 0x7ED3 + (wxChar) 0x679C));

    itemBoxSizer3->Add(m_noteBook_L, 0, wxGROW|wxALL, 0);

    wxBoxSizer* itemBoxSizer44 = new wxBoxSizer(wxVERTICAL);
    itemBoxSizer2->Add(itemBoxSizer44, 0, wxGROW|wxALL, 0);

    wxBoxSizer* itemBoxSizer45 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer44->Add(itemBoxSizer45, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 0);

    wxNotebook* itemNotebook46 = new wxNotebook( itemFrame1, ID_NOTEBOOK1, wxDefaultPosition, wxSize(385, 290), wxBK_DEFAULT|wxNB_FLAT );

    panelCCD1 = new wxPanel( itemNotebook46, ID_PANEL7, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    panelCCD1->SetBackgroundColour(wxColour(0, 0, 0));

    itemNotebook46->AddPage(panelCCD1, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT(" 1")));

    itemBoxSizer45->Add(itemNotebook46, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0);

    wxNotebook* itemNotebook48 = new wxNotebook( itemFrame1, ID_NOTEBOOK2, wxDefaultPosition, wxSize(385, -1), wxBK_DEFAULT );

    panelCCD2 = new wxPanel( itemNotebook48, ID_PANEL8, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    panelCCD2->SetBackgroundColour(wxColour(0, 0, 0));

    itemNotebook48->AddPage(panelCCD2, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT(" 2")));

    itemBoxSizer45->Add(itemNotebook48, 0, wxGROW|wxALL, 0);

    wxBoxSizer* itemBoxSizer50 = new wxBoxSizer(wxHORIZONTAL);
    itemBoxSizer44->Add(itemBoxSizer50, 0, wxGROW|wxALL, 0);

    wxNotebook* itemNotebook51 = new wxNotebook( itemFrame1, ID_NOTEBOOK3, wxDefaultPosition, wxSize(385, 153), wxBK_DEFAULT );

    panelCCD3 = new wxPanel( itemNotebook51, ID_PANEL9, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    panelCCD3->SetBackgroundColour(wxColour(0, 0, 0));

    itemNotebook51->AddPage(panelCCD3, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("3")));

    itemBoxSizer50->Add(itemNotebook51, 0, wxGROW|wxALL, 0);

    wxNotebook* itemNotebook53 = new wxNotebook( itemFrame1, ID_NOTEBOOK4, wxDefaultPosition, wxSize(385, 306), wxBK_DEFAULT );

    panelCCD4 = new wxPanel( itemNotebook53, ID_PANEL24, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    panelCCD4->SetBackgroundColour(wxColour(0, 0, 0));

    itemNotebook53->AddPage(panelCCD4, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("4")));

    itemBoxSizer50->Add(itemNotebook53, 0, wxGROW|wxALL, 0);

    wxPanel* itemPanel55 = new wxPanel( itemFrame1, ID_PANEL11, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
    itemBoxSizer44->Add(itemPanel55, 0, wxGROW|wxALL, 0);

    wxBoxSizer* itemBoxSizer56 = new wxBoxSizer(wxVERTICAL);
    itemPanel55->SetSizer(itemBoxSizer56);

    m_btnStart = new wxButton( itemPanel55, ID_BTN_INSPSTART, wxGetTranslation(wxString() + (wxChar) 0x5F00 + (wxChar) 0x59CB + (wxChar) 0x68C0 + (wxChar) 0x6D4B), wxDefaultPosition, wxSize(-1, 58), 0 );
    m_btnStart->SetBackgroundColour(wxColour(0, 255, 0));
    m_btnStart->SetFont(wxFont(18, wxSWISS, wxNORMAL, wxBOLD, false, wxT("Cambria")));
    itemBoxSizer56->Add(m_btnStart, 0, wxGROW|wxALL, 1);

    m_wxStatusBar = new wxStatusBar( itemFrame1, ID_STATUSBAR, wxST_SIZEGRIP|wxNO_BORDER );
    m_wxStatusBar->SetFieldsCount(3);
    m_wxStatusBar->SetStatusText(wxGetTranslation(wxString() + (wxChar) 0x5F53 + (wxChar) 0x9633 + (wxChar) 0x5E02 + (wxChar) 0x91D1 + (wxChar) 0x8BDA + (wxChar) 0x81EA + (wxChar) 0x52A8 + (wxChar) 0x5316 + (wxChar) 0x8BBE + (wxChar) 0x5907 + (wxChar) 0x6709 + (wxChar) 0x9650 + (wxChar) 0x516C + (wxChar) 0x53F8), 0);
    m_wxStatusBar->SetStatusText(_("-"), 1);
    m_wxStatusBar->SetStatusText(wxGetTranslation(wxString() + (wxChar) 0x00A9 + wxT("2013 www.machine-vision.com.cn")), 2);
    itemFrame1->SetStatusBar(m_wxStatusBar);

    wxToolBar* itemToolBar59 = CreateToolBar( wxTB_FLAT|wxTB_HORIZONTAL|wxTB_TEXT, ID_TOOLBAR );
    wxBitmap itemtool60Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/shutdown64.xpm")));
    wxBitmap itemtool60BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_SHUT, wxGetTranslation(wxString() + (wxChar) 0x5173 + (wxChar) 0x95ED + (wxChar) 0x7535 + (wxChar) 0x8111), itemtool60Bitmap, itemtool60BitmapDisabled, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    wxBitmap itemtool61Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/quit64.xpm")));
    wxBitmap itemtool61BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_QUIT, wxGetTranslation(wxString() + (wxChar) 0x9000 + (wxChar) 0x51FA + (wxChar) 0x7A0B + (wxChar) 0x5E8F), itemtool61Bitmap, itemtool61BitmapDisabled, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    itemToolBar59->AddSeparator();
    wxBitmap itemtool63Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/camDisplay.xpm")));
    wxBitmap itemtool63BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_DISP, wxGetTranslation(wxString() + (wxChar) 0x5F00 + (wxChar) 0x59CB + (wxChar) 0x663E + (wxChar) 0x793A), itemtool63Bitmap, itemtool63BitmapDisabled, wxITEM_CHECK, wxEmptyString, wxEmptyString);
    wxBitmap itemtool64Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/camSave.xpm")));
    wxBitmap itemtool64BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_SAVEIMGS, wxGetTranslation(wxString() + (wxChar) 0x5728 + (wxChar) 0x7EBF + (wxChar) 0x5B58 + (wxChar) 0x56FE), itemtool64Bitmap, itemtool64BitmapDisabled, wxITEM_CHECK, wxEmptyString, wxEmptyString);
    itemToolBar59->AddSeparator();
    wxBitmap itemtool66Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/cam1.xpm")));
    wxBitmap itemtool66BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_CAM1, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("1")), itemtool66Bitmap, itemtool66BitmapDisabled, wxITEM_RADIO, wxEmptyString, wxEmptyString);
    wxBitmap itemtool67Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/cam2.xpm")));
    wxBitmap itemtool67BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_CAM2, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("2")), itemtool67Bitmap, itemtool67BitmapDisabled, wxITEM_RADIO, wxEmptyString, wxEmptyString);
    wxBitmap itemtool68Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/cam3.xpm")));
    wxBitmap itemtool68BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_CAM3, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("3")), itemtool68Bitmap, itemtool68BitmapDisabled, wxITEM_RADIO, wxEmptyString, wxEmptyString);
    wxBitmap itemtool69Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/cam4.xpm")));
    wxBitmap itemtool69BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_CAM4, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + wxT("4")), itemtool69Bitmap, itemtool69BitmapDisabled, wxITEM_RADIO, wxEmptyString, wxEmptyString);
    wxBitmap itemtool70Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/imgSave.xpm")));
    wxBitmap itemtool70BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_SAVEIMG, wxGetTranslation(wxString() + (wxChar) 0x4FDD + (wxChar) 0x5B58 + (wxChar) 0x56FE + (wxChar) 0x50CF), itemtool70Bitmap, itemtool70BitmapDisabled, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    wxBitmap itemtool71Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/camSettings.xpm")));
    wxBitmap itemtool71BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_CAMSET, wxGetTranslation(wxString() + (wxChar) 0x76F8 + (wxChar) 0x673A + (wxChar) 0x8BBE + (wxChar) 0x7F6E), itemtool71Bitmap, itemtool71BitmapDisabled, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    wxBitmap itemtool72Bitmap(itemFrame1->GetBitmapResource(wxT("xpm/paraSettings.xpm")));
    wxBitmap itemtool72BitmapDisabled;
    itemToolBar59->AddTool(ID_TOOL_PARAMSET, wxGetTranslation(wxString() + (wxChar) 0x53C2 + (wxChar) 0x6570 + (wxChar) 0x8BBE + (wxChar) 0x7F6E), itemtool72Bitmap, itemtool72BitmapDisabled, wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    itemToolBar59->Realize();
    itemFrame1->SetToolBar(itemToolBar59);

    // Connect events and objects
    panelCCD1->Connect(ID_PANEL7, wxEVT_LEFT_DOWN, wxMouseEventHandler(ISBOTCAPMain::OnLeftDown), NULL, this);
    panelCCD1->Connect(ID_PANEL7, wxEVT_LEFT_UP, wxMouseEventHandler(ISBOTCAPMain::OnLeftUp), NULL, this);
    panelCCD1->Connect(ID_PANEL7, wxEVT_MOTION, wxMouseEventHandler(ISBOTCAPMain::OnMotion), NULL, this);
    panelCCD2->Connect(ID_PANEL8, wxEVT_LEFT_DOWN, wxMouseEventHandler(ISBOTCAPMain::OnLeftDown), NULL, this);
    panelCCD2->Connect(ID_PANEL8, wxEVT_LEFT_UP, wxMouseEventHandler(ISBOTCAPMain::OnLeftUp), NULL, this);
    panelCCD2->Connect(ID_PANEL8, wxEVT_MOTION, wxMouseEventHandler(ISBOTCAPMain::OnMotion), NULL, this);
    panelCCD3->Connect(ID_PANEL9, wxEVT_LEFT_DOWN, wxMouseEventHandler(ISBOTCAPMain::OnLeftDown), NULL, this);
    panelCCD3->Connect(ID_PANEL9, wxEVT_LEFT_UP, wxMouseEventHandler(ISBOTCAPMain::OnLeftUp), NULL, this);
    panelCCD3->Connect(ID_PANEL9, wxEVT_MOTION, wxMouseEventHandler(ISBOTCAPMain::OnMotion), NULL, this);
    panelCCD4->Connect(ID_PANEL24, wxEVT_LEFT_DOWN, wxMouseEventHandler(ISBOTCAPMain::OnLeftDown), NULL, this);
    panelCCD4->Connect(ID_PANEL24, wxEVT_LEFT_UP, wxMouseEventHandler(ISBOTCAPMain::OnLeftUp), NULL, this);
    panelCCD4->Connect(ID_PANEL24, wxEVT_MOTION, wxMouseEventHandler(ISBOTCAPMain::OnMotion), NULL, this);
////@end ISBOTCAPMain content construction
}


/*
 * wxEVT_IDLE event handler for ID_ISHCAPMAIN
 */

void ISBOTCAPMain::OnIdle( wxIdleEvent& event )
{
	bool b1 = c_pgvVisionManager->get_Reject();
	bool b2 = (c_pgvVisionManager->gvMgr_getStatus()==PSTATUS_Inspecting);
	if(b1&&b2)
	{
		c_pgvVisionManager->gvMgr_Reject();
	}
}


/*
 * wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL_PKTNUM
 */

void ISBOTCAPMain::OnSpinctrlPktnumUpdated( wxSpinEvent& event )
{
////@begin wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL_PKTNUM in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_SPINCTRL_UPDATED event handler for ID_SPINCTRL_PKTNUM in ISBOTCAPMain.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_SPINCTRL_PKTNUM
 */

void ISBOTCAPMain::OnSpinctrlPktnumUpdate( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_SPINCTRL_PKTNUM in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_SPINCTRL_PKTNUM in ISBOTCAPMain.
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ROISTART
 */

void ISBOTCAPMain::OnBtnRoistartClick( wxCommandEvent& event )
{
	c_pgvVisionManager->gvMgr_setStatus(PSTATUS_RoiMoving);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_ROISTART
 */

void ISBOTCAPMain::OnBtnRoistartUpdate( wxUpdateUIEvent& event )
{
	bool b1 = c_pgvVisionManager->gvMgr_getStatus() == PSTATUS_Loaded;
	event.Enable( b1 );
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ROIEND
 */

void ISBOTCAPMain::OnBtnRoiendClick( wxCommandEvent& event )
{
	c_pgvVisionManager->gvMgr_setStatus(PSTATUS_Loaded);
	wxString filename = c_pgvVisionManager->gvMgr_getConfigFile();
	c_pgvVisionManager->gvMgr_SaveConfig(filename,false);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_ROIEND
 */

void ISBOTCAPMain::OnBtnRoiendUpdate( wxUpdateUIEvent& event )
{
	event.Enable( (c_pgvVisionManager->gvMgr_getStatus() == PSTATUS_RoiMoving) ? true : false );
}


/*
 * wxEVT_COMMAND_LIST_ITEM_SELECTED event handler for ID_LISTCTRL_ARTICLES
 */

void ISBOTCAPMain::OnListctrlArticlesSelected( wxListEvent& event )
{
	/**获得当前所选的item信息*/
	wxListItem row_info;
	row_info.m_itemId = event.GetIndex();
	row_info.m_col = 1;
	row_info.m_mask = wxLIST_MASK_TEXT;
	m_lstArticles->GetItem( row_info );

	m_strArticleName_selected = row_info.m_text;
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLELOAD
 */

void ISBOTCAPMain::OnBtnArticleloadClick( wxCommandEvent& event )
{
	wxSetCursor(wxCURSOR_WAIT);
	if ( !m_strArticleName_selected.IsEmpty() )
	{
		wxString filepath = wxGetCwd()
			+ wxT("\\articles\\")
			+ m_strArticleName_selected
			+ wxT(".xml");

		c_pgvVisionManager->gvMgr_LoadConfig(filepath);
		wxSleep(1);
		ArticlesList_update();
//		int idxCam = m_camSelector->GetSelection();
//		params_Read(idxCam);
//		switch(idxCam)
//		{
//		case 0:
//		case 1:
//			m_noteBook_Settings->GetPage(1)->Enable(true);
//			m_noteBook_Settings->SetPageText(1,wxT("相机1"));
//			break;
//		case 2:
//		case 3:
//			m_noteBook_Settings->GetPage(2)->Enable(true);
//			m_noteBook_Settings->SetPageText(1,wxT("相机1"));
//			break;
//		default:break;
//		}
		c_pgvVisionManager->gvMgr_setStatus(PSTATUS_Loaded);
	/**< Show Roi */
		int iIndex= 0;
		for(iIndex= 0;iIndex<HGV_SUPPORT_CAMERANUM;iIndex++)
		{
			gvVisionCCD* pgvVisionCCD = c_pgvVisionManager->gvMgr_getVisionCCD(iIndex);
			if(pgvVisionCCD->get_using())
			{
				gvVisionImage_botcap* pgvVisionImage =(gvVisionImage_botcap*  )pgvVisionCCD->get_VisionImage();
				pgvVisionImage->gvIMG_DrawImage(true);
			}

		}

	}//if ( !m_strArticleName_selected.IsEmpty() )


	wxSetCursor(wxCURSOR_ARROW);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLELOAD
 */

void ISBOTCAPMain::OnBtnArticleloadUpdate( wxUpdateUIEvent& event )
{
	bool b1 = m_strArticleName_selected.IsEmpty() ? false : true;
	bool b2 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
	event.Enable(b1&&b2);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLEVIEW
 */

void ISBOTCAPMain::OnBtnArticleviewClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLEVIEW in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLEVIEW in ISBOTCAPMain.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLEVIEW
 */

void ISBOTCAPMain::OnBtnArticleviewUpdate( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLEVIEW in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLEVIEW in ISBOTCAPMain.
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLENEW
 */

void ISBOTCAPMain::OnBtnArticlenewClick( wxCommandEvent& event )
{
    dlgArticleNew* pdlg = new dlgArticleNew(c_pgvVisionManager, this);
    pdlg->ShowModal();
    pdlg->Destroy();
    ArticlesList_update();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLENEW
 */

void ISBOTCAPMain::OnBtnArticlenewUpdate( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		event.Enable(b1);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_ARTICLEDEL
 */

void ISBOTCAPMain::OnBtnArticledelClick( wxCommandEvent& event )
{
	wxListItem row_info;
	row_info.m_col = 1;
	row_info.m_mask = wxLIST_MASK_TEXT;

	int iIndex = 0;
	int iCnt = m_lstArticles->GetItemCount();
	for(iIndex=0;iIndex<iCnt;iIndex++)
	{
		row_info.m_itemId = iIndex;
		m_lstArticles->GetItem( row_info );
		if( m_strArticleName_selected == row_info.m_text )
		{
			wxString filepath = wxGetCwd()
				+ wxT("\\articles\\")
				+ m_strArticleName_selected
				+ wxT(".xml");
			if( wxYES == wxMessageBox(wxT("是否确定要删除选中方案:")+ m_strArticleName_selected, wxEmptyString,wxYES_NO | wxICON_QUESTION))
			{
				//删除文件
				wxRemoveFile(filepath);
				//更新列表框
				ArticlesList_update();
				break;
			}
		}//if( m_strArticleName_selected == row_info.m_text )
	}//for(iIndex=0;iIndex<iCnt;iIndex++)
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_ARTICLEDEL
 */

void ISBOTCAPMain::OnBtnArticledelUpdate( wxUpdateUIEvent& event )
{
	bool b1 = m_strArticleName_selected.IsEmpty() ? false : true;
	event.Enable(b1);
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_CLEAR
 */

void ISBOTCAPMain::OnBtnClearClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_CLEAR in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_CLEAR in ISBOTCAPMain.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_CLEAR
 */

void ISBOTCAPMain::OnBtnClearUpdate( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_BTN_CLEAR in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_BTN_CLEAR in ISBOTCAPMain.
}


/*
 * wxEVT_LEFT_DOWN event handler for ID_PANEL7
 */

void ISBOTCAPMain::OnLeftDown( wxMouseEvent& event )
{

	gvVisionCCD* pgvVisionCCD = c_pgvVisionManager->gvMgr_getVisionCCD(m_selectCCD);
	gvVisionImage_botcap* pgvVisionImage =(gvVisionImage_botcap*  )pgvVisionCCD->get_VisionImage();
		if (c_pgvVisionManager->gvMgr_getStatus() != PSTATUS_RoiMoving )
	{
		return;
	}
	m_isROIMoving=pgvVisionImage->gvIMG_ROISelect();
}


/*
 * wxEVT_LEFT_UP event handler for ID_PANEL7
 */

void ISBOTCAPMain::OnLeftUp( wxMouseEvent& event )
{
	gvVisionCCD* pgvVisionCCD = c_pgvVisionManager->gvMgr_getVisionCCD(m_selectCCD);
	gvVisionImage_botcap* pgvVisionImage =(gvVisionImage_botcap*  )pgvVisionCCD->get_VisionImage();
	if ( c_pgvVisionManager->gvMgr_getStatus() != PSTATUS_RoiMoving )
	{
		return;
	}
	if ( m_isROIMoving )
	{

		pgvVisionImage->gvIMG_ROIStop();
	}
	m_isROIMoving = false;
}


/*
 * wxEVT_MOTION event handler for ID_PANEL7
 */

void ISBOTCAPMain::OnMotion( wxMouseEvent& event )
{
	gvVisionCCD* pgvVisionCCD = c_pgvVisionManager->gvMgr_getVisionCCD(m_selectCCD);
	gvVisionImage_botcap* pgvVisionImage =(gvVisionImage_botcap*  )pgvVisionCCD->get_VisionImage();
	if ( c_pgvVisionManager->gvMgr_getStatus() != PSTATUS_RoiMoving )
	{
		return;
	}
	if(m_isROIMoving)
	{
		pgvVisionImage->gvIMG_ROIMove();
	}
	else
	{
		pgvVisionImage->gvIMG_SetROImshape(event.GetX(),event.GetY());
	}
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_BTN_INSPSTART
 */

void ISBOTCAPMain::OnBtnInspstartClick( wxCommandEvent& event )
{
	unsigned int iIndex = 0;
	if(c_pgvVisionManager->gvMgr_getStatus()==PSTATUS_Inspecting)
	{
		c_pgvVisionManager->gvMgr_runStop();
		m_btnStart->SetBackgroundColour( wxRGBToColour( RGB(0,255,0) ) );
	}
	else
	{
		m_btnStart->SetBackgroundColour( wxRGBToColour( RGB(255,0,0) ) );
		c_pgvVisionManager->gvMgr_runStart(PSTATUS_Inspecting);
	}
}


/*
 * wxEVT_UPDATE_UI event handler for ID_BTN_INSPSTART
 */

void ISBOTCAPMain::OnBtnInspstartUpdate( wxUpdateUIEvent& event )
{
		bool b3 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_unLoad;
		event.Enable(b3);
		if(c_pgvVisionManager->gvMgr_getStatus()==PSTATUS_Inspecting)
			event.SetText(wxT("停止检测"));
		else
			event.SetText(wxT("开始检测"));
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SHUT
 */

void ISBOTCAPMain::OnToolShutClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SHUT in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SHUT in ISBOTCAPMain.
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_SHUT
 */

void ISBOTCAPMain::OnToolShutUpdate( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_TOOL_SHUT in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_TOOL_SHUT in ISBOTCAPMain.
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_QUIT
 */

void ISBOTCAPMain::OnToolQuitClick( wxCommandEvent& event )
{
    Close();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_QUIT
 */

void ISBOTCAPMain::OnToolQuitUpdate( wxUpdateUIEvent& event )
{
////@begin wxEVT_UPDATE_UI event handler for ID_TOOL_QUIT in ISBOTCAPMain.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_UPDATE_UI event handler for ID_TOOL_QUIT in ISBOTCAPMain.
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_DISP
 */

void ISBOTCAPMain::OnToolDispClick( wxCommandEvent& event )
{

	if ( event.IsChecked() )
	{
		c_pgvVisionManager->gvMgr_runStart(PSTATUS_Displaying);
	}
	else
	{
		c_pgvVisionManager->gvMgr_runStop();

		wxString configfile = c_pgvVisionManager->gvMgr_getConfigFile();
		c_pgvVisionManager->gvMgr_SaveConfig(configfile);
	}
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_DISP
 */

void ISBOTCAPMain::OnToolDispUpdate( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		event.Enable(b1);
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SAVEIMGS
 */

void ISBOTCAPMain::OnToolSaveimgsClick( wxCommandEvent& event )
{

}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_SAVEIMGS
 */

void ISBOTCAPMain::OnToolSaveimgsUpdate( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		event.Enable(b1);
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAM1
 */

void ISBOTCAPMain::OnToolCam1Click( wxCommandEvent& event )
{
	int idxActiveCCD = 0;
	m_selectCCD = idxActiveCCD;
	c_pgvVisionManager->set_idxActiveCCD(idxActiveCCD);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_CAM1
 */

void ISBOTCAPMain::OnToolCam1Update( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		bool b2 =c_pgvVisionManager->gvMgr_getVisionCCD(0)->get_using();
		event.Enable(b1&&b2);
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAM2
 */

void ISBOTCAPMain::OnToolCam2Click( wxCommandEvent& event )
{
	int idxActiveCCD =1;
	m_selectCCD = idxActiveCCD;
	c_pgvVisionManager->set_idxActiveCCD(idxActiveCCD);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_CAM2
 */

void ISBOTCAPMain::OnToolCam2Update( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		bool b2 =c_pgvVisionManager->gvMgr_getVisionCCD(1)->get_using();
		event.Enable(b1&&b2);
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAM3
 */

void ISBOTCAPMain::OnToolCam3Click( wxCommandEvent& event )
{
		int idxActiveCCD =2;
		m_selectCCD = idxActiveCCD;
	c_pgvVisionManager->set_idxActiveCCD(idxActiveCCD);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_CAM3
 */

void ISBOTCAPMain::OnToolCam3Update( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		bool b2 =c_pgvVisionManager->gvMgr_getVisionCCD(2)->get_using();
		event.Enable(b1&&b2);
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAM4
 */

void ISBOTCAPMain::OnToolCam4Click( wxCommandEvent& event )
{
		int idxActiveCCD =3;
		m_selectCCD = idxActiveCCD;
	c_pgvVisionManager->set_idxActiveCCD(idxActiveCCD);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_CAM4
 */

void ISBOTCAPMain::OnToolCam4Update( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		bool b2 =c_pgvVisionManager->gvMgr_getVisionCCD(3)->get_using();
		event.Enable(b1&&b2);
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SAVEIMG
 */

void ISBOTCAPMain::OnToolSaveimgClick( wxCommandEvent& event )
{
		wxDateTime date = wxDateTime::Now();
		gvVisionImage_botcap* pgvImage =(gvVisionImage_botcap*)c_pgvVisionManager->gvMgr_getVisionCCD(m_selectCCD)->get_VisionImage();
		wxString filename = wxGetCwd()
		+ wxT("\\images\\tmp\\")
		+wxString::Format( wxT("%d-%02d-%02d\\CCD%d\\"), date.GetYear(), date.GetMonth()+1, date.GetDay() ,m_selectCCD+1)
		+wxString::Format( wxT("%02d-%02d-%02d"), (int )date.GetHour(), (int )date.GetMinute(), (int )date.GetSecond())
		+ wxT(".jpg");

		write_image(pgvImage->gvIMG_GetImage(),"jpg",0,filename);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_SAVEIMG
 */

void ISBOTCAPMain::OnToolSaveimgUpdate( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		bool b3 = c_pgvVisionManager->gvMgr_getStatus()==PSTATUS_Displaying;
		gvVisionImage_botcap* pgvImage =(gvVisionImage_botcap*)c_pgvVisionManager->gvMgr_getVisionCCD(m_selectCCD)->get_VisionImage();
		bool b2 = pgvImage->gvIMG_GetisLoadImage();
		event.Enable(true);
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_CAMSET
 */

void ISBOTCAPMain::OnToolCamsetClick( wxCommandEvent& event )
{
	gvVisionCCD		*pgvVisionCCD = c_pgvVisionManager->gvMgr_getVisionCCD(m_selectCCD);
	dlgSettingsCam* pdlg = new dlgSettingsCam(pgvVisionCCD,this);
	pdlg->ShowModal();
	pdlg->Destroy();
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_CAMSET
 */

void ISBOTCAPMain::OnToolCamsetUpdate( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		bool b2 = c_pgvVisionManager->gvMgr_getVisionCCD(m_selectCCD)->get_VisionCam()->isInit();
		event.Enable(b1&&b2);
}


/*
 * wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_PARAMSET
 */

void ISBOTCAPMain::OnToolParamsetClick( wxCommandEvent& event )
{
	gvVisionImage_botcap* pgvVisionImage = (gvVisionImage_botcap*)c_pgvVisionManager->gvMgr_getVisionCCD(m_selectCCD)->get_VisionImage();

	dlgArticleEdit* pdlg = new dlgArticleEdit(c_pgvVisionManager,pgvVisionImage,this);
	pdlg->ShowModal();
	pdlg->Destroy();
	pgvVisionImage->gvIMG_DrawImage(true);
}


/*
 * wxEVT_UPDATE_UI event handler for ID_TOOL_PARAMSET
 */

void ISBOTCAPMain::OnToolParamsetUpdate( wxUpdateUIEvent& event )
{
		bool b1 = c_pgvVisionManager->gvMgr_getStatus()!=PSTATUS_Inspecting;
		event.Enable(b1);
}


/*
 * Should we show tooltips?
 */

bool ISBOTCAPMain::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap ISBOTCAPMain::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin ISBOTCAPMain bitmap retrieval
    wxUnusedVar(name);
    if (name == _T("xpm/gvtec-232-60.xpm"))
    {
        wxBitmap bitmap(gvtec_232_60_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/shutdown64.xpm"))
    {
        wxBitmap bitmap(shutdown64_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/quit64.xpm"))
    {
        wxBitmap bitmap(quit64_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/camDisplay.xpm"))
    {
        wxBitmap bitmap(camDisplay_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/camSave.xpm"))
    {
        wxBitmap bitmap(camSave_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/cam1.xpm"))
    {
        wxBitmap bitmap(cam1_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/cam2.xpm"))
    {
        wxBitmap bitmap(cam2_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/cam3.xpm"))
    {
        wxBitmap bitmap(cam3_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/cam4.xpm"))
    {
        wxBitmap bitmap(cam4_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/imgSave.xpm"))
    {
        wxBitmap bitmap(imgSave_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/camSettings.xpm"))
    {
        wxBitmap bitmap(camSettings_xpm);
        return bitmap;
    }
    else if (name == _T("xpm/paraSettings.xpm"))
    {
        wxBitmap bitmap(paraSettings_xpm);
        return bitmap;
    }
    return wxNullBitmap;
////@end ISBOTCAPMain bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon ISBOTCAPMain::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin ISBOTCAPMain icon retrieval
    wxUnusedVar(name);
    if (name == _T("xpm/ISHCAP.xpm"))
    {
        wxIcon icon(ISHCAP_xpm);
        return icon;
    }
    return wxNullIcon;
////@end ISBOTCAPMain icon retrieval
}



void ISBOTCAPMain::ArticlesList_Init()
{
	RECT rcClient = wxGetClientRect( (HWND__*)m_lstArticles->GetHWND() );
	//初始化列表框
	m_lstArticles->InsertColumn( 0, wxT("序号"), wxLIST_FORMAT_LEFT, 50 );
	m_lstArticles->InsertColumn( 1, wxT("名称"), wxLIST_FORMAT_LEFT, 190 );
}
void ISBOTCAPMain::ArticlesList_update()
{
	m_lstArticles->DeleteAllItems();

	unsigned int iIndex = 0;
	wxArrayString arrFiles;

	wxDir::GetAllFiles( wxGetCwd() + wxT("\\articles"),
		&arrFiles,
		wxT("*.xml"),
		wxDIR_FILES );
	for(iIndex=0;iIndex<arrFiles.GetCount();iIndex++)
	{
		m_lstArticles->InsertItem( iIndex, wxString::Format(wxT("%d"),iIndex+1) );
		m_lstArticles->SetItem(iIndex,1,arrFiles[iIndex].AfterLast(wxT('\\')).BeforeFirst(wxT('.')) );
		if( c_pgvVisionManager )
		{
			if( c_pgvVisionManager->gvMgr_getConfigFile() == arrFiles[iIndex] )
			{
				m_lstArticles->SetItemTextColour(iIndex, wxColour(0,255,0) );
			}
		}//if( c_pgvVisionManager )
	}//for(iIndex=0;iIndex<arrFiles.GetCount();iIndex++)
}


/*
 * wxEVT_COMMAND_LIST_ITEM_DESELECTED event handler for ID_LISTCTRL_ARTICLES
 */

void ISBOTCAPMain::OnListctrlArticlesDeselected( wxListEvent& event )
{
	m_strArticleName_selected.Clear();
}

void ISBOTCAPMain::open_hWindow()
{
	int iIndex = 0;
	for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )
	{
		wxPanel* panel = nullptr;
		switch(iIndex)
		{
		case 0: panel = panelCCD1; break;
		case 1: panel = panelCCD2; break;
		case 2: panel = panelCCD3; break;
		case 3: panel = panelCCD4; break;
		}//switch(iIndex)

		gvVisionCCD* pgvVisionCCD = c_pgvVisionManager->gvMgr_getVisionCCD(iIndex);
		gvVisionImage_botcap* pgvVisionImage =(gvVisionImage_botcap*  )pgvVisionCCD->get_VisionImage();
		wxRect rcClient = panel->GetClientRect();
		pgvVisionImage->gvIMG_OpenWindow( (HWND)panel->GetHWND());
		pgvVisionImage->gvIMG_FitSize( rcClient.GetLeft(),rcClient.GetTop(),rcClient.GetWidth(),rcClient.GetHeight());


	}//for ( iIndex=0; iIndex<HGV_SUPPORT_CAMERANUM; iIndex++ )

}
