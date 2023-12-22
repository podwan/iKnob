#ifndef _MAIN_H_
#define _MAIN_H_

sbit Buz = P1^3;//pin17
sbit PO_SEGA = P1^5;//pin19
sbit PO_SEGB = P1^1;//pin15
sbit PO_SEGC = P0^1;//pin7
sbit PO_SEGD = P5^4;//pin4
//sbit PO_SEGD = P5^0;//pin4
sbit PO_SEGE = P0^2;//pin8
sbit PO_SEGF = P1^2;//pin16
sbit PO_SEGG = P0^0;//pin6
sbit PO_SEGDP = P2^0;//pin22
sbit PO_COM1 = P1^0;//pin14
sbit PO_COM2 = P0^5;//pin11
sbit PO_COM3 = P0^6;//pin12
sbit PO_COM4 = P0^7;//pin13
sbit PO_COM5 = P0^4;//pin10
sbit PO_COM6 = P0^3;//pin9


extern u8 g_mainTime;

extern void INT_Function_Set(void);


#endif

