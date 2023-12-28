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
/** \file delay.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "cms80f761xx.h"
#include "delay.h"

/****************************************************************************/
/*	Local pre-processor symbols('#define')
****************************************************************************/
#define clrwdt()			CKCON |= 0xC0; CKCON &= 0xDF; EA = 0, TA=0xAA, TA=0x55, WDCON = 0x03, EA = 1;
//看门狗溢出时间约350ms，关总中断，清看门狗，使能看门狗复位，开总中断
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
/******************************************************************************
** \brief	 Delay_ms
** \param [in] time
**            	
** \return  none
** \note  
******************************************************************************/
void Delay_ms(unsigned char time)
{
	unsigned char	i = 0;
	
	do{
		while(-- i);
		clrwdt();
	}while(time --);
}


