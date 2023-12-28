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
/** \file PWM.h
**
** 
**
** History:
** 
******************************************************************************/
#ifndef __PWM_H__
#define __PWM_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f761xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **PWM通道Mask
/*---------------------------------------------------------------------------*/
#define PWM_CHANNEL_NUM                     (6)    /* PWM channel number */
#define PWM_CH_0_MSK                       (0x1)   /* PWM channel 0 mask */
#define PWM_CH_1_MSK                       (0x2)   /* PWM channel 1 mask */
#define PWM_CH_2_MSK                       (0x4)   /* PWM channel 2 mask */
#define PWM_CH_3_MSK                       (0x8)   /* PWM channel 3 mask */
#define PWM_CH_4_MSK                       (0x10)  /* PWM channel 4 mask */
#define PWM_CH_5_MSK                       (0x20)  /* PWM channel 5 mask */

#define PWM0								(0x00)	/* PWM channel 0 number */
#define PWM1								(0x01)	/* PWM channel 1 number */
#define PWM2								(0x02)	/* PWM channel 2 number */
#define PWM3								(0x03)	/* PWM channel 3 number */
#define PWM4								(0x04)	/* PWM channel 4 number */
#define PWM5								(0x05)	/* PWM channel 5 number */

/*----------------------------------------------------------------------------
 **PWM波形发生器单元(WFG)模式
/*---------------------------------------------------------------------------*/
#define PWM_WFG_INDEPENDENT 		(0x00)  /*单个（独立）模式*/
#define PWM_WFG_COMPLEMENTARY 		(0x10)  /*互补模式*/
#define PWM_WFG_SYNCHRONIZED		(0x20)  /*同步模式*/
/*----------------------------------------------------------------------------
 **PWM输出控制单元(OC)模式
/*---------------------------------------------------------------------------*/
#define PWM_OC_GROUP				(0x08)  /*组控模式*/
#define PWM_OC_INDEPENDENT 			(0x00)  /* 通道各自独立控制*/

/*----------------------------------------------------------------------------
 **EPWM时钟分频系数
 * 总分频(PWMnDIV分频) = Fpwmn-PSC分频 * CLK_DIV分频
 *   Fpwmn-PSC分频 = PWMnPSC/2 (PWMnPSC不为0的情况)----2分频
/*---------------------------------------------------------------------------*/
#define PWM_CLK_DIV_1						(0xff)					//=Fsys（系统时钟）		
#define PWM_CLK_DIV_2						(0x04)					//= Fpwmn-PSC   (PWMnPSC/2)
#define PWM_CLK_DIV_4						(0x00)					//= Fpwmn-PSC/2 ((PWMnPSC/2)/2)
#define PWM_CLK_DIV_8						(0x01)					//= Fpwmn-PSC/4 ((PWMnPSC/2)/4)
#define PWM_CLK_DIV_16					(0x02)					//= Fpwmn-PSC/8 ((PWMnPSC/2)/8)
#define PWM_CLK_DIV_32					(0x03)					//= Fpwmn-PSC/16((PWMnPSC/2)/16)
												  
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
 ** \brief	 PWM_ConfigRunMode
 **			 设置PWM的运行模式
 ** \param [in] PWMRunMode:   (1)PWM_WFG_INDEPENDENT
 **							   (2)PWM_WFG_COMPLEMENTARY
 **							   (3)PWM_WFG_SYNCHRONIZED
 **							   (4)PWM_OC_GROUP
 **							   (5)PWM_OC_INDEPENDENT
 ** \return  none
 ** \note    以上5种摸式可组合成不同的运行模式，且共用一个8位寄存器
 ****************************************************************************/
void PWM_ConfigRunMode( uint8_t PWMRunMode);
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelClk	
 ** \param [in] ClkDiv: (1)PWM_CLK_DIV_1 
 **						(2)PWM_CLK_DIV_2
 **						(2)PWM_CLK_DIV_4
 **						(2)PWM_CLK_DIV_8
 **						(2)PWM_CLK_DIV_16
 **						(2)PWM_CLK_DIV_32
 ** \return  none	
 ** \note 
 **	(1)PWM01PSC共同控制PWM0、PWM1通道 ，所以此函数统一设置PWMxxPSC=0x01
 **	若需要其他的分频，请酌情对寄存器赋值
 **	(2)PWM 分频分为两级：PWMxPSC PWMnDIV 
 **	第一级分频(PWMxPSC)：0x00 预分频停止并且计数器停止，系统时钟分频系数PWMxPSC+1
 **	第二级分频（PWMnDIV): 0x00 FPWMPSC/2; 0x01 FPWMPSC/4；0x02:FPWMPSC/8；0x3 FPWMPSC/16
 **	0x04 FPWMPSC ; 其他 Fsys 
 ** 分频级数：1~4096，例Fsys=8M，PWM的频率范围：1.95k ~ 8M	
 ****************************************************************************/
void PWM_ConfigChannelClk(uint8_t ChannelNum,uint8_t ClkDiv);
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelPeriod
 **			 设置PWM通道的频率以及占空比
 ** \param [in] ChannelNum : PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 **				Period: 16位周期值
 ** \return none
 ** \note    
 ****************************************************************************/
void PWM_ConfigChannelPeriod(uint8_t ChannelNum,uint16_t Period);
 
/*****************************************************************************
 ** \brief	 PWM_ConfigChannelDuty
 **			 设置PWM通道占空比
 ** \param [in] ChannelNum  :PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 **				Duty: 16位占空比
 ** \return none
 ** \note   
 ****************************************************************************/
void PWM_ConfigChannelDuty(uint8_t ChannelNum,uint16_t Duty);

 /****************************************************************************
 ** \brief	 PWM_EnableOneShotMode
 **			 开启One-Shot模式
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void PWM_EnableOneShotMode(uint8_t ChannelMask);
/****************************************************************************
 ** \brief	 PWM_EnableAutoLoadMode
 **			 开启自动加载模式
 ** \param [in]  ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
*****************************************************************************/
void PWM_EnableAutoLoadMode(uint8_t ChannelMask);

/*****************************************************************************
 ** \brief	 PWM_Start
 **			
 ** \param [in]  ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note	
 ****************************************************************************/
void PWM_Start( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_Stop
 **				
 ** \param [in] ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note    停止计数并且PWM计数器清0
*****************************************************************************/
void PWM_Stop( uint8_t ChannelMask);

/*****************************************************************************
 ** \brief	 PWM_EnableOutput
 **			 开启PWM输出
 ** \param [in] ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_EnableOutput( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_DisableOutput
 **			 关闭PWM输出
 ** \param [in] ChannelMask   PWM_CH_0_MSK ~ PWM_CH_5_MSK
 ** \return  none
 ** \note    
*****************************************************************************/
void PWM_DisableOutput( uint8_t ChannelMask);

/****************************************************************************
 ** \brief	 PWM_EnableDeadZone
 **			 开启死区
 ** \param [in] Channel: PWM0、PWM1....PWM5		
 **			DeadTime : 死区时间( 0~0xFF) = DeadTime * TPWM
 ** \return  none
 ** \note  
*****************************************************************************/
void PWM_EnableDeadZone( uint8_t Channel, uint8_t DeadTime);
/*****************************************************************************
 ** \brief	 PWM_DisableDeadZone
 **			 关闭PWM死区
 ** \param [in] Channel: PWM0、PWM1....PWM5	
 ** \return  none
 ** \note  
*****************************************************************************/
void PWM_DisableDeadZone( uint8_t Channel);

/*****************************************************************************
 ** \brief	 PWM_EnableDownCmpInt
 **			 开启向下比较中断
 ** \param [in] ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_EnableDownCmpInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_DisableDownCmpInt
 **			 关闭向下比较中断
 ** \param [in] ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_DisableDownCmpInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_GetUpCmpIntFlag
 **			 获取向下比较中断标志位
 ** \param [in] ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return  0: 无中断产生
 **          1：有中断产生
 ** \note   
*****************************************************************************/
uint8_t PWM_GetDownCmpIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 PWM_ClearUpCmpIntFlag
 **			 清除向下比较中断标志位
 ** \param [in] ChannelNum :PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return  none
 ** \note   
*****************************************************************************/
void PWM_ClearDownCmpIntFlag( uint8_t ChannelNum);

/*****************************************************************************
 ** \brief	 PWM_EnableZeroInt
 **			 开启零点中断
 ** \param [in]  ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_EnableZeroInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_DisableZeroInt
 **			 关闭零点中断 
 ** \param [in]ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_DisableZeroInt( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_GetZeroIntFlag
 **			 获取零点中断标志位 
 ** \param [in] ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return   0：无中断产生
 **           1：有中断产生   
 ** \note   
 *****************************************************************************/
uint8_t PWM_GetZeroIntFlag( uint8_t ChannelNum);
/*****************************************************************************
 ** \brief	 PWM_ClearZeroIntFlag
 **			 清除零点中断标志位
 ** \param [in] ChannelNum: PWM0,PWM1,PWM2,PWM3,PWM4,PWM5
 ** \return   none     
 ** \note   
*****************************************************************************/
void PWM_ClearZeroIntFlag( uint8_t ChannelNum);

/*****************************************************************************
 ** \brief	 PWM_EnableReverseOutput
 **			 开启反向输出
 ** \param [in] ChannelMask : PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note 
*****************************************************************************/
void  PWM_EnableReverseOutput( uint8_t ChannelMask);
/*****************************************************************************
 ** \brief	 PWM_DisableReverseOutput
 **			 关闭反向输出
 ** \param [in]ChannelMask: PWM_CH_0_MSK ~ PWM_CH_5_MSK	
 ** \return  none
 ** \note   
*****************************************************************************/
void  PWM_DisableReverseOutput( uint8_t ChannelMask);

/*****************************************************************************
 ** \brief	 PWM_AllIntEnable
 **			 使能PWM总中断
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  PWM_AllIntEnable(void);
/*****************************************************************************
 ** \brief	 PWM_AllIntDisable
 **			 关闭PWM总中断
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void  PWM_AllIntDisable(void);

/****************************************************************************
 ** \brief	 PWM_EnableSynCount	
 **			使能PWMn同步计数
 ** \param [in]  none
 ** \return  none
 ** \note	
 ****************************************************************************/
void PWM_EnableSynCount(void);





#endif /* __PWM_H__ */







