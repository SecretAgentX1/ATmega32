/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Jun 20, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : DIO/GPIO
 *
 *
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../03_LIB/STD_TYPES.h"
typedef enum {
	DIO_INPUT,
	DIO_OUTPUT
} DIO_Direction_t;

typedef enum {
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
} DIO_PORT_t;

typedef enum {
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
} DIO_PIN_t;

typedef enum {
	DIO_LOW,
	DIO_HIGH
} DIO_PIN_Value_t;

typedef enum {
	DIO_NOK,
	DIO_OK
} DIO_ErrorStatus;
DIO_ErrorStatus DIO_enumSetPinDirection (DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN, DIO_Direction_t Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPinValue     (DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN, DIO_PIN_Value_t Copy_u8Value    );
DIO_ErrorStatus DIO_enumGetPinValue     (DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN, u8 * Copy_u8PtrData			   );
DIO_ErrorStatus DIO_enumTogglePinValue	(DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN                                  );



DIO_ErrorStatus DIO_enumSetPortDirection (DIO_PORT_t Copy_u8PORT, u8 Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPortValue     (DIO_PORT_t Copy_u8PORT, u8 Copy_u8Value   );
DIO_ErrorStatus DIO_enumGetPortValue     (DIO_PORT_t Copy_u8PORT, u8 * Copy_u8PtrData  );
DIO_ErrorStatus DIO_enumTogglePortValue  (DIO_PORT_t Copy_u8PORT);


DIO_ErrorStatus DIO_enumWriteLowNibble (DIO_PORT_t Copy_u8PORT, u8 Copy_u8Value);
DIO_ErrorStatus DIO_enumWriteHighNibble(DIO_PORT_t Copy_u8PORT, u8 Copy_u8Value);


#endif /* DIO_INTERFACE_H_ */
