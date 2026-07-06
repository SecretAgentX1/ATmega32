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


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

DIO_ErrorStatus DIO_enumSetPinDirection (DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN, DIO_Direction_t Copy_u8Direction){

	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if(Copy_u8PORT<= DIO_PORTD && Copy_u8PIN<=DIO_PIN7){
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
		else LOC_enumState = DIO_NOK;
	}
	else LOC_enumState = DIO_NOK;

	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumSetPinValue(DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN, DIO_PIN_Value_t Copy_u8Value){

	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if(Copy_u8PORT<= DIO_PORTD && Copy_u8PIN<=DIO_PIN7){
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
		else LOC_enumState = DIO_NOK;
	}
	else LOC_enumState = DIO_NOK;

	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumGetPinValue(DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN, u8 *Copy_u8PtrData){
	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if(Copy_u8PORT <= DIO_PORTD && Copy_u8PIN<=DIO_PIN7){
		switch(Copy_u8PORT){
			case DIO_PORTA: *Copy_u8PtrData = GET_BIT(PINA,Copy_u8PIN);break;
			case DIO_PORTB: *Copy_u8PtrData = GET_BIT(PINB,Copy_u8PIN);break;
			case DIO_PORTC: *Copy_u8PtrData = GET_BIT(PINC,Copy_u8PIN);break;
			case DIO_PORTD: *Copy_u8PtrData = GET_BIT(PIND,Copy_u8PIN);break;
		}
	}
	else LOC_enumState = DIO_NOK;

	return LOC_enumState;

}
DIO_ErrorStatus DIO_enumTogglePinValue(DIO_PORT_t Copy_u8PORT, DIO_PIN_t Copy_u8PIN){

	DIO_ErrorStatus LOC_enumState = DIO_OK;

	if(Copy_u8PORT <= DIO_PORTD && Copy_u8PIN<=DIO_PIN7){
		switch(Copy_u8PORT){
			case DIO_PORTA:TOG_BIT(PORTA,Copy_u8PIN);break;
			case DIO_PORTB:TOG_BIT(PORTB,Copy_u8PIN);break;
			case DIO_PORTC:TOG_BIT(PORTC,Copy_u8PIN);break;
			case DIO_PORTD:TOG_BIT(PORTD,Copy_u8PIN);break;
		}
	}
	else LOC_enumState = DIO_NOK;

	return LOC_enumState;
}



DIO_ErrorStatus DIO_enumSetPortDirection (DIO_PORT_t Copy_u8PORT, u8 Copy_u8Direction){
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	switch(Copy_u8PORT){
		case DIO_PORTA:DDRA=Copy_u8Direction;break;
		case DIO_PORTB:DDRB=Copy_u8Direction;break;
		case DIO_PORTC:DDRC=Copy_u8Direction;break;
		case DIO_PORTD:DDRD=Copy_u8Direction;break;
		default:LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumSetPortValue(DIO_PORT_t Copy_u8PORT,  u8 Copy_u8Value    ){
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	switch(Copy_u8PORT){
		case DIO_PORTA:PORTA=Copy_u8Value;break;
		case DIO_PORTB:PORTB=Copy_u8Value;break;
		case DIO_PORTC:PORTC=Copy_u8Value;break;
		case DIO_PORTD:PORTD=Copy_u8Value;break;
		default:LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumGetPortValue(DIO_PORT_t Copy_u8PORT, u8 * Copy_u8PtrData){
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	switch(Copy_u8PORT){
		case DIO_PORTA: *Copy_u8PtrData=PINA;break;
		case DIO_PORTB: *Copy_u8PtrData=PINB;break;
		case DIO_PORTC: *Copy_u8PtrData=PINC;break;
		case DIO_PORTD: *Copy_u8PtrData=PIND;break;
		default:LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumTogglePortValue(DIO_PORT_t Copy_u8PORT){
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	switch(Copy_u8PORT){
		case DIO_PORTA:PORTA=~PORTA;break;
		case DIO_PORTB:PORTB=~PORTB;break;
		case DIO_PORTC:PORTC=~PORTC;break;
		case DIO_PORTD:PORTD=~PORTD;break;
		default:LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}

DIO_ErrorStatus DIO_enumWriteLowNibble (DIO_PORT_t Copy_u8PORT, u8 Copy_u8Value){
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	Copy_u8Value &= 0x0F;
	u8 LOC_u8Temp;
	switch(Copy_u8PORT){
		case DIO_PORTA:
			LOC_u8Temp = PORTA;
			LOC_u8Temp &= 0xF0;
			LOC_u8Temp |= Copy_u8Value;
			PORTA = LOC_u8Temp;
			break;
		case DIO_PORTB:
			LOC_u8Temp = PORTB;
			LOC_u8Temp &= 0xF0;
			LOC_u8Temp |= Copy_u8Value;
			PORTB = LOC_u8Temp;
			break;
		case DIO_PORTC:
			LOC_u8Temp = PORTC;
			LOC_u8Temp &= 0xF0;
			LOC_u8Temp |= Copy_u8Value;
			PORTC = LOC_u8Temp;
			break;
		case DIO_PORTD:
			LOC_u8Temp = PORTD;
			LOC_u8Temp &= 0xF0;
			LOC_u8Temp |= Copy_u8Value;
			PORTD = LOC_u8Temp;
			break;
		default:LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
DIO_ErrorStatus DIO_enumWriteHighNibble(DIO_PORT_t Copy_u8PORT, u8 Copy_u8Value){
	DIO_ErrorStatus LOC_enumState = DIO_OK;
	Copy_u8Value &=0x0F;
	Copy_u8Value <<=4;
	u8 LOC_u8Temp;
	switch(Copy_u8PORT){
		case DIO_PORTA:
			LOC_u8Temp = PORTA;
			LOC_u8Temp &= 0x0F;
			LOC_u8Temp |= Copy_u8Value;
			PORTA = LOC_u8Temp;
			break;
		case DIO_PORTB:
			LOC_u8Temp = PORTB;
			LOC_u8Temp &= 0x0F;
			LOC_u8Temp |= Copy_u8Value;
			PORTB = LOC_u8Temp;
			break;
		case DIO_PORTC:
			LOC_u8Temp = PORTC;
			LOC_u8Temp &= 0x0F;
			LOC_u8Temp |= Copy_u8Value;
			PORTC = LOC_u8Temp;
			break;
		case DIO_PORTD:
			LOC_u8Temp = PORTD;
			LOC_u8Temp &= 0x0F;
			LOC_u8Temp |= Copy_u8Value;
			PORTD = LOC_u8Temp;
			break;
		default:LOC_enumState = DIO_NOK;
	}
	return LOC_enumState;
}
