
#include "userTimer.h"
#include "app.h"
#include "beeper.h"
#if NEED_POWER_OFF_MEMORY
#include "memory.h"
#endif

static void poweringOn();
static void standingby();
static void setting();
static void working();
static void testing();
static void faulting();
static void motorDrive();
static DevState devState;
static bit _1s;
static Level level;
uint showStuff;
static uchar workTime, flashCnt, settingCnt;
#if KEY_ENABLE
#include "key.h"
static KeyState keyState;
#endif
MotorState motorState;
#if DISPLAY_ENABLE
#include "display.h"
static void displayDataUpdate();
static Byte displayDataBuf[NUM_OF_COM];
#endif

#if NEED_COMMUNICATION
#include "comm.h"
static void uartRxProcess();
static void uartTxProcess();
#endif
#if WITH_NTC
#include "sensor.h"
static uint ntcTemp;
static uchar ntcErr, errNo;
#endif
/*
deal per 100ms
*/
void appRunning()
{

#if NEED_POWER_OFF_MEMORY
    if (devState != POWER_ON)
    {
        memory.firstByte = 'K';
        memory.lastByte = 'X';
    }
#endif
#if KEY_ENABLE
    getKeyState(&keyState);
#endif

#if NEED_COMMUNICATION
    uartRxProcess();
#endif

#if DISPLAY_ENABLE
    memset(displayDataBuf, 0, NUM_OF_COM * sizeof(Byte));
#endif

#if WITH_NTC
    ntcErr = getTemp(&ntcTemp);
    if (devState != FAULT && devState != POWER_ON)
    {
        if (ntcErr != 0)
        {
            devState = FAULT;
            errNo = ntcErr;
        }
    }
#endif

    _1s = getOneSecFlag();

    if (++flashCnt >= 10)
        flashCnt = 0;

    switch (devState)
    {
    case POWER_ON:
        poweringOn();
        break;

    case STANDBY:
        standingby();
        break;

    case SET:
        setting();
        break;

    case WORK:
        working();
        break;

    case TEST:
        testing();
        break;

    case FAULT:
        faulting();
    }
#if DISPLAY_ENABLE
    displayDataUpdate();
#endif

#if NEED_COMMUNICATION
    uartTxProcess();
#endif
    motorDrive();
    if (_1s)
    {

        _1s = 0;
    }
}

#if NEED_COMMUNICATION

static void uartRxProcess()
{
    if (rxUart.toProcessData)
    {

        if (rxUart.buf[0] == 'X' && rxUart.buf[--rxUart.len] == 'K')
        {
        }

        rxUart.len = 0;
        rxUart.toProcessData = 0;
    }
}
static void uartTxProcess()
{
    sprintf(sendStuff, "K%d%dX\n", (int)devState, (int)workMode);
}
#endif

#if DISPLAY_ENABLE
static void displayDataUpdate()
{
#if NEED_SEG_REMAP
    char i;
    for (i = 0; i < NUM_OF_COM; i++)
    {
        if (i == 1) // 数字部分
        {
            char seg = 0;

            if (displayDataBuf[i].bits.b0)
                SEG_REMAP(1); ///
            if (displayDataBuf[i].bits.b1)
                SEG_REMAP(0); ///
            if (displayDataBuf[i].bits.b2)
                SEG_REMAP(2); ///
            if (displayDataBuf[i].bits.b3)
                SEG_REMAP(3); ///
            if (displayDataBuf[i].bits.b4)
                SEG_REMAP(6); //
            if (displayDataBuf[i].bits.b5)
                SEG_REMAP(4); ///
            if (displayDataBuf[i].bits.b6)
                SEG_REMAP(5); ///
            if (displayDataBuf[i].bits.b7)
                SEG_REMAP(7); //

            displayDataBuf[i].byte = seg;
        }
    }
#endif
    memcpy(displayData, displayDataBuf, NUM_OF_COM * sizeof(Byte));
}
#endif
#if DEBUG_DISPLAY
uchar i;
#endif
static void poweringOn()
{

#if DEBUG_DISPLAY
    if (_1s)
    {
#if DEBUG_COM
        if (++i == NUM_OF_COM)
        {
            i = 0;
        }
#elif DEBUG_SEG
        if (++i == 8)
        {
            i = 0;
        }

#endif
    }
#if DEBUG_SEG
    displayDataBuf[1].byte = 1 << i;
#elif DEBUG_COM
    displayDataBuf[i].byte = 0xFF;
#endif
    D1 = DIGITS[i];
#elif DEBUG_KEY
    // D1 = DIGITS[keys_flag / 10000000];
    // D2 = DIGITS[keys_flag % 10000000 / 1000000];
    // D3 = DIGITS[keys_flag % 1000000 / 100000];
    // D4 = DIGITS[keys_flag % 100000 / 10000];
    // D1 = DIGITS[KeyFlag % 10000 / 1000];
    // D2 = DIGITS[KeyFlag % 1000 / 100];
    D1 = DIGITS[KeyFlag % 100 / 10];
    D2 = DIGITS[KeyFlag % 10];
#elif DEBUG_TEMP || DEBUG_MEMORY
    D1 = DIGITS[showStuff % 10000 / 1000];
    D2 = DIGITS[showStuff % 1000 / 100];
    D3 = DIGITS[showStuff % 100 / 10];
    D4 = DIGITS[showStuff % 10];
#else

    static unsigned char cnt;
    static uchar i;
    for (i = 0; i < NUM_OF_COM; i++)
    {
        displayDataBuf[i].byte = 0xFF;
    }

    if (++cnt >= 10)
    {
#if NEED_POWER_OFF_MEMORY
        recall();

        if (memory.firstByte == 'K' && memory.lastByte == 'X')
        {
            if (memory.devState == WORK)
            {
                // devState = memory.devState;
                // workMode = memory.workMode;
                // workTime = memory.workTime;
                // workTemp = memory.workTemp;
            }
            else
                STANDBY_INIT;
        }
        else
            STANDBY_INIT;
#else
        STANDBY_INIT;
#endif
    }

#endif
}

static void standingby()
{
    D1 = DIGITS[MID_BAR];
    D2 = DIGITS[MID_BAR];
    if (keyState == ONnOFF_SHORT)
    {
        beepOnce();
        SET_INIT;
    }
}
static void setting()
{
    if (keyState == LEVEL_SHORT)
    {
        beepOnce();
        settingCnt = 0;
        if (level++ == _80)
            level = _40;
        flashCnt = 0;
    }
    else if (keyState == ONnOFF_SHORT)
    {
        beepOnce();
        STANDBY_INIT;
    }
    if (level == _40)
        workTime = 40;
    else if (level == _60)
        workTime = 60;
    else if (level == _80)
        workTime = 80;

    if (flashCnt < 5)
    {
        D1 = DIGITS[workTime / 10];
        D2 = DIGITS[workTime % 10];
        SEC_LED_ON;
    }

    if (++settingCnt >= 30)
    {
        WORK_INIT;
        beepSet(2, 5, 10);
    }
}
static void working()
{
    if (_1s)
    {
        if (--workTime == 0)
        {
            STANDBY_INIT;
            beepSet(3, 25, 50);
        }
    }
    D1 = DIGITS[workTime / 10];
    D2 = DIGITS[workTime % 10];
    SEC_LED_ON;

    if (keyState == ONnOFF_SHORT)
    {
        beepOnce();
        STANDBY_INIT;
    }
}

static void testing()
{
}

static void faulting()
{
}

static void motorDrive()
{
    static uchar motorCnt;
    if (devState == WORK)
    {
        if (_1s)
        {
            if (++motorCnt >= 26)
            {
                motorCnt = 0;
            }
        }
        if (motorCnt <= 10)
            motorState = ANTI_CLOCKWISE;
        else if (motorCnt <= 13)
            motorState = STOP;
        else if (motorCnt <= 23)
            motorState = CLOCKWISE;
        else
            motorState = STOP;
    }
    else
    {
        motorCnt = 0;
        motorState = STOP;
    }

    if (motorState == STOP)
    {
        MOTOR_STOP;
    }
    else if (motorState == CLOCKWISE)
    {
        MOTOR_CLOCKWISE;
    }
    else
    {
        MOTOR_ANTICLOCKWISE;
    }
}
