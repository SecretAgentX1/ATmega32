/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< ADC_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Created on: Nov 9, 2026
 *  Author: Ali Osama Ismail
 *  Layer : MCAL
 *  SWC   : ADC
 *
 *
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_config.h"
#include "ADC_interface.h"
#include "ADC_private.h"

void ADC_voidInit(){
	#if ADC_REFERENCE == INTERNAL_REF
		SET_BIT(ADMUX, 7);
		SET_BIT(ADMUX, 6);
	#elif ADC_REFERENCE == EXTERNAL_AVCC
		CLR_BIT(ADMUX, 7);
		SET_BIT(ADMUX, 6);
	#elif ADC_REFERENCE == EXTERNAL_AREF
		CLR_BIT(ADMUX, 7);
		CLR_BIT(ADMUX, 6);
	#else
		#error "Invalid ADC Reference Selection"
	#endif

	#if ADJ_DIR == LEFT_ADJ
		SET_BIT(ADMUX, 5);
	#elif ADJ_DIR == RIGHT_ADJ
		CLR_BIT(ADMUX, 5);
	#endif

	WRITE_BITS(ADMUX,ADC_CHANNEL,0,4);

	#if ADC_MODE == ADC_AUTO_TRIGGER
		SET_BIT(ADCSRA,5);
		WRITE_BITS(SFIOR,ADC_TRIGGER_SOURCE,5,7);
	#elif ADC_MODE == ADC_SINGLE_CONVERSION
		CLR_BIT(ADCSRA,5);
	#else
		#error "Invalid ADC Trigger Source"
	#endif

	#if ADC_METHOD == ADC_INTERRUPT
		SET_BIT(ADCSRA,3);
	#elif ADC_METHOD == ADC_POLLING
		CLR_BIT(ADCSRA,3);
	#else
		#error "Invalid ADC Method"
	#endif

	#if ADC_PRESCALER>=ADC_DIV2 && ADC_PRESCALER <= ADC_DIV128 && ADC_PRESCALER != 1
		WRITE_BITS(ADCSRA,ADC_PRESCALER,0,2);
	#else
		#error "Invalid ADC prescaler"
	#endif

	SET_BIT(ADCSRA, ADEN);

}

u16 ADC_u16Read(){
	u8 LOC_u8Low;
	u8 LOC_u8High;
	u16 LOC_u16All = (u16)0;
	SET_BIT(ADCSRA,ADSC);
	while(GET_BIT(ADCSRA,ADIF) == 0){
		if(GET_BIT(ADCSRA,ADEN) == 0) break;
	}
	if(GET_BIT(ADCSRA,ADEN) == 0) return -1;

	#if ADJ_DIR == RIGHT_ADJ
		LOC_u8Low = (u8)ADCL;
		LOC_u8High = (u8)ADCH;
		LOC_u16All = ((u16)LOC_u8Low) | (((u16)LOC_u8High) << 8);
	#elif ADJ_DIR == LEFT_ADJ
		#if LEFT_VALUE == APPROXIMATE_VALUE
			LOC_u8High = (u8)ADCH;
			LOC_u16All = ((u16)LOC_u8High) << 2;
		#elif LEFT_VALUE == ALL_VALUE
			LOC_u8Low = (u8)ADCL;
			LOC_u8High = (u8)ADCH;
			LOC_u16All = ((u16)LOC_u8High) << 2 | ((u16)LOC_u8Low >> 6);
		#else
			#error "Invalid Left Value Method"
		#endif
	#else
		#error "Invalid Adjustment Direction"
	#endif
	SET_BIT(ADCSRA, ADIF);

	return LOC_u16All;
}

