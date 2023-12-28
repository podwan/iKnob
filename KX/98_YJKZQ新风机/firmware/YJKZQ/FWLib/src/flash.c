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
/** \file FLASH.c
**
** 
**
**	History:
**	
*****************************************************************************/
/****************************************************************************/
/*	include files
*****************************************************************************/
#include "flash.h"

/****************************************************************************/
/*	Local pre-processor symbols/macros('#define')
****************************************************************************/


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
 ** \brief	FLASH_UnLock
 **			解锁
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void FLASH_UnLock(void)
{
	if (EA == 1)//操作TA时序时不允许被打断，因而需要关闭中断
	{
		EA = 0;   //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		MLOCK = 0xAA;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		MLOCK = 0xAA;
	}
}
/*****************************************************************************
 ** \brief	FLASH_Lock
 **			上锁
 ** \param [in] none
 ** \return  none
 ** \note	 
*****************************************************************************/
void FLASH_Lock(void)
{
	if (EA == 1)//操作TA时序时不允许被打断，因而需要关闭中断
	{
		EA = 0;   //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		TA = 0xAA;
		TA = 0x55;
		MLOCK = 0x00;
		EA = 1;
	}
	else
	{
		TA = 0xAA;
		TA = 0x55;
		MLOCK = 0x00;
	}
}

/*****************************************************************************
 ** \brief	FLASH_Write
 **			写缓存
 ** \param [in] FLASHModule	：(1)FLASH_DATA
 **							  (2)FLASH_CODE
 **				Addr: 16bit	  (1)FLASH_DATA_ADDR: 0x00~0x3FF;
 **							  (2)FLASH_CODE_ADDR: 0x00~0x7FFF;	
 **				Data: 8bit
 ** \return  none
 ** \note	 
*****************************************************************************/
void FLASH_Write(uint8_t FLASHModule, uint16_t Addr, uint8_t Data)
{
	MDATA = Data;
	MADRL = Addr;
	MADRH = Addr>>8;
	if(1==EA)      
  {
    EA=0;    //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		MCTRL = FLASH_WRITE | FLASHModule;	//操作FLASH期间不允许被打断
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();	
		while(MCTRL & 0x01);
    EA=1;
  }
  else
  {
		MCTRL = FLASH_WRITE | FLASHModule;	
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		while(MCTRL & 0x01);
  }
	


}

/*****************************************************************************
 ** \brief	FLASH_Read
 **			读缓存
 ** \param [in]  FLASHModule：(1)FLASH_DATA
 **							  (2)FLASH_CODE
 **				Addr: 16bit	  (1)FLASH_DATA_ADDR: 0x00~0x3FF;
 **							  (2)FLASH_CODE_ADDR: 0x00~0x7FFF;	
 ** \return  8bit Data
 ** \note	
*****************************************************************************/
uint8_t FLASH_Read(uint8_t FLASHModule, uint16_t Addr)
{
	MADRL = Addr;
	MADRH = Addr>>8;
	if(1==EA)      
  {
    EA=0;    //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		MCTRL = FLASH_READ | FLASHModule;	//操作FLASH期间不允许被打断
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();	
		while(MCTRL & 0x01);
    EA=1;
  }
  else
  {
		MCTRL = FLASH_READ | FLASHModule;	
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();	
		while(MCTRL & 0x01);
  }
	return (MDATA);
}

/*****************************************************************************
 ** \brief	FLASH_Erase
 **			擦除
 ** \param [in]  FLASHModule：(1)FLASH_DATA
 **							  (2)FLASH_CODE
 **				Addr: 16bit	  (1)FLASH_DATA_ADDR: 0x00~0x3FF;
 **							  (2)FLASH_CODE_ADDR: 0x00~0x7FFF;
 ** \return  none
 ** \note	
*****************************************************************************/
void FLASH_Erase(uint8_t FLASHModule, uint16_t Addr)
{
	MADRL = Addr;
	MADRH = Addr>>8;
	if(1==EA)      
  {
    EA=0;    //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		MCTRL  = FLASH_ERASE | FLASHModule;	//操作FLASH期间不允许被打断
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		while(MCTRL & 0x01);
    EA=1;
  }
  else
  {
		MCTRL  = FLASH_ERASE | FLASHModule;	
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		while(MCTRL & 0x01);
  }
}

/*****************************************************************************
 ** \brief	FLASH_Crc
 **			CRC校验
 ** \param [in]  SAddr: 16bit  FLASH_CODE_ADDR: 0x00~0x7FFF;
 **				 EAddr: 16bit  FLASH_CODE_ADDR: 0x00~0x7FFF;
 ** \return 16位校验值
 ** \note	
*****************************************************************************/
uint16_t  FLASH_Crc(uint16_t SAddr, uint16_t EAddr)
{
	uint16_t crc;
	if(EA == 1)	//操作FLASH期间不允许被打断
	{
		EA = 0;   //在CPU_WAITCLOCK选择1T的模式时，在EA=0后必须加nop,选择多T时不加。
		_nop_();
		PCRCDL =0x00;
		PCRCDH =0x00;
		MCTRL = 0x00;
		MADRL = SAddr;
		MADRH = SAddr>>8;	
		MCTRL = 0x02;
		MADRL = EAddr;
		MADRH = EAddr>>8;	
		MCTRL = FLASH_CRC;	
		while(MCTRL & FLASH_MCTRL_MSTART_Msk);
		crc = PCRCDL | (PCRCDH<<8);
		EA = 1;
	}
	else
	{
		PCRCDL =0x00;
		PCRCDH =0x00;
		MCTRL = 0x00;
		MADRL = SAddr;
		MADRH = SAddr>>8;	
		MCTRL = 0x02;
		MADRL = EAddr;
		MADRH = EAddr>>8;	
		MCTRL = FLASH_CRC;	
		while(MCTRL & FLASH_MCTRL_MSTART_Msk);
		crc = PCRCDL | (PCRCDH<<8);
	}
	MCTRL &= ~(FLASH_MCTRL_CRCADR_Msk);
	return crc;
}