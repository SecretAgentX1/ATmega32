/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< GIE_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Oct 21, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : GIE
 *
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"


void GIE_voidEnable (void){
	SET_BIT(SREG,SREG_I);
}
void GIE_voidDisable(void){
	CLR_BIT(SREG,SREG_I);
}
