

#include "Type.h"
#include "i2c.h"
#include "TouchPanel.h"

#define __MODULE__          TouchPanel
//#define __DBGLVL__ 0        //OFF mode, show nothing
//#define __DBGLVL__ 1        //ERROR mode, show err, wrn only
#define __DBGLVL__ 1        //TRACE mode, show err, wrn, ind, msg and func and ind, msg and func can be filtering by __DBGFLT__ settings
#define __DBGFLT__ "*"      //*=All
#include "DebugModule.h"

static TouchPanel_INFO g_TouchPanelInfo;

static I2C_STS TouchPanel_I2C_Receive(UINT32 *value, BOOL bNACK, BOOL bStop)
{
    I2C_DATA I2cData;
    I2C_STS ret;

    I2cData.VersionInfo = DRV_VER_96650;
    I2cData.ByteCount = I2C_BYTE_CNT_1;
    I2cData.Byte[0].Param = I2C_BYTE_PARAM_NONE;
    if ( bNACK == TRUE )
        I2cData.Byte[0].Param |= I2C_BYTE_PARAM_NACK;
    if ( bStop == TRUE )
        I2cData.Byte[0].Param |= I2C_BYTE_PARAM_STOP;

    ret = i2c_receive(&I2cData);
    if ( ret != I2C_STS_OK )
    {
        DBG_ERR("i2c ret = %02x!!\r\n", ret);
    }

    *value = I2cData.Byte[0].uiValue;

    return ret;
}

static I2C_STS TouchPanel_I2C_Transmit(UINT32 value, BOOL bStart, BOOL bStop)
{
    I2C_DATA I2cData;
    I2C_STS ret;

    I2cData.VersionInfo = DRV_VER_96650;
    I2cData.ByteCount = I2C_BYTE_CNT_1;
    I2cData.Byte[0].uiValue = value & 0xff;
    I2cData.Byte[0].Param = I2C_BYTE_PARAM_NONE;
    if ( bStart == TRUE )
        I2cData.Byte[0].Param |= I2C_BYTE_PARAM_START;
    if ( bStop == TRUE )
        I2cData.Byte[0].Param |= I2C_BYTE_PARAM_STOP;
    ret = i2c_transmit(&I2cData);
    if ( ret != I2C_STS_OK )
    {
            DBG_ERR("i2c ret = %d!!\r\n", ret);
    }
    return ret;
}

/**
  Initialize TouchPanel IIC bus

  Initialize TouchPanel IIC bus

  @param void
  @return void
*/
BOOL TouchPanel_I2C_Init(TouchPanel_INFO TouchPanelInfo)
{
    UINT erReturn;

    g_TouchPanelInfo.I2C_RegBytes = TouchPanelInfo.I2C_RegBytes;
    g_TouchPanelInfo.I2C_PinMux = TouchPanelInfo.I2C_PinMux;
    g_TouchPanelInfo.I2C_BusClock = TouchPanelInfo.I2C_BusClock;
    g_TouchPanelInfo.I2C_Slave_WAddr = TouchPanelInfo.I2C_Slave_WAddr;
    g_TouchPanelInfo.I2C_Slave_RAddr = TouchPanelInfo.I2C_Slave_RAddr;

    if (g_TouchPanelInfo.I2C_RegBytes > TouchPanel_I2C_REGISTER_2BYTE)
    {
        debug_msg("Error register Byte Count !!\r\n");
        return FALSE;
    }

    if (g_TouchPanelInfo.I2C_PinMux > I2C_PINMUX_2ND)
    {
        debug_msg("Error I2C Pin mux !!\r\n");
        return FALSE;
    }

    if (g_TouchPanelInfo.I2C_BusClock > I2C_BUS_CLOCK_1MHZ)
    {
        debug_msg("Error I2C Bus Clock !!\r\n");
        return FALSE;
    }

    erReturn = i2c_open(&(g_TouchPanelInfo.I2C_Channel));
    if(erReturn != I2C_STS_OK)
    {
        debug_err(("Error open I2C driver!!\r\n"));
        return FALSE;
    }

    i2c_setConfig(g_TouchPanelInfo.I2C_Channel, I2C_CONFIG_ID_PINMUX, g_TouchPanelInfo.I2C_PinMux); //select to control I2C 1st device
    i2c_setConfig(g_TouchPanelInfo.I2C_Channel, I2C_CONFIG_ID_BUSCLOCK, g_TouchPanelInfo.I2C_BusClock); //up to 400KHZ

    return TRUE;
}


void TouchPanel_I2C_WriteReg(UINT32 uiAddr, UINT32 uiValue)
{
    UINT        erReturn;
    UINT32      ulWriteAddr, ulReg1, ulData;
    UINT32      ulReg2 = 0;

    i2c_lock(g_TouchPanelInfo.I2C_Channel);

    ulWriteAddr = g_TouchPanelInfo.I2C_Slave_WAddr;
    if (g_TouchPanelInfo.I2C_RegBytes == TouchPanel_I2C_REGISTER_2BYTE)
    {
        ulReg1      = (uiAddr>>8);
        ulReg2      = ((uiAddr)&(0x000000ff));
    } else {
        ulReg1      = ((uiAddr)&(0x000000ff));
    }
    ulData      = ((uiValue)&(0x000000ff));
    do
    {
        erReturn=TouchPanel_I2C_Transmit(ulWriteAddr, 1, 0);
        if (erReturn != I2C_STS_OK)
        {
            debug_err(("TP Error transmit data (write addr)!!\r\n"));
            break;
        }

        erReturn=TouchPanel_I2C_Transmit(ulReg1, 0, 0);
        if (erReturn != I2C_STS_OK)
        {
            debug_err(("TP Error transmit data (reg) !!\r\n"));
            break;
        }

        if (g_TouchPanelInfo.I2C_RegBytes == TouchPanel_I2C_REGISTER_2BYTE)
        {
            erReturn=TouchPanel_I2C_Transmit(ulReg2, 0, 0);
            if (erReturn != I2C_STS_OK)
            {
                debug_err(("TP Error transmit data (reg) !!\r\n"));
                break;
            }
        }

        erReturn=TouchPanel_I2C_Transmit(ulData, 0, 1);
        if (erReturn != I2C_STS_OK)
        {
            debug_err(("TP Error transmit data (data1) !!\r\n"));
            break;
        }
    } while(erReturn != I2C_STS_OK);

    i2c_unlock(g_TouchPanelInfo.I2C_Channel);
}	


UINT32 TouchPanel_I2C_ReadReg(UINT32 uiAddr)
{
  UINT32      ulWriteAddr, ulReadAddr, ulReg1;
  UINT32 	  ulReg2=0;
  static UINT32 ulData1;


    ulWriteAddr =g_TouchPanelInfo.I2C_Slave_WAddr;
    ulReadAddr  =g_TouchPanelInfo.I2C_Slave_RAddr;
    ulReg1      =(uiAddr&0x000000ff);
    ulData1     = 0;

    if (g_TouchPanelInfo.I2C_RegBytes == TouchPanel_I2C_REGISTER_2BYTE)
    {
        ulReg1      = (uiAddr>>8);
        ulReg2      = ((uiAddr)&(0x000000ff));
    } else {
        ulReg1      = ((uiAddr)&(0x000000ff));
    }
	
    if(i2c_lock(g_TouchPanelInfo.I2C_Channel) != E_OK)
    {
        debug_err(("TouchPanel: readReg I2C Lock Fail\r\n"));
        return ulData1;
    }

    if (TouchPanel_I2C_Transmit(ulWriteAddr, 1, 0) != I2C_STS_OK)
    {
        debug_err(("Error transmit data1!!\r\n"));
        i2c_unlock(g_TouchPanelInfo.I2C_Channel);
        return  ulData1;
    }

    if (TouchPanel_I2C_Transmit(ulReg1, 0, 0) != I2C_STS_OK)
    {
        debug_err(("Error transmit data2!!\r\n"));
        i2c_unlock(g_TouchPanelInfo.I2C_Channel);
        return  ulData1;
    }
	
    if (g_TouchPanelInfo.I2C_RegBytes == TouchPanel_I2C_REGISTER_2BYTE)
    {
	    if (TouchPanel_I2C_Transmit(ulReg2, 0, 0) != I2C_STS_OK)
	    {
	        debug_err(("Error transmit data2!!\r\n"));
	        i2c_unlock(g_TouchPanelInfo.I2C_Channel);
	        return  ulData1;
	    }
    }
    if (TouchPanel_I2C_Transmit(ulReadAddr, 1, 0) != I2C_STS_OK)
    {
        debug_err(("Error transmit data3!!\r\n"));
        i2c_unlock(g_TouchPanelInfo.I2C_Channel);
        return  ulData1;
    }

    if (TouchPanel_I2C_Receive(&ulData1, 1, 1) != I2C_STS_OK)
    {
        debug_err(("Error Receive data!!\r\n"));
        i2c_unlock(g_TouchPanelInfo.I2C_Channel);
        return  ulData1;
    }

    if(i2c_unlock(g_TouchPanelInfo.I2C_Channel) != E_OK)
    {
        debug_err(("TouchPanel: readReg I2C UnLock Fail\r\n"));
        return  ulData1;
    }

    return  ulData1;
}
