/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< KPD_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Oct 7, 2026
 *  Author: Ali Osama Ismail
 *  Layer : HAL
 *  SWC   : KPD
 *
 *
 */


#include "STD_TYPES.h"
#include "DIO_interface.h"
#include <util/delay.h>

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

void KPD_voidInit(){
	u8 LOC_u8Row;
	u8 LOC_u8Col;
	for(LOC_u8Row = 0 + KPD_ROW_INIT ;LOC_u8Row <= KPD_ROW_END; ++LOC_u8Row){
		DIO_enumConnectPullup   (KPD_ROW_PORT , LOC_u8Row , DIO_HIGH);
	}

	for(LOC_u8Col = 0 + KPD_COL_INIT; LOC_u8Col <= KPD_COL_END; ++LOC_u8Col){
		DIO_enumSetPinDirection (KPD_COL_PORT,LOC_u8Col,DIO_OUTPUT);
		DIO_enumSetPinValue     (KPD_COL_PORT,LOC_u8Col,DIO_HIGH);
	}
}
u8 KPD_u8GetPressed(){
	u8 LOC_u8ReturnData = NOTPRESSED;
	u8 LOC_u8GetPressed;
	u8 LOC_u8Row;
	u8 LOC_u8Col;


	for(LOC_u8Col = 0 + KPD_COL_INIT; LOC_u8Col <= KPD_COL_END; ++LOC_u8Col)
	{
		DIO_enumSetPinValue(KPD_COL_PORT,LOC_u8Col,DIO_LOW);
		for(LOC_u8Row = 0 + KPD_ROW_INIT ;LOC_u8Row <= KPD_ROW_END; ++LOC_u8Row)
		{
			DIO_enumGetPinValue(KPD_ROW_PORT,LOC_u8Row,&LOC_u8GetPressed);


			if(LOC_u8GetPressed == DIO_LOW)
			{
				_delay_ms(50);
				DIO_enumGetPinValue(KPD_ROW_PORT,LOC_u8Row,&LOC_u8GetPressed);



				if(LOC_u8GetPressed == DIO_LOW)
				{
					LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT];
					do{
						DIO_enumGetPinValue(KPD_ROW_PORT,LOC_u8Row,&LOC_u8GetPressed);
					}while(LOC_u8GetPressed == DIO_LOW);
					break;
				}


			}


		}
		DIO_enumSetPinValue(KPD_COL_PORT,LOC_u8Col,DIO_HIGH);
		if(LOC_u8ReturnData != NOTPRESSED)break;

	}
	return LOC_u8ReturnData;
}
























