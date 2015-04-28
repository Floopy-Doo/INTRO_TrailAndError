/**
* \file
* \author Florian Bucher <florian.bucher@stud.hslu.ch>
* Timer implmentation for robo k22
*/

#include "Platform.h"
#if PL_HAS_TIMER
//#include "TI1.h"
#include "Timer.h"
#include "Event.h"
#include "LED.h"
#include "Trigger.h"


void TMR_Init() {
	/*TI1_Enable();
	TI1_EnableEvent();*/
}

void TMR_Deinit() {
	/*TI1_Disable();
	TI1_DisableEvent();*/
}

void TMR_OnInterrupt(void) {
	// used for counting the tick up to a second
	static int trmTickCount = 0;

	// increase trigger tick
	TRG_IncTick();

	// do smthg / event every 10ms
	if ((++trmTickCount * TMR_TICK_MS) % 10 == 0) {
		//Do smthg



		/*bool isLeft = 1;
		bool isRight = 0;
		int32_t currSpeed = TACHO_GetSpeed(isLeft);
		int32_t setSpeed = 0;
		//PID_Config *config = ;

		//PID_SpeedCfg(currSpeed, setSpeed, isLeft, config);
*/
		trmTickCount = 0;
	}
}
#endif
