/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_config.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Jun 20, 2026
 *  Author: Ali Osama Ismail
 *  Layer : APPLICATION
 *
 *
 */

#include "./01_MCAL/01_DIO/DIO_interface.h"
#include <util/delay.h>

void main(){
	//DIO_voidSetPinDirection(0,0,1);
	DIO_voidSetPortDirection(0,0xFF);
	//DIO_voidSetPinValue(0,0,1);
	while(1){
	DIO_voidSetPortValue(0,0xFF);
	_delay_ms(1000);
	DIO_voidSetPortValue(0,0);
	_delay_ms(1000);
	}

}


