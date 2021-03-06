//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "MenuCommonOptionRes.c"
#include "UIFlow.h"
#include "UIFlowWndWrnMsg.h"
#include "Rtc.h"
#include "MenuId.h"
#include "UIInfo.h"

#include "UIFlow.h"

static UINT32 MenuCommonOptionIndex;
static UINT32 MenuCommonOptionIndexPre;
static UINT32 MenuCommonOptionCurrentPage=1;
static UINT32 MenuCommonOptionTotalPage=1;
static BOOL MenuCommonOptionTPKeyHasPressed=FALSE;
UINT32 uiTotalOption;
//---------------------MenuCommonOptionCtrl Control List---------------------------
CTRL_LIST_BEGIN(MenuCommonOption)
CTRL_LIST_ITEM(UIMenuCommonOptionTitle)
CTRL_LIST_ITEM(MenuCommonOptionPanel)
CTRL_LIST_ITEM(MenuCommonOptionReturn)
CTRL_LIST_ITEM(MenuCommonOption_Info)
CTRL_LIST_ITEM(MenuCommonOption_Right)
CTRL_LIST_ITEM(MenuCommonOption_Left)
CTRL_LIST_END

//----------------------MenuCommonOptionCtrl Event---------------------------
INT32 MenuCommonOption_OnOpen(VControl *, UINT32, UINT32 *);
INT32 MenuCommonOption_OnClose(VControl *, UINT32, UINT32 *);
INT32 MenuCommonOption_Menu_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 MenuCommonOption_Menu_OnTouchPanelKey(VControl *, UINT32, UINT32 *);
INT32 MenuCommonOption_OnBatteryLow(VControl *, UINT32, UINT32 *);



EVENT_BEGIN(MenuCommonOption)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,MenuCommonOption_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,MenuCommonOption_OnClose)

EVENT_ITEM(NVTEVT_KEY_ENTER,MenuCommonOption_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,MenuCommonOption_Menu_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_TP,MenuCommonOption_Menu_OnTouchPanelKey)
EVENT_ITEM(NVTEVT_BATTERY_LOW,MenuCommonOption_OnBatteryLow)
EVENT_END

//extern void MenuCommon_CalcPageInfo(VControl *pCtrl);

void MenuCommonOption_UpdateContent(TM_MENU* pMenu)
{
    UINT32      i;
    TM_PAGE*    pPage;
    TM_ITEM*    pItem;
    TM_OPTION*  pOption;
    UINT32  uiOption,uiOptionPerPage, uiTotalOptionOri;
	
    pPage = &pMenu->pPages[pMenu->SelPage];
    pItem = &pPage->pItems[pPage->SelItem];
  pOption = &pItem->pOptions[MenuCommonOptionIndexPre];
   //pOption = MenuCommonOptionIndexPre;//SysGetFlag(pItem->SysFlag);

     UxStatic_SetData(&MenuCommonOption_InfoCtrl, STATIC_VALUE, pOption->TextId);
    UxStatic_SetData(&UIMenuCommonOptionTitleCtrl, STATIC_VALUE, pItem->TextId);

    UxCtrl_SetDirty(&MenuCommonOptionCtrl, TRUE);
   
    //Ux_RedrawAllWind();
}


INT32 MenuCommonOption_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    TM_MENU*    pMenu = TM_GetMenu();
    TM_PAGE*    pPage;
    TM_ITEM*    pItem;

    pPage = &pMenu->pPages[pMenu->SelPage];
    pItem = &pPage->pItems[pPage->SelItem];
	uiTotalOption=pItem->Count -1;
    debug_msg("^G totle option num : %d\r\n",uiTotalOption);
    
    MenuCommonOptionIndexPre=SysGetFlag(pItem->SysFlag);
    MenuCommonOption_UpdateContent(pMenu);
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 MenuCommonOption_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
   
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}


    
INT32 MenuCommonOption_OnBatteryLow(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(pCtrl,0);
    Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_BATTERY_LOW, FLOWWRNMSG_TIMER_5SEC);
    return NVTEVT_CONSUME;
}

INT32 MenuCommonOption_Menu_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    TM_MENU*    pMenu = TM_GetMenu();
    TM_PAGE*    pPage;
    TM_ITEM*    pItem;
    UINT32      uiSelOption;
	debug_msg("^G ---- MenuCommonOption_Menu_OnKeyEnter  \r\n");
    pPage = &pMenu->pPages[pMenu->SelPage];
    pItem = &pPage->pItems[pPage->SelItem];

    //uiSelOption = UxMenu_GetData(&MenuCommonOption_MenuCtrl, MNU_CURITM); // selected option
    uiSelOption = MenuCommonOptionIndexPre;
    // set system flag by selected Option
    SysSetFlag(pItem->SysFlag, uiSelOption);

    // Close current UI Window now
    
    Ux_CloseWindow(&MenuCommonOptionCtrl, 2,pItem->ItemId,uiSelOption);
    // notify upper layer the Option had been confirmed
    TM_MENU_CALLBACK(pMenu, TMM_CONFIRM_OPTION, MAKE_LONG(pItem->ItemId, uiSelOption));


    return NVTEVT_CONSUME;
}




#if 1
INT32 MenuCommonOption_Menu_OnTouchPanelKey(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uiEvent;
    UINT32 P1,P2;
    UINT32  uiSoundMask; 
    UINT32 uiTotalItemOri;	
    UINT32 index,i;
    UINT32 CurrentOptionIndex;

    TM_MENU*    pMenu = TM_GetMenu();
    TM_PAGE*    pPage;
    TM_ITEM*    pItem;
 
    pPage = &pMenu->pPages[pMenu->SelPage];
    pItem = &pPage->pItems[pPage->SelItem];
	
    if(paramNum>0)
        uiEvent = paramArray[0];	

	switch(uiEvent)
	{
		case GESTURE_RIGHT2LEFT:						
		case GESTURE_LEFT2RIGHT:
		default:
	      								
		break;	
		
		case GESTURE_UP2DOWN:
			
			
		break;	
		case GESTURE_DOWN2UP:	
				
		break;			
		
		case GESTURE_PRESSONLY:
			
		break;
 
		case GESTURE_CKICK:
			P1= paramArray[1];
			P2=paramArray[2];  		
			if(TPIsOnRange(&MenuCommonOption_InfoCtrl,P1,P2)==TRUE)
			{
						      	
                        return MenuCommonOption_Menu_OnKeyEnter(&MenuCommonOption_InfoCtrl, paramNum, paramArray);
				      
				
			}		
                    
			else if(TPIsOnRange(&MenuCommonOption_RightCtrl,P1,P2)==TRUE)
			{
				if(MenuCommonOptionIndexPre >=uiTotalOption)
                            MenuCommonOptionIndexPre = 0;
                            else
                                MenuCommonOptionIndexPre ++;
                            MenuCommonOption_UpdateContent(pMenu);
			}	
                    else if(TPIsOnRange(&MenuCommonOption_LeftCtrl,P1,P2)==TRUE)
    			{
    				if(MenuCommonOptionIndexPre <= 0)
                            MenuCommonOptionIndexPre = uiTotalOption;
                            else
                                MenuCommonOptionIndexPre--;
                            MenuCommonOption_UpdateContent(pMenu);
    			}
                    else if(TPIsOnRange(&MenuCommonOptionReturnCtrl,P1,P2)==TRUE)
    			{
    				return MenuCommonOption_Menu_OnKeyEnter(&MenuCommonOption_InfoCtrl, paramNum, paramArray);
    			}
                    else 
                    {
                    //Ux_CloseWindow(&MenuCommonOptionCtrl,0);	
                    }
		break;
	}	  

	return NVTEVT_CONSUME;
}
#endif 
//----------------------UIMenuCommonOptionTitleCtrl Event---------------------------
EVENT_BEGIN(UIMenuCommonOptionTitle)
EVENT_END

//---------------------MenuCommonOptionPanelCtrl Control List---------------------------
CTRL_LIST_BEGIN(MenuCommonOptionPanel)
CTRL_LIST_END

//----------------------MenuCommonOptionPanelCtrl Event---------------------------
EVENT_BEGIN(MenuCommonOptionPanel)
EVENT_END

//----------------------MenuCommonOptionReturnCtrl Event---------------------------
EVENT_BEGIN(MenuCommonOptionReturn)
EVENT_END

//----------------------MenuCommonOption_InfoCtrl Event---------------------------
EVENT_BEGIN(MenuCommonOption_Info)
EVENT_END

//----------------------MenuCommonOption_RightCtrl Event---------------------------
EVENT_BEGIN(MenuCommonOption_Right)
EVENT_END

//----------------------MenuCommonOption_LeftCtrl Event---------------------------
EVENT_BEGIN(MenuCommonOption_Left)
EVENT_END
