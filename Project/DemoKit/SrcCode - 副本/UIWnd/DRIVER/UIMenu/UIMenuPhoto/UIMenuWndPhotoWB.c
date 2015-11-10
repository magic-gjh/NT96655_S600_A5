//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndPhotoWBRes.c"
#include "UIMenuWndPhotoWB.h"
#include "MenuCommonItem.h"
#include "UIPhotoObj.h"
#include "UISetup.h"
#include "UIFlow.h"

static UINT32 g_uiWBValue = 0; // for WB setting backup

//---------------------UIMenuWndPhotoWBCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoWB)
CTRL_LIST_ITEM(UIMenuWndPhotoWB_Panel)
CTRL_LIST_END

//----------------------UIMenuWndPhotoWBCtrl Event---------------------------
INT32 UIMenuWndPhotoWB_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoWB_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoWB_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoWB_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoWB_OnKeyMode(VControl *, UINT32, UINT32 *);
//INT32 UIMenuWndPhotoWB_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoWB)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndPhotoWB_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndPhotoWB_OnClose)
EVENT_ITEM(NVTEVT_KEY_LEFT,UIMenuWndPhotoWB_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_MENU,UIMenuWndPhotoWB_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIMenuWndPhotoWB_OnKeyMode)
//EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndPhotoWB_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndPhotoWB_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    g_uiWBValue = SysGetFlag(FL_WB); // backup WB setting
    UxMenu_SetData(&UIMenuWndPhotoWB_MenuCtrl,MNU_CURITM,g_uiWBValue);
    //Ux_RedrawAllWind();
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoWB_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2014/06/13#KS Hung -begin
    //#NT#Modify UIPhotoObjCtrl to CustomPhotoObjCtrl
    Ux_SendEvent(&CustomPhotoObjCtrl,NVTEVT_EXE_WB,1,g_uiWBValue); // recall WB setting
    //#NT#2014/06/13#KS Hung -end
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoWB_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(&UIMenuWndPhotoWBCtrl,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoWB_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //Ux_CloseWindow(&MenuCommonItemCtrl,0); // close whole tab menu
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoWB_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISetupObjCtrl,NVTEVT_EXE_CHANGEDSCMODE,1,DSCMODE_CHGTO_NEXT);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoWB_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISetupObjCtrl,NVTEVT_FORCETO_LIVEVIEW_MODE,0);
    return NVTEVT_CONSUME;
}
//---------------------UIMenuWndPhotoWB_PanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndPhotoWB_Panel)
CTRL_LIST_ITEM(UIMenuWndPhotoWB_Menu)
CTRL_LIST_END

//----------------------UIMenuWndPhotoWB_PanelCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndPhotoWB_Panel)
EVENT_END

//----------------------UIMenuWndPhotoWB_MenuCtrl Event---------------------------
INT32 UIMenuWndPhotoWB_Menu_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoWB_Menu_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoWB_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndPhotoWB_Menu_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndPhotoWB_Menu)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndPhotoWB_Menu_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndPhotoWB_Menu_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndPhotoWB_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndPhotoWB_Menu_OnKeyShutter2)
EVENT_END

INT32 UIMenuWndPhotoWB_Menu_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  value;
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    value = UxMenu_GetData(pCtrl,MNU_CURITM);
    //#NT#2014/06/13#KS Hung -begin
    //#NT#Modify UIPhotoObjCtrl to CustomPhotoObjCtrl
    Ux_SendEvent(&CustomPhotoObjCtrl,NVTEVT_EXE_WB,1,value);
    //#NT#2014/06/13#KS Hung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoWB_Menu_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  value;
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    value = UxMenu_GetData(pCtrl,MNU_CURITM);
    //#NT#2014/06/13#KS Hung -begin
    //#NT#Modify UIPhotoObjCtrl to CustomPhotoObjCtrl
    Ux_SendEvent(&CustomPhotoObjCtrl,NVTEVT_EXE_WB,1,value);
    //#NT#2014/06/13#KS Hung -end
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoWB_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    g_uiWBValue = UxMenu_GetData(pCtrl,MNU_CURITM); // change WB setting
    //#NT#2014/06/13#KS Hung -begin
    //#NT#Modify UIPhotoObjCtrl to CustomPhotoObjCtrl
    Ux_SendEvent(&CustomPhotoObjCtrl,NVTEVT_EXE_WB,1,g_uiWBValue);
    //#NT#2014/06/13#KS Hung -end
    Ux_CloseWindow(&UIMenuWndPhotoWBCtrl,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndPhotoWB_Menu_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    // the same behavior as ENTER key!
    return UIMenuWndPhotoWB_Menu_OnKeyEnter(pCtrl, paramNum, paramArray);
}
