/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADC_config.h >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Nov 9, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : ADC
 *
 *
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* Select Reference
 *  	INTERNAL_REF  -> FOR internal 2.56 volt WITH external capacitor at  AREF pin
 *  	EXTERNAL_AVCC -> External from AVCC WITH external capacitor at  AREF pin
 *  	EXTERNAL_AREF -> External from AREF WITH external capacitor at  AREF pin
 */
#define ADC_REFERENCE EXTERNAL_AVCC



/*
 *  Adjustment Direction
 *  	LEFT_ADJ
 *  	RIGHT_ADJ
 */
#define ADJ_DIR RIGHT_ADJ

/*
 *  Left Adjustment Value
 *  	ALL_VALUE
 *  	APPROXIMATE_VALUE
 */
#define LEFT_VALUE ALL_VALUE


/*
 *  Channels and Gain
 * 		Single Ended
 * 			ADC0 -> from 0 to 7
 * 			ADC_VBG -> 1.22V
 * 			ADC_GND -> 0V
 * 		Differential Ended
 * 			with gain 10
 * 				ADC_1G00 - ADC_1G10 - ADC_1G22 - ADC_1G23
 * 			with gain 200
 * 				ADC_2G00 - ADC_2G10 - ADC_2G22 - ADC_2G23
 * 			With gain 1
 * 				ADC(0:7)1 - ADC(0:5)2
 */
#define ADC_CHANNEL ADC0



/*
 *  ADC Modes
 *  	ADC_SINGLE_CONVERSION
 *  	ADC_AUTO_TRIGGER
 */

#define ADC_MODE ADC_SINGLE_CONVERSION


/*
 *  ADC Trigger Source
 *  	ADC_FR
 *  	ADC_AC
 *  	ADC_EXTI0
 *  	ADC_TIMER0_COMP
 *  	ADC_TIMER0_OVER
 *  	ADC_TIMER1_COMP
 *  	ADC_TIMER1_OVER
 *  	ADC_TIMER1_CAP
 */
#define ADC_TRIGGER_SOURCE ADC_FR


/*
 *  ADC Method
 *  	ADC_INTERRUPT
 *  	ADC_POLLING
 */

#define ADC_METHOD ADC_POLLING



/*
 *  ADC_PRESCALER
 *  	ADC_DIV2 -> 2 - 4 - 8 - 16 - 32 - 64 - 128
 */

#define ADC_PRESCALER ADC_DIV128





#endif /* ADC_CONFIG_H_ */
