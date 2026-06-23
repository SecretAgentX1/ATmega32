/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Jun 20, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : DIO/GPIO
 *
 *
 */


#include "../../03_LIB/STD_TYPES.h"
#include "../../03_LIB/BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection (DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN, DIO_Direction_t Copy_u8Direction){
	if(Copy_u8Direction == DIO_OUTPUT){
		switch(Copy_u8PORT){
			case DIO_PORTA:SET_BIT(DDRA,Copy_u8PIN);break;
			case DIO_PORTB:SET_BIT(DDRB,Copy_u8PIN);break;
			case DIO_PORTC:SET_BIT(DDRC,Copy_u8PIN);break;
			case DIO_PORTD:SET_BIT(DDRD,Copy_u8PIN);break;
		}
	}
	else if (Copy_u8Direction == DIO_INPUT){
		switch(Copy_u8PORT){
			case DIO_PORTA:CLR_BIT(DDRA,Copy_u8PIN);break;
			case DIO_PORTB:CLR_BIT(DDRB,Copy_u8PIN);break;
			case DIO_PORTC:CLR_BIT(DDRC,Copy_u8PIN);break;
			case DIO_PORTD:CLR_BIT(DDRD,Copy_u8PIN);break;
		}
	}
}
void DIO_voidSetPinValue     (DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN, DIO_PIN_Value_t Copy_u8Value){
	if(Copy_u8Value == DIO_HIGH){
		switch(Copy_u8PORT){
			case DIO_PORTA:SET_BIT(PORTA,Copy_u8PIN);break;
			case DIO_PORTB:SET_BIT(PORTB,Copy_u8PIN);break;
			case DIO_PORTC:SET_BIT(PORTC,Copy_u8PIN);break;
			case DIO_PORTD:SET_BIT(PORTD,Copy_u8PIN);break;
		}
	}
	else if (Copy_u8Value == DIO_LOW){
		switch(Copy_u8PORT){
			case DIO_PORTA:CLR_BIT(PORTA,Copy_u8PIN);break;
			case DIO_PORTB:CLR_BIT(PORTB,Copy_u8PIN);break;
			case DIO_PORTC:CLR_BIT(PORTC,Copy_u8PIN);break;
			case DIO_PORTD:CLR_BIT(PORTD,Copy_u8PIN);break;
		}
	}
}
DIO_PIN_Value_t   DIO_enumGetPinValue     (DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN){
	u8 LOC_u8Status;
	switch(Copy_u8PORT){
		case DIO_PORTA:LOC_u8Status = GET_BIT(PINA,Copy_u8PIN);break;
		case DIO_PORTB:LOC_u8Status = GET_BIT(PINB,Copy_u8PIN);break;
		case DIO_PORTC:LOC_u8Status = GET_BIT(PINC,Copy_u8PIN);break;
		case DIO_PORTD:LOC_u8Status = GET_BIT(PIND,Copy_u8PIN);break;
	}
	return LOC_u8Status;

}


void DIO_voidTogglePinValue(DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN){
	switch(Copy_u8PORT){
		case DIO_PORTA:TOG_BIT(PORTA,Copy_u8PIN);break;
		case DIO_PORTB:TOG_BIT(PORTB,Copy_u8PIN);break;
		case DIO_PORTC:TOG_BIT(PORTC,Copy_u8PIN);break;
		case DIO_PORTD:TOG_BIT(PORTD,Copy_u8PIN);break;
	}
}

void DIO_voidSetPortDirection (DIO_PORT_t Copy_u8PORT, u8 Copy_u8Direction){
	switch(Copy_u8PORT){
		case DIO_PORTA:DDRA=Copy_u8Direction;break;
		case DIO_PORTB:DDRB=Copy_u8Direction;break;
		case DIO_PORTC:DDRC=Copy_u8Direction;break;
		case DIO_PORTD:DDRD=Copy_u8Direction;break;
	}
}
void DIO_voidSetPortValue     (DIO_PORT_t Copy_u8PORT,  u8 Copy_u8Value    ){
	switch(Copy_u8PORT){
		case DIO_PORTA:PORTA=Copy_u8Value;break;
		case DIO_PORTB:PORTB=Copy_u8Value;break;
		case DIO_PORTC:PORTC=Copy_u8Value;break;
		case DIO_PORTD:PORTD=Copy_u8Value;break;
	}
}
u8   DIO_u8GetPortValue       (DIO_PORT_t Copy_u8PORT                      ){
	u8 LOC_u8Value;
	switch(Copy_u8PORT){
		case DIO_PORTA:LOC_u8Value=PINA;break;
		case DIO_PORTB:LOC_u8Value=PINB;break;
		case DIO_PORTC:LOC_u8Value=PINC;break;
		case DIO_PORTD:LOC_u8Value=PIND;break;
	}
	return LOC_u8Value;
}

void DIO_voidTogglePortValue(DIO_PORT_t Copy_u8PORT){
	switch(Copy_u8PORT){
		case DIO_PORTA:PORTA=~PORTA;break;
		case DIO_PORTB:PORTB=~PORTB;break;
		case DIO_PORTC:PORTC=~PORTC;break;
		case DIO_PORTD:PORTD=~PORTD;break;
	}
}
