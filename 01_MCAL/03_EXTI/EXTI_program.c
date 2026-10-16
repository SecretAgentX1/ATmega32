/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< EXTI_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Oct 16, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : EXTI
 *
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"

void(*EXTI_CallBack[3])(void) = { NULL };

void EXTI_voidInit(void){
	// Line 0
	#ifdef EXTI_LINE_EN0
		#if EXTI_SENSE_MODE0 == EXTI_FALLING_EDGE
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		#elif EXTI_SENSE_MODE0 == EXTI_RISING_EDGE
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		#elif EXTI_SENSE_MODE0 == EXTI_LOW_LEVEL
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		#elif EXTI_SENSE_MODE0 == EXTI_ON_CHANGE
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		#else
			#error "Wrong configuration in EXTI_SENSE_MODE0"
		#endif
		SET_BIT(GICR,EXTI_LINE0);
	#endif
	// Line 1
	#ifdef EXTI_LINE_EN1
		#if EXTI_SENSE_MODE1 == EXTI_FALLING_EDGE
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		#elif EXTI_SENSE_MODE1 == EXTI_RISING_EDGE
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		#elif EXTI_SENSE_MODE1 == EXTI_LOW_LEVEL
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		#elif EXTI_SENSE_MODE1 == EXTI_ON_CHANGE
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		#else
			#error "Wrong configuration in EXTI_SENSE_MODE1"
		#endif
		SET_BIT(GICR,EXTI_LINE1);
	#endif
	// Line 2
	#ifdef EXTI_LINE_EN2
		#if EXTI_SENSE_MODE2 == EXTI_FALLING_EDGE
			CLR_BIT(MCUCSR,6);
		#elif EXTI_SENSE_MODE2 == EXTI_RISING_EDGE
			SET_BIT(MCUCSR,6);
		#else
			#error "Wrong configuration in EXTI_SENSE_MODE2"
		#endif
		SET_BIT(GICR,EXTI_LINE2);
	#endif
}

void EXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8SenseMode){
	if(Copy_u8Line >= EXTI_LINE0 && Copy_u8Line <=EXTI_LINE1){
		Copy_u8Line = Copy_u8Line == EXTI_LINE0 ? 0 : 2 ;
		switch(Copy_u8SenseMode){
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCR,Copy_u8Line);
			SET_BIT(MCUCR,Copy_u8Line + 1);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCR,Copy_u8Line);
			SET_BIT(MCUCR,Copy_u8Line + 1);
			break;
		case EXTI_LOW_LEVEL:
			CLR_BIT(MCUCR,Copy_u8Line);
			CLR_BIT(MCUCR,Copy_u8Line + 1);
			break;
		case EXTI_ON_CHANGE:
			SET_BIT(MCUCR,Copy_u8Line);
			CLR_BIT(MCUCR,Copy_u8Line + 1);
			break;
		default: break;
		}
	}
	else if(Copy_u8Line == EXTI_LINE2){
		switch(Copy_u8SenseMode){
		case EXTI_FALLING_EDGE:
			CLR_BIT(MCUCSR,Copy_u8Line + 1);
			break;
		case EXTI_RISING_EDGE:
			SET_BIT(MCUCSR,Copy_u8Line + 1);
			break;
		default: break;
		}
	}
}

void EXTI_voidDisableInterrupt(u8 Copy_u8Line){
	if(Copy_u8Line >= 5 && Copy_u8Line <= 7)CLR_BIT(GICR,Copy_u8Line);
}
void EXTI_voidEnableInterrupt (u8 Copy_u8Line){
	if(Copy_u8Line >= 5 && Copy_u8Line <= 7)SET_BIT(GICR,Copy_u8Line);
}

void EXTI_voidClearFlag(u8 Copy_u8Line){
	if(Copy_u8Line >= 5 && Copy_u8Line <= 7)SET_BIT(GIFR,Copy_u8Line);
}

u8 EXTI_u8GetFlag(u8 Copy_u8Line){
	u8 LOC_u8FlagValue = 0;
	if(Copy_u8Line >= 5 && Copy_u8Line <= 7) LOC_u8FlagValue = GET_BIT(GIFR,Copy_u8Line);

	return LOC_u8FlagValue;
}


void EXTI_voidSetCallBack(u8 Copy_u8Line, void(*Copy_pvoidCallBack)(void)){
	if(Copy_pvoidCallBack != NULL && Copy_u8Line >=5 && Copy_u8Line<= 7){
		Copy_u8Line = ((u8)(Copy_u8Line - 6)) % 11;
		EXTI_CallBack[Copy_u8Line] = Copy_pvoidCallBack;
	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(EXTI_CallBack[0] != NULL ){
		EXTI_CallBack[0]();
		EXTI_voidClearFlag(EXTI_LINE0);
	}
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(EXTI_CallBack[1] != NULL ){
		EXTI_CallBack[1]();
		EXTI_voidClearFlag(EXTI_LINE1);
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(EXTI_CallBack[2] != NULL ){
		EXTI_CallBack[2]();
		EXTI_voidClearFlag(EXTI_LINE2);
	}
}

