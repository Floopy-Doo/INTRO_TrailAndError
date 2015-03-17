/*!
 * \file
 * \brief	
 * \author	Philipp Gosswiler <philipp.gosswiler@stud.hslu.ch>
 * \author	Reto Ritter <reto.ritter@stud.hslu.ch>
 *
 *
 */

#ifndef EVENT_H_
#define EVENT_H_

#include "Platform.h"
#include "PE_Types.h"

#if PL_HAS_EVENTS

typedef enum EVNT_Handle {
  EVNT_INIT,            /*!< System Initialization Event */
  EVNT_LED_ON,			/*!< LEDs on Event */
  EVNT_LED_OFF,			/*!< LEDs off Event */
  EVNT_LED_NEG,
  EVNT_SW1_PRESSED,
  EVNT_SW2_PRESSED,
  EVNT_SW3_PRESSED,
  EVNT_SW4_PRESSED,
  EVNT_SW5_PRESSED,
  EVNT_SW6_PRESSED,
  EVNT_SW7_PRESSED,
  EVNT_NOF_EVENTS       /*!< Must be last one! */
} EVNT_Handle;

/*!
 * \brief Sets an event.
 * \param[in] event The handle of the event to set.
 */
void EVNT_SetEvent(EVNT_Handle event);

/*!
 * \brief Clears an event.
 * \param[in] event The event handle of the event to clear.
 */
void EVNT_ClearEvent(EVNT_Handle event);

/*!
 * \brief Returns the status of an event.
 * \param[in] event The event handler of the event to check.
 * \return TRUE if the event is set, FALSE otherwise.
 */
bool EVNT_EventIsSet(EVNT_Handle event);

/*!
 * \brief Returns the status of an event. As a side effect, the event gets cleared.
 * \param[in] event The event handler of the event to check.
 * \return TRUE if the event is set, FALSE otherwise.
 */
bool EVNT_EventIsSetAutoClear(EVNT_Handle event);

/*!
 * \brief Routine to check if an event is pending. If an event is pending, the event is cleared and the provided callback is called.
 * \param[in] callback Callback routine to be called. The event handle is passed as argument to the callback.
 */
void EVNT_HandleEvent(void (*callback)(EVNT_Handle));

/*! \brief Event module initialization */
void EVNT_Init(void);

/*! \brief Event module de-initialization */
void EVNT_Deinit(void);

#endif /* PL_HAS_EVENTS */

#endif /* EVENT_H_ */
