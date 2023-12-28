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
/** \file wut.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "wut.h"

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
 ** \brief	 WUT_EnableWUTWakeUp
 **			 使能WUT定时唤醒功能
 ** \param [in] none
 **
 ** \return none
 ** \note   
 *****************************************************************************/
void WUT_EnableWUTWakeUp(void)
{
	WUTCRH |= (WUT_WUTCRH_WUTEN_Msk);

}
/*****************************************************************************
 ** \brief	 WUT_DisableWUTWakeUp
 **			 关闭定时唤醒功能
 ** \param [in] none
 **
 ** \return none
 ** \note   
 *****************************************************************************/
void WUT_DisableWUTWakeUp(void)
{
	WUTCRH &= ~(WUT_WUTCRH_WUTEN_Msk);
}

/*****************************************************************************
 ** \brief	 WUT_ConfigCLK
 **			设置定时唤醒时钟
 ** \param [in] clkdiv: (1)WUT_CLK_DIV_1 
 **						(2)WUT_CLK_DIV_8
 **						(2)WUT_CLK_DIV_32
**						(2)WUT_CLK_DIV_256
 ** \return none
 ** \note   
 *****************************************************************************/
void WUT_ConfigCLK(uint8_t clkdiv)
{
	uint8_t temp;
	temp = WUTCRH;	
	temp &= ~(WUT_WUTCRH_WUTPS_Msk);
	temp |= (clkdiv<<WUT_WUTCRH_WUTPS_Pos);
	WUTCRH = temp;
}

/*****************************************************************************
 ** \brief	 WUT_ConfigTime
 **			设置定时唤醒时间
 ** \param [in] time: 12it（0x0 ~ 0xFFF）
 ** \return none
 ** \note   
 *****************************************************************************/
void WUT_ConfigTime(uint16_t time )
{
	uint8_t temp;
	temp = WUTCRH;	
	temp &= ~(WUT_WUTCRH_WUTD_Msk);
	temp |= time>>8;
	WUTCRH = temp;
	WUTCRL = time;
}

/*****************************************************************************
 ** \brief	 WUT_GetOverflowFlag
 **			 获取WUT定时器计数溢出标志
 ** \param [in] none
 ** \return   0：无溢出   1：溢出
 ** \note
 *****************************************************************************/
uint8_t WUT_GetOverflowFlag(void)
{
	return((WUTCRH & WUT_WUTCRH_TMROV_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 WUT_ClearOverflowFlag
 **			 清除WUT定时器计数溢出标志
 ** \param [in] none
 ** \return   none
 ** \note
 *****************************************************************************/
void WUT_ClearOverflowFlag(void)
{
	WUTCRH &= ~(WUT_WUTCRH_TMROV_Msk);	
}











