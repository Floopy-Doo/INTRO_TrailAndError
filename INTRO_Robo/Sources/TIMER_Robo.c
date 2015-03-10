/**
* \file
* \author Florian Bucher <florian.bucher@stud.hslu.ch>
* Timer implmentation for robo k22
*/

#include "TI1.h"
#include "../../COMMON/Timer.h"
#include "../../COMMON/LED.h"

#define TMR_TICK_MS 10

void TMR_Init() {
	TI1_Enable();
	TI1_EnableEvent();
}

void TMR_Deinit() {
	TI1_Disable();
	TI1_DisableEvent();
}

int tmrTickCounter = 0;

void TMR_OnInterrupt() {
	if ((tmrTickCounter * TMR_TICK_MS) % 1000) {
		LED_On();
	}
}
