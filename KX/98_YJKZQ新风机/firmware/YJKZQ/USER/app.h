#ifndef __APP_H
#define __APP_H
#include "userMain.h"

#define KEY_ENABLE 0
#define DISPLAY_ENABLE 1
#define NEED_COMMUNICATION 0
#define WITH_NTC 0

#define DEBUG_COM 0
#define DEBUG_SEG 1

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
    }

#define WORK_INIT        \
    {                    \
        devState = WORK; \
    }

#define FAULT_INIT        \
    {                     \
        devState = FAULT; \
    }

#define TEST_INIT        \
    {                    \
        devState = TEST; \
    }

#define FAN_LCD_ON                         \
    {                                      \
        displayDataBuf[0].bytes |= 1 << 0; \
        displayDataBuf[0].bytes |= 1 << 1; \
        displayDataBuf[1].bytes |= 1 << 0; \
        displayDataBuf[1].bytes |= 1 << 1; \
        displayDataBuf[2].bytes |= 1 << 0; \
        displayDataBuf[2].bytes |= 1 << 1; \
    }


#define PM2p5_LCD_ON displayDataBuf[0].bytes |= 1 << 8
#define PM_VALUE_D1_4_ON displayDataBuf[0].bytes |= 1 << 9
#define PM_VALUE_D1_5_ON displayDataBuf[1].bytes |= 1 << 8
#define PM_VALUE_D1_3_ON displayDataBuf[1].bytes |= 1 << 9
#define PM_VALUE_D1_7_ON displayDataBuf[2].bytes |= 1 << 8
#define PM_VALUE_D1_2_ON displayDataBuf[2].bytes |= 1 << 9
#define PM_VALUE_D1_6_ON displayDataBuf[3].bytes |= 1 << 8
#define PM_VALUE_D1_1_ON displayDataBuf[3].bytes |= 1 << 9

#define OUTDOOR_LCD_ON displayDataBuf[0].bytes |= 1 << 10
#define PM_VALUE_D2_4_ON displayDataBuf[0].bytes |= 1 << 11
#define PM_VALUE_D2_5_ON displayDataBuf[1].bytes |= 1 << 10
#define PM_VALUE_D2_3_ON displayDataBuf[1].bytes |= 1 << 11
#define PM_VALUE_D2_7_ON displayDataBuf[2].bytes |= 1 << 10
#define PM_VALUE_D2_2_ON displayDataBuf[2].bytes |= 1 << 11
#define PM_VALUE_D2_6_ON displayDataBuf[3].bytes |= 1 << 10
#define PM_VALUE_D2_1_ON displayDataBuf[3].bytes |= 1 << 11

#define INNER_CYCLE_LCD_ON                 \
    {                                      \
        displayDataBuf[0].bytes |= 1 << 2; \
        displayDataBuf[3].bytes |= 1 << 0  \
    }

#define SLEEP_LCD_ON displayDataBuf[1].bytes |= 1 << 2
#define LOW_WIND_LCD_ON displayDataBuf[2].bytes |= 1 << 2
#define HIGH_WIND_LCD_ON displayDataBuf[3].bytes |= 1 << 1
#define OUT_WIND_LCD_ON displayDataBuf[3].bytes |= 1 << 2

#define WIFI_LCD_ON displayDataBuf[1].bytes |= 1 << 3
#define HEAT_EXCHANGE_LCD_ON displayDataBuf[2].bytes |= 1 << 3
#define VENTILATION_LCD_ON displayDataBuf[3].bytes |= 1 << 3

void appRunning();
extern uint showStuff;
#endif