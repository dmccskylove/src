#ifndef _HGVISIONDEF_H_
#define _HGVISIONDEF_H_

#include <wx/dir.h>
#include <wx/fileconf.h>
#include <wx/xml/xml.h>
#include <wx/filename.h>
#include <ctb-0.16/ctb.h>

#define HGV_SUPPORT_CAMERANUM			4
#define HGV_SIGNAL_NODE_NUM				64
#define HGV_ZERO						0.000001f
#define HGV_APP_TITLE					wxT("ISBOTCAP v2.0")

enum E_COLOR_TYPE
{
    TYPE_COLOR_R = 1,
    TYPE_COLOR_G = 2,
    TYPE_COLOR_B = 3,
};
/************************************************************************/
/*                                                                      */
/************************************************************************/

enum E_PROGRAM_STATUS
{
    PSTATUS_unLoad = -1,
    PSTATUS_Loaded = 0,
    PSTATUS_factorySettings,
    PSTATUS_RoiMoving,
    PSTATUS_ImgSaving,
    PSTATUS_Displaying,
    PSTATUS_Inspecting,
};

enum E_CCD_ROLE
{
    CCDROLE_FRONT = 0,
    CCDROLE_OBVERSE,
    CCDROLE_SIDE,
};

/**< 以下为检测任务的定义 */
enum E_TASKTYPE_FRONT
{
    TASK_FRONT_LOGO = 0,
    TASK_FRONT_BLACK,
    TASK_FRONT_NUM,
};


static const char *g_pchTask_Front[TASK_FRONT_NUM] =
{
	"商标",
    "黑斑",

};


enum E_TASK_OBVERSE
{
    TASK_OBVERSE_LOGO = 0,
    TASK_OBVERSE_COLOR,
    TASK_OBVERSE_CRACK,
    TASK_OBVERSE_NUM,
};


static const char *g_pchTask_Obverse[TASK_OBVERSE_NUM] =
{
	"商标",
	 "颜色",
    "裂纹",
};


enum E_TASK_SIDE
{
	TASK_SIDE_COLOR,
    TASK_SIDE_NUM,
};


static const char *g_pchTask_Side[TASK_SIDE_NUM] =
{
    "颜色",

};

enum E_TASK_TYPE_ALL
{
	TASKTYPE_LOGO = 0,
    TASKTYPE_BLACK,
	TASKTYPE_COLOR,
    TASK_TYPE_NUM,
};

static const char *g_pchTask_ALL[TASK_TYPE_NUM] =
{
    "商标",
    "黑斑",
	"颜色",
};

enum E_ROI_TYPE
{
	ROITYPE_CIRCLE = 0,
	ROITYPE_RECT,
};

/**< 以下为全局函数 */
namespace ISHCAP_API
{

wxXmlNode   *xml_GetNode( wxXmlNode* pNode_parent, wxString strNodeName );
wxString    xml_GetNodeValueS( wxXmlNode* pNode_parent, wxString strNodeName, wxString default_value );
double      xml_GetNodeValueF( wxXmlNode* pNode_parent, wxString strNodeName, double default_value );
long        xml_GetNodeValueL( wxXmlNode* pNode_parent, wxString strNodeName, long default_value );

bool        xml_SetNodeValueS( wxXmlNode* pNode_parent, wxString strNodeName, wxString strVal,wxString comment = wxEmptyString );
bool        xml_SetNodeValueF( wxXmlNode* pNode_parent, wxString strNodeName, double   dfVal,wxString comment = wxEmptyString );
bool        xml_SetNodeValueL( wxXmlNode* pNode_parent, wxString strNodeName, long     lVal,wxString comment = wxEmptyString );

}

#endif//_HGVISIONDEF_H_
