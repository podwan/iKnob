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
/** \file led.c
**
**  
**
**	History:
**
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "led.h"

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
 ** \brief	 LED_EnableMatrixMode
 **			 使能LED矩阵驱动模式
 ** \param [in] none		
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableMatrixMode(void)
{
	LEDMODE = 0x55;
}
/*****************************************************************************
 ** \brief	 LED_ConfigMatrixMode
 **			 配置LED矩阵驱动模式
 ** \param [in] ClkSel: (1)	LED_CLK_LSI
 **						(2) LED_CLK_LSE
 **						(3)	LED_CLK_FSYS
 **				Duty:	(1) LED_DUTY_4
 **						(2)	LED_DUTY_5
 **						(3)	LED_DUTY_6
 **						(4)	LED_DUTY_8	  
 **				Common:	(1) LED_COM_CATHODE			共阴驱动模式
 **						(2)	LED_COM_ANODE   		共阳驱动模式			
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigMatrixMode(uint8_t ClkSel, uint8_t Duty, uint8_t Common)
{
	LEDCON &= 0x80;
	LEDCON |=  ClkSel | (Duty<<LED_LEDCON_DUTY_Pos) | (Common<<LED_LEDCON_CCCA_Pos);	
}
/*****************************************************************************
 ** \brief	 LED_ConfigMatrixClkDiv
 **			 配置LED矩阵驱动模式时钟分频
 ** \param [in] ClkDiv: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigMatrixClkDiv(uint16_t ClkDiv)
{
	LEDCLKL =  (uint8_t)ClkDiv;
	LEDCLKH = (uint8_t)(ClkDiv>>8);
}
/*****************************************************************************
 ** \brief	 LED_ConfigMatrixComTime
 **			 配置矩阵驱动模式COM口有效时间
 ** \param [in] Time ： 0x01~0xff
 ** \return  none
 ** \note   禁止设置成0x00
******************************************************************************/
void LED_ConfigMatrixComTime(uint8_t Time)
{
	LEDCOMTIME = Time;
}
/*****************************************************************************
 ** \brief	 LED_StartMatrix
 **			 开启LED矩阵驱动
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StartMatrix(void)
{
	LEDCON |= LED_LEDCON_EN_Msk;
}
/*****************************************************************************
 ** \brief	 LED_StopMatrix
 **			 停止LED矩阵驱动
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StopMatrix(void)
{
	LEDCON &= ~(LED_LEDCON_EN_Msk);
}
	
/*****************************************************************************
 ** \brief	 LED_EnableLatticeMode
 **			 使能LED点阵驱动模式
 ** \param [in] none		
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableLatticeMode(void)
{
	LEDMODE = 0xAA;
}
/*****************************************************************************
 ** \brief	 LED_ConfigLatticeMode
 **			 配置LED点阵驱动模式
 ** \param [in] ClkSel: (1)	LED_CLK_LSI
 **						(2) LED_CLK_LSE
 **						(3)	LED_CLK_FSYS
 **				Mode:	(1) LED_LATTICE_4X4			4*4点阵
 **						(2)	LED_LATTICE_5X5			5*5点阵
 **						(3)	LED_LATTICE_6X6			6*6点阵
 **						(4)	LED_LATTICE_6X7			6*7点阵
 **						(5)	LED_LATTICE_7X7			7*7点阵
 **						(6)	LED_LATTICE_7X8			7*8点阵
 **						(7)	LED_LATTICE_8X8 		8*8点阵
 **				Scan:	(1) LED_SCAN_INTERRUPT		中断扫描模式
 **						(2)	LED_SCAN_LOOP   		循环扫描模式			
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticeMode(uint8_t ClkSel, uint8_t Mode, uint8_t Scan)
{
	LEDCON1 &=0x80;
	LEDCON1 |= ClkSel | (Mode<<LED_LEDCON1_DUTY_Pos)|(Scan<<LED_LEDCON1_SMODE_Pos);
}
/*****************************************************************************
 ** \brief	 LED_ConfigLatticeClkDiv
 **			 配置LED点阵驱动模式时钟分频
 ** \param [in] ClkDiv: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticeClkDiv(uint16_t ClkDiv)
{
	LEDCLKL1 =  (uint8_t)ClkDiv;
	LEDCLKH1 = (uint8_t)(ClkDiv>>8);	
}
/*****************************************************************************
 ** \brief	 LED_ConfigLatticePeriod1
 **			 配置LED点阵驱动模式的周期1
 ** \param [in] Period: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticePeriod1(uint16_t Period)
{
	SCAN1WL =  (uint8_t)Period;
	SCAN1WH = (uint8_t)(Period>>8);	
}
/*****************************************************************************
 ** \brief	 LED_ConfigLatticePeriod2
 **			 配置LED点阵驱动模式的周期2
 ** \param [in] Period: 0x00~0xffff
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ConfigLatticePeriod2(uint16_t Period)
{
	SCAN2WL =  (uint8_t)Period;
	SCAN2WH = (uint8_t)(Period>>8);			
}

/*****************************************************************************
 ** \brief	 LED_StartLattice
 **			 开启LED点阵驱动
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StartLattice(void)
{
	LEDCON1 |= LED_LEDCON1_SSTART_Msk;
}
/*****************************************************************************
 ** \brief	 LED_StopLattice
 **			 停止LED点阵驱动
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_StopLattice(void)
{
	LEDCON1 &= ~(LED_LEDCON1_SSTART_Msk);
}

/*****************************************************************************
 ** \brief	 LED_RestartLattice
 **			 重启LED点阵驱动
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_RestartLattice(void)
{
	LEDCON1 &= ~(LED_LEDCON1_SSTART_Msk);
	LEDCON1 |= LED_LEDCON1_SSTART_Msk;	
}

/*****************************************************************************
 ** \brief	 LED_EnableInt
 **			 使能LED点阵驱动模式中断
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_EnableInt(void)
{
	LEDSTATUS |= LED_LEDSTATUS_LEDIE_Msk;
}
/*****************************************************************************
 ** \brief	 LED_DisableInt
 **			 关闭LED点阵驱动模式中断
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_DisableInt(void)
{
	LEDSTATUS &= ~(LED_LEDSTATUS_LEDIE_Msk);
}
/*****************************************************************************
 ** \brief	 LED_GetIntFlag
 **			 获取LED点阵驱动模式中断标志
 ** \param [in] none
 ** \return  0:无中断  1:产生中断
 ** \note   
******************************************************************************/
uint8_t LED_GetIntFlag(void)
{
	return((LEDSTATUS & LED_LEDSTATUS_LEDIF_Msk) ? 1:0);
}
/*****************************************************************************
 ** \brief	 LED_ClearIntFlag
 **			 清除LED点阵驱动模式中断标志
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void LED_ClearIntFlag(void)
{
	LEDSTATUS &= ~(LED_LEDSTATUS_LEDIF_Msk);
}



