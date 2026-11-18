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

static u16* ADC_u8ResultAsync;
static void(*pfNotification_Job)(void) = NULL;
static u8 ADC_u8ISRState ;
static u16* ADC_u8ChainResultAsync;
static u8 * ADC_pu8ChainChannel ;
static u8 ADC_u8ChainSize ;
static u8 ADC_u8Index ;
static u8 ADC_u8State= ADC_IDLE ;


//static u8 ADC_u8MethodReconfiguered = 0;
//static u8 ADC_u8NewMethod ;

//static u8 ADC_u8Ref;
//static u8 ADC_u8Channel;
//static u8 ADC_u8Method;
//static u8 ADC_u8Channel;
//static u8 ADC_u8TriggerSource;

static struct ADC_Config
{
	u8 Channel ;
	u8 Mode  ;
	u8 Method;
	u8 ISR_State;
	void(*Notification_Job)(void);
} ADC_u8SavedConfig;

// =============================Helper=====================

u16 ADC_u16Read(){

	u16 LOC_u16All = (u16)0;
	#if ADJ_DIR == RIGHT_ADJ
		LOC_u16All = (ADCL|(ADCH << 8));
	#elif ADJ_DIR == LEFT_ADJ
		#if LEFT_VALUE == APPROXIMATE_VALUE
			LOC_u16All = ADCH << 2;
		#elif LEFT_VALUE == ALL_VALUE

			LOC_u16All = (ADCH << 2) | (ADCL >> 6);
		#else
			#error "Invalid Left Value Method"
		#endif
	#else
		#error "Invalid Adjustment Direction"
	#endif
	return LOC_u16All;
}

void ADC_voidSaveConfig(void){
	ADC_u8SavedConfig.Channel = GET_BITS(ADMUX,0,4);
	ADC_u8SavedConfig.Mode = GET_BIT(ADCSRA,5);
	ADC_u8SavedConfig.Method = GET_BIT(ADCSRA,ADIE);
	ADC_u8SavedConfig.ISR_State = ADC_u8ISRState;
	ADC_u8SavedConfig.Notification_Job = pfNotification_Job;
}

void ADC_voidReturnSaveConfig(){
	WRITE_BITS(ADMUX,ADC_u8SavedConfig.Channel,0,4);
	ADC_u8SavedConfig.Mode ? SET_BIT(ADCSRA,ADATE):CLR_BIT(ADCSRA,ADATE);
	ADC_u8SavedConfig.Method ? SET_BIT(ADCSRA,ADIE):CLR_BIT(ADCSRA,ADIE);
	ADC_u8ISRState = ADC_u8SavedConfig.ISR_State;
	pfNotification_Job = ADC_u8SavedConfig.Notification_Job;
}

void ADC_u8SetCallBack(void(*pfCallBack)(void)){
	pfNotification_Job = pfCallBack;
}
//=========================================================================
void ADC_voidInit(){
	// ====== Reference============
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
	// ================= Adjustment ==============
	#if ADJ_DIR == LEFT_ADJ
		SET_BIT(ADMUX, 5);
	#elif ADJ_DIR == RIGHT_ADJ
		CLR_BIT(ADMUX, 5);
	#endif
	// =============== Channels ======================
	WRITE_BITS(ADMUX,ADC_CHANNEL,0,4);

	// =============== Trigger Source ======================
	#if ADC_MODE == ADC_AUTO_TRIGGER
		SET_BIT(ADCSRA,ADATE);
		WRITE_BITS(SFIOR,ADC_TRIGGER_SOURCE,5,7);
		ADC_u8ISRState = ADC_AUTO_TRIGGER_ASYNCH;
	#elif ADC_MODE == ADC_SINGLE_CONVERSION
		CLR_BIT(ADCSRA,ADATE);
	#else
		#error "Invalid ADC Trigger Source"
	#endif
	// =============== Method ===============
	#if ADC_METHOD == ADC_INTERRUPT
		SET_BIT(ADCSRA,ADIE);
	#elif ADC_METHOD == ADC_POLLING
		CLR_BIT(ADCSRA,ADIE);
	#else
		#error "Invalid ADC Method"
	#endif
	// =============== Prescaler ===============
	#if ADC_PRESCALER>=ADC_DIV2 && ADC_PRESCALER <= ADC_DIV128 && ADC_PRESCALER != 1
		WRITE_BITS(ADCSRA,ADC_PRESCALER,0,2);
	#else
		#error "Invalid ADC prescaler"
	#endif

	SET_BIT(ADCSRA, ADEN);

}

u16 ADC_u16GetResultSync(){
	if(ADC_u8State == ADC_BUSY) return 254;
	SET_BIT(ADCSRA,ADSC);
	while(GET_BIT(ADCSRA,ADIF) == 0){
		if(GET_BIT(ADCSRA,ADEN) == 0) break;
	}
	if(GET_BIT(ADCSRA,ADEN) == 0) return 255;

	SET_BIT(ADCSRA, ADIF);

	return ADC_u16Read();
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,void(*Copy_pfNotification)(void),u16* Copy_u8Result){
	if(Copy_pfNotification == NULL || Copy_u8Result == NULL) return (u8)-1;
	if(ADC_u8State == ADC_BUSY) return (u8)-2;
	ADC_u8State = ADC_BUSY;


	ADC_voidSaveConfig();
	CLR_BIT(ADCSRA,ADEN);
	CLR_BIT(ADCSRA,ADATE);
	SET_BIT(ADCSRA,ADEN);

	ADC_u8ISRState = ADC_CHANNEL_ASYNCH;
	ADC_u8ResultAsync = Copy_u8Result;
	pfNotification_Job = Copy_pfNotification;
	if(Copy_u8Channel >= ADC0 && Copy_u8Channel <=ADC_GND) WRITE_BITS(ADMUX,Copy_u8Channel,0,4);
	SET_BIT(ADCSRA,ADSC);
	SET_BIT(ADCSRA,ADIE);
	return (u8)-10;
}

u8 ADC_u8StartChainAsynch 		 (Chain_t * Copy_Chain){
	if(Copy_Chain == NULL || Copy_Chain->Channel == NULL || Copy_Chain->Result == NULL || Copy_Chain->NotificationJob == NULL)
		return (u8)-1;
	if(ADC_u8State == ADC_BUSY) return (u8)-2;
	ADC_u8State = ADC_BUSY;
// pre conversion
	ADC_voidSaveConfig();
	ADC_u8ISRState = ADC_CHAIN_ASYNCH;
	CLR_BIT(ADCSRA,ADEN);
	CLR_BIT(ADCSRA,ADATE);
	SET_BIT(ADCSRA,ADEN);

	ADC_u8ChainResultAsync = Copy_Chain->Result;
	ADC_pu8ChainChannel = Copy_Chain->Channel;
	ADC_u8ChainSize = Copy_Chain->Size;
	ADC_u8Index = 0;
	pfNotification_Job = Copy_Chain->NotificationJob;
	WRITE_BITS(ADMUX,ADC_pu8ChainChannel[ADC_u8Index],0,4);

	SET_BIT(ADCSRA,ADSC);
	SET_BIT(ADCSRA,ADIE);
	return (u8)-10;
}

u8 ADC_u8StartAutoTrigger        (void(*Copy_pfNotification)(void), u16* Copy_u8Result){
	u8 LOC_u8Status = ADC_OK;
	if(GET_BIT(ADCSRA,ADIE) == 1){
		if(Copy_pfNotification==NULL) LOC_u8Status = ADC_INVALID_NULL_POINTER;
		else pfNotification_Job = Copy_pfNotification;
		if(Copy_u8Result == NULL) LOC_u8Status = ADC_INVALID_NULL_POINTER;
		else ADC_u8ResultAsync = Copy_u8Result;
	}
	LOC_u8Status!=ADC_INVALID_NULL_POINTER?SET_BIT(ADCSRA,ADSC):CLR_BIT(ADCSRA,ADSC);
	return LOC_u8Status;
}

u16 ADC_u16GetAutoResult      (){
	while(GET_BIT(ADCSRA, ADIF) == 0);
	u8 low  = ADCL;
	u8 high = ADCH;
	SET_BIT(ADCSRA, ADIF);
	#if ADC_TRIGGER_SOURCE == ADC_FR
		SET_BIT(ADCSRA, ADSC);           /* restart in case it stalled */
	#endif

	return (u16)low | ((u16)high << 8);
}

void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{
	u8 LOC_u8Low  = ADCL;
	u8 LOC_u8High = ADCH;
	if(ADC_u8ISRState == ADC_CHANNEL_ASYNCH){
		#if ADJ_DIR == RIGHT_ADJ
			*ADC_u8ResultAsync = ((u16)LOC_u8High << 8) | LOC_u8Low;
		#elif ADJ_DIR == LEFT_ADJ
			#if LEFT_VALUE == APPROXIMATE_VALUE
				*ADC_u8ResultAsync = LOC_u8High << 2;
			#elif LEFT_VALUE == ALL_VALUE

				*ADC_u8ResultAsync = (LOC_u8High << 2) | (LOC_u8Low >> 6);
			#else
				#error "Invalid Left Value Method"
			#endif
		#else
			#error "Invalid Adjustment Direction"
		#endif


		ADC_u8State = ADC_IDLE;
		pfNotification_Job();
		ADC_voidReturnSaveConfig();
	}
	else if(ADC_u8ISRState == ADC_CHAIN_ASYNCH){
		#if ADJ_DIR == RIGHT_ADJ
			ADC_u8ChainResultAsync[ADC_u8Index] = ((u16)LOC_u8High << 8) | LOC_u8Low;
		#elif ADJ_DIR == LEFT_ADJ
			#if LEFT_VALUE == APPROXIMATE_VALUE
				ADC_u8ChainResultAsync[ADC_u8Index] = LOC_u8High << 2;
			#elif LEFT_VALUE == ALL_VALUE

				ADC_u8ChainResultAsync[ADC_u8Index] = (LOC_u8High << 2) | (LOC_u8Low >> 6);
			#else
				#error "Invalid Left Value Method"
			#endif
		#else
			#error "Invalid Adjustment Direction"
		#endif

		ADC_u8Index++;

		if(ADC_u8Index == ADC_u8ChainSize){
			ADC_u8State = ADC_IDLE;
			pfNotification_Job();
			ADC_voidReturnSaveConfig();

		}
		else{
			WRITE_BITS(ADMUX,ADC_pu8ChainChannel[ADC_u8Index],0,4);
			SET_BIT(ADCSRA ,ADSC);
		}

	}
	else if(ADC_u8ISRState == ADC_AUTO_TRIGGER_ASYNCH){
		#if ADJ_DIR == RIGHT_ADJ

			*ADC_u8ResultAsync = ((u16)LOC_u8High << 8) | LOC_u8Low;
		#elif ADJ_DIR == LEFT_AD
			#if LEFT_VALUE == APPROXIMATE_VALUE
				*ADC_u8ResultAsync = LOC_u8High << 2;
			#elif LEFT_VALUE == ALL_VALUE

				*ADC_u8ResultAsync = (LOC_u8High << 2) | (LOC_u8Low >> 6);
			#else
				#error "Invalid Left Value Method"
			#endif
		#else
			#error "Invalid Adjustment Direction"
		#endif


		pfNotification_Job();
		SET_BIT(ADCSRA,ADIF);

	}
}
