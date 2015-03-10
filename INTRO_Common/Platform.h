/**
 * \file
 * \brief Platform Interface.
 * \author Erich Styger, erich.styger@hslu.ch
 *
 * This implements the platform interface.
 * Here the platform gets initialized, and all platform dependent macros get defined.
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

#include "PE_Types.h" /* for common Processor Expert types used throughout the project, e.g. 'bool' */
#include "PE_Error.h" /* global error constants */

/* List of supported platforms. The PL_BOARD_IS_xxx is defined in the compiler command line settings.  */
#define PL_IS_FRDM   (defined(PL_BOARD_IS_FRDM))
  /*!< Macro is defined through compiler option for the FRDM board */
#define PL_IS_ROBO   (defined(PL_BOARD_IS_ROBO))
  /*!< Macro is defined through compiler option for the Robot board */

#if 0 /* test only */
#if PL_IS_FRDM
  #include "MKL25Z4.h"
#elif PL_IS_ROBO
  #include "MK22F12.h"
#else
  #error "unknown CPU?"
#endif
#endif

#define PL_HAS_LED      (1)
  /*!< Set to 1 to enable LED support, 0 otherwise */
#define PL_HAS_EVENTS   (1)
  /*!< Set to 1 to enable events, 0 otherwise */

#if PL_IS_FRDM
  #define PL_NOF_LEDS       (3)
      /*!< FRDM board has 3 LEDs (RGB) */
#elif PL_IS_ROBO
  #define PL_NOF_LEDS       (2)
     /*!< We have up to 2 LED's on the robo board */
#else
  #error "unknown configuration?"
#endif

void PL_Init(void);
void PL_Deinit(void);

#endif /* PLATFORM_H_ */
