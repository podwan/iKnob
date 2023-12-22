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
/** \file gpio.c
**
** 
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "gpio.h"

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

 /********************************************************************************
 ** \brief	 GPIO_EnableInt
 **			 使能IO口的中断功能
 ** \param [in] Port  ： GPIO0、GPIO1、GPIO2、GPIO5
 **			    PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK			 
 ** \return  none
 ** \note   
 ******************************************************************************/
void GPIO_EnableInt(uint8_t Port, uint8_t PinMSK)
{
	switch(Port)
	{
		case GPIO0:
			P0EXTIE |= PinMSK;
			break;
		case GPIO1:
			P1EXTIE |= PinMSK;
			break;		
		case GPIO2:
			P2EXTIE |= PinMSK;
			break;			
		case GPIO5:
			P5EXTIE |= PinMSK;
			break;		
		default:
			break;	
	}
}
/********************************************************************************
 ** \brief	 GPIO_DisableInt
 **			 关闭IO口的中断功能
 ** \param [in] Port  ： GPIO0、GPIO1、GPIO2、GPIO5
 **			    PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK			 
 ** \return  none
 ** \note   
 ******************************************************************************/
void GPIO_DisableInt(uint8_t Port, uint8_t PinMSK)
{
	switch(Port)
	{
		case GPIO0:
			P0EXTIE &= ~PinMSK;
			break;
		case GPIO1:
			P1EXTIE &= ~PinMSK;
			break;		
		case GPIO2:
			P2EXTIE &= ~PinMSK;
			break;	
		case GPIO5:
			P5EXTIE &= ~PinMSK;
			break;		
		default:
			break;	
	}
}

 /******************************************************************************
 ** \brief	 GPIO_GetIntFlag
 **			 获取中断标志
 ** \param [in] Port  ： GPIO0、GPIO1、GPIO2、GPIO5
 **			    PinNum:  GPIO_PIN_0~GPIO_PIN_7 		 
 ** \return  0：无中断产生
 **			 1：有中断产生
 ** \note  
 ******************************************************************************/
uint8_t  GPIO_GetIntFlag(uint8_t Port, uint8_t PinNum)
{
	uint8_t PinIntFlag = 0;
	switch(Port)
	{
		case GPIO0:
			PinIntFlag = P0EXTIF & (1<<PinNum);
			break;
		case GPIO1:
			PinIntFlag = P1EXTIF & (1<<PinNum);
			break;		
		case GPIO2:
			PinIntFlag = P2EXTIF & (1<<PinNum);
			break;					
		case GPIO5:
			PinIntFlag = P5EXTIF & (1<<PinNum);
			break;				
		default:
			break;	
	}
	return( (PinIntFlag)? 1:0);
}
 /********************************************************************************
 ** \brief	 GPIO_ClearIntFlag
 **			清除中断标志位
 ** \param [in] Port  ： GPIO0、GPIO1、GPIO2、GPIO5
 **			    PinNum:  GPIO_PIN_0~GPIO_PIN_7 		 
 ** \return  none
 ** \note  
 ******************************************************************************/
void GPIO_ClearIntFlag(uint8_t Port, uint8_t PinNum)
{
	switch(Port)
	{
		case GPIO0:
			P0EXTIF = 0xff &(~(1<<PinNum));
			break;
		case GPIO1:
			P1EXTIF = 0xff &(~(1<<PinNum));
			break;		
		case GPIO2:
			P2EXTIF = 0xff &(~(1<<PinNum));
			break;			
		case GPIO5:
			P5EXTIF = 0xff &(~(1<<PinNum));
			break;			
		default:
			break;	
	}
}