#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "userMain.h"
#define NUM_OF_COM 2

#define S_1 P23
#define S_2 P11
#define S_3 P06
#define S_4 P07
#define S_5 P22

#define SET_S1_INPUT GPIO_ENABLE_INPUT(P2TRIS, GPIO_PIN_3)
#define SET_S2_INPUT GPIO_ENABLE_INPUT(P1TRIS, GPIO_PIN_1)
#define SET_S3_INPUT GPIO_ENABLE_INPUT(P0TRIS, GPIO_PIN_6)
#define SET_S4_INPUT GPIO_ENABLE_INPUT(P0TRIS, GPIO_PIN_7)
#define SET_S5_INPUT GPIO_ENABLE_INPUT(P2TRIS, GPIO_PIN_2)

#define SET_S1_OUTPUT GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_3)
#define SET_S2_OUTPUT GPIO_ENABLE_OUTPUT(P1TRIS, GPIO_PIN_1)
#define SET_S3_OUTPUT GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_6)
#define SET_S4_OUTPUT GPIO_ENABLE_OUTPUT(P0TRIS, GPIO_PIN_7)
#define SET_S5_OUTPUT GPIO_ENABLE_OUTPUT(P2TRIS, GPIO_PIN_2)
// #define S_F P1_7
// #define S_G P2_0
// #define S_H P0_2

// #define COM1 P1_6
// #define COM2 P1_5
// #define COM3 P3_5
// #define COM4 P3_4

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

#define SEG_A 0x1
#define SEG_B 0x2
#define SEG_C 0x4
#define SEG_D 0x8
#define SEG_E 0x10
#define SEG_F 0x20
#define SEG_G 0x40
#define SEG_DP 0x80

#define NEED_SEG_REMAP 1
#define SEG_REMAP(x) seg |= 1 << x

extern Byte displayData[NUM_OF_COM];
extern code unsigned char DIGITS[];

void display();

#endif
