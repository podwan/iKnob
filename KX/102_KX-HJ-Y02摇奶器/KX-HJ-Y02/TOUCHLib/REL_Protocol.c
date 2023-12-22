#include "REL_Protocol.h"
#include "CheckTouchKey_Set.h"

#define REL_TYPE_ID_USE	0x07

typedef struct _PackStrcut
{
	u16 rawData;//滤波值
	u16 thresholdA;//阈值1
	//u16 thresholdB;//阈值1
	u16 noiseData;//噪声值
}PackStrcut;


#define PACK_SEND_COUNT_ONCE	4

#if (C_KEY_TOTAL % PACK_SEND_COUNT_ONCE)
	#define PACK_IDX_MAX 			(C_KEY_TOTAL / PACK_SEND_COUNT_ONCE)
	#define PACK_SEND_COUNT_FINAL	(C_KEY_TOTAL % PACK_SEND_COUNT_ONCE)
#else
	#define PACK_IDX_MAX 			((C_KEY_TOTAL-1) / PACK_SEND_COUNT_ONCE)
	#define PACK_SEND_COUNT_FINAL	PACK_SEND_COUNT_ONCE
#endif

void REL_SenderLoop0()
{
	//static u8 bSend = 0;
	static u8 curIdx = 0;
	static u8 packIdx = 0;
	u8 thisSendCount;	
	PackHeader packHeader;
	PackStrcut packStrcut;
	
	//bSend = ~bSend;
	//if(bSend == 0) return;
	
	// 填写头部数据
	packHeader.typeId = REL_TYPE_ID_USE;
	packHeader.packIdxMax = PACK_IDX_MAX;
	packHeader.packIdxCur = packIdx;

#ifdef VOL_VALUE
	packHeader.extData[0] = VOL_VALUE;
#else
	packHeader.extData[0] = 0;
#endif


	if(packIdx == PACK_IDX_MAX)
	{
		thisSendCount = PACK_SEND_COUNT_FINAL;
		packHeader.length = sizeof(packHeader) + sizeof(packStrcut) * PACK_SEND_COUNT_FINAL + 1;
	}
	else
	{
		thisSendCount = PACK_SEND_COUNT_ONCE;
		packHeader.length = sizeof(packHeader) + sizeof(packStrcut) * PACK_SEND_COUNT_ONCE + 1;
	}
	
	// 开始发送
	REL_SendStart(packHeader);
	do
	{
		#ifdef	CMS_TOUCH_DEBUG//调试宏定义是否为1
			packStrcut.rawData = htol16(g_FactorRawDat[curIdx]);				
			packStrcut.thresholdA = htol16(g_Disp_KeyDown[curIdx]);
			//packStrcut.thresholdB = htol16(g_Disp_KeyDown_Pro[curIdx]);
			packStrcut.noiseData = htol16(g_NoiseDat[curIdx]);
		#endif
		REL_SendNext(packStrcut);	
		thisSendCount--;
		curIdx++;		
	}while(thisSendCount != 0);
	REL_SendEnd();	
	
	// 是否最后一包
	if(packIdx == PACK_IDX_MAX)
	{
		packIdx = 0;
		curIdx = 0;
	}
	else
	{
		packIdx++;
	}
}
