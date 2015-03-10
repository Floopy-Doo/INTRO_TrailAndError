
#include "../../COMMON/Timer.h"
#include "../../COMMON/LED.h"


/*! \brief Timer driver initialization */
void TMR_Init(void){
	Timer1ms_SetPeriodMS(TMR_TICK_MS);
	Timer1ms_Enable();
	Timer1ms_EnableEvent();

}

/*! \brief Timer driver de-initialization */
void TMR_Deinit(void){
	Timer1ms_DisableEvent();
	Timer1ms_Disable();
}
