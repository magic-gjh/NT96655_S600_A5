//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndHomeRes.c"
#include "UIFlowWndHome.h"
//---------------------UIFlowWndHomeCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndHome)
CTRL_LIST_ITEM(UIFlowWndHome_TimePnael)
CTRL_LIST_ITEM(UIFlowWndHome_Status_MovieMode)
CTRL_LIST_ITEM(UIFlowWndHome_Status_PhotoMode)
CTRL_LIST_ITEM(UIFlowWndHome_Status_PlaybackMode)
CTRL_LIST_ITEM(UIFlowWndHome_Status_RadarSet)
CTRL_LIST_ITEM(UIFlowWndHome_Status_PhotoSet)
CTRL_LIST_ITEM(UIFlowWndHome_Status_MovieSet)
CTRL_LIST_ITEM(UIFlowWndHome_Status_Setup)
CTRL_LIST_ITEM(UIFlowWndHome_Status_Return)
CTRL_LIST_END

//----------------------UIFlowWndHomeCtrl Event---------------------------
INT32 UIFlowWndHome_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndHome_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndHome)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndHome_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndHome_OnClose)
EVENT_END

INT32 UIFlowWndHome_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndHome_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//---------------------UIFlowWndHome_TimePnaelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndHome_TimePnael)
CTRL_LIST_ITEM(UIFlowWndHome_RDFW_Version)
CTRL_LIST_ITEM(UIFlowWndHome_RDDB_Version)
CTRL_LIST_ITEM(UIFlowWndHome_DBVersion)
CTRL_LIST_ITEM(UIFlowWndHome_FWVersion)
CTRL_LIST_END

//----------------------UIFlowWndHome_TimePnaelCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_TimePnael)
EVENT_END

//----------------------UIFlowWndHome_RDFW_VersionCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_RDFW_Version)
EVENT_END

//----------------------UIFlowWndHome_RDDB_VersionCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_RDDB_Version)
EVENT_END

//----------------------UIFlowWndHome_DBVersionCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_DBVersion)
EVENT_END

//----------------------UIFlowWndHome_FWVersionCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_FWVersion)
EVENT_END

//----------------------UIFlowWndHome_Status_MovieModeCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_Status_MovieMode)
EVENT_END

//----------------------UIFlowWndHome_Status_PhotoModeCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_Status_PhotoMode)
EVENT_END

//----------------------UIFlowWndHome_Status_PlaybackModeCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_Status_PlaybackMode)
EVENT_END

//----------------------UIFlowWndHome_Status_RadarSetCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_Status_RadarSet)
EVENT_END

//----------------------UIFlowWndHome_Status_PhotoSetCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_Status_PhotoSet)
EVENT_END

//----------------------UIFlowWndHome_Status_MovieSetCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_Status_MovieSet)
EVENT_END

//----------------------UIFlowWndHome_Status_SetupCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_Status_Setup)
EVENT_END

//----------------------UIFlowWndHome_Status_ReturnCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndHome_Status_Return)
EVENT_END
