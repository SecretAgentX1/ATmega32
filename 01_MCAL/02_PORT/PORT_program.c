/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PORT_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Oct 5, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : PORT
 *
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "PORT_config.h"
#include "PORT_private.h"

void PORT_voidInit(){
	DDRA = PORTA_DIR;
	DDRB = PORTB_DIR;
	DDRC = PORTC_DIR;
	DDRD = PORTD_DIR;


	PORTA = PORTA_VALUE;
	PORTB = PORTB_VALUE;
	PORTC = PORTC_VALUE;
	PORTD = PORTD_VALUE;

}
