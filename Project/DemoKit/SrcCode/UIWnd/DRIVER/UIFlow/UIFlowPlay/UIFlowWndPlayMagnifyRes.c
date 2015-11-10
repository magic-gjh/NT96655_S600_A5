//This source code is generated by UI Designer Studio.

#ifndef UIFLOWWNDPLAYMAGNIFYRES_H
#define UIFLOWWNDPLAYMAGNIFYRES_H

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

SHOW_ITEM_RECT(CMD_Rectangle,Skin3Rect,0,0,59,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_BODY(Skin3Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,59,27)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text5,0,0,59,27,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal2)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_BODY(Text5)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal2,16,412,75,439)

SHOW_MAP_BEGIN(UIFlowWndPlayMagnify_StaticTXT_DZoom)
SHOW_MAP_BODY(Normal2)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify_StaticTXT_DZoom)
CREATE_STATIC_DATA(UIFlowWndPlayMagnify_StaticTXT_DZoom,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndPlayMagnify_StaticTXT_DZoom,0,16,412,75,439)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin8,0,0,140,100)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon9, 44, 47, 99,101, ICONID_NULL,83886080,0,0,4,0,0,0,0)
SHOW_MAP_BEGIN(Normal7)
SHOW_MAP_BODY(Skin8)
SHOW_MAP_BODY(Icon9)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal7,525,86,665,186)

SHOW_MAP_BEGIN(UIFlowWndPlayMagnify_StaticIcon_DirUp)
SHOW_MAP_BODY(Normal7)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify_StaticIcon_DirUp)
CREATE_STATIC_DATA(UIFlowWndPlayMagnify_StaticIcon_DirUp,ICON_PLAYPHOTO_UP)
CREATE_STATIC_CTRL(UIFlowWndPlayMagnify_StaticIcon_DirUp,0,525,86,665,186)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin12)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin12,0,0,155,89)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon13, 43, 2, 103,58, ICONID_NULL,83886080,0,0,4,0,0,0,0)
SHOW_MAP_BEGIN(Normal11)
SHOW_MAP_BODY(Skin12)
SHOW_MAP_BODY(Icon13)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal11,528,306,683,395)

SHOW_MAP_BEGIN(UIFlowWndPlayMagnify_StaticIcon_DirDown)
SHOW_MAP_BODY(Normal11)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify_StaticIcon_DirDown)
CREATE_STATIC_DATA(UIFlowWndPlayMagnify_StaticIcon_DirDown,ICON_PLAYPHOTO_DOWN)
CREATE_STATIC_CTRL(UIFlowWndPlayMagnify_StaticIcon_DirDown,0,528,306,683,395)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin16)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin16,0,0,92,106)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon17, 0, 35, 55,78, ICONID_NULL,83886080,0,0,4,0,0,0,0)
SHOW_MAP_BEGIN(Normal15)
SHOW_MAP_BODY(Skin16)
SHOW_MAP_BODY(Icon17)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal15,665,186,757,292)

SHOW_MAP_BEGIN(UIFlowWndPlayMagnify_StaticIcon_DirRight)
SHOW_MAP_BODY(Normal15)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify_StaticIcon_DirRight)
CREATE_STATIC_DATA(UIFlowWndPlayMagnify_StaticIcon_DirRight,ICON_PLAYPHOTO_RIGHT)
CREATE_STATIC_CTRL(UIFlowWndPlayMagnify_StaticIcon_DirRight,0,665,186,757,292)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin20)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin20,0,0,97,102)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon21, 39, 25, 95,81, ICONID_NULL,0,0,0,4,0,0,0,0)
SHOW_MAP_BEGIN(Normal19)
SHOW_MAP_BODY(Skin20)
SHOW_MAP_BODY(Icon21)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal19,441,196,538,298)

SHOW_MAP_BEGIN(UIFlowWndPlayMagnify_StaticIcon_DirLeft)
SHOW_MAP_BODY(Normal19)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify_StaticIcon_DirLeft)
CREATE_STATIC_DATA(UIFlowWndPlayMagnify_StaticIcon_DirLeft,ICON_PLAYPHOTO_LEFT)
CREATE_STATIC_CTRL(UIFlowWndPlayMagnify_StaticIcon_DirLeft,0,441,196,538,298)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin24)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin24,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon25, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal23)
SHOW_MAP_BODY(Skin24)
SHOW_MAP_BODY(Icon25)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal23,258,417,329,479)

SHOW_MAP_BEGIN(Skin27)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin27,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon28, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused26)
SHOW_MAP_BODY(Skin27)
SHOW_MAP_BODY(Icon28)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused26,258,417,329,479)

SHOW_MAP_BEGIN(Skin30)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin30,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon31, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable29)
SHOW_MAP_BODY(Skin30)
SHOW_MAP_BODY(Icon31)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable29,258,417,329,479)

SHOW_MAP_BEGIN(Skin33)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin33,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon34, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable32)
SHOW_MAP_BODY(Skin33)
SHOW_MAP_BODY(Icon34)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable32,258,417,329,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin36Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin36)
SHOW_MAP_BODY(Skin36Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin36,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon37, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed35)
SHOW_MAP_BODY(Skin36)
SHOW_MAP_BODY(Icon37)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed35,258,417,329,479)

CREATE_LIST_ITEM_DATA(ICON_PLAY_PHOTO_ZOOMIN38,STRID_NULL,ICON_PLAY_PHOTO_ZOOMIN,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlayMagnify_Status_PhotoZoomin)
SHOW_MAP_BODY(Normal23)
SHOW_MAP_BODY(Focused26)
SHOW_MAP_BODY(Normal_Disable29)
SHOW_MAP_BODY(Focused_Disable32)
SHOW_MAP_BODY(Pressed35)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify_Status_PhotoZoomin)
LIST_LIST_BEGIN(UIFlowWndPlayMagnify_Status_PhotoZoomin)
LIST_LIST_ITEM(ICON_PLAY_PHOTO_ZOOMIN38)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlayMagnify_Status_PhotoZoomin,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlayMagnify_Status_PhotoZoomin,UIFlowWndPlayMagnify_Status_PhotoZoomin,0,258,417,329,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(Skin40)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin40,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon41, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal39)
SHOW_MAP_BODY(Skin40)
SHOW_MAP_BODY(Icon41)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal39,329,417,400,479)

SHOW_MAP_BEGIN(Skin43)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin43,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon44, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused42)
SHOW_MAP_BODY(Skin43)
SHOW_MAP_BODY(Icon44)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused42,329,417,400,479)

SHOW_MAP_BEGIN(Skin46)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin46,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon47, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal_Disable45)
SHOW_MAP_BODY(Skin46)
SHOW_MAP_BODY(Icon47)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable45,329,417,400,479)

SHOW_MAP_BEGIN(Skin49)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin49,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon50, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Focused_Disable48)
SHOW_MAP_BODY(Skin49)
SHOW_MAP_BODY(Icon50)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable48,329,417,400,479)

SHOW_ITEM_RECT(CMD_Rectangle,Skin52Rect,0,0,71,62,0,0,4,4,0,0,0)
SHOW_MAP_BEGIN(Skin52)
SHOW_MAP_BODY(Skin52Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin52,0,0,71,62)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon53, 0, 0, 71,62, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Pressed51)
SHOW_MAP_BODY(Skin52)
SHOW_MAP_BODY(Icon53)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed51,329,417,400,479)

CREATE_LIST_ITEM_DATA(ICON_PLAY_PHOTO_ZOOMOUT54,STRID_NULL,ICON_PLAY_PHOTO_ZOOMOUT,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlayMagnify_Status_PhotoZoomout)
SHOW_MAP_BODY(Normal39)
SHOW_MAP_BODY(Focused42)
SHOW_MAP_BODY(Normal_Disable45)
SHOW_MAP_BODY(Focused_Disable48)
SHOW_MAP_BODY(Pressed51)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify_Status_PhotoZoomout)
LIST_LIST_BEGIN(UIFlowWndPlayMagnify_Status_PhotoZoomout)
LIST_LIST_ITEM(ICON_PLAY_PHOTO_ZOOMOUT54)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlayMagnify_Status_PhotoZoomout,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlayMagnify_Status_PhotoZoomout,UIFlowWndPlayMagnify_Status_PhotoZoomout,0,329,417,400,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_IMAGE(CMD_Image,Image57, -1, 1, 66,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin56)
SHOW_MAP_BODY(Image57)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin56,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text59,23,31,52,47,STRID_NULL,0,0,0,0,2,1,1,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal55)
SHOW_MAP_BODY(Skin56)
SHOW_MAP_BODY(Text59)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal55,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image62, 1, 1, 67,62, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin61)
SHOW_MAP_BODY(Image62)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin61,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text64,23,31,52,47,STRID_NULL,0,0,0,0,2,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused60)
SHOW_MAP_BODY(Skin61)
SHOW_MAP_BODY(Text64)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused60,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image67, 0, 1, 66,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin66)
SHOW_MAP_BODY(Image67)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin66,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text69,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal_Disable65)
SHOW_MAP_BODY(Skin66)
SHOW_MAP_BODY(Text69)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal_Disable65,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image72, -1, 0, 67,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Skin71)
SHOW_MAP_BODY(Image72)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin71,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text74,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Focused_Disable70)
SHOW_MAP_BODY(Skin71)
SHOW_MAP_BODY(Text74)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Focused_Disable70,731,417,799,479)

SHOW_ITEM_IMAGE(CMD_Image,Image77, 1, 1, 68,61, ICON_MAIN_RETURN,83886080,0,0,0,0,0,17,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin76Rect,0,0,68,62,0,0,6,6,0,0,0)
SHOW_MAP_BEGIN(Skin76)
SHOW_MAP_BODY(Skin76Rect)
SHOW_MAP_BODY(Image77)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin76,0,0,68,62)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text79,23,31,52,47,STRID_NULL,0,0,0,0,1,1,1,256,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Pressed75)
SHOW_MAP_BODY(Skin76)
SHOW_MAP_BODY(Text79)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Pressed75,731,417,799,479)

CREATE_LIST_ITEM_DATA(STRID_NULL_80,STRID_NULL_,ICONID_NULL,STATUS_ENABLE) 
SHOW_MAP_BEGIN(UIFlowWndPlayMagnify_Status_Return)
SHOW_MAP_BODY(Normal55)
SHOW_MAP_BODY(Focused60)
SHOW_MAP_BODY(Normal_Disable65)
SHOW_MAP_BODY(Focused_Disable70)
SHOW_MAP_BODY(Pressed75)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify_Status_Return)
LIST_LIST_BEGIN(UIFlowWndPlayMagnify_Status_Return)
LIST_LIST_ITEM(STRID_NULL_80)
LIST_LIST_END

CREATE_LIST_DATA(UIFlowWndPlayMagnify_Status_Return,0,1,MENU_LAYOUT_VERTICAL|MENU_DISABLE_SHOW|MENU_SCROLL_STOP|MENU_SCROLL_NEXT_PAGE|MENU_DISABLE_NORMAL|LIST_DRAW_IMAGE,NVTEVT_NULL)

CREATE_LIST_CTRL(UIFlowWndPlayMagnify_Status_Return,UIFlowWndPlayMagnify_Status_Return,0,731,417,799,479)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//#NT#2009/07/24#Chris Chung -begin
//#NT#add specific rectangle for zoom in/out/move
//@@@@@@@@@@@@@@@@@@@@@@@  ZoomWin  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
SHOW_ITEM_RECT(CMD_Rectangle,Skin5600Rect,0,0,119,129,0,0,2,2,0,0,0)
SHOW_MAP_BEGIN(Skin5600)
SHOW_MAP_BODY(Skin5600Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin5600,0,0,22,21)

//SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon57, 1, 1, 20,21, ICONID_NULL,83886080,2,2,0,0,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin9900Rect,0,0,119,129,272,1,1,15,0,0,0)
SHOW_ITEM_RECT(CMD_Rectangle,Skin10000Rect,0,0,19,14,16,2,7,7,0,0,0) // color index 7: ORANGE

SHOW_MAP_BEGIN(Normal5500)
SHOW_MAP_BODY(Skin5600)
SHOW_MAP_BODY(Skin9900Rect)
SHOW_MAP_BODY(Skin10000Rect)

SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal5500,536,187,665,306)

SHOW_MAP_BEGIN(ZoomWin)
SHOW_MAP_BODY(Normal5500)
SHOW_MAP_END

DECLARE_EVENT(ZoomWin)
CREATE_ZOOM_DATA(ZoomWin,0)
CREATE_ZOOM_CTRL(ZoomWin,0,536,187,665,306)
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//#NT#2009/07/24#Chris Chung -end
SHOW_MAP_BEGIN(UIFlowWndPlayMagnify)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndPlayMagnify)
DECLARE_CTRL_LIST(UIFlowWndPlayMagnify)
CREATE_CTRL(UIFlowWndPlayMagnify,UIFlowWndPlayMagnify,CTRL_WND,NULL,0 ,0,0,799,479)
#endif
