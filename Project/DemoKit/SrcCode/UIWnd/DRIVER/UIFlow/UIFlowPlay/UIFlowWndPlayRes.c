//This source code is generated by UI Designer Studio.

#ifndef UIFLOWWNDPLAYRES_H
#define UIFLOWWNDPLAYRES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,799,479,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,799,479)

SHOW_MAP_BEGIN(Skin2)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin2,0,0,799,479)

SHOW_MAP_BEGIN(Skin4)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin4,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon5, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal3)
SHOW_MAP_BODY(Skin4)
SHOW_MAP_BODY(Icon5)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal3,222,417,293,479)

SHOW_MAP_BEGIN(Skin7)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin7,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon8, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused6)
SHOW_MAP_BODY(Skin7)
SHOW_MAP_BODY(Icon8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused6,222,417,293,479)

SHOW_MAP_BEGIN(Skin10)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin10,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon11, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable9)
SHOW_MAP_BODY(Skin10)
SHOW_MAP_BODY(Icon11)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable9,222,417,293,479)

SHOW_MAP_BEGIN(Skin13)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin13,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon14, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable12)
SHOW_MAP_BODY(Skin13)
SHOW_MAP_BODY(Icon14)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable12,222,417,293,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin16Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin16)
SHOW_MAP_BODY(Skin16Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin16,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon17, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed15)
SHOW_MAP_BODY(Skin16)
SHOW_MAP_BODY(Icon17)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed15,222,417,293,479)

CREATE_LIST_ITEM_DATA(ICON_PLAYBACK_PREONE18,STRID_NULL,ICON_PLAYBACK_PREONE,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_PRE_ONE)
SHOW_MAP_BODY(Normal3)
SHOW_MAP_BODY(Focused6)
SHOW_MAP_BODY(Normal_Disable9)
SHOW_MAP_BODY(Focused_Disable12)
SHOW_MAP_BODY(Pressed15)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_PRE_ONE)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_PRE_ONE)
LIST_LIST_ITEM(ICON_PLAYBACK_PREONE18)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_PRE_ONE,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_PRE_ONE,UIFlowWndPlay_Status_PRE_ONE,0,222,417,293,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin20)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin20,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon21, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal19)
SHOW_MAP_BODY(Skin20)
SHOW_MAP_BODY(Icon21)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal19,293,417,364,479)

SHOW_MAP_BEGIN(Skin23)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin23,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon24, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused22)
SHOW_MAP_BODY(Skin23)
SHOW_MAP_BODY(Icon24)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused22,293,417,364,479)

SHOW_MAP_BEGIN(Skin26)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin26,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon27, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable25)
SHOW_MAP_BODY(Skin26)
SHOW_MAP_BODY(Icon27)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable25,293,417,364,479)

SHOW_MAP_BEGIN(Skin29)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin29,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon30, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable28)
SHOW_MAP_BODY(Skin29)
SHOW_MAP_BODY(Icon30)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable28,293,417,364,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin32Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin32)
SHOW_MAP_BODY(Skin32Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin32,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon33, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed31)
SHOW_MAP_BODY(Skin32)
SHOW_MAP_BODY(Icon33)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed31,293,417,364,479)

CREATE_LIST_ITEM_DATA(ICON_PLAYBACK_BACKWARD34,STRID_NULL,ICON_PLAYBACK_BACKWARD,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_Backward)
SHOW_MAP_BODY(Normal19)
SHOW_MAP_BODY(Focused22)
SHOW_MAP_BODY(Normal_Disable25)
SHOW_MAP_BODY(Focused_Disable28)
SHOW_MAP_BODY(Pressed31)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_Backward)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_Backward)
LIST_LIST_ITEM(ICON_PLAYBACK_BACKWARD34)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_Backward,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_Backward,UIFlowWndPlay_Status_Backward,0,293,417,364,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin36Rect,0,0,71,62,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin36)
SHOW_MAP_BODY(Skin36Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin36,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon37, 0, 0, 71,62, ICONID_NULL,0,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal35)
SHOW_MAP_BODY(Skin36)
SHOW_MAP_BODY(Icon37)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal35,364,417,435,479)

CREATE_STATE_ITEM_DATA(ICON_PLAYBACK_PLAY38,STRID_NULL,ICON_PLAYBACK_PLAY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_PLAYBACK_PAUSE39,STRID_NULL,ICON_PLAYBACK_PAUSE,NULL) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_Play)
SHOW_MAP_BODY(Normal35)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_Play)
STATE_LIST_BEGIN(UIFlowWndPlay_Status_Play)
STATE_LIST_ITEM(ICON_PLAYBACK_PLAY38)
STATE_LIST_ITEM(ICON_PLAYBACK_PAUSE39)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndPlay_Status_Play,0)
CREATE_STATE_CTRL(UIFlowWndPlay_Status_Play,0,364,417,435,479)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin41)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin41,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon42, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal40)
SHOW_MAP_BODY(Skin41)
SHOW_MAP_BODY(Icon42)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal40,435,417,506,479)

SHOW_MAP_BEGIN(Skin44)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin44,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon45, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused43)
SHOW_MAP_BODY(Skin44)
SHOW_MAP_BODY(Icon45)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused43,435,417,506,479)

SHOW_MAP_BEGIN(Skin47)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin47,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon48, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable46)
SHOW_MAP_BODY(Skin47)
SHOW_MAP_BODY(Icon48)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable46,435,417,506,479)

SHOW_MAP_BEGIN(Skin50)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin50,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon51, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable49)
SHOW_MAP_BODY(Skin50)
SHOW_MAP_BODY(Icon51)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable49,435,417,506,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin53Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin53)
SHOW_MAP_BODY(Skin53Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin53,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon54, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed52)
SHOW_MAP_BODY(Skin53)
SHOW_MAP_BODY(Icon54)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed52,435,417,506,479)

CREATE_LIST_ITEM_DATA(ICON_PLAYBACK_FORWARD55,STRID_NULL,ICON_PLAYBACK_FORWARD,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_Forward)
SHOW_MAP_BODY(Normal40)
SHOW_MAP_BODY(Focused43)
SHOW_MAP_BODY(Normal_Disable46)
SHOW_MAP_BODY(Focused_Disable49)
SHOW_MAP_BODY(Pressed52)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_Forward)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_Forward)
LIST_LIST_ITEM(ICON_PLAYBACK_FORWARD55)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_Forward,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_Forward,UIFlowWndPlay_Status_Forward,0,435,417,506,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin57)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin57,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon58, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal56)
SHOW_MAP_BODY(Skin57)
SHOW_MAP_BODY(Icon58)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal56,506,417,577,479)

SHOW_MAP_BEGIN(Skin60)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin60,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon61, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused59)
SHOW_MAP_BODY(Skin60)
SHOW_MAP_BODY(Icon61)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused59,506,417,577,479)

SHOW_MAP_BEGIN(Skin63)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin63,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon64, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable62)
SHOW_MAP_BODY(Skin63)
SHOW_MAP_BODY(Icon64)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable62,506,417,577,479)

SHOW_MAP_BEGIN(Skin66)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin66,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon67, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable65)
SHOW_MAP_BODY(Skin66)
SHOW_MAP_BODY(Icon67)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable65,506,417,577,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin69Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin69)
SHOW_MAP_BODY(Skin69Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin69,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon70, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed68)
SHOW_MAP_BODY(Skin69)
SHOW_MAP_BODY(Icon70)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed68,506,417,577,479)

CREATE_LIST_ITEM_DATA(ICON_PLAYBACK_NEXTONE71,STRID_NULL,ICON_PLAYBACK_NEXTONE,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_NextOne)
SHOW_MAP_BODY(Normal56)
SHOW_MAP_BODY(Focused59)
SHOW_MAP_BODY(Normal_Disable62)
SHOW_MAP_BODY(Focused_Disable65)
SHOW_MAP_BODY(Pressed68)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_NextOne)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_NextOne)
LIST_LIST_ITEM(ICON_PLAYBACK_NEXTONE71)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_NextOne,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_NextOne,UIFlowWndPlay_Status_NextOne,0,506,417,577,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image74, 0, 1, 67,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin73)
SHOW_MAP_BODY(Image74)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin73,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text76,23,31,52,47,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal72)
SHOW_MAP_BODY(Skin73)
SHOW_MAP_BODY(Text76)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal72,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image79, 0, 1, 68,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin78)
SHOW_MAP_BODY(Image79)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin78,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text81,23,31,52,47,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused77)
SHOW_MAP_BODY(Skin78)
SHOW_MAP_BODY(Text81)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused77,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image84, 0, 1, 69,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin83)
SHOW_MAP_BODY(Image84)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin83,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text86,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable82)
SHOW_MAP_BODY(Skin83)
SHOW_MAP_BODY(Text86)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable82,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image89, 1, 1, 69,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin88)
SHOW_MAP_BODY(Image89)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin88,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text91,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable87)
SHOW_MAP_BODY(Skin88)
SHOW_MAP_BODY(Text91)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable87,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image94, 1, 0, 69,62, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin93Rect,0,0,68,62,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin93)
SHOW_MAP_BODY(Skin93Rect)
SHOW_MAP_BODY(Image94)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin93,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text96,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed92)
SHOW_MAP_BODY(Skin93)
SHOW_MAP_BODY(Text96)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed92,731,417,799,479)

CREATE_LIST_ITEM_DATA(STRID_NULL_97,STRID_NULL_,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_Return)
SHOW_MAP_BODY(Normal72)
SHOW_MAP_BODY(Focused77)
SHOW_MAP_BODY(Normal_Disable82)
SHOW_MAP_BODY(Focused_Disable87)
SHOW_MAP_BODY(Pressed92)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_Return)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_Return)
LIST_LIST_ITEM(STRID_NULL_97)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_Return,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_Return,UIFlowWndPlay_Status_Return,0,731,417,799,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin99)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin99,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon100, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal98)
SHOW_MAP_BODY(Skin99)
SHOW_MAP_BODY(Icon100)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal98,364,417,435,479)

SHOW_MAP_BEGIN(Skin102)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin102,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon103, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused101)
SHOW_MAP_BODY(Skin102)
SHOW_MAP_BODY(Icon103)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused101,364,417,435,479)

SHOW_MAP_BEGIN(Skin105)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin105,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon106, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable104)
SHOW_MAP_BODY(Skin105)
SHOW_MAP_BODY(Icon106)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable104,364,417,435,479)

SHOW_MAP_BEGIN(Skin108)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin108,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon109, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable107)
SHOW_MAP_BODY(Skin108)
SHOW_MAP_BODY(Icon109)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable107,364,417,435,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin111Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin111)
SHOW_MAP_BODY(Skin111Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin111,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon112, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed110)
SHOW_MAP_BODY(Skin111)
SHOW_MAP_BODY(Icon112)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed110,364,417,435,479)

CREATE_LIST_ITEM_DATA(ICONID_NULL113,STRID_NULL,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_PlayPause_BG)
SHOW_MAP_BODY(Normal98)
SHOW_MAP_BODY(Focused101)
SHOW_MAP_BODY(Normal_Disable104)
SHOW_MAP_BODY(Focused_Disable107)
SHOW_MAP_BODY(Pressed110)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_PlayPause_BG)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_PlayPause_BG)
LIST_LIST_ITEM(ICONID_NULL113)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_PlayPause_BG,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_PlayPause_BG,UIFlowWndPlay_Status_PlayPause_BG,0,364,417,435,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIFlowWndPlay_Panel_PlayMovie)
SHOW_MAP_BODY(Skin2)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Panel_PlayMovie)
DECLARE_CTRL_LIST(UIFlowWndPlay_Panel_PlayMovie)
CREATE_CTRL(UIFlowWndPlay_Panel_PlayMovie,UIFlowWndPlay_Panel_PlayMovie,CTRL_WND,NULL,0 ,0,0,799,479)
SHOW_MAP_BEGIN(Skin114)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin114,0,0,799,479)

SHOW_MAP_BEGIN(Skin116)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin116,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon117, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal115)
SHOW_MAP_BODY(Skin116)
SHOW_MAP_BODY(Icon117)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal115,400,417,471,479)

SHOW_MAP_BEGIN(Skin119)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin119,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon120, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused118)
SHOW_MAP_BODY(Skin119)
SHOW_MAP_BODY(Icon120)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused118,400,417,471,479)

SHOW_MAP_BEGIN(Skin122)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin122,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon123, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable121)
SHOW_MAP_BODY(Skin122)
SHOW_MAP_BODY(Icon123)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable121,400,417,471,479)

SHOW_MAP_BEGIN(Skin125)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin125,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon126, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable124)
SHOW_MAP_BODY(Skin125)
SHOW_MAP_BODY(Icon126)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable124,400,417,471,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin128Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin128)
SHOW_MAP_BODY(Skin128Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin128,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon129, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed127)
SHOW_MAP_BODY(Skin128)
SHOW_MAP_BODY(Icon129)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed127,400,417,471,479)

CREATE_LIST_ITEM_DATA(ICON_PLAYBACK_PREONE130,STRID_NULL,ICON_PLAYBACK_PREONE,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_PhotoPRE_ONE)
SHOW_MAP_BODY(Normal115)
SHOW_MAP_BODY(Focused118)
SHOW_MAP_BODY(Normal_Disable121)
SHOW_MAP_BODY(Focused_Disable124)
SHOW_MAP_BODY(Pressed127)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_PhotoPRE_ONE)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_PhotoPRE_ONE)
LIST_LIST_ITEM(ICON_PLAYBACK_PREONE130)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_PhotoPRE_ONE,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_PhotoPRE_ONE,UIFlowWndPlay_Status_PhotoPRE_ONE,0,400,417,471,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin132)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin132,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon133, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal131)
SHOW_MAP_BODY(Skin132)
SHOW_MAP_BODY(Icon133)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal131,329,417,400,479)

SHOW_MAP_BEGIN(Skin135)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin135,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon136, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused134)
SHOW_MAP_BODY(Skin135)
SHOW_MAP_BODY(Icon136)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused134,329,417,400,479)

SHOW_MAP_BEGIN(Skin138)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin138,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon139, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable137)
SHOW_MAP_BODY(Skin138)
SHOW_MAP_BODY(Icon139)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable137,329,417,400,479)

SHOW_MAP_BEGIN(Skin141)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin141,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon142, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable140)
SHOW_MAP_BODY(Skin141)
SHOW_MAP_BODY(Icon142)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable140,329,417,400,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin144Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin144)
SHOW_MAP_BODY(Skin144Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin144,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon145, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed143)
SHOW_MAP_BODY(Skin144)
SHOW_MAP_BODY(Icon145)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed143,329,417,400,479)

CREATE_LIST_ITEM_DATA(ICON_PLAY_PHOTO_ZOOMOUT146,STRID_NULL,ICON_PLAY_PHOTO_ZOOMOUT,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_PhotoZoomout)
SHOW_MAP_BODY(Normal131)
SHOW_MAP_BODY(Focused134)
SHOW_MAP_BODY(Normal_Disable137)
SHOW_MAP_BODY(Focused_Disable140)
SHOW_MAP_BODY(Pressed143)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_PhotoZoomout)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_PhotoZoomout)
LIST_LIST_ITEM(ICON_PLAY_PHOTO_ZOOMOUT146)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_PhotoZoomout,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_PhotoZoomout,UIFlowWndPlay_Status_PhotoZoomout,0,329,417,400,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin148)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin148,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon149, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal147)
SHOW_MAP_BODY(Skin148)
SHOW_MAP_BODY(Icon149)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal147,258,417,329,479)

SHOW_MAP_BEGIN(Skin151)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin151,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon152, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused150)
SHOW_MAP_BODY(Skin151)
SHOW_MAP_BODY(Icon152)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused150,258,417,329,479)

SHOW_MAP_BEGIN(Skin154)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin154,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon155, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable153)
SHOW_MAP_BODY(Skin154)
SHOW_MAP_BODY(Icon155)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable153,258,417,329,479)

SHOW_MAP_BEGIN(Skin157)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin157,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon158, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable156)
SHOW_MAP_BODY(Skin157)
SHOW_MAP_BODY(Icon158)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable156,258,417,329,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin160Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin160)
SHOW_MAP_BODY(Skin160Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin160,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon161, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed159)
SHOW_MAP_BODY(Skin160)
SHOW_MAP_BODY(Icon161)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed159,258,417,329,479)

CREATE_LIST_ITEM_DATA(ICON_PLAY_PHOTO_ZOOMIN162,STRID_NULL,ICON_PLAY_PHOTO_ZOOMIN,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_PhotoZoomin)
SHOW_MAP_BODY(Normal147)
SHOW_MAP_BODY(Focused150)
SHOW_MAP_BODY(Normal_Disable153)
SHOW_MAP_BODY(Focused_Disable156)
SHOW_MAP_BODY(Pressed159)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_PhotoZoomin)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_PhotoZoomin)
LIST_LIST_ITEM(ICON_PLAY_PHOTO_ZOOMIN162)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_PhotoZoomin,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_PhotoZoomin,UIFlowWndPlay_Status_PhotoZoomin,0,258,417,329,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin164)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin164,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon165, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal163)
SHOW_MAP_BODY(Skin164)
SHOW_MAP_BODY(Icon165)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal163,471,417,542,479)

SHOW_MAP_BEGIN(Skin167)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin167,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon168, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused166)
SHOW_MAP_BODY(Skin167)
SHOW_MAP_BODY(Icon168)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused166,471,417,542,479)

SHOW_MAP_BEGIN(Skin170)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin170,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon171, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable169)
SHOW_MAP_BODY(Skin170)
SHOW_MAP_BODY(Icon171)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable169,471,417,542,479)

SHOW_MAP_BEGIN(Skin173)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin173,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon174, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable172)
SHOW_MAP_BODY(Skin173)
SHOW_MAP_BODY(Icon174)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable172,471,417,542,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin176Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin176)
SHOW_MAP_BODY(Skin176Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin176,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon177, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed175)
SHOW_MAP_BODY(Skin176)
SHOW_MAP_BODY(Icon177)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed175,471,417,542,479)

CREATE_LIST_ITEM_DATA(ICON_PLAYBACK_NEXTONE178,STRID_NULL,ICON_PLAYBACK_NEXTONE,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_PhotoNextOne)
SHOW_MAP_BODY(Normal163)
SHOW_MAP_BODY(Focused166)
SHOW_MAP_BODY(Normal_Disable169)
SHOW_MAP_BODY(Focused_Disable172)
SHOW_MAP_BODY(Pressed175)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_PhotoNextOne)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_PhotoNextOne)
LIST_LIST_ITEM(ICON_PLAYBACK_NEXTONE178)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_PhotoNextOne,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_PhotoNextOne,UIFlowWndPlay_Status_PhotoNextOne,0,471,417,542,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image181, -1, 1, 66,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin180)
SHOW_MAP_BODY(Image181)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin180,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text183,23,31,52,47,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal179)
SHOW_MAP_BODY(Skin180)
SHOW_MAP_BODY(Text183)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal179,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image186, 1, 1, 67,62, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin185)
SHOW_MAP_BODY(Image186)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin185,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text188,23,31,52,47,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused184)
SHOW_MAP_BODY(Skin185)
SHOW_MAP_BODY(Text188)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused184,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image191, 0, 1, 66,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin190)
SHOW_MAP_BODY(Image191)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin190,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text193,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable189)
SHOW_MAP_BODY(Skin190)
SHOW_MAP_BODY(Text193)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable189,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image196, -1, 0, 67,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin195)
SHOW_MAP_BODY(Image196)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin195,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text198,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable194)
SHOW_MAP_BODY(Skin195)
SHOW_MAP_BODY(Text198)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable194,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image201, 1, 1, 68,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin200Rect,0,0,68,62,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin200)
SHOW_MAP_BODY(Skin200Rect)
SHOW_MAP_BODY(Image201)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin200,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text203,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed199)
SHOW_MAP_BODY(Skin200)
SHOW_MAP_BODY(Text203)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed199,731,417,799,479)

CREATE_LIST_ITEM_DATA(STRID_NULL_204,STRID_NULL_,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlay_Status_PhotoReturn)
SHOW_MAP_BODY(Normal179)
SHOW_MAP_BODY(Focused184)
SHOW_MAP_BODY(Normal_Disable189)
SHOW_MAP_BODY(Focused_Disable194)
SHOW_MAP_BODY(Pressed199)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Status_PhotoReturn)
LIST_LIST_BEGIN(UIFlowWndPlay_Status_PhotoReturn)
LIST_LIST_ITEM(STRID_NULL_204)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlay_Status_PhotoReturn,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlay_Status_PhotoReturn,UIFlowWndPlay_Status_PhotoReturn,0,731,417,799,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIFlowWndPlay_Panel_PlayPhoto)
SHOW_MAP_BODY(Skin114)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_Panel_PlayPhoto)
DECLARE_CTRL_LIST(UIFlowWndPlay_Panel_PlayPhoto)
CREATE_CTRL(UIFlowWndPlay_Panel_PlayPhoto,UIFlowWndPlay_Panel_PlayPhoto,CTRL_WND,NULL,0 ,0,0,799,479)
SHOW_ITEM_RECT(CMD_Rectangle,Skin206Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin206)
SHOW_MAP_BODY(Skin206Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin206,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon207, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal205)
SHOW_MAP_BODY(Skin206)
SHOW_MAP_BODY(Icon207)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal205,238,4,265,31)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticICN_Protect)
SHOW_MAP_BODY(Normal205)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticICN_Protect)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticICN_Protect,ICON_LOCK)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticICN_Protect,0,238,4,265,31)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin210Rect,0,0,107,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin210)
SHOW_MAP_BODY(Skin210Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin210,0,0,107,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text212,0,0,107,27,STRID_NULL,0,0,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal209)
SHOW_MAP_BODY(Skin210)
SHOW_MAP_BODY(Text212)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal209,9,3,116,30)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_Filename)
SHOW_MAP_BODY(Normal209)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_Filename)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_Filename,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_Filename,0,9,3,116,30)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin215Rect,0,0,81,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin215)
SHOW_MAP_BODY(Skin215Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin215,0,0,81,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text217,1,0,80,27,STRID_NULL,0,0,0,0,2,1,1,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal214)
SHOW_MAP_BODY(Skin215)
SHOW_MAP_BODY(Text217)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal214,708,3,789,30)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_MovPlayTime)
SHOW_MAP_BODY(Normal214)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_MovPlayTime)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_MovPlayTime,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_MovPlayTime,0,708,3,789,30)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin220Rect,0,0,59,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin220)
SHOW_MAP_BODY(Skin220Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin220,0,0,59,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text222,0,0,59,27,STRID_NULL,0,0,0,0,32,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal219)
SHOW_MAP_BODY(Skin220)
SHOW_MAP_BODY(Text222)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal219,6,376,65,403)

SHOW_MAP_BEGIN(UIFlowWndPlay_StaticTXT_Speed)
SHOW_MAP_BODY(Normal219)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay_StaticTXT_Speed)
CREATE_STATIC_DATA(UIFlowWndPlay_StaticTXT_Speed,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlay_StaticTXT_Speed,0,6,376,65,403)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIFlowWndPlay)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlay)
DECLARE_CTRL_LIST(UIFlowWndPlay)
CREATE_CTRL(UIFlowWndPlay,UIFlowWndPlay,CTRL_WND,NULL,0 ,0,0,799,479)
#endif
