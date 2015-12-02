//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndHomeRes.c"
#include "UIFlowWndHome.h"

#include "PrjCfg.h"
#include "UIFlow.h"
#include "UIFlowWndWrnMsg.h"
#include "UIMenuSetupSetting.h"
#include "UIMenuRadarSetting.h"

static UINT32  g_uiHomeTimerID = NULL_TIMER;
static UINT32  guiFlowHomeCounter=0;
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
INT32 UIFlowWndHome_TP(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndHome_OnTimer(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndHome)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndHome_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndHome_OnClose)
EVENT_ITEM(NVTEVT_KEY_TP,UIFlowWndHome_TP)
EVENT_ITEM(NVTEVT_TIMER,UIFlowWndHome_OnTimer)
EVENT_END

static CHAR    RD_FW_str[20] = {0};
static CHAR    RD_DB_str[20] = {0};
INT32 UIFlowWndHome_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    RDINFO RDInfo;
    Show_TP_Icon_Normal();
    GetRDInfo(&RDInfo);
 
     sprintf(RD_FW_str,"F%03d",RDInfo.FW_Version);
     sprintf(RD_DB_str,"DB%04d",RDInfo.DB_Version); 

    
    UxStatic_SetData(&UIFlowWndHome_RDFW_VersionCtrl,STATIC_VALUE,Txt_Pointer(RD_FW_str));
    UxStatic_SetData(&UIFlowWndHome_RDDB_VersionCtrl,STATIC_VALUE,Txt_Pointer(RD_DB_str));
    UxCtrl_SetShow(&UIFlowWndHome_RDFW_VersionCtrl,TRUE);
    UxCtrl_SetShow(&UIFlowWndHome_RDDB_VersionCtrl,TRUE);

    if (g_uiHomeTimerID == NULL_TIMER)
    {
        g_uiHomeTimerID = GxTimer_StartTimer(TIMER_ONE_SEC, NVTEVT_1SEC_TIMER, CONTINUE);
    }		
    guiFlowHomeCounter=0;
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndHome_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if (g_uiHomeTimerID!=NULL_TIMER)
    {
        GxTimer_StopTimer(&g_uiHomeTimerID);
    }
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}


typedef enum
{
	UIFLOW_HOME_TOUCH_KEY_NONE,
	UIFLOW_HOME_TOUCH_KEY_VIDEO_MODE,
	UIFLOW_HOME_TOUCH_KEY_PHOTO_MODE,
	UIFLOW_HOME_TOUCH_KEY_PLAYBACK_MODE,
	UIFLOW_HOME_TOUCH_KEY_MENU_VIDEO,
	UIFLOW_HOME_TOUCH_KEY_MENU_PHOTO,
	UIFLOW_HOME_TOUCH_KEY_MENU_RADAR,
	UIFLOW_HOME_TOUCH_KEY_MENU_SETUP,
	UIFLOW_HOME_TOUCH_KEY_RETURN,
	UIFLOW_HOME_TOUCH_KEY_MAX	
}UIFLOW_HOME_TOUCH_KEY;
static UIFLOW_HOME_TOUCH_KEY uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_NONE;

void Show_TP_Icon_Normal(void)
{
/*
    UxList_SetData(&UIFlowWndHome_Status_MovieModeCtrl,  LST_STYLE, STATUS_NORMAL);
    UxList_SetItemData(&UIFlowWndHome_Status_PhotoModeCtrl, 0, LSTITM_STATUS, STATUS_NORMAL);
    UxList_SetItemData(&UIFlowWndHome_Status_PlaybackModeCtrl, 0, LSTITM_STATUS, STATUS_NORMAL);
    UxList_SetItemData(&UIFlowWndHome_Status_RadarSetCtrl, 0, LSTITM_STATUS, STATUS_NORMAL);
    UxList_SetItemData(&UIFlowWndHome_Status_PhotoSetCtrl, 0, LSTITM_STATUS, STATUS_NORMAL);
    UxList_SetItemData(&UIFlowWndHome_Status_MovieSetCtrl, 0, LSTITM_STATUS, STATUS_NORMAL);
    UxList_SetItemData(&UIFlowWndHome_Status_SetupCtrl, 0, LSTITM_STATUS, STATUS_NORMAL);
    UxList_SetItemData(&UIFlowWndHome_Status_ReturnCtrl, 0, LSTITM_STATUS, STATUS_NORMAL);
*/
}

INT32 UIFlowWndHome_TP(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
 	UINT32 uiEvent;
    UINT32 P1,P2;
    UINT32  uiSoundMask;
	static BOOL SoundVolSet =FALSE;
	static UINT32 SoundVol = 0;

  
    if(paramNum>0)
        uiEvent = paramArray[0];	
	
	switch(uiEvent)
	{
		case GESTURE_DOWN2UP://GESTURE_RIGHT2LEFT:
		   		
		break;			
		
		case GESTURE_UP2DOWN://GESTURE_LEFT2RIGHT:
		    		
		break;	
 
		case GESTURE_PRESSONLY:
			P1= paramArray[1];
			P2=paramArray[2];  
                    Show_TP_Icon_Normal();
		    if(TPIsOnRange(&UIFlowWndHome_Status_MovieModeCtrl,P1,P2)==TRUE)
		    	{
		    	       uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_VIDEO_MODE;
                     //  UxList_SetData(&UIFlowWndHome_Status_MovieModeCtrl,  LST_STYLE, STATUS_FOCUS);
		       	//UxList_SetItemData(&UIFlowWndHome_Status_MovieModeCtrl, 0, LSTITM_STATUS, STATUS_FOCUS);
		    	}		
                    else  if(TPIsOnRange(&UIFlowWndHome_Status_PhotoModeCtrl,P1,P2)==TRUE)
		    	{
		    	       uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_PHOTO_MODE;
		       	//UxList_SetItemData(&UIFlowWndHome_Status_PhotoModeCtrl, 0, LSTITM_STATUS, STATUS_FOCUS);
		    	}	
                    else  if(TPIsOnRange(&UIFlowWndHome_Status_PlaybackModeCtrl,P1,P2)==TRUE)
		    	{
		    	       uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_PLAYBACK_MODE;
		       	//UxList_SetItemData(&UIFlowWndHome_Status_PlaybackModeCtrl, 0, LSTITM_STATUS, STATUS_FOCUS);
		    	}
                    else  if(TPIsOnRange(&UIFlowWndHome_Status_RadarSetCtrl,P1,P2)==TRUE)
		    	{
		    	       uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_MENU_RADAR;
		       	//UxList_SetItemData(&UIFlowWndHome_Status_RadarSetCtrl, 0, LSTITM_STATUS, STATUS_FOCUS);
		    	}
                    else  if(TPIsOnRange(&UIFlowWndHome_Status_PhotoSetCtrl,P1,P2)==TRUE)
		    	{
		    	       uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_MENU_PHOTO;
		       	//UxList_SetItemData(&UIFlowWndHome_Status_PhotoSetCtrl, 0, LSTITM_STATUS, STATUS_FOCUS);
		    	}
                    else  if(TPIsOnRange(&UIFlowWndHome_Status_MovieSetCtrl,P1,P2)==TRUE)
		    	{
		    	       uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_MENU_VIDEO;
		       	//UxList_SetItemData(&UIFlowWndHome_Status_MovieSetCtrl, 0, LSTITM_STATUS, STATUS_FOCUS);
		    	}
                    else  if(TPIsOnRange(&UIFlowWndHome_Status_SetupCtrl,P1,P2)==TRUE)
		    	{
		    	       uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_MENU_SETUP;
		       	//UxList_SetItemData(&UIFlowWndHome_Status_SetupCtrl, 0, LSTITM_STATUS, STATUS_FOCUS);
		    	}
                    else  if(TPIsOnRange(&UIFlowWndHome_Status_ReturnCtrl,P1,P2)==TRUE)
		    	{
		    	       uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_RETURN;
		       	//UxList_SetItemData(&UIFlowWndHome_Status_ReturnCtrl, 0, LSTITM_STATUS, STATUS_FOCUS);
		    	}
                    else
                        {
                        }
                
		   	
		break;

		case GESTURE_CKICK:
			P1= paramArray[1];
			P2=paramArray[2]; 
			if(SoundVolSet == TRUE)
			{
				SoundVolSet = FALSE;
				DrvSound_SetVol(SoundVol);
				debug_msg("DrvSound_GetVol = %d\r\n",DrvSound_GetVol());
			}
	           // debug_msg("^G movie GESTURE_RELEASE\r\n");
	           guiFlowHomeCounter=0;
		    if(TPIsOnRange(&UIFlowWndHome_Status_MovieModeCtrl,P1,P2)==TRUE)
		    {
		    	      // if(uiHomeKeyPressed==UIFLOW_HOME_TOUCH_KEY_VIDEO_MODE)
		    	       
			    	 if(System_GetState(SYS_STATE_CURRMODE)!=PRIMARY_MODE_MOVIE)
			    	 {
					 	Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);	
			    	 }
				      else
				      {
					  	//Ux_CloseWindow(&UIFlowWndHomeCtrl, 0);
					  	Ux_CloseWindow(&UIFlowWndHomeCtrl, 1,START_MOVIE_RECORD);
		    	      }
								   
		    	}	
                 else  if(TPIsOnRange(&UIFlowWndHome_Status_PhotoModeCtrl,P1,P2)==TRUE)
		    	{
		    	     // if(uiHomeKeyPressed==UIFLOW_HOME_TOUCH_KEY_PHOTO_MODE)
		    	       {
			    	       if(System_GetState(SYS_STATE_CURRMODE)!=PRIMARY_MODE_PHOTO)
					 Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PHOTO);	
				       else
					  Ux_CloseWindow(&UIFlowWndHomeCtrl, 0);  	
		    	       }
		       	
		    	}	
                else  if(TPIsOnRange(&UIFlowWndHome_Status_PlaybackModeCtrl,P1,P2)==TRUE)
		    	{
		    	      //if(uiHomeKeyPressed==UIFLOW_HOME_TOUCH_KEY_PLAYBACK_MODE)
		    	       {
			    	       if(System_GetState(SYS_STATE_CURRMODE)!=PRIMARY_MODE_PLAYBACK)
			    	       {
			    	       		SoundVol = DrvSound_GetVol();
    							debug_msg("DrvSound_GetVol = %d\r\n",SoundVol);
								DrvSound_SetVol(0);
								SoundVolSet = TRUE;
					 			Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PLAYBACK);	
								//debug_msg("1111111111\r\n");
			    	       }
				       		else
				       		{
					  			Ux_CloseWindow(&UIFlowWndHomeCtrl, 0); 
								//debug_msg("2222222\r\n");
				       		}
		    	       }
		       	
		    	}	
                else  if(TPIsOnRange(&UIFlowWndHome_Status_RadarSetCtrl,P1,P2)==TRUE)
		    	{
		    	      //if(uiHomeKeyPressed==UIFLOW_HOME_TOUCH_KEY_MENU_RADAR)
		    	       { 
			       	TM_SetMenu(&gRadarMenu);//jacky lan ,mark for test
			       	Ux_OpenWindow((VControl *)(&UIMenuRadarSettingCtrl), 0);
		    	       }
		       	
		    	}	
                else  if(TPIsOnRange(&UIFlowWndHome_Status_PhotoSetCtrl,P1,P2)==TRUE)
		    	{
		    	     // if(uiHomeKeyPressed==UIFLOW_HOME_TOUCH_KEY_MENU_PHOTO)
		    	       {
		    	            TM_SetMenu(&gPhotoMenu);
			       	Ux_OpenWindow((VControl *)(&UIMenuPhotoSettingCtrl), 0);
			       	//Ux_OpenWindow((VControl *)(&MenuCommonItemCtrl), 0);
		    	       }
		       	
		    	}	
                else  if(TPIsOnRange(&UIFlowWndHome_Status_MovieSetCtrl,P1,P2)==TRUE)
		    	{
		    	    //  if(uiHomeKeyPressed==UIFLOW_HOME_TOUCH_KEY_MENU_VIDEO)
		    	       {
		    	            TM_SetMenu(&gMovieMenu);
			       	Ux_OpenWindow((VControl *)(&UIMenuMovieSettingCtrl), 0);
			       	//Ux_OpenWindow((VControl *)(&MenuCommonItemCtrl), 0);
		    	       }
		       	
		    	}	
                else  if(TPIsOnRange(&UIFlowWndHome_Status_SetupCtrl,P1,P2)==TRUE)
		    	{
		    	     // if(uiHomeKeyPressed==UIFLOW_HOME_TOUCH_KEY_MENU_SETUP)
		    	       {
		    	              //RD_PutCommand(0X51, 0X58);
		    	              TM_SetMenu(&gSetupMenu);
			       	Ux_OpenWindow((VControl *)(&UIMenuSetupSettingCtrl), 0);
			       	//Ux_PostEvent(NVTEVT_KEY_SHUTTER2, 1, NVTEVT_KEY_PRESS);	
		    	       }
		       	
		    	}	
                else  if(TPIsOnRange(&UIFlowWndHome_Status_ReturnCtrl,P1,P2)==TRUE)
		    	{
		    	     if(System_GetState(SYS_STATE_CURRMODE)!=PRIMARY_MODE_MOVIE)
        			Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);	
        			else
        			Ux_CloseWindow(&UIFlowWndHomeCtrl, 1,START_MOVIE_RECORD);
		       	
		    	}	
                else
               {
              }					   				
		    uiHomeKeyPressed=UIFLOW_HOME_TOUCH_KEY_NONE;
		
		break;
	}	  
	

	  
	return NVTEVT_CONSUME;
}

#define COUNTER_20_SECONDS    21
INT32 UIFlowWndHome_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    NVTEVT event;


    if(paramNum > 0)
    {
       event = paramArray[0];
    } else {
       return NVTEVT_CONSUME;
    }
    switch(event)
    {
      case NVTEVT_1SEC_TIMER:
              //debug_msg("guiFlowHomeCounter:%d..\r\n",guiFlowHomeCounter);	
	  	
		if(guiFlowHomeCounter<COUNTER_20_SECONDS)
		{
			guiFlowHomeCounter++;
		}
		if(guiFlowHomeCounter==COUNTER_20_SECONDS)
		{
			if(System_GetState(SYS_STATE_CURRMODE)!=PRIMARY_MODE_MOVIE)
			Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);	
			else
			Ux_CloseWindow(&UIFlowWndHomeCtrl, 1,START_MOVIE_RECORD);				
		}
	break;
    }
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

