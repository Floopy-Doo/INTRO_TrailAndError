/*
 * Platform.c
 *
 *  Created on: 02.03.2015
 */
#include "Platform.h"

#if LED_ENABLE
	#include "LED.h"
#endif
#if PL_HAS_EVENTS
	#include "Event.h"
#endif
#if PL_HAS_MEALY
	#include "Mealy.h"
#endif

/*!
 * PLattform Initialization
 */
void PL_Init(void) {
#if LED_ENABLE
	LED_Init();
#endif
#if PL_HAS_EVENTS
	EVNT_Init();
	EVNT_SetEvent(EVNT_INIT);
#endif
#if PL_HAS_MEALY
	MEALY_Init();
#endif
}

/*!
 * Platform deinit
 */
void PL_Deinit(void) {
	#if LED_ENABLE
		LED_Deinit();
	#endif
	#if PL_HAS_EVENTS
		EVNT_Deinit();
	#endif
	#if PL_HAS_MEALY
		MEALY_Deinit();
	#endif
}
