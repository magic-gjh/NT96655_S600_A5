//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndPlayRes.c"
#include "UIFlowWndPlay.h"


#include "UIFlowWndPlayMagnify.h"
#include "AppCommon.h"
#include "Audio.h"
#include "UIPlayObj.h"
#include "UICommon.h"
#include "UIFlow.h"
//#NT#2012/08/31#Calvin Chang#Porting Media Flow -begin
#include "MediaPlayAPI.h"
#include "DCF.h"
#include "UIMovieObj.h"
#include "UIFlowWndHome.h"
//---------------------UIFlowWndPlayCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndPlay)
CTRL_LIST_ITEM(UIFlowWndPlay_StaticICN_Protect)
CTRL_LIST_ITEM(UIFlowWndPlay_StaticTXT_Filename)
CTRL_LIST_ITEM(UIFlowWndPlay_StaticTXT_MovPlayTime)
CTRL_LIST_ITEM(UIFlowWndPlay_StaticTXT_Speed)
CTRL_LIST_ITEM(UIFlowWndPlay_Status_PRE_ONE)
CTRL_LIST_ITEM(UIFlowWndPlay_Status_Return)
CTRL_LIST_END

//----------------------UIFlowWndPlayCtrl Event---------------------------
INT32 UIFlowWndPlay_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlay_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndPlay_TP(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndPlay)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndPlay_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndPlay_OnClose)
EVENT_ITEM(NVTEVT_KEY_TP,UIFlowWndPlay_TP)
EVENT_END

static void UIFlowWndPlay_CheckStatus(void)
{
    UINT32 uiStatus, uiCurrMode;
    uiStatus = AppPlay_GetData(PLAY_PBSTATUS);
    uiCurrMode = AppPlay_GetData(PLAY_CURRMODE);

    // Decode Error & Read Error
    if( uiStatus & (PB_STA_ERR_FILE | PB_STA_ERR_DECODE) )
    {
        if(uiCurrMode == PLAYMODE_AVI || uiCurrMode == PLAYMODE_MOVMJPG)
        {
            UINT32  uiBuffAddr, uiBuffSize;
            CHAR    chaFullName[64] = { 0 };

            PB_GetParam(PBPRMID_DATABUF_ADDR, &uiBuffAddr);
            PB_GetParam(PBPRMID_DATABUF_SIZE, &uiBuffSize);
            PB_GetParam(PBPRMID_CURR_FILEPATH, (UINT32 *)&chaFullName);
            MediaPlay_FileRecovery(chaFullName, uiBuffAddr, uiBuffSize);
#if USE_FILEDB
            FileDB_Refresh(0); // should refresh FileDB
#else
            DCF_Refresh(); // should refresh DCF
#endif
            Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_PLAYSINGLE, 1, PB_SINGLE_CURR);
            uiStatus = AppPlay_GetData(PLAY_PBSTATUS);
            if( uiStatus == PB_STA_DONE)
                return;
        }
        Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,FLOWWRNMSG_ISSUE_PICTURE_ERR,FLOWWRNMSG_TIMER_KEEP);
    }
}


typedef enum
{
	UIFLOW_PLAYBACK_TOUCH_KEY_NONE,
	UIFLOW_PLAYBACK_TOUCH_KEY_SHU,				
	UIFLOW_PLAYBACK_TOUCH_KEY_HOME,			
	UIFLOW_PHOTO_TOUCH_KEY_MAX	
}UIFLOW_PLAYBACK_TOUCH_KEY;
static UIFLOW_PLAYBACK_TOUCH_KEY uiPlaybackKeyPressed=UIFLOW_PLAYBACK_TOUCH_KEY_NONE;

INT32 UIFlowWndPlay_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
      UINT32  uiSoundMask,uiStatus;

   

    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_PLAYINIT,0);
    //After playback ready, point to the last file

//    PB_OpenSpecFileBySeq(DCF_GetDBInfo(DCF_INFO_TOL_FILE_COUNT), TRUE);
    PB_OpenSpecFileBySeq(AppPlay_GetData(PLAY_FILENUM), TRUE);

    Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_PLAYSINGLE, 2, PB_SINGLE_CURR, 1);

    uiStatus = AppPlay_GetData(PLAY_PBSTATUS);

    if (uiStatus & PB_STA_NOIMAGE)
    //if(DCF_GetDBInfo(DCF_INFO_TOL_FILE_COUNT)==0)
    {
        Ux_OpenWindow(&UIFlowWndWrnMsgCtrl,2,FLOWWRNMSG_ISSUE_NO_IMAGE,FLOWWRNMSG_TIMER_KEEP);

    }
    else
    {
        g_PlbData.VideoPBSpeed=PLB_FWD_MOV_1x;
        g_PlbData.State = PLB_ST_FULL;
        UIFlowWndPlay_CheckStatus();
        
    }
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndPlay_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}

INT32 UIFlowWndPlay_TP(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
  UINT32 uiEvent;
    UINT32 P1,P2;
    UINT32  uiSoundMask;
  
    if(paramNum>0)
        uiEvent = paramArray[0];	
	
	switch(uiEvent)
	{
		case GESTURE_DOWN2UP://GESTURE_RIGHT2LEFT:
		    	
		break;			
		
		case GESTURE_UP2DOWN://GESTURE_LEFT2RIGHT:
		    		
		break;	
 
		case GESTURE_PRESSONLY:
			P1= paramArray[1];
			P2=paramArray[2];  
		    if(TPIsOnRange(&UIFlowWndPlay_Status_ReturnCtrl,P1,P2)==TRUE)
		    	{
		    	       uiPlaybackKeyPressed=UIFLOW_PLAYBACK_TOUCH_KEY_HOME;
		       	//Ux_PostEvent(NVTEVT_KEY_SHUTTER2, 1, NVTEVT_KEY_PRESS);	
		    	}		
                   
                
		   	
		break;

		case GESTURE_RELEASE:
			P1= paramArray[1];
			P2=paramArray[2];  
	            //debug_msg("^G movie GESTURE_RELEASE\r\n");
		    if(TPIsOnRange(&UIFlowWndPlay_Status_ReturnCtrl,P1,P2)==TRUE)
		    	{
		    	       if(uiPlaybackKeyPressed==UIFLOW_PLAYBACK_TOUCH_KEY_HOME)
		    	       {
			       	
                                   
                                    switch(g_PlbData.State)
				    {
				    case PLB_ST_FULL:
                               
				        
					   
					   Ux_OpenWindow((VControl *)(&UIFlowWndHomeCtrl), 0);
                                    
				        break;
                                case PLB_ST_PAUSE_MOV:
									#if 1
                              
                                         debug_msg("^G ==== MediaPlay_GetStatus = %d \r\n",MediaPlay_GetStatus());
				            Ux_SendEvent(&UIMoviePlayObjCtrl, NVTEVT_PAUSE_PLAY_MOVIE, 0);
                                         debug_msg("^G ==== MediaPlay_GetStatus = %d \r\n",MediaPlay_GetStatus());
				            Ux_SendEvent(&UIMoviePlayObjCtrl, NVTEVT_CLOSE_PLAY_MOVIE, 0);
                                        debug_msg("^G ==== MediaPlay_GetStatus = %d \r\n",MediaPlay_GetStatus());

				            //#NT#2012/10/23#Philex Lin - begin
				            // enable auto power off/USB detect timer
				            // enable key tone flag
				            KeyScan_EnableMisc(TRUE);
				            //#NT#2012/10/23#Philex Lin - end

				            
                                        Ux_SendEvent(&UIPlayObjCtrl,NVTEVT_PLAYSINGLE, 1, PB_SINGLE_CURR);
                                        g_PlbData.State = PLB_ST_MENU;
					   
					   Ux_OpenWindow((VControl *)(&UIFlowWndHomeCtrl), 0);
					   #endif
                                        break;
					default:
			            		FlowPB_UpdateIcons(1);
			               break;							
				    }	
		    	      	}
				else
				{ 
        				FlowPB_UpdateIcons(TRUE);
				}
		    	  }

			else
			    {
			    
			    }
		   
				
		    uiPlaybackKeyPressed=UIFLOW_PLAYBACK_TOUCH_KEY_NONE;
		
		break;
	}	  
	

	  
	return NVTEVT_CONSUME;
}



//----------------------UIFlowWndPlay_StaticICN_ProtectCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlay_StaticICN_Protect)
EVENT_END

//----------------------UIFlowWndPlay_StaticTXT_FilenameCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlay_StaticTXT_Filename)
EVENT_END

//----------------------UIFlowWndPlay_StaticTXT_MovPlayTimeCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlay_StaticTXT_MovPlayTime)
EVENT_END

//----------------------UIFlowWndPlay_StaticTXT_SpeedCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlay_StaticTXT_Speed)
EVENT_END

//----------------------UIFlowWndPlay_Status_PRE_ONECtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlay_Status_PRE_ONE)
EVENT_END

//----------------------UIFlowWndPlay_Status_ReturnCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndPlay_Status_Return)
EVENT_END
