/**
 * \file
 * \brief LED driver implementation.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This module implements a generic LED driver for up to 5 LEDs.
 * It is using macros for maximum flexibility with minimal code overhead.
 */
/*!
**  @addtogroup LED_module LED module documentation
**  @{
*/

#include "LED.h"

/*!
 * \brief LED test routine.
 * This routine tests if:
 * - we can turn the LEDs properly on and off
 * - if we can negate them
 * - if we can set an LED value
 * - if we can get the LED value
 * If the test fails, the program will hanging in an endless loop
 */
void LED_Test(void) {
  bool isOn = TRUE;

  LED1_On();
  LED2_On();
  LED3_On();

  LED1_Off();
  LED2_Off();
  LED3_Off();

  LED1_Neg();
  LED2_Neg();
  LED3_Neg();

  LED3_Off();
  LED2_Off();
  LED1_Off();

  LED1_On();
  if (!LED1_Get()) {
    for(;;){} /*! \todo Need a dedicated error routine? */
  }
  LED1_Off();
  if (LED1_Get()) {
    for(;;){}; /* error */
  }
  LED1_Put(isOn);
  if (!LED1_Get()) {
    for(;;){}; /* error */
  }
}


void LED_Init(void) {
#if 0
  LED_Test();
#endif
  /* all LED's off by default */
  LED1_Off();
  LED2_Off();
  LED3_Off();
}

void LED_Deinit(void) {
  /* nothing to do */
}

/*!
** @}
*/
