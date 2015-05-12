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
#include "Event.h"
#include "Timer.h"
#include "WAIT.h"
#include "Keys.h"
#include "CLS1.h"
#include "Trigger.h"
#include "Reflectance.h"
#include "DriveFunction.h"
#include "Remote.h"
#include "Shell.h"
#include "Accel.h"



static portTASK_FUNCTION(T1, pvParameters) {
	 uint8_t buf[64];
	 uint16_t x;
	 uint16_t y;
	 uint16_t z;
	 static bool driveState =1;

  for(;;) {
    LED_Neg(LED_ALL);
    /*SHELL_SendString((unsigned char*)"\nUltrasonic Distance:");
    UTIL1_Num16uToStr(buf, sizeof(buf), US_GetLastCentimeterValue());
    SHELL_SendString((unsigned char*) buf);
*/
  /*  ACCEL_GetValues(&x,&y,&z);
    SHELL_SendString((unsigned char*)"\nAccel \tx:");
    UTIL1_Num16sToStr(buf, sizeof(buf), x);
    SHELL_SendString((unsigned char*) buf);

    SHELL_SendString((unsigned char*)" \ty:");
    UTIL1_Num16sToStr(buf, sizeof(buf), y);
    SHELL_SendString((unsigned char*) buf);

    SHELL_SendString((unsigned char*)"\tz:");
    UTIL1_Num16sToStr(buf, sizeof(buf), z);
    SHELL_SendString((unsigned char*) buf);
*/


#if PL_HAS_DRIVE
    if(checkUpsideDown()){
    	driveState = DRV_isEnabled();
    	DRV_EnableDisable(FALSE);
    } else {

    	DRV_EnableDisable(TRUE);
    }
#endif
    FRTOS1_vTaskDelay(100/portTICK_RATE_MS);
  }
}


static void MainTask(void *pvParameters) {
	(void)pvParameters;
	(void)ACCEL_LowLevelInit();

	for(;;){
		KEY_Scan();
		EVNT_HandleEvent(APP_HandleEvent);
		if(!REMOTE_GetOnOff()){
			DRIVEFCNT_HandleEvent();
		}
		FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
	}
}

static void FightTask(void *pvParameters) {
	(void)pvParameters;
	for(;;){
		#if PL_IS_ROBO
			if(!REMOTE_GetOnOff()){
				DRIVEFCNT_HandleEvent();
			}
		#endif
		FRTOS1_vTaskDelay(10/portTICK_RATE_MS);
	}
}

void RTOS_Run(void) {

	if (FRTOS1_xTaskCreate(MainTask,"Main",configMINIMAL_STACK_SIZE+100,(void*)NULL,tskIDLE_PRIORITY,(xTaskHandle*)NULL) != pdPASS){
		for(;;){}/* error */
	}
	//if (FRTOS1_xTaskCreate(FightTask,"Fight",configMINIMAL_STACK_SIZE+100,(void*)NULL,tskIDLE_PRIORITY,(xTaskHandle*)NULL) != pdPASS){
	//	for(;;){}/* error */
	//}
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


