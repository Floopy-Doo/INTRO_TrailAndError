/*
 * Platform.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */
#include "Platform.h"
#include "LED.h"
#include "Event.h"


/*!
 * PLattform Initialization
 */
void PL_Init(void) {
	#if LED_ENABLE
	LED_Init();
	#endif
	#if EVENT_ENABLED
	EVNT_Init();
	#endif
}

/*!
 * Platform deinit
 */
void PL_Deinit(void) {
	#if LED_ENABLE
	LED_Deinit();
	#endif
	#if EVENT_ENABLED
	EVNT_Deinit();
	#endif
}
