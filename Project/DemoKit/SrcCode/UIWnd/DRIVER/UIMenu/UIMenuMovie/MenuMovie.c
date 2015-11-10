#include <stdio.h>
#include "UIFlow.h"

// --------------------------------------------------------------------------
// OPTIONS
// --------------------------------------------------------------------------
#if 1
#if (_MULTI_RECORD_FUNC_)
// Dual Recording Optiosn
TMDEF_BEGIN_OPTIONS(MOVIE_DUAL_REC)
    TMDEF_OPTION_TEXT(MOVIE_DUAL_REC_OFF)
    TMDEF_OPTION_TEXT(MOVIE_DUAL_REC_ON)
TMDEF_END_OPTIONS()
#endif

// Movie Size Options
#if (UPDATE_CFG == UPDATE_CFG_YES)
TM_OPTION gTM_OPTIONS_MOVIE_SIZE[MOVIE_SIZE_ID_MAX] = {0};
#else
TMDEF_BEGIN_OPTIONS(MOVIE_SIZE)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_1080FHD)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_720P)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_WVGA)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_VGA)
TMDEF_END_OPTIONS()
#endif

TMDEF_BEGIN_OPTIONS(MOVIE_SIZE_DUAL)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_1080P_720P)
    TMDEF_OPTION_TEXT(MOVIE_SIZE_720P_720P)
TMDEF_END_OPTIONS()

// Cyclic recroding Options
TMDEF_BEGIN_OPTIONS(MOVIE_CYCLIC_REC)
    TMDEF_OPTION_TEXT(MOVIE_CYCLIC_REC_OFF)
    TMDEF_OPTION_TEXT(MOVIE_CYCLIC_REC_3MIN)
    TMDEF_OPTION_TEXT(MOVIE_CYCLIC_REC_5MIN)
    TMDEF_OPTION_TEXT(MOVIE_CYCLIC_REC_10MIN)
TMDEF_END_OPTIONS()

// Time lapse recoring Options
TMDEF_BEGIN_OPTIONS(MOVIE_TIMELAPSE_REC)
    TMDEF_OPTION_TEXT(MOVIE_TIMELAPSE_REC_OFF)
    TMDEF_OPTION_TEXT(MOVIE_TIMELAPSE_REC_100MS)
    TMDEF_OPTION_TEXT(MOVIE_TIMELAPSE_REC_200MS)
    TMDEF_OPTION_TEXT(MOVIE_TIMELAPSE_REC_500MS)
TMDEF_END_OPTIONS()
TMDEF_BEGIN_OPTIONS(MOVIE_MOTION_DET)
    TMDEF_OPTION_TEXT(MOVIE_MOTION_DET_OFF)
    TMDEF_OPTION_TEXT(MOVIE_MOTION_DET_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_HDR)
    TMDEF_OPTION_TEXT(MOVIE_HDR_OFF)
    TMDEF_OPTION_TEXT(MOVIE_HDR_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_AUDIO)
    TMDEF_OPTION_TEXT(MOVIE_AUDIO_OFF)
    TMDEF_OPTION_TEXT(MOVIE_AUDIO_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_DATEIMPRINT)
    TMDEF_OPTION_TEXT(MOVIE_DATEIMPRINT_OFF)
    TMDEF_OPTION_TEXT(MOVIE_DATEIMPRINT_ON)
TMDEF_END_OPTIONS()

// Car num
TMDEF_BEGIN_OPTIONS(CAR_NUM)
    TMDEF_OPTION_TEXT(CAR_NUM_OFF)
    TMDEF_OPTION_TEXT(CAR_NUM_ON)
TMDEF_END_OPTIONS()

TMDEF_BEGIN_OPTIONS(MOVIE_GSENSOR)
    TMDEF_OPTION_TEXT(MOVIE_GSENSOR_OFF)
    TMDEF_OPTION_TEXT(MOVIE_GSENSOR_LOW)
    TMDEF_OPTION_TEXT(MOVIE_GSENSOR_MED)
    TMDEF_OPTION_TEXT(MOVIE_GSENSOR_HIGH)
TMDEF_END_OPTIONS()

// --------------------------------------------------------------------------
// OPTIONS
// --------------------------------------------------------------------------
// Monitor Options
TMDEF_BEGIN_OPTIONS(MOVIE_PARKING)
    TMDEF_OPTION_TEXT(MOVIE_PARKING_OFF)
    TMDEF_OPTION_TEXT(MOVIE_PARKING_ON)
TMDEF_END_OPTIONS()

#if 0
// Edog On Off
TMDEF_BEGIN_OPTIONS(EDOGMODE)
    TMDEF_OPTION_TEXT(EDOGMODE_OFF)
    TMDEF_OPTION_TEXT(EDOGMODE_ON)
TMDEF_END_OPTIONS()

// Radar volume
TMDEF_BEGIN_OPTIONS(EDOGVOLUME)
    TMDEF_OPTION_TEXT(EDOGVOLUME_LOWEST)
    TMDEF_OPTION_TEXT(EDOGVOLUME_MED)
    TMDEF_OPTION_TEXT(EDOGVOLUME_HIGHER)
    TMDEF_OPTION_TEXT(EDOGVOLUME_HIGHEST)    
TMDEF_END_OPTIONS()

// Radar Mute
TMDEF_BEGIN_OPTIONS(EDOGMUTE)
    TMDEF_OPTION_TEXT(EDOGMUTE_OFF)
    TMDEF_OPTION_TEXT(EDOGMUTE_20)
    TMDEF_OPTION_TEXT(EDOGMUTE_30)
    TMDEF_OPTION_TEXT(EDOGMUTE_40)
    TMDEF_OPTION_TEXT(EDOGMUTE_50)
    TMDEF_OPTION_TEXT(EDOGMUTE_60)
    TMDEF_OPTION_TEXT(EDOGMUTE_70)
    TMDEF_OPTION_TEXT(EDOGMUTE_80)
    TMDEF_OPTION_TEXT(EDOGMUTE_90)
    TMDEF_OPTION_TEXT(EDOGMUTE_100)
    TMDEF_OPTION_TEXT(EDOGMUTE_110)
    TMDEF_OPTION_TEXT(EDOGMUTE_120)    
TMDEF_END_OPTIONS()


// Radar Drive mode
TMDEF_BEGIN_OPTIONS(EDOGDRIVEMODE)
    TMDEF_OPTION_TEXT(EDOGDRIVEMODE_CAPTURE)
    TMDEF_OPTION_TEXT(EDOGDRIVEMODE_SAFETY)      
TMDEF_END_OPTIONS()

// Radar Sensitivity
TMDEF_BEGIN_OPTIONS(EDOGSENSITY)
    TMDEF_OPTION_TEXT(EDOGSENSITY_OFF)
    TMDEF_OPTION_TEXT(EDOGSENSITY_MED)
    TMDEF_OPTION_TEXT(EDOGSENSITY_HIGH)
    TMDEF_OPTION_TEXT(EDOGSENSITY_AUTO)    
TMDEF_END_OPTIONS()

// Radar Speed limit
TMDEF_BEGIN_OPTIONS(EDOGSPEED_LIMIT)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT0)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT40)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT50)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT60)    
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT70)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT80)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT90) 
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT100)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT110)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT120) 
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT130)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT140)
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT150)     
    TMDEF_OPTION_TEXT(EDOGSPEED_LIMIT160)         
TMDEF_END_OPTIONS()

// Radar Speed adjust
TMDEF_BEGIN_OPTIONS(EDOGSPEED_ADJUST)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N10)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N9)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N8)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N7)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N6)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N5)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N4)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N3)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N2)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_N1)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_0)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P1)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P2)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P3)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P4)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P5)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P6)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P7)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P8)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P9)
    TMDEF_OPTION_TEXT(EDOGSPEED_ADJUST_P10)      
TMDEF_END_OPTIONS()

// Radar Broadcast
TMDEF_BEGIN_OPTIONS(EDOGBROADCAST)
    TMDEF_OPTION_TEXT(EDOGBROADCAST_CONCISION)
    TMDEF_OPTION_TEXT(EDOGBROADCAST_COMPLETE)      
TMDEF_END_OPTIONS()
#endif
#endif
static int MenuCustom_EdogVolume(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIMenuWndEdogVolumeCtrl, 0);
    return TMF_PROCESSED;
}

static int MenuCustom_RadarDefault(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIMenuWndEdogDefaultCtrl, 0);
    return TMF_PROCESSED;
}

static int MenuCustom_RadarVersion(UINT32 uiMessage, UINT32 uiParam)
{
    Ux_OpenWindow(&UIMenuWndSetupVersionCtrl, 1,TRUE);
    return TMF_PROCESSED;
}

TMDEF_BEGIN_ITEMS(MOVIE)
    TMDEF_ITEM_TEXTID(MOVIE_SIZE)
#if (_MULTI_RECORD_FUNC_)
    TMDEF_ITEM_TEXTID(MOVIE_DUAL_REC)
#endif
    TMDEF_ITEM_TEXTID(MOVIE_CYCLIC_REC)
    TMDEF_ITEM_TEXTID(MOVIE_TIMELAPSE_REC)
    TMDEF_ITEM_TEXTID(MOVIE_HDR)
    //TMDEF_ITEM_TEXTID(MOVIE_EV)
    TMDEF_ITEM_TEXTID(EV)
    TMDEF_ITEM_TEXTID(MOVIE_MOTION_DET)
    TMDEF_ITEM_TEXTID(MOVIE_AUDIO)
    TMDEF_ITEM_TEXTID(MOVIE_DATEIMPRINT)
    TMDEF_ITEM_TEXTID(CAR_NUM)        
    TMDEF_ITEM_TEXTID(MOVIE_GSENSOR)
    TMDEF_ITEM_TEXTID(MOVIE_PARKING)    
    #if(GPS_FUNCTION == ENABLE)    
    //TMDEF_ITEM_TEXTID(MOVIE_GPS)
#endif 
TMDEF_END_ITEMS()

// Movie Size Menu Items (for single/dual rec menu item data copy)
TMDEF_BEGIN_ITEMS(MOVIE_SIZE)
    TMDEF_ITEM_TEXTID(MOVIE_SIZE)
    TMDEF_ITEM_TEXTID(MOVIE_SIZE_DUAL)
TMDEF_END_ITEMS()

TMDEF_BEGIN_PAGES(MOVIE)
    TMDEF_PAGE_TEXT_ICON(MOVIE)
    //TMDEF_PAGE_TEXT_ICON(SETUP)
TMDEF_END_PAGES()

TMDEF_EMNU(gMovieMenu, MOVIE, Movie_MenuCallback)

void Movie_MenuSizeConfig(void)
{
#if (_MULTI_RECORD_FUNC_)
    UINT32 i = SysGetFlag(FL_MOVIE_DUAL_REC) ? 1 : 0;

    // copy item "MOVIE_SIZE" or "MOVIE_SIZE_DUAL" to movie menu
    memcpy((void *)&gTM_ITEMS_MOVIE[0], (void *)&gTM_ITEMS_MOVIE_SIZE[i], sizeof(TM_ITEM));
#endif
}

int Movie_MenuCallback(UINT32 uiMessage, UINT32 uiParam)
{
    UINT16  uwItemId;
    UINT16  uwOption;

    if (uiMessage == TMM_CONFIRM_OPTION)
    {
        uwItemId = LO_WORD(uiParam);
        uwOption = HI_WORD(uiParam);

        switch (uwItemId)
        {
        case IDM_MOVIE_SIZE:
        case IDM_MOVIE_SIZE_DUAL:
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIESIZE, 1, uwOption);
            if(System_GetState(SYS_STATE_CURRMODE)==PRIMARY_MODE_MOVIE)
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_IMAGE_RATIO, 1, uwOption);
            break;

        case IDM_EV:
            Ux_SendEvent(&CustomPhotoObjCtrl, NVTEVT_EXE_EV, 1, uwOption);
            break;

        case IDM_MOVIE_HDR:
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIE_HDR, 1, uwOption);
            break;

#if (_MULTI_RECORD_FUNC_)
        case IDM_MOVIE_DUAL_REC:
            if(System_GetState(SYS_STATE_CURRMODE)==PRIMARY_MODE_MOVIE)
                    {
                    UINT32 uiSelect = (uwOption == 0) ? FALSE : TRUE; // according to option order
                Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_DUAL_REC, 1, uiSelect);
                Movie_MenuSizeConfig();
                UINT32 uiSize;
                    uiSize = UI_GetData(FL_MOVIE_DUAL_REC) ? UI_GetData(FL_MOVIE_SIZE_DUAL) : UI_GetData(FL_MOVIE_SIZE);
                Ux_SendEvent(&CustomMovieObjCtrl,NVTEVT_EXE_MOVIESIZE, 1, uiSize);
                    Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_IMAGE_RATIO, 1, uiSize);
                    /*
        		if(!UI_GetData(FL_MOVIE_DUAL_REC))
        			PipView_SetStyle(PIP_STYLE_1T1F);
                        else
                            PipView_SetStyle(PIP_STYLE_2T1B2S);
                            */
                    }
                else
                    {
                    UI_SetData(FL_MOVIE_DUAL_REC, uwOption);
                    }
            #if 0
            {
                UINT32 uiSelect = (uwOption == 0) ? FALSE : TRUE; // according to option order
                Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_DUAL_REC, 1, uiSelect);
                Movie_MenuSizeConfig();
            }
            {
                // set image ratio
                UINT32 uiSize;
                uiSize = SysGetFlag(FL_MOVIE_DUAL_REC) ? SysGetFlag(FL_MOVIE_SIZE_DUAL) : SysGetFlag(FL_MOVIE_SIZE);
                Ux_SendEvent(&CustomMovieObjCtrl,NVTEVT_EXE_MOVIESIZE, 1, uiSize);
                Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_IMAGE_RATIO, 1, uiSize);
            }
            #endif
            break;
#endif

        case IDM_MOVIE_CYCLIC_REC:
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_CYCLIC_REC, 1, uwOption);
            break;

        case IDM_MOVIE_TIMELAPSE_REC:
            SysSetFlag(FL_MOVIE_TIMELAPSE_REC,uwOption);
            break;

        case IDM_MOVIE_MOTION_DET:
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOTION_DET, 1, uwOption);
            break;

        case IDM_MOVIE_AUDIO:
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIE_AUDIO, 1, uwOption);
            break;

        case IDM_MOVIE_DATEIMPRINT:
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIE_DATE_IMPRINT, 1, uwOption);
            break;
			
	  case IDM_CAR_NUM:
	  	if(uwOption==1)
	  	{
	            if (SysGetFlag(FL_LANGUAGE) == LANG_SC) 
	            {
	                Ux_OpenWindow(&UIMenuWndSetupCarNumberCtrl, 1, 0);
	            }
	            else
	            {
	                Ux_OpenWindow(&UIMenuWndSetupCommonCarNumberCtrl, 1, 0);
	            }		
		}
	  	break;
		
        case IDM_MOVIE_GSENSOR:
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_GSENSOR,1,uwOption);
            break;
			
        case IDM_MOVIE_PARKING:
            Ux_SendEvent(&CustomMovieObjCtrl, NVTEVT_EXE_MOVIEPARKING, 1, uwOption);
            break;

        case IDM_EDOGMODE:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_EDOGMODE, 1, uwOption);			
		break;
	case IDM_EDOGVOLUME:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_EDOGVOLUME, 1, uwOption);					
		break;
        case IDM_EDOGMUTE:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_EDOGMUTE, 1, uwOption);						
            break;
			
        case IDM_EDOGDRIVEMODE:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_EDOGDRIVEMODE, 1, uwOption);						
            break;
			
        case IDM_EDOGSENSITY:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_EDOGSENSITY, 1, uwOption);						
            break;
			
        case IDM_EDOGSPEED_LIMIT:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_EDOGSPEED_LIMIT, 1, uwOption);						
            break;
			
        case IDM_EDOGSPEED_ADJUST:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_EDOGSPEED_ADJUST, 1, uwOption);						
            break;
			
        case IDM_EDOGBROADCAST:
            Ux_SendEvent(&UISetupObjCtrl, NVTEVT_EXE_EDOGBROADCAST, 1, uwOption);						
            break;	
    
        default:
            Setup_MenuCallback(uiMessage, uiParam);
            break;
        }
    }
    else if (uiMessage == TMM_ENTER_ITEM)
    {
        Movie_MenuSizeConfig();
    }

    return TMF_PROCESSED;
}
