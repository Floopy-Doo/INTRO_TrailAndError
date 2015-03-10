/**
 * \file
 * \brief FRDM LED Driver
 * \author Philipp Gosswiler <philipp.gosswiler@stud.hslu.ch>
 * \author Reto Ritter <reto.ritter@stud.hslu.ch>
 *
 * Platform specific LED driver component for the FRDM board.
 */
#ifndef LED_FRDM_H_
#define LED_FRDM_H_

/*!
 * Represents a status for an individual LED.
 */
typedef enum {
	LED_ON = 0,	/*!< Indicates that the LED is active */
	LED_OFF = 1	/*!< Indicates that the LED is inactive */
} LED_Status;

/*!
 * Represents a bit mask for all LEDs available.
 */
typedef enum {
	LED_RED = (1<<1),							/*!< Represents the red LED */
	LED_GREEN = (1<<2),							/*!< Represents the green LED */
	LED_BLUE = (1<<3),							/*!< Represents the blue LED */
	LED_CYAN = LED_GREEN | LED_BLUE,			/*!< Represents the green and blue LED, which results in cyan */
	LED_MAGENTA = LED_RED | LED_BLUE,			/*!< Represents the red and blue LED, which results in magenta */
	LED_YELLOW = LED_RED | LED_GREEN,			/*!< Represents the green and red LED, which results in yellow */
	LED_WHITE = LED_RED | LED_GREEN | LED_BLUE,	/*!< Represents the red, green and blue LED, which results in white */
	LED_ALL = LED_WHITE							/*!< Additional enumerator for all LED */
} LED_Set;

#endif /* LED_FRDM_H_ */
