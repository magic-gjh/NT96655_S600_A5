////////////////////////////////////////////////////////////////////////////////
#include "SysCommon.h"
#include "AppCommon.h"
////////////////////////////////////////////////////////////////////////////////
#include "UIFrameworkExt.h"
#include "AppLib.h"
#include "UIStorageCheck.h"
#include "FileSysTsk.h"
#include "DeviceCtrl.h"
#include "UIAppMovie.h"
#include "UIAppPhoto.h"
#include "DialogWarn.h"
#include "FlowPhotoParams.h"
#include "DCF.h"
#include "UISetupMapping.h"
#include "DispDef.h" //for NTSC/PAL mode
#include "UIAppNetwork.h"
#include "rtc.h"

#define __MODULE__          UISetupExe
//#define __DBGLVL__ 0        //OFF mode, show nothing
//#define __DBGLVL__ 1        //ERROR mode, show err, wrn only
#define __DBGLVL__ 2        //TRACE mode, show err, wrn, ind, msg and func and ind, msg and func can be filtering by __DBGFLT__ settings
#define __DBGFLT__ "*"      //*=All
#include "DebugModule.h"

//Error message
#define SystemExeErrMsg(...)                debug_msg ("SystemExe: "__VA_ARGS__)
//#NT#2010/11/27Steven feng-begin
#define CAL_CLEAR_FOLDER  "A:\\CalClear"
//#NT#2010/11/27Steven feng-end

extern void UpdateNand_SetFileName(UINT8 *pUpdateFile);
extern void Display_ChangeDevice(int dev_id);
//extern ER copy_iso(void);
//#NT#2011/02/14#Brad Chen -begin
//#NT# format nand
extern void FormatNand(void);
extern ER check_iso(UINT32 addr,UINT32 value,UINT32 Length);
//#NT#2011/02/14#Brad Chen -end
//#NT#2011/02/15 Steven feng-begin
extern void Cal_ItemClearStatus(void);
//#NT#2011/02/15 Steven feng-end

extern BOOL gbQuickMute;

///////////////////////////////////////////////////////////////////////

UINT32 Get_VolumeValue(UINT32 uhIndex)
{
    //#NT#2013/03/05#Lily Kao -begin
    //#NT# new volume range 0 ~ 100
    //#NT# previous setting should not use "AUDIO_GAIN_x"
    #if 1
    switch(uhIndex)
    {
        case BEEP_VOL_1:
            return 25;
        case BEEP_VOL_2:
            return 50;
        case BEEP_VOL_3:
            return 75;
        case BEEP_VOL_MUTE:
            return 0;
        default:
            return 50;
    }
    #else
    switch(uhIndex)
    {
        case BEEP_VOL_1:
            #if BEEP_VOLUME_LOUDER
            return AUDIO_GAIN_4;
            #else
            return AUDIO_GAIN_3;
            #endif
        case BEEP_VOL_2:
            #if BEEP_VOLUME_LOUDER
            return AUDIO_GAIN_6;
            #else
            return AUDIO_GAIN_5;
            #endif
        case BEEP_VOL_3:
            #if BEEP_VOLUME_SMALLER
            return AUDIO_GAIN_6;
            #else
            return AUDIO_GAIN_7;
            #endif
        case BEEP_VOL_MUTE:
            return AUDIO_GAIN_MUTE;
        default:
            return AUDIO_GAIN_5;
    }
    #endif
    //#NT#2013/03/05#Lily Kao -end
}

///////////////////////////////////////////////////////////////////////////
#if USE_FILEDB
#include "FileDB.h"
#include "namerule_fileDB.h"
#endif
INT32 SetupExe_OnFILEDB_FILEID_RESET(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
#if USE_FILEDB
 PFILEDB_FILE_ATTR  pFileAttr;
 int curfilenameLen;
 CHAR FileIndex[8]={0};

    FileDB_Refresh(0);
    if (FileDB_GetTotalFileNum(0))
    {
        pFileAttr = FileDB_CurrFile(0);
        curfilenameLen = strlen(pFileAttr->filename);
        strncpy(FileIndex, pFileAttr->filename+curfilenameLen-7, 3);
        debug_msg("fileid:%d\r\n",atoi(FileIndex));
        NH_FileDB_SetFileID(atoi(FileIndex));
    } else {
        debug_msg("fileid:%d\r\n",0);
        NH_FileDB_SetFileID(0);
    }
#endif
    return NVTEVT_CONSUME;
}
////////////////////////////////////////////////////////////////
static UINT32 LowPowerTimelapseRecTime = 0;

UINT32 Sys_GetDayMaxByDate(struct tm *pDateTime)
{
    UINT32 day_max;

    switch (pDateTime->tm_mon)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        day_max = 30;
        break;
    case 2:
        day_max = ((pDateTime->tm_year % 4) || (pDateTime->tm_year == 2000)) ? 28 : 29;
        break;
    default:
        day_max = 31;
        break;
    }

    return day_max;
}

void Sys_GetDateTimeBySecShift(struct tm *pOriTime, struct tm *pNewTime, UINT32 uiSecShift)
{
    UINT32  year, month, day, hour, min, sec;
    UINT32  day_max, day_add, hour_add, min_add, sec_add;

    // limitation: suppose timelapse time is not over 1 month
    sec_add  = (uiSecShift % 60);
    min_add  = (uiSecShift / 60) % 60;
    hour_add = (uiSecShift / 3600) % 24;
    day_add  = (uiSecShift / 86400);

    sec      = pOriTime->tm_sec  + sec_add;
    min      = pOriTime->tm_min  + min_add;
    hour     = pOriTime->tm_hour + hour_add;
    day      = pOriTime->tm_mday + day_add;
    month    = pOriTime->tm_mon;
    year     = pOriTime->tm_year;

    if (sec >= 60)
        min++;

    if (min >= 60)
        hour++;

    if (hour >= 24)
        day++;

    day_max = Sys_GetDayMaxByDate(pOriTime);

    pNewTime->tm_sec  = sec  % 60;
    pNewTime->tm_min  = min  % 60;
    pNewTime->tm_hour = hour % 24;
    pNewTime->tm_mday = day  % day_max;

    if (day >= day_max)
        month++;

    if (month >= 12)
        year++;

    pNewTime->tm_mon  = month % 12;
    pNewTime->tm_year = year;

    DBG_MSG("Ori: %04d/%02d/%02d %02d:%02d:%02d\r\n",
        pOriTime->tm_year, pOriTime->tm_mon, pOriTime->tm_mday, pOriTime->tm_hour, pOriTime->tm_min, pOriTime->tm_sec);

    DBG_MSG("Add: %d sec, %02d:%02d:%02d:%02d\r\n",
        uiSecShift, day_add, hour_add, min_add, sec_add);

    DBG_MSG("New: %04d/%02d/%02d %02d:%02d:%02d\r\n",
        pNewTime->tm_year, pNewTime->tm_mon, pNewTime->tm_mday, pNewTime->tm_hour, pNewTime->tm_min, pNewTime->tm_sec);
}

INT32 SetupExe_OnLowPowerTimelapseRec(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    struct tm cDateTime;
    struct tm alarmDateTime = {0};

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_LOW_POWER_TIMELAPSE_REC,uhSelect);

    switch(uhSelect)
    {
        case LOW_POWER_TIMELAPSE_REC_5SEC:
            LowPowerTimelapseRecTime = 5;
            break;
        case LOW_POWER_TIMELAPSE_REC_10SEC:
            LowPowerTimelapseRecTime = 10;
            break;
        case LOW_POWER_TIMELAPSE_REC_1MIN:
            LowPowerTimelapseRecTime = 60;
            break;
        case LOW_POWER_TIMELAPSE_REC_5MIN:
            LowPowerTimelapseRecTime = 300;
            break;
        case LOW_POWER_TIMELAPSE_REC_10MIN:
            LowPowerTimelapseRecTime = 600;
            break;
        case LOW_POWER_TIMELAPSE_REC_30MIN:
            LowPowerTimelapseRecTime = 1800;
            break;
        case LOW_POWER_TIMELAPSE_REC_60MIN:
            LowPowerTimelapseRecTime = 3600;
            break;
        default:
            LowPowerTimelapseRecTime = 0;
            break;
    }

    if(LowPowerTimelapseRecTime)
    {
        rtc_waitCSETDone(); //wait for last time write setting to RTC is completed. (EX: date, time, key)

        // get current Date/Time
        cDateTime = HwClock_GetCurrentTime();
        //DBG_MSG("Curr Time %04d/%02d/%02d %02d:%02d:%02d\r\n",
        //    cDateTime.tm_year, cDateTime.tm_mon, cDateTime.tm_mday, cDateTime.tm_hour, cDateTime.tm_min, cDateTime.tm_sec);

        Sys_GetDateTimeBySecShift(&cDateTime, &alarmDateTime, LowPowerTimelapseRecTime);

        //DBG_MSG("Alarm Time %04d/%02d/%02d %02d:%02d:%02d\r\n",
        //    alarmDateTime.tm_year, alarmDateTime.tm_mon, alarmDateTime.tm_mday, alarmDateTime.tm_hour, alarmDateTime.tm_min, alarmDateTime.tm_sec);

        HwClock_SetPowerAlarmTime(alarmDateTime);
        HwClock_EnablePowerAlarm(TRUE);
        alarmDateTime = HwClock_GetPowerAlarmTime();
        rtc_waitCSETDone();

        //DBG_MSG("Get Alarm Time %04d/%02d/%02d %02d:%02d:%02d\r\n",
        //    alarmDateTime.tm_year, alarmDateTime.tm_mon, alarmDateTime.tm_mday, alarmDateTime.tm_hour, alarmDateTime.tm_min, alarmDateTime.tm_sec);

        System_PowerOff(SYS_POWEROFF_NORMAL);
    }

    return NVTEVT_CONSUME;
}
UINT32 GetLowPowerTimelapseRecTime(void)
{
    return LowPowerTimelapseRecTime;
}

////////////////////////////////////////////////////////////////////////
#include "UIBackgroundObj.h"
INT32 SetupExe_OnFormat(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
#if 1
    //debug_msg("[SetupObj] do Format storage\r\n");

    UIStorageCheck_ResetFileReachMax();
    BKG_PostEvent(NVTEVT_BKW_FORMAT);
#else
    Ux_PostEvent(NVTEVT_BACKGROUND_DONE, 1, NVTEVT_BKW_FORMAT);

#endif
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnSlideShowEffect(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
    {
        uhSelect = paramArray[0];
    }

    UI_SetData(FL_SlideShowEffectIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnSlideShowInterval(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
    {
        uhSelect = paramArray[0];
    }

    UI_SetData(FL_SlideShowIntervalIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnSlideShowRepeat(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
    {
        uhSelect = paramArray[0];
    }

    UI_SetData(FL_SlideShowRepeatIndex,uhSelect);

    return NVTEVT_CONSUME;
}

//#NT#2011/01/12#Steven feng -begin
#if ( SLIDESHOW_MUSIC_OPTION ==   ENABLE )
INT32 SetupExe_OnSlideShowMusic(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
    {
        uhSelect = paramArray[0];
    }

    UI_SetData(FL_SlideShowMusicIndex,uhSelect);

    return NVTEVT_CONSUME;
}
#endif
//#NT#2011/01/12#Steven feng -end

///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnBeepVolume(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    if(paramNum>0)
    {
        uhSelect= paramArray[0];
    }

    UI_SetData(FL_BeepVolumnIndex,uhSelect);
    //#Set volumn
    GxSound_SetVolume(Get_VolumeValue(uhSelect));

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnBeepShutter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set Beep Shutter\r\n");
    if(paramNum>0)
    {
        uhSelect= paramArray[0];
    }

    UI_SetData(FL_BeepShutterIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnBeepKey(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set Beep Key\r\n");
    if(paramNum>0)
    {
        uhSelect= paramArray[0];
    }

    UI_SetData(FL_BeepKeyIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnBeepSelftimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set Beep Selftimer\r\n");
    if(paramNum>0)
    {
        uhSelect= paramArray[0];
    }

    UI_SetData(FL_BeepSelftimerIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnBeepPower(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set Beep Power\r\n");
    if(paramNum>0)
    {
        uhSelect= paramArray[0];
    }

    UI_SetData(FL_BeepPowerIndex,uhSelect);

    return NVTEVT_CONSUME;
}


///////////////////////////////////////////////////////////////////
#include "UIResource.h"
#include "UIGraphics.h"
///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnLanguage(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_LANGUAGE,uhSelect);
    if(UI_GetData(FL_LANGUAGE)!=LANG_SC)
    {
        SysSetNZHCarNoStamp(CAR_NUMBER_STAMP_STR);
    }	
    GxGfx_SetStringTable((const STRING_TABLE*)Get_LanguageValue(uhSelect));

    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnFreq(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
 UINT32 uiFreq = 0;

    if (paramNum>0)
        uiFreq = paramArray[0];

    IPL_AlgSetUIInfo(IPL_SEL_FREQUENCY,uiFreq);
    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnChangeDSCMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
 UINT32 uiCurMode,uiChangeTo = 0;
 UINT32 uiType = DSCMODE_CHGTO_NEXT;

    if (paramNum>0)
        uiType = paramArray[0];
    uiCurMode = System_GetState(SYS_STATE_CURRMODE);

    switch(uiType)
    {
      case DSCMODE_CHGTO_NEXT:
            if (PRIMARY_MODE_PHOTO == (INT32)uiCurMode)
            {
                uiChangeTo = PRIMARY_MODE_PLAYBACK;
            } else if (PRIMARY_MODE_MOVIE == (INT32)uiCurMode)
            {
                uiChangeTo = PRIMARY_MODE_PLAYBACK;
            } else if (PRIMARY_MODE_PLAYBACK == (INT32)uiCurMode)
            {
                uiChangeTo = PRIMARY_MODE_MOVIE;
            } else {
                debug_err(("UISystemObj: Unknown current DSC mode 0x%x\r\n", uiCurMode));
            }
        break;
      case DSCMODE_CHGTO_PREV:
        uiChangeTo = UI_GetData(FL_PreMode);
        break;
      case DSCMODE_CHGTO_CURR:
        uiChangeTo = uiCurMode;
        break;
    }

    if (1)//(KeyScan_IsHDMIPlugIn()==FALSE)
    {
        UI_SetData(FL_PreMode,uiCurMode);
        UI_SetData(FL_NextMode,uiChangeTo);
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, uiChangeTo);
    }

    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnForceToLivedMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
  UINT32 uiCurrMode,uiPrevMode;
  VControl *pCloseWnd = NULL;

    uiCurrMode = UI_GetData(FL_NextMode);
    uiPrevMode = UI_GetData(FL_PreMode);

     if ((INT32)uiCurrMode==PRIMARY_MODE_MOVIE||(INT32)uiCurrMode==PRIMARY_MODE_PHOTO)
     {
        /* Close all the window upper than root */
        Ux_GetWindowByIndex(&pCloseWnd, UX_2NDLAYER_WND_IDX);
        if(pCloseWnd)
        {
           Ux_CloseWindow(pCloseWnd, 0);
        }
     } else if ((INT32)uiCurrMode==PRIMARY_MODE_PLAYBACK)
     {
        /* Switch to the previous liveview mode before playback mode */
        /* switch to the previous mode only unpluging HDMI */
        if (1)//(KeyScan_IsHDMIPlugIn()==FALSE)
        {
             UI_SetData(FL_PreMode,PRIMARY_MODE_PLAYBACK);
             UI_SetData(FL_NextMode,PRIMARY_MODE_MOVIE);
             Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);
        }
     } else
     {
        debug_err(("UISetupObj: Unknown current DSC mode 0x%x\r\n", uiCurrMode));
     }
    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnForceToPlaybackMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
  UINT32 uiCurrMode;

    uiCurrMode = UI_GetData(FL_NextMode);

    if ((INT32)uiCurrMode!=PRIMARY_MODE_PLAYBACK)
    {
        UI_SetData(FL_PreMode,uiCurrMode);
        UI_SetData(FL_NextMode,PRIMARY_MODE_PLAYBACK);
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_PLAYBACK);
    }

    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnLCDOff(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    //debug_msg("[SetupObj] LCDOff mode\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_LCDOffIndex,uhSelect);

    switch(uhSelect)
    {
#if 0//(AUTOSLEEP_FUNCTION == ENABLE)
        case LCDOFF_ON:
            GxPower_SetControl(GXPWR_CTRL_SLEEP_EN, FALSE);
        break;
        case LCDOFF_30SEC:
            GxPower_SetControl(GXPWR_CTRL_SLEEP_EN, TRUE);
            //GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_L, 10);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_L, 20);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME, 30);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_D, 30);
        break;
        case LCDOFF_1MIN:
            GxPower_SetControl(GXPWR_CTRL_SLEEP_EN, TRUE);
            //GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_L, 10);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_L, 40);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME, 60);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_D, 60);
        break;
        case LCDOFF_2MIN:
            GxPower_SetControl(GXPWR_CTRL_SLEEP_EN, TRUE);
            //GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_L, 10);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_L, 90);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME, 120);
            GxPower_SetControl(GXPWR_CTRL_SLEEP_TIME_D, 120);
        break;
#else
        case LCDOFF_ON:
            GxCustom_SetControl(GXCUSTOM_CTRL_AUTOLCDOFF_EN, FALSE);
        break;
        case LCDOFF_30SEC:
            GxCustom_SetControl(GXCUSTOM_CTRL_AUTOLCDOFF_EN, TRUE);
            GxCustom_SetControl(GXCUSTOM_CTRL_AUTOLCDOFF_TIME, 30);
        break;
        case LCDOFF_1MIN:
            GxCustom_SetControl(GXCUSTOM_CTRL_AUTOLCDOFF_EN, TRUE);
            GxCustom_SetControl(GXCUSTOM_CTRL_AUTOLCDOFF_TIME, 60);
        break;
        case LCDOFF_2MIN:
            GxCustom_SetControl(GXCUSTOM_CTRL_AUTOLCDOFF_EN, TRUE);
            GxCustom_SetControl(GXCUSTOM_CTRL_AUTOLCDOFF_TIME, 120);
        break;		
#endif
        default:
            SystemExeErrMsg("Error parameter (%d) with SetupExe_OnLCDOff\r\n",uhSelect);
        break;
    }


    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
#include "GxPower.h"
INT32 SetupExe_OnPowerOff(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set PowerOff mode\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_AUTO_POWER_OFF,uhSelect);

    switch(uhSelect)
    {
#if (AUTOPWROFF_FUNCTION == ENABLE)
        case POWER_ON:
            GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_EN, FALSE);
        break;
        case POWER_3MIN:
            GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_EN, TRUE);
            GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_TIME, 180);
        break;
        case POWER_5MIN:
            GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_EN, TRUE);
            GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_TIME, 300);
        break;
        case POWER_10MIN:
            GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_EN, TRUE);
            GxPower_SetControl(GXPWR_CTRL_AUTOPOWEROFF_TIME, 600);
        break;
#endif
        default:
            SystemExeErrMsg("Error parameter (%d) with SetupExe_OnPowerOff\r\n",uhSelect);
        break;
    }

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnDelayOff(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set DelayOff mode\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_DELAYOFF,uhSelect);

    switch(uhSelect)
    {
        case DELAYOFF_OFF:
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_EN, FALSE);
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_RESET, 0);		
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_TIME, 0);
			
        break;
        case DELAYOFF_10SEC:
            debug_msg("DELAYOFF_5SEC================1\r\n");
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_EN, TRUE);
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_TIME, 10);
        break;
        case DELAYOFF_20SEC:
            debug_msg("DELAYOFF_10SEC================1\r\n");
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_EN, TRUE);
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_TIME, 20);
        break;
        case DELAYOFF_30SEC:
            debug_msg("DELAYOFF_30SEC================1\r\n");
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_EN, TRUE);
            GxCustom_SetControl(GXCUSTOM_CTRL_DELAYOFF_TIME, 30);
        break;
        default:
            SystemExeErrMsg("Error parameter (%d) with SetupExe_OnDelayOff\r\n",uhSelect);
        break;
    }

    return NVTEVT_CONSUME;
}

///////////////////////////////////////////////////////////////////

INT32 SetupExe_OnSysReset(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //debug_msg("[SetupObj] do SysReset\r\n");
#if PST_FUNC
    AppBKW_SetData(BKW_WAIT_TIME, 1000);//show wait window for 2 second
    BKG_PostEvent(NVTEVT_BKW_DUMMY_WAIT);
    //#NT#For menu reset flag,for FlowPhoto_InitSettingParams
    UI_SetData(FL_ResetFlag,TRUE);

#if (UI_STYLE==UI_STYLE_DEMO)
    //#NT#2011/03/24#Lincy Lin -begin
    RestorePhotoParamsInfo();
#endif
    //#NT#2011/03/24#Lincy Lin -end
    //#NT#2011/03/25#Lincy Lin -begin
    //#NT#
    UI_SetData(FL_IsInMuseum, FALSE);
    //#NT#2011/03/25#Lincy Lin -end

    //#NT#2010/09/10#Lincy Lin -begin
    //#NT#For special key reset function
    #if SPECIAL_KEY_RESET_FUNC
    if ((GxKey_GetData(GXKEY_NORMAL_KEY) & FLGKEY_ZOOMIN))
    {
        UI_SetData(FL_ResetAllStatus,RESET_ALL_ON);
        UI_SetData(FL_TakePictCnt,0);
        UI_SetData(FL_ModeIndex,0);
        //System_PowerOff(SYS_POWEROFF_NORMAL);
    }
    #endif
    //#NT#2010/09/10#Lincy Lin -end
    //#NT#2014/06/13#KS Hung -begin
    #if ((_DUAL_CARD_FUNC_ == ENABLE) && (_CHIP_ == _CHIP_650_))
    if (SysGetFlag(FL_DualCardMain) == MAIN_CARD_2)
    {
        GxStrg_CloseDevice(0); // Release bus to SPI using
    }
    System_OnStrgInit_PS();
    #endif
    Reset_MenuInfo();
    #if ((_DUAL_CARD_FUNC_ == ENABLE) && (_CHIP_ == _CHIP_650_))
    System_OnStrgExit_PS(); // Release bus to SD card using
    if (SysGetFlag(FL_DualCardMain) == MAIN_CARD_2)
    {
        GxStrg_OpenDevice(0, Dx_GetObject(DX_CLASS_STORAGE_EXT|DX_TYPE_CARD2));
    }
    #endif
    //#NT#2014/06/13#KS Hung -end

    //#NT#2014/06/13#KS Hung -begin
    //#NT#This had been done in Reset_MenuInfo function.
    //Save_MenuInfo();
    //#NT#2014/06/13#KS Hung -end
#else
    Ux_PostEvent(NVTEVT_BACKGROUND_DONE, 1, NVTEVT_BKW_DUMMY_WAIT);
#endif
    return NVTEVT_CONSUME;
}
INT32 SetupExe_OnSysResetNoWin(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    debug_ind(("[SetupObj] do SysReset No Win\r\n"));
#if PST_FUNC
    Reset_MenuInfo();
    Save_MenuInfo();
#endif
    return NVTEVT_CONSUME;
}

///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnPanMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_PanModeIndex,uhSelect);

    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
#include "UIPlayObj.h"

INT32 SetupExe_OnNumReset(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    debug_msg("[SetupObj] do NumReset\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    BKG_PostEvent(NVTEVT_BKW_NUM_RESET);

    return NVTEVT_CONSUME;
}


///////////////////////////////////////////////////////////////////
#include "GxDisplay.h"
INT32 SetupExe_OnBrightAdj(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set LCD Brightness Adjust\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_BrightAdjIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnBrightLvl(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set LCD Brightness Level\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    GxVideo_SetDeviceCtrl(DOUT1, DISPLAY_DEVCTRL_BRIGHTLVL, uhSelect);

    UI_SetData(FL_LCD_BRIGHTNESS,uhSelect);

    return NVTEVT_CONSUME;
}


///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnUSBMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set USB mode\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];
    UI_SetData(FL_USB_MODE,uhSelect);

    return NVTEVT_CONSUME;
}



///////////////////////////////////////////////////////////////////

extern BOOL bDetect_ForceLock;
//#NT#TV change action should be postponed from movie play start to first video frame decoded
extern BOOL    g_bPostponeTVChange;
INT32 SetupExe_OnDisplayDev(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set display device %d\r\n", paramArray[0]);

    if(paramNum>0)
        uhSelect= paramArray[0];
    UI_SetData(FL_DisplayDevIndex,uhSelect);

    switch(uhSelect)
    {
#if _DEMO_TODO
    case PRIMARY_DISPTYPE_TV:
        //debug_msg("switch to TV\r\n");
        //#NT#2010/03/08#Jeah Yen -begin
        //TV plug: �����event�n���檺�ʧ@ (�������������ʧ@, �ýШD���s����)
        //#�ݭn�����ﵦ����]: �аѦ�UI_LockEvent(), UI_UnlockEvent()
        //#NT#2010/03/09#[0011089]Ben Wang -begin
        //#NT#TV change action should be postponed from movie play start to first video frame decoded
        //if(bDetect_ForceLock)
        if(bDetect_ForceLock || g_bPostponeTVChange)
        //#NT#2010/03/09#[0011089]Ben Wang -end
        {
            //Ignore this action, and force TV detect next time
            GxVideo_SetDeviceCtrl(DOUT1, DISPLAY_DEVCTRL_FORCEDETINS, 1);
            return NVTEVT_CONSUME;
        }
        //#NT#2010/03/08#Jeah Yen -end
        Display_ChangeDevice(PRIMARY_DISPTYPE_TV);//change display to TV
        //while display change device or change mode, cannot allow to turn on/off any OSD/VDO
        //but Ux_Redraw() will sometimes turn on/off any OSD/VDO
        break;
    case PRIMARY_DISPTYPE_LCD:
        //debug_msg("switch to LCD\r\n");
        //#NT#2010/03/08#Jeah Yen -begin
        //TV unplug: �����event�n���檺�ʧ@ (�������������ʧ@, �ýШD���s����)
        //#�ݭn�����ﵦ����]: �аѦ�UI_LockEvent(), UI_UnlockEvent()
        if(bDetect_ForceLock)
        {
            //Ignore this action, and force TV detect next time
            GxVideo_SetDeviceCtrl(DOUT1, DISPLAY_DEVCTRL_FORCEDETINS, 1);
            return NVTEVT_CONSUME;
        }
        //#NT#2010/03/08#Jeah Yen -end
        Display_ChangeDevice(PRIMARY_DISPTYPE_LCD);//change display to LCD
        //while display change device or change mode, cannot allow to turn on/off any OSD/VDO
        //but Ux_Redraw() will sometimes turn on/off any OSD/VDO
        break;
#endif
    default:
        SystemExeErrMsg("Error parameter (%d) with SetupExe_OnDisplayDev\r\n",uhSelect);
        break;
    }

    return NVTEVT_CONSUME;
}

extern UINT32 gDevTVObj;

INT32 SetupExe_OnTVFormat(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set TV mode\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];
    UI_SetData(FL_TV_MODE,uhSelect);

    switch(uhSelect)
    {
     case VIDEOOUT_NTSC:
        /*
        Display_ChangeMode(PRIMARY_TVFMT_NTSC); //change TV to NTSC format
        //while display change device or change mode, cannot allow to turn on/off any OSD/VDO
        //but Ux_Redraw() will sometimes turn on/off any OSD/VDO
        */
        //Ux_SendEvent(0, NVTEVT_VIDEO_MODE,2,gDevTVObj,DISP_TVMODE_NTSC);
        Ux_PostEvent(NVTEVT_VIDEO_MODE,2,gDevTVObj,DISP_TVMODE_NTSC);
        break;
    case VIDEOOUT_PAL:
        /*
        Display_ChangeMode(PRIMARY_TVFMT_PAL); //change TV to PAL format
        //while display change device or change mode, cannot allow to turn on/off any OSD/VDO
        //but Ux_Redraw() will sometimes turn on/off any OSD/VDO
        */
        //Ux_SendEvent(0, NVTEVT_VIDEO_MODE,2,gDevTVObj,DISP_TVMODE_PAL);
        Ux_PostEvent(NVTEVT_VIDEO_MODE,2,gDevTVObj,DISP_TVMODE_PAL);
        break;
    default:
        SystemExeErrMsg("Error parameter (%d) with SetupExe_OnTVFormat\r\n",uhSelect);
        break;
    }

    return NVTEVT_CONSUME;
}


INT32 SetupExe_OnLed(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set DelayOff mode\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_LEDSET,uhSelect);

    switch(uhSelect)
    {
        case LED_OFF:
		GPIOMap_TurnOffWhiteLight();						
 		break;
	 case LED_ON:
		GPIOMap_TurnOnWhiteLight();				 	
	 	break;
	 default:
	 	break;
    }

    return NVTEVT_CONSUME;
}

extern UINT32 gDevHDMIObj;

INT32 SetupExe_OnHDMIFormat(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set HDMI mode\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];
    UI_SetData(FL_HDMI_MODE,uhSelect);

    switch(uhSelect)
    {
     case VIDEOOUT2_FHD:
        /*
        Display_ChangeMode(PRIMARY_TVFMT_NTSC); //change TV to NTSC format
        //while display change device or change mode, cannot allow to turn on/off any OSD/VDO
        //but Ux_Redraw() will sometimes turn on/off any OSD/VDO
        */
        //Ux_SendEvent(0, NVTEVT_VIDEO_MODE,2,gDevHDMIObj,DISP_HDMIMODE_1920X1080I60);
        Ux_PostEvent(NVTEVT_VIDEO_MODE,2,gDevHDMIObj,DISP_HDMIMODE_1920X1080I60);
        break;
    case VIDEOOUT2_HD:
        /*
        Display_ChangeMode(PRIMARY_TVFMT_PAL); //change TV to PAL format
        //while display change device or change mode, cannot allow to turn on/off any OSD/VDO
        //but Ux_Redraw() will sometimes turn on/off any OSD/VDO
        */
        //Ux_SendEvent(0, NVTEVT_VIDEO_MODE,2,gDevHDMIObj,DISP_HDMIMODE_720X480P60);
        Ux_PostEvent(NVTEVT_VIDEO_MODE,2,gDevHDMIObj,DISP_HDMIMODE_720X480P60);
        break;
    default:
        SystemExeErrMsg("Error parameter (%d) with SetupExe_OnHDMIFormat\r\n",uhSelect);
        break;
    }

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnDualDisp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
        uhSelect= paramArray[0];
    UI_SetData(FL_DualDisp,uhSelect);
    debug_msg("[SetupObj] set DualDisp %d\r\n",uhSelect);

    return NVTEVT_CONSUME;
}


INT32 SetupExe_OnWifiStart(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    UINT32 result=0;

    if(paramNum>0)
        uhSelect= paramArray[0];
    debug_msg("[SetupObj] set wifi %d %x\r\n",uhSelect,&result);
    UI_SetData(FL_NetWorkMode,uhSelect);

    return NVTEVT_CONSUME;
}
INT32 SetupExe_OnWifiStop(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINet_HFSUnInit();
#if(_NETWORK_ == _NETWORK_SDIO_EVB_WIFI_)
    UINet_WifiUnInit(UI_GetData(FL_NetWorkMode));
#elif(_NETWORK_ == _NETWORK_SPI_EVB_ETHERNET_)
    UINet_LanUnInit(UI_GetData(FL_NetWorkMode));
#endif

    return NVTEVT_CONSUME;
}

///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnDateFormat(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set Date format\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];
    UI_SetData(FL_DateFormatIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnTimeFormat(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    //debug_msg("[SetupObj] set Time format\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];
    UI_SetData(FL_TimeFormatIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnFWUpdate(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //debug_msg("[SetupObj] FW Update\r\n");
    if(paramNum>0)
    {
#if 1
        BKG_PostEvent(NVTEVT_BKW_FW_UPDATE);
#else
        Ux_PostEvent(NVTEVT_BACKGROUND_DONE, 1, NVTEVT_BKW_FW_UPDATE);
#endif
    }
    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnPreviewMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    int curMode = System_GetState(SYS_STATE_CURRMODE);
    //debug_msg("[SetupObj] do Back to Previous mode:%d\r\n",curMode);

    #if 0
    UI_Switch_DscMode(UI_GetData(FL_PreMode),DSCMODE_SWITCH_FORCE,DSCMODE_SWITCHDIR_DONT_CARE);
    #else
    if (curMode ==PRIMARY_MODE_PLAYBACK)
    {
        UI_Switch_DscMode(UI_GetData(FL_PreMode),DSCMODE_SWITCH_FORCE,DSCMODE_SWITCHDIR_DONT_CARE);
    }
    else
    {
        VControl *previewWnd;
        Ux_GetWindowByIndex(&previewWnd,1);
        //close wind untill root window
        Ux_CloseWindow(previewWnd, 0);
    }
    #endif
    return NVTEVT_CONSUME;
}
///////////////////////////////////////////////////////////////////
INT32 SetupExe_OnWallpaperMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    //debug_msg("[SetupObj] SetupExe_OnWallpaper Menu\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_WallpaperMenuIndex,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnWallpaperStartup(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    //debug_msg("[SetupObj] SetupExe_OnWallpaper Startup Screen\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_WallpaperStartupIndex,uhSelect);

    return NVTEVT_CONSUME;

}

INT32 SetupExe_OnWallpaperBack(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    //debug_msg("[SetupObj] Wallpaper Back to default\r\n");

    if(paramNum>0)
        uhSelect= paramArray[0];

    UI_SetData(FL_WallpaperBackIndex,uhSelect);

    return NVTEVT_CONSUME;

}

INT32 SetupExe_OnSetDCFNextID(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 useFileDB =0;
    useFileDB = UI_GetData(FL_IsUseFileDB);

    //#if !USE_FILEDB
    if (useFileDB == 0)
    {
        UINT32     uhFolderId=0, uhFileId=0;
        DCF_GetNextID(&uhFolderId,&uhFileId);

        if(UI_GetData(FL_FileNumbering)== FILE_NUMBER_MODE_CONT )
        {
            UI_SetData(FL_DCF_DIR_ID,uhFolderId);
            UI_SetData(FL_DCF_FILE_ID,uhFileId);
        }

        debug_ind(("NextDirNum = %d, NextFileNum = %d\r\n",UI_GetData(FL_DCF_DIR_ID),UI_GetData(FL_DCF_FILE_ID)));
    }
    return NVTEVT_CONSUME;

}


INT32 SetupExe_OnCopy2Card(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    debug_ind(("[SetupObj] do copy to card\r\n"));

    BKG_PostEvent(NVTEVT_BKW_COPY2CARD);

    return NVTEVT_CONSUME;
}


INT32 SetupExe_OnZone(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    debug_ind(("[SetupObj] Set Zone\r\n"));
    if(paramNum==3)
    {
        UI_SetData(FL_TimeLocaleIndex, paramArray[0]);
        UI_SetData(FL_HomeZoneIndex, paramArray[1]);
        UI_SetData(FL_TravalZoneIndex, paramArray[2]);

    }

    return NVTEVT_CONSUME;
}
INT32 SetupExe_OnPbRetractLens(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    DevCtrl_Lens_Playback_Retract();
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnFileSysInit(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
#if _DEMO_TODO
    //#NT#2010/11/27Steven feng-begin
    UINT32       uiPoolAddr;
    UINT32       uiBufSize = 0 ,status;
    //#NT#2011/02/16#Steven feng -begin
    #if SLIDESHOW_MUSIC_OPTION
    UINT32       i;
    #endif
    //#NT#2011/02/16#Steven feng -end
    //#NT#2010/11/27Steven feng-end
    //debug_msg("[SetupObj] FileSysInit\r\n");
    //#NT#2010/09/28#Lincy Lin -begin
    //#NT#Add check if write Photo frame Pstore when update FW
    if(FlowMode_IsPowerOnUpdateFW())
    {
        FST_FILE filehdl = NULL;
        INT32 ret = FST_STA_ERROR;
        //#NT#2011/01/07#Janice Huang -begin
        //#NT#add warn wind,for Production line ,unplug bettery
        Ux_OpenWindow(&DialogWarnCtrl, 2, WRN_FW_UPDATING, WARN_ALWAYS);
        //#NT#2010/11/04#Lincy Lin -begin
        // delay for AE stable
        SwTimer_DelayMs(100);
        //#NT#2010/11/04#Lincy Lin -end
        UIRes_ChkWritePHFE();

        //#NT#2011/02/14Steven feng-begin
        #if SLIDESHOW_MUSIC_OPTION
        UIRes_ChkWriteSSWAV();
        #endif
        //#NT#2011/02/14Steven feng-end

        //#NT#2010/11/27Steven feng-begin

        uiPoolAddr = OS_GetMempoolAddr(POOL_ID_APP);

        filehdl = FileSys_OpenFile(CAL_CLEAR_FOLDER,FST_OPEN_READ);
        ret = FileSys_ReadFile(filehdl,(UINT8*)uiPoolAddr,&uiBufSize, 0, 0);
        FileSys_CloseFile(filehdl);
        if(ret == FST_STA_OK)
        {
           debug_err(("^G Clear Cal Data & status\r\n"));
           Cal_ItemClearStatus();
        }
        else
           debug_err(("^G Reserve Cal Data & status\r\n"));

        //#NT#2010/11/27Steven feng-end

//#NT#2011/01/28#Brad Chen -begin
//#NT# add burn ISO
        if(_MSDC_MODE_==_MSDC_ALL_NAND2_|| _MSDC_MODE_ == _MSDC_SINGLE_NAND2_)
        {
            ER result = E_OK;
            char        *fileName = "A:\\GEISO.ISO";
            FST_FILE   *pFile;
            UINT32 value = 0X30444301;
            result = copy_iso();
            pFile = FileSys_OpenFile((char *)fileName,FST_OPEN_READ);
            if (pFile != NULL)
            {
                FormatNand();
            }
            else
            {
                debug_err(("open file error\r\n"));
            }

            result = check_iso(0x8000,value,4);
            if (result == E_OK)
            {
                debug_msg(" set AutoRunISOWriteSts OK\r\n");
                UI_SetData(FL_AutoRunISOWriteSts,TRUE);
            }
            else
                debug_msg(" set AutoRunISOWriteSts Fail\r\n");

        }
//#NT#2011/01/28#Brad Chen -end


        Ux_CloseWindow(&DialogWarnCtrl,0);

        UIRes_InitReadPHFE();
        //#NT#2011/02/16#Steven feng -begin
        #if SLIDESHOW_MUSIC_OPTION
        for(i = 0 ; i<4 ; i++)
            UIRes_InitReadSSWAV(i);
        #endif
       //#NT#2011/02/16#Steven feng -end
        Ux_OpenWindow(&DialogWarnCtrl, 2, WRN_FW_CHECK, WARN_ALWAYS);

        //post event again,because open wind ,miss the event
        Ux_PostEvent(NVTEVT_STORAGE_INIT, 0, 0);
        //#NT#2011/01/07#Janice Huang -end

        //#NT#2011/03/01#Lincy Lin -begin
        //#NT#Fix remove battery the info not save bug
        Save_MenuInfo();
        //#NT#2011/03/01#Lincy Lin -end
    }
    else
    {
        //#NT#2010/09/28#Lincy Lin -end
        //#NT#2010/11/01#Lincy Lin -begin
        UIRes_InitReadPHFE();
        //#NT#2010/11/01#Lincy Lin -end
    }

    #if _PWRON_WAIT_FILESYSTEM_
    if (UIStorageCheck(STORAGE_CHECK_DCIM_READONLY, NULL) == TRUE)
    {
        UI_SetData(FL_IsDCIMReadOnly,TRUE);
    }
    #endif

    //#NT#2011/03/24#Lincy Lin -begin
    //#NT#
    BackupPhotoParamsInfo();
    //#NT#2011/03/24#Lincy Lin -end
#endif

    return NVTEVT_CONSUME;
}

//Edog 
INT32 SetupExe_OnEdogMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
        uhSelect= paramArray[0];
	
   SysSetFlag(FL_EDOGMODE,uhSelect);

    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnEdogVolume(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
        uhSelect= paramArray[0];

     if(gbQuickMute==TRUE)
         return NVTEVT_CONSUME;
	 
     SysSetFlag(FL_EDOGVOLUME,uhSelect);
	
     EdgoRec_PutKeyCommand(MENU_VOLUME,SysGetFlag(FL_EDOGVOLUME)+1);	
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnEdogMute(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    UINT32 uiValue=0;
    if(paramNum>0)
        uhSelect= paramArray[0];
	
   SysSetFlag(FL_EDOGMUTE,uhSelect);
   switch(uhSelect)
   {
		case EDOG_MUTE_OFF:
			uiValue=0;
		break;
		case EDOG_MUTE_20:
		case EDOG_MUTE_30:
		case EDOG_MUTE_40:
		case EDOG_MUTE_50:
		case EDOG_MUTE_60:
		case EDOG_MUTE_70:
		case EDOG_MUTE_80:
		case EDOG_MUTE_90:
		case EDOG_MUTE_100:
		case EDOG_MUTE_110:
		case EDOG_MUTE_120:	
			uiValue=(uhSelect+1)*10;
		break;		
		default:
			uiValue=0;
		break;
   }
   EdgoRec_PutKeyCommand(MENU_RADAR_MUTE,uiValue);	   
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnEdogDriveMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
        uhSelect= paramArray[0];
	
   SysSetFlag(FL_EDOGDRIVEMODE,uhSelect);
   EdgoRec_PutKeyCommand(MENU_DRIVE_MODE,uhSelect+1);	      
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnEdogSensitivity(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    UINT32 uiValue=0;

    if(paramNum>0)
        uhSelect= paramArray[0];
	
   SysSetFlag(FL_EDOGSENSITY,uhSelect);
      
   EdgoRec_PutKeyCommand(MENU_RADAR_SENSITIVITY,uhSelect);	   
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnEdogSpeenLimit(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    UINT32 uiValue=0;

    if(paramNum>0)
        uhSelect= paramArray[0];
	
   SysSetFlag(FL_EDOGSPEED_LIMIT,uhSelect);
   switch(uhSelect)
   {
	case SPEEDLIMIT_OFF:
		uiValue=0;
	break;		
	case SPEEDLIMIT_40:
	case SPEEDLIMIT_50:
	case SPEEDLIMIT_60:
	case SPEEDLIMIT_70:
	case SPEEDLIMIT_80:
	case SPEEDLIMIT_90:
	case SPEEDLIMIT_100:
	case SPEEDLIMIT_110:
	case SPEEDLIMIT_120:
	case SPEEDLIMIT_130:
	case SPEEDLIMIT_140:
	case SPEEDLIMIT_150:
	case SPEEDLIMIT_160:  
		uiValue=(uhSelect+3)*10;
	break;		
	default:
		uiValue=0;
	break;		
   }
   EdgoRec_PutKeyCommand(MENU_SPEEDLIMIT,uiValue);	      
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnEdogSpeenAdjust(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;
    UINT32 uiValue=0;

    if(paramNum>0)
        uhSelect= paramArray[0];
	
   SysSetFlag(FL_EDOGSPEED_ADJUST,uhSelect);
   switch(uhSelect)
   {
		case SPEED_ADJUST_N1:
		case SPEED_ADJUST_N2:		
		case SPEED_ADJUST_N3:	
		case SPEED_ADJUST_N4:	
		case SPEED_ADJUST_N5:		
		case SPEED_ADJUST_N6:		
		case SPEED_ADJUST_N7:		
		case SPEED_ADJUST_N8:		
		case SPEED_ADJUST_N9:		
		case SPEED_ADJUST_N10:	
			uiValue=0xFA-uhSelect;
			break;			
		case SPEED_ADJUST_0:	
			uiValue=0x00;
			break;				
		case SPEED_ADJUST_P1:			
		case SPEED_ADJUST_P2:			
		case SPEED_ADJUST_P3:
		case SPEED_ADJUST_P4:
		case SPEED_ADJUST_P5:
		case SPEED_ADJUST_P6:
		case SPEED_ADJUST_P7:
		case SPEED_ADJUST_P8:
		case SPEED_ADJUST_P9:
		case SPEED_ADJUST_P10:	
			uiValue=uhSelect-10;
			break;				
   }
   EdgoRec_PutKeyCommand(MENU_SPEEDADJUST,uiValue);	      
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnEdogBroadcast(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uhSelect = 0;

    if(paramNum>0)
        uhSelect= paramArray[0];
	
   SysSetFlag(FL_EDOGBROADCAST,uhSelect);
   EdgoRec_PutKeyCommand(MENU_BROADCAST,uhSelect+1);	     
    return NVTEVT_CONSUME;
}

INT32 SetupExe_OnEdogDefault(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
   EdgoRec_PutKeyCommand(MENU_DEFAULTSETTING,0);	  
    return NVTEVT_CONSUME;
}

////////////////////////////////////////////////////////////

EVENT_ENTRY UISetupObjCmdMap[] =
{
//Mode
    //#NT#2012/7/11#philex - begin
    {NVTEVT_EXE_CHANGEDSCMODE,       SetupExe_OnChangeDSCMode     },
    {NVTEVT_FORCETO_LIVEVIEW_MODE,   SetupExe_OnForceToLivedMode  },
    {NVTEVT_FORCETO_PLAYBACK_MODE,   SetupExe_OnForceToPlaybackMode},
    {NVTEVT_FILEID_RESET,            SetupExe_OnFILEDB_FILEID_RESET},
    //#NT#2012/7/11#philex - end
    {NVTEVT_PREVIEWMODE,             SetupExe_OnPreviewMode       },

//Status
    {NVTEVT_EXE_FWUPDATE,            SetupExe_OnFWUpdate          },
    {NVTEVT_EXE_SYSRESET,            SetupExe_OnSysReset          },
    {NVTEVT_EXE_SYSRESET_NO_WIN,     SetupExe_OnSysResetNoWin     },
//Time
    {NVTEVT_EXE_DATEFORMAT,          SetupExe_OnDateFormat        },
    {NVTEVT_EXE_TIMEFORMAT,          SetupExe_OnTimeFormat        },
    {NVTEVT_EXE_ZONE,                SetupExe_OnZone              },
//Power
    {NVTEVT_EXE_LCDOFF,              SetupExe_OnLCDOff            },
    {NVTEVT_EXE_POWEROFF,            SetupExe_OnPowerOff          },
    {NVTEVT_EXE_LED,            SetupExe_OnLed          },
    {NVTEVT_EXE_DELAYOFF,            SetupExe_OnDelayOff          },
//Sound
    {NVTEVT_EXE_BEEPVOLUME,          SetupExe_OnBeepVolume        },
//Display
    {NVTEVT_EXE_DISPLAYDEV,          SetupExe_OnDisplayDev        },
    {NVTEVT_EXE_TVFORMAT,            SetupExe_OnTVFormat          },
    {NVTEVT_EXE_HDMIFORMAT,          SetupExe_OnHDMIFormat        },
    {NVTEVT_EXE_DUALDISP,            SetupExe_OnDualDisp          },
    {NVTEVT_EXE_WIFI_START,          SetupExe_OnWifiStart         },
    {NVTEVT_EXE_WIFI_STOP,           SetupExe_OnWifiStop          },
    {NVTEVT_EXE_BRIGHTADJ,           SetupExe_OnBrightAdj         },
    {NVTEVT_EXE_BRIGHTLVL,           SetupExe_OnBrightLvl         },
//FileSys
    {NVTEVT_EXE_FILESYS_INIT,        SetupExe_OnFileSysInit       },
    {NVTEVT_EXE_FORMAT,              SetupExe_OnFormat            },
    {NVTEVT_EXE_SETUPCOPY2CARD,      SetupExe_OnCopy2Card         },
//USB
    {NVTEVT_EXE_USBMODE,             SetupExe_OnUSBMode           },
//Lens
    {NVTEVT_EXE_PB_RETRACT_LENS,     SetupExe_OnPbRetractLens     },
//DCF manage
    {NVTEVT_EXE_NUMRESET,            SetupExe_OnNumReset          },
    {NVTEVT_EXE_SET_DCFNEXTID,       SetupExe_OnSetDCFNextID      },
//UI Sound
    {NVTEVT_EXE_BEEPSHUTTER,         SetupExe_OnBeepShutter       },
    {NVTEVT_EXE_BEEPKEY,             SetupExe_OnBeepKey           },
    {NVTEVT_EXE_BEEPSELFTIMER,       SetupExe_OnBeepSelftimer     },
    {NVTEVT_EXE_BEEPPOWER,           SetupExe_OnBeepPower         },
//UI Text
    {NVTEVT_EXE_LANGUAGE,            SetupExe_OnLanguage          },
//UI Image
    {NVTEVT_EXE_WALLPAPER_MENU,      SetupExe_OnWallpaperMenu     },
    {NVTEVT_EXE_WALLPAPER_STARTUP,   SetupExe_OnWallpaperStartup  },
    {NVTEVT_EXE_WALLPAPER_BACK,      SetupExe_OnWallpaperBack     },

//Playback
    {NVTEVT_EXE_SLIDESHOW_EFFECT,    SetupExe_OnSlideShowEffect   },
    {NVTEVT_EXE_SLIDESHOW_INTERVAL,  SetupExe_OnSlideShowInterval },
    {NVTEVT_EXE_SLIDESHOW_REPEAT,    SetupExe_OnSlideShowRepeat   },
#if ( SLIDESHOW_MUSIC_OPTION ==   ENABLE )
    {NVTEVT_EXE_SLIDESHOW_MUSIC,     SetupExe_OnSlideShowMusic    },
#endif

//Photo
    {NVTEVT_EXE_PANMODE,             SetupExe_OnPanMode           },
    //#NT#2012/7/11#philex - begin
    {NVTEVT_EXE_FREQ,                SetupExe_OnFreq              },
    //#NT#2012/7/11#philex - end
    // time interval setting of low power timelapse recording mode
    {NVTEVT_EXE_LOWPOWER_TIMELAPSE_REC, SetupExe_OnLowPowerTimelapseRec },

    {NVTEVT_EXE_AFWINDOW,            PhotoExe_OnAFWindow          },
    {NVTEVT_EXE_AFBEAM,              PhotoExe_OnAFBeam            },
    {NVTEVT_EXE_CONTAF,              PhotoExe_OnContAF            },
    {NVTEVT_EXE_METERING,            PhotoExe_OnMetering          },
    {NVTEVT_EXE_PREVIEW,             PhotoExe_OnPreview           },
    {NVTEVT_EXE_DIGITAL_ZOOM,        PhotoExe_OnDigitalZoom       },
    {NVTEVT_EXE_DATE_PRINT,          PhotoExe_OnDatePrint         },
    {NVTEVT_EXE_BLINKDET,            PhotoExe_OnBlinkDet          },
    {NVTEVT_EXE_PAN,                 PhotoExe_OnPan               },

//Movie
    {NVTEVT_EXE_MOVIECONTAF,         MovieExe_OnContAF            },
    {NVTEVT_EXE_MOVIEMETERING,       MovieExe_OnMetering          },
    {NVTEVT_EXE_MOVIEDIS,            MovieExe_OnDis               },
    {NVTEVT_EXE_MOVIEGDC,            MovieExe_OnGdc               },
    {NVTEVT_EXE_MOVIESMEAR,          MovieExe_OnSmear             },

//Edog
    {NVTEVT_EXE_EDOGMODE, 		 	SetupExe_OnEdogMode},		
    {NVTEVT_EXE_EDOGVOLUME, 			SetupExe_OnEdogVolume},
    {NVTEVT_EXE_EDOGMUTE,  			SetupExe_OnEdogMute},						
    {NVTEVT_EXE_EDOGDRIVEMODE,  	 	SetupExe_OnEdogDriveMode},					
    {NVTEVT_EXE_EDOGSENSITY,   		SetupExe_OnEdogSensitivity},						
    {NVTEVT_EXE_EDOGSPEED_LIMIT,   	SetupExe_OnEdogSpeenLimit},						
    {NVTEVT_EXE_EDOGSPEED_ADJUST,   	SetupExe_OnEdogSpeenAdjust},									
    {NVTEVT_EXE_EDOGBROADCAST, 		SetupExe_OnEdogBroadcast},
    {NVTEVT_EXE_EDOG_DEFAULT, 		SetupExe_OnEdogDefault},
		
    //#NT#2010/12/03#Janice Huang -end
    {NVTEVT_NULL,                    0},  //End of Command Map
};

CREATE_APP(UISetupObj,APP_BASE)
