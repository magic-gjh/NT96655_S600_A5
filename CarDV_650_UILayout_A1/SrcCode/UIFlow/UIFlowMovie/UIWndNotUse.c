//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIWndNotUseRes.c"
#include "UIWndNotUse.h"
//---------------------UIWndNotUseCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIWndNotUse)
CTRL_LIST_END

//----------------------UIWndNotUseCtrl Event---------------------------
INT32 UIWndNotUse_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIWndNotUse_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIWndNotUse)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIWndNotUse_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIWndNotUse_OnClose)
EVENT_END

INT32 UIWndNotUse_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIWndNotUse_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
