/*
 * Application.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "Application.h"
#include "Platform.h"
#include "LED.h"
#include "LED_WAIT.h"
#include "Mealy.h"

/**
 * Startup code for the application.
 * All logic happens here
 */
void APP_Start(void) {
	// Initialize Platform
	PL_Init();

#if PL_HAS_EVENTS
	// Init Events
	EVNT_Init();
	// Fire EVNT_INIT event (initial startup);
	EVNT_SetEvent(EVNT_INIT);
#endif

#if PL_HAS_MEALY
	// Init mealy state event maschine
	MEALY_Init();
#endif

	for(;;) {
#if PL_HAS_EVENTS
		// Call event handler
		EVNT_HandleEvent(APP_HandleEvent);
#endif
	}


	// Finalize Platform
#if PL_HAS_MEALY
	MEALY_Deinit();
#endif
#if PL_HAS_EVENTS
	EVNT_Deinit();
#endif

	PL_Deinit();
}

/*
 * Match the event to a code section
 */
void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
		case EVNT_INIT:
			LED_On(LED_FRONT_RIGHT);
			LED_WAIT_Waitns(50);
			LED_Off(LED_FRONT_RIGHT);
			break;
		case EVNT_HEARTBEAT:
			LED_Neg(LED_FRONT_RIGHT);
			break;
		case EVNT_LED_ON:
			LED_On(LED_ALL);
			break;
		case EVNT_LED_OFF:
			LED_Off(LED_ALL);
			break;
		default: /* do nothing */
			break;
	}
}
