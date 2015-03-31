/*
 * Application.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "Application.h"
#include "Platform.h"
#include "LED.h"
#include "WAIT.h"
#include "CLS1.h"
#include "Buzzer.h"
#include "FRTOS1.h"

/**
 * Startup code for the application.
 * All logic happens here
 */
void APP_Start(void) {
	// Initialize Platform
	PL_Init();

#if PL_HAS_RTOS
	RTOS_Run();
#endif

#if !PL_HAS_RTOS
	for (;;) {
#if PL_HAS_EVENTS
		// Call event handler
		EVNT_HandleEvent(APP_HandleEvent);
#endif
	}
#endif

	// Finalize Platform
	PL_Deinit();
}

/*
 * Match the event to a code section
 */
void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
	case EVNT_INIT:
		LED_On(LED_ALL);
		WAIT_WaitOSms(50);
		LED_Off(LED_ALL);
		BUZ_Beep(300, 500);
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
