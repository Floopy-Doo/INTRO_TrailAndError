/**
 * \file
 * \brief Platform implementation module.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This implements the platform module.
 * Here the platform gets initialized, and all platform dependent macros get defined.
 */
/*!
**  @addtogroup PLATFORM_module Platform module documentation
**  @{
*/

#include "Platform.h"
#include "LED.h"
#include "Event.h"
#include "Timer.h"
#include "Mealy.h"
#include "Keys.h"
#include "Trigger.h"
#include "Buzzer.h"
#include "Debounce.h"
#include "RTOS.h"
#include "Shell.h"
#include "ShellQueue.h"

#if PL_HAS_SHELL
  #include "CLS1.h"
#endif
#if PL_HAS_BLTH
  #include "BT1.h"
#endif
//#include "Buzzer.h"

void PL_Init(void) {
#if PL_HAS_LED
  LED_Init();
#endif
#if PL_HAS_EVENTS
  EVNT_Init();
#endif
#if PL_HAS_TIMER
  TMR_Init();
#endif
#if PL_HAS_KEYS
  KEY_Init();
#endif
#if PL_HAS_MEALY
  MEALY_Init();
#endif
#if PL_HAS_TRIGGER
  TRG_Init();
#endif
#if PL_HAS_BUZZER
  BUZ_Init();
#endif
#if PL_HAS_DEBOUNCE
  DBNC_Init();
#endif
#if PL_HAS_RTOS
  RTOS_Init();
#endif
#if PL_HAS_SHELL
  SHELL_Init();
#endif
#if PL_HAS_SHELL_QUEUE
  SQUEUE_Init();
#endif



}

void PL_Deinit(void) {
#if PL_HAS_SHELL_QUEUE
  SQUEUE_Deinit();
#endif
#if PL_HAS_SHELL
  SHELL_Deinit();
#endif
#if PL_HAS_RTOS
  RTOS_Deinit();
#endif
#if PL_HAS_DEBOUNCE
  DBNC_Deinit();
#endif
#if PL_HAS_BUZZER
  BUZ_Deinit();
#endif
#if PL_HAS_TRIGGER
  TRG_Deinit();
#endif
#if PL_HAS_MEALY
  MEALY_Deinit();
#endif
#if PL_HAS_KEYS
  KEY_Deinit();
#endif
#if PL_HAS_TIMER
  TMR_Deinit();
#endif
#if PL_HAS_EVENTS
  EVNT_Deinit();
#endif
#if PL_HAS_LED
  LED_Deinit();
#endif
}

/*!
** @}
*/
