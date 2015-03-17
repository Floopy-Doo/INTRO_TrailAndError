/*
 * Application.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "Application.h"
#include "Platform.h"
#include "LED.h"
#include "Event.h"
#include "Timer.h"
#include "LED_WAIT.h"
#include "LED_FRDM.h"
#include "Keys.h"


void APP_Start(void) {
	// Initialize Platform

	PL_Init();
	EVNT_Init();
	KEY_Init();
	KEY_EnableInterrupts();


	// Do work
	for(;;) {
		EVNT_HandleEvent(APP_HandleEvent);
	}

	// Finalize Platform
	PL_Deinit();
	EVNT_Deinit();
	KEY_Deinit();
}

void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
		case EVNT_INIT:
			break;
		case EVNT_LED_ON:
			//LED1_On();
			break;
		case EVNT_LED_OFF:
			LED1_Off();
			break;
		case EVNT_SW1_PRESSED:
			LED1_Off();
			LED2_On();
			break;

		default: /* do nothing */
			break;
	}
}
