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
/** \file adc.c
**
**
**
**	History:
**
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "adc.h"
#include "gpio.h"
/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/

/****************************************************************************/
/*	Local type definitions('typedef')
*****************************************************************************/

/****************************************************************************/
/*	Local variable  definitions('static')
*****************************************************************************/

/****************************************************************************/
/*	Local function prototypes('static')
*****************************************************************************/

/****************************************************************************/
/*	Function implementation - global ('extern') and local('static')
*****************************************************************************/

/*****************************************************************************
 ** \brief	 ADC_Start
 ** \param [in] none
 ** \return  none
 *****************************************************************************/
void ADC_Start(void)
{
	ADCON1 |= ADC_ADCON1_ADEN_Msk;
}
/*****************************************************************************
 ** \brief	 ADC_Stop
 ** \param [in] none
 ** \return  none
 *****************************************************************************/
void ADC_Stop(void)
{
	ADCON1 &= ~(ADC_ADCON1_ADEN_Msk);
}

/*****************************************************************************
 ** \brief	 ADC_ConfigRunMode
 **			  配置ADC的运行模式
 ** \param [in] ADCClkDiv: ADC_CLK_DIV_2 ~ ADC_CLK_DIV_256
 **          	ADCResultTpye: (1)ADC_RESULT_LEFT    左对齐
 **							   (2)ADC_RESULT_RIGHT   右对齐
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_ConfigRunMode(uint8_t ADCClkDiv, uint8_t ADCResultTpye)
{
	ADCON0 &= ~(ADC_ADCON0_ADFM_Msk);
	ADCON0 |= ADCResultTpye;

	ADCON1 &= ~(ADC_ADCON1_ADCKS_Msk);
	ADCON1 |= (ADCClkDiv << ADC_ADCON1_ADCKS_Pos);
}

/*****************************************************************************
 ** \brief	 ADC_EnableHardwareTrig
 **			使能硬件触发ADC
 ** \param [in] none
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_EnableHardwareTrig(void)
{
	ADCON2 |= (ADC_ADCON2_ADCEX_Msk);
}
/*****************************************************************************
 ** \brief	 ADC_DisableHardwareTrig
 **			 关闭硬件触发ADC
 ** \param [in] none
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_DisableHardwareTrig(void)
{
	ADCON2 &= ~(ADC_ADCON2_ADCEX_Msk);
}
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
void ADC_ConfigHardwareTrig(uint8_t ADCTGSource, uint8_t TGMode)
{
	ADCON2 &= ~(ADC_ADCON2_ADTGS_Msk | ADC_ADCON2_ADEGS_Msk);
	ADCON2 |= (ADCTGSource << ADC_ADCON2_ADTGS_Pos) | (TGMode << ADC_ADCON2_ADEGS_Pos);
}

/*****************************************************************************
 ** \brief	 ADC_EnableChannel
 **			 使能ADC转换通道
 ** \param [in]  ADCChannel: ADC_CH_0 ..... ADC_CH_63
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_EnableChannel(uint8_t ADCChannel)
{
	ADCCHS = ADCChannel;
}

/*****************************************************************************
 ** \brief	 ADC_ConfigAN63
 **			 配置AN63通道
 ** \param [in]	An31Channel:（1）ADC_CH_63_BGR...ADC_CH_63_VDD
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_ConfigAN63(uint8_t An63Channel)
{
	ADCON0 &= ~(ADC_ADCON0_ANACH_Msk);
	ADCON0 |= (An63Channel << ADC_ADCON0_ANACH_Pos);
}

/*****************************************************************************
 ** \brief	 ADC_SetTrigDelayTime
 **			 配置硬件触发模式的延时时间
 ** \param [in]  TrigTime: 0~1023
 ** \return  none
 ** \note 	(TrigTime + 4)) *Tsys
 *****************************************************************************/
void ADC_SetTrigDelayTime(uint16_t TrigTime)
{
	ADDLYL = TrigTime;
	ADCMPC &= ~(ADC_ADCMPC_ADDLY_Msk);
	ADCMPC |= ADC_ADCMPC_ADDLY_Msk & (TrigTime >> 8);
}

/*****************************************************************************
 ** \brief	 ADC_ConfigADCBrake
 **			 配置ADC比较极性
 ** \param [in]  ADCBreak: (1)ADC_BRK_LESS_THAN_ADCMP 	: ADRES < ADCMP 触发
 **						   (2)ADC_BRK_NOT_LESS_THAN_ADCMP : ADRES >= ADCMP 触发
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_ConfigADCCMP(uint8_t ADCCMP)
{
	ADCMPC &= ~(ADC_ADCMPC_ADCMPPS_Msk);
	ADCMPC |= ADCCMP;
}

/*****************************************************************************
 ** \brief	 ADC_ConfigCompareValue
 **			 配置ADC比较值
 ** \param [in]  ADCCompareValue: ADCMPH,ADCMPL
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_ConfigCompareValue(uint16_t ADCCompareValue)
{
	ADCMPL = ADCCompareValue & 0xF;
	ADCMPH = ADCCompareValue >> 4;
}

/*****************************************************************************
 ** \brief	 ADC_GetCmpResult
 **			 获取ADC比较结果
 ** \param [in]  none
 ** \return   0/1
 ** \note
 *****************************************************************************/
uint8_t ADC_GetCmpResult(void)
{
	return ((ADCMPC & ADC_ADCMPC_ADCMPO_Msk) ? 1 : 0);
}

/*****************************************************************************
 ** \brief	 ADC_GetADCResult
 **			 获取ADC转换结果
 ** \param [in]  none
 ** \return  16bits ADC值
 ** \note
 *****************************************************************************/
uint16_t ADC_GetADCResult(void)
{
	if (!(ADCON0 & ADC_ADCON0_ADFM_Msk)) /*左对齐*/
	{
		return (0xfff & (((ADRESH << 4) | (ADRESL >> 4))));
	}
	return (0xfff & ((ADRESH << 8) | ADRESL));
}

/*****************************************************************************
 ** \brief	 ADC_EnableInt
 **			 开启ADC转换完成中断
 ** \param [in]  none
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_EnableInt(void)
{
	EIE2 |= IRQ_EIE2_ADCIE_Msk;
}
/*****************************************************************************
 ** \brief	 ADC_DisableInt
 **			 关闭ADC转换完成中断
 ** \param [in]  none
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_DisableInt(void)
{
	EIE2 &= ~(IRQ_EIE2_ADCIE_Msk);
}
/*****************************************************************************
 ** \brief	 ADC_GetIntFlag
 **			 获取ADC转换完成中断标志位
 ** \param [in]  none
 ** \return  0：无中断，1：产生中断
 ** \note
 *****************************************************************************/
uint8_t ADC_GetIntFlag(void)
{
	return ((EIF2 & IRQ_EIF2_ADCIF_Msk) ? 1 : 0);
}
/*****************************************************************************
 ** \brief	 ADC_ClearIntFlag
 **			 清ADC转换完成中断标志位
 ** \param [in] none
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_ClearIntFlag(void)
{
	EIF2 = 0xFF & (~(IRQ_EIF2_ADCIF_Msk));
}

/*****************************************************************************
 ** \brief	 ADC_EnableLDO
 **			使能ADC的LDO
 ** \param [in] none
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_EnableLDO(void)
{
	ADCLDO |= ADC_ADCLDO_LDOEN_Msk;
}
/*****************************************************************************
 ** \brief	 ADC_DisableLDO
 **			关闭ADC的LDO
 ** \param [in] none
 ** \return  none
 ** \note
 *****************************************************************************/
void ADC_DisableLDO(void)
{
	ADCLDO &= ~(ADC_ADCLDO_LDOEN_Msk);
}
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
void ADC_ConfigADCVref(uint8_t ADCVref)
{
	ADCLDO &= ~(ADC_ADCLDO_VSEL_Msk);
	ADCLDO |= ADCVref;
}

void ADC_Config(void)
{
	// 设置ADC的运行模式
	ADC_ConfigRunMode(ADC_CLK_DIV_128, ADC_RESULT_LEFT); // 设置ADC时钟为系统时钟的128分频，ADC结果为左对齐，如有对ADC时钟有操作请参考"中微8051芯片ADC模块应用笔记"

	// 设置ADC转换通道
	//  ADC_EnableChannel(ADC_CH_0);
	GPIO_SET_MUX_MODE(P00CFG, GPIO_P00_MUX_AN0);

	// 设置ADC LDO   禁止LDO 参考VDD
	//  ADC_EnableLDO();
	//  ADC_ConfigADCVref(ADC_VREF_3V);		//ADC_VREF_1P2V, ADC_VREF_2V, ADC_VREF_2P4V, ADC_VREF_3V

	// 设置ADC中断
	// ADC_EnableInt();
	// IRQ_SET_PRIORITY(IRQ_ADC, IRQ_PRIORITY_HIGH);
	// IRQ_ALL_ENABLE();

	// 开启ADC
	ADC_Start();
}

uint16_t getAdcValue(uint8_t chn)
{

	ADC_EnableChannel(chn);

	ADC_GO();

	while (ADC_IS_BUSY)
		;
	return ADC_GetADCResult();
}