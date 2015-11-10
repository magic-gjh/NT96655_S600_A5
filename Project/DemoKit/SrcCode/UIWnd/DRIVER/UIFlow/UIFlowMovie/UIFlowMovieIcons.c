
#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIFlow.h"
#include "JpgEnc.h"
#include "Exif.h"
#include "Utility.h"
#include "audio.h"
#include "RTC.h"
//#include "PhotoTsk.h"
#include "UIConfig.h"

#define FW_TEST   DISABLE//ENABLE//

extern BOOL gbQuickMute;

static CHAR    g_RecMaxTimeStr[20] = {0};
static UINT32  g_RecMaxTime=0;
static CHAR    g_RecCurrTimeStr[20] = {0};
static UINT32  g_RecCurrTime=0;
static CHAR    date_str[20] = {0};
static CHAR    time_str[20] = {0};

static CHAR    resolution_Buf[MOVIE_SIZE_ID_MAX][10]=
{
    "1080FHD",
    "720P",
    "WVGA",
    "VGA"
};

static CHAR    resolution_dual_Buf[MOVIE_SIZE_DUAL_ID_MAX][16]=
{
    "1080P + 720P",
    "720P + 720P"
};

#define MARK 0



void FlowMovie_IconDrawMaxRecTime(void)
{
#if MARK
    memset((void *)g_RecMaxTimeStr, 0, sizeof(g_RecMaxTimeStr));
    g_RecMaxTime = UIMovRecObj_GetData(RECMOVIE_MAXSECOND);

    if (g_RecMaxTime <= 2)
    {
        FlowMovie_SetRecMaxTime(0);
    }
    else if (g_RecMaxTime > 86399)
    {   ///23:59:59
        FlowMovie_SetRecMaxTime(86399);
    }

    #if (_DUAL_CARD_FUNC_ == ENABLE)
    if ((UI_GetData(FL_CardStatus) == CARD_REMOVED) && (UI_GetData(FL_Card2Status) == CARD_REMOVED))
    #else
    if (UI_GetData(FL_CardStatus) == CARD_REMOVED)
    #endif
    {
        sprintf(g_RecMaxTimeStr,"%02d:%02d:%02d", 0, 0, 0);
    }
    else
    {
        sprintf(g_RecMaxTimeStr,"%02d:%02d:%02d", g_RecMaxTime/3600,(g_RecMaxTime%3600)/60, (g_RecMaxTime%3600)%60);
    }

    UxStatic_SetData(&UIFlowWndMovie_Static_maxtimeCtrl,STATIC_VALUE,Txt_Pointer(g_RecMaxTimeStr));
    UxCtrl_SetShow(&UIFlowWndMovie_Static_maxtimeCtrl, TRUE);
    #endif
}

void FlowMovie_IconHideMaxRecTime(void)
{
  //  UxCtrl_SetShow(&UIFlowWndMovie_Static_maxtimeCtrl, FALSE);
}

void FlowMovie_IconDrawRecTime(void)
{
    switch (gMovData.State)
    {
    case MOV_ST_REC:
    case MOV_ST_REC | MOV_ST_ZOOM:
        
       
        g_RecCurrTime = FlowMovie_GetRecCurrTime();
        sprintf(g_RecCurrTimeStr,"%02d:%02d:%02d", g_RecCurrTime/3600,(g_RecCurrTime%3600)/60, (g_RecCurrTime%3600)%60);
        UxStatic_SetData(&UIFlowWndMovie_TXT_RECCtrl,STATIC_VALUE,Txt_Pointer(g_RecCurrTimeStr));
        UxCtrl_SetShow(&UIFlowWndMovie_TXT_RECCtrl, TRUE);
        break;
        default:
        UxCtrl_SetShow(&UIFlowWndMovie_TXT_RECCtrl, FALSE);
            break;
    }
}

void FlowMovie_IconDrawDateTime(void)
{
 RTC_DATE    Date;
 RTC_TIME    Time;

    // display Date/Time string in movie mode
    
    Time = rtc_getTime();
    //sprintf(date_str,"%02d-%02d",Date.s.month,Date.s.day);
    //debug_msg("%02d:%02d:%02d\r\n",Time.s.hour,Time.s.minute,Time.s.second);
    UxState_SetData(&UIFlowWndMovie_HMS_Hour_HCtrl,STATE_CURITEM,(Time.s.hour/10));
    UxState_SetData(&UIFlowWndMovie_HMS_Hour_LCtrl,STATE_CURITEM,(Time.s.hour%10));
    UxState_SetData(&UIFlowWndMovie_HMS_Min_HCtrl,STATE_CURITEM,(Time.s.minute/10));
    UxState_SetData(&UIFlowWndMovie_HMS_Min_LCtrl,STATE_CURITEM,(Time.s.minute%10));
    UxState_SetData(&UIFlowWndMovie_HMS_Sec_HCtrl,STATE_CURITEM,(Time.s.second/10));
    UxState_SetData(&UIFlowWndMovie_HMS_Sec_LCtrl,STATE_CURITEM,(Time.s.second%10));
    UxCtrl_SetShow(&UIFlowWndMovie_HMSCtrl,TRUE);
    
}

void FlowMovie_IconHideDateTime(void)
{
    UxCtrl_SetShow(&UIFlowWndMovie_HMSCtrl,FALSE);
    
}

void FlowMovie_IconDrawSize(void)
{
 VControl *pCtrl = &UIFlowWndMovie_ResolutionCtrl;

    if (SysGetFlag(FL_MOVIE_DUAL_REC))
    {
        UxStatic_SetData(pCtrl,STATIC_VALUE,Txt_Pointer(resolution_dual_Buf[SysGetFlag(FL_MOVIE_SIZE_DUAL)]));
    }
    else
    {
        UxStatic_SetData(pCtrl,STATIC_VALUE,Txt_Pointer(resolution_Buf[SysGetFlag(FL_MOVIE_SIZE)]));
    }
    UxCtrl_SetShow(pCtrl, TRUE);
}

void FlowMovie_IconHideSize(void)
{
    UxCtrl_SetShow(&UIFlowWndMovie_ResolutionCtrl, FALSE);
}


void FlowMovie_IconDrawEV(void)
{
    //UxState_SetData(&UIFlowWndMovie_StatusICN_EVCtrl,STATE_CURITEM,SysGetFlag(FL_EV));
    //UxCtrl_SetShow(&UIFlowWndMovie_StatusICN_EVCtrl,TRUE);
}

void FlowMovie_IconHideEV(void)
{
    //UxCtrl_SetShow(&UIFlowWndMovie_StatusICN_EVCtrl,FALSE);
}

void FlowMovie_IconDrawStorage(void)
{
 VControl *pCtrl=&UIFlowWndMovie_Status_StorageCtrl;

    /* Update status item data */
    #if (_DUAL_CARD_FUNC_ == ENABLE)
    if ((UI_GetData(FL_CardStatus) == CARD_REMOVED) && (UI_GetData(FL_Card2Status) == CARD_REMOVED))
    {
        UxState_SetData(pCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Storage_ICONID_NULL);
    } else if ((UI_GetData(FL_CardStatus) == CARD_LOCKED) || (UI_GetData(FL_Card2Status) == CARD_LOCKED)) {
        UxState_SetData(pCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Storage_ICON_SD_LOCK);
    } else {
        UxState_SetData(pCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Storage_ICON_SD_CARD);
    }
    #else
    if (UI_GetData(FL_CardStatus) == CARD_INSERTED)
    {
        UxState_SetData(pCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Storage_ICON_SD_CARD);
    } else {
        UxState_SetData(pCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Storage_ICONID_NULL);
    }
    #endif

    UxCtrl_SetShow(pCtrl, TRUE);
}

void FlowMovie_IconHideStorage(void)
{
    UxCtrl_SetShow(&UIFlowWndMovie_Status_StorageCtrl, FALSE);
}



void FlowMovie_IconDrawCyclicRec(void)
{
   // UxState_SetData(&UIFlowWndMovie_Status_CyclicRecCtrl,STATE_CURITEM,SysGetFlag(FL_MOVIE_CYCLIC_REC));
   // UxCtrl_SetShow(&UIFlowWndMovie_Status_CyclicRecCtrl, TRUE);
}

void FlowMovie_IconHideCyclicRec(void)
{
   // UxCtrl_SetShow(&UIFlowWndMovie_Status_CyclicRecCtrl, FALSE);
}

void FlowMovie_IconDrawHDR(void)
{
    //UxState_SetData(&UIFlowWndMovie_Status_HDRCtrl,STATE_CURITEM,SysGetFlag(FL_MOVIE_HDR));
    //UxCtrl_SetShow(&UIFlowWndMovie_Status_HDRCtrl, TRUE);
}

void FlowMovie_IconHideHDR(void)
{
   // UxCtrl_SetShow(&UIFlowWndMovie_Status_HDRCtrl, FALSE);
}

void FlowMovie_IconDrawMotionDet(void)
{
    //UxState_SetData(&UIFlowWndMovie_Status_MotionDetCtrl,STATE_CURITEM,SysGetFlag(FL_MOVIE_MOTION_DET));
    //UxCtrl_SetShow(&UIFlowWndMovie_Status_MotionDetCtrl, TRUE);
}

void FlowMovie_IconHideMotionDet(void)
{
    //UxCtrl_SetShow(&UIFlowWndMovie_Status_MotionDetCtrl, FALSE);
}

void FlowMovie_IconDrawBattery(void)
{
    UxState_SetData(&UIFlowWndMovie_Status_batteryCtrl,STATE_CURITEM,GetBatteryLevel());
    UxCtrl_SetShow(&UIFlowWndMovie_Status_batteryCtrl,TRUE);
}

void FlowMovie_IconHideBattery(void)
{
    UxCtrl_SetShow(&UIFlowWndMovie_Status_batteryCtrl,FALSE);
}

void FlowMovie_IconDrawDZoom(void)
{
 BOOL   bShow;
// VControl *pCtrl = &UIFlowWndMovie_Zoom_StaticCtrl;

 //   UxStatic_SetData(pCtrl,STATIC_VALUE,Txt_Pointer(Get_DZoomRatioString()));
 //   bShow = (DZOOM_IDX_GET() > DZOOM_IDX_MIN())? TRUE : FALSE;
 //   UxCtrl_SetShow(pCtrl,bShow);
}

void FlowMovie_IconHideDZoom(void)
{
   // UxCtrl_SetShow(&UIFlowWndMovie_Zoom_StaticCtrl,FALSE);
}

void FlowMovie_DrawPIM(BOOL bDraw)
{
   // UxCtrl_SetShow(&UIFlowWndMovie_StaticIcon_PIMCCtrl, bDraw);
}

void FlowMovie_IconDrawLED(void)
{
  //  if(SysGetFlag(FL_LEDSET) == LED_OFF)
  //  UxState_SetData(&UIFlowWndMovie_Status_LEDCtrl,STATE_CURITEM,UIFlowWndMovie_Status_LED_ICON_IRLED_OFF);
  //  else
 //   UxState_SetData(&UIFlowWndMovie_Status_LEDCtrl,STATE_CURITEM,UIFlowWndMovie_Status_LED_ICON_IRLED_ON);
  //  UxCtrl_SetShow(&UIFlowWndMovie_Status_LEDCtrl, TRUE);
}
void FlowMovie_IconHideLED(void)
{
   // UxCtrl_SetShow(&UIFlowWndMovie_Status_LEDCtrl, FALSE);
}

void FlowMovie_IconDrawDateStamp(void)
{
    //UxState_SetData(&UIFlowWndMovie_Status_DateStampCtrl,STATE_CURITEM,UI_GetData(FL_MOVIE_DATEIMPRINT));
   // UxCtrl_SetShow(&UIFlowWndMovie_Status_DateStampCtrl, TRUE);
}

void FlowMovie_IconHideDateStamp(void)
{
   // UxCtrl_SetShow(&UIFlowWndMovie_Status_DateStampCtrl, FALSE);
}

static char LockFileBuf[16] = {0};
void FlowMovie_IconDrawLockFile(void)
{
UxCtrl_SetShow(&UIFlowWndMovie_LockCtrl, TRUE);

/*
    debug_msg("FlowMovie_IconDrawLockFile..\r\n");
    sprintf(LockFileBuf,"LOCK");
        UxStatic_SetData(&UIFlowWndMovie_Txt_DistanceCtrl,STATIC_VALUE,Txt_Pointer(LockFileBuf));
    UxCtrl_SetShow(&UIFlowWndMovie_Txt_DistanceCtrl, TRUE);
    */
}

void FlowMovie_IconHideLockFile(void)
{
    UxCtrl_SetShow(&UIFlowWndMovie_LockCtrl, FALSE);
}

void FlowMovie_IconDrawGsensor(void)
{
    //UxState_SetData(&UIFlowWndMovie_Status_GSENSORCtrl,STATE_CURITEM,UI_GetData(FL_MOVIE_GSENSOR));
    //UxCtrl_SetShow(&UIFlowWndMovie_Status_GSENSORCtrl, TRUE);
}

void FlowMovie_IconHideGsensor(void)
{
    //UxCtrl_SetShow(&UIFlowWndMovie_Status_GSENSORCtrl, FALSE);
}

void FlowMovie_IconDrawPlateNumber(void)
{
#if MARK
	static char CarNoBuf[16] = {0};
	if (SysGetFlag(FL_CAR_NUM) == CAR_NUM_ON) {
		if (SysGetFlag(FL_LANGUAGE) == LANG_SC) { 
			strncpy(CarNoBuf, SysGetZHCarNoStamp(), 16);
			if (CarNoBuf[0]<1 || CarNoBuf[0]>32)
			{
				CarNoBuf[0] = 2;
				strcpy(CarNoBuf+1, SysGetNZHCarNoStamp());
				SysSetZHCarNoStamp(CarNoBuf);
			}
			UxState_SetData(&UIFlowWndMovie_Status_ZHCarNoCtrl,STATE_CURITEM,CarNoBuf[0]);
			UxCtrl_SetShow(&UIFlowWndMovie_Status_ZHCarNoCtrl,TRUE);

                    UxStatic_SetData(&UIFlowWndMovie_CarNo_StaticCtrl,STATIC_VALUE,Txt_Pointer(&CarNoBuf[1]));
                    UxCtrl_SetShow(&UIFlowWndMovie_CarNo_StaticCtrl,TRUE);
		}
		else
		{
              UxStatic_SetData(&UIFlowWndMovie_CarNo_StaticCtrl,STATIC_VALUE,Txt_Pointer(SysGetNZHCarNoStamp()));
    		UxCtrl_SetShow(&UIFlowWndMovie_CarNo_StaticCtrl,TRUE);
              UxCtrl_SetShow(&UIFlowWndMovie_Status_ZHCarNoCtrl,FALSE);
		}
	}
	else
	{
        UxCtrl_SetShow(&UIFlowWndMovie_Status_ZHCarNoCtrl,FALSE);
        UxCtrl_SetShow(&UIFlowWndMovie_CarNo_StaticCtrl,FALSE);
	}
	#endif
}

void FlowMovie_IconHidePlateNumber(void)
{
        //UxCtrl_SetShow(&UIFlowWndMovie_Status_ZHCarNoCtrl,FALSE);
       // UxCtrl_SetShow(&UIFlowWndMovie_CarNo_StaticCtrl,FALSE);
}

void FlowMovie_IconDrawTimeLapes(void)
{
/*
    if(UI_GetData(FL_MOVIE_TIMELAPSE_REC)!=MOVIE_TIMELAPSEREC_OFF){
    		UxState_SetData(&UIFlowWndMovie_Status_TimeLapesCtrl,STATE_CURITEM,UIFlowWndMovie_Status_TimeLapes_ICON_TIMELAPSE_REC_STATUS);
    		UxCtrl_SetShow(&UIFlowWndMovie_Status_TimeLapesCtrl, TRUE);
    }
    else
    {
    		UxCtrl_SetShow(&UIFlowWndMovie_Status_TimeLapesCtrl, FALSE);
	}
	*/
}
void FlowMovie_IconDrawParkingMonitor(void)
{
   // UxState_SetData(&UIFlowWndMovie_Status_ParkingMonitorCtrl,STATE_CURITEM,UI_GetData(FL_MOVIE_PARKING));
    
 //   UxCtrl_SetShow(&UIFlowWndMovie_Status_ParkingMonitorCtrl, TRUE);
}

void FlowMovie_IconHideParkingMonitor(void)
{
   // UxCtrl_SetShow(&UIFlowWndMovie_Status_ParkingMonitorCtrl, FALSE);
}

void FlowMovie_IconDrawGPS(void)
{
    UxCtrl_SetShow(&UIFlowWndMovie_Icon_GPSCtrl, TRUE);
}

void FlowMovie_IconHideGPS(void)
{
    UxCtrl_SetShow(&UIFlowWndMovie_Icon_GPSCtrl, FALSE);
}
void FlowMovie_IconDrawAudioOnOff(void)
{

    UxState_SetData(&UIFlowWndMovie_AudioCtrl,STATE_CURITEM,!UI_GetData(FL_MOVIE_AUDIO));
    UxCtrl_SetShow(&UIFlowWndMovie_AudioCtrl, TRUE);
    
}

void FlowMovie_IconHideAudioOnOff(void)
{
    UxCtrl_SetShow(&UIFlowWndMovie_AudioCtrl, FALSE);
}



void FlowMovie_InitEdogIcon(BOOL bShow)
{
/*
	if(bShow)
	{		
	  	FlowMovie_IconDrawGPS();
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	//clean last 
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,TRUE);	//clean last 	
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);	//clean last 
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);	//clean last 
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);	//clean last 	
	}
	else
	{		
	  	FlowMovie_IconHideGPS();	      	
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	//clean last 
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,FALSE);	//clean last 	
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);	//clean last 
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);	//clean last 
	      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);	//clean last 
	}		
	*/
}

void FlowMovie_ShowAllEdogIcon()
{
/*
      debug_msg("FlowMovie_ShowAllEdogIcon..\r\n");

	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	 
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,TRUE);		
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);	
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);	
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);	
	UxCtrl_SetShow(&UFlowwndMovie_StatusICON_UintCtrl,TRUE);	
 
	
      UxCtrl_SetShow(&UFlowwndMovie_StatusICON_DerectionCtrl,TRUE);	
	UxCtrl_SetShow(&UIFlowWndMovie_StatusTXT_WeekCtrl, TRUE);	  

      UxCtrl_SetShow(&UIFlowwndMovie_Panel_SpeedLimitCtrl,FALSE);	  
      UxCtrl_SetShow(&UIFlowwndMovie_Panel_RadarStatusCtrl,FALSE);	
      if(uiCurrentWarningType!=UFlowwndMovie_StatusICON_WarningType_ICONID_NULL)	
      	{
      		UxCtrl_SetShow(&UIFlowwndMovie_Panel_WarningTypeCtrl,TRUE);	
      	}
      else	  
      	{
      		UxCtrl_SetShow(&UIFlowwndMovie_Panel_WarningTypeCtrl,FALSE);	
      	}	  	
	//if(gbQuickMute==TRUE)
      	//UxState_SetData(&UIFlowWndMovie_Status_VolumeCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Volume_ICON_VOL_OFF);
	//else
    	//UxState_SetData(&UIFlowWndMovie_Status_VolumeCtrl,STATE_CURITEM,SysGetFlag(FL_EDOGVOLUME)+1);	  
      UxCtrl_SetShow(&UIFlowWndMovie_Status_VolumeCtrl,FALSE);	

      UxCtrl_SetShow(&UIFlowWndMovie_Status_GPSCtrl, TRUE);
      UxCtrl_SetShow(&UIFlowWndMovie_Status_RadarCtrl, TRUE);
      UxCtrl_SetShow(&UIFlowWndMovie_Status_GPRSCtrl, TRUE);	  	  
	  */
}
void FlowMovie_ClearAllEdogIcon()
{
/*
      debug_msg("FlowMovie_ClearAllEdogIcon..\r\n");
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	 
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,FALSE);		
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);	
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);	
	UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);	
	UxCtrl_SetShow(&UFlowwndMovie_StatusICON_UintCtrl,FALSE);	

      UxCtrl_SetShow(&UFlowwndMovie_StatusICON_DerectionCtrl,FALSE);	
	UxCtrl_SetShow(&UIFlowWndMovie_StatusTXT_WeekCtrl, FALSE);	  

      UxCtrl_SetShow(&UIFlowwndMovie_Panel_SpeedLimitCtrl,FALSE);	  
      UxCtrl_SetShow(&UIFlowwndMovie_Panel_RadarStatusCtrl,FALSE);	
      UxCtrl_SetShow(&UIFlowwndMovie_Panel_WarningTypeCtrl,FALSE);	
	  
      UxCtrl_SetShow(&UIFlowWndMovie_Status_VolumeCtrl,FALSE);	
      UxCtrl_SetShow(&UIFlowWndMovie_Status_GPSCtrl, FALSE);
      UxCtrl_SetShow(&UIFlowWndMovie_Status_RadarCtrl, FALSE);
      UxCtrl_SetShow(&UIFlowWndMovie_Status_GPRSCtrl, FALSE);	  	  
	  */
}


void FlowMovie_DrawEdogGPSStatusIcon(EDOG_INFO *pEdogInfo)
{	
#if 0
    //char EdogCurrentGPSStatus='V';
    //static char EdogLastGPSStatus;	
    static UINT32 counter=1;
    if(gMovData.State==MOV_ST_MENU)
	return ;
    //if(EdogCurrentGPSStatus!=EdogLastGPSStatus)
    {
	    if(pEdogInfo->CommandG.SatStatus=='A')
	    {
	    		UxState_SetData(&UIFlowWndMovie_Status_GPSCtrl,STATE_CURITEM,UIFlowWndMovie_Status_GPS_ICON_GPS_OK);
	    		UxCtrl_SetShow(&UIFlowWndMovie_Status_GPSCtrl, TRUE);  
	    }
	    else
	    {
	    		debug_msg("GPS Status %d ..\r\n",counter);
	    		UxState_SetData(&UIFlowWndMovie_Status_GPSCtrl,STATE_CURITEM,counter);
	    		UxCtrl_SetShow(&UIFlowWndMovie_Status_GPSCtrl, TRUE); 
	    		counter++;								
			if(counter==UIFlowWndMovie_Status_GPS_ICON_GPS_OK)
			  counter=UIFlowWndMovie_Status_GPS_ICON_GPS_LEVEL0;
	    }    
	//EdogLastGPSStatus=EdogCurrentGPSStatus;
    }
    #endif
}

void FlowMovie_HideEdogGPSStatusIcon(void)
{
    //	UxCtrl_SetShow(&UIFlowWndMovie_Status_GPSCtrl, FALSE); 
}

#define EDOG_SPEED_LIMIT   (220)
void FlowMovie_DrawEdogSpeedIcon(EDOG_INFO *pEdogInfo)
{
#if 0
    UINT32 SpeedTotal;
    UINT32 SpeedTotal1,SpeedTotal2,SpeedTotal3;
    static UINT32 SpeedTmp;

    if(gMovData.State==MOV_ST_MENU)
	return ;
#if(FW_TEST==ENABLE)	
	SpeedTotal = SpeedTmp;//
#else
	SpeedTotal = pEdogInfo->CommandG.Speed;//SpeedTmp;//
#endif
      if(SpeedTotal>EDOG_SPEED_LIMIT)
	  SpeedTmp=0;
	SpeedTotal1=SpeedTotal/100;
	if((SpeedTotal1<0)||(SpeedTotal1>9))
	  SpeedTotal1=0;
	SpeedTotal2=SpeedTotal%100;	
	SpeedTotal2=SpeedTotal2/10;
	if((SpeedTotal2<0)||(SpeedTotal2>9))
	  SpeedTotal2=0;	
	SpeedTotal3=(SpeedTotal%100)%10;	
	if((SpeedTotal3<0)||(SpeedTotal3>9))
	  SpeedTotal3=0;	
	//debug_msg("SpeedTotal:%d,SpeedTotal1:%d,SpeedTotal2:%d,SpeedTotal3:%d\r\n",SpeedTotal,SpeedTotal1,SpeedTotal2,SpeedTotal3);
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,FALSE);	//clean last 	
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);	//clean last 

    if((SpeedTotal1==0)&&(SpeedTotal2==0)&&(SpeedTotal3==0))
     {
    		UxState_SetData(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,STATE_CURITEM,SpeedTotal3);
     }
     else if((SpeedTotal1==0)&&(SpeedTotal2==0)&&(SpeedTotal3!=0))
     {
    		UxState_SetData(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,STATE_CURITEM,SpeedTotal3);
	}
     else if((SpeedTotal1==0)&&(SpeedTotal2!=0))
     {
    		UxState_SetData(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,STATE_CURITEM,SpeedTotal2);
    		UxState_SetData(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,STATE_CURITEM,SpeedTotal3);			
	}	 
    else if(SpeedTotal1!=0)
	{
    	UxState_SetData(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,STATE_CURITEM,SpeedTotal1);
    	UxState_SetData(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,STATE_CURITEM,SpeedTotal2);
    	UxState_SetData(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,STATE_CURITEM,SpeedTotal3);
	}
	
    if((SpeedTotal1==0)&&(SpeedTotal2==0)&&(SpeedTotal3==0))
    {
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,TRUE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);	
    }
    else if((SpeedTotal1==0)&&(SpeedTotal2==0)&&(SpeedTotal3!=0))
    {
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);		
    }
    else if((SpeedTotal1==0)&&(SpeedTotal2!=0))
    {
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,TRUE);		
    }
    else if(SpeedTotal1!=0)
    {
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,TRUE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);		
    }		
#if(FW_TEST==ENABLE)		
    SpeedTmp+=5;
#endif	
#endif
}

void FlowMovie_HideEdogSpeedIcon()
{
#if 0
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_1Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_2Ctrl,FALSE);	//clean last 	
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_3Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_4Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Speed_5Ctrl,FALSE);	//clean last 
      #endif
}

void FlowMovie_DrawEdogSpeedLimitIocn(EDOG_INFO *pEdogInfo)
{
#if 0
    UINT32 SpeedLimitTotal;
    UINT32 SpeedLimitTotal1,SpeedLimitTotal2,SpeedLimitTotal3;
    static UINT32 SpeedTmp;
#if(FW_TEST==ENABLE)		
	SpeedLimitTotal = SpeedTmp;//
#else
	SpeedLimitTotal = pEdogInfo->CommandG.SpeedLimit;//SpeedTmp;//
#endif	
      if(SpeedLimitTotal>EDOG_SPEED_LIMIT)
	  SpeedLimitTotal=SpeedTmp=0;
	  
	SpeedLimitTotal1=SpeedLimitTotal/100;
	if((SpeedLimitTotal1<0)||(SpeedLimitTotal1>9))
	  SpeedLimitTotal1=0;
	SpeedLimitTotal2=SpeedLimitTotal%100;	
	SpeedLimitTotal2=SpeedLimitTotal2/10;
	if((SpeedLimitTotal2<0)||(SpeedLimitTotal2>9))
	  SpeedLimitTotal2=0;	
	SpeedLimitTotal3=(SpeedLimitTotal%100)%10;	
	if((SpeedLimitTotal3<0)||(SpeedLimitTotal3>9))
	  SpeedLimitTotal3=0;	

	if(SpeedLimitTotal==0)
	{
      		UxCtrl_SetShow(&UIFlowwndMovie_Panel_SpeedLimitCtrl,FALSE);
	}
	else
	{
      		UxCtrl_SetShow(&UIFlowwndMovie_Panel_SpeedLimitCtrl,TRUE);
	}		
		
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_1Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_2Ctrl,FALSE);	//clean last 	
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_3Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_4Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_5Ctrl,FALSE);	//clean last 

    if((SpeedLimitTotal1==0)&&(SpeedLimitTotal2==0)&&(SpeedLimitTotal3==0))
     {
    		UxState_SetData(&UIFlowwndMovie_StatusICON_SpeedLimit_2Ctrl,STATE_CURITEM,SpeedLimitTotal3);
     }
     else if((SpeedLimitTotal1==0)&&(SpeedLimitTotal2==0)&&(SpeedLimitTotal3!=0))
     {
    		UxState_SetData(&UIFlowwndMovie_StatusICON_SpeedLimit_2Ctrl,STATE_CURITEM,SpeedLimitTotal3);
	}
     else if((SpeedLimitTotal1==0)&&(SpeedLimitTotal2!=0))
     {
    		UxState_SetData(&UIFlowwndMovie_StatusICON_SpeedLimit_4Ctrl,STATE_CURITEM,SpeedLimitTotal2);
    		UxState_SetData(&UIFlowwndMovie_StatusICON_SpeedLimit_5Ctrl,STATE_CURITEM,SpeedLimitTotal3);			
	}	 
    else if(SpeedLimitTotal1!=0)
	{
    	UxState_SetData(&UIFlowwndMovie_StatusICON_SpeedLimit_1Ctrl,STATE_CURITEM,SpeedLimitTotal1);
    	UxState_SetData(&UIFlowwndMovie_StatusICON_SpeedLimit_2Ctrl,STATE_CURITEM,SpeedLimitTotal2);
    	UxState_SetData(&UIFlowwndMovie_StatusICON_SpeedLimit_3Ctrl,STATE_CURITEM,SpeedLimitTotal3);
	}
	
    if((SpeedLimitTotal1==0)&&(SpeedLimitTotal2==0)&&(SpeedLimitTotal3==0))
    {
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_1Ctrl,FALSE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_2Ctrl,TRUE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_5Ctrl,FALSE);	
    }
    else if((SpeedLimitTotal1==0)&&(SpeedLimitTotal2==0)&&(SpeedLimitTotal3!=0))
    {
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_1Ctrl,FALSE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_2Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_5Ctrl,FALSE);		
    }
    else if((SpeedLimitTotal1==0)&&(SpeedLimitTotal2!=0))
    {
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_1Ctrl,FALSE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_4Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_5Ctrl,TRUE);		
    }
    else if(SpeedLimitTotal1!=0)
    {
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_1Ctrl,TRUE);	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_3Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_2Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_4Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_SpeedLimit_5Ctrl,FALSE);		
    }		
#if(FW_TEST==ENABLE)			
    SpeedTmp+=10;	  
#endif    
#endif
}

void FlowMovie_HideEdogSpeedLimitIocn()
{
   //   UxCtrl_SetShow(&UIFlowwndMovie_Panel_SpeedLimitCtrl,FALSE);

}

void FlowMovie_DrawEdogDistanceIocn(EDOG_INFO *pEdogInfo)
{
#if 0
	UINT32  LongTotal,LongTemp1,LongTemp2,LongTemp3,LongTemp4;
      static UINT32 DistanceTmp=1000;
	  
      LongTemp1= pEdogInfo->CommandG.Distance1;
      LongTemp2= pEdogInfo->CommandG.Distance2;
#if(FW_TEST==ENABLE)				  
      LongTotal=DistanceTmp;//
#else
      LongTotal=(LongTemp2<<8)|(LongTemp1&0xff);//DistanceTmp;//
#endif
	LongTemp1=LongTotal/1000;
	LongTemp2=(LongTotal%1000)/100;	
	LongTemp3=((LongTotal%1000)%100)/10;
	LongTemp4=((LongTotal%1000)%100)%10;

    //debug_msg("distance:%d..\r\n",LongTotal);	
    if((LongTemp1==0)&&(LongTemp2==0)&&(LongTemp3==0)&&(LongTemp4==0))
    {	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_1Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,TRUE);    
    }
    else if((LongTemp1==0)&&(LongTemp2==0)&&(LongTemp3==0)&&(LongTemp4!=0))
    {	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_1Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,TRUE);    
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,STATE_CURITEM,LongTemp4);	
    }
    else if((LongTemp1==0)&&(LongTemp2==0)&&(LongTemp3!=0))
    {	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_1Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,TRUE);  
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,STATE_CURITEM,LongTemp3);	
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,STATE_CURITEM,LongTemp4);		
    }
    else if((LongTemp1==0)&&(LongTemp2!=0))
    {	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_1Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_2Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,TRUE);  
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_2Ctrl,STATE_CURITEM,LongTemp2);		
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,STATE_CURITEM,LongTemp3);	
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,STATE_CURITEM,LongTemp4);		
    }
    else if((LongTemp1!=0))
    {	
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_1Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_2Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,TRUE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,TRUE);  
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_1Ctrl,STATE_CURITEM,LongTemp1);		
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_2Ctrl,STATE_CURITEM,LongTemp2);		
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,STATE_CURITEM,LongTemp3);	
    UxState_SetData(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,STATE_CURITEM,LongTemp4);		
    }
    UxCtrl_SetShow(&UIFlowWndMovie_Static_Uint_MCtrl,TRUE);
#if(FW_TEST==ENABLE)				  	
    DistanceTmp-=50;	
    if(DistanceTmp==0)
	  DistanceTmp=1000;	
#endif	
#endif
}

void FlowMovie_HideEdogDistanceIocn()
{
#if 0
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_1Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_2Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_3Ctrl,FALSE);
    UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Distance_4Ctrl,FALSE);  
    UxCtrl_SetShow(&UIFlowWndMovie_Static_Uint_MCtrl,FALSE);
    #endif
	
}

void FlowMovie_DrawEdogDerectionIocn(EDOG_INFO *pEdogInfo)
{
#if 0
	UINT32 uiCurrentDegrees;	
	static UINT32 uiLastDegrees=0XFF,test=0;	
#if(FW_TEST==ENABLE)				  		
	uiCurrentDegrees=test;//
#else
	uiCurrentDegrees=pEdogInfo->CommandG.Direction-1;	//test;//
#endif
	if((uiCurrentDegrees<0)||(uiCurrentDegrees>UFlowwndMovie_StatusICON_Derection_MAX))
	uiCurrentDegrees=0;
	
       if(gMovData.State==MOV_ST_MENU)
	return ;	
	   
	if(uiCurrentDegrees!=uiLastDegrees)
	{
    		UxState_SetData(&UFlowwndMovie_StatusICON_DerectionCtrl,STATE_CURITEM,uiCurrentDegrees);
		uiLastDegrees=uiCurrentDegrees;
	}
#if(FW_TEST==ENABLE)				  			
	test++;	
	if(test==UFlowwndMovie_StatusICON_Derection_MAX)
	test=0;
#endif	
#endif
}

void FlowMovie_HideEdogDerectionIocn()
{
   // UxCtrl_SetShow(&UFlowwndMovie_StatusICON_DerectionCtrl,FALSE);
}

void FlowMovie_DrawEdogGPRSStatus(EDOG_INFO *pEdogInfo)
{
#if 0
	UINT32 uiGPRSStatus;
	uiGPRSStatus=pEdogInfo->CommandC.GPRSStatus;
	{
		if((uiGPRSStatus&0x08)==0x08)
		{
    			UxState_SetData(&UIFlowWndMovie_Status_GPRSCtrl,STATE_CURITEM,UIFlowWndMovie_Status_GPRS_ICON_GPRS_OK);
      			UxCtrl_SetShow(&UIFlowWndMovie_Status_GPRSCtrl,TRUE);					
		}	
		else if((uiGPRSStatus&0x01)==0x01)
		{
    			UxState_SetData(&UIFlowWndMovie_Status_GPRSCtrl,STATE_CURITEM,UIFlowWndMovie_Status_GPRS_ICON_GPRS_CONNECT);
      			UxCtrl_SetShow(&UIFlowWndMovie_Status_GPRSCtrl,TRUE);	
			if((uiGPRSStatus&0x02)==0x02)
			{
	    			UxState_SetData(&UIFlowWndMovie_Status_GPRSCtrl,STATE_CURITEM,UIFlowWndMovie_Status_GPRS_ICON_GPRS_DOWNLOAD);
	      			UxCtrl_SetShow(&UIFlowWndMovie_Status_GPRSCtrl,TRUE);					
			}	
			else if((uiGPRSStatus&0x04)==0x04)
			{
	    			UxState_SetData(&UIFlowWndMovie_Status_GPRSCtrl,STATE_CURITEM,UIFlowWndMovie_Status_GPRS_ICON_GPRS_UPLOAD);
	      			UxCtrl_SetShow(&UIFlowWndMovie_Status_GPRSCtrl,TRUE);					
			}					
		}		
		else
		{
    			UxState_SetData(&UIFlowWndMovie_Status_GPRSCtrl,STATE_CURITEM,UIFlowWndMovie_Status_GPRS_ICON_GPRS_NG);
      			UxCtrl_SetShow(&UIFlowWndMovie_Status_GPRSCtrl,TRUE);					
		}		
	}
    #endif
}

void FlowMovie_HideEdogGPRSStatus()
{
}

void FlowMovie_DrawEdogWarningTypeIocn(EDOG_INFO *pEdogInfo)
{
#if 0
	static UINT32 uiLastWarningType=0xFF,TestType=0;
#if(FW_TEST==ENABLE)		
	uiCurrentWarningType=TestType;//
#else
	uiCurrentWarningType=pEdogInfo->CommandG.WarningType;//TestType;//
#endif
	if((uiCurrentWarningType<UFlowwndMovie_StatusICON_WarningType_ICONID_NULL)||(uiCurrentWarningType>UFlowwndMovie_StatusICON_WarningType_MAX))
		uiCurrentWarningType=UFlowwndMovie_StatusICON_WarningType_ICONID_NULL;
	
       if(gMovData.State==MOV_ST_MENU)
	return ;	
	
	if(uiCurrentWarningType!=uiLastWarningType)
	{
		uiLastWarningType=uiCurrentWarningType;
		//User_UI_ShowLogoFile(uiCurrentWarningType);   

		if(uiCurrentWarningType==UFlowwndMovie_StatusICON_WarningType_ICONID_NULL)
		{
      			UxCtrl_SetShow(&UIFlowwndMovie_Panel_WarningTypeCtrl,FALSE);	
		}
		else if((uiCurrentWarningType>UFlowwndMovie_StatusICON_WarningType_ICON_WARNING_DEFAULT)&&(uiCurrentWarningType<UFlowwndMovie_StatusICON_WarningType_MAX))
		{
    		       UxState_SetData(&UFlowwndMovie_StatusICON_WarningTypeCtrl,STATE_CURITEM,uiCurrentWarningType);		
      			UxCtrl_SetShow(&UIFlowwndMovie_Panel_WarningTypeCtrl,TRUE);	
		}
		else
		{
    			UxState_SetData(&UFlowwndMovie_StatusICON_WarningTypeCtrl,STATE_CURITEM,UFlowwndMovie_StatusICON_WarningType_ICON_WARNING_DEFAULT);
      			UxCtrl_SetShow(&UIFlowwndMovie_Panel_WarningTypeCtrl,TRUE);					
		}		
	}
	if(uiCurrentWarningType!=UFlowwndMovie_StatusICON_WarningType_ICONID_NULL)
	{
		FlowMovie_DrawEdogDistanceIocn(pEdogInfo);				
	}
#if(FW_TEST==ENABLE)			
	TestType++;
	if(TestType==UFlowwndMovie_StatusICON_WarningType_MAX)
		TestType=0;
#endif	
#endif
}

void FlowMovie_HideEdogWarningTypeIocn()
{
	//UxCtrl_SetShow(&UIFlowwndMovie_Panel_WarningTypeCtrl,FALSE);	
}

void FlowMovie_DrawRadarBand(EDOG_INFO *pEdogInfo)
{
#if 0
	UINT32  BandTotal,BandTemp1,BandTemp2,BandTemp3,BandTemp4,BandTemp5;
      static UINT32 BandTmp;
	  
      BandTemp1= pEdogInfo->CommandR.RadarFrequency1;
      BandTemp2= pEdogInfo->CommandR.RadarFrequency2;
#if(FW_TEST==ENABLE)				  
      BandTotal=BandTmp;//
#else
      BandTotal=(BandTemp2<<8)|(BandTemp1&0xff);//BandTmp;//
#endif
	BandTemp1=BandTotal/10000;
	BandTemp2=(BandTotal%10000)/1000;
	BandTemp3=((BandTotal%10000)%1000)/100;	
	BandTemp4=((BandTotal%10000)%1000%100)/10;
	BandTemp5=((BandTotal%10000)%1000%100)%10;

      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band1Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band2Ctrl,FALSE);	//clean last 	
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band3Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band4Ctrl,FALSE);	//clean last 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band5Ctrl,FALSE);	//clean last 
      
      UxState_SetData(&UIFlowwndMovie_StatusICON_Band1Ctrl,STATE_CURITEM,BandTemp1);		
      UxState_SetData(&UIFlowwndMovie_StatusICON_Band2Ctrl,STATE_CURITEM,BandTemp2);		
      UxState_SetData(&UIFlowwndMovie_StatusICON_Band3Ctrl,STATE_CURITEM,BandTemp3);	
      UxState_SetData(&UIFlowwndMovie_StatusICON_Band4Ctrl,STATE_CURITEM,BandTemp4);		
      UxState_SetData(&UIFlowwndMovie_StatusICON_Band5Ctrl,STATE_CURITEM,BandTemp5);	    

      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band1Ctrl,TRUE);
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band2Ctrl,TRUE);	
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band3Ctrl,TRUE);
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band4Ctrl,TRUE); 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band5Ctrl,TRUE);	
      UxCtrl_SetShow(&UIFlowWndMovie_StaticICON_PointCtrl,TRUE);	
#if(FW_TEST==ENABLE)				  	  
    	BandTmp+=50;	
     if(BandTmp>30000)
	 BandTmp=0;	
#endif	 
#endif
}

void FlowMovie_HideRadarBand()
{
#if 0
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band1Ctrl,FALSE);
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band2Ctrl,FALSE);	 	
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band3Ctrl,FALSE);	
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band4Ctrl,FALSE);	 
      UxCtrl_SetShow(&UIFlowwndMovie_StatusICON_Band5Ctrl,FALSE);	
      UxCtrl_SetShow(&UIFlowWndMovie_StaticICON_PointCtrl,FALSE);	
	#endif  
}
void FlowMovie_DrawRadarStatus(EDOG_INFO *pEdogInfo)
{
#if 0
	UINT32 uiCurrentRadarStatus;
	static UINT32 uiLastRadarStatus=0xFF,TestType=0;
	static UINT32 uiCounter;
	
#if(FW_TEST==ENABLE)	
	uiCurrentRadarStatus=TestType;//
#else
	uiCurrentRadarStatus=pEdogInfo->CommandR.RadarBand;//TestType;//
#endif
	if(uiCurrentRadarStatus!=uiLastRadarStatus)
	{
		uiLastRadarStatus=uiCurrentRadarStatus;
		if(uiCurrentRadarStatus==UFlowwndMovie_StatusICON_RadarType_ICONID_NULL)
		{
	      		UxCtrl_SetShow(&UIFlowwndMovie_Panel_RadarStatusCtrl,FALSE);		
    		      UxState_SetData(&UIFlowWndMovie_Status_RadarCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Radar_ICON_RADAR_NG);						
		}
		else if(uiCurrentRadarStatus==UIFlowWndMovie_RadarStatus)
		{
	      		UxCtrl_SetShow(&UIFlowwndMovie_Panel_RadarStatusCtrl,FALSE);		
    		      UxState_SetData(&UIFlowWndMovie_Status_RadarCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Radar_ICON_RADAR_LEVEL3);					
		}
		else
		{
    		      UxState_SetData(&UFlowwndMovie_StatusICON_RadarTypeCtrl,STATE_CURITEM,uiCurrentRadarStatus);		
			FlowMovie_DrawRadarBand(pEdogInfo);		
	      		UxCtrl_SetShow(&UIFlowwndMovie_Panel_RadarStatusCtrl,TRUE);		
    		      UxState_SetData(&UIFlowWndMovie_Status_RadarCtrl,STATE_CURITEM,UIFlowWndMovie_Status_Radar_ICON_RADAR_OK);										
		}
	}

#if(FW_TEST==ENABLE)		
	TestType++;
	if(TestType==UFlowwndMovie_StatusICON_RadarType_MAX)
		TestType=UIFlowWndMovie_RadarStatus;
	if(TestType==UIFlowWndMovie_RadarStatus)
		TestType=0;
#endif	
#endif
}

void FlowMovie_HideRadarStatus()
{
    //UxCtrl_SetShow(&UFlowwndMovie_StatusICON_RadarTypeCtrl,FALSE);
}


void FlowMovie_UpgradeCode(EDOG_INFO *pEdogInfo)
{
	UINT32 ErrorCode;
	ErrorCode=pEdogInfo->EdogUdateType;
	switch(ErrorCode)
	{
		case 0x01:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_LINK_OK,FLOWWRNMSG_TIMER_KEEP);
		 break;
		case 0x02:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATING,FLOWWRNMSG_TIMER_KEEP);
		 break;
		case 0x03:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_DONE,FLOWWRNMSG_TIMER_KEEP);
		 break;	
		case 0x04:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CONTINUSE,FLOWWRNMSG_TIMER_KEEP);
		 break;		 
		case 0x05:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_LINK_DEVICE,FLOWWRNMSG_TIMER_KEEP);
		 break;		 		 
	}
}

void FlowMovie_UpdateErrorCode(EDOG_INFO *pEdogInfo)
{
	UINT32 ErrorCode;
	ErrorCode=pEdogInfo->EdogErrorType;
	switch(ErrorCode)
	{
		case 0x00:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CHECKSUMING,FLOWWRNMSG_TIMER_KEEP);
		 break;
		case 0x01:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR1,FLOWWRNMSG_TIMER_KEEP);
		 break;
		case 0x02:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR2,FLOWWRNMSG_TIMER_KEEP);
		 break;
		case 0x03:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR3,FLOWWRNMSG_TIMER_KEEP);
		 break;	
		case 0x04:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR4,FLOWWRNMSG_TIMER_KEEP);
		 break;		 
		case 0x07:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_READDATA_ERROR,FLOWWRNMSG_TIMER_KEEP);
		 break;		 
		case 0x08:
		 	Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CHECKSUMDATA_ERROR,FLOWWRNMSG_TIMER_KEEP);
		 break;		 
	}
}

void FlowMovie_UpdateEdogInfo_G(EDOG_INFO *pEdogInfo)
{
	FlowMovie_DrawEdogSpeedIcon(pEdogInfo);			
	FlowMovie_DrawEdogGPSStatusIcon(pEdogInfo);			
	FlowMovie_DrawEdogDerectionIocn(pEdogInfo);
	FlowMovie_DrawEdogWarningTypeIocn(pEdogInfo);
	FlowMovie_DrawEdogSpeedLimitIocn(pEdogInfo);
}

void FlowMovie_IconDrawDscMode(void)
{
}
void FlowMovie_IconHideDscMode(void)
{
}

void FlowMovie_UpdateIcons(BOOL bShow)
{
    static BOOL first=TRUE;
    if ((bShow == FALSE) || (SysGetFlag(FL_LCD_DISPLAY) == DISPLAY_OFF))
    {
        FlowMovie_IconHideDscMode();
        FlowMovie_IconHideSize();
        FlowMovie_IconHideMaxRecTime();
        //UxState_SetData(&UIFlowWndMovie_Status_RECCtrl,STATE_CURITEM,UIFlowWndMovie_Status_REC_ICON_TRANSPAENT);
        FlowMovie_IconHideStorage();
        FlowMovie_IconHideCyclicRec();
        FlowMovie_IconHideMotionDet();
        FlowMovie_IconHideDZoom();
        FlowMovie_IconHideBattery();
        FlowMovie_IconHideEV();
        FlowMovie_IconHideDateTime();
        FlowMovie_DrawPIM(FALSE);
	  FlowMovie_IconHideLockFile();
	  FlowMovie_IconHideAudioOnOff();
	  FlowMovie_IconHideGPS();
        FlowMovie_IconHideLED();	
	  FlowMovie_IconHidePlateNumber();		
	  FlowMovie_IconHideDateTime();
	  //FlowMovie_HideEdogSpeedLimitIocn();
	  //FlowMovie_HideEdogSpeedIcon();
	  //FlowMovie_ShowAllEdogIcon();
        //UxCtrl_SetShow(&UIFlowWndMovie_Static_timeCtrl, FALSE);	  
    }
    else
    {
        //FlowMovie_IconDrawDscMode();
        FlowMovie_IconDrawSize();
        FlowMovie_IconDrawMaxRecTime();
       // UxState_SetData(&UIFlowWndMovie_Status_RECCtrl,STATE_CURITEM,UIFlowWndMovie_Status_REC_ICON_TRANSPAENT);
        FlowMovie_IconDrawStorage();
        FlowMovie_IconDrawCyclicRec();
        FlowMovie_IconDrawHDR();
        FlowMovie_IconDrawMotionDet();
        FlowMovie_IconDrawDZoom();
        FlowMovie_IconDrawBattery();
        FlowMovie_IconDrawEV();
        FlowMovie_IconDrawDateTime();
        FlowMovie_DrawPIM(FALSE);
        FlowMovie_IconDrawGsensor();	
		
        if(UIFlowWndMovie_IsGsensorTrig()==TRUE)
	  FlowMovie_IconDrawLockFile();			
	  else	
	  FlowMovie_IconHideLockFile();
	  
        FlowMovie_IconDrawAudioOnOff();	  	
        FlowMovie_IconHideLED();	
        //FlowMovie_IconDrawLED();
        if(SysGetFlag(FL_CAR_NUM)==CAR_NUM_ON)
            FlowMovie_IconDrawPlateNumber();
        else
            FlowMovie_IconHidePlateNumber();

        FlowMovie_IconDrawTimeLapes();

	  FlowMovie_IconDrawParkingMonitor();	
	  FlowMovie_IconDrawDateStamp();
	  FlowMovie_IconDrawRecTime();
        if(gMovData.State != MOV_ST_REC)
        {
            UxCtrl_SetShow(&UIFlowWndMovie_TXT_RECCtrl, FALSE);
            UxCtrl_SetShow(&UIFlowWndMovie_RecPanelCtrl, FALSE);            
         }
        UxCtrl_SetShow(&UIFlowWndMovie_Icon_Radar_WaringCtrl,FALSE);
        UxCtrl_SetShow(&UIFlowWndMovie_Icon_Radar_SingalLvlCtrl,FALSE); 
        UxCtrl_SetShow(&UIFlowWndMovie_DistanceCtrl,FALSE);
        UxCtrl_SetShow(&UIFlowWndMovie_Icon_Speed_limit_PanelCtrl,FALSE);
        UxCtrl_SetShow(&UIFlowWndMovie_GPSDBCtrl,FALSE);
        if(first==TRUE)
        {
            first=FALSE;
            UxCtrl_SetShow(&UIFlowWndMovie_CurSpeed_LCtrl,TRUE);
            UxCtrl_SetShow(&UIFlowWndMovie_CurSpeed_MCtrl,FALSE);
            UxCtrl_SetShow(&UIFlowWndMovie_CurSpeed_HCtrl,FALSE);
            UxCtrl_SetShow(&UIFlowWndMovie_CurSpeedCtrl,TRUE);    
        }
            
         Ux_RedrawAllWind();
    }
}

