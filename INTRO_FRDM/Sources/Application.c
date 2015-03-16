/*
 * Application.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "../../COMMON/Application.h"
#include "../../COMMON/Platform.h"
#include "../../COMMON/LED.h"
#include "../../COMMON/Event.h"
#include "../../COMMON/Timer.h"
#include "LED_WAIT.h"
#include "LED_FRDM.c"


void APP_Start(void) {
	// Initialize Platform
	PL_Init();

	// Do work
	for(;;) {
		EVNT_HandleEvent(APP_HandleEvent);
	}

	// Finalize Platform
	PL_Deinit();

}

void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
		case EVNT_INIT:
			break;
		case EVNT_LED_ON:
			LED1_On();
			break;
		case EVNT_LED_OFF:
			LED1_Off();

		default: /* do nothing */
			break;
	}
}
