/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CLCD_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Sep 22, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : CLCD
 *
 *
 */

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_
#include "STD_TYPES.h"
#include "DIO_interface.h"


#define bit4 0
#define bit8 1

#define CLCD_WRITE 0
#define CLCD_READ  1

// Commands
#define _Clcd_Clear       0x01
#define _Clcd_ReturnHome  0x02
#define _Clcd_EntryShL    0x07
#define _Clcd_EntryShR    0x05
#define _Clcd_EntryCurR   0x06
#define _Clcd_EntryCurL   0x04
#define _Clcd_DisplayOn   0x0C
#define _Clcd_DisplayOff  0x08
#define _Clcd_CursorOn 	  0x0E
#define _Clcd_CursorOff   0x0C
#define _Clcd_BlinkOn	  0x0F
#define _Clcd_BlinkOff	  0x0E
#define _Clcd_CursorRight 0x14
#define _Clcd_CursorLeft  0x10
#define _Clcd_ShiftLeft	  0x18
#define _Clcd_ShiftRight  0x1C

#define _Clcd_SetCursor   0x80
#define _Clcd_CGRAM       0x40





#define CLCD_ROW_1   1
#define CLCD_ROW_2   2

#define CLCD_COL_1   1
#define CLCD_COL_2   2
#define CLCD_COL_3   3
#define CLCD_COL_4   4
#define CLCD_COL_5   5
#define CLCD_COL_6   6
#define CLCD_COL_7   7
#define CLCD_COL_8   8
#define CLCD_COL_9   9
#define CLCD_COL_10  10
#define CLCD_COL_11  11
#define CLCD_COL_12  12
#define CLCD_COL_13  13
#define CLCD_COL_14  14
#define CLCD_COL_15  15
#define CLCD_COL_16  16



typedef struct{
	DIO_PORT_t PortEN;
	DIO_PIN_t PinEN;
	DIO_PORT_t PortRS;
	DIO_PIN_t PinRS;
	DIO_PORT_t PortRW;
	DIO_PIN_t PinRW;
	DIO_PORT_t PortData;
} CLCD_t;



void CLCD_voidInit          (const CLCD_t* Copy_structCLCD);
void CLCD_voidSendData      (const CLCD_t* Copy_structCLCD, u8 Copy_u8Data    );
void CLCD_voidSendCommand   (const CLCD_t* Copy_structCLCD, u8 Copy_u8Command);
void CLCD_voidSendString    (const CLCD_t* Copy_structCLCD, const u8* Copy_u8String);
void CLCD_voidSetPosition   (const CLCD_t* Copy_structCLCD, u8 Copy_u8Row, u8 Copy_u8Col);
void CLCD_voidSendExtraChar (const CLCD_t* Copy_structCLCD, u8 Copy_u8Row, u8 Copy_u8Col);


#endif /* CLCD_INTERFACE_H_ */
