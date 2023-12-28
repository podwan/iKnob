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
#include "time.h"

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
/******************************************************************************
** \brief	 TMR0_Config
** \param [in] 
**            	
** \return  none
** \note  
******************************************************************************/
void TMR0_Config(void)
{
	/*
	PT0 = 1;
	TMOD |= 0x02;
	CKCON |= 0x00;//TMR_CLK_DIV_12
	TH0 = 256-250;
	TL0 = 256-250;
	IP |= 0x02;//优先级高
	IE |= 0x02;
	TCON |= 0x10;
	*/
	
	PT0 = 1;
	TMOD |= 0X01;//16bit
	CKCON |= 0x00;//TMR_CLK_DIV_12
	TH0 = 0xfe;
	TL0 = 0x0b;
	IP |= 0x02;
	IE |= 0x82;
	TCON |= 0x10;

}

