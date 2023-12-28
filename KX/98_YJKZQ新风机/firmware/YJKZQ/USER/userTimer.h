#ifndef __USERTIMER_H
#define __USERTIMER_H
#include "userMain.h"
#define ZERO_IO
#define ZERO_POLL 0
#define USE_ZERO_TIMER 0
#define DOUBLE_EDGE 0
#define CROSS_ZERO_POWER_OFF_DECTECTION 0
#define FREQUENCE_JUDGE 0
#define ZERO_ERR_TIME 1000

void dealPer125us();
unsigned char getFrequence();
bit getOneSecFlag();
bit getPowerLost();
bit getOneMsFlag();
void initializeClock();
bit getZeroErr();
void setCrossZero4timer();
bit getCrossZero();
#endif