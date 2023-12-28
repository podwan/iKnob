#include "tm1621c.h"
//-----------------------------------------------------------------------------------------
// 函数名称：Delay()
// 功 能：延时子程序
//-----------------------------------------------------------------------------------------
void Delay(uchar us) // 5,7,9
{
    while (--us)
        ;
}
//-----------------------------------------------------------------------------------------
// 函数名称：DelayMS()
// 功 能：延时子程序
//-----------------------------------------------------------------------------------------
void DelayMS(uint iMs)
{
    uint i, j;
    for (i = 0; i < iMs; i++)
        for (j = 0; j < 65; j++)
        {
            Delay(1);
        }
}
static void tm1621cWrite(unsigned char byte, unsigned char cnt);
// static void TM1620_WriteCommand(unsigned char cmd);

void tm1621cInit()
{

    CS_IO = 1;
    WR_IO = 1;
    DATA_IO = 1;
    DelayMS(20); // 延时使LCD工作电压稳定
    TM1620_WriteCommand(BIAS);

    TM1620_WriteCommand(RC256);
    TM1620_WriteCommand(SYSDIS);
    TM1620_WriteCommand(WDTDIS);
    TM1620_WriteCommand(SYSEN);
    TM1620_WriteCommand(LCDON);
    DelayMS(20); // 延时一段时间
}

void TM1620cWriteData(unsigned char addr, unsigned char Data)
{

    CS_IO = 0;
    DelayMS(1);
    tm1621cWrite(0xA0, 3);      // 写入命令标志100
    tm1621cWrite(addr << 2, 6); // 写入地址数据
    tm1621cWrite(Data << 4, 4); // 写入数据
    CS_IO = 1;
}

static void tm1621cWrite(unsigned char byte, unsigned char cnt)
{
    unsigned char i = 0;

    for (i = 0; i < cnt; i++)
    {
        WR_IO = 0;
        DelayMS(3);
        DATA_IO = byte & 0x80;

        WR_IO = 1;
        DelayMS(3);
        byte <<= 1;
    }
}

void TM1620_WriteCommand(unsigned char cmd)
{
    CS_IO = 0;
    DelayMS(1);
    tm1621cWrite(0x80, 4); // 写入命令标志100
    tm1621cWrite(cmd, 8);
    CS_IO = 1;
}
//-----------------------------------------------------------------------------------------
// 函数名称：Ht1621Wr_Data()
// 功 能：写数据函数,cnt为传送数据位数,数据传送为低位在前
//-----------------------------------------------------------------------------------------
// void Ht1621Wr_Data(uchar Data, uchar cnt)
// {
//     uchar i;
//      for (i=0;i
//      {
//         CLS_HT_WR;

//         DelayMS(3);

//         if ((Data & 0x80) == 0x80)
//         {
//             SET_HT_DAT;
//         }
//         else
//         {
//             CLS_HT_DAT;
//         }
//         SET_HT_WR;
//         DelayMS(3);
//         Data <<= 1;
//      }
// }