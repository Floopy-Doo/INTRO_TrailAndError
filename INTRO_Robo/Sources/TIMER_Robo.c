/**
* \file
* \author Florian Bucher <florian.bucher@stud.hslu.ch>
* Timer implmentation for robo k22
*/

#include "TI1.h"
#include "Timer.h"
#include "Event.h"
#include "LED.h"
#include "Trigger.h"

// special override for timer tick, due to shorter timer tick on robot
#define TMR_TICK_MS 1

void TMR_Init() {
	TI1_Enable();
	TI1_EnableEvent();
}

void TMR_Deinit() {
	TI1_Disable();
	TI1_DisableEvent();
}

void TMR_OnInterrupt(void) {
	// used for counting the tick up to a second
	static uint8_t trmTickCount = 0;

	// increase trigger tick
	TRG_IncTick();

	// send out heartbeat event every second
	if ((++trmTickCount * TMR_TICK_MS) % 1000 == 0) {
		trmTickCount = 0;
		EVNT_SetEvent(EVNT_HEARTBEAT);
	}
}
