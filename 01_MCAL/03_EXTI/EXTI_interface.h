/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< EXTI_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Oct 16, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : EXTI
 *
 *
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#include "STD_TYPES.h"


#define EXTI_LINE0 6
#define EXTI_LINE1 7
#define EXTI_LINE2 5

#define EXTI_FALLING_EDGE 0
#define EXTI_RISING_EDGE  1
#define EXTI_LOW_LEVEL    2
#define EXTI_ON_CHANGE    3



void EXTI_voidInit(void);
void EXTI_voidSetSignalLatch(u8 Copy_u8Line, u8 Copy_u8SenseMode);
void EXTI_voidDisableInterrupt(u8 Copy_u8Line);
void EXTI_voidEnableInterrupt (u8 Copy_u8Line);
void EXTI_voidClearFlag(u8 Copy_u8Line);
u8 EXTI_u8GetFlag(u8 Copy_u8Line);
void EXTI_voidSetCallBack(u8 Copy_u8Line, void(*Copy_pvoidCallBack)(void));
#endif /* EXTI_INTERFACE_H_ */
