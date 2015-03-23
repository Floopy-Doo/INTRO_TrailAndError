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
#include "CLS1.h"


void APP_Start(void) {
	// Initialize Platform

	PL_Init();
	EVNT_Init();
	KEY_Init();
	KEY_EnableInterrupts();
	CLS1_Init();

	// Do work
	for(;;) {
		EVNT_HandleEvent(APP_HandleEvent);
		KEY_Scan();
		LED_WAIT_Waitms(50); /* wait some time */
	}

	// Finalize Platform
	PL_Deinit();
	EVNT_Deinit();
	KEY_Deinit();
	CLS1_Deinit();
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
			LED_All_Off();
			LED_All_On();
			CLS1_SendStr("EVNT_SW1_PRESSED\r\n", CLS1_GetStdio()->stdOut);

			break;
		case EVNT_SW2_PRESSED:
			LED_All_Off();
			LED2_On();
			CLS1_SendStr("EVNT_SW2_PRESSED\r\n", CLS1_GetStdio()->stdOut);

			break;
		case EVNT_SW3_PRESSED:
			LED_All_Off();
			LED2_On();
			CLS1_SendStr("EVNT_SW3_PRESSED\r\n", CLS1_GetStdio()->stdOut);

			break;
		case EVNT_SW4_PRESSED:
			LED_All_Off();
			LED1_On();
			CLS1_SendStr("EVNT_SW4_PRESSED\r\n", CLS1_GetStdio()->stdOut);

			break;
		case EVNT_SW5_PRESSED:
			LED_All_Off();
			LED1_On();
			LED2_On();
			CLS1_SendStr("EVNT_SW5_PRESSED\r\n", CLS1_GetStdio()->stdOut);

			break;
		case EVNT_SW6_PRESSED:
			LED_All_Off();
			LED1_On();
			LED3_On();
			CLS1_SendStr("EVNT_SW6_PRESSED\r\n", CLS1_GetStdio()->stdOut);

			break;
		default: /* do nothing */
			break;
	}
}
