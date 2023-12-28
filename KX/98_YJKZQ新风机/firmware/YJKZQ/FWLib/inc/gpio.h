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
/** \file gpio.h
**
** 
**
** History:
** 
*****************************************************************************/
#ifndef __GPIO_H__
#define __GPIO_H__
/*****************************************************************************/
/* Include files */
/*****************************************************************************/
#include "cms80f761xx.h"
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define') */
/*****************************************************************************/
/*----------------------------------------------------------------------------
 **GPIO引脚
 ---------------------------------------------------------------------------*/
#define  GPIO_PIN_0_MSK				(0x01)		/* GPIO Pin 0 mask */
#define  GPIO_PIN_1_MSK				(0x02)		/* GPIO Pin 1 mask */
#define  GPIO_PIN_2_MSK				(0x04)		/* GPIO Pin 2 mask */
#define  GPIO_PIN_3_MSK				(0x08)		/* GPIO Pin 3 mask */
#define  GPIO_PIN_4_MSK				(0x10)		/* GPIO Pin 4 mask */
#define  GPIO_PIN_5_MSK				(0x20)		/* GPIO Pin 5 mask */
#define  GPIO_PIN_6_MSK				(0x40)		/* GPIO Pin 6 mask */
#define  GPIO_PIN_7_MSK				(0x80)		/* GPIO Pin 7 mask */

#define  GPIO_PIN_0					(0x00)		/* GPIO Pin 0 number*/
#define  GPIO_PIN_1					(0x01)		/* GPIO Pin 1 number */
#define  GPIO_PIN_2					(0x02)		/* GPIO Pin 2 number */
#define  GPIO_PIN_3					(0x03)		/* GPIO Pin 3 number */
#define  GPIO_PIN_4					(0x04)		/* GPIO Pin 4 number */
#define  GPIO_PIN_5					(0x05)		/* GPIO Pin 5 number */
#define  GPIO_PIN_6					(0x06)		/* GPIO Pin 6 number */
#define  GPIO_PIN_7					(0x07)		/* GPIO Pin 7 number */

#define  GPIO0						(0x00)
#define  GPIO1						(0x01)
#define  GPIO2						(0x02)
#define  GPIO3						(0x03)
#define  GPIO4						(0x04)
#define  GPIO5						(0x05)

#define  GPIO_P00					(0x00)
#define  GPIO_P01					(0x01)
#define  GPIO_P02					(0x02)
#define  GPIO_P03					(0x03)
#define  GPIO_P04					(0x04)
#define  GPIO_P05					(0x05)
#define  GPIO_P06					(0x06)
#define  GPIO_P07					(0x07)

#define  GPIO_P10					(0x10)
#define  GPIO_P11					(0x11)
#define  GPIO_P12					(0x12)
#define  GPIO_P13					(0x13)
#define  GPIO_P14					(0x14)
#define  GPIO_P15					(0x15)
#define  GPIO_P16					(0x16)
#define  GPIO_P17					(0x17)

#define  GPIO_P20					(0x20)
#define  GPIO_P21					(0x21)
#define  GPIO_P22					(0x22)
#define  GPIO_P23					(0x23)
#define  GPIO_P24					(0x24)
#define  GPIO_P25					(0x25)
#define  GPIO_P26					(0x26)
#define  GPIO_P27					(0x27)

#define  GPIO_P30					(0x30)
#define  GPIO_P31					(0x31)
#define  GPIO_P32					(0x32)
#define  GPIO_P33					(0x33)
#define  GPIO_P34					(0x34)
#define  GPIO_P35					(0x35)
#define  GPIO_P36					(0x36)
#define  GPIO_P37					(0x37)

#define  GPIO_P40					(0x40)
#define  GPIO_P41					(0x41)
#define  GPIO_P42					(0x42)
#define  GPIO_P43					(0x43)
#define  GPIO_P44					(0x44)
#define  GPIO_P45					(0x45)
#define  GPIO_P46					(0x46)
#define  GPIO_P47					(0x47)

#define  GPIO_P50					(0x50)
#define  GPIO_P51					(0x51)
#define  GPIO_P52					(0x52)
#define  GPIO_P53					(0x53)
#define  GPIO_P54					(0x54)
#define  GPIO_P55					(0x55)

/*----------------------------------------------------------------------------
 ** IO引脚复用模式
---------------------------------------------------------------------------*/
#define  GPIO_MUX_GPIO		(0x00)			/*GPIO功能*/

#define  GPIO_MUX_TXD1		(0x06)			/*TXD1功能*/
#define  GPIO_MUX_RXD1		(0x07)			/*RXD1功能*/

/*--GPIO数字功能---------------------------------------------------------*/
/*--Timer2比较器输出通道-----------------------------------------------*/
#define  GPIO_P00_MUX_CC0	(0x04)
#define  GPIO_P01_MUX_CC1	(0x04)
#define  GPIO_P02_MUX_CC2	(0x04)
#define  GPIO_P03_MUX_CC3	(0x04)

#define  GPIO_P10_MUX_CC0	(0x04)
#define  GPIO_P11_MUX_CC1	(0x04)
#define  GPIO_P12_MUX_CC2	(0x04)
#define  GPIO_P13_MUX_CC3	(0x04)

#define  GPIO_P20_MUX_CC0	(0x04)
#define  GPIO_P21_MUX_CC1	(0x04)
#define  GPIO_P22_MUX_CC2	(0x04)
#define  GPIO_P23_MUX_CC3	(0x04)

#define  GPIO_P30_MUX_CC0	(0x04)
#define  GPIO_P31_MUX_CC1	(0x04)
#define  GPIO_P32_MUX_CC2	(0x04)
#define  GPIO_P33_MUX_CC3	(0x04)

#define  GPIO_P40_MUX_CC0	(0x04)
#define  GPIO_P41_MUX_CC1	(0x04)
#define  GPIO_P42_MUX_CC2	(0x04)
#define  GPIO_P43_MUX_CC3	(0x04)

#define  GPIO_P50_MUX_CC0	(0x04)
#define  GPIO_P51_MUX_CC1	(0x04)
#define  GPIO_P52_MUX_CC2	(0x04)
#define  GPIO_P53_MUX_CC3	(0x04)

/*--蜂鸣器输出通道-----------------------------------------------------*/
#define  GPIO_P06_MUX_BUZZ	(0x04)
#define  GPIO_P16_MUX_BUZZ	(0x04)
#define  GPIO_P26_MUX_BUZZ	(0x04)
#define  GPIO_P36_MUX_BUZZ	(0x04)
#define  GPIO_P46_MUX_BUZZ	(0x04)

/*--系统时钟输出通道（系统时钟的64分频）（只需配置IO即可）---------------*/
#define  GPIO_P07_MUX_CLO	(0x04)
#define  GPIO_P17_MUX_CLO	(0x04)
#define  GPIO_P27_MUX_CLO	(0x04)
#define  GPIO_P37_MUX_CLO	(0x04)
#define  GPIO_P47_MUX_CLO	(0x04)

/*--I2C通道----------------------------------------------------------*/
#define  GPIO_P04_MUX_SCL	(0x04)
#define  GPIO_P05_MUX_SDA	(0x04)

#define  GPIO_P14_MUX_SCL	(0x04)
#define  GPIO_P15_MUX_SDA	(0x04)

#define  GPIO_P24_MUX_SCL	(0x04)
#define  GPIO_P25_MUX_SDA	(0x04)

#define  GPIO_P34_MUX_SCL	(0x04)
#define  GPIO_P35_MUX_SDA	(0x04)

#define  GPIO_P44_MUX_SCL	(0x04)
#define  GPIO_P45_MUX_SDA	(0x04)

#define  GPIO_P54_MUX_SCL	(0x04)
#define  GPIO_P55_MUX_SDA	(0x04)

/*--串口通道-------------------------------------------------------------*/
#define  GPIO_P00_MUX_RXD2	(0x02)
#define  GPIO_P01_MUX_TXD2	(0x02)


#define  GPIO_P14_MUX_RXD0	(0x02)
#define  GPIO_P15_MUX_TXD0	(0x02)

#define  GPIO_P24_MUX_RXD0	(0x02)
#define  GPIO_P25_MUX_TXD0	(0x02)

#define  GPIO_P30_MUX_RXD0	(0x02)
#define  GPIO_P31_MUX_TXD0	(0x02)

#define  GPIO_P40_MUX_RXD0	(0x02)
#define  GPIO_P41_MUX_TXD0	(0x02)

#define  GPIO_P50_MUX_RXD0	(0x02)
#define  GPIO_P51_MUX_TXD0	(0x02)

/*--SPI通道-------------------------------------------------------------*/
#define  GPIO_P00_MUX_SCLK	(0x03)
#define  GPIO_P01_MUX_MOSI	(0x03)
#define  GPIO_P02_MUX_MISO	(0x03)
#define  GPIO_P03_MUX_NSS	(0x03)
#define  GPIO_P04_MUX_NSS	(0x03)
#define  GPIO_P05_MUX_NSS	(0x03)
#define  GPIO_P06_MUX_NSS	(0x03)

#define  GPIO_P03_MUX_NSSO0	(0x03)
#define  GPIO_P04_MUX_NSSO1	(0x03)
#define  GPIO_P05_MUX_NSSO2	(0x03)
#define  GPIO_P06_MUX_NSSO3	(0x03)


#define  GPIO_P10_MUX_SCLK	(0x03)
#define  GPIO_P11_MUX_MOSI	(0x03)
#define  GPIO_P12_MUX_MISO	(0x03)
#define  GPIO_P13_MUX_NSS	(0x03)
#define  GPIO_P14_MUX_NSS	(0x03)
#define  GPIO_P15_MUX_NSS	(0x03)
#define  GPIO_P16_MUX_NSS	(0x03)

#define  GPIO_P13_MUX_NSSO0	(0x03)
#define  GPIO_P14_MUX_NSSO1	(0x03)
#define  GPIO_P15_MUX_NSSO2	(0x03)
#define  GPIO_P16_MUX_NSSO3	(0x03)

#define  GPIO_P20_MUX_SCLK	(0x03)
#define  GPIO_P21_MUX_MOSI	(0x03)
#define  GPIO_P22_MUX_MISO	(0x03)
#define  GPIO_P23_MUX_NSS	(0x03)
#define  GPIO_P24_MUX_NSS	(0x03)
#define  GPIO_P25_MUX_NSS	(0x03)
#define  GPIO_P26_MUX_NSS	(0x03)

#define  GPIO_P23_MUX_NSSO0	(0x03)
#define  GPIO_P24_MUX_NSSO1	(0x03)
#define  GPIO_P25_MUX_NSSO2	(0x03)
#define  GPIO_P26_MUX_NSSO3	(0x03)


#define  GPIO_P32_MUX_SCLK	(0x03)
#define  GPIO_P33_MUX_MOSI	(0x03)
#define  GPIO_P34_MUX_MISO	(0x03)
#define  GPIO_P35_MUX_NSS	(0x03)
#define  GPIO_P36_MUX_NSS	(0x03)
#define  GPIO_P37_MUX_NSS	(0x03)

#define  GPIO_P35_MUX_NSSO0	(0x03)
#define  GPIO_P36_MUX_NSSO1	(0x03)
#define  GPIO_P37_MUX_NSSO2	(0x03)

#define  GPIO_P40_MUX_SCLK	(0x03)
#define  GPIO_P41_MUX_MOSI	(0x03)
#define  GPIO_P42_MUX_MISO	(0x03)
#define  GPIO_P43_MUX_NSS	(0x03)
#define  GPIO_P44_MUX_NSS	(0x03)
#define  GPIO_P45_MUX_NSS	(0x03)
#define  GPIO_P46_MUX_NSS	(0x03)

#define  GPIO_P43_MUX_NSSO0	(0x03)
#define  GPIO_P44_MUX_NSSO1	(0x03)
#define  GPIO_P45_MUX_NSSO2	(0x03)
#define  GPIO_P46_MUX_NSSO3	(0x03)

#define  GPIO_P50_MUX_SCLK	(0x03)
#define  GPIO_P51_MUX_MOSI	(0x03)
#define  GPIO_P52_MUX_MISO	(0x03)
#define  GPIO_P53_MUX_NSS	(0x03)
#define  GPIO_P54_MUX_NSS	(0x03)
#define  GPIO_P55_MUX_NSS	(0x03)

#define  GPIO_P53_MUX_NSSO0	(0x03)
#define  GPIO_P54_MUX_NSSO1	(0x03)
#define  GPIO_P55_MUX_NSSO2	(0x03)


/*--PWM通道----------------------------------------------------------*/
#define  GPIO_P04_MUX_PG0	(0x05)
#define  GPIO_P05_MUX_PG1	(0x05)

#define  GPIO_P06_MUX_PG0	(0x05)
#define  GPIO_P07_MUX_PG1	(0x05)

#define  GPIO_P12_MUX_PG0	(0x05)
#define  GPIO_P13_MUX_PG1	(0x05)
#define  GPIO_P14_MUX_PG2	(0x05)
#define  GPIO_P15_MUX_PG3	(0x05)
#define  GPIO_P16_MUX_PG4	(0x05)
#define  GPIO_P17_MUX_PG5	(0x05)

#define  GPIO_P22_MUX_PG0	(0x05)
#define  GPIO_P23_MUX_PG1	(0x05)
#define  GPIO_P24_MUX_PG2	(0x05)
#define  GPIO_P25_MUX_PG3	(0x05)
#define  GPIO_P26_MUX_PG4	(0x05)
#define  GPIO_P27_MUX_PG5	(0x05)

#define  GPIO_P32_MUX_PG0	(0x05)
#define  GPIO_P33_MUX_PG1	(0x05)
#define  GPIO_P34_MUX_PG2	(0x05)
#define  GPIO_P35_MUX_PG3	(0x05)
#define  GPIO_P36_MUX_PG4	(0x05)
#define  GPIO_P37_MUX_PG5	(0x05)

#define  GPIO_P42_MUX_PG0	(0x05)
#define  GPIO_P43_MUX_PG1	(0x05)
#define  GPIO_P44_MUX_PG2	(0x05)
#define  GPIO_P45_MUX_PG3	(0x05)
#define  GPIO_P46_MUX_PG4	(0x05)
#define  GPIO_P47_MUX_PG5	(0x05)

#define  GPIO_P50_MUX_PG0	(0x05)
#define  GPIO_P51_MUX_PG1	(0x05)
#define  GPIO_P52_MUX_PG2	(0x05)
#define  GPIO_P53_MUX_PG3	(0x05)
#define  GPIO_P54_MUX_PG4	(0x05)
#define  GPIO_P55_MUX_PG5	(0x05)

/*--Timer2捕获通道（只适用于PS_CAPn寄存器赋值）--------------------------------*/
#define  GPIO_P14_MUX_CAP0	(0x14)		/*PS_CAP0寄存器*/
#define  GPIO_P15_MUX_CAP1	(0x15)		/*PS_CAP1寄存器*/
#define  GPIO_P16_MUX_CAP2	(0x16)		/*PS_CAP2寄存器*/
#define  GPIO_P17_MUX_CAP3	(0x17)		/*PS_CAP3寄存器*/

#define  GPIO_P34_MUX_CAP0	(0x34)		/*PS_CAP0寄存器*/
#define  GPIO_P35_MUX_CAP1	(0x35)		/*PS_CAP1寄存器*/
#define  GPIO_P36_MUX_CAP2	(0x36)		/*PS_CAP2寄存器*/
#define  GPIO_P37_MUX_CAP3	(0x37)		/*PS_CAP3寄存器*/


/*--Timer0门控输入（只适用于PS_T0G寄存器赋值）--------------------------------*/
#define  GPIO_P02_MUX_T0G	(0x02)
#define  GPIO_P12_MUX_T0G	(0x12)
#define  GPIO_P22_MUX_T0G	(0x22)
#define  GPIO_P32_MUX_T0G	(0x32)
#define  GPIO_P42_MUX_T0G	(0x42)

/*--Timer0外部时钟输入（只适用于PS_T0寄存器赋值）----------------------------*/
#define  GPIO_P03_MUX_T0	(0x03)
#define  GPIO_P13_MUX_T0	(0x13)
#define  GPIO_P23_MUX_T0	(0x23)
#define  GPIO_P33_MUX_T0	(0x33)
#define  GPIO_P43_MUX_T0	(0x43)

/*--Timer1门控输入（只适用于PS_T1G寄存器赋值）--------------------------------*/
#define  GPIO_P02_MUX_T1G	(0x02)
#define  GPIO_P12_MUX_T1G	(0x12)
#define  GPIO_P22_MUX_T1G	(0x22)
#define  GPIO_P32_MUX_T1G	(0x32)
#define  GPIO_P42_MUX_T1G	(0x42)

/*--Timer1外部时钟输入（只适用于PS_T1寄存器赋值）----------------------------*/
#define  GPIO_P03_MUX_T1	(0x03)
#define  GPIO_P13_MUX_T1	(0x13)
#define  GPIO_P23_MUX_T1	(0x23)
#define  GPIO_P33_MUX_T1	(0x33)
#define  GPIO_P43_MUX_T1	(0x43)

/*--Timer2 外部加载输入（只适用于PS_T2EX寄存器赋值）--------------------------*/
#define  GPIO_P02_MUX_T2EX	(0x02)
#define  GPIO_P12_MUX_T2EX	(0x12)
#define  GPIO_P22_MUX_T2EX	(0x22)
#define  GPIO_P32_MUX_T2EX	(0x32)
#define  GPIO_P42_MUX_T2EX	(0x42)

/*--Timer2外部输入或门控输入（只适用于PS_T2寄存器赋值）-----------------------*/
#define  GPIO_P03_MUX_T2	(0x03)
#define  GPIO_P13_MUX_T2	(0x13)
#define  GPIO_P23_MUX_T2	(0x23)
#define  GPIO_P33_MUX_T2	(0x33)
#define  GPIO_P43_MUX_T2	(0x43)

/*--ADC 硬件触发引脚（只适用于PS_ADET寄存器赋值）-----------------------------*/
#define  GPIO_P06_MUX_ADET	(0x06)
#define  GPIO_P26_MUX_ADET	(0x26)
#define  GPIO_P46_MUX_ADET	(0x46)

/*--外部中断0引脚（只适用于PS_INT0寄存器赋值）-----------------------------*/
#define  GPIO_P06_MUX_INT0	(0x06)
#define  GPIO_P07_MUX_INT0	(0x07)
#define  GPIO_P26_MUX_INT0	(0x26)
#define  GPIO_P27_MUX_INT0	(0x27)
#define  GPIO_P46_MUX_INT0	(0x46)
#define  GPIO_P47_MUX_INT0	(0x47)

/*--外部中断1引脚（只适用于PS_INT1寄存器赋值）-----------------------------*/
#define  GPIO_P07_MUX_INT1	(0x07)
#define  GPIO_P27_MUX_INT1	(0x27)
#define  GPIO_P47_MUX_INT1	(0x47)

/*--ANALOG功能--------------------------------------------------------------*/
#define  GPIO_MUX_ANA		(0x01)			/*模拟功能(GPIO数字功能关闭)*/
/*----ADC输入通道-----------------------------------------------------------*/
#define  GPIO_P00_MUX_AN0	(0x01)
#define  GPIO_P01_MUX_AN1	(0x01)
#define  GPIO_P02_MUX_AN2	(0x01)
#define  GPIO_P03_MUX_AN3	(0x01)
#define  GPIO_P04_MUX_AN4	(0x01)
#define  GPIO_P05_MUX_AN5	(0x01)
#define  GPIO_P06_MUX_AN6	(0x01)
#define  GPIO_P07_MUX_AN7	(0x01)

#define  GPIO_P10_MUX_AN8	(0x01)
#define  GPIO_P11_MUX_AN9	(0x01)
#define  GPIO_P12_MUX_AN10	(0x01)
#define  GPIO_P13_MUX_AN11	(0x01)
#define  GPIO_P14_MUX_AN12	(0x01)
#define  GPIO_P15_MUX_AN13	(0x01)
#define  GPIO_P16_MUX_AN14	(0x01)
#define  GPIO_P17_MUX_AN15	(0x01)

#define  GPIO_P20_MUX_AN16	(0x01)
#define  GPIO_P21_MUX_AN17	(0x01)
#define  GPIO_P22_MUX_AN18	(0x01)
#define  GPIO_P23_MUX_AN19	(0x01)
#define  GPIO_P24_MUX_AN20	(0x01)
#define  GPIO_P25_MUX_AN21	(0x01)
#define  GPIO_P26_MUX_AN22	(0x01)
#define  GPIO_P27_MUX_AN23	(0x01)

#define  GPIO_P30_MUX_AN24	(0x01)
#define  GPIO_P31_MUX_AN25	(0x01)
#define  GPIO_P32_MUX_AN26	(0x01)
#define  GPIO_P33_MUX_AN27	(0x01)
#define  GPIO_P34_MUX_AN28	(0x01)
#define  GPIO_P35_MUX_AN29	(0x01)
#define  GPIO_P36_MUX_AN30	(0x01)
#define  GPIO_P37_MUX_AN31	(0x01)

#define  GPIO_P40_MUX_AN32	(0x01)
#define  GPIO_P41_MUX_AN33	(0x01)
#define  GPIO_P42_MUX_AN34	(0x01)
#define  GPIO_P43_MUX_AN35	(0x01)
#define  GPIO_P44_MUX_AN36	(0x01)
#define  GPIO_P45_MUX_AN37	(0x01)
#define  GPIO_P46_MUX_AN38	(0x01)
#define  GPIO_P47_MUX_AN39	(0x01)

#define  GPIO_P50_MUX_AN40	(0x01)
#define  GPIO_P51_MUX_AN41	(0x01)
#define  GPIO_P52_MUX_AN42	(0x01)
#define  GPIO_P53_MUX_AN43	(0x01)
#define  GPIO_P54_MUX_AN44	(0x01)
#define  GPIO_P55_MUX_AN45	(0x01)

/********************************************************************************
 ** \brief	 GPIO_SET_MUX_MODE
 **			 设置IO口的复用功能
 ** \param [in] PorttCFG ：IO口的复用寄存器 P00CFG.....
 **            PinMode ：IO口的复用功能 
 ** \return  none
********************************************************************************/
#define  GPIO_SET_MUX_MODE(PortCFG,PinMode)		(PortCFG = PinMode)	

/********************************************************************************
 ** \brief	 GPIO_SET_PS_MODE
 **			 设置端口输入功能分配
 ** \param [in]  Ps_mode；PS_INT0、PS_INT1..... PS_RXD1
 **				 gpio:	(1)GPIO_P00 .... GPIO_P55
 **						(2)GPIO_P02_MUX_T0G....GPIO_P47_MUX_INT1
 ** \return  none
********************************************************************************/
#define  GPIO_SET_PS_MODE(Ps_mode,gpio)		(Ps_mode = gpio)	


/********************************************************************************
 ** \brief	 GPIO_ENABLE_OUTPUT
 **			 使能GPIO为输出模式
 ** \param [in] PortTRIS ：方向寄存器 P0TRIS,P1TRIS,P2TRIS,P3TRIS,P4TRIS,P5TRIS  
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define	 GPIO_ENABLE_OUTPUT(PortTRIS, PinNum)	(PortTRIS |= (1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_INPUT
 **			 使能GPIO为三态输入模式
 ** \param [in] PortTRIS ：方向寄存器 P0TRIS,P1TRIS,P2TRIS,P3TRIS,P4TRIS,P5TRIS 
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_INPUT(PortTRIS, PinNum)	(PortTRIS &= ~(1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_OD
 **			 GPIO开漏功能开启
 ** \param [in] PortOD  :开漏功能寄存器：P0OD,P1OD,P2OD,P3OD,P4OD,P5OD
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_OD(PortOD, PinNum)			(PortOD |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_OD
 **			 GPIO开漏功能关闭
 ** \param [in] PortOD  :开漏功能寄存器：P0OD,P1OD,P2OD,P3OD,P4OD,P5OD
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_OD(PortOD, PinNum)		(PortOD &= ~(1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_UP
 **			 GPIO上拉功能开启
 ** \param [in] PortUP  :上拉功能寄存器：P0UP,P1UP,P2UP,P3UP,P4UP,P5UP
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_UP(PortUP, PinNum)			(PortUP |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_UP
 **			 GPIO上拉功能关闭
 ** \param [in] PortUP  :上拉功能寄存器：P0UP,P1UP,P2UP,P3UP,P4UP,P5UP
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_UP(PortUP, PinNum)		(PortUP &= ~(1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_ENABLE_RD
 **			 GPIO下拉功能开启
 ** \param [in] PortRD  :下拉功能寄存器：P0RD,P1RD,P2RD,P3RD,P4RD,P5RD
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_RD(PortRD, PinNum)			(PortRD |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_RD
 **			 GPIO下拉功能关闭
 ** \param [in] PortRD  :下拉功能寄存器：P0RD,P1RD,P2RD,P3RD,P4RD,P5RD
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_RD(PortRD, PinNum)		(PortRD &= ~(1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_ENABLE_SR
 **			 GPIO慢斜率功能开启
 ** \param [in] PortSR  :斜率控制功能寄存器：P0SR,P1SR,P2SR,P3SR,P4SR,P5SR
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_SR(PortSR, PinNum)      (PortSR |= (1<<PinNum))
/********************************************************************************
 ** \brief	 GPIO_DISABLE_SR
 **			 GPIO 慢斜率功能关闭
 ** \param [in] PortSR  :斜率控制功能寄存器：P0SR,P1SR,P2SR,P3SR,P4SR,P5SR
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_SR(PortSR, PinNum)     (PortSR &= ~(1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_SET_DS
 **			 置位数据输入选择寄存器
 ** \param [in] PortDS  :数据输入选择寄存器：P0DS,P1DS,P2DS,P3DS,P4DS,P5DS
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define GPIO_SET_DS(PortDS, PinNum)			(PortDS |= (1<<PinNum))

/********************************************************************************
 ** \brief	 GPIO_CLR_DS
			清零数据输入选择寄存器
 ** \param [in] PortDS  :数据输入选择寄存器：P0DS,P1DS,P2DS,P3DS,P4DS,P5DS
 **            PinNum：GPIO_PIN_0...GPIO_PIN_7
 ** \return  none
 ******************************************************************************/
#define GPIO_CLR_DS(PortDS, PinNum)			(PortDS &= ~(1<<PinNum))

/*----------------------------------------------------------------------------
 **GPIO 引脚中断触发模式
/*---------------------------------------------------------------------------*/
#define  GPIO_INT_RISING	(0x01)			/*上升沿触发中断*/
#define  GPIO_INT_FALLING	(0x02)			/*下降沿触发中断*/
#define  GPIO_INT_BOTH_EDGE	(0x03)			/*上升、下降沿均触发中断*/

/********************************************************************************
 ** \brief	 GPIO_SET_INT_MODE
 **			 设置IO口的外部中断功能
 ** \param [in] PorttEICFG ：IO口的外部中断模式配置寄存器
 **            PinIntMode ：IO口的复用功能 
 ** \return  none
 ******************************************************************************/
#define  GPIO_SET_INT_MODE(PortEICFG, PinIntMode)	(PortEICFG = PinIntMode)

/********************************************************************************
 ** \brief	 GPIO_ENABLE_INT_MODE
 **			使能IO口的外部中断功能
 ** \param [in] PorttEXTIE ：IO口的外部中断寄存器
 **            PinMSK：GPIO_PIN_0_MSK .. GPIO_PIN_7_MSK
 ** \return  none
 ******************************************************************************/
#define  GPIO_ENABLE_INT_MODE(PortEXTIE,PinMSK)		(PortEXTIE |= PinMSK)	

/********************************************************************************
 ** \brief	 GPIO_DISABLE_INT_MODE
 **			关闭IO口的外部中断功能
 ** \param [in] PorttEXTIE ：IO口的外部中断寄存器
 **            PinMSK: GPIO_PIN_0_MSK .. GPIO_PIN_7_MSK
 ** \return  none
 ******************************************************************************/
#define  GPIO_DISABLE_INT_MODE(PortEXTIE,PinMSK)	(PortEXTIE &= ~PinMSK)	

/*****************************************************************************/
/* Global type definitions ('typedef') */
/*****************************************************************************/


/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source) */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source) */
/*****************************************************************************/

 /********************************************************************************
 ** \brief	 GPIO_EnableInt
 **			 使能IO口的中断功能
 ** \param [in] Port  ： GPIO0、GPIO1、GPIO2、GPIO3、GPIO4、GPIO5
 **			    PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK			 
 ** \return  none
 ** \note   
 ******************************************************************************/
void GPIO_EnableInt(uint8_t Port, uint8_t PinMSK);
/********************************************************************************
 ** \brief	 GPIO_DisableInt
 **			 关闭IO口的中断功能
 ** \param [in] Port  ： GPIO0、GPIO1、GPIO2、GPIO3、GPIO4、GPIO5
 **			    PinMSK: GPIO_PIN_0_MSK ~ GPIO_PIN_7_MSK			 
 ** \return  none
 ** \note   
 ******************************************************************************/
void GPIO_DisableInt(uint8_t Port, uint8_t PinMSK);

 /******************************************************************************
 ** \brief	 GPIO_GetIntFlag
 **			 获取中断标志
 ** \param [in] Port  ： GPIO0、GPIO1、GPIO2、GPIO3、GPIO4、GPIO5
 **			    PinNum:  GPIO_PIN_0~GPIO_PIN_7 		 
 ** \return  0：无中断产生
 **			 1：有中断产生
 ** \note  
 ******************************************************************************/
uint8_t  GPIO_GetIntFlag(uint8_t Port, uint8_t PinNum);
 /********************************************************************************
 ** \brief	 GPIO_ClearIntFlag
 **			清除中断标志位
 ** \param [in] Port  ： GPIO0、GPIO1、GPIO2、GPIO3、GPIO4、GPIO5
 **			    PinNum:  GPIO_PIN_0~GPIO_PIN_7 		 
 ** \return  none
 ** \note  
 ******************************************************************************/
void GPIO_ClearIntFlag(uint8_t Port, uint8_t PinNum);

#endif /* __GPIO_H__ */






