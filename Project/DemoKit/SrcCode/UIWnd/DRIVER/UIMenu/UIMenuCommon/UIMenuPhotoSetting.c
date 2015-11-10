//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuPhotoSettingRes.c"
#include "UIMenuPhotoSetting.h"

#include "UIFlow.h"
#include "MenuId.h"


typedef enum
{
	UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_NONE,
	UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_SHU,				
	UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_HOME,	
	UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_RETURN,	
	UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_MAX	
}UIFLOW_UIMenuPhotoSetting_TOUCH_KEY;
//---------------------UIMenuPhotoSettingCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuPhotoSetting)
CTRL_LIST_ITEM(Panel88)
CTRL_LIST_ITEM(UIMenuPhotoSetting_TXT_Title)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_Return)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_SelfTime)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_Size)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_CntShoot)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_Quality)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_Sharp)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_HandSheak)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_EV)
CTRL_LIST_ITEM(UIMenuPhotoSetting_Status_ISO)
CTRL_LIST_ITEM(UIMenuMovieSetting_Status_AWB)
CTRL_LIST_END

//----------------------UIMenuPhotoSettingCtrl Event---------------------------
INT32 UIMenuPhotoSetting_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuPhotoSetting_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuPhotoSetting_TP(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuPhotoSetting)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuPhotoSetting_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuPhotoSetting_OnClose)
EVENT_ITEM(NVTEVT_KEY_TP,UIMenuPhotoSetting_TP)
EVENT_END


INT32 UIMenuPhotoSetting_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuPhotoSetting_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}


static UIFLOW_UIMenuPhotoSetting_TOUCH_KEY uiPhotoSettingPressed=UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_NONE;



void  GotoPHOTO_MenuItemOption(int pCtrl)
{
  TM_MENU*    pMenu = TM_GetMenu();
    TM_PAGE*    pPage;
    TM_ITEM*    pItem;
    int ItemNum = 0;
    pMenu->Status = TMS_ON_ITEM;
    {
        pPage = &pMenu->pPages[pMenu->SelPage];
       
                pPage->SelItem = pCtrl;
               
        pItem = &pPage->pItems[pPage->SelItem];

        if (pItem->Count != 0 && pItem->SysFlag != 0)   // standard process
        {
            if (TM_MENU_CALLBACK(pMenu, TMM_ENTER_OPTION, MAKE_LONG(pItem->ItemId, 0)) == TMF_PASS_MESSAGE)
            {
                return NVTEVT_CONSUME;
            }
        }

       
        Ux_Redraw();

        if (pItem->Count != 0 && pItem->SysFlag != 0)   // standard process
        {
            pMenu->Status = TMS_ON_OPTION;
            Ux_OpenWindow(&MenuCommonOptionCtrl, 0);
        }
        else if (pItem->pOptions != 0)                  // custom process
        {
            pMenu->Status = TMS_ON_CUSTOM;
            TM_ITEM_CALLBACK(pItem, 0, 0);              // execute custom menu flow
        }
    }
}



INT32 UIMenuPhotoSetting_TP(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
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
		    if(TPIsOnRange(&UIMenuPhotoSetting_Status_ReturnCtrl,P1,P2)==TRUE)
		    	{
		    	       uiPhotoSettingPressed=UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_RETURN;
		       	//Ux_PostEvent(NVTEVT_KEY_SHUTTER2, 1, NVTEVT_KEY_PRESS);	
		    	}		
                    
		   	
		break;

		case GESTURE_CKICK:
			P1= paramArray[1];
			P2=paramArray[2];  
     
	            //debug_msg("^G movie GESTURE_RELEASE\r\n");
		    if(TPIsOnRange(&UIMenuPhotoSetting_Status_ReturnCtrl,P1,P2)==TRUE)
		    	{
		    	       //if(uiPhotoSettingPressed==UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_RETURN)
		    	       {
			       	
                                 
							Ux_CloseWindow((VControl *)(&UIMenuPhotoSettingCtrl), 0);
					
		    	       }
								   
		    	}	
            else if(TPIsOnRange(&UIMenuPhotoSetting_Status_SelfTimeCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoPHOTO_MenuItemOption(MENU_SELFTIMER);
								   
		    	}	
            else if(TPIsOnRange(&UIMenuPhotoSetting_Status_SizeCtrl,P1,P2)==TRUE)
		    	{
		    	      
						GotoPHOTO_MenuItemOption(MENU_PHOTO_SIZE);		   
		    	}	
            else if(TPIsOnRange(&UIMenuPhotoSetting_Status_CntShootCtrl,P1,P2)==TRUE)
		    	{
		    	      
						GotoPHOTO_MenuItemOption(MENU_CONTINUE_SHOT);			   
		    	}	
            else if(TPIsOnRange(&UIMenuPhotoSetting_Status_QualityCtrl,P1,P2)==TRUE)
		    	{
		    	      
							GotoPHOTO_MenuItemOption(MENU_QUALITY);		   
		    	}	
            else if(TPIsOnRange(&UIMenuPhotoSetting_Status_SharpCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoPHOTO_MenuItemOption(MENU_SHARPNESS);	
								   
		    	}	
            else if(TPIsOnRange(&UIMenuPhotoSetting_Status_HandSheakCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoPHOTO_MenuItemOption(MENU_ANTISHAKE);	
								   
		    	}	
            else if(TPIsOnRange(&UIMenuPhotoSetting_Status_EVCtrl,P1,P2)==TRUE)
		    	{
		    	      
						GotoPHOTO_MenuItemOption(MENU_EV);			   
		    	}	
            else if(TPIsOnRange(&UIMenuPhotoSetting_Status_ISOCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoPHOTO_MenuItemOption(MENU_ISO);	
								   
		    	}	
            else if(TPIsOnRange(&UIMenuMovieSetting_Status_AWBCtrl,P1,P2)==TRUE)
		    	{
		    	      GotoPHOTO_MenuItemOption(MENU_WB);	
								   
		    	}	
           
           else
			    {
			    
			    }
		   
				
		    uiPhotoSettingPressed=UIFLOW_UIMenuPhotoSetting_TOUCH_KEY_NONE;
		
		break;
	}	  
	

	  
	return NVTEVT_CONSUME;
}

//---------------------Panel88Ctrl Control List---------------------------
CTRL_LIST_BEGIN(Panel88)
CTRL_LIST_END

//----------------------Panel88Ctrl Event---------------------------
EVENT_BEGIN(Panel88)
EVENT_END

//----------------------UIMenuPhotoSetting_TXT_TitleCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_TXT_Title)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_ReturnCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_Return)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_SelfTimeCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_SelfTime)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_SizeCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_Size)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_CntShootCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_CntShoot)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_QualityCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_Quality)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_SharpCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_Sharp)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_HandSheakCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_HandSheak)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_EVCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_EV)
EVENT_END

//----------------------UIMenuPhotoSetting_Status_ISOCtrl Event---------------------------
EVENT_BEGIN(UIMenuPhotoSetting_Status_ISO)
EVENT_END

//----------------------UIMenuMovieSetting_Status_AWBCtrl Event---------------------------
EVENT_BEGIN(UIMenuMovieSetting_Status_AWB)
EVENT_END
