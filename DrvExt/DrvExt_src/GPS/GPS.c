/*
    Copyright   Novatek Microelectronics Corp. 2005.  All rights reserved.

    @file       GPS.c
    @ingroup

    @brief      Excute command via UART interface.
                Excute command and output message via UART interface.

    @note       Nothing.

    @version    V1.00.000
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Debug.h"
#include "SysKer.h"
#include "Kernel.h"
#include "UART.h"
#include "GPS.h"

#include "../../../Project/DemoKit/SrcCode/NVTUserCommand.h"


#define _GPS_DEBUG_SYMBOL         0
#if _GPS_DEBUG_SYMBOL
#define GPS_debug(arg)            debug_msg arg
#else
#define GPS_debug(arg)
#endif

#define _GPS_NMEA_DEBUG_SYMBOL    0
#if _GPS_NMEA_DEBUG_SYMBOL
#define NMEA_debug(arg)            debug_msg arg
#else
#define NMEA_debug(arg)
#endif


#define UART_CONNECT_EDOG      ENABLE

#define EDOG_START_BYTE      0x7C  // "|"
#define EDOG_STOP_BYTE      0x7E  // "~"

#define DEBUG_MSG 0

EDOG_INFO  EdogInfo;


//Declare functions
BOOL GPSRec_NMEAParser(CHAR *NMEA_str, UINT32 Len, NMEATYPE NMEAtype);


//Declare variables
GSAINFO GSAInfo;
RMCINFO RMCInfo;
GGAINFO GGAInfo;
GSVINFO GSVInfo;
RDINFO RDInfo;
#define RD_START_BYTE      0x02  // "|"
#define RD_STOP_BYTE      0x03  // "~"

_ALIGNED(4) NMEASENTENCE NMEASentence={0};


#define PRI_GPSRECEIVE            10
#define STKSIZE_GPSRECEIVE        6144//64KB stack size
UINT32 GPSRECEIVE_ID = 0;
UINT32 FLG_ID_GPS = 0;

// global variables for parsing NMEA code
CHAR   type[6],RemainStr[NMEA_SENTENCE_SIZE], PostPtr[NMEA_SENTENCE_SIZE + 20], *pPostPrt;
UINT32 PostPtrLen;
UINT32 CheckSum;
//GSA used
CHAR   SelMode;
UINT32 FixMode, SatUsed01, SatUsed02, SatUsed03, SatUsed04, SatUsed05, SatUsed06, SatUsed07, SatUsed08, SatUsed09, SatUsed10, SatUsed11, SatUsed12;
double  PDOP, HDOP, VDOP;
//RMC used
UINT32 Date;
CHAR   Status,MagVarInd;
double  Speed, Angle, MagVar;
//GGA used
double  UTCTime;
UINT32 PosFixInd, SatNumber, Empty1, Empty2;
double  Lat, Lon, Alt, MSL;
CHAR   NSInd, EWInd, M1, M2;
//GSV used
UINT32 NumOfSen, SenNum, SatInView, SatNum1, Elev1, Azi1, SNR1, SatNum2, Elev2, Azi2, SNR2, SatNum3, Elev3, Azi3, SNR3, SatNum4, Elev4, Azi4, SNR4;


extern void GPSRecTsk(void);

BOOL GPSRec_TransformData(CHAR *NMEA_str, UINT32 Len, CHAR *pPostPrt, UINT32 *PostPtrLen);
BOOL GPSRec_CheckSum(CHAR *NMEA_str, UINT32 Len, UINT32 CheckSum);
BOOL GPSRec_GetUTCDate(UINT32 *Year, UINT32 *Month, UINT32 *Day);
BOOL GPSRec_GetUTCTime(UINT32 *Hour, UINT32 *Minute, UINT32 *Second);

void GPS_InstallID(void)
{
    debug_msg("GPS_InstallID...\r\n");
    OS_CONFIG_TASK(GPSRECEIVE_ID, PRI_GPSRECEIVE, STKSIZE_GPSRECEIVE, GPSRecTsk);
    OS_CONFIG_FLAG(FLG_ID_GPS);
}

static BOOL bGPSRecOpened = FALSE;
ER GPSRec_Open(UART_BAUDRATE BaudRate)
{

    if (bGPSRecOpened)
        return E_SYS;

    #if (RECEIVE_FROM_UART2)
    if (uart2_open() == E_OK)
    {
        debug_msg("\r\nUART2: Open success\r\n");
        uart2_init(BaudRate, UART_LEN_L8_S1, UART_PARITY_NONE);
    }
    else
    {
        debug_err(("UART2: open fail!\r\n"));
        return E_SYS;
    }
    #endif

    debug_msg("Start GPS receive task\r\n");
    sta_tsk(GPSRECEIVE_ID,0);

    loc_cpu();
    bGPSRecOpened = TRUE;
    unl_cpu();

    return E_OK;
}

ER GPSRec_Close(void)
{

    if (!bGPSRecOpened)
        return E_SYS;

    #if (RECEIVE_FROM_UART2)
    if (uart2_close() == E_OK)
        debug_msg(("UART2: close success\r\n"));
    else
        debug_err(("UART2: close fail!\r\n"));
    #endif

    debug_msg("Terminate GPS receive task\r\n");

    ter_tsk(GPSRECEIVE_ID);

    loc_cpu();
    bGPSRecOpened = FALSE;
    unl_cpu();

    return E_OK;
}

void GPSRecTsk(void)
{
    CHAR      cLen;
    UINT16    CheckSentenceType1, CheckSentenceType2;
    UINT32    CheckSentenceType3;
    CHAR      RecSentence[NMEA_SENTENCE_SIZE];
    CHAR      *pSentenceData;
#if(UART_CONNECT_EDOG==ENABLE)
    static CHAR dataTemp;
    static UINT32 Step=0;
    UINT32 i;
    UINT32 Lat1,Lat2,Lat3;
    float LatTotal;
    UINT32 Long1,Long2,Long3;
    float LongTotal;
	
    static UINT32 DistanceTmp=1000;
    
#endif
    kent_tsk();

    clr_flg(FLG_ID_GPS, GPS_FLAG_DATAVALID);

    while(1)
    {
        cLen = NMEA_SENTENCE_SIZE ;
       #if (RECEIVE_FROM_UART2)
        if (uart2_getString(RecSentence, &cLen) == E_PAR)
        #else
        if (uart_getString(RecSentence, &cLen) == E_PAR)
        #endif
            debug_err(("UART2: parameter error!\r\n"));


        //debug_err(("%s\r\n",RecSentence));
        //Each NMEA sentence begins with '$' (0x24)
        if (RecSentence[0] == 0x24)
        {
            pSentenceData = RecSentence;
            CheckSentenceType1 = *(UINT16 *)(pSentenceData + 2);
            CheckSentenceType2 = *(UINT16 *)(pSentenceData + 4);
            CheckSentenceType3 = ((UINT)CheckSentenceType2 << 16) | (UINT)CheckSentenceType1;

            switch(CheckSentenceType3)
            {
            case ZCAM_SENTENCE:
                #if DEBUG_MSG
                debug_err(("^Y %s\r\n",RecSentence));
                #endif
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, CAM);
                break;

            case RMC_SENTENCE:
                NMEASentence.RMC = RecSentence;
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, RMC);
                break;
                #if 0
            case GSV_SENTENCE:
                NMEASentence.GSV = RecSentence;
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, GSV);
                break;
                #endif
                }
            }
#if 0//(UART_CONNECT_EDOG==ENABLE)
	  Step=0;
        uart2_getChar(RecSentence);

	  if(*RecSentence == EDOG_START_BYTE)
	  {
        	uart2_getChar(&dataTemp);				
		cLen=dataTemp;
		if(cLen<4)
		{
			Step=0;
		}
		else
		{
			RecSentence[1]=dataTemp;
			Step=1;
		}
	  }
	  if(Step==1)
	  {
	      //memset(Command_buf,0,sizeof(Command_buf));		  
		uart2_read(&RecSentence[2],cLen);
		
	      debug_msg("data: ");		
		for(i=0;i<cLen+2;i++)
		{
	      		debug_msg("%x ",RecSentence[i]);
		}
	      debug_msg("\r\n");
		
		if(RecSentence[cLen+1]==EDOG_STOP_BYTE)
		{		
			Step=2;
		}
		else
		{
			Step=0;
		}
	  }	  
	  if(Step==2)
	  {
		if(EdogRec_CheckSum(&RecSentence[1],cLen)==TRUE)
		{
			switch(RecSentence[2])
			{
				case 'G':
					//debug_msg("Edog command G...\r\n");
					EdogInfo.CommandG.SatStatus=RecSentence[3];
					EdogInfo.CommandG.WarningType=RecSentence[4];
					EdogInfo.CommandG.SpeedLimit=RecSentence[5];
					EdogInfo.CommandG.Distance1=RecSentence[6];
					EdogInfo.CommandG.Distance2=RecSentence[7];
					EdogInfo.CommandG.Speed=RecSentence[8];
					EdogInfo.CommandG.Direction=RecSentence[9];
					EdogInfo.CommandG.Latitude1=RecSentence[10];
					EdogInfo.CommandG.Latitude2=RecSentence[11];
					EdogInfo.CommandG.Latitude3=RecSentence[12];
					EdogInfo.CommandG.Longitude1=RecSentence[13];
					EdogInfo.CommandG.Longitude2=RecSentence[14];
					EdogInfo.CommandG.Longitude3=RecSentence[15];	
					if(EdogInfo.CommandG.SatStatus=='A')
					{
				            RMCInfo.Hour =      10;//(UINT32)UTCTime / 10000;
				            RMCInfo.Minute =    30;//((UINT32)UTCTime % 10000) / 100;
				            RMCInfo.Second =    30;//((UINT32)UTCTime % 100);
				            RMCInfo.Status =    EdogInfo.CommandG.SatStatus;
							
  					      Lat1= EdogInfo.CommandG.Latitude1;
  					      Lat2= EdogInfo.CommandG.Latitude2;
					      Lat3= EdogInfo.CommandG.Latitude3;	  
  					      LatTotal=(Lat3<<16)|(Lat2<<8)|(Lat1&0xff);						      	  
				            RMCInfo.Latitude =  LatTotal/10000;
				            RMCInfo.NSInd =     'N';
							
  					      Long1= EdogInfo.CommandG.Longitude1;
  					      Long2= EdogInfo.CommandG.Longitude2;
					      Long3= EdogInfo.CommandG.Longitude3;	  
  					      LongTotal=(Long3<<16)|(Long2<<8)|(Long1&0xff);								
				            RMCInfo.Longitude = Lon;
				            RMCInfo.EWInd =     'E';
							
				            RMCInfo.Speed =     EdogInfo.CommandG.Speed;
				            RMCInfo.Angle =     0;
				            RMCInfo.Day =       1;//Date / 10000;
				            RMCInfo.Month =     1;//(Date % 10000) / 100;
				            RMCInfo.Year =      15;//(Date % 100);					
					}
        	       		Ux_PostEvent(NVTEVT_EDOG_MESSAGE, 1,'G');							
				break;
				case 'R':
					//debug_msg("Edog command R...\r\n");	
					EdogInfo.CommandR.RadarBand=RecSentence[3];
					EdogInfo.CommandR.RadarFrequency1=RecSentence[4];
					EdogInfo.CommandR.RadarFrequency2=RecSentence[5];	

        	       		Ux_PostEvent(NVTEVT_EDOG_MESSAGE, 1,'R');		
									
				break;	
				case 'T':
					//debug_msg("Edog command T...\r\n");	
					EdogInfo.CommandT.Year=RecSentence[3];
					EdogInfo.CommandT.Month=RecSentence[4];
					EdogInfo.CommandT.Day=RecSentence[5];
					EdogInfo.CommandT.Hour=RecSentence[6];
					EdogInfo.CommandT.Minute=RecSentence[7];
					EdogInfo.CommandT.Second=RecSentence[8];
					EdogInfo.CommandT.Week=RecSentence[9];			
        	       		Ux_PostEvent(NVTEVT_EDOG_MESSAGE, 1,'T');		//gps info 					
				break;	
				case 'P':
					//debug_msg("Edog command P...\r\n");	
					
					EdogInfo.CommandP.DataVersion1=RecSentence[3];
					EdogInfo.CommandP.DataVersion2=RecSentence[4];
					EdogInfo.CommandP.FWVersion=RecSentence[5];
					EdogInfo.CommandP.Volume=RecSentence[6];
					EdogInfo.CommandP.RadarMuteSetting=RecSentence[7];
					EdogInfo.CommandP.DriveMode=RecSentence[8];
					EdogInfo.CommandP.RadarSensitivity=RecSentence[9];
					EdogInfo.CommandP.OverSpeedSetting=RecSentence[10];
					EdogInfo.CommandP.SpeedOffset=RecSentence[11];
					EdogInfo.CommandP.VoiceSetting=RecSentence[12];
		  
					Ux_PostEvent(NVTEVT_EDOG_MESSAGE, 1,'P');
				break;
				case 'C':
					//debug_msg("Edog command C...\r\n");	
					EdogInfo.CommandC.GPRSStatus=RecSentence[3];
        	       		Ux_PostEvent(NVTEVT_EDOG_MESSAGE, 1,'C');		//gps info 					
				break;				
				case 'E':
					//debug_msg("Edog command E...\r\n");	
					EdogInfo.EdogErrorType=RecSentence[3];
        	       		Ux_PostEvent(NVTEVT_EDOG_MESSAGE, 1,'E');		//gps info 					
				break;
				case 'U':
					//debug_msg("Edog command U...\r\n");	
					EdogInfo.EdogUdateType=RecSentence[3];
        	       		Ux_PostEvent(NVTEVT_EDOG_MESSAGE, 1,'U');		//gps info 					
				break;			
				
			}
		}		
	  }
	  
#elif 0
        #if (RECEIVE_FROM_UART2)
        if (uart2_getString(RecSentence, &cLen) == E_PAR)
        #else
        if (uart_getString(RecSentence, &cLen) == E_PAR)
        #endif
            debug_err(("UART2: parameter error!\r\n"));


        //debug_err(("%s\r\n",RecSentence));
        //Each NMEA sentence begins with '$' (0x24)
        if (RecSentence[0] == 0x24)
        {
            pSentenceData = RecSentence;
            CheckSentenceType1 = *(UINT16 *)(pSentenceData + 2);
            CheckSentenceType2 = *(UINT16 *)(pSentenceData + 4);
            CheckSentenceType3 = ((UINT)CheckSentenceType2 << 16) | (UINT)CheckSentenceType1;

            switch(CheckSentenceType3)
            {
            case GSA_SENTENCE:
                NMEASentence.GSA = RecSentence;
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, GSA);
                break;

            case RMC_SENTENCE:
                NMEASentence.RMC = RecSentence;
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, RMC);
                break;

            case GGA_SENTENCE:
                NMEASentence.GGA = RecSentence;
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, GGA);
                break;

            case GSV_SENTENCE:
                NMEASentence.GSV = RecSentence;
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, GSV);
                break;

            case GLL_SENTENCE:
                NMEASentence.GLL = RecSentence;
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, GLL);
                break;

            case VTG_SENTENCE:
                NMEASentence.VTG = RecSentence;
                GPSRec_NMEAParser(RecSentence, (UINT32)cLen, VTG);
                break;

            default:
                debug_err(("GPS: Can't identify this sentence 0x%X \r\n",CheckSentenceType3));
                break;
            }


        }

#endif


    }

}


ER GPSRec_Reset(void)
{
    clr_flg(FLG_ID_GPS, GPS_FLAG_DATAVALID);
    return E_OK;
}

BOOL GPSRec_CheckData(void)
{
    //debug_msg("GPS: DATA VALID: 0x%X\r\n",kchk_flg(FLG_ID_GPS, GPS_FLAG_DATAVALID));
    if (kchk_flg(FLG_ID_GPS, GPS_FLAG_DATAVALID))
        return TRUE;
    else
        return FALSE;

}


char ChangeSumData(CHAR KeyValue)
{
    char data = 0x0;
    switch(KeyValue)
        {
        case  '0':
            data = 0x0;
            break;
        case  '1':
            data = 0x1;
            break;
        case  '2':
            data = 0x2;
            break;
        case  '3':
            data = 0x3;
            break;
        case  '4':
            data = 0x4;
            break;
        case  '5':
            data = 0x5;
            break;
        case  '6':
            data = 0x6;
            break;
        case  '7':
            data = 0x7;
            break;
        case  '8':
            data = 0x8;
            break;
        case  '9':
            data = 0x9;
            break;
        case  'A':
            data = 0xa;
            break;
        case  'B':
            data = 0xb;
            break;
        case  'C':
            data = 0xc;
            break;
        case  'D':
            data = 0xd;
            break;
        case  'E':
            data = 0xe;
            break;
        case  'F':
            data = 0xf;
            break;
        }
    return data;
}

BOOL GPSRec_TransformData(CHAR *NMEA_str, UINT32 Len, CHAR *pPostPrt, UINT32 *PostPtrLen)
{
    UINT32 i;
    BOOL ret = FALSE;
    CHAR CeackSum = 0;
    CHAR CeackSum2 = 0;
    //Process sentence, change ',' as ' '.
    //If message is null, change to corresponding value.
    for (i = 0; i <= Len; i++)
    {
        *pPostPrt = *NMEA_str;
        if(*NMEA_str != '$'  && *NMEA_str != '*' )    
            CeackSum ^= *NMEA_str;
        if (*NMEA_str == ',')
        {
            *pPostPrt = 0x20;   //Instead of ' '
            if ((*(NMEA_str+1) == ',')|(*(NMEA_str+1) == '*'))
            {
                *++pPostPrt = 0x30;  //Insert '0'
                *PostPtrLen = *PostPtrLen + 1;
            }
        }
        else if ((*NMEA_str == '*')|(i == Len))
        {
            *pPostPrt = 0x20;   //Instead of ' '
            if(i != Len)
                {
            CeackSum2 = ((ChangeSumData(*(NMEA_str + 1)))<<4)|ChangeSumData(*(NMEA_str + 2)) ;
            #if DEBUG_MSG
            debug_msg("^Y  Cal GPS  CeackSum  0x%x : 0x%x \r\n",CeackSum , CeackSum2);
            #endif
            if(CeackSum != CeackSum2)
                {
                ret = TRUE;
                
                }
                }
        }

        NMEA_str++;
        pPostPrt++;

    }

    NMEA_str -= Len;
    pPostPrt -= *PostPtrLen;
    return ret;
}



BOOL GPSRec_TransformData2(CHAR *NMEA_str, UINT32 Len, CHAR *pPostPrt, UINT32 *PostPtrLen)
{
    UINT32 i;
    BOOL ret = FALSE;
    CHAR CeackSum = 0;
    CHAR CeackSum2 = 0;
    //CHAR CeackSum3 = 0;
    //CHAR CeackSum4 = 0;
    //Process sentence, change ',' as ' '.
    //If message is null, change to corresponding value.
    for (i = 0; i <= Len; i++)
    {
        *pPostPrt = *NMEA_str;
        if(*NMEA_str != '$'  && *NMEA_str != '*' )    
            CeackSum ^= *NMEA_str;
        //if(*NMEA_str != '$'  && *NMEA_str != '*' && *NMEA_str != ',' )    
        //    CeackSum2 ^= *NMEA_str;
        
        if (*NMEA_str == ',')
        {
            *pPostPrt = 0x20;   //Instead of ' '
            
        }
        else if ((*NMEA_str == '*')|(i == Len))
        {
            *pPostPrt = 0x20;   //Instead of ' '
            if(i != Len)
                {
            CeackSum2 = ((ChangeSumData(*(NMEA_str + 1)))<<4)|ChangeSumData(*(NMEA_str + 2)) ;
            #if DEBUG_MSG
            debug_msg("^Y  Cal  CAM CeackSum  0x%x : 0x%x \r\n",CeackSum , CeackSum2);
            #endif
            if(CeackSum != CeackSum2)
                {
                ret = TRUE;
                
                }
                }
        }
        

        NMEA_str++;
        pPostPrt++;

    }

    NMEA_str -= Len;
    pPostPrt -= *PostPtrLen;
    return ret;
}



BOOL GPSRec_CheckSum(CHAR *NMEA_str, UINT32 Len, UINT32 CheckSum)
{
    UINT32 i, LenTemp = 1;
    CHAR XORData;
    //#NT#2009/04/07#Photon Lin -begin
    //#Refine GPS firmware
    XORData = *(NMEA_str++);

    //Doing 8 bit exclusive OR of all characters between, but not including, the '$' and '*'.
    for (i = 1; i < Len; i++)
    {
        NMEA_str++;
        if (*NMEA_str == '*')
            break;

        LenTemp++;
        XORData ^= *NMEA_str;
    }
    //#NT#2009/04/07#Photon Lin -end
    NMEA_str -= LenTemp;
    if (XORData == (CHAR)CheckSum)
        return TRUE;
    else
    {
        debug_err(("GPS: check sum error! 0x%X != 0x%X\r\n",CheckSum, XORData));
        return FALSE;
    }


}



BOOL GPSRec_NMEAParser(CHAR *NMEA_str, UINT32 Len, NMEATYPE NMEAtype)
{
    BOOL data_ok = FALSE;
  UINT32 i;
int kind, limitspeed, distance, RD_band, HZ, Singallvl, RD_IS_Connect, DB_Version, FW_Version, RD_Speed, RD_volume, RD_City_Mode,GPS_SNR1,GPS_SNR2,GPS_SNR3,GPS_SNR4;
    pPostPrt = PostPtr;
    PostPtrLen = Len;

    if(NMEAtype == CAM)
    {
    #if DEBUG_MSG
        debug_msg("^R   Old  value  (len : %d) : %s\r\n",strlen(pPostPrt),pPostPrt);
    #endif
        memset(pPostPrt,0,strlen(pPostPrt));
        if(GPSRec_TransformData2(NMEA_str, Len, pPostPrt, &PostPtrLen))
            {
            debug_msg("^R   Cheack CAM Data  Fail\r\n");
            
            data_ok = TRUE;
            return data_ok;
            }
        #if DEBUG_MSG
        debug_msg("^G%s\r\n",pPostPrt);
        #endif
    }
    else
    {
        if(GPSRec_TransformData(NMEA_str, Len, pPostPrt, &PostPtrLen))
            {
            debug_msg("^R   Cheack GPS Data  Fail\r\n");
            
            data_ok = TRUE;
            return data_ok;
            }
        #if DEBUG_MSG
        debug_msg("^G%s\r\n",pPostPrt);
        #endif
    }
    switch(NMEAtype)
    {
    case GSA:
        
        sscanf(pPostPrt, "%s %c %d %d %d %d %d %d %d %d %d %d %d %d %d %lf %lf %lf %X\n", type, &SelMode, &FixMode, &SatUsed01, &SatUsed02, &SatUsed03, &SatUsed04, &SatUsed05, &SatUsed06, &SatUsed07, &SatUsed08, &SatUsed09, &SatUsed10, &SatUsed11, &SatUsed12, &PDOP, &HDOP, &VDOP, &CheckSum);
        #if (_GPS_CheckSum_Enable)
            GPSRec_CheckSum(NMEA_str, Len, CheckSum);
        #endif
        if (FixMode != No_Fix)
        {
            GSAInfo.SelMode = SelMode;
            GSAInfo.FixMode = FixMode;
            GSAInfo.SatUsed01 = SatUsed01;
            GSAInfo.SatUsed02 = SatUsed02;
            GSAInfo.SatUsed03 = SatUsed03;
            GSAInfo.SatUsed04 = SatUsed04;
            GSAInfo.SatUsed05 = SatUsed05;
            GSAInfo.SatUsed06 = SatUsed06;
            GSAInfo.SatUsed07 = SatUsed07;
            GSAInfo.SatUsed08 = SatUsed08;
            GSAInfo.SatUsed09 = SatUsed09;
            GSAInfo.SatUsed10 = SatUsed10;
            GSAInfo.SatUsed11 = SatUsed11;
            GSAInfo.SatUsed12 = SatUsed12;
            GSAInfo.PDOP = PDOP;
            GSAInfo.HDOP = HDOP;
            GSAInfo.VDOP = VDOP;
            GPS_debug(("#GSA SelMode = %c, FixMode = %d \r\n",GSAInfo.SelMode,GSAInfo.FixMode));
            GPS_debug(("#GSA SelMode = %c, FixMode = %d \r\n",GSAInfo.SelMode,GSAInfo.FixMode));
            GPS_debug(("#GSA SatUsed1 = %d, %d, %d, %d \r\n",GSAInfo.SatUsed01,GSAInfo.SatUsed02, GSAInfo.SatUsed03, GSAInfo.SatUsed04));
            GPS_debug(("#GSA SatUsed2 = %d, %d, %d, %d \r\n",GSAInfo.SatUsed05,GSAInfo.SatUsed06, GSAInfo.SatUsed07, GSAInfo.SatUsed08));
            GPS_debug(("#GSA SatUsed3 = %d, %d, %d, %d \r\n",GSAInfo.SatUsed09,GSAInfo.SatUsed10, GSAInfo.SatUsed11, GSAInfo.SatUsed12));
            GPS_debug(("#PDOP = %.1f, HDOP = %.1f, VDOP = %.1f CheckSum = %X\r\n",GSAInfo.PDOP,GSAInfo.HDOP, GSAInfo.VDOP,CheckSum));
        }
        if (Len)
        {
            for (i = 0; i < Len; i++)
                NMEA_debug(("%c",*NMEA_str++));
        }
        NMEA_debug(("\r\n"));

        //Check processed sentence
        /*
        if (PostPtrLen)
        {
            for (i = 0; i < PostPtrLen; i++)
                NMEA_debug(("%c",*pPostPrt++));
        }
        NMEA_debug(("\r\n"));
        */
        
        break;
    case CAM:
        //$XZCAM,0,0,58,0,0,6,1,530,100,0,5,0*75
        sscanf(pPostPrt, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", type, &kind, &limitspeed, &distance, &RD_band, &HZ, &Singallvl, &RD_IS_Connect, &DB_Version, &FW_Version, &RD_Speed, &RD_volume, &RD_City_Mode,&GPS_SNR1,&GPS_SNR2,&GPS_SNR3,&GPS_SNR4);
        //sscanf(pPostPrt, "%s %d %d %d %d %d %d %d %d %d %d %d %d \n", type, &kind, &limitspeed, &distance, &RD_band, &HZ, &Singallvl, &RD_IS_Connect, &DB_Version, &FW_Version, &RD_Speed, &RD_volume, &RD_City_Mode);
        #if DEBUG_MSG
        //debug_msg("^G date  : %s  kind:%d limitspeed:%d distance:%d RD_band:%d HZ:%d Singallvl:%d RD_IS_Connect:%d DB_Version:%d FW_Version:%d RD_Speed:%d RD_volume:%d RD_City_Mode:%d\r\n",type, kind, limitspeed, distance, RD_band, HZ, Singallvl, RD_IS_Connect, DB_Version, FW_Version, RD_Speed, RD_volume, RD_City_Mode);
        debug_msg("^Y %s  RD_Speed:%d RD_volume:%d RD_City_Mode:%d   GPS: %d:%d:%d:%d\r\n",type,  RD_Speed, RD_volume, RD_City_Mode,GPS_SNR1,GPS_SNR2,GPS_SNR3,GPS_SNR4);
        //debug_msg("^Y %s  RD_Speed:%d RD_volume:%d RD_City_Mode:%d   \r\n",type,  RD_Speed, RD_volume, RD_City_Mode);
        #endif
        RDInfo.kind = kind;
        RDInfo.limitspeed = limitspeed;
        RDInfo.distance = distance;
        RDInfo.RD_band = RD_band;
        RDInfo.HZ = HZ;
        RDInfo.Singallvl = Singallvl;
        RDInfo.RD_IS_Connect = RD_IS_Connect;
        RDInfo.DB_Version = DB_Version;
        RDInfo.FW_Version = FW_Version;
        RDInfo.RD_Speed = RD_Speed;
        RDInfo.RD_volume = RD_volume;
        RDInfo.RD_City_Mode = RD_City_Mode;
        
        RDInfo.GPS_SNR1= GPS_SNR1;
        RDInfo.GPS_SNR2 = GPS_SNR2;
        RDInfo.GPS_SNR3 = GPS_SNR3;
        RDInfo.GPS_SNR4 = GPS_SNR4;
        
        break;
    case RMC:
        sscanf(pPostPrt, "%s %lf %c %lf %c %lf %c %lf %lf %d %lf %c %X\n", type, &UTCTime, &Status, &Lat, &NSInd, &Lon, &EWInd, &Speed, &Angle, &Date, &MagVar, &MagVarInd, &CheckSum);
        #if DEBUG_MSG
        debug_err(("^R  UTCTime : %lf  speed : %04f   : %04f  Angle : %04f\r\n",UTCTime,Speed,Speed*1.852,Angle));
        //debug_msg("^Y RMC :%s %lf %c %lf %c %lf %c %lf %lf %d %lf %c %X \r\n", type, UTCTime, Status, Lat, NSInd, Lon, EWInd, Speed, Angle, Date, MagVar, MagVarInd, CheckSum);
        #endif
        #if (_GPS_CheckSum_Enable)
            GPSRec_CheckSum(NMEA_str, Len, CheckSum);
        #endif

            RMCInfo.Hour =      (UINT32)UTCTime / 10000;
            RMCInfo.Minute =    ((UINT32)UTCTime % 10000) / 100;
            RMCInfo.Second =    ((UINT32)UTCTime % 100);
            RMCInfo.Status =    Status;
            RMCInfo.Latitude =  Lat;
            RMCInfo.NSInd =     NSInd;
            RMCInfo.Longitude = Lon;
            RMCInfo.EWInd =     EWInd;
            RMCInfo.Speed =     Speed;
            RMCInfo.Angle =     Angle;
            RMCInfo.Day =       Date / 10000;
            RMCInfo.Month =     (Date % 10000) / 100;
            RMCInfo.Year =      (Date % 100)+2000;
            //debug_msg("^Y %d:%d:%d  \r\n",RMCInfo.Hour,RMCInfo.Minute,RMCInfo.Second);
        if (Status == 'A')   //Data valid
        {
            set_flg(FLG_ID_GPS, GPS_FLAG_DATAVALID);

            GPS_debug(("\x1b[34m"));   //Blue
            GPS_debug(("#RMC: Status = %c, Speed = %.1f, Angle = %.1f \r\n",RMCInfo.Status,RMCInfo.Speed,RMCInfo.Angle));
            GPS_debug(("#RMC: Date = %d\\%d\\%d CheckSum = %X\r\n",RMCInfo.Year,RMCInfo.Month,RMCInfo.Day,CheckSum));
            GPS_debug(("\x1b[30m"));   //Black
        }
        else if (Status == 'V')
        {
            clr_flg(FLG_ID_GPS, GPS_FLAG_DATAVALID);
        }
        NMEA_debug(("\x1b[34m"));   //Blue
        if (Len)
        {
            for (i = 0; i < Len; i++)
                NMEA_debug(("%c",*NMEA_str++));
        }
        NMEA_debug(("\r\n"));
        //Check processed sentence
        /*
        if (PostPtrLen)
        {
            for (i = 0; i < PostPtrLen; i++)
                NMEA_debug(("%c",*pPostPrt++));
        }
        NMEA_debug(("\r\n"));
        */
        NMEA_debug(("\x1b[30m"));   //Black

        break;

    case GGA:

        sscanf(pPostPrt, "%s %lf %lf %c %lf %c %d %d %lf %lf %c %lf %c %d %d %X\n", type, &UTCTime, &Lat, &NSInd, &Lon, &EWInd, &PosFixInd, &SatNumber, &HDOP, &Alt, &M1, &MSL, &M2, &Empty1, &Empty2, &CheckSum);
        #if (_GPS_CheckSum_Enable)
            GPSRec_CheckSum(NMEA_str, Len, CheckSum);
        #endif

        if (PosFixInd == 1)  //Data valid
        {
            GGAInfo.Hour = (UINT32)UTCTime / 10000;
            GGAInfo.Minute = ((UINT32)UTCTime % 10000) / 100;
            GGAInfo.Second = ((UINT32)UTCTime % 100);
            GGAInfo.Latitude = Lat;
            GGAInfo.NSInd = NSInd;
            GGAInfo.Longitude = Lon;
            GGAInfo.EWInd = EWInd;
            GGAInfo.PosFixInd = PosFixInd;
            GGAInfo.SatNumber = SatNumber;
            GGAInfo.HDOP = HDOP;
            GGAInfo.Altitude = Alt;
            GGAInfo.MSL = MSL;
            GPS_debug(("\x1b[31m"));   //Red
            GPS_debug(("#GGA: Time = %d:%d:%d CheckSum = %X\r\n", GGAInfo.Hour, GGAInfo.Minute, GGAInfo.Second,CheckSum));
            GPS_debug(("#GGA: Lat = %1f %c, Lon = %1f %c \r\n", GGAInfo.Latitude, NSInd, GGAInfo.Longitude, EWInd));
            GPS_debug(("#GGA: PosFixInd = %d, SatNum = %d, HDOP = %2.1f, Alt = %.1f, MSL = %.1f \r\n", GGAInfo.PosFixInd, GGAInfo.SatNumber, GGAInfo.HDOP, GGAInfo.Altitude, GGAInfo.MSL));
            GPS_debug(("\x1b[30m"));   //Black

        }

        NMEA_debug(("\x1b[31m"));   //Red
        if (Len)
        {
            for (i = 0; i < Len; i++)
                NMEA_debug(("%c",*NMEA_str++));
        }
        NMEA_debug(("\r\n"));

        //Check processed sentence
        /*
        if (PostPtrLen)
        {
            for (i = 0; i < PostPtrLen; i++)
                NMEA_debug(("%c",*pPostPrt++));
        }
        NMEA_debug(("\r\n"));
        */
        NMEA_debug(("\x1b[30m"));   //Black

        break;

    case GSV:
        sscanf(pPostPrt, "%s %d %d %d %s\n", type, &NumOfSen, &SenNum, &SatInView, RemainStr);
        //debug_msg("^G  GSV:  %s; %d ;%d ;%d ;%s",type, NumOfSen, SenNum, SatInView, RemainStr);
        if (NumOfSen == SenNum)
        {
            if ((SatInView % 4) == 1)
                sscanf(pPostPrt, "%s %d %d %d %d %d %d %d %X\n", type, &NumOfSen, &SenNum, &SatInView, &SatNum1, &Elev1, &Azi1, &SNR1, &CheckSum);
            else if ((SatInView % 4) == 2)
                sscanf(pPostPrt, "%s %d %d %d %d %d %d %d %d %d %d %d %X\n", type, &NumOfSen, &SenNum, &SatInView, &SatNum1, &Elev1, &Azi1, &SNR1, &SatNum2, &Elev2, &Azi2, &SNR2, &CheckSum);
            else if ((SatInView % 4) == 3)
                sscanf(pPostPrt, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %X\n", type, &NumOfSen, &SenNum, &SatInView, &SatNum1, &Elev1, &Azi1, &SNR1, &SatNum2, &Elev2, &Azi2, &SNR2, &SatNum3, &Elev3, &Azi3, &SNR3, &CheckSum);
            else
                sscanf(pPostPrt, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %X\n", type, &NumOfSen, &SenNum, &SatInView, &SatNum1, &Elev1, &Azi1, &SNR1, &SatNum2, &Elev2, &Azi2, &SNR2, &SatNum3, &Elev3, &Azi3, &SNR3, &SatNum4, &Elev4, &Azi4, &SNR4, &CheckSum);
        }
        else
            sscanf(pPostPrt, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %X\n", type, &NumOfSen, &SenNum, &SatInView, &SatNum1, &Elev1, &Azi1, &SNR1, &SatNum2, &Elev2, &Azi2, &SNR2, &SatNum3, &Elev3, &Azi3, &SNR3, &SatNum4, &Elev4, &Azi4, &SNR4, &CheckSum);

        #if (_GPS_CheckSum_Enable)
            GPSRec_CheckSum(NMEA_str, Len, CheckSum);
        #endif

        if (SenNum == 1)   //GSV1
        {
            GSVInfo.NumOfSen =     NumOfSen;
            GSVInfo.SatInView =    SatInView;
            GSVInfo.SAT01.SatNum = SatNum1;
            GSVInfo.SAT01.Elev =   Elev1;
            GSVInfo.SAT01.Azi =    Azi1;
            GSVInfo.SAT01.SNR =    SNR1;
            GSVInfo.SAT02.SatNum = SatNum2;
            GSVInfo.SAT02.Elev =   Elev2;
            GSVInfo.SAT02.Azi =    Azi2;
            GSVInfo.SAT02.SNR =    SNR2;
            GSVInfo.SAT03.SatNum = SatNum3;
            GSVInfo.SAT03.Elev =   Elev3;
            GSVInfo.SAT03.Azi =    Azi3;
            GSVInfo.SAT03.SNR =    SNR3;
            GSVInfo.SAT04.SatNum = SatNum4;
            GSVInfo.SAT04.Elev =   Elev4;
            GSVInfo.SAT04.Azi =    Azi4;
            GSVInfo.SAT04.SNR =    SNR4;
            GPS_debug(("\x1b[35m"));   //Violet
            GPS_debug(("#GSV%d SatInView = %d, CheckSum = %X\r\n",SenNum, SatInView, CheckSum));
            GPS_debug(("#GSV%d Sat1 = %d, %d, %d, %d, Sat2 = %d, %d, %d, %d\r\n",SenNum, SatNum1, Elev1, Azi1, SNR1, SatNum2, Elev2, Azi2, SNR2));
            GPS_debug(("#GSV%d Sat3 = %d, %d, %d, %d, Sat4 = %d, %d, %d, %d\r\n",SenNum, SatNum3, Elev3, Azi3, SNR3, SatNum4, Elev4, Azi4, SNR4));
            GPS_debug(("\x1b[30m"));      //Black

        }
        else if (SenNum == 2)   //GSV2
        {
            GSVInfo.NumOfSen =     NumOfSen;
            GSVInfo.SatInView =    SatInView;
            GSVInfo.SAT05.SatNum = SatNum1;
            GSVInfo.SAT05.Elev =   Elev1;
            GSVInfo.SAT05.Azi =    Azi1;
            GSVInfo.SAT05.SNR =    SNR1;
            GSVInfo.SAT06.SatNum = SatNum2;
            GSVInfo.SAT06.Elev =   Elev2;
            GSVInfo.SAT06.Azi =    Azi2;
            GSVInfo.SAT06.SNR =    SNR2;
            GSVInfo.SAT07.SatNum = SatNum3;
            GSVInfo.SAT07.Elev =   Elev3;
            GSVInfo.SAT07.Azi =    Azi3;
            GSVInfo.SAT07.SNR =    SNR3;
            GSVInfo.SAT08.SatNum = SatNum4;
            GSVInfo.SAT08.Elev =   Elev4;
            GSVInfo.SAT08.Azi =    Azi4;
            GSVInfo.SAT08.SNR =    SNR4;
            GPS_debug(("\x1b[35m"));   //Violet
            GPS_debug(("#GSV%d SatInView = %d, CheckSum = %X\r\n",SenNum, SatInView, CheckSum));
            GPS_debug(("#GSV%d Sat5 = %d, %d, %d, %d, Sat6 = %d, %d, %d, %d\r\n",SenNum, SatNum1, Elev1, Azi1, SNR1, SatNum2, Elev2, Azi2, SNR2));
            GPS_debug(("#GSV%d Sat7 = %d, %d, %d, %d, Sat8 = %d, %d, %d, %d\r\n",SenNum, SatNum3, Elev3, Azi3, SNR3, SatNum4, Elev4, Azi4, SNR4));
            GPS_debug(("\x1b[30m"));      //Black

        }
        else if (SenNum == 3)   //GSV3
        {
            GSVInfo.NumOfSen =     NumOfSen;
            GSVInfo.SatInView =    SatInView;
            GSVInfo.SAT09.SatNum = SatNum1;
            GSVInfo.SAT09.Elev =   Elev1;
            GSVInfo.SAT09.Azi =    Azi1;
            GSVInfo.SAT09.SNR =    SNR1;
            GSVInfo.SAT10.SatNum = SatNum2;
            GSVInfo.SAT10.Elev =   Elev2;
            GSVInfo.SAT10.Azi =    Azi2;
            GSVInfo.SAT10.SNR =    SNR2;
            GSVInfo.SAT11.SatNum = SatNum3;
            GSVInfo.SAT11.Elev =   Elev3;
            GSVInfo.SAT11.Azi =    Azi3;
            GSVInfo.SAT11.SNR =    SNR3;
            GSVInfo.SAT12.SatNum = SatNum4;
            GSVInfo.SAT12.Elev =   Elev4;
            GSVInfo.SAT12.Azi =    Azi4;
            GSVInfo.SAT12.SNR =    SNR4;
            GPS_debug(("\x1b[35m"));   //Violet
            GPS_debug(("#GSV%d SatInView = %d, CheckSum = %X\r\n",SenNum, SatInView, CheckSum));
            GPS_debug(("#GSV%d Sat9 = %d, %d, %d, %d,  Sat10 = %d, %d, %d, %d\r\n",SenNum, SatNum1, Elev1, Azi1, SNR1, SatNum2, Elev2, Azi2, SNR2));
            GPS_debug(("#GSV%d Sat11 = %d, %d, %d, %d, Sat12 = %d, %d, %d, %d\r\n",SenNum, SatNum3, Elev3, Azi3, SNR3, SatNum4, Elev4, Azi4, SNR4));
            GPS_debug(("\x1b[30m"));      //Black

        }
        else
            debug_err(("GPS: Invalid number of GSV"));


        NMEA_debug(("\x1b[35m"));   //Violet
        if (Len)
        {
            for (i = 0; i < Len; i++)
                NMEA_debug(("%c",*NMEA_str++));
        }
        NMEA_debug(("\r\n"));
        //Check processed sentence
        /*
        if (PostPtrLen)
        {
            for (i = 0; i < PostPtrLen; i++)
                NMEA_debug(("%c",*pPostPrt++));
        }
        NMEA_debug(("\r\n"));
        */
        NMEA_debug(("\x1b[30m"));      //Black
        break;
    //Do not support GLL and VTG yet
    case GLL:

        NMEA_debug(("\x1b[36m"));   //Blue
        if (Len)
        {
            for (i = 0; i < Len; i++)
                NMEA_debug(("%c",*NMEA_str++));
        }
        NMEA_debug(("\r\n"));
        NMEA_debug(("\x1b[30m"));   //Black


        break;

    case VTG:

        NMEA_debug(("\x1b[32m"));   //Green
        if (Len)
        {
            for (i = 0; i < Len; i++)
                NMEA_debug(("%c",*NMEA_str++));
        }
        NMEA_debug(("\r\n"));
        NMEA_debug(("\x1b[30m"));   //Black

        break;

    default:

        break;
    }

    return data_ok;



}

BOOL GPSRec_GetRMCDate(RMCINFO *pRMCInfo)
{
    memcpy(pRMCInfo,&RMCInfo,sizeof(RMCINFO));
    if (RMCInfo.Status == 'A')  //Data valid
    {
        return TRUE;
    }
    else
        return FALSE;
}

BOOL GPSRec_GetUTCDate(UINT32 *Year, UINT32 *Month, UINT32 *Day)
{
    if (RMCInfo.Status == 'A')  //Data valid
    {
        *Year   = RMCInfo.Year;
        *Month  = RMCInfo.Month;
        *Day    = RMCInfo.Day;
        return TRUE;
    }
    else
        return FALSE;

}

BOOL GPSRec_GetUTCTime(UINT32 *Hour, UINT32 *Minute, UINT32 *Second)
{
    if (RMCInfo.Status == 'A')   //Data valid
    {
        *Hour   = RMCInfo.Hour;
        *Minute = RMCInfo.Minute;
        *Second = RMCInfo.Second;
        return TRUE;
    }
    else
        return FALSE;

}

void EdgoRec_GetEdogInfo(EDOG_INFO *pEdogInfo)
{
    memcpy(pEdogInfo,&EdogInfo,sizeof(EDOG_INFO));
}

BOOL EdogRec_CheckSum(CHAR *NMEA_str, UINT32 Len)
{
    UINT32 i;
    UINT32 checkSum=0;

    for (i = 0; i < Len-1; i++)
    {    
        checkSum += *NMEA_str;				
        NMEA_str++;		
    }
    checkSum&=0x00FF;
    checkSum^=0x8A;
	
    if (checkSum == *NMEA_str){
        return TRUE;
    }
    else
    {
        debug_err(("GPS: check sum error! 0x%X != 0x%X\r\n",*NMEA_str, checkSum));
        return FALSE;
    }

}

void EdgoRec_PutKeyCommand(UINT32 KeyIndex,UINT32 KeyValue)
{
#if 0
	UINT32 i = 0;
       UINT8 data[7]={0};	 
       UINT32 checkSum=0;
	   	
	data[0] = EDOG_START_BYTE;
	data[1] = 0x05;
	data[2] = 'K';
	data[3] = KeyIndex;
	data[4] =KeyValue;
      checkSum =(data[1]+data[2]+data[3]+data[4]);		
      checkSum&=0x00FF;
      checkSum^=0x8A;
	
	data[5] = checkSum;
	data[6] = EDOG_STOP_BYTE;
	
	for(i=0;i<7;i++)
	{
		uart2_putChar(data[i]);
		debug_msg("0x%02x ",data[i]);
	}
      debug_err(("\r\n"));
      #endif
}

void EdgoRec_PutDemandCommand(CHAR Command)
{
#if 0
	UINT32 i = 0;
       UINT8 data[5]={0};	 
       UINT32 checkSum=0;
	   	
	data[0] = EDOG_START_BYTE;
	data[1] = 0x03;
	data[2] = Command;
      checkSum =(data[1]+data[2]);		
      checkSum&=0x00FF;
      checkSum^=0x8A;
	
	data[3] = checkSum;
	data[4] = EDOG_STOP_BYTE;
	
	for(i=0;i<5;i++)
	{
		uart2_putChar(data[i]);
		debug_msg("0x%02x ",data[i]);
	}
      debug_err(("\r\n"));
      #endif
}


UINT32 GetGPSSingalLvl(GSVINFO *GSVDesInfo)
{
    memcpy(GSVDesInfo,&GSVInfo,sizeof(GSVINFO));
}


void GetRDInfo(RDINFO *pEdogInfo)
{
    memcpy(pEdogInfo,&RDInfo,sizeof(RDINFO));
}

char ChangeValue(int KeyValue)
{
    char data = 0x0;
    switch(KeyValue)
        {
        case  0:
            data = 0x0;
            break;
        case  1:
            data = 0x1;
            break;
        case  2:
            data = 0x2;
            break;
        case  3:
            data = 0x3;
            break;
        case  4:
            data = 0x4;
            break;
        case  5:
            data = 0x5;
            break;
        case  6:
            data = 0x6;
            break;
        case  7:
            data = 0x7;
            break;
        case  8:
            data = 0x8;
            break;
        case  9:
            data = 0x9;
            break;
        case  10:
            data = 0xa;
            break;
        case  11:
            data = 0xb;
            break;
        case  12:
            data = 0xc;
            break;
        case  13:
            data = 0xd;
            break;
        case  14:
            data = 0xe;
            break;
        case  15:
            data = 0xf;
            break;
        }
    return data;
}

void RD_PutCommand(UINT32 KeyIndex,int KeyValue)
{

	UINT32 i = 0;
       char data[4]={0};	 
	data[0] = RD_START_BYTE;
	data[1] = KeyIndex;
	data[2] = ChangeValue(KeyValue)+0x50;
	data[3] = RD_STOP_BYTE;
	
	
	for(i=0;i<4;i++)
	{
		uart2_putChar(data[i]);
		debug_msg("0x%02x ",data[i]);
	}
      debug_msg(("\r\n"));

}


void RD_PutXZMUICommand(int* DataValue)
{

	UINT32 i = 0;
       char data[8]={0};	 
       /*
       debug_msg("XZMUI:");
        for(i=0;i<12;i++)
	{
		
		debug_msg("^R 0x%02x ",DataValue[i]);
	}
        debug_msg(("\r\n"));
        */
	data[0] = RD_START_BYTE;
	data[1] = (ChangeValue(*(DataValue))<<4)|ChangeValue(*(DataValue+1));
        data[2] = (ChangeValue(*(DataValue+2))<<3)|ChangeValue(*(DataValue+3)<<2)|ChangeValue(*(DataValue+4)<<1)|ChangeValue(*(DataValue+5))|0x50;
        data[3] = (ChangeValue(*(DataValue+6))<<4)|ChangeValue(*(DataValue+7));
        data[4] = (ChangeValue(*(DataValue+8))<<4)|ChangeValue(*(DataValue+9));
        data[5] = 0x55;
        data[6] = data[1]^data[2]^data[3]^data[4]^data[5];//data[6] = 0x68;
	data[7] = RD_STOP_BYTE;
	
	//debug_msg("XZMUI:");
	for(i=0;i<8;i++)
	{
		uart2_putChar(data[i]);
		//debug_msg("^Y 0x%02x ",data[i]);
	}
      //debug_msg(("\r\n"));

}

