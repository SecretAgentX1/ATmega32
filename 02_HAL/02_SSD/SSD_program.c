/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Jul 3, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : SSD
 *
 *
 */


#include "../../03_LIB/BIT_MATH.h"

#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

static const u8 SSD_NumberPattern[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

SSD_ErrorStatus SSD_enumInit  (const SSD_t* Copy_structSSD){
	SSD_ErrorStatus LOC_enumState = SSD_OK;
	if(NULL == Copy_structSSD) return SSD_NULL_POINTER;
	LOC_enumState = DIO_enumSetPortDirection(Copy_structSSD->DataPort,0xFF);
	return LOC_enumState;
}

SSD_ErrorStatus SSD_enumOn    (const SSD_t* Copy_structSSD){
	SSD_ErrorStatus LOC_enumState = SSD_OK;
	if(NULL == Copy_structSSD) return SSD_NULL_POINTER;
	switch(Copy_structSSD->Type){
	case SSD_COM_CATHODE:
		LOC_enumState = DIO_enumSetPinDirection(Copy_structSSD->EnablePort,Copy_structSSD->EnablePin,DIO_OUTPUT);
		if(LOC_enumState == SSD_NOK) return LOC_enumState;
		LOC_enumState = DIO_enumSetPinValue(Copy_structSSD->EnablePort,Copy_structSSD->EnablePin,DIO_HIGH);
		break;
	case SSD_COM_ANODE:
		LOC_enumState = DIO_enumSetPinDirection(Copy_structSSD->EnablePort,Copy_structSSD->EnablePin,DIO_OUTPUT);
		if(LOC_enumState == SSD_NOK) return LOC_enumState;
		LOC_enumState = DIO_enumSetPinValue(Copy_structSSD->EnablePort,Copy_structSSD->EnablePin,DIO_LOW);
		break;

	default: return SSD_INVALID_TYPE;
	}
	return LOC_enumState;
}


SSD_ErrorStatus SSD_enumOff   (const SSD_t* Copy_structSSD){
	SSD_ErrorStatus LOC_enumState = SSD_OK;
	if(NULL == Copy_structSSD) return SSD_NULL_POINTER;
	switch(Copy_structSSD->Type){
	case SSD_COM_CATHODE:
		LOC_enumState = DIO_enumSetPinDirection(Copy_structSSD->EnablePort,Copy_structSSD->EnablePin,DIO_OUTPUT);
		if(LOC_enumState == SSD_NOK) return LOC_enumState;
		LOC_enumState = DIO_enumSetPinValue(Copy_structSSD->EnablePort,Copy_structSSD->EnablePin,DIO_LOW);
		break;
	case SSD_COM_ANODE:
		LOC_enumState = DIO_enumSetPinDirection(Copy_structSSD->EnablePort,Copy_structSSD->EnablePin,DIO_OUTPUT);
		if(LOC_enumState == SSD_NOK) return LOC_enumState;
		LOC_enumState = DIO_enumSetPinValue(Copy_structSSD->EnablePort,Copy_structSSD->EnablePin,DIO_HIGH);
		break;

	default: return SSD_INVALID_TYPE;
	}
	return LOC_enumState;
}


SSD_ErrorStatus SSD_enumDisplayNum(const SSD_t* Copy_structSSD,u8 Copy_u8Number){
	SSD_ErrorStatus LOC_enumState = SSD_OK;
	if(NULL == Copy_structSSD) return SSD_NULL_POINTER;
	if(Copy_u8Number>9) return SSD_INVALID_NUMBER;
	switch(Copy_structSSD->Type){
		case SSD_COM_CATHODE:
			LOC_enumState = DIO_enumSetPortValue(Copy_structSSD->DataPort,SSD_NumberPattern[Copy_u8Number]);
			break;
		case SSD_COM_ANODE:
			LOC_enumState = DIO_enumSetPortValue(Copy_structSSD->DataPort,(u8)~SSD_NumberPattern[Copy_u8Number]);
			break;

		default: return SSD_INVALID_TYPE;
		}
	return LOC_enumState;
}
