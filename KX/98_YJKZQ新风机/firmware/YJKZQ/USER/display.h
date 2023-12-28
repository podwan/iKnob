#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "userMain.h"
#define NUM_OF_COM 32
#define NUM_OF_SEG 4
#define BG_IO P10
#define BG_ON BG_IO = 1
#define BG_OFF BG_IO = 0
/*
        __a_
       f|   |b
        | g |
        -----
       e|   |c
        |   |
        -----
           d
*/
#define SEG_A 0x1
#define SEG_B 0x2
#define SEG_C 0x4
#define SEG_D 0x8
#define SEG_E 0x10
#define SEG_F 0x20
#define SEG_G 0x40
#define SEG_DP 0x80

#define SEG1_IO P07
#define SEG2_IO P06
#define SEG12_IO P34
#define SEG11_IO P35
#define SEG10_IO P40
#define SEG3_IO P41
#define SEG4_IO P42
#define SEG5_IO P43
#define SEG6_IO P44
#define SEG9_IO P45
#define SEG8_IO P46
#define SEG7_IO P47

#define COM1 P05
#define COM2 P04
#define COM3 P03
#define COM4 P02

#define SET_COM1_IN P5TRIS &= ~(1 << 5)
#define SET_COM2_IN P5TRIS &= ~(1 << 4)
#define SET_COM3_IN P5TRIS &= ~(1 << 3)
#define SET_COM4_IN P5TRIS &= ~(1 << 2)

#define SET_COM1_OUT P5TRIS |= (1 << 5)
#define SET_COM2_OUT P5TRIS |= (1 << 4)
#define SET_COM3_OUT P5TRIS |= (1 << 3)
#define SET_COM4_OUT P5TRIS |= (1 << 2)

// P0TRIS = 0xFF; // 0:input mode	1:output mode
// P1TRIS = 0xFF;
// P2TRIS = 0xFF;
// P3TRIS = 0xFF;
// P4TRIS = 0xFF;
// P5TRIS = 0xFF;

#define X 10
#define LETTER_H 11
#define LETTER_E 12
#define LETTER_C 13
#define U_BAR 14
#define R_U_BAR 15
#define R_B_BAR 16
#define B_BAR 17
#define MID_BAR 18
#define LETTER_r 19
#define LETTER_U 20
#define LETTER_F 21
#define LETTER_C 13
#define LETTER_d 22
#define LETTER_S 23
#define U_CIRCLE 24
#define D_CIRCLE 25
#define LETTER_P 26
#define LETTER_L 27
#define LETTER_n 28
#define R_BRACKET 29
#define L_U_BAR 30
#define L_B_BAR 31

#define NEED_SEG_REMAP 0
#define SEG_REMAP(x) seg |= 1 << x

extern Byte displayData[NUM_OF_COM];
extern code unsigned char DIGITS[];

void display();
void TM1621bDrive();
#endif
