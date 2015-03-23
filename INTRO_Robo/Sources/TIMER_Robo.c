/**
* \file
* \author Florian Bucher <florian.bucher@stud.hslu.ch>
* Timer implmentation for robo k22
*/

#include "TI1.h"
#include "Timer.h"
#include "Event.h"
#include "LED.h"

void TMR_Init() {
	TI1_Enable();
	TI1_EnableEvent();
}

void TMR_Deinit() {
	TI1_Disable();
	TI1_DisableEvent();
}

void TMR_OnInterrupt(void) {
	static int trmTickCount = 0;

	if ((++trmTickCount * TMR_TICK_MS) % 1000 == 0) {
		trmTickCount = 0;
		EVNT_SetEvent(EVNT_HEARTBEAT);
	}
}
