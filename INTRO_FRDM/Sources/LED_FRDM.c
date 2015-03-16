/*
 * LED_FRDM.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "../../COMMON/LED.h"
#include "../../COMMON/Platform.h"
#include "LED_FRDM.h"
#include "LedBit1.h"
#include "LedBit2.h"
#include "LedBit3.h"
#include "LED_WAIT.h"

// Initialization
/*!void LED_Init(void) {
	LED_All_Off();
}

void LED_Deinit(void) {
	LED_All_Off();
}

void LED_Test(void) {
	#if LED_TEST
	int i;
	LED_On(LED_BLUE);
	for (i = 0; i < 5; i++) {
		LED_WAIT_Waitms(500);
		LED_Neg(LED_MAGENTA);
	}
	LED_All_Off();
	#endif
}

// Open & Close
void LED_Open(void) {}
void LED_Close(void) {}

// Functionality
void LED_On(LED_Set leds) {
	if (leds & LED_GREEN) LedBit1_PutVal(LED_ON);
	if (leds & LED_RED) LedBit2_PutVal(LED_ON);
	if (leds & LED_BLUE) LedBit3_PutVal(LED_ON);
}

void LED_Off(LED_Set leds) {
	if (leds & LED_GREEN) LED_GREEN_PutVal(LED_OFF);
	if (leds & LED_RED) LED_RED_PutVal(LED_OFF);
	if (leds & LED_BLUE) LED_BLUE_PutVal(LED_OFF);
}

void LED_All_Off(void) {
	LED_Off(LED_ALL);
}

void LED_Neg(LED_Set leds) {
	if (leds & LED_GREEN) LED_GREEN_NegVal();
	if (leds & LED_BLUE) LED_BLUE_NegVal();
	if (leds & LED_RED) LED_RED_NegVal();
}

LED_Status LED_Get(LED_Set leds) {
	uint8 status = (LED_GREEN_GetVal()<<2) & (LED_RED_GetVal()<<1) & (LED_BLUE_GetVal()<<3);
	if (leds & status) {
		return LED_ON;
	}
	return LED_OFF;
}
*/

