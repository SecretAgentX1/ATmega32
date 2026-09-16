/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SW_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Sept 16, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : SW
 *
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

#include "SW_interface.h"
#include "SW_private.h"
#include "SW_config.h"

SW_ErrorStatus SW_enumInit (const SW_Type* Copy_structSW){
	SW_ErrorStatus LOC_enumState = SW_OK;
	DIO_ErrorStatus LOC_enumDioStatus = DIO_OK;
	if(NULL == Copy_structSW) return SW_NULL_POINTER;
	LOC_enumDioStatus = DIO_enumSetPinDirection(Copy_structSW->Port,Copy_structSW->Pin,DIO_INPUT);
	if(LOC_enumDioStatus==DIO_NOK || Copy_structSW->Pull_State > 3) LOC_enumState = SW_NOK;
	else{
		if(Copy_structSW->Pull_State == SW_Int_Pull_UP){
			LOC_enumDioStatus = DIO_enumSetPinValue(Copy_structSW->Port,Copy_structSW->Pin,DIO_HIGH);
			if(LOC_enumDioStatus==DIO_NOK) LOC_enumState = SW_NOK;
		}
	}

	return LOC_enumState;
}
SW_ErrorStatus SW_enumGetPressed (const SW_Type* Copy_structSW, u8* Copy_u8PressData){

	SW_ErrorStatus LOC_enumState = SW_OK;
	DIO_ErrorStatus LOC_enumDioStatus = DIO_OK;

	
	if(NULL == Copy_structSW || NULL == Copy_u8PressData) LOC_enumState = SW_NULL_POINTER;
	else{
		u8 LOC_u8PinVal = SW_NOT_PRESSED;
		*Copy_u8PressData = SW_NOT_PRESSED;
		LOC_enumDioStatus = DIO_enumGetPinValue( Copy_structSW->Port , Copy_structSW->Pin , &LOC_u8PinVal );
		if(LOC_enumDioStatus == DIO_NOK || Copy_structSW->Pull_State > 3) LOC_enumState = SW_NOK;
		else {
			if(Copy_structSW->Pull_State == SW_Int_Pull_UP || Copy_structSW->Pull_State == SW_Ext_Pull_UP){
				if(LOC_u8PinVal == 0){
					*Copy_u8PressData = SW_PRESSED;
				}
				else if(LOC_u8PinVal == 1){
					*Copy_u8PressData = SW_NOT_PRESSED;
				}
			}
			else if(Copy_structSW->Pull_State == SW_Ext_Pull_DOWN){
				if(LOC_u8PinVal == 1){
					*Copy_u8PressData = SW_PRESSED;
				}
				else if(LOC_u8PinVal == 0){
					*Copy_u8PressData = SW_NOT_PRESSED;
				}
			}
		}
	}



	return LOC_enumState;

}