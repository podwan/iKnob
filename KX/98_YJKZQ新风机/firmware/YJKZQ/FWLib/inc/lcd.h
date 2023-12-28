/*******************************************************************************
* Copyright (C) 2019 China Micro Semiconductor Limited Company. All Rights Reserved.
*
* This software is owned and published by:
* CMS LLC, No 2609-10, Taurus Plaza, TaoyuanRoad, NanshanDistrict, Shenzhen, China.
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with CMS
* components. This software is licensed by CMS to be adapted only
* for use in systems utilizing CMS components. CMS shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. CMS is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/

/*****************************************************************************/
/** \file lcd.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __LCD_H__
#define __LCD_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f761xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **LCD模式
 ---------------------------------------------------------------------------*/
#define 	LCD_DISPLAY_NORMAL		(0x03<<LCD_LCDCON0_DM_Pos)		/*LCD 正常输出*/
#define		LCD_SEG_ALL_ON			(0x01<<LCD_LCDCON0_DM_Pos)		/*LCD SEG全开*/
#define		LCD_SEG_ALL_OFF			(0x00)		/*LCD SEG全关*/
/*----------------------------------------------------------------------------
 **LCD 占空比
 ---------------------------------------------------------------------------*/
#define 	LCD_DUTY_4			(0x03)		/*LCD 1/4 DUTY*/			
#define		LCD_DUTY_5			(0x02)		/*LCD 1/5 DUTY*/
#define		LCD_DUTY_6			(0x01)		/*LCD 1/6 DUTY*/
#define		LCD_DUTY_8			(0x00)		/*LCD 1/8 DUTY*/

/*----------------------------------------------------------------------------
 **LCD 电压
 ---------------------------------------------------------------------------*/
#define 	LCD_VSEL_VDD		(0x00)		/*LCD 电压选择 VDD*/		
#define 	LCD_VSEL_VLCD		(0x01<<LCD_LCDCON1_TEN_Pos)		/*LCD 电压选择 VLCD*/	
/*----------------------------------------------------------------------------
 **LCD BIAS
 ---------------------------------------------------------------------------*/
#define 	LCD_BIAS_2			(0x00)		/*LCD BIAS 1/2*/	
#define 	LCD_BIAS_3			(0x01<<LCD_LCDCON1_BIAS_Pos)	/*LCD BIAS 1/3*/
#define 	LCD_BIAS_4			(0x02<<LCD_LCDCON1_BIAS_Pos)	/*LCD BIAS 1/4*/
/*----------------------------------------------------------------------------
 **LCD 充电模式
 ---------------------------------------------------------------------------*/
#define 	LCD_R_60K			(0x00)				/*LCD分压电阻选择60K*/
#define 	LCD_R_225K			(0x01<<LCD_LCDCON3_LCDRM_Pos)	/*LCD分压电阻选择225K*/	
#define 	LCD_R_900K			(0x03<<LCD_LCDCON3_LCDRM_Pos)	/*LCD分压电阻选择900K*/

#define 	LCD_FCMODE_0		(0x00)			/*LCD传统电阻模式*/
#define 	LCD_FCMODE_1		(0x01<<LCD_LCDCON3_FCMODE_Pos) /*LCD快速充电模式*/

#define 	LCD_FCCTL_8			(0x00)			/*LCD充电时间1/8 COM周期*/	
#define 	LCD_FCCTL_16		(0x01)			/*LCD充电时间1/16 COM周期*/	
#define 	LCD_FCCTL_32		(0x02)			/*LCD充电时间1/32 COM周期*/				
#define 	LCD_FCCTL_64		(0x03)			/*LCD充电时间1/64 COM周期*/	


/*----------------------------------------------------------------------------
 **LCD 时钟源选择
 ---------------------------------------------------------------------------*/
#define 	LCD_CLK_LSI			(0x03<<LCD_LCDCON2_SEL_Pos)		/*LCD时钟选择LSI*/
#define 	LCD_CLK_LSE			(0x01<<LCD_LCDCON2_SEL_Pos)		/*LCD时钟选择LSE*/
#define 	LCD_CLK_FSYS		(0x00)				/*LCD时钟选择Fsys*/
/*----------------------------------------------------------------------------
 **LCD 时钟源分频
 ---------------------------------------------------------------------------*/
#define 	LCD_CLKDIV_64			(0x00)		
#define 	LCD_CLKDIV_128			(0x01)
#define 	LCD_CLKDIV_256			(0x02)
#define 	LCD_CLKDIV_512			(0x03)
#define 	LCD_CLKDIV_1024			(0x04)
#define 	LCD_CLKDIV_2048			(0x05)
#define 	LCD_CLKDIV_4096			(0x06)
#define 	LCD_CLKDIV_8192			(0x07)
#define 	LCD_CLKDIV_16384		(0x08)
#define 	LCD_CLKDIV_32768		(0x09)
#define 	LCD_CLKDIV_65536		(0x0F)


/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/



/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/


/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/
/*****************************************************************************
 ** \brief	 LCD_ConfigRunMode
 **			 配置LCD运行模式
 ** \param [in] DispalyMode: (1) LCD_DISPLAY_NORMAL
 **						(2) LCD_SEG_ALL_ON
 **						(3)	LCD_SEG_ALL_OFF	
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_ConfigRunMode(uint8_t DispalyMode);
/*****************************************************************************
 ** \brief	 LCD_ConfigDuty
 **			 配置LCD Duty
 ** \param [in] Duty：  (1) LCD_DUTY_4
 **						(2) LCD_DUTY_5
 **						(3) LCD_DUTY_6
 **						(4) LCD_DUTY_8
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_ConfigDuty(uint8_t Duty);
/*****************************************************************************
 ** \brief	 LCD_ConfigVLCD
 **			 配置LCD 电压模式
 ** \param [in] VDDSel: (1) LCD_VSEL_VDD
 **						(2) LCD_VSEL_VLCD
 **				LCDtvs:  0x00~0xf     ;VLCD=（15 + LCDtvs ）*VDD/30 
 **				Bias :  (1) LCD_BIAS_2
 **						(2) LCD_BIAS_3
 **						(3) LCD_BIAS_4
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_ConfigVLCD(uint8_t VDDSel, uint8_t LCDtvs , uint8_t Bias);

/*****************************************************************************
 ** \brief	 LCD_ConfigClk
 **			 配置LCD 时钟
 ** \param [in] CLSSel: (1) LCD_CLK_LSI
 **						(2) LCD_CLK_LSE
 **						(3) LCD_CLK_FSYS 
 **				ClkDiv:  LCD_CLKDIV_64 ~ LCD_CLKDIV_65536 
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_ConfigClk(uint8_t CLSSel, uint8_t ClkDiv);
/*****************************************************************************
 ** \brief	 LCD_EnableLSI
 **			 使能LSI时钟（LCD模块使能）
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_EnableLSI(void);
/*****************************************************************************
 ** \brief	 LCD_DisableLSI
 **			 关闭LSI时钟
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_DisableLSI(void);
/*****************************************************************************
 ** \brief	 LCD_ConfigResistance
 **			 配置LCD 分压电阻
 ** \param [in] Rmode: (1) LCD_FCMODE_0
 **					   (2) LCD_FCMODE_1
 **				Rsel:  (1)LCD_R_60K
 **					   (2)LCD_R_225K
 **					   (3)LCD_R_900K
 **				Rclk: (1)LCD_FCCTL_8		LCD充电时间1/8 COM周期	
 **					  (2)LCD_FCCTL_16		LCD充电时间1/16 COM周期	
 **					  (3)LCD_FCCTL_32		LCD充电时间1/32 COM周期	
 **					  (4)LCD_FCCTL_64		LCD充电时间1/64 COM周期	
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_ConfigResistance(uint8_t Rmode, uint8_t Rsel, uint8_t Rclk);


/*****************************************************************************
 ** \brief	 LCD_Start
 **			 使能LCD
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_Start(void);
/*****************************************************************************
 ** \brief	 LCD_Stop
 **			 关闭LCD
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_Stop(void);





#endif /* __LCD_H__ */
