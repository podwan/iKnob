#ifndef __KEY_H
#define __KEY_H

#include "userMain.h"

#define KEY1_LONG_CNT 300
#define KEY2_LONG_CNT 300
#define KEY3_LONG_CNT 1
#define KEY4_LONG_CNT 0
#define KEY5_LONG_CNT 1
#define KEY6_LONG_CNT 0
#define KEY7_LONG_CNT 0
#define KEY8_LONG_CNT 1
#define KEY9_LONG_CNT 0
#define KEY10_LONG_CNT 0
#define KEY11_LONG_CNT 1
#define KEY12_LONG_CNT 0

#define FILTER_CNT 12

#define CONTINUOUS_INTEVAL 40

#define CONTINUOUS_TRIG_CNT 100

#define K(i) (KEY_FLAG_BYTES)(1 << i)

#define TK1 1  // 3
#define TK2 2 // 3
#define KL3 2048 // 3
#define KL4 1    // 3
#define KL5 2    // 3
#define KL6 32   // 3
#define KR1 4    // 3
#define KR2 8    // 3
#define KR3 16   // 3
#define KR4 256  // 3
#define KR5 128  // 3
#define KR6 64   // 3

#define KEY_NUM 3 // 实际按键数量 + 1 （KEY0 自检进入方式）

#define TOUCH_KEY_FLAGS KeyFlag

typedef enum
{
    NO_TRIG,
    TRIG_SHORT,
    TRIG_LONG,
} TrigType;

typedef enum
{
    SHORT,           // 短按一次,按下有效
    LONG,            // 仅长按有效
    LONG_WITH_SHORT, // 长按一次或短按抬起有效
    CONTINUOUS,      // 长按连续触发
} KeyType;

typedef struct
{
    KeyType keyType;
    uint trigCnt;
    TrigType trigType;
    TrigType preKeyValue;
} KeyStruct;

void keyScan();
void getKeyState(KeyState *keyState);
bit getSwitchClosed();

#endif
