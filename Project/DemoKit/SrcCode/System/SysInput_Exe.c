/*
    System Input Callback

    System Callback for Input Module.

    @file       SysInput_Exe.c
    @ingroup    mIPRJSYS

    @note

    Copyright   Novatek Microelectronics Corp. 2010.  All rights reserved.
*/

////////////////////////////////////////////////////////////////////////////////
#include "SysCommon.h"
#include "AppCommon.h"
////////////////////////////////////////////////////////////////////////////////
#include "UIFrameworkExt.h"
#include "UICommon.h"
#include "AppLib.h"
#include "GxInput.h"
#include "GxPower.h"
#include "NvtSystem.h"
//global debug level: PRJ_DBG_LVL
#include "PrjCfg.h"
#if (UI_STYLE==UI_STYLE_DEMO)
#include "Demo_Sound.h"
#else
#include "SoundData.h"
#endif
#include "DxInput.h"
#include "PipView.h"
//local debug level: THIS_DBGLVL
#define THIS_DBGLVL         1 //0=OFF, 1=ERROR, 2=TRACE
///////////////////////////////////////////////////////////////////////////////
#define __MODULE__          SysInputExe
#define __DBGLVL__          ((THIS_DBGLVL>=PRJ_DBG_LVL)?THIS_DBGLVL:PRJ_DBG_LVL)
#define __DBGFLT__          "*" //*=All, [mark]=CustomClass
#include "DebugModule.h"
#include "UIFlowMovieFuncs.h"
#include "Adc.h"

#define PW84_KEY_BOARD_D_V01   1

#define KEY_BOARD_TYPE    PW84_KEY_BOARD_D_V01

///////////////////////////////////////////////////////////////////////////////

//#NT#Refine code for continue key
#define    BURSTKEY_DEBOUNCE     800//ms
#define    BURSTKEY_INTERVAL     200//ms
#define    TOUCH_TIMER_CNT       2//  2//2X20ms=40ms
#define    DOUBLECLICK_INTERVAL     500//ms

int SX_TIMER_DET_KEY_ID = -1;
int SX_TIMER_DET_IRKEY_ID = -1;
int SX_TIMER_DET_TOUCH_ID = -1;
int SX_TIMER_DET_PWR_ID = -1;
int SX_TIMER_DET_MODE_ID = -1;
int SX_TIMER_AUTO_INPUT_ID = -1;
int SX_TIMER_DET_ReversingCAR_ID = -1;
void UI_DetPwrKey(void);
void UI_DetNormalKey(void);
void UI_DetIrKey(void);
void UI_DetStatusKey(void);
void UI_DetReversing_CARIO(void);


#if (POWERKEY_FUNCTION == ENABLE)
SX_TIMER_ITEM(Input_DetPKey, UI_DetPwrKey, 1, FALSE)
#endif
#if (NORMALKEY_FUNCTION == ENABLE)
SX_TIMER_ITEM(Input_DetNKey, UI_DetNormalKey, 1, FALSE)
#endif
#if (CAR_TOUCHLCD_IR == ENABLE)
SX_TIMER_ITEM(Input_DetIrKey, UI_DetIrKey, 1, FALSE)
#endif
#if (STATUSKEY_FUNCTION == ENABLE)
SX_TIMER_ITEM(Input_DetSKey, UI_DetStatusKey, 7, FALSE)
#endif
#if (TOUCH_FUNCTION == ENABLE)
SX_TIMER_ITEM(Input_DetTP, GxTouch_DetTP, TOUCH_TIMER_CNT, FALSE)
#endif
#if (AUTOINPUT_FUNCTION == ENABLE)
SX_TIMER_ITEM(Input_FeedKey, AutoInput, AUTO_INPUT_TIMER_CNT, FALSE)
#endif
SX_TIMER_ITEM(Input_Reversing_CARIO, UI_DetReversing_CARIO, 10, FALSE)
static BOOL         m_uiAnyKeyUnlockEn        = FALSE;

#if (TOUCH_FUNCTION == ENABLE)
static TOUCH_OBJ g_TouchTable[] =
{
    {TP_GESTURE_PRESS,         NVTEVT_PRESS,        0},//{TP_GESTURE_PRESS,         NVTEVT_PRESS,        DEMOSOUND_SOUND_KEY_TONE},
    //{TP_GESTURE_MOVE,          NVTEVT_MOVE,         0},
    {TP_GESTURE_RELEASE,       NVTEVT_RELEASE,      0},//{TP_GESTURE_RELEASE,       NVTEVT_RELEASE,      DEMOSOUND_SOUND_KEY_TONE},
    {TP_GESTURE_CLICK,         NVTEVT_CLICK,        0},
    {TP_GESTURE_SLIDE_LEFT,    NVTEVT_SLIDE_LEFT,   0},
    {TP_GESTURE_SLIDE_RIGHT,   NVTEVT_SLIDE_RIGHT,  0},
    {TP_GESTURE_SLIDE_UP,      NVTEVT_SLIDE_UP,     0},
    {TP_GESTURE_SLIDE_DOWN,    NVTEVT_SLIDE_DOWN,   0}
};
#endif


#if (UI_STYLE==UI_STYLE_DEMO)
static KEY_OBJ g_KeyTable[] =
{
    //POWER KEY
    {FLGKEY_KEY_POWER,    KEY_RELEASE,     NVTEVT_KEY_POWER_REL,        0,                            0},
    //NORMAL KEY
    {FLGKEY_ENTER,        KEY_PRESS,       NVTEVT_KEY_ENTER,            0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_MENU,         KEY_PRESS,       NVTEVT_KEY_MENU,             0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_MODE,         KEY_PRESS,       NVTEVT_KEY_MODE,             0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_PLAYBACK,     KEY_PRESS,       NVTEVT_KEY_PLAYBACK,         0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_MOVIE,        KEY_PRESS,       NVTEVT_KEY_MOVIE,            0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_DEL,          KEY_PRESS,       NVTEVT_KEY_I,                0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_UP,           KEY_PRESS,       NVTEVT_KEY_UP,               0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_UP,           KEY_CONTINUE,    NVTEVT_KEY_UP,               0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_UP,           KEY_RELEASE,     NVTEVT_KEY_UP_REL,           0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_DOWN,         KEY_PRESS,       NVTEVT_KEY_DOWN,             0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_DOWN,         KEY_CONTINUE,    NVTEVT_KEY_DOWN,             0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_DOWN,         KEY_RELEASE,     NVTEVT_KEY_DOWN_REL,         0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_LEFT,         KEY_PRESS,       NVTEVT_KEY_LEFT,             0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_LEFT,         KEY_CONTINUE,    NVTEVT_KEY_LEFT,             0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_LEFT,         KEY_RELEASE,     NVTEVT_KEY_LEFT_REL,         0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_RIGHT,        KEY_PRESS,       NVTEVT_KEY_RIGHT,            0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_RIGHT,        KEY_CONTINUE,    NVTEVT_KEY_RIGHT,            0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_RIGHT,        KEY_RELEASE,     NVTEVT_KEY_RIGHT_REL,        0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_DOWN,         KEY_PRESS,       NVTEVT_KEY_DOWN,             0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_DOWN,         KEY_CONTINUE,    NVTEVT_KEY_DOWN,             0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_DOWN,         KEY_RELEASE,     NVTEVT_KEY_DOWN_REL,         0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_ZOOMIN,       KEY_PRESS,       NVTEVT_KEY_ZOOMIN,           0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_ZOOMIN,       KEY_CONTINUE,    NVTEVT_KEY_ZOOMIN,           0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_ZOOMIN,       KEY_RELEASE,     NVTEVT_KEY_ZOOMRELEASE,      0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_ZOOMOUT,      KEY_PRESS,       NVTEVT_KEY_ZOOMOUT,          0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_ZOOMOUT,      KEY_CONTINUE,    NVTEVT_KEY_ZOOMOUT,          0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_ZOOMOUT,      KEY_RELEASE,     NVTEVT_KEY_ZOOMRELEASE,      0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_SHUTTER2,     KEY_PRESS,       NVTEVT_KEY_SHUTTER2,         0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_SHUTTER2,     KEY_RELEASE,     NVTEVT_KEY_SHUTTER2_REL,     0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_SHUTTER1,     KEY_PRESS,       NVTEVT_KEY_SHUTTER1,         0,     PLAYSOUND_SOUND_KEY_TONE},
    {FLGKEY_SHUTTER1,     KEY_RELEASE,     NVTEVT_KEY_SHUTTER1_REL,     0,     PLAYSOUND_SOUND_KEY_TONE},
#if (STATUSKEY_FUNCTION == ENABLE)
    //STATUS KEY
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_1, NVTEVT_KEY_STATUS1,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_2, NVTEVT_KEY_STATUS2,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_3, NVTEVT_KEY_STATUS3,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_4, NVTEVT_KEY_STATUS4,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_5, NVTEVT_KEY_STATUS5,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_6, NVTEVT_KEY_STATUS6,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_7, NVTEVT_KEY_STATUS7,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_8, NVTEVT_KEY_STATUS8,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_9, NVTEVT_KEY_STATUS9,         0,     0},
    {STATUS_KEY_GROUP1,   STATUS_KEY_LVL_10,NVTEVT_KEY_STATUS10,        0,     0}
#endif
};
#else
static KEY_OBJ g_KeyTable[] =
{
    //POWER KEY
    {FLGKEY_KEY_POWER,    KEY_RELEASE,     NVTEVT_KEY_POWER_REL,        0,                  0},
    //NORMAL KEY
    {FLGKEY_ENTER,        KEY_PRESS,       NVTEVT_KEY_ENTER,        NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_MENU,         KEY_PRESS,       NVTEVT_KEY_MENU,         NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_MODE,         KEY_PRESS,       NVTEVT_KEY_MODE,         NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_PLAYBACK,     KEY_PRESS,       NVTEVT_KEY_PLAYBACK,     NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_UP,           KEY_PRESS,       NVTEVT_KEY_UP,           NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_UP,           KEY_CONTINUE,    NVTEVT_KEY_UP,           NVTEVT_KEY_CONTINUE,    0},
    {FLGKEY_UP,           KEY_RELEASE,     NVTEVT_KEY_UP,           NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_DOWN,         KEY_PRESS,       NVTEVT_KEY_DOWN,         NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_DOWN,         KEY_CONTINUE,    NVTEVT_KEY_DOWN,         NVTEVT_KEY_CONTINUE,    0},
    {FLGKEY_DOWN,         KEY_RELEASE,     NVTEVT_KEY_DOWN,         NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_LEFT,         KEY_PRESS,       NVTEVT_KEY_LEFT,         NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_LEFT,         KEY_CONTINUE,    NVTEVT_KEY_LEFT,         NVTEVT_KEY_CONTINUE,    0},
    {FLGKEY_LEFT,         KEY_RELEASE,     NVTEVT_KEY_LEFT,         NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_RIGHT,        KEY_PRESS,       NVTEVT_KEY_RIGHT,        NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_RIGHT,        KEY_CONTINUE,    NVTEVT_KEY_RIGHT,        NVTEVT_KEY_CONTINUE,    0},
    {FLGKEY_RIGHT,        KEY_RELEASE,     NVTEVT_KEY_RIGHT,        NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_DOWN,         KEY_PRESS,       NVTEVT_KEY_DOWN,         NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_DOWN,         KEY_CONTINUE,    NVTEVT_KEY_DOWN,         NVTEVT_KEY_CONTINUE,    0},
    {FLGKEY_DOWN,         KEY_RELEASE,     NVTEVT_KEY_DOWN,         NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_ZOOMIN,       KEY_PRESS,       NVTEVT_KEY_ZOOMIN,       NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_ZOOMIN,       KEY_CONTINUE,    NVTEVT_KEY_ZOOMIN,       NVTEVT_KEY_CONTINUE,    0},
    {FLGKEY_ZOOMIN,       KEY_RELEASE,     NVTEVT_KEY_ZOOMIN,       NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_ZOOMOUT,      KEY_PRESS,       NVTEVT_KEY_ZOOMOUT,      NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_ZOOMOUT,      KEY_CONTINUE,    NVTEVT_KEY_ZOOMOUT,      NVTEVT_KEY_CONTINUE,    0},
    {FLGKEY_ZOOMOUT,      KEY_RELEASE,     NVTEVT_KEY_ZOOMOUT,      NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_SHUTTER2,     KEY_PRESS,       NVTEVT_KEY_SHUTTER2,     NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_SHUTTER2,     KEY_RELEASE,     NVTEVT_KEY_SHUTTER2,     NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_SHUTTER1,     KEY_PRESS,       NVTEVT_KEY_SHUTTER1,     NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_KEY_TONE},
    {FLGKEY_SHUTTER1,     KEY_RELEASE,     NVTEVT_KEY_SHUTTER1,     NVTEVT_KEY_RELEASE,     0},
    {FLGKEY_CUSTOM1,      KEY_PRESS,       NVTEVT_KEY_CUSTOM1,      NVTEVT_KEY_PRESS,       DEMOSOUND_SOUND_NONE},
    {FLGKEY_CUSTOM1,      KEY_RELEASE,     NVTEVT_KEY_CUSTOM1,      NVTEVT_KEY_RELEASE,     0},
};
#endif
void KeySoundCB(UINT32 uiSoundID)
{
    if(uiSoundID)
    {
        UISound_Play(uiSoundID);
    }
}

UINT32 Input_GroupStatus2Event(UINT32 status)
{
    UINT32 i=0;
    for(i=0;i<sizeof(g_KeyTable)/sizeof(KEY_OBJ);i++)
    {
    if( (g_KeyTable[i].uiKeyFlag == STATUS_KEY_GROUP1) && (g_KeyTable[i].status == status))
        return g_KeyTable[i].uiKeyEvent;
    }
    return 0;
}

/**
  convert GPIO key to UI key event
  [InputCB internal API]

  @param UINT32 keys: Input key code detected from GPIO mapping
  @return UINT32: NVTEVT
**/
#if 0
static UINT32 Input_Key2Evt(UINT32 keys)
{
    if(keys & FLGKEY_MOVIE)
        return NVTEVT_KEY_MOVIE;
    if(keys & FLGKEY_I)
        return NVTEVT_KEY_I;
    if(keys & FLGKEY_MODE)
        return NVTEVT_KEY_MODE;
    if(keys & FLGKEY_PLAYBACK)
        return NVTEVT_KEY_PLAYBACK;
    if(keys & FLGKEY_MENU)
        return NVTEVT_KEY_MENU;
    if(keys & FLGKEY_FACEDETECT)
        return NVTEVT_KEY_FACEDETECT;
    if(keys & FLGKEY_DEL)
        return NVTEVT_KEY_DEL;
    if(keys & FLGKEY_LEFT)
        return NVTEVT_KEY_LEFT;
    if(keys & FLGKEY_RIGHT)
        return NVTEVT_KEY_RIGHT;
    if(keys & FLGKEY_ENTER)
        return NVTEVT_KEY_ENTER;
    if(keys & FLGKEY_SHUTTER1)
        return NVTEVT_KEY_SHUTTER1;
    if(keys & FLGKEY_SHUTTER2)
        return NVTEVT_KEY_SHUTTER2;
    if(keys & FLGKEY_ZOOMOUT)
        return NVTEVT_KEY_ZOOMOUT;
    if(keys & FLGKEY_ZOOMIN)
        return NVTEVT_KEY_ZOOMIN;
    if(keys & FLGKEY_UP)
        return NVTEVT_KEY_UP;
    if(keys & FLGKEY_DOWN)
        return NVTEVT_KEY_DOWN;
    else
        return NVTEVT_NULL;
}
#endif
//just for backward compatible
void Input_SetKeyMask(KEY_STATUS uiMode, UINT32 uiMask)
{
    SysMan_SetKeyMask(uiMode, uiMask);
}
UINT32 Input_GetKeyMask(KEY_STATUS uiMode)
{
    return SysMan_GetKeyMask(uiMode);
}
void Input_SetKeySoundMask(KEY_STATUS uiMode, UINT32 uiMask)
{
    SysMan_SetKeySoundMask(uiMode, uiMask);
}
UINT32 Input_GetKeySoundMask(KEY_STATUS uiMode)
{
    return SysMan_GetKeySoundMask(uiMode);
}
#if 0
void Input_SetTouchMask(UINT32 uiMask)
{
#if (TOUCH_FUNCTION == ENABLE)
    uiTouchMask = uiMask;
#endif
}
#endif
/**
    reset all mask,usually in new winodw onOpen
*/
void Input_ResetMask(void)
{
    // Set key mask as default
    SysMan_SetKeyMask(KEY_PRESS, FLGKEY_KEY_MASK_DEFAULT);
    SysMan_SetKeyMask(KEY_RELEASE, FLGKEY_KEY_MASK_DEFAULT);
    SysMan_SetKeyMask(KEY_CONTINUE, FLGKEY_KEY_MASK_NULL);
#if (TOUCH_FUNCTION == ENABLE)
    // Set touch mask as default
    SysMan_SetTouchMask(TOUCH_MASK_DEFAULT);
#endif
    SysMan_SetKeySoundMask(KEY_PRESS, FLGKEY_SOUND_MASK_DEFAULT);
    SysMan_SetKeySoundMask(KEY_RELEASE, FLGKEY_KEY_MASK_NULL);
    SysMan_SetKeySoundMask(KEY_CONTINUE, FLGKEY_SOUND_MASK_DEFAULT);
}
/**
    for some case,press any key unlock all,and post NVTEVT_KEY_PRESS
    ex:Timelapse or smile detect
*/
void Input_SetAnyKeyUnlock(BOOL en)
{
    m_uiAnyKeyUnlockEn = en;
}


UINT32 Input_Key2Mode(UINT32 keys)
{
#if (STATUSKEY_FUNCTION == ENABLE)
    switch (keys)
    {
        case NVTEVT_KEY_STATUS1: return DSC_MODE_MOVIE;
        case NVTEVT_KEY_STATUS2: return DSC_MODE_PHOTO_MANUAL;
        case NVTEVT_KEY_STATUS3: return DSC_MODE_PHOTO_MANUAL;
        case NVTEVT_KEY_STATUS4: return DSC_MODE_PHOTO_MANUAL;
        case NVTEVT_KEY_STATUS5: return DSC_MODE_PHOTO_MANUAL;
        case NVTEVT_KEY_STATUS6: return DSC_MODE_PHOTO_SCENE;
        case NVTEVT_KEY_STATUS7: return DSC_MODE_PHOTO_MANUAL;
        case NVTEVT_KEY_STATUS8: return DSC_MODE_PHOTO_MANUAL;
        case NVTEVT_KEY_STATUS9: return DSC_MODE_PHOTO_MANUAL;
        case NVTEVT_KEY_STATUS10: return DSC_MODE_PHOTO_MANUAL;
        default: return DSC_MODE_PHOTO_AUTO;
    }
#else
    return 0;
#endif
}
extern SX_CMD_ENTRY key[];
void System_OnInputInit(void)
{
    //PHASE-1 : Init & Open Drv or DrvExt
    {
        GxKey_RegCB(Key_CB);         //Register CB function of GxInput
        #if (TOUCH_FUNCTION == ENABLE)
        GxTouch_RegCB(Touch_CB);     //Register CB function of GxInput
        #endif
        GxKey_Init();
        SxCmd_AddTable(key);
    }
    //PHASE-2 : Init & Open Lib or LibExt
    {
        //1.設定init值
        //2.設定CB值,
        GxKey_SetContDebounce(BURSTKEY_DEBOUNCE/SxTimer_GetData(SXTIMER_TIMER_BASE));
        GxKey_SetRepeatInterval(BURSTKEY_INTERVAL/SxTimer_GetData(SXTIMER_TIMER_BASE));
        SysMan_RegKeySoundCB(KeySoundCB);
        SysMan_RegKeyTable(g_KeyTable, sizeof(g_KeyTable)/sizeof(KEY_OBJ));
        //3.註冊SxJob服務 ---------> System Job
        //4.註冊SxTimer服務 ---------> Detect Job

        #if (POWERKEY_FUNCTION == ENABLE)
        SX_TIMER_DET_PWR_ID = SxTimer_AddItem(&Timer_Input_DetPKey);
        #endif
        #if (NORMALKEY_FUNCTION == ENABLE)
        SX_TIMER_DET_KEY_ID = SxTimer_AddItem(&Timer_Input_DetNKey);
        #endif
        #if (CAR_TOUCHLCD_IR == ENABLE)
        SX_TIMER_DET_IRKEY_ID = SxTimer_AddItem(&Timer_Input_DetIrKey);
        #endif
        #if (STATUSKEY_FUNCTION == ENABLE)
        SX_TIMER_DET_MODE_ID = SxTimer_AddItem(&Timer_Input_DetSKey);
        #endif
        #if (TOUCH_FUNCTION == ENABLE)
        SX_TIMER_DET_TOUCH_ID = SxTimer_AddItem(&Timer_Input_DetTP);
        #endif
        #if (AUTOINPUT_FUNCTION == ENABLE)
        SX_TIMER_AUTO_INPUT_ID = SxTimer_AddItem(&Timer_Input_FeedKey);
        #endif
        SX_TIMER_DET_ReversingCAR_ID = SxTimer_AddItem(&Timer_Input_Reversing_CARIO);
#if _MIPS_TODO
        if(FlowMode_IsPowerOnPlayback())
        {
            GxKey_SetFirstKeyInvalid(KEY_PRESS, FLGKEY_PLAYBACK);
        }
#endif
        #if (STATUSKEY_FUNCTION == ENABLE)
        GxKey_DetStatusKey();
        #endif

        #if (POWERKEY_FUNCTION == ENABLE)
        SxTimer_SetFuncActive(SX_TIMER_DET_PWR_ID, TRUE);
        #endif
        #if (NORMALKEY_FUNCTION == ENABLE)
        SxTimer_SetFuncActive(SX_TIMER_DET_KEY_ID, TRUE);
        #endif
        #if (CAR_TOUCHLCD_IR == ENABLE)
        SxTimer_SetFuncActive(SX_TIMER_DET_IRKEY_ID, TRUE);
        #endif
        #if (STATUSKEY_FUNCTION == ENABLE)
        SxTimer_SetFuncActive(SX_TIMER_DET_MODE_ID, TRUE);
        #endif

        #if (TOUCH_FUNCTION == ENABLE)
        //1.設定init值
        GxTouch_Init();
        GxTouch_SetCtrl(GXTCH_DOUBLE_CLICK_INTERVAL,
            DOUBLECLICK_INTERVAL/TOUCH_TIMER_CNT/SxTimer_GetData(SXTIMER_TIMER_BASE));
        SysMan_RegTouchSoundCB(KeySoundCB);
        SysMan_RegTouchTable(g_TouchTable, sizeof(g_TouchTable)/sizeof(TOUCH_OBJ));
        //2.設定CB值,
        //3.註冊SxJob服務 ---------> System Job
        //4.註冊SxTimer服務 ---------> Detect Job
        //SX_TIMER_DET_TOUCH_ID = System_AddSxTimer(GxTouch_DetTP, TOUCH_TIMER_CNT, "GxTouch_DetTP", TRUE);
        //SX_TIMER_DET_TOUCH_ID = SxTimer_AddItem(&Timer_Input_DetTP);
        //5.註冊SxCmd服務 ---------> Cmd Function
        //System_AddSxCmd(Touch_OnCommand); //GxInput

        SxTimer_SetFuncActive(SX_TIMER_DET_TOUCH_ID, TRUE);
        #endif
    }
}

void System_OnInputExit(void)
{
    //PHASE-2 : Close Lib or LibExt
    {
    }
    //PHASE-1 : Close Drv or DrvExt
    {
    }
}

/////////////////////////////////////////////////////////////////////////////
#define KEYSCAN_PWROFF_INIT_STATE       0
#define KEYSCAN_PWROFF_RELEASE_STATE    1
#define KEYSCAN_PWROFF_PRESS_STATE      2

#define KEYSCAN_PWRKEY_UNKNOWN          0xFFFFFFFF
#define KEYSCAN_PWRKEY_RELEASED         0
#define KEYSCAN_PWRKEY_PRESSED          1

#define KEYSCAN_POWEROFF_COUNT  100 //20ms is 1

void UI_DetPwrKey(void)
{
    if(!UI_IsForceLock())
    {
#if 1
    {
        static UINT32 uiPowerKey    = KEYSCAN_PWRKEY_UNKNOWN;
        static UINT32 uiPWRState    = KEYSCAN_PWROFF_INIT_STATE;
        static UINT32 uiPowerKeyPressCount = 0;

        if ( rtc_getPWRStatus())
        {
        // Reset shutdown timer
        rtc_resetShutdownTimer();

        // Debounce
        if (uiPowerKey == KEYSCAN_PWRKEY_PRESSED)
        {
            if (uiPWRState == KEYSCAN_PWROFF_RELEASE_STATE)
            {
                uiPowerKeyPressCount++;
                debug_err(("uiPowerKeyPressCount : %d....%d\r\n",uiPowerKeyPressCount,KEYSCAN_POWEROFF_COUNT));
		  GPIO_CLEAR_CMD_PWR_KEY();
                if (uiPowerKeyPressCount > KEYSCAN_POWEROFF_COUNT)
                {                
                    uiPWRState = KEYSCAN_PWROFF_PRESS_STATE;
                }
            }

            if(uiPWRState == KEYSCAN_PWROFF_PRESS_STATE)
            {
                  //uiKeyCode = FLGKEY_KEY_POWER;
		     uiPowerKeyPressCount = 0;
        	     //rtc_resetShutdownTimer();		 
		    Delay_DelayMs(200);
		    //System_PowerOff(SYS_POWEROFF_NORMAL);
    		    //Ux_SendEvent(0, NVTEVT_SYSTEM_SHUTDOWN, 1, 0); //shutdown start			
                 Ux_PostEvent(NVTEVT_KEY_POWER_REL, 1, NVTEVT_KEY_PRESS);	
		    
            }
        }
        else
        {
            uiPowerKey = KEYSCAN_PWRKEY_PRESSED;
        }
    }
    else
	{
        // Debounce
        if (uiPowerKey == KEYSCAN_PWRKEY_RELEASED)
        {
            if (uiPWRState == KEYSCAN_PWROFF_INIT_STATE)
            {
                uiPWRState = KEYSCAN_PWROFF_RELEASE_STATE;
            }

            if (uiPowerKeyPressCount)
            {	   
                uiPowerKeyPressCount = 0;   
		#if (_MODEL_DSC_ == _MODEL_CARDV_)
               // UISound_Play(DEMOSOUND_SOUND_KEY_TONE);		
		#else
	      if((GPIOMap_IsLCDBacklightOn()==FALSE)&&
		  	(KeyScan_GetPlugDev() != 1)&&(KeyScan_GetPlugDev() != 2))
	     	{
			GPIOMap_TurnOnLCDBacklight();
			System_ResetPowerSaveCount();		    			
	     	}						
		else
		{		
              	
		}	
                
                Delay_DelayMs(20); 
                GPIO_SET_CMD_PWR_KEY();
		#endif                	  
            }
        }
        else
        {
            GPIO_SET_CMD_PWR_KEY();
            uiPowerKey = KEYSCAN_PWRKEY_RELEASED;
        }
    }	  
        
    }
#else     
        GxKey_DetPwrKey();
#endif
    }
}

#define KEYSCAN_CUSTOMER_INIT_STATE       0
#define KEYSCAN_CUSTOMER_RELEASE_STATE    1
#define KEYSCAN_CUSTOMER_PRESS_STATE      2

#define KEYSCAN_CUSTOMER_UNKNOWN          0xFFFFFFFF
#define KEYSCAN_CUSTOMER_RELEASED         0
#define KEYSCAN_CUSTOMER_PRESSED          1

#define KEYSCAN_CUSTOMER_COUNT  100 //20ms is 1

#define KEY_ADC_RANGE        (25)
#if 0// 誑薊痄雄
#define KEY_ADC_DOWN         (174)
#define KEY_ADC_UP        (348)
#else //F84 
#define KEY_ADC_DOWN         (174)
#define KEY_ADC_UP        (348)
#endif

void UI_DetCustomerModeKey(void)
{
	static UINT32 uiDownKey    = KEYSCAN_CUSTOMER_UNKNOWN;
	static UINT32 uiDownState    = KEYSCAN_CUSTOMER_INIT_STATE;
	static UINT32 uiDownKeyPressCount = 0;

	static UINT32 uiUpKey    = KEYSCAN_CUSTOMER_UNKNOWN;
	static UINT32 uiUpState    = KEYSCAN_CUSTOMER_INIT_STATE;
	static UINT32 uiUpKeyPressCount = 0;
	
	UINT32 uiADCValue;

	uiADCValue=adc_readData(1);
	if((uiADCValue>(KEY_ADC_DOWN-KEY_ADC_RANGE))&&(uiADCValue<(KEY_ADC_DOWN+KEY_ADC_RANGE)))
	{
        // Debounce
        if (uiDownKey == KEYSCAN_CUSTOMER_PRESSED)
        {
            if (uiDownState == KEYSCAN_CUSTOMER_RELEASE_STATE)
            {
                uiDownKeyPressCount++;
                debug_err(("uiDownKeyPressCount : %d....%d\r\n",uiDownKeyPressCount,KEYSCAN_CUSTOMER_COUNT));
				
                if (uiDownKeyPressCount > KEYSCAN_CUSTOMER_COUNT)
                {
                    uiDownState = KEYSCAN_CUSTOMER_PRESS_STATE;
                }
            }

            if(uiDownState == KEYSCAN_CUSTOMER_PRESS_STATE)
            {
                  //uiKeyCode = FLGKEY_KEY_POWER;
		     uiDownKeyPressCount = 0;		
		     uiDownKey    = KEYSCAN_CUSTOMER_UNKNOWN;
		     uiDownState    = KEYSCAN_CUSTOMER_INIT_STATE;			
                UISound_Play(DEMOSOUND_SOUND_KEY_TONE);		
			if((GPIOMap_IsLCDBacklightOn()==FALSE)&&
			(KeyScan_GetPlugDev() != 1)&&(KeyScan_GetPlugDev() != 2))
			{
				GPIOMap_TurnOnLCDBacklight();
				System_ResetPowerSaveCount();		    			
			}				
			else
			{
				Ux_PostEvent(NVTEVT_KEY_DOWN, 1, NVTEVT_KEY_CONTINUE);			   	
			}  
            }
        }
        else
        {
            uiDownKey = KEYSCAN_PWRKEY_PRESSED;
        }
    }
	else
	{
        // Debounce
        if (uiDownKey == KEYSCAN_CUSTOMER_RELEASED)
        {
            if (uiDownState == KEYSCAN_CUSTOMER_INIT_STATE)
            {
                uiDownState = KEYSCAN_CUSTOMER_RELEASE_STATE;
            }

            if (uiDownKeyPressCount)
            {	   
                uiDownKeyPressCount = 0;   
                UISound_Play(DEMOSOUND_SOUND_KEY_TONE);		
			if((GPIOMap_IsLCDBacklightOn()==FALSE)&&
			(KeyScan_GetPlugDev() != 1)&&(KeyScan_GetPlugDev() != 2))
			{
				GPIOMap_TurnOnLCDBacklight();
				System_ResetPowerSaveCount();		    			
			}				
			else
			{
                		Ux_PostEvent(NVTEVT_KEY_DOWN, 1, NVTEVT_KEY_PRESS);	
			}  				
            }
        }
        else
        {
            uiDownKey = KEYSCAN_CUSTOMER_RELEASED;
        }
    }	
	
   if((uiADCValue>(KEY_ADC_UP-KEY_ADC_RANGE))&&(uiADCValue<(KEY_ADC_UP+KEY_ADC_RANGE)))
	{
        // Debounce
        if (uiUpKey == KEYSCAN_CUSTOMER_PRESSED)
        {
            if (uiUpState == KEYSCAN_CUSTOMER_RELEASE_STATE)
            {
                uiUpKeyPressCount++;
                debug_err(("uiUpKeyPressCount : %d....%d\r\n",uiUpKeyPressCount,KEYSCAN_CUSTOMER_COUNT));
				
                if (uiUpKeyPressCount > KEYSCAN_CUSTOMER_COUNT)
                {
                    uiUpState = KEYSCAN_CUSTOMER_PRESS_STATE;
                }
            }

            if(uiUpState == KEYSCAN_CUSTOMER_PRESS_STATE)
            {
                  //uiKeyCode = FLGKEY_KEY_POWER;
		     uiUpKeyPressCount = 0;		
		     uiUpKey    = KEYSCAN_CUSTOMER_UNKNOWN;
		     uiUpState    = KEYSCAN_CUSTOMER_INIT_STATE;			
                UISound_Play(DEMOSOUND_SOUND_KEY_TONE);				
			if((GPIOMap_IsLCDBacklightOn()==FALSE)&&
			(KeyScan_GetPlugDev() != 1)&&(KeyScan_GetPlugDev() != 2))
			{
				GPIOMap_TurnOnLCDBacklight();
				System_ResetPowerSaveCount();		    			
			}				
			else
			{
                		Ux_PostEvent(NVTEVT_KEY_UP, 1, NVTEVT_KEY_CONTINUE);			   	
			}  				
		    
            }
        }
        else
        {
            uiUpKey = KEYSCAN_PWRKEY_PRESSED;
        }
    }
	else
	{
        // Debounce
        if (uiUpKey == KEYSCAN_CUSTOMER_RELEASED)
        {
            if (uiUpState == KEYSCAN_CUSTOMER_INIT_STATE)
            {
                uiUpState = KEYSCAN_CUSTOMER_RELEASE_STATE;
            }

            if (uiUpKeyPressCount)
            {	   
                uiUpKeyPressCount = 0;   
                UISound_Play(DEMOSOUND_SOUND_KEY_TONE);		
			if((GPIOMap_IsLCDBacklightOn()==FALSE)&&
			(KeyScan_GetPlugDev() != 1)&&(KeyScan_GetPlugDev() != 2))
			{
				GPIOMap_TurnOnLCDBacklight();
				System_ResetPowerSaveCount();		    			
			}				
			else
			{
                		Ux_PostEvent(NVTEVT_KEY_UP, 1, NVTEVT_KEY_PRESS);	
			}  				
            }
        }
        else
        {
            uiUpKey = KEYSCAN_CUSTOMER_RELEASED;
        }
    }			
}


static BOOL s_bContinePostLongPressKey = FALSE;

void MY_EnableContinuePosetKey(BOOL enable)
{
	s_bContinePostLongPressKey = enable;
}

BOOL MY_GetEnableContinuePosetKey(void)
{
	return s_bContinePostLongPressKey;
}

//static BOOL         m_uiAnyKeyUnlockEn        = FALSE;
#define KEYSCAN_KEY_UNKNOWN          0xFFFFFFFF
#define KEYSCAN_KEY_RELEASED         0
#define KEYSCAN_KEY_PRESSED          1

#define KEYSCAN_KEY_INIT_STATE       0
#define KEYSCAN_KEY_RELEASE_STATE    1
#define KEYSCAN_KEY_PRESS_STATE      2

#define KEYSCAN_LONG_PRESS_COUNT		80
#define MY_KEY_ADC_LVL4         (0)
#define MY_KEY_ADC_LVL3         (516)//down//shu2  datatime
//#define MY_KEY_ADC_LVL2         (687) //up



#define MY_KEY_ADC_RANGE        (50)


void MY_DetNormalKeyLVL4(UINT32 uiKey1ADC, UINT32 uiPostKey, UINT32 uiMaskFlagKey, BOOL bContinuePost)
{
    static UINT32 uiKeyPressCount = 0;
    static UINT32 uiKey    = KEYSCAN_KEY_UNKNOWN;
    static UINT32 uiState    = KEYSCAN_KEY_INIT_STATE;
	static BOOL   bNeedRelease = FALSE, bHold = FALSE;

	if((uiKey1ADC >= MY_KEY_ADC_LVL4) && (uiKey1ADC < MY_KEY_ADC_LVL4 + MY_KEY_ADC_RANGE))
	{
        // Debounce
        if (uiKey == KEYSCAN_KEY_PRESSED)
        {
            if (uiState == KEYSCAN_KEY_RELEASE_STATE)
            {
                uiKeyPressCount++;
                GPIO_CLEAR_CMD_MODE_KEY();
				if (MY_GetEnableContinuePosetKey() && (bContinuePost == TRUE))
				{
					if (uiKeyPressCount % 10 == 0)
					{
						if ((KeyScan_GetPlugDev() == PLUG_OFF) && !GPIOMap_IsLCDBacklightOn())
						{
							GPIOMap_TurnOnLCDBacklight();
						}
						else
						{
				            //UISound_Play(DEMOSOUND_SOUND_KEY_TONE);
						//	Ux_PostEvent(uiPostKey, 1, NVTEVT_KEY_CONTINUE);
						}
						bNeedRelease = FALSE;
						bHold = TRUE;
					}
				}
				else
				{
	                if (uiKeyPressCount > KEYSCAN_LONG_PRESS_COUNT)
	                {
	                
	                    uiState = KEYSCAN_KEY_PRESS_STATE;
	                }
				}
            }

            if (uiState == KEYSCAN_KEY_PRESS_STATE)
			{
				uiKeyPressCount = 0;
				bNeedRelease = TRUE;
				uiKey    = KEYSCAN_KEY_UNKNOWN;
				uiState    = KEYSCAN_KEY_INIT_STATE;
				if ((KeyScan_GetPlugDev() == PLUG_OFF) && !GPIOMap_IsLCDBacklightOn())
				{
					GPIOMap_TurnOnLCDBacklight();
				}
				else
				{
				
                                                                     		  				
		            	//UISound_Play(DEMOSOUND_SOUND_KEY_TONE);
                                   // Ux_PostEvent(NVTEVT_KEY_MENU, 1, NVTEVT_KEY_PRESS); //playback mode
					//Ux_PostEvent(NVTEVT_KEY_MODE, 1, NVTEVT_KEY_CONTINUE);
				
				
				}
                        GPIO_CLEAR_CMD_MODE_KEY();     
                        
			}
		}
        else
        {
            uiKey = KEYSCAN_KEY_PRESSED;
        }
	}
    else
    {
        // Debounce
        if (uiKey == KEYSCAN_KEY_RELEASED)
        {
            if (uiState == KEYSCAN_KEY_INIT_STATE)
            {
                uiState = KEYSCAN_KEY_RELEASE_STATE;
            }

            if (uiKeyPressCount)
            {
            	if (!bHold)
            	{
					uiKeyPressCount = 0;
					bNeedRelease = TRUE;
					if ((KeyScan_GetPlugDev() == PLUG_OFF) && !GPIOMap_IsLCDBacklightOn())
					{
						GPIOMap_TurnOnLCDBacklight();
					}
					else
					{
			                    //UISound_Play(DEMOSOUND_SOUND_KEY_TONE);
						//Ux_PostEvent(NVTEVT_KEY_MODE, 1, NVTEVT_KEY_PRESS);
					}
                                    
                                    Delay_DelayMs(20);
                                    GPIO_SET_CMD_MODE_KEY();   
				}
            }
			else if (bNeedRelease)
			{
				bNeedRelease = FALSE;
				if (Input_GetKeyMask(KEY_RELEASE) & uiMaskFlagKey)
				{
				GPIO_SET_CMD_MODE_KEY();
				//	Ux_PostEvent(uiPostKey, 1, NVTEVT_KEY_RELEASE);
				}
			}
        }
        else
        {
            uiKey = KEYSCAN_KEY_RELEASED;
        }
    }
}


void UI_DetNormalKey(void)
{
    static UINT32 keyDetectCount = 0;
    UINT32        uiKey1ADC;
    if(!UI_IsForceLock())
    {
        //GxKey_DetNormalKey();
        uiKey1ADC = adc_readData(ADC_CHANNEL_1);
        MY_DetNormalKeyLVL4(uiKey1ADC, NVTEVT_KEY_MENU, FLGKEY_MENU, TRUE);//MY_DetNormalKeyLVL3(uiKey1ADC, NVTEVT_KEY_UP, FLGKEY_UP, FALSE);
        //UI_DetCustomerModeKey(); //jacky lan ,marked 
        if (keyDetectCount < 4)
        {
            keyDetectCount++;
        }

        if (keyDetectCount == 2)
        {
            //recover the key detection after system boot up
            GxKey_SetFirstKeyInvalid(KEY_PRESS, 0);
        }
    }
}

void UI_DetIrKey(void)
{
   UINT32 uiDataContent = 0xFFFFFFFF;

   uiDataContent = GxKey_DetIrKey();
}

void UI_DetStatusKey(void)
{
//check mode key
    if((!UI_IsForceLock())&&(!UI_IsForceLockStatus()))
        GxKey_DetStatusKey();
}

/////////////////////////////////////////////////////////////////////////////
extern void System_ResetDetCloseLenCount(void);
extern void System_ResetPowerSaveCount(void);
BOOL g_bConsumeStatus = FALSE;

INT32 System_UserKeyFilter(NVTEVT evt, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 key = evt;
    if(IN_RANGE_EVENT(key, NVTEVT_KEY_STATUS_START, NVTEVT_KEY_STATUS_END)) //Status class
    {
        System_ResetDetCloseLenCount();
        System_ResetPowerSaveCount();
#if (STATUSKEY_FUNCTION == ENABLE)
        DBG_IND("^Bgroup key event=0x%x\r\n", key);

        if(g_bConsumeStatus)
        {
            g_bConsumeStatus = 0;
        }
        else
        {
            UINT32 uiDscMode = Input_Key2Mode(key);
            DBG_IND("^YDscMode=0x%x\r\n", uiDscMode);
            //FlowMode_OnKeyMode(uiDscMode);
            UI_Switch_DscMode(uiDscMode,DSCMODE_SWITCH_FORCE,DSCMODE_SWITCHDIR_DONT_CARE);
        }
#endif
        return NVTEVT_CONSUME;
    }
    else if(IN_RANGE_EVENT(key, NVTEVT_KEY_BUTTON_START, NVTEVT_KEY_BUTTON_END)) //Button class
    {
        if(IN_RANGE_EVENT(key, NVTEVT_KEY_PRESS_START, NVTEVT_KEY_PRESS_END)) //Press key
        {
#if (_MODEL_DSC_ == _MODEL_CARDV_)
#else
		if((GPIOMap_IsLCDBacklightOn()==FALSE)&&
		(KeyScan_GetPlugDev() != 1)&&(KeyScan_GetPlugDev() != 2))
		{
			GPIOMap_TurnOnLCDBacklight();
			System_ResetPowerSaveCount();	
                   return NVTEVT_CONSUME;			
		}        
#endif		
            if(key == NVTEVT_KEY_POWER)
            {
                return NVTEVT_CONSUME;
            }

            System_ResetDetCloseLenCount();
            if(GxPower_GetControl(GXPWR_CTRL_SLEEP_LEVEL) > 1)  // drop key if sleep level > 1
            {
                //NOTE! do not set GXPWR_CTRL_SLEEP_RESET before get GXPWR_CTRL_SLEEP_LEVEL,
                //  because GXPWR_CTRL_SLEEP_LEVEL status maybe alter by sleep wakeup flow~
                System_ResetPowerSaveCount();
                return NVTEVT_CONSUME;
            }
            else
            {
                System_ResetPowerSaveCount();
                if (m_uiAnyKeyUnlockEn)
                {
                    Ux_PostEvent(NVTEVT_KEY_PRESS_START, 1, key);
                    return NVTEVT_CONSUME;
                }
                return NVTEVT_PASS;
            }
        }
        else if(IN_RANGE_EVENT(key, NVTEVT_KEY_CONTINUE_START, NVTEVT_KEY_CONTINUE_END)) //Contine key
        {
            if(key == NVTEVT_KEY_POWER_CONT)
            {
                return NVTEVT_CONSUME;
            }

            System_ResetDetCloseLenCount();
            System_ResetPowerSaveCount();
            return NVTEVT_PASS;
        }
        else if(IN_RANGE_EVENT(key, NVTEVT_KEY_RELEASE_START, NVTEVT_KEY_RELEASE_END)) //Release key
        {
            if(key == NVTEVT_KEY_POWER_REL)
            {
                System_ResetDetCloseLenCount();
                if(GxPower_GetControl(GXPWR_CTRL_SLEEP_LEVEL) > 1)  // drop key if sleep level > 1
                {
                    //NOTE! do not set GXPWR_CTRL_SLEEP_RESET before get GXPWR_CTRL_SLEEP_LEVEL,
                    //  because GXPWR_CTRL_SLEEP_LEVEL status maybe alter by sleep wakeup flow~
                    System_ResetPowerSaveCount();
                }
                else
                {
                    //g_bIsExitSystemWithPowerKey = TRUE;
		        if (System_GetState(SYS_STATE_CURRMODE)==PRIMARY_MODE_MOVIE)
		        {
		        	switch(gMovData.State)	
		        	{
		        	     case MOV_ST_REC:
				     case MOV_ST_REC|MOV_ST_ZOOM:
					//MediaRec_Stop(MEDIAREC_WAIT_END);  	
	                		FlowMovie_StopRec();				
				     break;
		        	}
		        }                       
                    System_PowerOff(SYS_POWEROFF_NORMAL);
                }
                return NVTEVT_CONSUME;
            }

            System_ResetDetCloseLenCount();
            System_ResetPowerSaveCount();
            return NVTEVT_PASS;
        }
    }
    return NVTEVT_PASS;
}
#if (TOUCH_FUNCTION == ENABLE)
#define TP_PANEL_W          (800)
#define TP_PANEL_H          (480)

static BOOL CalLCD = FALSE;
BOOL GetCALLCDMode(void)
{
    return CalLCD;
}
void SetCALLCDMode(BOOL Enb)
{
    CalLCD = Enb;
}

INT32 System_UserTouchFilter(NVTEVT evt, UINT32 paramNum, UINT32 *paramArray)
{
    INT32 Ret = NVTEVT_PASS;
    //debug_msg("^Bevt=%d, point=(%d, %d)\r\n", evt - NVTEVT_PRESS, paramArray[0], paramArray[1]);
    //DBG_DUMP("^Bevt=%d, point=(%d, %d)\r\n", evt - NVTEVT_PRESS, paramArray[0], paramArray[1]);
    if(evt >= NVTEVT_PRESS && evt <= NVTEVT_SLIDE_DOWN)
    {
        if(GxPower_GetControl(GXPWR_CTRL_SLEEP_LEVEL) > 1)  // drop key if sleep level > 1
        {
            //NOTE! do not set GXPWR_CTRL_SLEEP_RESET before get GXPWR_CTRL_SLEEP_LEVEL,
            //  because GXPWR_CTRL_SLEEP_LEVEL status maybe alter by sleep wakeup flow~
            System_ResetPowerSaveCount();
            return NVTEVT_CONSUME;
        }
        else
        {
            System_ResetPowerSaveCount();
            if(evt == NVTEVT_CLICK)
            {
                UISound_Play(DEMOSOUND_SOUND_KEY_TONE);	        
                if(((paramArray[0]>0)&&(paramArray[0]<TP_PANEL_W - 1)&&(paramArray[1]>0)&&(paramArray[1]<TP_PANEL_H - 1)) || GetCALLCDMode())
                {
	 	        Ux_PostEvent(NVTEVT_KEY_TP, 3, GESTURE_CKICK,paramArray[0],paramArray[1]);
			 //return NVTEVT_CONSUME;	
                 }
             }
            if(evt == NVTEVT_RELEASE)
            {
                //UISound_Play(DEMOSOUND_SOUND_KEY_TONE);	 
                if((paramArray[0]>0)&&(paramArray[0]<TP_PANEL_W - 1)&&(paramArray[1]>0)&&(paramArray[1]<TP_PANEL_H - 1))
                {
	 	        Ux_PostEvent(NVTEVT_KEY_TP, 1, GESTURE_RELEASE);
			 //return NVTEVT_CONSUME;	
                 }
             }	
           
            return NVTEVT_PASS;
        }
    }
    return Ret;
}
#endif

static BOOL IsReversingCarMode = FALSE;

void Set_ReversingCarMode_Status(BOOL Enb)
{
    IsReversingCarMode = Enb;
}

BOOL Get_ReversingCarMode_Status(void)
{
       return IsReversingCarMode;
}


void UI_DetReversing_CARIO(void)
{
	 static BOOL bLastReversingCarDet     = TRUE;
    static BOOL bLastReversingCarStatus  = TRUE;
    BOOL        bCurReversingCarDet, bCurReversingCarStatus;
   static BOOL 	ISReversingCar = TRUE;
   static  PIP_STYLE lastStyle =PIP_STYLE_2T1B2S;  
    static  int TimeCount = 0;
    bCurReversingCarDet = GPIOMap_Reversing_CAR();
   //debug_msg("###  IO : %d\r\n",bCurReversingCarDet);
    bCurReversingCarStatus = (BOOL)(bCurReversingCarDet & bLastReversingCarDet);

    if (bCurReversingCarStatus != bLastReversingCarStatus)
    {
       
        if (bCurReversingCarStatus == FALSE)
        {
            System_ResetPowerSaveCount();
            if (!GPIOMap_IsLCDBacklightOn())
    	    {
    		GPIOMap_TurnOnLCDBacklight();
    	    }
           ISReversingCar = TRUE;
		   TimeCount = 0;
		   
		   lastStyle = PipView_GetStyle();
		   debug_msg("#### Reversin CAR  Start   %d:%d \r\n",lastStyle,PIP_STYLE_2T2F);
		PipView_SetStyle(PIP_STYLE_2T2F);
        Set_ReversingCarMode_Status(TRUE);
        }
        
        else
        {
        debug_msg("#### Reversin CAR  end  \r\n");
         ISReversingCar = FALSE;
		 TimeCount = 0;
        }
    }

	if(!ISReversingCar)
		{
		//TimeCount ++;
		//if(TimeCount >=  6)//(TimeCount >=  26)//5 sec
			{
			  System_ResetPowerSaveCount();
                        if (!GPIOMap_IsLCDBacklightOn())
                	{
                		GPIOMap_TurnOnLCDBacklight();
                	}
			ISReversingCar = TRUE;
			debug_msg("#### back to last mode :%d  \r\n",lastStyle);
			PipView_SetStyle(lastStyle);
            Set_ReversingCarMode_Status(FALSE);
			}
		}
    bLastReversingCarDet     = bCurReversingCarDet;
    bLastReversingCarStatus  = bCurReversingCarStatus;
}
