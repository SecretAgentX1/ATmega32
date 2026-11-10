/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADC_interface.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Nov 9, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : ADC
 *
 *
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "STD_TYPES.h"

#define EXTERNAL_AREF 0
#define EXTERNAL_AVCC 1
#define INTERNAL_REF  3


#define RIGHT_ADJ 0
#define LEFT_ADJ  1

#define ALL_VALUE         0
#define APPROXIMATE_VALUE 1


#define ADC0      0
#define ADC1      1
#define ADC2      2
#define ADC3      3
#define ADC4      4
#define ADC5      5
#define ADC6      6
#define ADC7      7

#define ADC_1G00  8
#define ADC_1G10  9
#define ADC_2G00 10
#define ADC_2G10 11
#define ADC_1G22 12
#define ADC_1G32 13
#define ADC_2G22 14
#define ADC_2G32 15

#define ADC01    16
#define ADC11    17
#define ADC21    18
#define ADC31    19
#define ADC41    20
#define ADC51    21
#define ADC61    22
#define ADC71    23
#define ADC02    24
#define ADC12    25
#define ADC22    26
#define ADC32    27
#define ADC42    28
#define ADC52    29
#define ADC_VBG  30
#define ADC_GND  31


#define ADC_SINGLE_CONVERSION 0
#define ADC_AUTO_TRIGGER      1


#define ADC_FR           0
#define ADC_AC           1
#define ADC_EXTI0        2
#define ADC_TIMER0_COMP  3
#define ADC_TIMER0_OVER  4
#define ADC_TIMER1_COMP  5
#define ADC_TIMER1_OVER  6
#define ADC_TIMER1_CAP   7


#define ADC_POLLING   0
#define ADC_INTERRUPT 1


#define ADC_DIV2   0
#define ADC_DIV4   2
#define ADC_DIV8   3
#define ADC_DIV16  4
#define ADC_DIV32  5
#define ADC_DIV64  6
#define ADC_DIV128 7


#define ADLAR 5

#define ADEN  7
#define ADSC  6
#define ADATE 5
#define ADIF  4
#define ADIE  3

#define ADC_CONF_CHANGED 0
#define ADC_CONF         1

void ADC_voidInit(void);
u16 ADC_u16Read   (void);




#endif /* ADC_INTERFACE_H_ */
