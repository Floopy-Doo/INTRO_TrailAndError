/*
 * DriveFunction.h
 *
 *  Created on: 11.05.2015
 *      Author: Roman
 */

#ifndef DRIVEFUNCTION_H_
#define DRIVEFUNCTION_H_
#if PL_IS_ROBO
#include "Platform.h"
#include "Drive.h"
#include "Reflectance.h"
#include "Ultrasonic.h"
#include "Wait.h"

typedef enum DRIVEFCNT_Handle {
	DRIVEFCNT_STARTUP,
	DRIVEFCNT_SEARCH_FOR_ENEMYS,            /*!< System Initialization Event */
	DRIVEFCNT_DRIVE_IN_CIRCLE,
	DRIVEFCNT_NOF_EVENTS       /*!< Must be last one! */
} DRIVEFCNT_Handle;

void DRIVEFCNT_HandleEvent(void);
void DRIVEFCNT_SetEVENT(DRIVEFCNT_Handle event);
DRIVEFCNT_Handle DRIVEFCNT_GetEVENT(void);
void DRIVEFCNT_DriveJeanette(void);
void checkLine(void);

#endif /* DRIVEFUNCTION_H_ */
#endif
