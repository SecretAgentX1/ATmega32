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

#define ADLAR 5

#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3


#define ADC_IDLE 0
#define ADC_BUSY 1


#define ADC_CHANNEL_ASYNCH        0
#define ADC_CHAIN_ASYNCH          1
#define ADC_AUTO_TRIGGER_ASYNCH   2

#define ADC_CONF   0
#define ADC_RECONF 1

u16 ADC_u16Read         (void);
void ADC_voidSaveConfig (void);
void ADC_u8SetCallBack  (void(*pfCallBack)(void));


#endif /* ADC_PRIVATE_H_ */
