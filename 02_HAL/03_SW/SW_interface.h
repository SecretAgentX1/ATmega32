/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SW_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Sept 16, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : SW
 *
 *
 */

#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_
#include "STD_TYPES.h"
#include "DIO_interface.h"


typedef enum {
	SW_NOK,
	SW_OK,
	SW_NULL_POINTER
} SW_ErrorStatus;

#define SW_PRESSED 1
#define SW_NOT_PRESSED 0


#define SW_Int_Pull_UP 0
#define SW_Ext_Pull_UP 1
#define SW_Ext_Pull_DOWN 2
#define SW_FLOATING 3

typedef struct{
	DIO_PORT_t Port;
	DIO_PIN_t Pin;
	u8 Pull_State;
} SW_Type;


SW_ErrorStatus SW_enumInit (const SW_Type* Copy_structSW);
SW_ErrorStatus SW_enumGetPressed (const SW_Type* Copy_structSW, u8* Copy_u8PressData);



#endif /* SW_INTERFACE_H_ */
