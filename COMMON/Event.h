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
  EVNT_HEARTBEAT,		/*!< LED Heartbeat Event */
  EVNT_STARTUP,
  EVNT_REF_START_STOP_CALIBRATION, //Needed for Reflectance Sensor. Details: Lab #25

#if PL_NOF_KEYS >= 1
  EVNT_SW1_PRESSED,
  EVNT_SW1_LPRESSED,
  EVNT_SW1_RELEASED,
#endif

#if PL_IS_ROBO			//Geplant für die Hauptanwendungs-State-Machine.
  EVNT_DRIVEFORWARD,
  EVNT_WHITELINEDETECTED,
  EVNT_DRIVEBACKWARD,
  EVNT_ULTRASONIC_OBJEC_DETECTED,
#endif
#if PL_NOF_KEYS >= 2
  EVNT_SW2_PRESSED,
  EVNT_SW2_LPRESSED,
  EVNT_SW2_RELEASED,
#endif
#if PL_NOF_KEYS >= 3
  EVNT_SW3_PRESSED,
  EVNT_SW3_LPRESSED,
  EVNT_SW3_RELEASED,
#endif
#if PL_NOF_KEYS >= 4
  EVNT_SW4_PRESSED,
  EVNT_SW4_LPRESSED,
  EVNT_SW4_RELEASED,
#endif
#if PL_NOF_KEYS >= 5
  EVNT_SW5_PRESSED,
  EVNT_SW5_LPRESSED,
  EVNT_SW5_RELEASED,
#endif
#if PL_NOF_KEYS >= 6
  EVNT_SW6_PRESSED,
  EVNT_SW6_LPRESSED,
  EVNT_SW6_RELEASED,
#endif
#if PL_NOF_KEYS >= 7
  EVNT_SW7_PRESSED,
  EVNT_SW7_LPRESSED,
  EVNT_SW7_RELEASED,
#endif
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
