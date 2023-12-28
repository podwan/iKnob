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
/** \file wwdt.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __WWDT_H__
#define __WWDT_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f761xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/

/*----------------------------------------------------------------------------
 **WWDT 模式
/*---------------------------------------------------------------------------*/
#define  WWDT_CLEAN_ALLTIME_MODE		(0x0)		/*任意时间喂狗模式（计数器自减1到0产生复位）。*/
#define  WWDT_CLEAN_WINDOW_MODE			(0x1)		/*窗口喂狗模式（0<计数器值<CMPDAT值区间喂狗不会产生复位，其他情况复位）*/

/*----------------------------------------------------------------------------
 **WWDT 时钟分频
/*---------------------------------------------------------------------------*/
#define WWDT_CLK_DIV_256 		(0x00)		/*溢出时间= TLSI * 2^8   */
#define WWDT_CLK_DIV_512 		(0x01)		/*溢出时间= TLSI * 2^9   */
#define WWDT_CLK_DIV_1024 		(0x02)		/*溢出时间= TLSI * 2^10  */
#define WWDT_CLK_DIV_2048 		(0x02)		/*溢出时间= TLSI * 2^11  */
#define WWDT_CLK_DIV_4096 		(0x04)		/*溢出时间= TLSI * 2^12  */
#define WWDT_CLK_DIV_8192 		(0x05)		/*溢出时间= TLSI * 2^13  */
#define WWDT_CLK_DIV_16384 		(0x06)		/*溢出时间= TLSI * 2^14  */
#define WWDT_CLK_DIV_32768 		(0x07)		/*溢出时间= TLSI * 2^15  */
#define WWDT_CLK_DIV_65536 		(0x08)		/*溢出时间= TLSI * 2^16  */

#define WWDT_CLK_DIV_131072 	(0x09)		/*溢出时间= TLSI * 2^17  */
#define WWDT_CLK_DIV_262144 	(0x0a)		/*溢出时间= TLSI * 2^18  */
#define WWDT_CLK_DIV_524288 	(0x0b)		/*溢出时间= TLSI * 2^19  */
#define WWDT_CLK_DIV_1048576 	(0x0c)		/*溢出时间= TLSI * 2^20  */
#define WWDT_CLK_DIV_2097152 	(0x0d)		/*溢出时间= TLSI * 2^21  */
#define WWDT_CLK_DIV_4194304 	(0x0e)		/*溢出时间= TLSI * 2^22  */

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
** \brief	 WWDT_ConfigRunMode
**			 配置WWDT的运行模式
** \param [in] mode: (1)WWDT_CLEAN_ALLTIME_MODE
**					 (2)WWDT_CLEAN_WINDOW_MODE
** \return none 
** \note
*****************************************************************************/
void WWDT_ConfigRunMode(uint8_t mode);
/*****************************************************************************
** \brief	WWDT_ConfigOverflowTime
**			 配置WWDT的溢出时间
** \param [in] time: WWDT_CLK_DIV_256 ~ WWDT_CLK_DIV_4194304
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_ConfigOverflowTime(uint8_t time);
 
/*****************************************************************************
** \brief	WWDT_ConfigCompareValue
**			 配置WWDT的比较值
** \param [in] value: 0~0x1F
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_ConfigCompareValue(uint8_t value);
  
/*****************************************************************************
** \brief	WWDT_ClearWWDT
**			清WWDT
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_ClearWWDT(void);
 
/*****************************************************************************
** \brief	WWDT_EnableWWDTWakeUp
**			使能WWDT休眠唤醒System
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_EnableWWDTWakeUp(void); 
/*****************************************************************************
** \brief	WWDT_DisableWWDTWakeUp
**			关闭WWDT休眠唤醒System
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_DisableWWDTWakeUp(void);  
 
/*****************************************************************************
 ** \brief	 WWDT_EnableCompareInt
 **			 使能WWDT计数比较中断
 ** \param [in] none
 **
 ** \return none 
 ** \note
 *****************************************************************************/
 void WWDT_EnableCompareInt(void);
/*****************************************************************************
 ** \brief	 WWDT_DisableCompareInt
 **			 关闭WWDT计数比较中断
 ** \param [in] none
 **
 ** \return none 
 ** \note
 *****************************************************************************/
 void WWDT_DisableCompareInt(void);
/*****************************************************************************
 ** \brief	 WWDT_GetCompareIntFlag
 **			 获取WWDT计数比较中断标志
 ** \param [in] none
 **
 ** \return 0：无中断，1：有中断
 ** \note
 *****************************************************************************/
uint8_t WWDT_GetCompareIntFlag(void);
/*****************************************************************************
 ** \brief	 WWDT_ClearCompareIntFlag
 **			 清除WWDT计数比较中断标志
 ** \param [in] none
 **
 ** \return 0：无中断，1：有中断
 ** \note
 *****************************************************************************/
void WWDT_ClearCompareIntFlag(void);


/*****************************************************************************
** \brief	WWDT_EnableWWDTReset
**			使能WWDT复位System
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_EnableWWDTReset(void);
/*****************************************************************************
** \brief	WWDT_DisableWWDTReset
**			关闭WWDT复位System
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_DisableWWDTReset(void);

/*****************************************************************************
** \brief	WWDT_Start
**			使能WWDT
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_Start(void);
/*****************************************************************************
** \brief	WWDT_Stop
**			关闭WWDT
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_Stop(void);

/*****************************************************************************
** \brief	WWDT_ForceRun
**			强制WWDT运行并开启复位系统模式
** \param [in] none
**					
** \return none 
** \note
*****************************************************************************/
void WWDT_ForceRun(void);

#endif /* __WWDT_H__ */

