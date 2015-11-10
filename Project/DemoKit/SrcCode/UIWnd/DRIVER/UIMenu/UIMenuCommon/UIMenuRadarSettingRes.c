//This source code is generated by UI Designer Studio.

#ifndef UIMENURADARSETTINGRES_H
#define UIMENURADARSETTINGRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,799,479,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,799,479)

SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,214,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text5,0,1,213,26,STRID_NULL,0,0,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal2)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_BODY(Text5)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal2,21,15,235,42)

SHOW_MAP_BEGIN(UIMenuRadarSetting_TXT_Title)
SHOW_MAP_BODY(Normal2)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_TXT_Title)
CREATE_STATIC_DATA(UIMenuRadarSetting_TXT_Title,STRID_RADAR_SET_TITLE)
CREATE_STATIC_CTRL(UIMenuRadarSetting_TXT_Title,0,21,15,235,42)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image9, 18, 6, 49,37, ICON_TIME_SET_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin8Rect,0,0,151,47,0,0,13,13,0,0,0)
SHOW_MAP_BEGIN(Skin8)
SHOW_MAP_BODY(Skin8Rect)
SHOW_MAP_BODY(Image9)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin8,0,0,151,47)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text11,58,16,137,31,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal7)
SHOW_MAP_BODY(Skin8)
SHOW_MAP_BODY(Text11)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal7,648,0,799,47)

SHOW_ITEM_IMAGE(CMD_Image,Image14, 18, 6, 49,37, ICON_TIME_SET_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin13Rect,0,0,151,47,0,0,13,13,0,0,0)
SHOW_MAP_BEGIN(Skin13)
SHOW_MAP_BODY(Skin13Rect)
SHOW_MAP_BODY(Image14)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin13,0,0,151,47)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text16,58,16,137,31,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused12)
SHOW_MAP_BODY(Skin13)
SHOW_MAP_BODY(Text16)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused12,648,0,799,47)

SHOW_ITEM_IMAGE(CMD_Image,Image19, 18, 6, 49,37, ICON_TIME_SET_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin18Rect,0,0,151,47,0,0,13,13,0,0,0)
SHOW_MAP_BEGIN(Skin18)
SHOW_MAP_BODY(Skin18Rect)
SHOW_MAP_BODY(Image19)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin18,0,0,151,47)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text21,58,16,137,31,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable17)
SHOW_MAP_BODY(Skin18)
SHOW_MAP_BODY(Text21)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable17,648,0,799,47)

SHOW_ITEM_IMAGE(CMD_Image,Image24, 18, 6, 49,37, ICON_TIME_SET_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin23Rect,0,0,151,47,0,0,13,13,0,0,0)
SHOW_MAP_BEGIN(Skin23)
SHOW_MAP_BODY(Skin23Rect)
SHOW_MAP_BODY(Image24)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin23,0,0,151,47)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text26,58,16,137,31,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable22)
SHOW_MAP_BODY(Skin23)
SHOW_MAP_BODY(Text26)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable22,648,0,799,47)

SHOW_ITEM_IMAGE(CMD_Image,Image29, 18, 6, 49,37, ICON_TIME_SET_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin28Rect,0,0,151,47,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin28)
SHOW_MAP_BODY(Skin28Rect)
SHOW_MAP_BODY(Image29)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin28,0,0,151,47)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text31,58,16,137,31,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed27)
SHOW_MAP_BODY(Skin28)
SHOW_MAP_BODY(Text31)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed27,648,0,799,47)

CREATE_LIST_ITEM_DATA(STRID_RETURN_FORWARD32,STRID_RETURN_FORWARD,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuRadarSetting_Status_Return)
SHOW_MAP_BODY(Normal7)
SHOW_MAP_BODY(Focused12)
SHOW_MAP_BODY(Normal_Disable17)
SHOW_MAP_BODY(Focused_Disable22)
SHOW_MAP_BODY(Pressed27)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_Status_Return)
LIST_LIST_BEGIN(UIMenuRadarSetting_Status_Return)
LIST_LIST_ITEM(STRID_RETURN_FORWARD32)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuRadarSetting_Status_Return,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuRadarSetting_Status_Return,UIMenuRadarSetting_Status_Return,0,648,0,799,47)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image35, 30, 36, 124,120, ICON_MENU_RADAR_USER_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text37,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin34Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin34)
SHOW_MAP_BODY(Skin34Rect)
SHOW_MAP_BODY(Image35)
SHOW_MAP_BODY(Text37)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin34,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text39,69,135,151,151,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal33)
SHOW_MAP_BODY(Skin34)
SHOW_MAP_BODY(Text39)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal33,0,59,153,263)

SHOW_ITEM_IMAGE(CMD_Image,Image42, 30, 36, 124,120, ICON_MENU_RADAR_USER_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text44,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin41Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin41)
SHOW_MAP_BODY(Skin41Rect)
SHOW_MAP_BODY(Image42)
SHOW_MAP_BODY(Text44)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin41,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text46,69,135,151,151,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused40)
SHOW_MAP_BODY(Skin41)
SHOW_MAP_BODY(Text46)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused40,0,59,153,263)

SHOW_ITEM_IMAGE(CMD_Image,Image49, 30, 36, 124,120, ICON_MENU_RADAR_USER_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text51,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin48Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin48)
SHOW_MAP_BODY(Skin48Rect)
SHOW_MAP_BODY(Image49)
SHOW_MAP_BODY(Text51)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin48,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text53,69,135,151,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable47)
SHOW_MAP_BODY(Skin48)
SHOW_MAP_BODY(Text53)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable47,0,59,153,263)

SHOW_ITEM_IMAGE(CMD_Image,Image56, 30, 36, 124,120, ICON_MENU_RADAR_USER_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text58,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin55Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin55)
SHOW_MAP_BODY(Skin55Rect)
SHOW_MAP_BODY(Image56)
SHOW_MAP_BODY(Text58)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin55,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text60,69,135,151,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable54)
SHOW_MAP_BODY(Skin55)
SHOW_MAP_BODY(Text60)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable54,0,59,153,263)

SHOW_ITEM_IMAGE(CMD_Image,Image63, 30, 36, 124,120, ICON_MENU_RADAR_USER_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text65,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin62Rect,0,0,153,204,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin62)
SHOW_MAP_BODY(Skin62Rect)
SHOW_MAP_BODY(Image63)
SHOW_MAP_BODY(Text65)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin62,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text67,69,135,151,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed61)
SHOW_MAP_BODY(Skin62)
SHOW_MAP_BODY(Text67)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed61,0,59,153,263)

CREATE_LIST_ITEM_DATA(STRID_USER68,STRID_USER,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuRadarSetting_Status_UserSpeedLimit)
SHOW_MAP_BODY(Normal33)
SHOW_MAP_BODY(Focused40)
SHOW_MAP_BODY(Normal_Disable47)
SHOW_MAP_BODY(Focused_Disable54)
SHOW_MAP_BODY(Pressed61)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_Status_UserSpeedLimit)
LIST_LIST_BEGIN(UIMenuRadarSetting_Status_UserSpeedLimit)
LIST_LIST_ITEM(STRID_USER68)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuRadarSetting_Status_UserSpeedLimit,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuRadarSetting_Status_UserSpeedLimit,UIMenuRadarSetting_Status_UserSpeedLimit,0,0,59,153,263)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image71, 30, 36, 124,120, ICON_MENU_RADAR_CITYMODE_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text73,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin70Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin70)
SHOW_MAP_BODY(Skin70Rect)
SHOW_MAP_BODY(Image71)
SHOW_MAP_BODY(Text73)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin70,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text75,70,136,152,152,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal69)
SHOW_MAP_BODY(Skin70)
SHOW_MAP_BODY(Text75)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal69,161,58,314,262)

SHOW_ITEM_IMAGE(CMD_Image,Image78, 30, 36, 124,120, ICON_MENU_RADAR_CITYMODE_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text80,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin77Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin77)
SHOW_MAP_BODY(Skin77Rect)
SHOW_MAP_BODY(Image78)
SHOW_MAP_BODY(Text80)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin77,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text82,70,136,152,152,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused76)
SHOW_MAP_BODY(Skin77)
SHOW_MAP_BODY(Text82)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused76,161,58,314,262)

SHOW_ITEM_IMAGE(CMD_Image,Image85, 30, 36, 124,120, ICON_MENU_RADAR_CITYMODE_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text87,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin84Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin84)
SHOW_MAP_BODY(Skin84Rect)
SHOW_MAP_BODY(Image85)
SHOW_MAP_BODY(Text87)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin84,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text89,70,136,152,152,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable83)
SHOW_MAP_BODY(Skin84)
SHOW_MAP_BODY(Text89)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable83,161,58,314,262)

SHOW_ITEM_IMAGE(CMD_Image,Image92, 30, 36, 124,120, ICON_MENU_RADAR_CITYMODE_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text94,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin91Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin91)
SHOW_MAP_BODY(Skin91Rect)
SHOW_MAP_BODY(Image92)
SHOW_MAP_BODY(Text94)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin91,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text96,70,136,152,152,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable90)
SHOW_MAP_BODY(Skin91)
SHOW_MAP_BODY(Text96)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable90,161,58,314,262)

SHOW_ITEM_IMAGE(CMD_Image,Image99, 30, 36, 124,120, ICON_MENU_RADAR_CITYMODE_SPEEDLIMIT,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text101,24,176,150,192,STRID_RADAR_SPEED_LIMIT_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin98Rect,0,0,153,204,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin98)
SHOW_MAP_BODY(Skin98Rect)
SHOW_MAP_BODY(Image99)
SHOW_MAP_BODY(Text101)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin98,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text103,70,136,152,152,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed97)
SHOW_MAP_BODY(Skin98)
SHOW_MAP_BODY(Text103)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed97,161,58,314,262)

CREATE_LIST_ITEM_DATA(STRID_CITY_MODE104,STRID_CITY_MODE,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuRadarSetting_Status_CitySpeedLimit)
SHOW_MAP_BODY(Normal69)
SHOW_MAP_BODY(Focused76)
SHOW_MAP_BODY(Normal_Disable83)
SHOW_MAP_BODY(Focused_Disable90)
SHOW_MAP_BODY(Pressed97)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_Status_CitySpeedLimit)
LIST_LIST_BEGIN(UIMenuRadarSetting_Status_CitySpeedLimit)
LIST_LIST_ITEM(STRID_CITY_MODE104)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuRadarSetting_Status_CitySpeedLimit,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuRadarSetting_Status_CitySpeedLimit,UIMenuRadarSetting_Status_CitySpeedLimit,0,161,58,314,262)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image107, 30, 36, 128,124, ICON_MENU_RADAR_SPEAKSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text109,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin106Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin106)
SHOW_MAP_BODY(Skin106Rect)
SHOW_MAP_BODY(Image107)
SHOW_MAP_BODY(Text109)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin106,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text111,70,135,152,151,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal105)
SHOW_MAP_BODY(Skin106)
SHOW_MAP_BODY(Text111)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal105,322,59,475,263)

SHOW_ITEM_IMAGE(CMD_Image,Image114, 30, 36, 129,124, ICON_MENU_RADAR_SPEAKSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text116,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin113Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin113)
SHOW_MAP_BODY(Skin113Rect)
SHOW_MAP_BODY(Image114)
SHOW_MAP_BODY(Text116)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin113,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text118,70,135,152,151,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused112)
SHOW_MAP_BODY(Skin113)
SHOW_MAP_BODY(Text118)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused112,322,59,475,263)

SHOW_ITEM_IMAGE(CMD_Image,Image121, 30, 36, 129,124, ICON_MENU_RADAR_SPEAKSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text123,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin120Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin120)
SHOW_MAP_BODY(Skin120Rect)
SHOW_MAP_BODY(Image121)
SHOW_MAP_BODY(Text123)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin120,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text125,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable119)
SHOW_MAP_BODY(Skin120)
SHOW_MAP_BODY(Text125)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable119,322,59,475,263)

SHOW_ITEM_IMAGE(CMD_Image,Image128, 30, 36, 129,124, ICON_MENU_RADAR_SPEAKSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text130,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin127Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin127)
SHOW_MAP_BODY(Skin127Rect)
SHOW_MAP_BODY(Image128)
SHOW_MAP_BODY(Text130)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin127,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text132,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable126)
SHOW_MAP_BODY(Skin127)
SHOW_MAP_BODY(Text132)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable126,322,59,475,263)

SHOW_ITEM_IMAGE(CMD_Image,Image135, 30, 36, 129,124, ICON_MENU_RADAR_SPEAKSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text137,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin134Rect,0,0,153,204,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin134)
SHOW_MAP_BODY(Skin134Rect)
SHOW_MAP_BODY(Image135)
SHOW_MAP_BODY(Text137)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin134,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text139,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed133)
SHOW_MAP_BODY(Skin134)
SHOW_MAP_BODY(Text139)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed133,322,59,475,263)

CREATE_LIST_ITEM_DATA(STRID_RADAR140,STRID_RADAR,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuRadarSetting_Status_RadarReport)
SHOW_MAP_BODY(Normal105)
SHOW_MAP_BODY(Focused112)
SHOW_MAP_BODY(Normal_Disable119)
SHOW_MAP_BODY(Focused_Disable126)
SHOW_MAP_BODY(Pressed133)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_Status_RadarReport)
LIST_LIST_BEGIN(UIMenuRadarSetting_Status_RadarReport)
LIST_LIST_ITEM(STRID_RADAR140)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuRadarSetting_Status_RadarReport,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuRadarSetting_Status_RadarReport,UIMenuRadarSetting_Status_RadarReport,0,322,59,475,263)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image143, 4, 30, 137,123, ICON_MENU_RADAR_X,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text145,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin142Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin142)
SHOW_MAP_BODY(Skin142Rect)
SHOW_MAP_BODY(Image143)
SHOW_MAP_BODY(Text145)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin142,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text147,70,135,152,151,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal141)
SHOW_MAP_BODY(Skin142)
SHOW_MAP_BODY(Text147)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal141,0,274,153,478)

SHOW_ITEM_IMAGE(CMD_Image,Image150, 7, 28, 135,125, ICON_MENU_RADAR_X,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text152,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin149Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin149)
SHOW_MAP_BODY(Skin149Rect)
SHOW_MAP_BODY(Image150)
SHOW_MAP_BODY(Text152)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin149,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text154,70,135,152,151,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused148)
SHOW_MAP_BODY(Skin149)
SHOW_MAP_BODY(Text154)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused148,0,274,153,478)

SHOW_ITEM_IMAGE(CMD_Image,Image157, 7, 28, 135,125, ICON_MENU_RADAR_X,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text159,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin156Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin156)
SHOW_MAP_BODY(Skin156Rect)
SHOW_MAP_BODY(Image157)
SHOW_MAP_BODY(Text159)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin156,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text161,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable155)
SHOW_MAP_BODY(Skin156)
SHOW_MAP_BODY(Text161)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable155,0,274,153,478)

SHOW_ITEM_IMAGE(CMD_Image,Image164, 7, 28, 135,125, ICON_MENU_RADAR_X,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text166,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin163Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin163)
SHOW_MAP_BODY(Skin163Rect)
SHOW_MAP_BODY(Image164)
SHOW_MAP_BODY(Text166)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin163,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text168,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable162)
SHOW_MAP_BODY(Skin163)
SHOW_MAP_BODY(Text168)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable162,0,274,153,478)

SHOW_ITEM_IMAGE(CMD_Image,Image171, 7, 28, 135,125, ICON_MENU_RADAR_X,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text173,24,176,150,192,STRID_BOBAOSHEDING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin170Rect,0,0,153,204,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin170)
SHOW_MAP_BODY(Skin170Rect)
SHOW_MAP_BODY(Image171)
SHOW_MAP_BODY(Text173)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin170,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text175,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed169)
SHOW_MAP_BODY(Skin170)
SHOW_MAP_BODY(Text175)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed169,0,274,153,478)

CREATE_LIST_ITEM_DATA(STRID_RADAR_HZ_X176,STRID_RADAR_HZ_X,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuRadarSetting_Status_XReport)
SHOW_MAP_BODY(Normal141)
SHOW_MAP_BODY(Focused148)
SHOW_MAP_BODY(Normal_Disable155)
SHOW_MAP_BODY(Focused_Disable162)
SHOW_MAP_BODY(Pressed169)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_Status_XReport)
LIST_LIST_BEGIN(UIMenuRadarSetting_Status_XReport)
LIST_LIST_ITEM(STRID_RADAR_HZ_X176)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuRadarSetting_Status_XReport,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuRadarSetting_Status_XReport,UIMenuRadarSetting_Status_XReport,0,0,274,153,478)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image179, 30, 32, 137,123, ICON_MENU_RADAR_DRIVERMODE,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text181,24,176,150,192,STRID_DRAVING_MODE,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin178Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin178)
SHOW_MAP_BODY(Skin178Rect)
SHOW_MAP_BODY(Image179)
SHOW_MAP_BODY(Text181)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin178,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text183,69,135,151,151,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal177)
SHOW_MAP_BODY(Skin178)
SHOW_MAP_BODY(Text183)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal177,161,274,314,478)

SHOW_ITEM_IMAGE(CMD_Image,Image186, 30, 31, 135,125, ICON_MENU_RADAR_DRIVERMODE,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text188,24,176,150,192,STRID_DRAVING_MODE,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin185Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin185)
SHOW_MAP_BODY(Skin185Rect)
SHOW_MAP_BODY(Image186)
SHOW_MAP_BODY(Text188)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin185,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text190,69,135,151,151,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused184)
SHOW_MAP_BODY(Skin185)
SHOW_MAP_BODY(Text190)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused184,161,274,314,478)

SHOW_ITEM_IMAGE(CMD_Image,Image193, 30, 31, 135,125, ICON_MENU_RADAR_DRIVERMODE,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text195,24,176,150,192,STRID_DRAVING_MODE,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin192Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin192)
SHOW_MAP_BODY(Skin192Rect)
SHOW_MAP_BODY(Image193)
SHOW_MAP_BODY(Text195)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin192,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text197,69,135,151,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable191)
SHOW_MAP_BODY(Skin192)
SHOW_MAP_BODY(Text197)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable191,161,274,314,478)

SHOW_ITEM_IMAGE(CMD_Image,Image200, 30, 31, 135,125, ICON_MENU_RADAR_DRIVERMODE,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text202,24,176,150,192,STRID_DRAVING_MODE,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin199Rect,0,0,153,204,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin199)
SHOW_MAP_BODY(Skin199Rect)
SHOW_MAP_BODY(Image200)
SHOW_MAP_BODY(Text202)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin199,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text204,69,135,151,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable198)
SHOW_MAP_BODY(Skin199)
SHOW_MAP_BODY(Text204)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable198,161,274,314,478)

SHOW_ITEM_IMAGE(CMD_Image,Image207, 30, 31, 135,125, ICON_MENU_RADAR_DRIVERMODE,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text209,24,176,150,192,STRID_DRAVING_MODE,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin206Rect,0,0,153,204,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin206)
SHOW_MAP_BODY(Skin206Rect)
SHOW_MAP_BODY(Image207)
SHOW_MAP_BODY(Text209)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin206,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text211,69,135,151,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed205)
SHOW_MAP_BODY(Skin206)
SHOW_MAP_BODY(Text211)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed205,161,274,314,478)

CREATE_LIST_ITEM_DATA(STRID_NULL_212,STRID_NULL_,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuRadarSetting_Status_DrivingMode)
SHOW_MAP_BODY(Normal177)
SHOW_MAP_BODY(Focused184)
SHOW_MAP_BODY(Normal_Disable191)
SHOW_MAP_BODY(Focused_Disable198)
SHOW_MAP_BODY(Pressed205)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_Status_DrivingMode)
LIST_LIST_BEGIN(UIMenuRadarSetting_Status_DrivingMode)
LIST_LIST_ITEM(STRID_NULL_212)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuRadarSetting_Status_DrivingMode,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuRadarSetting_Status_DrivingMode,UIMenuRadarSetting_Status_DrivingMode,0,161,274,314,478)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image215, 30, 32, 130,120, ICON_MENU_RADAR_SPEED_SETTING,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text217,24,176,150,192,STRID_SPEED_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin214Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin214)
SHOW_MAP_BODY(Skin214Rect)
SHOW_MAP_BODY(Image215)
SHOW_MAP_BODY(Text217)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin214,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text219,70,135,152,151,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal213)
SHOW_MAP_BODY(Skin214)
SHOW_MAP_BODY(Text219)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal213,322,274,475,478)

SHOW_ITEM_IMAGE(CMD_Image,Image222, 30, 31, 129,120, ICON_MENU_RADAR_SPEED_SETTING,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text224,24,176,150,192,STRID_SPEED_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin221Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin221)
SHOW_MAP_BODY(Skin221Rect)
SHOW_MAP_BODY(Image222)
SHOW_MAP_BODY(Text224)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin221,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text226,70,135,152,151,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused220)
SHOW_MAP_BODY(Skin221)
SHOW_MAP_BODY(Text226)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused220,322,274,475,478)

SHOW_ITEM_IMAGE(CMD_Image,Image229, 30, 31, 129,120, ICON_MENU_RADAR_SPEED_SETTING,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text231,24,176,150,192,STRID_SPEED_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin228Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin228)
SHOW_MAP_BODY(Skin228Rect)
SHOW_MAP_BODY(Image229)
SHOW_MAP_BODY(Text231)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin228,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text233,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable227)
SHOW_MAP_BODY(Skin228)
SHOW_MAP_BODY(Text233)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable227,322,274,475,478)

SHOW_ITEM_IMAGE(CMD_Image,Image236, 30, 31, 129,120, ICON_MENU_RADAR_SPEED_SETTING,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text238,24,176,150,192,STRID_SPEED_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin235Rect,0,0,153,204,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin235)
SHOW_MAP_BODY(Skin235Rect)
SHOW_MAP_BODY(Image236)
SHOW_MAP_BODY(Text238)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin235,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text240,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable234)
SHOW_MAP_BODY(Skin235)
SHOW_MAP_BODY(Text240)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable234,322,274,475,478)

SHOW_ITEM_IMAGE(CMD_Image,Image243, 30, 31, 129,120, ICON_MENU_RADAR_SPEED_SETTING,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text245,24,176,150,192,STRID_SPEED_SET,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin242Rect,0,0,153,204,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin242)
SHOW_MAP_BODY(Skin242Rect)
SHOW_MAP_BODY(Image243)
SHOW_MAP_BODY(Text245)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin242,0,0,153,204)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text247,70,135,152,151,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed241)
SHOW_MAP_BODY(Skin242)
SHOW_MAP_BODY(Text247)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed241,322,274,475,478)

CREATE_LIST_ITEM_DATA(STRID_NULL_248,STRID_NULL_,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuRadarSetting_Status_SPEED_Correction)
SHOW_MAP_BODY(Normal213)
SHOW_MAP_BODY(Focused220)
SHOW_MAP_BODY(Normal_Disable227)
SHOW_MAP_BODY(Focused_Disable234)
SHOW_MAP_BODY(Pressed241)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_Status_SPEED_Correction)
LIST_LIST_BEGIN(UIMenuRadarSetting_Status_SPEED_Correction)
LIST_LIST_ITEM(STRID_NULL_248)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuRadarSetting_Status_SPEED_Correction,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuRadarSetting_Status_SPEED_Correction,UIMenuRadarSetting_Status_SPEED_Correction,0,322,274,475,478)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image251, 108, 161, 208,249, ICON_MENU_RADAR_WARNINGSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text253,98,304,224,320,STRID_RDOG_SETTING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin250Rect,0,0,315,419,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin250)
SHOW_MAP_BODY(Skin250Rect)
SHOW_MAP_BODY(Image251)
SHOW_MAP_BODY(Text253)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin250,0,0,315,419)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text255,203,261,285,277,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal249)
SHOW_MAP_BODY(Skin250)
SHOW_MAP_BODY(Text255)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal249,484,59,799,478)

SHOW_ITEM_IMAGE(CMD_Image,Image258, 108, 161, 207,250, ICON_MENU_RADAR_WARNINGSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text260,98,304,224,320,STRID_RDOG_SETTING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin257Rect,0,0,315,419,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin257)
SHOW_MAP_BODY(Skin257Rect)
SHOW_MAP_BODY(Image258)
SHOW_MAP_BODY(Text260)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin257,0,0,315,419)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text262,98,304,224,320,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused256)
SHOW_MAP_BODY(Skin257)
SHOW_MAP_BODY(Text262)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused256,484,59,799,478)

SHOW_ITEM_IMAGE(CMD_Image,Image265, 108, 161, 207,250, ICON_MENU_RADAR_WARNINGSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text267,98,304,224,320,STRID_RDOG_SETTING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin264Rect,0,0,315,419,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin264)
SHOW_MAP_BODY(Skin264Rect)
SHOW_MAP_BODY(Image265)
SHOW_MAP_BODY(Text267)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin264,0,0,315,419)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text269,98,304,224,320,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable263)
SHOW_MAP_BODY(Skin264)
SHOW_MAP_BODY(Text269)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable263,484,59,799,478)

SHOW_ITEM_IMAGE(CMD_Image,Image272, 108, 161, 207,250, ICON_MENU_RADAR_WARNINGSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text274,98,304,224,320,STRID_RDOG_SETTING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin271Rect,0,0,315,419,0,0,83,83,0,0,0)
SHOW_MAP_BEGIN(Skin271)
SHOW_MAP_BODY(Skin271Rect)
SHOW_MAP_BODY(Image272)
SHOW_MAP_BODY(Text274)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin271,0,0,315,419)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text276,98,304,224,320,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable270)
SHOW_MAP_BODY(Skin271)
SHOW_MAP_BODY(Text276)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable270,484,59,799,478)

SHOW_ITEM_IMAGE(CMD_Image,Image279, 108, 161, 207,250, ICON_MENU_RADAR_WARNINGSET,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_TEXT(CMD_Text,Text281,98,304,224,320,STRID_RDOG_SETTING,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin278Rect,0,0,315,419,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin278)
SHOW_MAP_BODY(Skin278Rect)
SHOW_MAP_BODY(Image279)
SHOW_MAP_BODY(Text281)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin278,0,0,315,419)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text283,98,304,224,320,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed277)
SHOW_MAP_BODY(Skin278)
SHOW_MAP_BODY(Text283)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed277,484,59,799,478)

CREATE_LIST_ITEM_DATA(STRID_NULL_284,STRID_NULL_,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIMenuRadarSetting_Status_EdogOnOff)
SHOW_MAP_BODY(Normal249)
SHOW_MAP_BODY(Focused256)
SHOW_MAP_BODY(Normal_Disable263)
SHOW_MAP_BODY(Focused_Disable270)
SHOW_MAP_BODY(Pressed277)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting_Status_EdogOnOff)
LIST_LIST_BEGIN(UIMenuRadarSetting_Status_EdogOnOff)
LIST_LIST_ITEM(STRID_NULL_284)
LIST_LIST_END

CREATE_LIST_DATA(UIMenuRadarSetting_Status_EdogOnOff,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIMenuRadarSetting_Status_EdogOnOff,UIMenuRadarSetting_Status_EdogOnOff,0,484,59,799,478)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIMenuRadarSetting)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIMenuRadarSetting)
DECLARE_CTRL_LIST(UIMenuRadarSetting)
CREATE_CTRL(UIMenuRadarSetting,UIMenuRadarSetting,CTRL_WND,NULL,0 ,0,0,799,479)
#endif
