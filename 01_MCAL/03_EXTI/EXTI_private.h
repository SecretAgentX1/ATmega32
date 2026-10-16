/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< EXTI_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Oct 16, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : EXTI
 *
 *
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define GICR   *((volatile u8*)0x5B)
#define GIFR   *((volatile u8*)0x5A)
#define MCUCR  *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)

#endif /* EXTI_PRIVATE_H_ */
