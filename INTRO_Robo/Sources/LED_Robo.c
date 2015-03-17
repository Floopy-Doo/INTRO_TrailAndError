/*
 * LED_Robo.c
 *
 *  Created on: 03.03.2015
 *      Author: Philipp Gosswiler
 */
#include "Platform.h"
#include "LED.h"
#include "LED_Robo.h"
#include "LED_WAIT.h"
#include "LED_FRONT_LEFT.h"
#include "LED_FRONT_RIGHT.h"

// Initialization
void LED_Init(void) {
	LED_All_Off();
}

void LED_Deinit(void) {
	LED_All_Off();
}

void LED_Test(void) {
	#if LED_TEST
	int i;
	LED_On(LED_FRONT_LEFT);
	for (i = 0; i < 5; i++) {
		LED_WAIT_Waitms(500);
		LED_Neg(LED_FRONT);
	}
	LED_All_Off();
	#endif
}

// Open & Close
void LED_Open(void) {}
void LED_Close(void) {}

// Functionality
void LED_On(LED_Set leds) {
	if (leds & LED_FRONT_LEFT) LED_FRONT_LEFT_PutVal(LED_ON);
	if (leds & LED_FRONT_RIGHT) LED_FRONT_RIGHT_PutVal(LED_ON);
}

void LED_Off(LED_Set leds) {
	if (leds & LED_FRONT_LEFT) LED_FRONT_LEFT_PutVal(LED_OFF);
	if (leds & LED_FRONT_RIGHT) LED_FRONT_RIGHT_PutVal(LED_OFF);
}

void LED_All_Off(void) {
	LED_Off(LED_ALL);
}

void LED_Neg(LED_Set leds) {
	if (leds & LED_FRONT_LEFT) LED_FRONT_LEFT_NegVal();
	if (leds & LED_FRONT_RIGHT) LED_FRONT_RIGHT_NegVal();
}

LED_Status LED_Get(LED_Set leds) {
	uint8 status = (LED_FRONT_RIGHT_GetVal()<<2) & (LED_FRONT_LEFT_GetVal()<<1);
	if (leds & status) {
		return LED_ON;
	}
	return LED_OFF;
}
