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
/** \file CheckTouchKey_Set_80F73xx.c
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
#include "CheckTouchKey_Set.h"
/****************************************************************************/
/*	Local pre-processor symbols('#define')
*****************************************************************************/

/****************************************************************************/
/*	Global variable definitions(declared in header file with 'extern')
*****************************************************************************/
//检测通道设定
unsigned char code Table_KeyChannel[C_KEY_TOTAL] = {
#if	((C_KEY_TOTAL-0)	>	0)//CCKEY1_USER
	C_KEY1_CH,	//按键1对应触摸通道 	
#endif			
#if	((C_KEY_TOTAL-1)>	0)//CCKEY2_USER	
	C_KEY2_CH,	//按键2对应触摸通道 	
#endif			
#if	((C_KEY_TOTAL-2)>	0)//CCKEY3_USER	
	C_KEY3_CH,			
#endif			
#if	((C_KEY_TOTAL-3)>	0)//CCKEY4_USER	
	C_KEY4_CH,			
#endif			
#if	((C_KEY_TOTAL-4)>	0)//CCKEY5_USER	
	C_KEY5_CH,			
#endif			
#if	((C_KEY_TOTAL-5)>	0)//CCKEY6_USER	
	C_KEY6_CH,			
#endif			
#if	((C_KEY_TOTAL-6)>	0)//CCKEY7_USER	
	C_KEY7_CH,			
#endif			
#if	((C_KEY_TOTAL-7)>	0)//CCKEY8_USER	
	C_KEY8_CH,			
#endif			
#if	((C_KEY_TOTAL-8)>	0)//CCKEY9_USER	
	C_KEY9_CH,			
#endif			
#if	((C_KEY_TOTAL-9)>	0)//CCKEY10_USER	
	C_KEY10_CH, 		
#endif			
#if	((C_KEY_TOTAL-10)>	0)//CCKEY11_USER	
	C_KEY11_CH, 		
#endif			
#if	((C_KEY_TOTAL-11)>	0)//CCKEY12_USER	
	C_KEY12_CH, 		
#endif			
#if	((C_KEY_TOTAL-12)>	0)//CCKEY13_USER	
	C_KEY13_CH, 		
#endif			
#if	((C_KEY_TOTAL-13)>	0)//CCKEY14_USER	
	C_KEY14_CH, 		
#endif			
#if	((C_KEY_TOTAL-14)>	0)//CCKEY15_USER	
	C_KEY15_CH, 		
#endif			
#if	((C_KEY_TOTAL-15)>	0)//CCKEY16_USER	
	C_KEY16_CH, 		
#endif			
#if	((C_KEY_TOTAL-16)>	0)//CCKEY17_USER	
	C_KEY17_CH, 		
#endif			
#if	((C_KEY_TOTAL-17)>	0)//CCKEY18_USER	
	C_KEY18_CH, 		
#endif			
#if	((C_KEY_TOTAL-18)>	0)//CCKEY19_USER	
	C_KEY19_CH, 		
#endif			
#if	((C_KEY_TOTAL-19)>	0)//CCKEY20_USER	
	C_KEY20_CH, 		
#endif			
#if	((C_KEY_TOTAL-20)>	0)//CCKEY21_USER	
	C_KEY21_CH, 		
#endif			
#if	((C_KEY_TOTAL-21)>	0)//CCKEY22_USER	
	C_KEY22_CH, 		
#endif			
#if	((C_KEY_TOTAL-22)>	0)//CCKEY23_USER	
	C_KEY23_CH, 		
#endif			
#if	((C_KEY_TOTAL-23)>	0)//CCKEY24_USER	
	C_KEY24_CH, 		
#endif			
#if	((C_KEY_TOTAL-24)>	0)//CCKEY25_USER	
	C_KEY25_CH, 		
#endif			
#if	((C_KEY_TOTAL-25)>	0)//CCKEY26_USER	
	C_KEY26_CH, 		
#endif

};

//
unsigned int code Table_KeyDown[C_KEY_TOTAL] = 
{
	#if	((C_KEY_TOTAL-0)> 0)		
	C_KEY1_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-1)> 0)		
	C_KEY2_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-2)> 0)		
	C_KEY3_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-3)> 0)		
	C_KEY4_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-4)> 0)//
	C_KEY5_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-5)> 0)//
	C_KEY6_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-6)> 0)//
	C_KEY7_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-7)> 0)//
	C_KEY8_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-8)> 0)//
	C_KEY9_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-9)> 0)//
	C_KEY10_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-10)> 0)//
	C_KEY11_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-11)> 0)//
	C_KEY12_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-12)> 0)//
	C_KEY13_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-13)> 0)//
	C_KEY14_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-14)> 0)//
	C_KEY15_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-15)> 0)//
	C_KEY16_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-16)> 0)//
	C_KEY17_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-17)> 0)//
	C_KEY18_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-18)> 0)//
	C_KEY19_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-19)> 0)//
	C_KEY20_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-20)> 0)//
	C_KEY21_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-21)> 0)//
	C_KEY22_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-22)> 0)//
	C_KEY23_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-23)> 0)//
	C_KEY24_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-24)> 0)//
	C_KEY25_THRESHOLD,				
	#endif			
	#if	((C_KEY_TOTAL-25)> 0)//
	C_KEY26_THRESHOLD,				
	#endif
};

//内部并联电容选择
unsigned char code Table_KeyCap[C_KEY_TOTAL] = 
{
	#if	((C_KEY_TOTAL-0)> 0)		
	C_KEY1_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-1)> 0)		
	C_KEY2_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-2)> 0)		
	C_KEY3_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-3)> 0)		
	C_KEY4_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-4)> 0)//
	C_KEY5_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-5)> 0)//
	C_KEY6_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-6)> 0)//
	C_KEY7_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-7)> 0)//
	C_KEY8_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-8)> 0)//
	C_KEY9_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-9)> 0)//
	C_KEY10_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-10)> 0)//
	C_KEY11_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-11)> 0)//
	C_KEY12_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-12)> 0)//
	C_KEY13_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-13)> 0)//
	C_KEY14_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-14)> 0)//
	C_KEY15_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-15)> 0)//
	C_KEY16_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-16)> 0)//
	C_KEY17_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-17)> 0)//
	C_KEY18_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-18)> 0)//
	C_KEY19_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-19)> 0)//
	C_KEY20_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-20)> 0)//
	C_KEY21_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-21)> 0)//
	C_KEY22_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-22)> 0)//
	C_KEY23_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-23)> 0)//
	C_KEY24_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-24)> 0)//
	C_KEY25_CAP,				
	#endif			
	#if	((C_KEY_TOTAL-25)> 0)//
	C_KEY26_CAP,				
	#endif
};



//Debug相关
#ifdef	CMS_TOUCH_DEBUG
unsigned int xdata g_FactorRawDat[C_KEY_TOTAL];
unsigned int xdata g_Disp_KeyDown[C_KEY_TOTAL];
unsigned int xdata g_NoiseDat[C_KEY_TOTAL];
#endif
/*-------------------------------------------------------
以下请勿修改
-------------------------------------------------------*/
//若startup.a51里没有对xdata进行上电清0的配置，则此部分xdata需要上电程序清0
unsigned int xdata g_CMS_RAM0[C_KEY_TOTAL];
unsigned int xdata g_CMS_RAM1[C_KEY_TOTAL];
unsigned int xdata g_CMS_RAM2[C_KEY_TOTAL];
unsigned char xdata g_CMS_RAM3[C_KEY_TOTAL];
unsigned char xdata g_CMS_RAM4[C_KEY_TOTAL];
unsigned char xdata g_CMS_RAM5[C_KEY_TOTAL];
unsigned char xdata g_CMS_RAM6[C_KEY_TOTAL];
unsigned char xdata g_CMS_RAM7[C_KEY_TOTAL];
unsigned char xdata g_CMS_RAM8[C_KEY_TOTAL];

unsigned char code g__KeyTotalNumber = C_KEY_TOTAL;
unsigned char code g__KeyShakeCounter = C_KEY_SHAKE;
unsigned char code g__KeyOffCounter = C_KEY_OFFSHAKE;
unsigned char code g__VolValue = VOL_VALUE;
unsigned char code g__SluValue = SLU_VALUE;
unsigned char code g__CmBase = CM_BASE;
unsigned char code g__KeyValidNumber = C_VALID_KEY;
unsigned long int code g__KeyValidTime = C_VALID_TIME;
unsigned char code g__KeyUNTime = C_UN_TIME;
unsigned char code g__UnNol_Check = UNNOL_CHECK;
unsigned char code g__UnNol_Times = UNNOL_TIMES;
unsigned char code g__LMDValue = LMDVALUE;
unsigned char code g__Key_LDOSel = KEY_LDOSEL;
unsigned char code g__Key_En1kres = KEY_EN1KRES;
unsigned char code g__WaterMode = WATER_MODE;

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




