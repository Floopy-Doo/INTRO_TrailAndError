/**
 * \file
 * \brief Real Time Operating System (RTOS) main program.
 * \author Erich Styger, erich.styger@hslu.ch
 */

#include "Platform.h"
#if PL_HAS_RTOS
#include "RTOS.h"
#include "FRTOS1.h"
#include "LED.h"
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

static portTASK_FUNCTION(T1, pvParameters) {
  for(;;) {
    LED1_Neg();
    FRTOS1_vTaskDelay(100/portTICK_RATE_MS);
  }
}


static void MainTask(void *pvParameters) {
	(void)pvParameters;
	for(;;){
	KEY_Scan();
		EVNT_HandleEvent(APP_HandleEvent);
		FRTOS1_vTaskDelay(50/portTICK_RATE_MS);
	/*    LED1_Neg();
	    FRTOS1_vTaskDelay(100/portTICK_RATE_MS);*/
	}
}

void RTOS_Run(void) {

	if (FRTOS1_xTaskCreate(MainTask,"Main",configMINIMAL_STACK_SIZE+100,(void*)NULL,tskIDLE_PRIORITY,(xTaskHandle*)NULL) != pdPASS){
		for(;;){}/* error */
	}

	FRTOS1_vTaskStartScheduler();
}

void RTOS_Init(void) {
  /*! \todo Add tasks here */

  if (FRTOS1_xTaskCreate(T1, (signed portCHAR *)"T1", configMINIMAL_STACK_SIZE, NULL, tskIDLE_PRIORITY, NULL) != pdPASS) {
    for(;;){} /* error */
  }
}

void RTOS_Deinit(void) {
}

#endif /* PL_HAS_RTOS */


