//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "NVTToolCommand.h"
#include "UIFlowWndWrnMsgRes.c"
#include "UIFlowWndWrnMsgAPI.h"
#include "UIFlow.h"

//-----------------------------------------------------------------------------
// UIFlowWndWrnMsg User Variable & Function Declarations
//-----------------------------------------------------------------------------
static UINT32 g_uiWrnMsgIssue       = 0;
static UINT32 g_uiWrnMsgExpTime     = 0;
static UINT32 g_uiExpTimerID        = NULL_TIMER;
static UINT32 g_uiWrnMsgPseudoTimerID = NULL_TIMER;

//---------------------UIFlowWndWrnMsgCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndWrnMsg)
CTRL_LIST_ITEM(UIFlowWndWrnMsg_StatusTXT_Msg)
CTRL_LIST_END

//----------------------UIFlowWndWrnMsgCtrl Event---------------------------
INT32 UIFlowWndWrnMsg_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_OnKeyMode(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_OnKeyMenu(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_OnKeyPlayback(VControl *, UINT32, UINT32 *);
//#NT#2012/09/04#Ben Wang -begin
//#NT#Add PictureError warning message
INT32 UIFlowWndWrnMsg_OnKeyLeft(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_OnKeyRight(VControl *, UINT32, UINT32 *);
//#NT#2012/09/04#Ben Wang -end
INT32 UIFlowWndWrnMsg_OnTimer(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_EdogMessage(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_OnTouchKey(VControl *, UINT32, UINT32 *);

EVENT_BEGIN(UIFlowWndWrnMsg)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndWrnMsg_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndWrnMsg_OnClose)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIFlowWndWrnMsg_OnKeyEnter)
EVENT_ITEM(NVTEVT_KEY_MODE,UIFlowWndWrnMsg_OnKeyMode)
EVENT_ITEM(NVTEVT_KEY_MENU,UIFlowWndWrnMsg_OnKeyMenu)
EVENT_ITEM(NVTEVT_KEY_PLAYBACK,UIFlowWndWrnMsg_OnKeyPlayback)
//#NT#2012/09/04#Ben Wang -begin
//#NT#Add PictureError warning message
EVENT_ITEM(NVTEVT_KEY_LEFT,UIFlowWndWrnMsg_OnKeyLeft)
EVENT_ITEM(NVTEVT_KEY_RIGHT,UIFlowWndWrnMsg_OnKeyRight)
//#NT#2012/09/04#Ben Wang -end
EVENT_ITEM(NVTEVT_TIMER,UIFlowWndWrnMsg_OnTimer)
EVENT_ITEM(NVTEVT_EDOG_MESSAGE,UIFlowWndWrnMsg_EdogMessage)
EVENT_ITEM(NVTEVT_KEY_TP,UIFlowWndWrnMsg_OnTouchKey)
EVENT_END

INT32 UIFlowWndWrnMsg_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    debug_ind(("UIFlowWndWrnMsg: OnOpen\r\n"));

    if(paramNum > 0)
    {
        g_uiWrnMsgIssue = paramArray[0];
        debug_ind(("UIFlowWndWrnMsg: Issue case = %d\r\n", g_uiWrnMsgIssue));
        if(paramNum > 1)
        {
            g_uiWrnMsgExpTime = paramArray[1];
            debug_ind(("UIFlowWndWrnMsg: Exp time = %d\r\n", g_uiWrnMsgExpTime));
        }
    }

    debug_ind(("UIFlowWndWrnMsg_OnOpen g_uiWrnMsgIssue = %d\n\r",g_uiWrnMsgIssue));
    //#NT#2012/09/04#Ben Wang -begin
    //#NT#Add PictureError warning message 
    //UxState_SetItemData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_NO_FILE,STATE_ITEM_STRID,STRID_PICTUREERROR);
    //#NT#2012/09/04#Ben Wang -end
    UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,g_uiWrnMsgIssue);
    UxCtrl_SetShow(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,TRUE);

    /* Start window expiration timer */
    if(g_uiWrnMsgExpTime)
    {
        if(g_uiExpTimerID != NULL_TIMER)
        {
            GxTimer_StopTimer(&g_uiExpTimerID);
        }
        if(g_uiWrnMsgPseudoTimerID != NULL_TIMER)
        {
            GxTimer_StopTimer(&g_uiWrnMsgPseudoTimerID);
        }
        g_uiExpTimerID = GxTimer_StartTimer((1000 * g_uiWrnMsgExpTime), NVTEVT_WARNING_TIMER, ONE_SHOT);
        g_uiWrnMsgPseudoTimerID = GxTimer_StartTimer(1000, NVTEVT_1SEC_TIMER, CONTINUE);
    }
    SysSetFlag(FL_EDOG_WRNINGINDEX,g_uiWrnMsgIssue);
    Save_MenuInfo();	
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnMsg_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    /* Stop window expiration timer if exists */
    if(g_uiExpTimerID != NULL_TIMER)
    {
        GxTimer_StopTimer(&g_uiExpTimerID);
    }
    if(g_uiWrnMsgPseudoTimerID != NULL_TIMER)
    {
        GxTimer_StopTimer(&g_uiWrnMsgPseudoTimerID);
    }

    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}

INT32 UIFlowWndWrnMsg_OnTouchKey(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32 uiEvent;
    UINT32 P1,P2;
    UINT32  uiSoundMask;
  
    if(paramNum>0)
        uiEvent = paramArray[0];	
	
	switch(uiEvent)
	{
		case GESTURE_RIGHT2LEFT:						
		case GESTURE_LEFT2RIGHT:	
		case GESTURE_UP2DOWN:
		case GESTURE_DOWN2UP:
		case GESTURE_PRESSONLY:
		default:
		break;

		case GESTURE_RELEASE:	
	            switch (g_uiWrnMsgIssue)
	            {
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_BATTERY_LOW:
						break;
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_MEMORY_FULL:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_MEMORYERROR:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_CARD_FULL:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_CARDERROR:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_CARD_LOCKED:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_FILE_PROTECT:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_NO_IMAGE:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_NO_CARD:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_FOLDERFULL:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_NOT_JPEG:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_NO_FILE:
    						Ux_SendEvent(&UISetupObjCtrl,NVTEVT_EXE_CHANGEDSCMODE,1,DSCMODE_CHGTO_NEXT);						
						break;
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_PLEASE_INSERT_SD:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_CLUSTER_WRONG:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_SD_CLASS4:
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_SD_CLASS6:
						Ux_CloseWindow(&UIFlowWndWrnMsgCtrl,0);
					break;
					case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_PICTUREERROR:
        					Ux_CloseWindow(pCtrl,2,NVTRET_WARNING,NVTEVT_KEY_RIGHT);
					break;
						
	            }
		break;
	}	  	  
	return NVTEVT_CONSUME;
}

INT32 UIFlowWndWrnMsg_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnMsg_OnKeyMode(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISetupObjCtrl,NVTEVT_EXE_CHANGEDSCMODE,1,DSCMODE_CHGTO_NEXT);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnMsg_OnKeyMenu(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_CloseWindow(pCtrl,1,NVTRET_ENTER_MENU);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnMsg_OnKeyPlayback(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_SendEvent(&UISetupObjCtrl,NVTEVT_FORCETO_PLAYBACK_MODE,0);
    return NVTEVT_CONSUME;
}
//#NT#2012/09/04#Ben Wang -begin
//#NT#Add PictureError warning message 
INT32 UIFlowWndWrnMsg_OnKeyLeft(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(g_uiWrnMsgIssue == FLOWWRNMSG_ISSUE_PICTURE_ERR)
        Ux_CloseWindow(pCtrl,2,NVTRET_WARNING,NVTEVT_KEY_LEFT);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnMsg_OnKeyRight(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if(g_uiWrnMsgIssue == FLOWWRNMSG_ISSUE_PICTURE_ERR)
        Ux_CloseWindow(pCtrl,2,NVTRET_WARNING,NVTEVT_KEY_RIGHT);
    return NVTEVT_CONSUME;
}
//#NT#2012/09/04#Ben Wang -end

INT32 UIFlowWndWrnMsg_EdogMessage(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiEvent;
    EDOG_INFO EdogInfo;
    UINT32 ErrorCode;

    if(SysGetFlag(FL_EDOGMODE)== EDOG_OFF)
    return NVTEVT_CONSUME;

	
    uiEvent = paramNum ? paramArray[0] : 0;
    if((g_uiWrnMsgIssue<UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CHECKSUMING)||(g_uiWrnMsgIssue>(g_uiWrnMsgIssue<UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CHECKSUMING)))
    return NVTEVT_CONSUME;
		
    switch(uiEvent)
    {
		case 'U':
                   EdgoRec_GetEdogInfo(&EdogInfo);    			
			ErrorCode=EdogInfo.EdogUdateType;
			switch(ErrorCode)
			{
				case 0x01:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_LINK_OK;
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_LINK_OK);					
				 break;
				case 0x02:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATING;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATING);					
				 break;
				case 0x03:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_DONE;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_DONE);										
				 break;	
				case 0x04:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CONTINUSE;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CONTINUSE);										
				 break;		 
				case 0x05:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_LINK_DEVICE;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_LINK_DEVICE);										
				 break;		 		 
			}
		break;		
		case 'E':
                   EdgoRec_GetEdogInfo(&EdogInfo);    						
			ErrorCode=EdogInfo.EdogErrorType;
			switch(ErrorCode)
			{
				case 0x00:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CHECKSUMING;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CHECKSUMING);										
				 break;
				case 0x01:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR2;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR1);										
				 break;
				case 0x02:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR2;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR2);										
				 break;
				case 0x03:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR3;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR3);										
				 break;	
				case 0x04:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR4;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_ERROR4);										
				 break;		 
				case 0x07:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_READDATA_ERROR;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_READDATA_ERROR);										
				 break;		 
				case 0x08:
					g_uiWrnMsgIssue=UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CHECKSUMDATA_ERROR;					
    					UxState_SetData(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl,STATE_CURITEM,UIFlowWndWrnMsg_StatusTXT_Msg_STRID_UPDATE_CHECKSUMDATA_ERROR);										
				 break;		 
			}
		break;

	
    }
    SysSetFlag(FL_EDOG_WRNINGINDEX,g_uiWrnMsgIssue);
    Save_MenuInfo();	
    return NVTEVT_CONSUME;
}


INT32 UIFlowWndWrnMsg_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    NVTEVT event;

    event = paramArray[0];
    debug_ind(("UIFlowWndWrnMsg OnTimer event = 0x%x\r\n", event));

    switch(event)
    {
        case NVTEVT_WARNING_TIMER:
            /**************************************************************************************
            **
            ** Warning Timeout Action
            **
            **************************************************************************************/
            if(g_uiExpTimerID != NULL_TIMER)
            {
                GxTimer_StopTimer(&g_uiExpTimerID);
            }
            if(g_uiWrnMsgPseudoTimerID != NULL_TIMER)
            {
                GxTimer_StopTimer(&g_uiWrnMsgPseudoTimerID);
            }
            if (g_uiWrnMsgIssue == FLOWWRNMSG_ISSUE_PICTURE_ERR)
                Ux_CloseWindow(pCtrl,2,NVTRET_WARNING,FLOWWRNMSG_ISSUE_PICTURE_ERR);
            else
                Ux_CloseWindow(pCtrl,0);
            if (g_uiWrnMsgIssue == UIFlowWndWrnMsg_StatusTXT_Msg_STRID_BATTERY_LOW)
            {
                System_PowerOff(SYS_POWEROFF_NORMAL);
            }
            break;
        case NVTEVT_1SEC_TIMER:
            switch (g_uiWrnMsgIssue)
            {
            case UIFlowWndWrnMsg_StatusTXT_Msg_STRID_BATTERY_LOW:
                 if (UxCtrl_IsShow(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl) == TRUE)
                 {
                     UxCtrl_SetShow(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl, FALSE);
                 }
                 else
                 {
                     UxCtrl_SetShow(&UIFlowWndWrnMsg_StatusTXT_MsgCtrl, TRUE);
                 }
                break;
            }
            break;

        default:
            debug_err(("UIFlowWndWrnMsg OnTimer: Unknown event 0x%x\r\n", event));
            break;
    }
    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndWrnMsg_StatusTXT_MsgCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndWrnMsg_StatusTXT_Msg)
EVENT_END

