
#ifndef __TouchPanel_H
#define __TouchPanel_H

#include "i2c.h"

typedef enum
{
    TouchPanel_I2C_REGISTER_1BYTE = 1,
    TouchPanel_I2C_REGISTER_2BYTE = 2,
    ENUM_DUMMY4WORD(TouchPanel_I2C_REGISTER_BYTES)
} TouchPanel_I2C_REGISTER_BYTES, *PTouchPanel_I2C_REGISTER_BYTES;


typedef struct
{
    I2C_SECTION I2C_Channel;
    TouchPanel_I2C_REGISTER_BYTES  I2C_RegBytes;
    I2C_PINMUX      I2C_PinMux;
    I2C_BUS_CLOCK   I2C_BusClock;
    UINT32          I2C_Slave_WAddr;
    UINT32          I2C_Slave_RAddr;
} TouchPanel_INFO,*PTouchPanel_INFO;


extern BOOL   TouchPanel_open(void);
extern BOOL   TouchPanel_close(void);
extern BOOL   TouchPanel_Init(void);
extern BOOL   TouchPanel_IsInitOK(void);


extern BOOL TouchPanel_I2C_Init(TouchPanel_INFO TouchPanelInfo);
extern void TouchPanel_I2C_WriteReg(UINT32 uiAddr, UINT32 uiValue);
extern UINT32 TouchPanel_I2C_ReadReg(UINT32 uiAddr);


#endif  //__TouchPanel_H
