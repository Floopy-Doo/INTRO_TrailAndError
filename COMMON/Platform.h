

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


#if PL_IS_FRDM
  #include "MKL25Z4.h"
  #include "LED_FDRM.h"
#elif PL_IS_ROBO
  #include "MK22F12.h"
  #include "LED_Robo.h"
#else
  #error "unknown CPU?"
#endif


#define LED_ENABLE (1)
  /*!< Set to 1 to enable LED support, 0 otherwise */
#define PL_HAS_EVENTS (1)
  /*!< Set to 1 to enable events, 0 otherwise */
#define PL_HAS_TIMER    (1)
  /*!< Set to 1 to enable timers, 0 otherwise */
#define PL_HAS_KEYS           (1)
  /*!< Set to 1 to enable keys, 0 otherwise */
#define PL_HAS_KBI            (1)
  /*!< Set to 1 to enable key interrupt support, 0 otherwise */
#define PL_HAS_KBI_NMI        (1 && PL_IS_FRDM && PL_HAS_JOYSTICK)
  /*!< Set to 1 for special case on NMI/PTA pin on FRDM board, 0 otherwise */
#define PL_HAS_MEALY          (1 && PL_NOF_LEDS>=1 && PL_NOF_KEYS>=1)
  /*!< Set to 1 to enable Mealy sequential state machine, 0 otherwise */
#define PL_HAS_RESET_KEY      (0 && PL_IS_FRDM && PL_HAS_KEYS)
  /*!< Set to 1 to use reset switch on FRDM as button, 0 otherwise */
#define PL_HAS_JOYSTICK       (1 && PL_IS_FRDM && PL_HAS_KEYS)
  /*!< Set to 1 to enable joystick shield support, 0 otherwise */
#define PL_HAS_TRIGGER        (1)
  /*!< Set to 1 for trigger enabled, 0 otherwise */
#define PL_HAS_SHELL          (0)
  /*!< Set to 1 for shell enabled, 0 otherwise */
#define PL_HAS_BUZZER         (1 && PL_IS_ROBO)
  /*!< Set to 1 for buzzer enabled, 0 otherwise */

/* if keys are using interrupts or are polled */
#if PL_IS_FRDM
  #define PL_KEY_POLLED_KEY1    (0)
  #define PL_KEY_POLLED_KEY2    (0)
  #define PL_KEY_POLLED_KEY3    (0)
  #define PL_KEY_POLLED_KEY4    (0)
  #define PL_KEY_POLLED_KEY5    (1)
  #define PL_KEY_POLLED_KEY6    (1)
  #define PL_KEY_POLLED_KEY7    (0)
#elif PL_IS_ROBO
  #define PL_KEY_POLLED_KEY1    (0)
#endif

#if PL_IS_FRDM
  #if PL_HAS_JOYSTICK
    #define PL_NOF_LEDS       (2)
      /*!< FRDM board has 2 LEDs (blue is used by joystick shield/nrf24L01+ SPI CLK) */
    #define PL_NOF_KEYS       (7)
       /*!< FRDM board has no keys without joystick shield */
  #else
    #define PL_NOF_LEDS       (3)
       /*!< FRDM board has up to 3 LEDs (RGB) */
#if PL_HAS_RESET_KEY
    #define PL_NOF_KEYS       (1)
       /*!< FRDM board with using the reset button */
#else
    #define PL_NOF_KEYS       (0)
       /*!< FRDM board has no keys without joystick shield */
#endif
  #endif
#elif PL_IS_ROBO
  #define PL_NOF_LEDS       (2)
     /*!< We have up to 2 LED's on the robo board */
  #define PL_NOF_KEYS       (1)
     /*!< We have up to 1 push button */
#else
  #error "unknown configuration?"
#endif


void PL_Init(void);
void PL_Deinit(void);

#endif /* PLATFORM_H_ */
