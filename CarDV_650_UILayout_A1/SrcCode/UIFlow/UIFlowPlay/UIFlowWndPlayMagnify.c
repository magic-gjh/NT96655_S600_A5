//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndPlayMagnifyRes.c"
#include "UIFlowWndPlayMagnify.h"
//---------------------UIFlowWndPlayMagnifyCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlayMagnify)
CTRL_LIST_ITEM(UIFlowWndPlayMagnify_StaticTXT_DZoom)
CTRL_LIST_ITEM(UIFlowWndPlayMagnify_StaticIcon_DirUp)
CTRL_LIST_ITEM(UIFlowWndPlayMagnify_StaticIcon_DirDown)
CTRL_LIST_ITEM(UIFlowWndPlayMagnify_StaticIcon_DirRight)
CTRL_LIST_ITEM(UIFlowWndPlayMagnify_StaticIcon_DirLeft)
CTRL_LIST_ITEM(UIFlowWndPlayMagnify_Status_PhotoZoomin)
CTRL_LIST_ITEM(UIFlowWndPlayMagnify_Status_PhotoZoomout)
CTRL_LIST_ITEM(UIFlowWndPlayMagnify_Status_Return)
CTRL_LIST_END

//----------------------UIFlowWndPlayMagnifyCtrl Event---------------------------
INT32 UIFlowWndPlayMagnify_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlayMagnify_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndPlayMagnify)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndPlayMagnify_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndPlayMagnify_OnClose)
EVENT_END

INT32 UIFlowWndPlayMagnify_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlayMagnify_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndPlayMagnify_StaticTXT_DZoomCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayMagnify_StaticTXT_DZoom)
EVENT_END

//----------------------UIFlowWndPlayMagnify_StaticIcon_DirUpCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayMagnify_StaticIcon_DirUp)
EVENT_END

//----------------------UIFlowWndPlayMagnify_StaticIcon_DirDownCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayMagnify_StaticIcon_DirDown)
EVENT_END

//----------------------UIFlowWndPlayMagnify_StaticIcon_DirRightCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayMagnify_StaticIcon_DirRight)
EVENT_END

//----------------------UIFlowWndPlayMagnify_StaticIcon_DirLeftCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayMagnify_StaticIcon_DirLeft)
EVENT_END

//----------------------UIFlowWndPlayMagnify_Status_PhotoZoominCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayMagnify_Status_PhotoZoomin)
EVENT_END

//----------------------UIFlowWndPlayMagnify_Status_PhotoZoomoutCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayMagnify_Status_PhotoZoomout)
EVENT_END

//----------------------UIFlowWndPlayMagnify_Status_ReturnCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlayMagnify_Status_Return)
EVENT_END

