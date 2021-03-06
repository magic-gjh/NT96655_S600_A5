//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuPhotoSettingRes.c"
#include "UIMenuPhotoSetting.h"
//---------------------UIMenuPhotoSettingCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuPhotoSetting)
CTRL_LIST_ITEM(Panel88)
CTRL_LIST_ITEM(UIMenuPhotoSetting_TXT_Title)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_Return)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_SelfTime)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_Size)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_CntShoot)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_Quality)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_Sharp)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_HandSheak)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_EV)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_ISO)
CTRL_LIST_ITEM(UIMenuMovieSetting_Status_AWB)
CTRL_LIST_END

//----------------------UIMenuPhotoSettingCtrl Event---------------------------
INT32 UIMenuPhotoSetting_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuPhotoSetting_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuPhotoSetting)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuPhotoSetting_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuPhotoSetting_OnClose)
EVENT_END

INT32 UIMenuPhotoSetting_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuPhotoSetting_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//---------------------Panel88Ctrl Control List---------------------------
CTRL_LIST_BEGIN(Panel88)
CTRL_LIST_END

//----------------------Panel88Ctrl Event---------------------------
EVENT_BEGIN(Panel88)
EVENT_END

//----------------------UIMenuPhotoSetting_TXT_TitleCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_TXT_Title)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_ReturnCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_Return)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_SelfTimeCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_SelfTime)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_SizeCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_Size)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_CntShootCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_CntShoot)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_QualityCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_Quality)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_SharpCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_Sharp)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_HandSheakCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_HandSheak)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_EVCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_EV)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_ISOCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_ISO)
EVENT_END

//----------------------UIMenuMovieSetting_Status_AWBCtrl Event---------------------------
EVENT_BEGIN(UIMenuMovieSetting_Status_AWB)
EVENT_END

