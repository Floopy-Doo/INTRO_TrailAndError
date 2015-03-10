/*
 * Application.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "../../COMMON/Application.h"
#include "../../COMMON/Platform.h"
#include "../../COMMON/LED.h"
#include "LED_WAIT.h"

void APP_Start(void) {
	// Initialize Platform
	PL_Init();

	// Do work
	LED_Test();

	LED_On(LED_FRONT_LEFT);
	for(;;) {
		LED_WAIT_Waitms(500);
		LED_Neg(LED_FRONT);
	}

	// Finalize Platform
	PL_Deinit();
}
