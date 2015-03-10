/**
 * \file
 * \brief Platform initialization
 * \author Philipp Gosswiler <philipp.gosswiler@stud.hslu.ch>
 * \author Reto Ritter <reto.ritter@stud.hslu.ch>
 *
 * Provides means to initialize and finalize the platform.
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#define LED_ENABLE (1)
#define LED_TEST (LED_ENABLE & 1)
#define EVENT_ENABLED (1)
#define PL_HAS_AS_TIMER (1)


// Initialization
/*!
 * Initializes the platform.
 */
void PL_Init(void);

/*!
 * Finalizes the platform.
 */
void PL_Deinit(void);


#endif /* PLATFORM_H_ */
