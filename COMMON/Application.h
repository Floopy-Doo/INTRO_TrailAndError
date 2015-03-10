/**
 * \file
 * \brief Application entry point
 * \author Philipp Gosswiler <philipp.gosswiler@stud.hslu.ch>
 * \author Reto Ritter <reto.ritter@stud.hslu.ch>
 *
 * Entry point to the application. All of the non generated code should be placed within Application.c. Avoid adding individual code to main.c.
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Event.h"

/*!
 * Entry point to the application.
 */
void APP_Start(void);

void APP_HandleEvent(EVNT_Handle event);

#endif /* APPLICATION_H_ */
