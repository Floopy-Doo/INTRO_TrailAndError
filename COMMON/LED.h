/*!
 *  \file LED.h
 *  \brief LED Driver
 *  \author Philipp Gosswiler <philipp.gosswiler@stud.hslu.ch>
 *  \author Reto Ritter <reto.ritter@stud.hslu.ch>
 *
 *  Interface for LED Driver. Defines basic functions to use LEDs in the project.
 */

#ifndef LED_H_
#define LED_H_

#include "Platform.h"
#if LED_ENABLE

#ifdef PL_BOARD_IS_FRDM
	#include "LED_FRDM.h"
#elif defined(PL_BOARD_IS_ROBO)
	#include "LED_Robo.h"
#else
	#error "Unknown Board"
#endif

// Initialization
void LED_Init(void);
void LED_Deinit(void);
void LED_Test(void);

// Open & Close
void LED_Open(void);
void LED_Close(void);

// Functionality
void LED_On(LED_Set leds);
void LED_All_Off(void);
void LED_Off(LED_Set leds);
void LED_Neg(LED_Set leds);
LED_Status LED_Get(LED_Set leds);

#endif /* LED_ENABLE */
#endif /* LED_H_ */
