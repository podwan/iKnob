#ifndef __BEEPER_H
#define __BEEPER_H
#include "userMain.h"
#define SIM_PWM 1

#define BEEPER_IO P03

#define BEEP_ON (BEEPER_IO = !BEEPER_IO)
#define BEEP_OFF (BEEPER_IO = 1)

void beepPolling(void);
void beepDrive();
void beepOnce();
void beepSet(unsigned char beepCnt, unsigned char beepOnTime, unsigned char beepPeriod);
bit isBeeping();
#endif