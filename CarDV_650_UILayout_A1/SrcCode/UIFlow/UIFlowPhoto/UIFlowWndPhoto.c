//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndPhotoRes.c"
#include "UIFlowWndPhoto.h"
//---------------------UIFlowWndPhotoCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPhoto)
CTRL_LIST_ITEM(UIFlowWndPhoto_StaticTXT_FreePicC)
CTRL_LIST_ITEM(UIFlowWndPhoto_StatusICN_EVC)
CTRL_LIST_ITEM(UIFlowWndPhoto_StatusICN_ISOC)
CTRL_LIST_ITEM(UIFlowWndPhoto_StaticTXT_SizeC)
CTRL_LIST_ITEM(UIFlowWndPhoto_StatusICN_AntiShakingC)
CTRL_LIST_ITEM(UIFlowWndPhoto_StatusICN_WBC)
CTRL_LIST_ITEM(UIFlowWndPhoto_StatusICN_Quality)
CTRL_LIST_ITEM(UIFlowWndPhoto_StatusICN_Storage)
CTRL_LIST_ITEM(UIFlowWndPhoto_StaticTXT_DZoom)
CTRL_LIST_ITEM(UIFlowWndPhoto_StatusICN_Battery)
CTRL_LIST_ITEM(UIFlowWndPhoto_StaticTXT_SelftimerCnt)
CTRL_LIST_ITEM(UIFlowWndPhoto_StatusICN_ContinueShot)
CTRL_LIST_ITEM(UIFlowWndPhoto_Status_Return)
CTRL_LIST_END

//----------------------UIFlowWndPhotoCtrl Event---------------------------
INT32 UIFlowWndPhoto_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPhoto_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndPhoto)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndPhoto_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndPhoto_OnClose)
EVENT_END

INT32 UIFlowWndPhoto_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPhoto_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndPhoto_StaticTXT_FreePicCCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StaticTXT_FreePicC)
EVENT_END

//----------------------UIFlowWndPhoto_StatusICN_EVCCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StatusICN_EVC)
EVENT_END

//----------------------UIFlowWndPhoto_StatusICN_ISOCCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StatusICN_ISOC)
EVENT_END

//----------------------UIFlowWndPhoto_StaticTXT_SizeCCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StaticTXT_SizeC)
EVENT_END

//----------------------UIFlowWndPhoto_StatusICN_AntiShakingCCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StatusICN_AntiShakingC)
EVENT_END

//----------------------UIFlowWndPhoto_StatusICN_WBCCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StatusICN_WBC)
EVENT_END

//----------------------UIFlowWndPhoto_StatusICN_QualityCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StatusICN_Quality)
EVENT_END

//----------------------UIFlowWndPhoto_StatusICN_StorageCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StatusICN_Storage)
EVENT_END

//----------------------UIFlowWndPhoto_StaticTXT_DZoomCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StaticTXT_DZoom)
EVENT_END

//----------------------UIFlowWndPhoto_StatusICN_BatteryCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StatusICN_Battery)
EVENT_END

//----------------------UIFlowWndPhoto_StaticTXT_SelftimerCntCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StaticTXT_SelftimerCnt)
EVENT_END

//----------------------UIFlowWndPhoto_StatusICN_ContinueShotCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_StatusICN_ContinueShot)
EVENT_END

//----------------------UIFlowWndPhoto_Status_ReturnCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPhoto_Status_Return)
EVENT_END
