
#include "Platform.h"
#include "Timer.h"
#include "LED.h"
#include "Event.h"
#include "Trigger.h"


void TMR_OnInterrupt(void){
	TRG_IncTick();
	//EVNT_SetEvent(EVNT_LED_ON);	//Wirfe bei Timerinterrupt ein Event. Wird in Application.c behandelt
}

/*! \brief Timer driver initialization */
void TMR_Init(void){

}

/*! \brief Timer driver de-initialization */
void TMR_Deinit(void){

}
