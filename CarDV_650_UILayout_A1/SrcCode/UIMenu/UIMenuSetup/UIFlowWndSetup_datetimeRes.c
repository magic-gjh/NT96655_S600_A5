//This source code is generated by UI Designer Studio.

#ifndef UIFLOWWNDSETUP_DATETIMERES_H
#define UIFLOWWNDSETUP_DATETIMERES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,799,479,0,0,26,26,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,799,479)

SHOW_ITEM_RECT(CMD_Rectangle,Rect5,0,0,699,78,16,2,0,26,0,0,0)
SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_BODY(Rect5)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,699,78)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text7,0,0,599,78,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal2)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_BODY(Text7)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal2,100,36,799,114)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetimeTitle)
SHOW_MAP_BODY(Normal2)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetimeTitle)
CREATE_STATIC_DATA(UIFlowWndSetup_datetimeTitle,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetimeTitle,0,100,36,799,114)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Rect12,0,0,99,78,16,2,0,26,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin10Rect,0,0,99,78,0,0,26,26,0,0,0)
SHOW_MAP_BEGIN(Skin10)
SHOW_MAP_BODY(Skin10Rect)
SHOW_MAP_BODY(Rect12)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin10,0,0,99,78)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon13, 0, 0, 99,78, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal9)
SHOW_MAP_BODY(Skin10)
SHOW_MAP_BODY(Icon13)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal9,0,36,99,114)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetimeReturn)
SHOW_MAP_BODY(Normal9)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetimeReturn)
CREATE_STATIC_DATA(UIFlowWndSetup_datetimeReturn,ICON_MENU_RETURN_NEW)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetimeReturn,0,0,36,99,114)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin15Rect,0,0,799,4,0,0,1,1,0,0,0)
SHOW_MAP_BEGIN(Skin15)
SHOW_MAP_BODY(Skin15Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin15,0,0,799,4)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetimePanel)
SHOW_MAP_BODY(Skin15)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetimePanel)
DECLARE_CTRL_LIST(UIFlowWndSetup_datetimePanel)
CREATE_CTRL(UIFlowWndSetup_datetimePanel,UIFlowWndSetup_datetimePanel,CTRL_WND,NULL,0 ,0,115,799,119)
SHOW_ITEM_RECT(CMD_Rectangle,Skin16Rect,0,0,799,359,0,0,26,26,0,0,0)
SHOW_MAP_BEGIN(Skin16)
SHOW_MAP_BODY(Skin16Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin16,0,0,799,359)

SHOW_MAP_BEGIN(Skin18)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin18,0,0,67,56)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text20,0,0,67,56,STRID_NULL,0,0,0,0,1,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal17)
SHOW_MAP_BODY(Skin18)
SHOW_MAP_BODY(Text20)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal17,170,200,237,256)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime_YMD_Y)
SHOW_MAP_BODY(Normal17)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime_YMD_Y)
CREATE_STATIC_DATA(UIFlowWndSetup_datetime_YMD_Y,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetime_YMD_Y,0,170,80,237,136)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin23)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin23,0,0,39,56)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text25,0,0,39,56,STRID_NULL,0,0,0,0,1,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal22)
SHOW_MAP_BODY(Skin23)
SHOW_MAP_BODY(Text25)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal22,300,200,339,256)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime_YMD_M)
SHOW_MAP_BODY(Normal22)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime_YMD_M)
CREATE_STATIC_DATA(UIFlowWndSetup_datetime_YMD_M,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetime_YMD_M,0,300,80,339,136)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin28)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin28,0,0,39,56)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text30,0,0,39,56,STRID_NULL,0,0,0,0,1,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal27)
SHOW_MAP_BODY(Skin28)
SHOW_MAP_BODY(Text30)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal27,415,200,454,256)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime_YMD_D)
SHOW_MAP_BODY(Normal27)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime_YMD_D)
CREATE_STATIC_DATA(UIFlowWndSetup_datetime_YMD_D,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetime_YMD_D,0,415,80,454,136)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin33)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin33,0,0,39,56)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text35,0,0,39,56,STRID_NULL,0,0,0,0,1,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal32)
SHOW_MAP_BODY(Skin33)
SHOW_MAP_BODY(Text35)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal32,182,360,221,416)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime_YMD_HR)
SHOW_MAP_BODY(Normal32)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime_YMD_HR)
CREATE_STATIC_DATA(UIFlowWndSetup_datetime_YMD_HR,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetime_YMD_HR,0,182,240,221,296)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin38)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin38,0,0,39,56)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text40,0,0,39,56,STRID_NULL,0,0,0,0,1,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal37)
SHOW_MAP_BODY(Skin38)
SHOW_MAP_BODY(Text40)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal37,300,360,339,416)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime_YMD_MIN)
SHOW_MAP_BODY(Normal37)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime_YMD_MIN)
CREATE_STATIC_DATA(UIFlowWndSetup_datetime_YMD_MIN,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetime_YMD_MIN,0,300,240,339,296)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin43)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin43,0,0,39,56)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text45,0,0,39,56,STRID_NULL,0,0,0,0,1,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal42)
SHOW_MAP_BODY(Skin43)
SHOW_MAP_BODY(Text45)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal42,415,360,454,416)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime_YMD_SEC)
SHOW_MAP_BODY(Normal42)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime_YMD_SEC)
CREATE_STATIC_DATA(UIFlowWndSetup_datetime_YMD_SEC,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetime_YMD_SEC,0,415,240,454,296)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime_Tab)
SHOW_MAP_BODY(Skin16)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime_Tab)
CTRL_LIST_BEGIN(UIFlowWndSetup_datetime_Tab)
CTRL_LIST_ITEM(UIFlowWndSetup_datetime_YMD_Y)
CTRL_LIST_ITEM(UIFlowWndSetup_datetime_YMD_M)
CTRL_LIST_ITEM(UIFlowWndSetup_datetime_YMD_D)
CTRL_LIST_ITEM(UIFlowWndSetup_datetime_YMD_HR)
CTRL_LIST_ITEM(UIFlowWndSetup_datetime_YMD_MIN)
CTRL_LIST_ITEM(UIFlowWndSetup_datetime_YMD_SEC)
CTRL_LIST_END

CREATE_TAB_DATA(UIFlowWndSetup_datetime_Tab,0)

CREATE_TAB_CTRL(UIFlowWndSetup_datetime_Tab,UIFlowWndSetup_datetime_Tab,0,0,120,799,479)
SHOW_MAP_BEGIN(Skin48)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin48,0,0,20,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text50,1,0,20,29,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal47)
SHOW_MAP_BODY(Skin48)
SHOW_MAP_BODY(Text50)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal47,257,214,277,243)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_YMD_VALUE_Other0)
SHOW_MAP_BODY(Normal47)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_YMD_VALUE_Other0)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_YMD_VALUE_Other0,STRID_MODE)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_YMD_VALUE_Other0,0,257,214,277,243)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin53)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin53,0,0,20,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text55,1,0,20,29,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal52)
SHOW_MAP_BODY(Skin53)
SHOW_MAP_BODY(Text55)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal52,360,214,380,243)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_YMD_VALUE_Other1)
SHOW_MAP_BODY(Normal52)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_YMD_VALUE_Other1)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_YMD_VALUE_Other1,STRID_L)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_YMD_VALUE_Other1,0,360,214,380,243)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin58)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin58,0,0,20,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text60,1,0,20,29,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal57)
SHOW_MAP_BODY(Skin58)
SHOW_MAP_BODY(Text60)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal57,257,373,277,402)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_YMD_VALUE_Other2)
SHOW_MAP_BODY(Normal57)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_YMD_VALUE_Other2)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_YMD_VALUE_Other2,STRID_L)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_YMD_VALUE_Other2,0,257,373,277,402)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin63)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin63,0,0,20,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text65,1,0,20,29,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal62)
SHOW_MAP_BODY(Skin63)
SHOW_MAP_BODY(Text65)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal62,360,373,380,402)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_YMD_VALUE_Other3)
SHOW_MAP_BODY(Normal62)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_YMD_VALUE_Other3)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_YMD_VALUE_Other3,STRID_L)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_YMD_VALUE_Other3,0,360,373,380,402)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin68)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin68,0,0,69,66)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon69, -1, 22, 68,67, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal67)
SHOW_MAP_BODY(Skin68)
SHOW_MAP_BODY(Icon69)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal67,168,133,237,199)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_Y_UP)
SHOW_MAP_BODY(Normal67)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_Y_UP)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_Y_UP,ICON_SCROLBAR_UP)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_Y_UP,0,168,133,237,199)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin72)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin72,0,0,69,65)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon73, -1, 23, 68,66, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal71)
SHOW_MAP_BODY(Skin72)
SHOW_MAP_BODY(Icon73)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal71,285,135,354,200)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_MON_UP)
SHOW_MAP_BODY(Normal71)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_MON_UP)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_MON_UP,ICON_SCROLBAR_UP)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_MON_UP,0,285,135,354,200)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin76)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin76,0,0,69,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon77, -1, 20, 68,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal75)
SHOW_MAP_BODY(Skin76)
SHOW_MAP_BODY(Icon77)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal75,402,138,471,200)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_DAY_UP)
SHOW_MAP_BODY(Normal75)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_DAY_UP)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_DAY_UP,ICON_SCROLBAR_UP)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_DAY_UP,0,402,138,471,200)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin80)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin80,0,0,69,40)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon81, -1, -1, 68,40, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal79)
SHOW_MAP_BODY(Skin80)
SHOW_MAP_BODY(Icon81)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal79,168,320,237,360)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_H_UP)
SHOW_MAP_BODY(Normal79)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_H_UP)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_H_UP,ICON_SCROLBAR_UP)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_H_UP,0,168,320,237,360)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin84)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin84,0,0,69,43)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon85, -1, -1, 68,43, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal83)
SHOW_MAP_BODY(Skin84)
SHOW_MAP_BODY(Icon85)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal83,285,317,354,360)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_MIN_UP)
SHOW_MAP_BODY(Normal83)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_MIN_UP)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_MIN_UP,ICON_SCROLBAR_UP)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_MIN_UP,0,285,317,354,360)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin88)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin88,0,0,69,47)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon89, 1, 0, 70,47, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal87)
SHOW_MAP_BODY(Skin88)
SHOW_MAP_BODY(Icon89)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal87,400,313,469,360)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_SEC_UP)
SHOW_MAP_BODY(Normal87)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_SEC_UP)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_SEC_UP,ICON_SCROLBAR_UP)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_SEC_UP,0,400,313,469,360)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin92)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin92,0,0,69,39)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon93, -1, 1, 68,32, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal91)
SHOW_MAP_BODY(Skin92)
SHOW_MAP_BODY(Icon93)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal91,168,256,237,295)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_Y_DOWN)
SHOW_MAP_BODY(Normal91)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_Y_DOWN)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_Y_DOWN,ICON_SCROLBAR_DOWN)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_Y_DOWN,0,168,256,237,295)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin96)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin96,0,0,69,38)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon97, -1, 1, 68,32, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal95)
SHOW_MAP_BODY(Skin96)
SHOW_MAP_BODY(Icon97)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal95,284,256,353,294)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_MON_DOWN)
SHOW_MAP_BODY(Normal95)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_MON_DOWN)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_MON_DOWN,ICON_SCROLBAR_DOWN)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_MON_DOWN,0,284,256,353,294)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin100)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin100,0,0,69,41)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon101, -1, 1, 68,32, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal99)
SHOW_MAP_BODY(Skin100)
SHOW_MAP_BODY(Icon101)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal99,402,256,471,297)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_DAY_DOWN)
SHOW_MAP_BODY(Normal99)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_DAY_DOWN)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_DAY_DOWN,ICON_SCROLBAR_DOWN)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_DAY_DOWN,0,402,256,471,297)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin104)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin104,0,0,69,53)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon105, -1, 1, 68,33, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal103)
SHOW_MAP_BODY(Skin104)
SHOW_MAP_BODY(Icon105)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal103,168,416,237,469)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_H_DOWN)
SHOW_MAP_BODY(Normal103)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_H_DOWN)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_H_DOWN,ICON_SCROLBAR_DOWN)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_H_DOWN,0,168,416,237,469)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin108)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin108,0,0,69,52)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon109, -1, 1, 68,34, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal107)
SHOW_MAP_BODY(Skin108)
SHOW_MAP_BODY(Icon109)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal107,285,416,354,468)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_MIN_DOWN)
SHOW_MAP_BODY(Normal107)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_MIN_DOWN)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_MIN_DOWN,ICON_SCROLBAR_DOWN)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_MIN_DOWN,0,285,416,354,468)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin112)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin112,0,0,69,51)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon113, -1, 1, 68,29, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal111)
SHOW_MAP_BODY(Skin112)
SHOW_MAP_BODY(Icon113)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal111,402,416,471,467)

SHOW_MAP_BEGIN(UIMenuWndSetup_datetime_SEC_DOWN)
SHOW_MAP_BODY(Normal111)
SHOW_MAP_END

DECLARE_EVENT(UIMenuWndSetup_datetime_SEC_DOWN)
CREATE_STATIC_DATA(UIMenuWndSetup_datetime_SEC_DOWN,ICON_SCROLBAR_DOWN)
CREATE_STATIC_CTRL(UIMenuWndSetup_datetime_SEC_DOWN,0,402,416,471,467)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin116)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin116,0,0,269,83)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text118,3,24,267,52,STRID_NULL,0,0,0,0,1,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal115)
SHOW_MAP_BODY(Skin116)
SHOW_MAP_BODY(Text118)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal115,500,269,769,352)

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime_Format)
SHOW_MAP_BODY(Normal115)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime_Format)
CREATE_STATIC_DATA(UIFlowWndSetup_datetime_Format,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndSetup_datetime_Format,0,500,269,769,352)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIFlowWndSetup_datetime)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndSetup_datetime)
DECLARE_CTRL_LIST(UIFlowWndSetup_datetime)
CREATE_CTRL(UIFlowWndSetup_datetime,UIFlowWndSetup_datetime,CTRL_WND,NULL,0 ,0,0,799,479)
#endif