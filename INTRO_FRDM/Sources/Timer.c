
#include "../../COMMON/Platform.h"
#include "../../COMMON/Timer.h"
#include "../../COMMON/LED.h"
#include "../../COMMON/Event.h"


void TMR_OnInterrupt(void){
	EVNT_SetEvent(EVNT_LED_ON);
}

/*! \brief Timer driver initialization */
void TMR_Init(void){

}

/*! \brief Timer driver de-initialization */
void TMR_Deinit(void){

}