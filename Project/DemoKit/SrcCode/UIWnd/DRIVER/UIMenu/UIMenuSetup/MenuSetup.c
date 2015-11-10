#include <stdio.h>
#include "UIFlow.h"
#include "UIFlowWndSetup_datetime.h"
#include "UIFlowWndCalLCD.h"
#if 1
// --------------------------------------------------------------------------
// OPTIONS
// --------------------------------------------------------------------------
// Power Saving Options
TMDEF_BEGIN_OPTIONS(AUTO_POWER_OFF)
    TMDEF_OPTION_TEXT(OFF)
    TMDEF_OPTION_TEXT(3MIN)
    TMDEF_OPTION_TEXT(5MIN)
    TMDEF_OPTION_TEXT(10MIN)
TMDEF_END_OPTIONS()


// Beep Options
TMDEF_BEGIN_OPTIONS(BEEP)
    TMDEF_OPTION_TEXT(BEEP_OFF)
    TMDEF_OPTION_TEXT(BEEP_ON)
TMDEF_END_OPTIONS()


// Language Options
#if (UPDATE_CFG == UPDATE_CFG_YES)
TM_OPTION gTM_OPTIONS_LANGUAGE[LANG_ID_MAX] = {0};
#else
TMDEF_BEGIN_OPTIONS(LANGUAGE)
    TMDEF_OPTION_TEXT(LANG_EN)
    TMDEF_OPTION_TEXT(LANG_FR)
    TMDEF_OPTION_TEXT(LANG_ES)
    TMDEF_OPTION_TEXT(LANG_PO)
    TMDEF_OPTION_TEXT(LANG_DE)
    TMDEF_OPTION_TEXT(LANG_IT)
    TMDEF_OPTION_TEXT(LANG_SC)
    TMDEF_OPTION_TEXT(LANG_TC)
    TMDEF_OPTION_TEXT(LANG_RU)
    TMDEF_OPTION_TEXT(LANG_JP)
TMDEF_END_OPTIONS()
#endif

// TV Mode Options
TMDEF_BEGIN_OPTIONS(TV_MODE)
    TMDEF_OPTION_TEXT(TV_NTSC)
    TMDEF_OPTION_TEXT(TV_PAL)
TMDEF_END_OPTIONS()


// Frequency Options
TMDEF_BEGIN_OPTIONS(FREQUENCY)
    TMDEF_OPTION_TEXT(50HZ)
    TMDEF_OPTION_TEXT(60HZ)
TMDEF_END_OPTIONS()

// Frequency Options
TMDEF_BEGIN_OPTIONS(LEDSET)
    TMDEF_OPTION_TEXT(LEDSET_OFF)
    TMDEF_OPTION_TEXT(LEDSET_ON)
TMDEF_END_OPTIONS()

// Sensor Rotate Options
TMDEF_BEGIN_OPTIONS(SENSOR_ROTATE)
    TMDEF_OPTION_TEXT(SENSOR_ROTATE_OFF)
    TMDEF_OPTION_TEXT(SENSOR_ROTATE_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(LCDOFF)
    TMDEF_OPTION_TEXT(LCDOFF_OFF)
    TMDEF_OPTION_TEXT(LCDOFF_30SEC)
    TMDEF_OPTION_TEXT(LCDOFF_1MIN)
    TMDEF_OPTION_TEXT(LCDOFF_2MIN)    
TMDEF_END_OPTIONS()
// Delay off Options
TMDEF_BEGIN_OPTIONS(DELAYOFF)
    TMDEF_OPTION_TEXT(DELAYOFF_OFF)
    TMDEF_OPTION_TEXT(DELAYOFF_10SEC)
    TMDEF_OPTION_TEXT(DELAYOFF_20SEC)
    TMDEF_OPTION_TEXT(DELAYOFF_30SEC)
TMDEF_END_OPTIONS()

// --------------------------------------------------------------------------
// ITEMS
// --------------------------------------------------------------------------
static int MenuCustom_DateTime(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIFlowWndSetup_datetimeCtrl, 0);
    return TMF_PROCESSED;
}


static int MenuCustom_CalLcd(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIFlowWndCalLCDCtrl, 0);
    return TMF_PROCESSED;
}
static int MenuCustom_Format(UINT32 uiMessage, UINT32 uiParam)
{
    //Ux_OpenWindow(&UIMenuWndSetupFormatCtrl, 0);
    Ux_OpenWindow(&UIMenuWndSetupFormatConfirmCtrl, 0);
    return TMF_PROCESSED;
}

static int MenuCustom_Default(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIMenuWndSetupDefaultSettingCtrl, 0);
    return TMF_PROCESSED;
}

static int MenuCustom_Version(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIMenuWndSetupVersionCtrl, 0);
    return TMF_PROCESSED;
}

// Setup Menu Items
TMDEF_BEGIN_ITEMS(SETUP)
    //TMDEF_ITEM_CUSTOM(DATE_TIME, MenuCustom_DateTime)
    TMDEF_ITEM_CUSTOM(CAL_LCD, MenuCustom_CalLcd)
    TMDEF_ITEM_TEXTID(AUTO_POWER_OFF)
    //TMDEF_ITEM_TEXTID(BEEP)
    TMDEF_ITEM_TEXTID(TV_MODE)
    TMDEF_ITEM_TEXTID(LANGUAGE)
    TMDEF_ITEM_CUSTOM(VERSION, MenuCustom_Version)
    TMDEF_ITEM_TEXTID(FREQUENCY)
    //TMDEF_ITEM_TEXTID(SENSOR_ROTATE)
    TMDEF_ITEM_CUSTOM(FORMAT, MenuCustom_Format)
#if (_MODEL_DSC_ != _MODEL_CARDV_)    
    TMDEF_ITEM_TEXTID(LCDOFF)        
#endif    
    //TMDEF_ITEM_TEXTID(LEDSET)    

    TMDEF_ITEM_TEXTID(DELAYOFF)    
    TMDEF_ITEM_CUSTOM(DEFAULT, MenuCustom_Default)
TMDEF_END_ITEMS()
#endif

TMDEF_BEGIN_PAGES(SETUP)
    TMDEF_PAGE_TEXT_ICON(SETUP)
TMDEF_END_PAGES()

TMDEF_EMNU(gSetupMenu, SETUP, Setup_MenuCallback)
// --------------------------------------------------------------------------
// Menu Callback
// --------------------------------------------------------------------------
int Setup_MenuCallback(UINT32 uiMessage, UINT32 uiParam)
{
    UINT16  uwItemId;
    UINT16  uwOption;

    if (uiMessage == TMM_CONFIRM_OPTION)
    {
        uwItemId = LO_WORD(uiParam);
        uwOption = HI_WORD(uiParam);

        switch (uwItemId)
        {
        case IDM_AUTO_POWER_OFF:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_POWEROFF, 1, uwOption);
            break;

        case IDM_BEEP:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_BEEPKEY, 1, uwOption);
            break;

        case IDM_LANGUAGE:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_LANGUAGE, 1, uwOption);
            break;

        case IDM_TV_MODE:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_TVFORMAT, 1, uwOption);
            break;

        case IDM_FREQUENCY:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_FREQ, 1, uwOption);
            break;

        case IDM_SENSOR_ROTATE:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_SENSOR_ROTATE, 1, uwOption);
            break;
        case IDM_LCDOFF:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_LCDOFF, 1, uwOption);
            break;

        case IDM_LEDSET:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_LED, 1, uwOption);
            break;			
        case IDM_DELAYOFF:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_DELAYOFF, 1, uwOption);
            break;

        }
    }

    return TMF_PROCESSED;
}


#if 1
TMDEF_BEGIN_OPTIONS(USER_SPEED_LIMIT)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_OFF)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_80)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_90)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_100)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_110)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_120)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_130)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_140)
    TMDEF_OPTION_TEXT(USER_SPEED_LIMIT_150)
    
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(CITYMODE_SPEEDLIMIT)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_20)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_30)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_40)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_50)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_60)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_70)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_80)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_90)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_100)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_110)
    TMDEF_OPTION_TEXT(CITYMODE_SPEEDLIMIT_120)
TMDEF_END_OPTIONS()
TMDEF_BEGIN_OPTIONS(RADAR_REPORT)
    TMDEF_OPTION_TEXT(RADAR_REPORT_OFF)
    TMDEF_OPTION_TEXT(RADAR_REPORT_ON)
TMDEF_END_OPTIONS()
TMDEF_BEGIN_OPTIONS(RADAR_K_REPORT)
    TMDEF_OPTION_TEXT(RADAR_K_REPORT_OFF)
    TMDEF_OPTION_TEXT(RADAR_K_REPORT_ON)
TMDEF_END_OPTIONS()
TMDEF_BEGIN_OPTIONS(RADAR_KA_REPORT)
    TMDEF_OPTION_TEXT(RADAR_KA_REPORT_OFF)
    TMDEF_OPTION_TEXT(RADAR_KA_REPORT_ON)
TMDEF_END_OPTIONS()
TMDEF_BEGIN_OPTIONS(RADAR_X_REPORT)
    TMDEF_OPTION_TEXT(RADAR_X_REPORT_OFF)
    TMDEF_OPTION_TEXT(RADAR_X_REPORT_ON)
TMDEF_END_OPTIONS()
TMDEF_BEGIN_OPTIONS(DRIVING_MODE)
    TMDEF_OPTION_TEXT(DRIVING_MODE_ALL)
    TMDEF_OPTION_TEXT(DRIVING_MODE_SAFE)
    TMDEF_OPTION_TEXT(DRIVING_MODE_EYE)
    TMDEF_OPTION_TEXT(DRIVING_MODE_OFF)
TMDEF_END_OPTIONS()
TMDEF_BEGIN_OPTIONS(SPEED_Correction)
    TMDEF_OPTION_TEXT(SPEED_Correction_OFF)
    TMDEF_OPTION_TEXT(SPEED_Correction_2)
    TMDEF_OPTION_TEXT(SPEED_Correction_4)
    TMDEF_OPTION_TEXT(SPEED_Correction_6)
    TMDEF_OPTION_TEXT(SPEED_Correction_8)
    TMDEF_OPTION_TEXT(SPEED_Correction_10)
TMDEF_END_OPTIONS()
TMDEF_BEGIN_OPTIONS(RADAR_ONOFF)
TMDEF_OPTION_TEXT(RADAR_SET_OFF)
TMDEF_OPTION_TEXT(RADAR_SET_ON)
/*
    TMDEF_OPTION_TEXT(RADAR_VOL_OFF)
    TMDEF_OPTION_TEXT(RADAR_VOL_1)
    TMDEF_OPTION_TEXT(RADAR_VOL_2)
    TMDEF_OPTION_TEXT(RADAR_VOL_3)
    TMDEF_OPTION_TEXT(RADAR_VOL_4)
    TMDEF_OPTION_TEXT(RADAR_VOL_5)
    TMDEF_OPTION_TEXT(RADAR_VOL_6)
    TMDEF_OPTION_TEXT(RADAR_VOL_7)
    TMDEF_OPTION_TEXT(RADAR_VOL_8)
    TMDEF_OPTION_TEXT(RADAR_VOL_9)
    */
TMDEF_END_OPTIONS()

// Setup Menu Items
TMDEF_BEGIN_ITEMS(RADAR)
    TMDEF_ITEM_TEXTID(USER_SPEED_LIMIT)
    TMDEF_ITEM_TEXTID(CITYMODE_SPEEDLIMIT)
    TMDEF_ITEM_TEXTID(RADAR_REPORT)
    //TMDEF_ITEM_TEXTID(RADAR_K_REPORT)
    //TMDEF_ITEM_TEXTID(RADAR_KA_REPORT)
    TMDEF_ITEM_TEXTID(RADAR_X_REPORT) 
    TMDEF_ITEM_TEXTID(DRIVING_MODE)         
    TMDEF_ITEM_TEXTID(SPEED_Correction)    
    TMDEF_ITEM_TEXTID(RADAR_ONOFF)    
TMDEF_END_ITEMS()


TMDEF_BEGIN_PAGES(RADAR)
    TMDEF_PAGE_TEXT_ICON(RADAR)
TMDEF_END_PAGES()

TMDEF_EMNU(gRadarMenu, RADAR, Radar_MenuCallback)


// --------------------------------------------------------------------------
// Menu Callback
// --------------------------------------------------------------------------
int Radar_MenuCallback(UINT32 uiMessage, UINT32 uiParam)
{
    UINT16  uwItemId;
    UINT16  uwOption;
    char Data;

    if (uiMessage == TMM_CONFIRM_OPTION)
    {
        uwItemId = LO_WORD(uiParam);
        uwOption = HI_WORD(uiParam);
        
        switch (uwItemId)
        {

        case IDM_USER_SPEED_LIMIT:
            //sprintf(&Data,"%x",uwOption+7);
            RD_PutCommand(USER_SPEED_LIMIT, uwOption+7);
            UI_SetData(FL_USER_SPEED_LIMIT,uwOption);
            break;

        case IDM_CITYMODE_SPEEDLIMIT:
            //sprintf(&Data,"%x",uwOption+2);
            RD_PutCommand(CITYMODE_SPEEDLIMIT, uwOption+2);
            UI_SetData(FL_CITYMODE_SPEEDLIMIT,uwOption);
            break;

        case IDM_RADAR_REPORT:
            //sprintf(&Data,"%x",uwOption);
            RD_PutCommand(RADAR_REPORT, uwOption);
            UI_SetData(FL_RADAR_REPORT,uwOption);
            break;

        case IDM_RADAR_K_REPORT:
            //sprintf(&Data,"%x",uwOption);
            RD_PutCommand(RADAR_X_REPORT, uwOption);
            UI_SetData(FL_RADAR_K_REPORT,uwOption);
            break;

        case IDM_RADAR_KA_REPORT:
            //sprintf(&Data,"%c",uwOption);
            RD_PutCommand(0x55, uwOption);
            UI_SetData(FL_RADAR_KA_REPORT,uwOption);
            break;

        case IDM_RADAR_X_REPORT:
            //sprintf(&Data,"%x",uwOption);
            RD_PutCommand(RADAR_X_REPORT, uwOption);
            UI_SetData(FL_RADAR_X_REPORT,uwOption);
            break;
        case IDM_DRIVING_MODE:
            //sprintf(&Data,"%x",uwOption+5);
            RD_PutCommand(DRIVING_MODE, uwOption+5);
            UI_SetData(FL_DRIVING_MODE,uwOption);
            break;

        case IDM_SPEED_Correction:
            //sprintf(&Data,"%x",uwOption);
            RD_PutCommand(SPEED_Correction, uwOption);
            UI_SetData(FL_SPEED_Correction,uwOption);
            break;			
        case IDM_RADAR_ONOFF:
            //sprintf(&Data,"%x",uwOption);
            RD_PutCommand(RADAR_ONOFF, uwOption);
            UI_SetData(FL_RADAR_ONOFF,uwOption);
            break;

        }
    }

    return TMF_PROCESSED;
}
#endif