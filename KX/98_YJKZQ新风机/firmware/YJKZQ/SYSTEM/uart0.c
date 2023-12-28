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
/** \file time.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "uart0.h"

/****************************************************************************/
/*	Local pre-processor symbols('#define')
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
 ** \brief	 UART0_Config
 **
 ** \param [in]  none   
 **
 ** \return 0
 *****************************************************************************/
void UART0_Config(void)
{
	 uint16_t  BRTValue = 0;

	 /*
	 (1)设置UARTx的运行模式
	 */
	 UART_ConfigRunMode(UART0,UART_MOD_ASY_8BIT, UART_BAUD_BRT);
	 UART_EnableReceive(UART0);
	 /*
	 (2)配置UARTx的波特率
	 */
	 UART_ConfigBRTClk(BRT_CLK_DIV_2);	
	
	 UART_EnableDoubleFrequency(UART0); 							/*波特率使能倍频：SMOD =1*/
	
	 #ifdef USE_FORMULA			//使用公式计算定时器的加载值(需要对Systemclock赋值(main.c))，USE_FORMULA 在 选项Option->C51->Preporcessor Symbols->Define中定义
	 BRTValue = UART_ConfigBaudRate(UART0, BaudRateVlue) ;
  #else 
		BRTValue = 65523;//115200 				//使用数据手册上推荐的加载值(BRT章节)
		//BRTValue = 65497;//38400
		//BRTValue = 65458;//19200
		//BRTValue = 65380;//9600
	#endif
 
	 UART_ConfigBRTPeriod(BRTValue);						/*配置重装值*/
	 UART_EnableBRT();										/*使能定时器*/
	 /*
	 (3)配置IO口
	 */
	 //PS_TXD0 = 0x25;
	 //P24CFG = 0x03;//RX
	 P25CFG = 0x02;//TX
}


void UART0_SendChar (char ch)
{
	SBUF0 = ch;
	while( !(SCON0 & (1<<1)));
	SCON0 &=~(1<<1);		
}

