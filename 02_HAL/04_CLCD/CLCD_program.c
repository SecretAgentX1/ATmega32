/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CLCD_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Sep 22, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : CLCD
 *
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_extrachar.h"
#include <util/delay.h>

static void voidSendFallingEdge(const CLCD_t* Copy_structCLCD){
	DIO_enumSetPinValue (Copy_structCLCD->PortEN, Copy_structCLCD->PinEN, DIO_HIGH); 
	_delay_ms(1);
	DIO_enumSetPinValue (Copy_structCLCD->PortEN, Copy_structCLCD->PinEN, DIO_LOW );
	_delay_ms(1);

}
void CLCD_voidInit(const CLCD_t* Copy_structCLCD){
	DIO_enumSetPortDirection(Copy_structCLCD->PortData, DIO_OUTPUT);
	DIO_enumSetPinDirection (Copy_structCLCD->PortEN, Copy_structCLCD->PinEN, DIO_OUTPUT);
	DIO_enumSetPinDirection (Copy_structCLCD->PortRW, Copy_structCLCD->PinRW, DIO_OUTPUT);
	DIO_enumSetPinDirection (Copy_structCLCD->PortRS, Copy_structCLCD->PinRS, DIO_OUTPUT);
	_delay_ms(50);
	CLCD_voidSendCommand(Copy_structCLCD, 0x38);
	// _delay_ms(1);
	CLCD_voidSendCommand(Copy_structCLCD, 0x0C);
	// _delay_ms(1);
	CLCD_voidSendCommand(Copy_structCLCD, 0x01);
	// _delay_ms(10);
	CLCD_voidSendCommand(Copy_structCLCD, 0x06);
}

void CLCD_voidSendData   (const CLCD_t* Copy_structCLCD, u8 Copy_u8Data    ){
	DIO_enumSetPortValue(Copy_structCLCD->PortData, Copy_u8Data);
	DIO_enumSetPinValue (Copy_structCLCD->PortRS, Copy_structCLCD->PinRS, DIO_HIGH  );
	DIO_enumSetPinValue (Copy_structCLCD->PortRW, Copy_structCLCD->PinRW, CLCD_WRITE);
	
	voidSendFallingEdge(Copy_structCLCD);


}
void CLCD_voidSendCommand(const CLCD_t* Copy_structCLCD, u8 Copy_u8Command){
	DIO_enumSetPortValue(Copy_structCLCD->PortData, Copy_u8Command);
	DIO_enumSetPinValue (Copy_structCLCD->PortRS, Copy_structCLCD->PinRS, DIO_LOW   );
	DIO_enumSetPinValue (Copy_structCLCD->PortRW, Copy_structCLCD->PinRW, CLCD_WRITE);

	voidSendFallingEdge(Copy_structCLCD);
	
	if(Copy_u8Command == _Clcd_Clear || Copy_u8Command == _Clcd_ReturnHome)
		_delay_ms(1);

}


void CLCD_voidSendString (const CLCD_t* Copy_structCLCD, const u8* Copy_u8String){
	DIO_enumSetPortValue(Copy_structCLCD->PortData, Copy_u8String[0]);
	DIO_enumSetPinValue (Copy_structCLCD->PortRS, Copy_structCLCD->PinRS, DIO_HIGH  );
	DIO_enumSetPinValue (Copy_structCLCD->PortRW, Copy_structCLCD->PinRW, CLCD_WRITE);
	voidSendFallingEdge(Copy_structCLCD);
	u8 num = 1;
	while(Copy_u8String[num] != '\0'){
		DIO_enumSetPortValue(Copy_structCLCD->PortData, Copy_u8String[num]);
		voidSendFallingEdge(Copy_structCLCD);
		num++;
	}
}


void CLCD_voidSetPosition(const CLCD_t* Copy_structCLCD, u8 Copy_u8Row, u8 Copy_u8Col){
	u8 LOC_u8Data = _Clcd_SetCursor;
	if(Copy_u8Col >= CLCD_COL_1 && Copy_u8Col <= CLCD_COL_16){
		if(Copy_u8Row == CLCD_ROW_1){
			LOC_u8Data = LOC_u8Data + Copy_u8Col - 1;
		}
		else if(Copy_u8Row == CLCD_ROW_2){
			LOC_u8Data = LOC_u8Data + Copy_u8Col + 63;
		}
	}
	CLCD_voidSendCommand(Copy_structCLCD, LOC_u8Data);
}

void CLCD_voidSendExtraChar (const CLCD_t* Copy_structCLCD, u8 Copy_u8Row, u8 Copy_u8Col){
	u8 LOC_u8Iterator = 0;
	CLCD_voidSendCommand(Copy_structCLCD,_Clcd_CGRAM);

	for(;LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]) ; LOC_u8Iterator++){
		CLCD_voidSendData(Copy_structCLCD, CLCD_u8ExtraChar[LOC_u8Iterator] );
	}
	CLCD_voidSetPosition(Copy_structCLCD,Copy_u8Row,Copy_u8Col);

	for(LOC_u8Iterator = 0;LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]) / 8; LOC_u8Iterator++){
		CLCD_voidSendData(Copy_structCLCD, LOC_u8Iterator );
	}

}