#ifndef _MAIN_H_
#define _MAIN_H_

sbit Buz = P1^2;//
sbit PO_SEGA = P3^1;//P1^5;//
sbit PO_SEGB = P1^5;//P1^1;//
sbit PO_SEGC = P3^7;//P0^1;//
sbit PO_SEGD = P4^6;//P5^4;//
sbit PO_SEGE = P3^6;//P0^2;//
sbit PO_SEGF = P1^4;//P1^2;//
sbit PO_SEGG = P4^4;//P0^0;//
//sbit PO_SEGDP = P2^0;//
sbit PO_COM1 = P1^7;//P1^0;//
sbit PO_COM2 = P1^1;//P0^5;//
sbit PO_COM3 = P0^7;//P0^6;//
sbit PO_COM4 = P0^6;//P0^7;//
sbit PO_COM5 = P1^6;//P0^4;//
sbit PO_COM6 = P3^0;//P0^3;//


extern u8 g_mainTime;

extern void INT_Function_Set(void);


#endif

