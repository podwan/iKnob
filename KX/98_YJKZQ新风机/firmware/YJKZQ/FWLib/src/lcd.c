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

/****************************************************************************/
/** \file lcd.c
**
**  
**
**	History:
**
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "lcd.h"

/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
****************************************************************************/

/*****************************************************************************
 ** \brief	 LCD_ConfigRunMode
 **			 配置LCD运行模式
 ** \param [in] DispalyMode: (1) LCD_DISPLAY_NORMAL
 **						(2) LCD_SEG_ALL_ON
 **						(3)	LCD_SEG_ALL_OFF		
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_ConfigRunMode(uint8_t DispalyMode)
{
	LCDCON0 &= ~(LCD_LCDCON0_DM_Msk);
	LCDCON0 |= DispalyMode;
}

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
void LCD_ConfigDuty(uint8_t Duty)
{
	LCDCON0 &= ~(LCD_LCDCON0_DUTY_Msk);
	LCDCON0 |= Duty;
}

/*****************************************************************************
 ** \brief	 LCD_ConfigVLCD
 **			 配置LCD 电压模式
 ** \param [in] VDDSel: (1) LCD_VSEL_VDD
 **						(2) LCD_VSEL_VLCD
 **				LCDtvs:  0x00~0xe     ;VLCD=（15 + LCDtvs ）*VDD/30 
 **				Bias :  (1) LCD_BIAS_2
 **						(2) LCD_BIAS_3
 **						(3) LCD_BIAS_4
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_ConfigVLCD(uint8_t VDDSel, uint8_t LCDtvs , uint8_t Bias)
{
	LCDCON1 = VDDSel |  LCDtvs | Bias;
}

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
void LCD_ConfigClk(uint8_t CLSSel, uint8_t ClkDiv)
{
	uint8_t temp;
	temp = LCDCON2;	
	temp &= ~(LCD_LCDCON2_SEL_Msk|LCD_LCDCON2_PSC_Msk); 
	temp |= CLSSel | ClkDiv;
	LCDCON2 = temp;
}
/*****************************************************************************
 ** \brief	 LCD_EnableLSI
 **			 使能LSI时钟（LCD模块使能）
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_EnableLSI(void)
{
	LCDCON2 |= LCD_LCDCON2_LSIEN_Msk;
}
/*****************************************************************************
 ** \brief	 LCD_DisableLSI
 **			 关闭LSI时钟
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_DisableLSI(void)
{
	LCDCON2 &= ~(LCD_LCDCON2_LSIEN_Msk);	
}
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
void LCD_ConfigResistance(uint8_t Rmode, uint8_t Rsel, uint8_t Rclk)
{
	LCDCON3 = Rmode | Rsel | Rclk;
}

/*****************************************************************************
 ** \brief	 LCD_Start
 **			 使能LCD
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_Start(void)
{
	LCDCON0 |= LCD_LCDCON0_EN_Msk;
}
/*****************************************************************************
 ** \brief	 LCD_Stop
 **			 关闭LCD
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LCD_Stop(void)
{
	LCDCON0 &= ~(LCD_LCDCON0_EN_Msk);
}



