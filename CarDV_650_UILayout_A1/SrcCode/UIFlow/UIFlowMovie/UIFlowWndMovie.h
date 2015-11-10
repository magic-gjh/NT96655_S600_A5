//This source code is generated by UI Designer Studio.

#ifndef UIFLOWWNDMOVIE_H
#define UIFLOWWNDMOVIE_H

#include "UIFramework.h"

extern VControl UIFlowWndMovieCtrl;//Panel type 

extern VControl UIFlowWndMovie_RecPanelCtrl;//Panel type 

extern VControl UIFlowWndMovie_ResolutionCtrl;//Static type 

extern VControl UIFlowWndMovie_Status_batteryCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Status_battery_ICON_BATTERY_FULL,
UIFlowWndMovie_Status_battery_ICON_BATTERY_MED,
UIFlowWndMovie_Status_battery_ICON_BATTERY_LOW,
UIFlowWndMovie_Status_battery_ICON_BATTERY_EMPTY,
UIFlowWndMovie_Status_battery_ICON_BATTERY_ZERO,
UIFlowWndMovie_Status_battery_ICON_BATTERY_CHARGE,
UIFlowWndMovie_Status_battery_MAX
}UIFlowWndMovie_Status_battery_Setting;

extern VControl UIFlowWndMovie_Status_ReturnCtrl;//List type 

typedef enum
{
UIFlowWndMovie_Status_Return_STRID_NULL_,
UIFlowWndMovie_Status_Return_MAX
}UIFlowWndMovie_Status_Return_Setting;

extern VControl UIFlowWndMovie_Radar_ModeCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Radar_Mode_ICON_HIGHSPEED_MODE,
UIFlowWndMovie_Radar_Mode_ICON_CITY_MODE,
UIFlowWndMovie_Radar_Mode_MAX
}UIFlowWndMovie_Radar_Mode_Setting;

extern VControl UIFlowWndMovie_Radar_VolCtrl;//Static type 

extern VControl UIFlowWndMovie_Radar_Vol_LvlCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_0,
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_2,
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_3,
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_4,
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_5,
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_6,
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_7,
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_8,
UIFlowWndMovie_Radar_Vol_Lvl_ICON_VOL_NUM_9,
UIFlowWndMovie_Radar_Vol_Lvl_MAX
}UIFlowWndMovie_Radar_Vol_Lvl_Setting;

extern VControl UIFlowWndMovie_AngleCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Angle_ICON_E,
UIFlowWndMovie_Angle_ICON_ES,
UIFlowWndMovie_Angle_ICON_S,
UIFlowWndMovie_Angle_ICON_WS,
UIFlowWndMovie_Angle_ICON_W,
UIFlowWndMovie_Angle_ICON_WN,
UIFlowWndMovie_Angle_ICON_N,
UIFlowWndMovie_Angle_ICON_EN,
UIFlowWndMovie_Angle_MAX
}UIFlowWndMovie_Angle_Setting;

extern VControl UIFlowWndMovie_Icon_GPSCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Icon_GPS_ICON_GPS_OFF_RD_DIS,
UIFlowWndMovie_Icon_GPS_ICON_GPS_OFF_RD_EN,
UIFlowWndMovie_Icon_GPS_ICON_GPS_ON_RD_DIS,
UIFlowWndMovie_Icon_GPS_ICON_GPS_ON_RD_EN,
UIFlowWndMovie_Icon_GPS_MAX
}UIFlowWndMovie_Icon_GPS_Setting;

extern VControl UIFlowWndMovie_Icon_Speed_limit_PanelCtrl;//Panel type 

extern VControl UIFlowWndMovie_Panel_WarHighSpeedCtrl;//Panel type 

extern VControl UIFlowWndMovie_Speed_HCtrl;//Static type 

extern VControl UIFlowWndMovie_Speed_MCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Speed_M_ICON_RADAR_WAR_0,
UIFlowWndMovie_Speed_M_ICON_RADAR_WAR_1,
UIFlowWndMovie_Speed_M_ICON_RADAR_WAR_2,
UIFlowWndMovie_Speed_M_MAX
}UIFlowWndMovie_Speed_M_Setting;

extern VControl UIFlowWndMovie_Speed_LCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_0,
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_1,
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_2,
UIFlowWndMovie_Speed_L_ICON_RD_EYE_OFF,
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_4,
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_5,
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_6,
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_7,
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_8,
UIFlowWndMovie_Speed_L_ICON_RADAR_WAR_9,
UIFlowWndMovie_Speed_L_MAX
}UIFlowWndMovie_Speed_L_Setting;

extern VControl UIFlowWndMovie_Panel_WarLowSpeedCtrl;//Panel type 

extern VControl UIFlowWndMovie_Speed_LowModeHCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_0,
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_1,
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_2,
UIFlowWndMovie_Speed_LowModeH_ICON_RD_EYE_OFF,
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_4,
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_5,
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_6,
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_7,
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_8,
UIFlowWndMovie_Speed_LowModeH_ICON_RADAR_WAR_9,
UIFlowWndMovie_Speed_LowModeH_MAX
}UIFlowWndMovie_Speed_LowModeH_Setting;

extern VControl UIFlowWndMovie_Speed_LowModeLCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_0,
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_1,
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_2,
UIFlowWndMovie_Speed_LowModeL_ICON_RD_EYE_OFF,
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_4,
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_5,
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_6,
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_7,
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_8,
UIFlowWndMovie_Speed_LowModeL_ICON_RADAR_WAR_9,
UIFlowWndMovie_Speed_LowModeL_MAX
}UIFlowWndMovie_Speed_LowModeL_Setting;

extern VControl UIFlowWndMovie_Panel_WarningCtrl;//Panel type 

extern VControl UIFlowWndMovie_Panel_Warning_TypeCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Panel_Warning_Type_ICON_REDLED,
UIFlowWndMovie_Panel_Warning_Type_ICON_RADAR_JG,
UIFlowWndMovie_Panel_Warning_Type_ICON_RD_WAR_EYE,
UIFlowWndMovie_Panel_Warning_Type_MAX
}UIFlowWndMovie_Panel_Warning_Type_Setting;

extern VControl UIFlowWndMovie_DistanceCtrl;//Panel type 

extern VControl UIFlowWndMovie_Distance_HCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Distance_H_ICON_DISTANCE_0,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_1,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_2,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_3,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_4,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_5,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_6,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_7,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_8,
UIFlowWndMovie_Distance_H_ICON_DISTANCE_9,
UIFlowWndMovie_Distance_H_MAX
}UIFlowWndMovie_Distance_H_Setting;

extern VControl UIFlowWndMovie_Distance_MCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Distance_M_ICON_DISTANCE_0,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_1,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_2,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_3,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_4,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_5,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_6,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_7,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_8,
UIFlowWndMovie_Distance_M_ICON_DISTANCE_9,
UIFlowWndMovie_Distance_M_MAX
}UIFlowWndMovie_Distance_M_Setting;

extern VControl UIFlowWndMovie_Distance_LCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Distance_L_ICON_DISTANCE_0,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_1,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_2,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_3,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_4,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_5,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_6,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_7,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_8,
UIFlowWndMovie_Distance_L_ICON_DISTANCE_9,
UIFlowWndMovie_Distance_L_MAX
}UIFlowWndMovie_Distance_L_Setting;

extern VControl UIFlowWndMovie_Distance_UintCtrl;//Static type 

extern VControl UIFlowWndMovie_CurSpeedCtrl;//Panel type 

extern VControl UIFlowWndMovie_CurSpeed_HCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_0,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_1,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_2,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_3,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_4,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_5,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_6,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_7,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_8,
UIFlowWndMovie_CurSpeed_H_ICON_NUM_B_9,
UIFlowWndMovie_CurSpeed_H_MAX
}UIFlowWndMovie_CurSpeed_H_Setting;

extern VControl UIFlowWndMovie_CurSpeed_MCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_0,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_1,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_2,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_3,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_4,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_5,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_6,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_7,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_8,
UIFlowWndMovie_CurSpeed_M_ICON_NUM_B_9,
UIFlowWndMovie_CurSpeed_M_MAX
}UIFlowWndMovie_CurSpeed_M_Setting;

extern VControl UIFlowWndMovie_CurSpeed_LCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_0,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_1,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_2,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_3,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_4,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_5,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_6,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_7,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_8,
UIFlowWndMovie_CurSpeed_L_ICON_NUM_B_9,
UIFlowWndMovie_CurSpeed_L_MAX
}UIFlowWndMovie_CurSpeed_L_Setting;

extern VControl UIFlowWndMovie_CurSpeed_UintCtrl;//Static type 

extern VControl UIFlowWndMovie_Status_StorageCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Status_Storage_ICONID_NULL,
UIFlowWndMovie_Status_Storage_ICON_SD_CARD,
UIFlowWndMovie_Status_Storage_MAX
}UIFlowWndMovie_Status_Storage_Setting;

extern VControl UIFlowWndMovie_Icon_Radar_WaringCtrl;//Panel type 

extern VControl UIFlowWndMovie_Icon_Radar_Waring_Panel_WarningCtrl;//Panel type 

extern VControl UIFlowWndMovie_Icon_Radar_Waring_Panel_Warning_TypeCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Icon_Radar_Waring_Panel_Warning_Type_ICON_HZ_K,
UIFlowWndMovie_Icon_Radar_Waring_Panel_Warning_Type_ICON_HZ_KA,
UIFlowWndMovie_Icon_Radar_Waring_Panel_Warning_Type_ICON_HZ_X,
UIFlowWndMovie_Icon_Radar_Waring_Panel_Warning_Type_MAX
}UIFlowWndMovie_Icon_Radar_Waring_Panel_Warning_Type_Setting;

extern VControl UIFlowWndMovie_Icon_Radar_SingalLvlCtrl;//Panel type 

extern VControl UIFlowWndMovie_Icon_Radar_SingalLvl_IconCtrl;//Static type 

extern VControl UIFlowWndMovie_Icon_Radar_SingalLvl_Panel0Ctrl;//Panel type 

extern VControl Static93Ctrl;//Static type 

extern VControl Static94Ctrl;//Static type 

extern VControl Static95Ctrl;//Static type 

extern VControl Static95CCtrl;//Static type 

extern VControl UIFlowWndMovie_Icon_RD_EYECtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Icon_RD_EYE_ICON_RD_EYE_OFF,
UIFlowWndMovie_Icon_RD_EYE_ICON_RD_EYE_ON,
UIFlowWndMovie_Icon_RD_EYE_MAX
}UIFlowWndMovie_Icon_RD_EYE_Setting;

extern VControl UIFlowWndMovie_Icon_RD_ONCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Icon_RD_ON_ICON_RD_OFF,
UIFlowWndMovie_Icon_RD_ON_ICON_RD_ON,
UIFlowWndMovie_Icon_RD_ON_MAX
}UIFlowWndMovie_Icon_RD_ON_Setting;

extern VControl UIFlowWndMovie_TXT_RECCtrl;//Static type 

extern VControl UIFlowWndMovie_GPSDBCtrl;//Static type 

extern VControl UIFlowWndMovie_AudioCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_Audio_ICON_VOICE_ON,
UIFlowWndMovie_Audio_ICON_VOICE_OFF,
UIFlowWndMovie_Audio_MAX
}UIFlowWndMovie_Audio_Setting;

extern VControl UIFlowWndMovie_LockCtrl;//Static type 

extern VControl UIFlowWndMovie_HMSCtrl;//Panel type 

extern VControl UIFlowWndMovie_HMS_Hour_HCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_0,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_1,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_2,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_3,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_4,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_5,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_6,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_7,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_8,
UIFlowWndMovie_HMS_Hour_H_ICON_TIME_9,
UIFlowWndMovie_HMS_Hour_H_MAX
}UIFlowWndMovie_HMS_Hour_H_Setting;

extern VControl UIFlowWndMovie_HMS_Hour_LCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_0,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_1,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_2,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_3,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_4,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_5,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_6,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_7,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_8,
UIFlowWndMovie_HMS_Hour_L_ICON_TIME_9,
UIFlowWndMovie_HMS_Hour_L_MAX
}UIFlowWndMovie_HMS_Hour_L_Setting;

extern VControl UIFlowWndMovie_HMS_Dot1Ctrl;//Static type 

extern VControl UIFlowWndMovie_HMS_Min_HCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_HMS_Min_H_ICON_TIME_0,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_1,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_2,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_3,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_4,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_5,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_6,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_7,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_8,
UIFlowWndMovie_HMS_Min_H_ICON_TIME_9,
UIFlowWndMovie_HMS_Min_H_MAX
}UIFlowWndMovie_HMS_Min_H_Setting;

extern VControl UIFlowWndMovie_HMS_Min_LCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_HMS_Min_L_ICON_TIME_0,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_1,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_2,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_3,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_4,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_5,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_6,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_7,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_8,
UIFlowWndMovie_HMS_Min_L_ICON_TIME_9,
UIFlowWndMovie_HMS_Min_L_MAX
}UIFlowWndMovie_HMS_Min_L_Setting;

extern VControl UIFlowWndMovie_HMS_Dot2Ctrl;//Static type 

extern VControl UIFlowWndMovie_HMS_Sec_HCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_0,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_1,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_2,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_3,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_4,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_5,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_6,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_7,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_8,
UIFlowWndMovie_HMS_Sec_H_ICON_TIME_9,
UIFlowWndMovie_HMS_Sec_H_MAX
}UIFlowWndMovie_HMS_Sec_H_Setting;

extern VControl UIFlowWndMovie_HMS_Sec_LCtrl;//Status type 

typedef enum
{
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_0,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_1,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_2,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_3,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_4,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_5,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_6,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_7,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_8,
UIFlowWndMovie_HMS_Sec_L_ICON_TIME_9,
UIFlowWndMovie_HMS_Sec_L_MAX
}UIFlowWndMovie_HMS_Sec_L_Setting;

extern VControl UIFlowWndMovie_Status_RECCtrl;//List type 

typedef enum
{
UIFlowWndMovie_Status_REC_STRID_NULL_,
UIFlowWndMovie_Status_REC_MAX
}UIFlowWndMovie_Status_REC_Setting;

//---------------------UIFlowWndMovieCtrl User Export---------------------------
#endif
