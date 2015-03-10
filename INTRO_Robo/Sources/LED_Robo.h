/*
 * LED_Robo.h
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#ifndef LED_ROBO_H_
#define LED_ROBO_H_

// LEDs are low active
typedef enum {
	LED_ON = 0,
	LED_OFF = 1
} LED_Status;

typedef enum
{
	LED_NONE = 0,
	LED_FRONT_LEFT = (1<<1),
	LED_FRONT_RIGHT = (1<<2),
	LED_FRONT = LED_FRONT_LEFT | LED_FRONT_RIGHT,
	LED_ALL = LED_FRONT
} LED_Set;


#endif /* LED_ROBO_H_ */
