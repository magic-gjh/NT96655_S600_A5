#include "TouchPanel.h"
#include "TouchPanel_GT9XX.h"
#include "SwTimer.h"
#include "Debug.h"
#include <stdlib.h>

static BOOL TouchPanelInitOK=FALSE;

BOOL TouchPanel_Init(void)
{
    UINT32 value;
    UINT32 i;
    UINT32 j=0;	
    UINT32 check_sum;
/*	
   j=0;
   for(i=REG_START;i<=REG_END;i++){   	
    //debug_msg("TP write[0x%x] = 0x%x\r\n",i,GT9XX_Init_Config[j]);   	
    TouchPanel_I2C_WriteReg(i,GT9XX_Init_Config[j]);
    check_sum+=GT9XX_Init_Config[j];
    j++;
   }
   */
    debug_msg("check_sum: 0x%x\r\n",check_sum);   	
    //TouchPanel_I2C_WriteReg(REG_END+1,GT9XX_Init_Config[j]);
    //j++;
    //TouchPanel_I2C_WriteReg(REG_END+2,GT9XX_Init_Config[j]);
   ///
 
   for(i=REG_START;i<=REG_END;i++){   	
    value = TouchPanel_I2C_ReadReg(i);
   //debug_msg("TP addr[0x%x] = 0x%x\r\n",i,value);
   }   
	TouchPanelInitOK=TRUE;   	
}

BOOL   TouchPanel_IsInitOK(void)
{
	return TouchPanelInitOK;
}
BOOL   TouchPanel_open(void)
{
	TouchPanel_Init();
}
BOOL   TouchPanel_close(void)
{

}
