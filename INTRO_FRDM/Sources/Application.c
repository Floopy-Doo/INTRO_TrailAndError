/*
 * Application.c
 *
 *  Created on: 02.03.2015
 *      Author: Philipp Gosswiler
 */

#include "Application.h"
#include "Platform.h"
#include "LED.h"
#include "Event.h"
#include "Timer.h"
#include "WAIT.h"
#include "LED_FRDM.h"
#include "Keys.h"
#include "CLS1.h"
#include "Trigger.h"
#include "Shell.h"
#include "RTOS.h"
#include "RNet_AppConfig.h"
#include "RNet_App.h"
#include "RApp.h"
#include "Remote.h"

uint8_t val8 = 0;

void APP_Start(void) {
	// Initialize Platform
	PL_Init();
	KEY_EnableInterrupts();
	CLS1_Init();
	RTOS_Run();
}

void APP_DebugPrint(unsigned char *str) {
#if PL_HAS_SHELL
  SHELL_SendString(str);
#endif
}


void APP_HandleEvent(EVNT_Handle event) {
	switch (event) {
    case EVNT_STARTUP:
      LED1_On();
      WAIT_Waitms(50);
      LED1_Off();
#if PL_HAS_BUZZER
      BUZ_Beep(300, 500);
#endif
     break;
    case EVNT_HEARTBEAT:
      LED1_Neg();
      break;
#if PL_NOF_KEYS >= 1
    case EVNT_SW1_PRESSED:
      CLS1_SendStr("A short\r\n", CLS1_GetStdio()->stdOut);
      // Remote ein/aus
      val8 = 2;
     (void)RAPP_SendPayloadDataBlock(&val8, sizeof(val8), RAPP_MSG_TYPE_DATA, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE); /* only send low byte */
      REMOTE_SetOnOff(!REMOTE_GetOnOff());

      break;
    case EVNT_SW1_LPRESSED:
      CLS1_SendStr("A long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW1_RELEASED:
      CLS1_SendStr("A released\r\n", CLS1_GetStdio()->stdOut);
      break;
      break;
#endif
#if PL_NOF_KEYS >= 2
    case EVNT_SW2_PRESSED:
      CLS1_SendStr("B short\r\n", CLS1_GetStdio()->stdOut);
      // Notstop
      val8 = 1;
      (void)RAPP_SendPayloadDataBlock(&val8, sizeof(val8), RAPP_MSG_TYPE_DATA, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE); /* only send low byte */
      break;
    case EVNT_SW2_LPRESSED:
      CLS1_SendStr("B long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW2_RELEASED:
      CLS1_SendStr("B released\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 3
    case EVNT_SW3_PRESSED:
      CLS1_SendStr("C short\r\n", CLS1_GetStdio()->stdOut);
      // Motor ein
		val8 = 3;
		(void)RAPP_SendPayloadDataBlock(&val8, sizeof(val8), RAPP_MSG_TYPE_DATA, RNETA_GetDestAddr(), RPHY_PACKET_FLAGS_NONE); /* only send low byte */
		break;
    case EVNT_SW3_LPRESSED:
      CLS1_SendStr("C long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW3_RELEASED:
      CLS1_SendStr("C released\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 4
    case EVNT_SW4_PRESSED:
      CLS1_SendStr("D short\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW4_LPRESSED:
      CLS1_SendStr("D long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW4_RELEASED:
      CLS1_SendStr("D released\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 5
    case EVNT_SW5_PRESSED:
      CLS1_SendStr("SW5\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW5_LPRESSED:
      CLS1_SendStr("SW5 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW5_RELEASED:
      CLS1_SendStr("SW5 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 6
    case EVNT_SW6_PRESSED:
      CLS1_SendStr("SW6\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW6_LPRESSED:
      CLS1_SendStr("SW6 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW6_RELEASED:
      CLS1_SendStr("SW6 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
#if PL_NOF_KEYS >= 7
    case EVNT_SW7_PRESSED:
      CLS1_SendStr("SW7\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW7_LPRESSED:
      CLS1_SendStr("SW7 long\r\n", CLS1_GetStdio()->stdOut);
      break;
    case EVNT_SW7_RELEASED:
      CLS1_SendStr("SW7 release\r\n", CLS1_GetStdio()->stdOut);
      break;
#endif
		default: /* do nothing */
			break;
	}
}
