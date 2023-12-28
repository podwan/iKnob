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
/** \file system.c
**
**  
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "system.h"

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
 ** \brief	 SYS_ConfigSystemClk
 **			 配置系统时钟
 ** \param [in] SystemClkMode : (1)SYS_CLK_LSI:	内部低速时钟
 **								(2)SYS_CLK_LSE: 外部低速时钟
 **								(3)SYS_CLK_HSE: 外部高速时钟
 **								(4)SYS_CLK_HSI: 内部高速时钟
 ** \return  0:配置失败  1：配置成功
 ** \note	 
*****************************************************************************/
uint8_t SYS_ConfigSystemClk(uint8_t SystemClkMode)
{
	uint16_t WaitTime = 60000;
	uint8_t temp;
	temp = (SYS_SCKSEL_SEL_Msk | SystemClkMode);
	if (EA == 1)//操作TA时序时不允许被打断，因而需要关闭中断
	{
		EA = 0;		//在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		SCKSEL = temp;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		SCKSEL = temp;
	}		
	temp = temp | SYS_SCKSEL_WRITE_Msk;
	do{
		if(SCKSTAU & (1<< SystemClkMode))
		{
			if (EA == 1)//操作TA时序时不允许被打断，因而需要关闭中断
			{
				EA = 0;  //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
				_nop_();
				TA = 0xAA;
				TA = 0x55;
				SCKSEL = temp;
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				EA = 1;
			}
			else
			{
				TA = 0xAA;
				TA = 0x55;
				SCKSEL = temp;
				_nop_();
				_nop_();
				_nop_();
				_nop_();
				_nop_();
			}		
			return 1;
		}
	}
	while(WaitTime--);
	return 0;
}

/*****************************************************************************
 ** \brief	 SYS_EnableSoftwareReset
 **			 使能软件复位System
 ** \param [in] none
 ** \return none
 ** \note
 *****************************************************************************/
void SYS_EnableSoftwareReset(void)
{
	if (EA == 1)//操作TA时序时不允许被打断，因而需要关闭中断
	{
		EA = 0;   //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WDCON |= WDT_WDCON_SWRST_Msk;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WDCON |= WDT_WDCON_SWRST_Msk;
	}
}
/*****************************************************************************
 ** \brief	 SYS_DisableSoftwareReset
 **			 关闭软件复位System
 ** \param [in] none
 ** \return none
 ** \note
 *****************************************************************************/
void SYS_DisableSoftwareReset(void)
{
	if (EA == 1)//操作TA时序时不允许被打断，因而需要关闭中断
	{
		EA = 0;   //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WDCON &= ~(WDT_WDCON_SWRST_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WDCON &= ~(WDT_WDCON_SWRST_Msk);
	}
}

/*****************************************************************************
 ** \brief	 SYS_GetWDTResetFlag
 **			 获取WDT复位System的标志
 ** \param [in] none
 ** \return 0：复位不由WDT溢出引起    1：复位由WDT溢出引起
 ** \note
 *****************************************************************************/
uint8_t SYS_GetWDTResetFlag(void)
{
	return((WDCON & WDT_WDCON_WDTRF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 SYS_ClearWDTResetFlag
 **			 清除WDT复位System的标志
 ** \param [in] none
 ** \return   none
 ** \note
 *****************************************************************************/
void SYS_ClearWDTResetFlag(void)
{
	if (EA == 1)//操作TA时序时不允许被打断，因而需要关闭中断
	{
		EA = 0;   //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		WDCON &= ~(WDT_WDCON_WDTRF_Msk);
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		WDCON &= ~(WDT_WDCON_WDTRF_Msk);
	}	
}

/*****************************************************************************
 ** \brief	 SYS_GetPowerOnResetFlag
 **			 获取上电复位System的标志
 ** \param [in] none
 ** \return   0：复位不由上电复位引起    1：复位由上电复位引起
 ** \note
 *****************************************************************************/
uint8_t SYS_GetPowerOnResetFlag(void)
{
	return((WDCON & WDT_WDCON_PORF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 SYS_ClearPowerOnResetFlag
 **			 清除上电复位System的标志
 ** \param [in] none
 ** \return   none
 ** \note
 *****************************************************************************/
void SYS_ClearPowerOnResetFlag(void)
{
	WDCON &= ~(WDT_WDCON_PORF_Msk);	
}

/*****************************************************************************
 ** \brief	 SYS_GetEXTResetFlag
 **			 获取外部复位System的标志
 ** \param [in] none
 ** \return   0：复位不由外部复位引起    1：复位由外部复位引起
 ** \note
 *****************************************************************************/
uint8_t SYS_GetEXTResetFlag(void)
{
	return((WDCON & WDT_WDCON_EXTIF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 SYS_ClearEXTResetFlag
 **			 清除外部复位System的标志
 ** \param [in] none
 ** \return   none
 ** \note
 *****************************************************************************/
void SYS_ClearEXTResetFlag(void)
{
	WDCON &= ~(WDT_WDCON_EXTIF_Msk);	
}

/*****************************************************************************
 ** \brief	 SYS_GetConfigResetFlag
 **			 获取Config保护位复位System的标志
 ** \param [in] none
 ** \return   0：复位不由Config保护位复位引起    1：复位由Config保护位复位引起
 ** \note
 *****************************************************************************/
uint8_t SYS_GetConfigResetFlag(void)
{
	return((WDCON & WDT_WDCON_FIXIF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 SYS_ClearConfigResetFlag
 **			 清除Config保护位复位System的标志
 ** \param [in] none
 ** \return   none
 ** \note
 *****************************************************************************/
void SYS_ClearConfigResetFlag(void)
{
	WDCON &= ~(WDT_WDCON_FIXIF_Msk);	
}

/*****************************************************************************
 ** \brief	 SYS_GetWWDTResetFlag
 **			 获取WWDT溢出复位System的标志
 ** \param [in] none
 ** \return   0：复位不由WWDT溢出复位引起    1：复位由WWDT溢出复位引起
 ** \note
 *****************************************************************************/
uint8_t SYS_GetWWDTResetFlag(void)
{
	return((WWDTCON & WWDT_WWDTCON_WWDTRF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 SYS_ClearWWDTResetFlag
 **			 清除WWDT溢出复位System的标志
 ** \param [in] none
 ** \return   none
 ** \note
 *****************************************************************************/
void SYS_ClearWWDTResetFlag(void)
{
	WWDTCON &= ~(WWDT_WWDTCON_WWDTRF_Msk);	
}



/*****************************************************************************
 ** \brief	 SYS_EnableWakeUp
 **			 使能休眠唤醒
 ** \param [in] none
 ** \return none
 ** \note	 
 *****************************************************************************/
void SYS_EnableWakeUp(void)
{
	PCON |= SYS_PCON_SWE_Msk;
}
/*****************************************************************************
 ** \brief	 SYS_EnableWakeUp
 **			 关闭休眠唤醒
 ** \param [in] none
 ** \return none
 ** \note	
 *****************************************************************************/
void SYS_DisableWakeUp(void)
{
	PCON &= ~(SYS_PCON_SWE_Msk);
}

/*****************************************************************************
 ** \brief	 SYS_EnterStop
 **			 进入休眠中STOP状态
 ** \param [in] none
 ** \return none
 ** \note	
 *****************************************************************************/
void SYS_EnterStop(void)
{
	_nop_();
	_nop_();
	PCON |= SYS_PCON_STOP_Msk;
	_nop_();
	_nop_();	
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}
/*****************************************************************************
 ** \brief	 SYS_EnterIdle
 **			 进入休眠模式中Idle状态
 ** \param [in] none
 ** \return none
 ** \note   
 *****************************************************************************/
void SYS_EnterIdle(void)
{
	_nop_();
	_nop_();
	PCON |= SYS_PCON_IDLE_Msk;
	_nop_();
	_nop_();	
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}

/*****************************************************************************
 ** \brief	 SYS_EnableSCM
 **			 使能停振监测功能
 ** \param [in] none
 ** \return none
 ** \note   
 *****************************************************************************/
void SYS_EnableSCM(void)
{
	XT_SCM |= SYS_XTSCM_SCMEN_Msk;
}
/*****************************************************************************
 ** \brief	 SYS_DisableSCM
 **			 关闭停振监测功能
 ** \param [in] none
 ** \return none
 ** \note   
 *****************************************************************************/
void SYS_DisableSCM(void)
{
	XT_SCM &= ~(SYS_XTSCM_SCMEN_Msk);
}

/*****************************************************************************
 ** \brief	 SYS_EnableSCMInt
 **			 使能停振监测中断功能
 ** \param [in] none
 ** \return none
 ** \note   
 *****************************************************************************/
void SYS_EnableSCMInt(void)
{
	XT_SCM |= SYS_XTSCM_SCMIE_Msk;	
}
/*****************************************************************************
 ** \brief	 SYS_DisableSCMInt
 **			 关闭停振监测中断功能
 ** \param [in] none
 ** \return none
 ** \note   
 *****************************************************************************/
void SYS_DisableSCMInt(void)
{
	XT_SCM &= ~(SYS_XTSCM_SCMIE_Msk);
}
/*****************************************************************************
 ** \brief	 SYS_GetSCMIntFlag
 **			 获取停振监测中断标志位
 ** \param [in] none
 ** \return  0:无中断 1：有中断
 ** \note	 
*****************************************************************************/
uint8_t SYS_GetSCMIntFlag(void)
{
	return((XT_SCM & SYS_XTSCM_SCMIF_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 SYS_GetSCMState
 **			 获取停振监测状态位位
 ** \param [in] none
 ** \return  0:停振恢复 1：停振
 ** \note	 
*****************************************************************************/
uint8_t SYS_GetSCMState(void)
{
	return((XT_SCM & SYS_XTSCM_SCMSTA_Msk)? 1:0);
}
/*****************************************************************************
 ** \brief	 SYS_ClearSCMIntFlag
 **			 清除停振监测中断标志位
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SYS_ClearSCMIntFlag(void)
{
	XT_SCM &= ~(SYS_XTSCM_SCMIF_Msk);	
}


/*****************************************************************************
 ** \brief	 SYS_EnableLVD
 **			 开启电压监测功能
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SYS_EnableLVD(void)
{
	LVDCON |= LVD_LVDCON_LVDEN_Msk;
}
/*****************************************************************************
 ** \brief	 SYS_DisableLVD
 **			  关闭电压监测功能
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SYS_DisableLVD(void)
{
	LVDCON &= ~(LVD_LVDCON_LVDEN_Msk);	
}
/*****************************************************************************
  ** \brief	 SYS_ConfigLVD
 **			 配置系统电压监测电压
 ** \param [in] LVDValue :(1)SYS_LVD_2_0V		LVD电压监测点2.0V					
						(2)	SYS_LVD_2_2V		LVD电压监测点2.2V
						(3)	SYS_LVD_2_4V		LVD电压监测点2.4V
						(4)	SYS_LVD_2_7V		LVD电压监测点2.7V
						(5)	SYS_LVD_3_0V		LVD电压监测点3.0V
						(6)	SYS_LVD_3_7V		LVD电压监测点3.7V
						(7)	SYS_LVD_4_0V		LVD电压监测点4.0V
						(8)	SYS_LVD_4_3V		LVD电压监测点4.3V
 ** \return  none
 ** \note	 
*****************************************************************************/
void SYS_ConfigLVD(uint8_t LVDValue)
{
	LVDCON &= ~(LVD_LVDCON_LVDSEL_Msk);
	LVDCON |= LVDValue;	
}

/*****************************************************************************
 ** \brief	 SYS_EnableLVDInt
 **			 开启电压监测中断功能
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SYS_EnableLVDInt(void)
{
	LVDCON |= LVD_LVDCON_LVDINTE_Msk;	
}
/*****************************************************************************
 ** \brief	 SYS_DisableLVDInt
 **			  关闭电压监测中断功能
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SYS_DisableLVDInt(void)
{
	LVDCON &= ~(LVD_LVDCON_LVDINTE_Msk);	
}

/*****************************************************************************
 ** \brief	 SYS_GetLVDIntFlag
 **			 获取LVD中断标志位
 ** \param [in] none
 ** \return  0:无中断 1：有中断
 ** \note	 
*****************************************************************************/
uint8_t SYS_GetLVDIntFlag(void)
{
	return((LVDCON & LVD_LVDCON_LVDINTF_Msk)? 1:0);
}

/*****************************************************************************
 ** \brief	 SYS_ClearLVDIntFlag
 **			 清除LVD中断标志位
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void SYS_ClearLVDIntFlag(void)
{
	LVDCON	&= ~(LVD_LVDCON_LVDINTF_Msk);
}

