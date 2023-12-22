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
/** \file adc.h
**
** 
**
** History:
** 
******************************************************************************/
#ifndef __ADC_H__
#define __ADC_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f731xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **ADC 通道编号
/*---------------------------------------------------------------------------*/
#define  ADC_CH_0		 	(0x00)				/* AN0 */
#define  ADC_CH_1			(0x01)				/* AN1 */
#define  ADC_CH_2		 	(0x02)				/* AN2 */
#define  ADC_CH_3			(0x03)				/* AN3 */
#define  ADC_CH_4		 	(0x04)				/* AN4 */
#define  ADC_CH_5			(0x05)				/* AN5 */
#define  ADC_CH_6		 	(0x06)				/* AN6 */
#define  ADC_CH_7			(0x07)				/* AN7 */
#define  ADC_CH_8		 	(0x08)				/* AN8 */
#define  ADC_CH_9			(0x09)				/* AN9 */
#define  ADC_CH_10			(0x0a)				/* AN10 */
#define  ADC_CH_11		 	(0x0b)				/* AN11 */
#define  ADC_CH_12			(0x0c)				/* AN12 */
#define  ADC_CH_13		 	(0x0d)				/* AN13 */
#define  ADC_CH_14			(0x0e)				/* AN14 */
#define  ADC_CH_15			(0x0f)				/* AN15 */
#define  ADC_CH_16			(0x10)				/* AN16 */
#define  ADC_CH_17			(0x11)				/* AN17 */
#define  ADC_CH_18			(0x12)				/* AN18 */
#define  ADC_CH_19			(0x13)				/* AN19 */
#define  ADC_CH_39			(0x27)				/* AN39 */
#define  ADC_CH_40			(0x28)				/* AN40 */
#define  ADC_CH_41			(0x29)				/* AN41 */
#define  ADC_CH_42			(0x2a)				/* AN42 */
#define  ADC_CH_43			(0x2b)				/* AN43 */
#define  ADC_CH_44			(0x2c)				/* AN44 */


#define  ADC_CH_63_BGR			(0x0)				/* AN63接固定参考电压1.2V*/
#define  ADC_CH_63_VSS			(0x5)				/* AN63接 VSS ADC参考地*/
#define  ADC_CH_63_VDD			(0x7)				/* AN63接 VDD 参考电压*/


/*----------------------------------------------------------------------------
 **ADC 运行时钟分频
/*---------------------------------------------------------------------------*/
#define  ADC_CLK_DIV_2		(0x00)
#define  ADC_CLK_DIV_4		(0x01)
#define  ADC_CLK_DIV_8		(0x02)
#define  ADC_CLK_DIV_16		(0x03)
#define  ADC_CLK_DIV_32		(0x04)
#define  ADC_CLK_DIV_64		(0x05)
#define  ADC_CLK_DIV_128	(0x06)
#define  ADC_CLK_DIV_256	(0x07)
/*----------------------------------------------------------------------------
 **ADC 转换结果格式
/*---------------------------------------------------------------------------*/
#define	 ADC_RESULT_LEFT	(0x00<< ADC_ADCON0_ADFM_Pos)			/*左对齐*/
#define  ADC_RESULT_RIGHT	(0x01<< ADC_ADCON0_ADFM_Pos)			/*右对齐*/

/*----------------------------------------------------------------------------
 **ADC 硬件触发模式
/*---------------------------------------------------------------------------*/
#define	ADC_TG_PWM0			(0x00)		//PWM0触发ADC转换
#define	ADC_TG_PWM2			(0x01)		//PWM2触发ADC转换
#define	ADC_TG_PWM4			(0x02)		//PWM4触发ADC转换
#define	ADC_TG_ADET			(0x03)		//ADET引脚触发ADC转换

#define	ADC_TG_FALLING		(0x00)		//下降沿触发
#define	ADC_TG_RISING		(0x01)		//上升沿触发
#define	ADC_TG_PWM_PE		(0x03)		//PWM周期零点触发

/*----------------------------------------------------------------------------
 **ADC 参考电压
/*---------------------------------------------------------------------------*/
#define ADC_VREF_1P2V			(0x00)						/*Vref =1.2v*/
#define ADC_VREF_2V				(0x01<<ADC_ADCLDO_VSEL_Pos)	/*Vref =2.0v*/
#define ADC_VREF_2P4V			(0x02<<ADC_ADCLDO_VSEL_Pos)	/*Vref =2.4v*/
#define ADC_VREF_3V				(0x03<<ADC_ADCLDO_VSEL_Pos)	/*Vref =3v*/
/*****************************************************************************
 ** \brief	 ADC_IS_BUSY
 **			 判断ADC工作状态
 ** \param [in]	 none        
 ** \return   
*****************************************************************************/
#define  ADC_IS_BUSY				(ADCON0 & ADC_ADCON0_ADGO_Msk)
/*****************************************************************************
 ** \brief	 ADC_GO
 **			 启动ADC转换(软件触发)
 ** \param [in]	 none     
 ** \return  none
*****************************************************************************/
#define  ADC_GO() 				 do{\
									ADCON0 |= ADC_ADCON0_ADGO_Msk;\
								   }while(0)
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
 ** \brief	 ADC_Start
 **			 ADC模块开启
 ** \param [in]	 none
 **          
 ** \return  none
*****************************************************************************/
void  ADC_Start(void);
/*****************************************************************************
 ** \brief	 ADC_Stop
 **			 ADC模块停止
 ** \param [in] none
 **          
 ** \return  none
*****************************************************************************/
void  ADC_Stop(void);

/*****************************************************************************
 ** \brief	 ADC_ConfigRunMode
 **			  配置ADC的运行模式
 ** \param [in] ADCClkDiv: ADC_CLK_DIV_1 ~ ADC_CLK_DIV_256
 **          	ADCResultTpye: (1)ADC_RESULT_LEFT    左对齐
 **							   (2)ADC_RESULT_RIGHT   右对齐
 ** \return  none
 ** \note 	 左对齐模式: ADRESH存放数据的高8位，ADRESL高4位存放数据低4位
 **			 右对齐模式: ADRESH存放数据的高4位，ADRESL存放数据低8位	
*****************************************************************************/
void  ADC_ConfigRunMode( uint8_t ADCClkDiv, uint8_t ADCResultTpye);

/*****************************************************************************
 ** \brief	 ADC_EnableHardwareTrig
 **			使能硬件触发ADC
 ** \param [in] none
 ** \return  none
 ** \note 	 
*****************************************************************************/
void  ADC_EnableHardwareTrig(void);

/*****************************************************************************
 ** \brief	 ADC_DisableHardwareTrigger
 **			关闭硬件触发ADC
 ** \param [in] none
 ** \return  none
 ** \note 	 
*****************************************************************************/
void  ADC_DisableHardwareTrig(void);

/*****************************************************************************
 ** \brief	 ADC_ConfigHardwareTrig
 **			 配置硬件触发模式
 ** \param [in] ADCTGSource: ADC_TG_PWM0、ADC_TG_PWM2、ADC_TG_PWM4、ADC_TG_ADET
 **				TGMode：(1)ADC_TG_FALLING
 **						(2)ADC_TG_RISING
 **						(3)ADC_TG_PWM_PE
 ** \return  none
 ** \note 	 
*****************************************************************************/
void  ADC_ConfigHardwareTrig(uint8_t ADCTGSource, uint8_t TGMode);
/*****************************************************************************
 ** \brief	 ADC_SetTrigDelayTime
 **			配置硬件触发模式的延时时间
 ** \param [in]  TrigTime: 0~1023
 ** \return  none
 ** \note 	(TrigTime + 4)) *Tsys
*****************************************************************************/
void  ADC_SetTrigDelayTime(uint16_t TrigTime);

/*****************************************************************************
 ** \brief	 ADC_EnableChannel
 **			 使能ADC转换通道
 ** \param [in]  ADCChannel: ADC_CH_0 ..... ADC_CH_63
 ** \return  none
 ** \note 	
*****************************************************************************/
void  ADC_EnableChannel(uint8_t ADCChannel);

/*****************************************************************************
 ** \brief	 ADC_ConfigAN63
 **			 配置AN63通道
 ** \param [in]	An31Channel:（1）ADC_CH_63_BGR...ADC_CH_63_VDD
 ** \return  none
 ** \note 	
*****************************************************************************/
void  ADC_ConfigAN63(uint8_t An31Channel);

/*****************************************************************************
 ** \brief	 ADC_ConfigADCBrake
 **			 配置ADC比较极性 
 ** \param [in]  ADCBreak: (1)ADC_BRK_LESS_THAN_ADCMP 	: ADRES < ADCMP 触发
 **						   (2)ADC_BRK_NOT_LESS_THAN_ADCMP : ADRES >= ADCMP 触发 
 ** \return  none
 ** \note 
*****************************************************************************/
void  ADC_ConfigADCCMP(uint8_t ADCCMP);

/*****************************************************************************
 ** \brief	 ADC_ConfigCompareValue
 **			 配置ADC比较值
 ** \param [in]  ADCCompareValue: ADCMPH,ADCMPL
 ** \return  none
 ** \note 
*****************************************************************************/
void ADC_ConfigCompareValue(uint16_t ADCCompareValue);
/*****************************************************************************
 ** \brief	 ADC_GetCmpResult
 **			 获取ADC比较结果
 ** \param [in]  none
 ** \return   0/1
 ** \note 
*****************************************************************************/
uint8_t  ADC_GetCmpResult(void);

/*****************************************************************************
 ** \brief	 ADC_GetADCResult
 **			 获取ADC转换结果
 ** \param [in]  none
 ** \return  16bits ADC值
 ** \note 
*****************************************************************************/
uint16_t  ADC_GetADCResult(void);

/*****************************************************************************
 ** \brief	 ADC_EnableInt
 **			 开启ADC转换完成中断
 ** \param [in]  none
 ** \return  none
 ** \note 
*****************************************************************************/
void ADC_EnableInt(void);
/*****************************************************************************
 ** \brief	 ADC_DisableInt
 **			 关闭ADC转换完成中断
 ** \param [in]  none
 ** \return  none
 ** \note 
*****************************************************************************/
void ADC_DisableInt(void);
/*****************************************************************************
 ** \brief	 ADC_GetIntFlag
 **			 获取ADC转换完成中断标志位
 ** \param [in]  none
 ** \return  0：无中断，1：产生中断
 ** \note 
******************************************************************************/
uint8_t ADC_GetIntFlag(void);
/******************************************************************************
 ** \brief	 ADC_ClearIntFlag
 **			 清ADC转换完成中断标志位
 ** \param [in] none
 ** \return  none
 ** \note   
******************************************************************************/
void ADC_ClearIntFlag(void);

/*****************************************************************************
 ** \brief	 ADC_EnableLDO
 **			使能ADC的LDO
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void ADC_EnableLDO(void);
/*****************************************************************************
 ** \brief	 ADC_DisableLDO
 **			关闭ADC的LDO
 ** \param [in] none
 ** \return  none
 ** \note   
*****************************************************************************/
void ADC_DisableLDO(void);
/*****************************************************************************
 ** \brief	 ADC_ConfigADCVref
 **			 配置ADC的VREF
 ** \param [in] ADCVref :(1)ADC_VREF_1P2V :	Vref =1.2v
 **						 (2)ADC_VREF_2V	  : Vref =2v
 **						 (2)ADC_VREF_2P4V : Vref =2.4v
 **						 (2)ADC_VREF_3V	  : Vref =3v
 ** \return  none
 ** \note   
*****************************************************************************/
void ADC_ConfigADCVref(uint8_t ADCVref);

void ADC_Config(void);
uint16_t getAdcValue(uint8_t chn);

#endif /* __ADC_H__ */






