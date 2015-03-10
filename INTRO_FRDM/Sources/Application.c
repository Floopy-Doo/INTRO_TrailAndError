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

void APP_Start(void) {
	// Initialize Platform
	PL_Init();


	// Do work
	for(;;) {
		/*!LED_WAIT_Waitms(500);
		EVNT_SetEvent(EVNT_LED_ON);
		EVNT_HandleEvent(APP_HandleEvent);
		LED_WAIT_Waitms(500);
		EVNT_SetEvent(EVNT_LED_OFF);*/
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
			LED_On(LED_ALL);
			break;
		case EVNT_LED_OFF:
			LED_All_Off();
			break;
			/*!case EVNT_LED_NEG:
			LED_On(LED_ALL);
			if(LED_Get(LED_ALL)==LED_ON){
				LED_All_Off();
			}
			else{
				LED_All_On();
			}*/
		default: /* do nothing */
			break;
	}
}
