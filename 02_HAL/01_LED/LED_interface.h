/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Jun 30, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : LED
 *
 *
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"

typedef enum{
	LED_ACTIVE_LOW,
	LED_ACTIVE_HIGH
}LED_Connection;

typedef enum {
	LED_NOK,
	LED_OK,
	LED_NULL_POINTER,
	LED_INVALID_CONNECTION
} LED_ErrorStatus;

typedef struct{
	DIO_PORT_t Port;
	DIO_PIN_t Pin;
	LED_Connection connection;
}LED_t;


LED_ErrorStatus LED_enumInit  (const LED_t* Copy_structLED);
LED_ErrorStatus LED_enumOn    (const LED_t* Copy_structLED);
LED_ErrorStatus LED_enumOff   (const LED_t* Copy_structLED);
LED_ErrorStatus LED_enumToggle(const LED_t* Copy_structLED);




#endif /* LED_INTERFACE_H_ */
