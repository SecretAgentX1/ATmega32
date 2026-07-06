/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Jun 30, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : LED
 *
 *
 */


#include "BIT_MATH.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

LED_ErrorStatus LED_enumInit(const LED_t* Copy_structLED){

	LED_ErrorStatus LOC_enumStatus = LED_OK;
	DIO_ErrorStatus LOC_enumDioStatus = DIO_OK;
	if(NULL == Copy_structLED) LOC_enumStatus = LED_NULL_POINTER;
	else {
		LOC_enumDioStatus=DIO_enumSetPinDirection(Copy_structLED->Port,Copy_structLED->Pin,DIO_OUTPUT);
		if(LOC_enumDioStatus==DIO_NOK) LOC_enumStatus = LED_NOK;
		else{
			switch(Copy_structLED->connection){
			case LED_ACTIVE_LOW:
				LOC_enumDioStatus=DIO_enumSetPinValue(Copy_structLED->Port,Copy_structLED->Pin,DIO_HIGH);break;
			case LED_ACTIVE_HIGH:
				LOC_enumDioStatus=DIO_enumSetPinValue(Copy_structLED->Port,Copy_structLED->Pin,DIO_LOW);break;
			default:
				LOC_enumStatus = LED_INVALID_CONNECTION;
			}
		}
		if(LOC_enumDioStatus==DIO_NOK) LOC_enumStatus = LED_NOK;
	}

	return LOC_enumStatus;
}


LED_ErrorStatus LED_enumOn(const LED_t* Copy_structLED){
	LED_ErrorStatus LOC_enumStatus = LED_OK;
	DIO_ErrorStatus LOC_enumDioStatus = DIO_OK;
	if(NULL == Copy_structLED) LOC_enumStatus = LED_NULL_POINTER;
	else {

		switch(Copy_structLED->connection){
		case LED_ACTIVE_LOW:
			LOC_enumDioStatus=DIO_enumSetPinValue(Copy_structLED->Port,Copy_structLED->Pin,DIO_LOW);break;
		case LED_ACTIVE_HIGH:
			LOC_enumDioStatus=DIO_enumSetPinValue(Copy_structLED->Port,Copy_structLED->Pin,DIO_HIGH);break;
		default:
			LOC_enumStatus = LED_INVALID_CONNECTION;break;
		}
	}
	if(LOC_enumDioStatus==DIO_NOK) LOC_enumStatus = LED_NOK;


	return LOC_enumStatus;
}
LED_ErrorStatus LED_enumOff(const LED_t* Copy_structLED){
	LED_ErrorStatus LOC_enumStatus = LED_OK;
	DIO_ErrorStatus LOC_enumDioStatus = DIO_OK;
	if(NULL == Copy_structLED) LOC_enumStatus = LED_NULL_POINTER;
	else {

		switch(Copy_structLED->connection){
		case LED_ACTIVE_LOW:
			LOC_enumDioStatus=DIO_enumSetPinValue(Copy_structLED->Port,Copy_structLED->Pin,DIO_HIGH);break;
		case LED_ACTIVE_HIGH:
			LOC_enumDioStatus=DIO_enumSetPinValue(Copy_structLED->Port,Copy_structLED->Pin,DIO_LOW);break;
		default:
			LOC_enumStatus = LED_INVALID_CONNECTION;break;
		}
	}
	if(LOC_enumDioStatus==DIO_NOK) LOC_enumStatus = LED_NOK;


	return LOC_enumStatus;
}

LED_ErrorStatus LED_enumToggle(const LED_t* Copy_structLED){
	LED_ErrorStatus LOC_enumStatus = LED_OK;
	DIO_ErrorStatus LOC_enumDioStatus = DIO_OK;
	if(NULL == Copy_structLED) LOC_enumStatus = LED_NULL_POINTER;
	else {
		LOC_enumDioStatus=DIO_enumTogglePinValue(Copy_structLED->Port,Copy_structLED->Pin);
		if(LOC_enumDioStatus==DIO_NOK) LOC_enumStatus = LED_NOK;
	}
	return LOC_enumStatus;
}
