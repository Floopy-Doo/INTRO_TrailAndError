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

void PL_Init(void) {
#if PL_HAS_LED
  LED_Init();
#endif
#if PL_HAS_EVENTS
  EVNT_Init();
#endif
}

void PL_Deinit(void) {
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
