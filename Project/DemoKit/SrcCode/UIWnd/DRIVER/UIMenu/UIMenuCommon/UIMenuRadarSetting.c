//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuRadarSettingRes.c"
#include "UIMenuRadarSetting.h"

#include "UIFlow.h"
#include "MenuId.h"

//---------------------UIMenuRadarSettingCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuRadarSetting)
CTRL_LIST_ITEM(UIMenuRadarSetting_TXT_Title)
CTRL_LIST_ITEM(UIMenuRadarSetting_Status_Return)
CTRL_LIST_ITEM(UIMenuRadarSetting_Status_UserSpeedLimit)
CTRL_LIST_ITEM(UIMenuRadarSetting_Status_CitySpeedLimit)
CTRL_LIST_ITEM(UIMenuRadarSetting_Status_RadarReport)
CTRL_LIST_ITEM(UIMenuRadarSetting_Status_XReport)
CTRL_LIST_ITEM(UIMenuRadarSetting_Status_DrivingMode)
CTRL_LIST_ITEM(UIMenuRadarSetting_Status_SPEED_Correction)
CTRL_LIST_ITEM(UIMenuRadarSetting_Status_EdogOnOff)
CTRL_LIST_END

//----------------------UIMenuRadarSettingCtrl Event---------------------------
INT32 UIMenuRadarSetting_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuRadarSetting_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuRadarSetting_TP(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuRadarSetting)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuRadarSetting_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuRadarSetting_OnClose)
EVENT_ITEM(NVTEVT_KEY_TP,UIMenuRadarSetting_TP)
EVENT_END


INT32 UIMenuRadarSetting_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuRadarSetting_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}

void  GotoRADAR_MenuItemOption(int pCtrl)
{
  TM_MENU*    pMenu = TM_GetMenu();
    TM_PAGE*    pPage;
    TM_ITEM*    pItem;
    int ItemNum = 0;
    pMenu->Status = TMS_ON_ITEM;
    {
        pPage = &pMenu->pPages[pMenu->SelPage];
       
                pPage->SelItem = pCtrl;
               
        pItem = &pPage->pItems[pPage->SelItem];

        if (pItem->Count != 0 && pItem->SysFlag != 0)   // standard process
        {
            if (TM_MENU_CALLBACK(pMenu, TMM_ENTER_OPTION, MAKE_LONG(pItem->ItemId, 0)) == TMF_PASS_MESSAGE)
            {
                return NVTEVT_CONSUME;
            }
        }

       
        Ux_Redraw();

        if (pItem->Count != 0 && pItem->SysFlag != 0)   // standard process
        {
            pMenu->Status = TMS_ON_OPTION;
            Ux_OpenWindow(&MenuCommonOptionCtrl, 0);
        }
        else if (pItem->pOptions != 0)                  // custom process
        {
            pMenu->Status = TMS_ON_CUSTOM;
            TM_ITEM_CALLBACK(pItem, 0, 0);              // execute custom menu flow
        }
    }
}

    INT32 UIMenuRadarSetting_TP(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
  UINT32 uiEvent;
    UINT32 P1,P2;
    UINT32  uiSoundMask;
  
    if(paramNum>0)
        uiEvent = paramArray[0];	
	
	switch(uiEvent)
	{
		case GESTURE_DOWN2UP://GESTURE_RIGHT2LEFT:
		   		
		break;			
		
		case GESTURE_UP2DOWN://GESTURE_LEFT2RIGHT:
		    		
		break;	
 
		
		case GESTURE_CKICK:
			P1= paramArray[1];
			P2=paramArray[2];  
     
	            //debug_msg("^G movie GESTURE_CKICK\r\n");
		    if(TPIsOnRange(&UIMenuRadarSetting_Status_ReturnCtrl,P1,P2)==TRUE)
		    	{
		    	       //if(uiPhotoSettingPressed==UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_RETURN)
		    	       {
			       	
                                 
							Ux_CloseWindow(&UIMenuRadarSettingCtrl, 0);
					
		    	       }
								   
		    	}	
            else if(TPIsOnRange(&UIMenuRadarSetting_Status_UserSpeedLimitCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoRADAR_MenuItemOption(MENU_USER_SPEED_LIMIT);
								   
		    	}	
            else if(TPIsOnRange(&UIMenuRadarSetting_Status_CitySpeedLimitCtrl,P1,P2)==TRUE)
		    	{
		    	      
						GotoRADAR_MenuItemOption(MENU_CITYMODE_SPEEDLIMIT);		   
		    	}	
            else if(TPIsOnRange(&UIMenuRadarSetting_Status_RadarReportCtrl,P1,P2)==TRUE)
		    	{
		    	      
						GotoRADAR_MenuItemOption(MENU_RADAR_REPORT);			   
		    	}	
            else if(TPIsOnRange(&UIMenuRadarSetting_Status_XReportCtrl,P1,P2)==TRUE)
		    	{
		    	      
							GotoRADAR_MenuItemOption(MENU_RADAR_X_REPORT);		   
		    	}	
            else if(TPIsOnRange(&UIMenuRadarSetting_Status_SPEED_CorrectionCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoRADAR_MenuItemOption(MENU_SPEED_Correction);	
								   
		    	}	
            else if(TPIsOnRange(&UIMenuRadarSetting_Status_EdogOnOffCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoRADAR_MenuItemOption(MENU_RADAR_ONOFF);	
								   
		    	}	
            else if(TPIsOnRange(&UIMenuRadarSetting_Status_DrivingModeCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoRADAR_MenuItemOption(MENU_DRIVING_MODE);	
								   
		    	}
            
           
           else
			    {
			    Ux_CloseWindow(&UIMenuRadarSettingCtrl, 0);
			    }
		
		break;
	}	  
	

	  
	return NVTEVT_CONSUME;
}

//----------------------UIMenuRadarSetting_TXT_TitleCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_TXT_Title)
EVENT_END

//----------------------UIMenuRadarSetting_Status_ReturnCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_Status_Return)
EVENT_END

//----------------------UIMenuRadarSetting_Status_UserSpeedLimitCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_Status_UserSpeedLimit)
EVENT_END

//----------------------UIMenuRadarSetting_Status_CitySpeedLimitCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_Status_CitySpeedLimit)
EVENT_END

//----------------------UIMenuRadarSetting_Status_RadarReportCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_Status_RadarReport)
EVENT_END

//----------------------UIMenuRadarSetting_Status_XReportCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_Status_XReport)
EVENT_END

//----------------------UIMenuRadarSetting_Status_DrivingModeCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_Status_DrivingMode)
EVENT_END

//----------------------UIMenuRadarSetting_Status_SPEED_CorrectionCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_Status_SPEED_Correction)
EVENT_END

//----------------------UIMenuRadarSetting_Status_EdogOnOffCtrl Event---------------------------
EVENT_BEGIN(UIMenuRadarSetting_Status_EdogOnOff)
EVENT_END

