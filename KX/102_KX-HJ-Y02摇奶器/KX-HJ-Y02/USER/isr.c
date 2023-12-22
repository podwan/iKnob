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
/** \file isr.c
**
**
**
**	History:
**
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "cms80f731xx.h"
#include "main.h"
#include "userTimer.h"
/****************************************************************************/
/*	Local pre-processor symbols('#define')
****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
****************************************************************************/
u8 g_mainTime;
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
 ** \brief	 Timer 0 interrupt service function
 **
 ** \param [in]  none
 **
 ** \return none
 ******************************************************************************/
#define TMR0_VECTOR 1

void Timer0_IRQHandler(void) interrupt TMR0_VECTOR
{
	TH0 = 0xfe;
	TL0 += 0x0b;

	g_mainTime++;

	dealPer125us();
}
