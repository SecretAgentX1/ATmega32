/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADC_private.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Nov 9, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : ADC
 *
 *
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX  *((volatile u8*)0x27)
#define ADCSRA *((volatile u8*)0x26)
#define SFIOR  *((volatile u8*)0x50)
#define ADCH   *((volatile u8*)0x25)
#define ADCL   *((volatile u8*)0x24)

u8 ADC_u8DirChanged = 0;

#endif /* ADC_PRIVATE_H_ */
