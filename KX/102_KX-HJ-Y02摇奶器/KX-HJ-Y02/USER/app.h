#ifndef __APP_H
#define __APP_H
#include "userMain.h"

#define KEY_ENABLE 1
#define DISPLAY_ENABLE 1
#define NEED_COMMUNICATION 0
#define WITH_NTC 0

#define DEBUG_COM 0
#define DEBUG_SEG 1

#define D1 displayDataBuf[0].byte
#define D2 displayDataBuf[1].byte

#define SEC_LED_ON displayDataBuf[1].byte |= 1 << 7

#define POWER_ON_INIT        \
    {                        \
        devState = POWER_ON; \
    }

#define STANDBY_INIT        \
    {                       \
        devState = STANDBY; \
    }

#define SET_INIT        \
    {                   \
        devState = SET; \
        level = _60;    \
        settingCnt = 0; \
        flashCnt = 0;   \
    }

#define WORK_INIT          \
    {                      \
        devState = WORK;   \
        initializeClock(); \
    }

#define FAULT_INIT        \
    {                     \
        devState = FAULT; \
    }

#define TEST_INIT        \
    {                    \
        devState = TEST; \
    }

#define F_IO P01
#define Z_IO P02

#define MOTOR_CLOCKWISE \
    {                   \
        F_IO = 1;       \
        Z_IO = 0;       \
    }

#define MOTOR_ANTICLOCKWISE \
    {                       \
        F_IO = 0;           \
        Z_IO = 1;           \
    }

#define MOTOR_STOP \
    {              \
        F_IO = 0;  \
        Z_IO = 0;  \
    }

typedef enum
{
    STOP,
    CLOCKWISE,
    ANTI_CLOCKWISE,
} MotorState;

void appRunning();
extern uint showStuff;
#endif