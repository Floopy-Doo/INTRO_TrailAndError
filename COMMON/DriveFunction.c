/*
 * DriveFunctions.c
 *
 *  Created on: 11.05.2015
 *      Author: Roman
 */
#include "Platform.h"
#include "DriveFunction.h"

#if PL_IS_ROBO
uint16_t test = 0;
uint16_t us;
uint16_t cm;

DRIVEFCNT_Handle event = DRIVEFCNT_STARTUP;

void  DRIVEFCNT_SetEVENT(DRIVEFCNT_Handle aevent){
	event = aevent;
}

DRIVEFCNT_Handle DRIVEFCNT_GetEVENT(void){
	return event;
}


//Rückwärtfahrende Blondine
void DRIVEFCNT_DriveJeanette(void){
	DRV_SetSpeed(-0x800,-0x800);
	WAIT_Waitms(100);
}

void checkLine(void){
	if((REF_GetLineValue()<=3000)&& (REF_GetLineValue()>0)){
		DRV_SetSpeed(0x00,-0x800);
		WAIT_Waitms(100);
	}
	else if(REF_GetLineValue()>=4000){
		DRV_SetSpeed(-0x800,0x00);
		WAIT_Waitms(100);
	}
	else if(REF_GetLineValue()==3500){
		DRV_SetSpeed(-0x800,-0x800);
	}
}

void DRIVEFCNT_HandleEvent(void) {
	if (event !=DRIVEFCNT_STARTUP){
		checkLine();
	}

	switch (event) {

		case DRIVEFCNT_STARTUP:
			//event = DRIVEFCNT_SEARCH_FOR_ENEMYS;
			DRV_SetSpeed(0,0);
		break;

/*		case DRIVEFCNT_DRIVE_IN_CIRCLE:
			if((REF_GetLineValue()<=3000)&& (REF_GetLineValue()>0)){

				DRV_SetSpeed(0x00,-0x800);
				WAIT_Waitms(100);
			}
			else if(REF_GetLineValue()>=4000){

				DRV_SetSpeed(-0x800,0x00);
				WAIT_Waitms(100);

			}
			else if(REF_GetLineValue()==0){
				DRV_SetSpeed(0x800,0x800);
			}
			else{
				DRV_SetSpeed(-0x800,-0x800);
			}
		break;
*/
		case DRIVEFCNT_SEARCH_FOR_ENEMYS:
			 while((REF_GetLineValue()<=5)&&(event == DRIVEFCNT_SEARCH_FOR_ENEMYS)){
				if((cm < 70) && (cm > 0)){
					DRV_SetSpeed(0x800,0x800);
				}
				else{
				   DRV_SetSpeed(0x400,-0x400);
				}
				cm = US_usToCentimeters(US_Measure_us(), 22);
			 }
		break;

		default:
		break;

	}
}
#endif
