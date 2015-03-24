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
#include "CLS1.h"
#include "Buzzer.h"

/**
 * Startup code for the application.
 * All logic happens here
 */
void APP_Start(void) {
	// Initialize Platform
	PL_Init();

	for (;;) {
#if PL_HAS_EVENTS
		// Call event handler
		EVNT_HandleEvent(APP_HandleEvent);
#endif
	}

	// Finalize Platform
	PL_Deinit();
}

/*
 * Match the event to a code section
 */
void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
	case EVNT_INIT:
		BUZ_Beep(500, 1000);
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
#if PL_NOF_KEYS >= 1
	case EVNT_SW1_PRESSED:
		LED_On(LED_FRONT_LEFT);
		CLS1_SendStr("Button Pressed: Hello you :P! \r\n",
				CLS1_GetStdio()->stdOut);
		LED_Off(LED_FRONT_LEFT);
		break;
#endif
	default: /* do nothing */
		break;
	}
}
