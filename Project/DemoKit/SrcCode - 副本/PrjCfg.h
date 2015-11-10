/**
    Copyright   Novatek Microelectronics Corp. 2009.  All rights reserved.

    @file       PrjCfg.h
    @ingroup

    @brief

    @note       Nothing.
*/

#ifndef _PRJCFG_H_
#define _PRJCFG_H_

#include "Type.h"
#include "debug.h"

#include "PrjCfg_Comm.h"
#if (_MODEL_DSC_ == _MODEL_DEMO1_)
#include "PrjCfg_Demo.h"
#elif (_MODEL_DSC_ == _MODEL_EVB_)
#include "PrjCfg_EVB.h"
#elif (_MODEL_DSC_ == _MODEL_CARDV_)
#include "PrjCfg_CARDV.h"
#elif (_MODEL_DSC_ == _MODEL_PW8402_)
#include "PrjCfg_PW8402.h"
#else //Unknown MODEL
#warning Unknown MODEL?
#warning Please assign your "MODEL" in include "ModelConfig.txt"
#error (see above)
#endif

#endif //_PRJCFG_H_
