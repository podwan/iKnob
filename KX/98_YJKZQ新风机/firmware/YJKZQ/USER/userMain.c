

#include "userTimer.h"
#include "display.h"
// #include "app.h"
// #include "beeper.h"
// #include "sensor.h"
// #include "key.h"

void userMain(void)
{
	static uchar _5msCnt, _30msCnt, _20msCnt, _100msCnt, _10msCnt;

#if NEED_POWER_OFF_MEMORY
#include "memory.h"
	static bit memorized, recalled;
	if (!recalled)
	{
		recalled = 1;
		recall();
	}
	if (getPowerLost() && !memorized)
	{
		memorize();
		memorized = 1;
	}
#endif

	if (getOneMsFlag())
	{
		if (_100msCnt < 100)
			_100msCnt++;
		else
		{
			appRunning();

			_100msCnt = 0;
		}

		if (_10msCnt < 10)
			_10msCnt++;
		else
		{
			_10msCnt = 0;

			TM1621bDrive();
		}

		// if (_30msCnt < 30)
		// 	_30msCnt++;
		// else
		// {
		// 	_30msCnt = 0;
		// 	sensoring();
		// }

		// if (_20msCnt < 20)
		// 	_20msCnt++;
		// else
		// {
		// 	_20msCnt = 0;
		// 	beepPolling();
		// }
	}
}
