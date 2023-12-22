#ifndef __USERMAIN_H
#define __USERMAIN_H

#include <stdio.h>
#include <string.h>
#include "cms80f731xx.h"
#include "gpio.h"
#include "CheckTouchKey_80F73xx.h"
#define TOUCH_KEY 0
#define FEED_WATCH_DOG 0
#define TOUCH_KEY_SCAN 0

#define USE_UART 0
#define PRINT_LOG 0
#define SPEED_UP 0
#define DISPLAY_TEMP 0
#define WITHOUT_POWER_BOARD 0
#define POWER_ADJUST 0
#define USE_ZERO 0
#define DEBUG_HEAT 0
#define DEBUGGING 0
#define SHOW_PWMDUTY 0
#define DEBUG_MEMORY 0
#define SIMU 0
#define DEBUG_TEMP 0
#define DEBUG_DISPLAY 0
#define DEBUG_KEY 0

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;

typedef enum
{
    POWER_ON,
    POWER_OFF,
    STANDBY,
    PREHEAT,
    SET,
    WORK,
    TEST,
    FAULT,
    CLEAN,
    VERSION
} DevState;
typedef enum
{
    ONE_CUP,
    TWO_CUP,
    STEAM,
    HOT_WATER
} WorkMode;

typedef enum
{
    VALVE_ON,
    TEMP_HIGH,
    ZERO_ERR,
    NTC_ERR
} FaultType;
typedef enum
{
    _40,
    _60,
    _80,
} Level;

typedef enum
{
    NO_VALUE,
    KEY1_SHORT,
    KEY1_LONG,
    KEY2_SHORT,
    KEY2_LONG,
    KEY3_SHORT,
    KEY3_LONG,
    KEY4_SHORT,
    KEY4_LONG,
    KEY5_SHORT,
    KEY6_SHORT,
    KEY6_LONG,
    KEY7_SHORT,
    KEY8_SHORT,
    THREE_KEYS_LONG,
    TWO_KEYS_LONG,
    KEY12_SHORT,
    DOUBLE_LONG,
    DUAL_LONG,
} KeyValue;

typedef enum
{
    NONE_KEY,
    ONnOFF_SHORT,
    ONnOFF_LONG,
    LEVEL_SHORT,
    LEVEL_LONG,
    ONE_CUP_LONG,
    TWO_CUP_LONG,
    STEAM_LONG,
    STEAM_SHORT,
    RESET_WORKED_TIMES_KEY,
    RESET_COFFEE_TIME_KEY,
    MENU_SHORT,
    TEST_KEY,
    RESET_KEY,
    VERSION_KEY
} KeyState;

#define KEY_FLAG_BYTES uint
typedef union
{
    KEY_FLAG_BYTES bytes;
    struct
    {
        int b0 : 1;
        int b1 : 1;
        int b2 : 1;
        int b3 : 1;
        int b4 : 1;
        int b5 : 1;
        int b6 : 1;
        int b7 : 1;
        int b8 : 1;
        int b9 : 1;
        int b10 : 1;
        int b11 : 1;
        int b12 : 1;
        int b13 : 1;
        int b14 : 1;
        int b15 : 1;
    } bits;
} UserKeyFlag;

typedef union
{
    unsigned char byte;
    struct
    {
        unsigned char b0 : 1;
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
    } bits;
} Byte;

// typedef enum
// {
//     STILL,
//     CLOCKWISE,
//     ANTI_CLOCKWISE,
// } EncoderState;

#define MAX_LEN 20

typedef struct
{
    unsigned char index;
    unsigned char buf[MAX_LEN];
    unsigned char len;
    unsigned char toProcessData;
} Uart;

typedef struct
{
    unsigned char firstByte;
    unsigned int workedTimes;
    unsigned char oneCupTime;
    unsigned char twoCupTime;
    Level tempLv;
    Level waterLv;
    unsigned char lastByte;
} Memory;

#define LongToBin(n)         \
    (                        \
        ((n >> 21) & 0x80) | \
        ((n >> 18) & 0x40) | \
        ((n >> 15) & 0x20) | \
        ((n >> 12) & 0x10) | \
        ((n >> 9) & 0x08) |  \
        ((n >> 6) & 0x04) |  \
        ((n >> 3) & 0x02) |  \
        ((n) & 0x01))

#define Bin(n) LongToBin(0x##n##l) // write binary charactor set,exsample : Bin(11111111) = 0xff

void userMain(void);
void setPowerLost();
bit getPowerLost();
#endif