/**
    Copyright   Novatek Microelectronics Corp. 2007.  All rights reserved.

    @file       BuildDateInfo.c
    @ingroup    mIPRJAPCfg

    @brief      Project source build time information
                Project source build time information

    @note       The project source build time info will be updated every time you build the image.

    @date       2007/11/06
*/

/** \addtogroup mIPRJAPCfg*/
//@{

#include <stdio.h>
#include "ProjectInfo.h"
#include "Type.h"
#include "PrjCfg.h"
#include <string.h>

//-----------------------------------------------------------------------------
// FW info
//-----------------------------------------------------------------------------
//FW updtae FW need access external fw version via versioninfo.s offset 0x000000A8
//char gFWExternalVersion[33]="PW84.TVP5150.2015.03.12";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="PW84.TVP5150.2015.03.23";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="PW8402.2015.06.11";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.07.30";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.08.14";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.08.24";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.08.26";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.08.31";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.09.02";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.09.06";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.09.09";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.09.10";//FW_VERSION_NUM;
//char gFWExternalVersion[33]="A5.2015.09.11";//FW_VERSION_NUM; 
//char gFWExternalVersion[33]="A5.2015.09.14";//FW_VERSION_NUM; 
//char gFWExternalVersion[33]="A5.2015.09.24";//FW_VERSION_NUM; 
//char gFWExternalVersion[33]="A5.2015.09.28";//FW_VERSION_NUM; 
//char gFWExternalVersion[33]="A5.2015.10.08";//FW_VERSION_NUM; 
//char gFWExternalVersion[33]="A5.2015.1106.V0.1";//FW_VERSION_NUM; 
char gFWExternalVersion[33]="A5.2015.1109.V0.3";//FW_VERSION_NUM; 

char* Prj_GetVersionString()
{
    return gFWExternalVersion;
}


//-----------------------------------------------------------------------------
// User define info
//-----------------------------------------------------------------------------
static char gVersion[9];
static char gModelName[9];
static char gReleaseDate[9];
//extern UINT32 ProjectCode;
//extern UINT32 VersionNumber;
//extern UINT32 ReleaseDate;

//Please modify VersionInfo.s :: ProjectCode
char* Prj_GetModelInfo()
{
    //strncpy(gModelName, (char *)&ProjectCode, 9);
    gModelName[8] = 0;
    return gModelName;
}

//Please modify VersionInfo.s :: VersionNumber
char* Prj_GetVerInfo()
{
    //strncpy(gVersion, (char *)&VersionNumber, 9);
    gVersion[8] = 0;
    return gVersion;
}

//Please modify VersionInfo.s :: ReleaseDate
char* Prj_GetReleaseDate()
{
    //strncpy(gReleaseDate, (char *)&ReleaseDate, 9);
    gReleaseDate[8] = 0;
    return gReleaseDate;
}


//-----------------------------------------------------------------------------
// Compiler-time info
//-----------------------------------------------------------------------------
#include "ProjectInfo.cfg"

// C standard format: Mmm dd yyyy HH:MM:SS (ex. Nov 06 2007 11:15:11)
static CHAR gPrjBuildDateStd[] = __DATE__ ", " __TIME__;

// User defined format: yyyy/mm/dd HH:MM:SS (ex. 2007/11/06 11:15:11)
static CHAR gPrjBuildDateUser[32];

// Retrieve year info
#define OS_YEAR     ((((__DATE__ [7] - '0') * 10 + (__DATE__ [8] - '0')) * 10 \
                        + (__DATE__ [9] - '0')) * 10 + (__DATE__ [10] - '0'))

// Retrieve month info
#define OS_MONTH    (__DATE__ [2] == 'n' ? (__DATE__ [1] == 'a' ? 1 : 6) \
                        : __DATE__ [2] == 'b' ? 2 \
                        : __DATE__ [2] == 'r' ? (__DATE__ [0] == 'M' ? 3 : 4) \
                        : __DATE__ [2] == 'y' ? 5 \
                        : __DATE__ [2] == 'l' ? 7 \
                        : __DATE__ [2] == 'g' ? 8 \
                        : __DATE__ [2] == 'p' ? 9 \
                        : __DATE__ [2] == 't' ? 10 \
                        : __DATE__ [2] == 'v' ? 11 : 12)

// Retrieve day info
#define OS_DAY      ((__DATE__ [4] == ' ' ? 0 : __DATE__ [4] - '0') * 10 \
                        + (__DATE__ [5] - '0'))

// Retrieve hour info
#define OS_HOUR     ((__TIME__ [0] - '0') * 10 + (__TIME__ [1] - '0'))

// Retrieve minute info
#define OS_MINUTE   ((__TIME__ [3] - '0') * 10 + (__TIME__ [4] - '0'))

// Retrieve second info
#define OS_SECOND   ((__TIME__ [6] - '0') * 10 + (__TIME__ [7] - '0'))




//-----------------------------------------------------------------------------
// Project build time info, C standard (US) format
//-----------------------------------------------------------------------------
char* Prj_GetBuildDateStd(void)
{
    return gPrjBuildDateStd;
}

//-----------------------------------------------------------------------------
// Project build time info, user defined format
//-----------------------------------------------------------------------------
char* Prj_GetBuildDateUser(void)
{
    sprintf(gPrjBuildDateUser, "%d/%02d/%02d, %s", OS_YEAR, OS_MONTH, OS_DAY, __TIME__);
    return gPrjBuildDateUser;
}

char* Prj_GetCheckinDate(void)
{
    return gPrjCheckInDate;
}




//@}