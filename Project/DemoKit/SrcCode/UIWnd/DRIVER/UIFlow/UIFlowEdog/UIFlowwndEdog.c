//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowwndEdogRes.c"
#include "UIFlowwndEdog.h"
#include "PrjCfg.h"
#include "UIConfig.h"

//---------------------UIFlowwndEdogCtrl Debug Definition -----------------------------
#define _UIFLOWWNDEDOG_ERROR_MSG        1
#define _UIFLOWWNDEDOG_TRACE_MSG        0

#if (_UIFLOWWNDEDOG_ERROR_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_ERR))
#define UIFlowwndEdogErrMsg(...)            debug_msg ("^R UIFlowwndEdog: "__VA_ARGS__)
#else
#define UIFlowwndEdogErrMsg(...)
#endif

#if (_UIFLOWWNDEDOG_TRACE_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_TRC))
#define UIFlowwndEdogTraceMsg(...)          debug_msg ("^B UIFlowwndEdog: "__VA_ARGS__)
#else
#define UIFlowwndEdogTraceMsg(...)
#endif

extern UINT32 EdogVolumeIndex;
extern UINT32 EdogMuteIndex;
extern UINT32 EdogDriveModeIndex;
extern UINT32 EdogRadarIndex;
extern UINT32 EdogOverSpeedIndex;
extern UINT32 EdogSpeedOffsetIndex;
extern UINT32 EdogBroadCastIndex;

UINT32 EdogVolumeIndex_Cur=VOLUME_5;
UINT32 EdogMuteIndex_Cur=MUTE_20;
UINT32 EdogDriveModeIndex_Cur =DRIVERMODE_SAFTY;
UINT32 EdogRadarIndex_Cur =RADAR_AUTO;
UINT32 EdogOverSpeedIndex_Cur =OVERSPEED_80;
UINT32 EdogSpeedOffsetIndex_Cur =SPEEDOFFSET_0;
UINT32 EdogBroadCastIndex_Cur = BROADCAST_CONCISION;

static UINT32 uiEdogMenuItemIndex=MENU_VOLUME;

//---------------------UIFlowwndEdogCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowwndEdog)
CTRL_LIST_ITEM(UIFlowwndEdogMenuItem)
CTRL_LIST_END

//----------------------UIFlowwndEdogCtrl Event---------------------------
INT32 UIFlowwndEdog_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowwndEdog_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndEdog_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndEdog_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndEdog_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndEdog_OnKeyShutter2(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndEdog_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndEdog_OnTimer(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowwndEdog)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowwndEdog_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowwndEdog_OnClose)
EVENT_ITEM(NVTEVT_KEY_UP,UIFlowWndEdog_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIFlowWndEdog_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIFlowWndEdog_OnKeyShutter2)
EVENT_ITEM(NVTEVT_KEY_MENU,UIFlowWndEdog_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_MODE,UIFlowWndEdog_OnKeyMode)
EVENT_ITEM(NVTEVT_TIMER,UIFlowWndEdog_OnTimer)
EVENT_END


INT32 UIFlowwndEdog_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    User_UI_ShowLogoFile(VOLUME1+EdogVolumeIndex); 
    uiEdogMenuItemIndex=MENU_VOLUME;
    UxState_SetData(&UIFlowwndEdogMenuItemCtrl,STATE_CURITEM,UIFlowwndEdogMenuItem_ICON_EDOG_MENU_VOLUME);	
    UxCtrl_SetShow(&UIFlowwndEdogMenuItemCtrl, TRUE);
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndEdog_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];

    switch(uiKeyAct)
    {
     case NVTEVT_KEY_PRESS:
	   switch(uiEdogMenuItemIndex)
	   {
			case MENU_VOLUME:
				if(EdogVolumeIndex<VOLUME_5)
				{
					EdogVolumeIndex++;
				}
				else
				{
					EdogVolumeIndex=VOLUME_1;
				}
    				User_UI_ShowLogoFile(VOLUME1+EdogVolumeIndex); 
				EdgoRec_PutKeyCommand(MENU_VOLUME,EdogVolumeIndex);
			  break;
			case MENU_RADAR_MUTE:
				if(EdogMuteIndex<MUTE_120)
				{
					EdogMuteIndex++;
				}
				else
				{
					EdogMuteIndex=MUTE_OFF;
				}
    				User_UI_ShowLogoFile(MUTE0+EdogMuteIndex); 					
			  break;
			case MENU_DRIVE_MODE:
			      if(EdogDriveModeIndex<DRIVERMODE_SAFTY)
				{
					EdogDriveModeIndex++;
				}
				else
				{
					EdogDriveModeIndex=DRIVERMODE_TEST;
				}	
    				User_UI_ShowLogoFile(DRIVERTEST+EdogDriveModeIndex); 						
			  break;
			case MENU_RADAR_STATUS:
			      if(EdogRadarIndex<RADAR_AUTO)
				{
					EdogRadarIndex++;
				}
				else
				{
					EdogRadarIndex=RADAR_OFF;
				}	
    				User_UI_ShowLogoFile(RADAROFF+EdogRadarIndex); 					
			  break;
			case MENU_SPEEDLIMIT:
				if(EdogOverSpeedIndex==OVERSPEED_OFF)
				{
					EdogOverSpeedIndex=OVERSPEED_40;
				}
			      else if(EdogOverSpeedIndex<OVERSPEED_160)
				{
					EdogOverSpeedIndex++;
				}
				else
				{
					EdogOverSpeedIndex=OVERSPEED_OFF;
				}	
    				User_UI_ShowLogoFile(MUTE0+EdogOverSpeedIndex); 				
			  break;
			case MENU_SPEEDOFFSET:
				if(EdogSpeedOffsetIndex<SPEEDOFFSET_N9)
				{
					EdogSpeedOffsetIndex++;
				}	
				else
				{
					EdogSpeedOffsetIndex=SPEEDOFFSET_0;
				}					
    				User_UI_ShowLogoFile(SOFFSET0+EdogSpeedOffsetIndex); 				
			  break;	
			case MENU_BROADCAST:
			      if(EdogBroadCastIndex<BROADCAST_COMPLETE)
				{
					EdogBroadCastIndex++;
				}
				else
				{
					EdogBroadCastIndex=BROADCAST_CONCISION;
				}	
    				User_UI_ShowLogoFile(BCASTCON+EdogBroadCastIndex); 					
			  break;			  		  
	   }
	 break;
    	}
    return NVTEVT_CONSUME;
	
}
INT32 UIFlowWndEdog_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];

    switch(uiKeyAct)
    {
     case NVTEVT_KEY_PRESS:
	   switch(uiEdogMenuItemIndex)
	   {
			case MENU_VOLUME:
				if(EdogVolumeIndex>VOLUME_1)
				{
					EdogVolumeIndex--;
				}
				else
				{
					EdogVolumeIndex=VOLUME_5;
				}
    				User_UI_ShowLogoFile(VOLUME1+EdogVolumeIndex); 
				EdgoRec_PutKeyCommand(MENU_VOLUME,EdogVolumeIndex);					
			  break;
			case MENU_RADAR_MUTE:
				if(EdogMuteIndex>MUTE_OFF)
				{
					EdogMuteIndex--;
				}
				else
				{
					EdogMuteIndex=MUTE_120;
				}
    				User_UI_ShowLogoFile(MUTE0+EdogMuteIndex); 						
			  break;
			case MENU_DRIVE_MODE:
			      if(EdogDriveModeIndex>DRIVERMODE_TEST)
				{
					EdogDriveModeIndex--;
				}
				else
				{
					EdogDriveModeIndex=DRIVERMODE_SAFTY;
				}	
    				User_UI_ShowLogoFile(DRIVERTEST+EdogDriveModeIndex); 					
			  break;
			case MENU_RADAR_STATUS:
			      if(EdogRadarIndex>RADAR_OFF)
				{
					EdogRadarIndex--;
				}
				else
				{
					EdogRadarIndex=RADAR_AUTO;
				}	
    				User_UI_ShowLogoFile(RADAROFF+EdogRadarIndex); 					
			  break;
			case MENU_SPEEDLIMIT:
			      if(EdogOverSpeedIndex==OVERSPEED_40)
				{
					EdogOverSpeedIndex=OVERSPEED_OFF;
				}
				else if(EdogOverSpeedIndex>OVERSPEED_40)
				{
					EdogOverSpeedIndex--;
				}	
				else
				{
					EdogOverSpeedIndex=OVERSPEED_160;
				}					
    				User_UI_ShowLogoFile(MUTE0+EdogOverSpeedIndex); 					
			  break;
			case MENU_SPEEDOFFSET:
				if(EdogSpeedOffsetIndex>SPEEDOFFSET_0)
				{
					EdogSpeedOffsetIndex--;
				}	
				else
				{
					EdogSpeedOffsetIndex=SPEEDOFFSET_N9;
				}					
    				User_UI_ShowLogoFile(SOFFSET0+EdogSpeedOffsetIndex); 				
			  break;	
			case MENU_BROADCAST:
			      if(EdogBroadCastIndex>BROADCAST_CONCISION)
				{
					EdogBroadCastIndex--;
				}
				else
				{
					EdogBroadCastIndex=BROADCAST_COMPLETE;
				}	
    				User_UI_ShowLogoFile(BCASTCON+EdogBroadCastIndex); 					
			  break;			  
			  
	   }	 	
	 break;
    	}
    return NVTEVT_CONSUME;
	
}
INT32 UIFlowWndEdog_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];

    switch(uiKeyAct)
    {
     case NVTEVT_KEY_PRESS:
	      switch(uiEdogMenuItemIndex)
	      	{
			case MENU_VOLUME:
    				uiEdogMenuItemIndex=MENU_RADAR_MUTE;					
    				User_UI_ShowLogoFile(MUTE0+EdogMuteIndex); 							
    				UxState_SetData(&UIFlowwndEdogMenuItemCtrl,STATE_CURITEM,UIFlowwndEdogMenuItem_ICON_EDOG_MENU_RADAR_MUTE);						
			break;
			case MENU_RADAR_MUTE:
    				uiEdogMenuItemIndex=MENU_DRIVE_MODE;					
    				User_UI_ShowLogoFile(DRIVERTEST+EdogDriveModeIndex); 		
    				UxState_SetData(&UIFlowwndEdogMenuItemCtrl,STATE_CURITEM,UIFlowwndEdogMenuItem_ICON_EDOG_MENU_MODE);						
			break;		
			case MENU_DRIVE_MODE:
    				uiEdogMenuItemIndex=MENU_RADAR_STATUS;						
    				User_UI_ShowLogoFile(RADAROFF+EdogRadarIndex); 	
    				UxState_SetData(&UIFlowwndEdogMenuItemCtrl,STATE_CURITEM,UIFlowwndEdogMenuItem_ICON_EDOG_MENU_SENSITIVITY);						
			break;		
			case MENU_RADAR_STATUS:
    				uiEdogMenuItemIndex=MENU_SPEEDLIMIT;					
    				User_UI_ShowLogoFile(MUTE0+EdogOverSpeedIndex); 
    				UxState_SetData(&UIFlowwndEdogMenuItemCtrl,STATE_CURITEM,UIFlowwndEdogMenuItem_ICON_EDOG_MENU_OVERSPEED);						
			break;		
			case MENU_SPEEDLIMIT:
    				uiEdogMenuItemIndex=MENU_SPEEDOFFSET;							
    				User_UI_ShowLogoFile(SOFFSET0+EdogSpeedOffsetIndex); 
    				UxState_SetData(&UIFlowwndEdogMenuItemCtrl,STATE_CURITEM,UIFlowwndEdogMenuItem_ICON_EDOG_MENU_SPEEDOFFSET);						
			break;		
			case MENU_SPEEDOFFSET:
    				uiEdogMenuItemIndex=MENU_BROADCAST;									
    				User_UI_ShowLogoFile(BCASTCON+EdogBroadCastIndex); 	
    				UxState_SetData(&UIFlowwndEdogMenuItemCtrl,STATE_CURITEM,UIFlowwndEdogMenuItem_ICON_EDOG_MENU_BROADCAST);						
			break;			
			case MENU_BROADCAST:
    				uiEdogMenuItemIndex=MENU_DEFAULTSETTING;	
    				User_UI_ShowLogoFile(CONFIRM); 					
    				UxState_SetData(&UIFlowwndEdogMenuItemCtrl,STATE_CURITEM,UIFlowwndEdogMenuItem_ICON_EDOG_MENU_DEFAULT);						
			break;
			case MENU_DEFAULTSETTING:
    				uiEdogMenuItemIndex=MENU_VOLUME;			
    				User_UI_ShowLogoFile(BG_MAIN); 		
		  		EdgoRec_PutKeyCommand(MENU_RETURN,0);		
    				UxCtrl_SetShow(&UIFlowwndEdogMenuItemCtrl, FALSE);				
    	        		Ux_CloseWindow((VControl *)(&UIFlowwndEdogCtrl), 0);	 
			break;				
		}
	 break;
    	}
    return NVTEVT_CONSUME;
	
}

INT32 UIFlowWndEdog_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiKeyAct;

    uiKeyAct = paramArray[0];

    switch(uiKeyAct)
    {
       case NVTEVT_KEY_PRESS:
    		  User_UI_ShowLogoFile(BG_MAIN); 	
		  EdgoRec_PutKeyCommand(MENU_RETURN,0);									  
    	        Ux_CloseWindow((VControl *)(&UIFlowwndEdogCtrl), 0);	 				
	 break;
    	}
    return NVTEVT_CONSUME;
	
}

INT32 UIFlowWndEdog_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;

}

INT32 UIFlowwndEdog_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//----------------------UIFlowwndEdogMenuItemCtrl Event---------------------------
EVENT_BEGIN(UIFlowwndEdogMenuItem)
EVENT_END
INT32 UIFlowWndEdog_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiEvent;
	
    uiEvent = paramNum ? paramArray[0] : 0;
    switch(uiEvent)
    {
    		case NVTEVT_5SEC_TIMER:
			break;
    }
    Ux_DefaultEvent(pCtrl,NVTEVT_TIMER,paramNum,paramArray);
    return NVTEVT_CONSUME;
}

