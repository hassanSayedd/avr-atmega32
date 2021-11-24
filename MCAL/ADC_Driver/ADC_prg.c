/*
 * ADC_prg.c
 *
 *  Created on: Sep 6, 2019
 *      Author: express
 */

#include"Std_types.h"
#include"Bit_math.h"
#include "Dio_int.h"
#include "ADC_cfg.h"
#include "ADC_int.h"
#include "ADC_priv.h"

void ADC_vidInit(void)
{
	/*************reference voltage selection*****************/

#if Adc_u8ReferenceVoltage==Adc_u8Internal_5Volt

	CLEAR_BIT(ADMUX,7);  //FOR V(REF) 5 volt
	SET_BIT(ADMUX,6);  //FOR V(REF)   5 volt

#elif Adc_u8ReferenceVoltage==Adc_u8Internal_2Volt

	SET_BIT(ADMUX,7);  //FOR V(REF)  for 2.36 volt
	SET_BIT(ADMUX,6);  //FOR V(REF)  for 2.36 volt

#elif Adc_u8ReferenceVoltage==Adc_u8ExternalVolt

	CLEAR_BIT(ADMUX,7);  //FOR V(REF) for external volt the internal volt will turn off
	CLEAR_BIT(ADMUX,6);  //FOR V(REF) for external volt the internal volt will turn off

#endif
	/********************end of reference volt**********************/




	/*************************result adjustment***********************/

#if Adc_u8Adjust==Adc_u8RightAdjust

	CLEAR_BIT(ADMUX,5);  //FOR right ADJUST

#elif Adc_u8Adjust==Adc_u8LeftAdjust

	SET_BIT(ADMUX,5);  //FOR left ADJUST

#endif
	/**********************end of result adjustment*********************/




	//ADMUX bit numbers 4,3,2,1,0 for input channel that i want to convert

	SET_BIT(ADCSRA,7); //FOR  ADC EN


	//ADCSRA BIT 6 TO START CONVERSION



	/*********************auto trigger***********************************/

#if Adc_u8AutoTrigger==Adc_u8Enabale

	SET_BIT(ADCSRA,5); //TO enable AUTO TRIGER

#elif Adc_u8AutoTrigger==Adc_u8Disable

	CLEAR_BIT(ADCSRA,5); //TO disable AUTO TRIGER

#endif
	/*********************END OF AUTO TRIGGER MODE SELESTION*************/


	/*****************************Adc interrupt*****************************/

#if Adc_u8AdcInterrupt==Adc_u8EnableInterrupt

	SET_BIT(ADCSRA,3);  // (PIE)

#elif Adc_u8AdcInterrupt==Adc_u8DisableInterrupt
	SET_BIT(SREG,7);      //(GIE)
	CLEAR_BIT(ADCSRA,3);  // (PIE)

#endif
	/******************************************************************************/


	/*********************prescaler sellection***********************/

#if Adc_u8DivisionFactorSelect==Adc_u8DivisionFactor2

	CLEAR_BIT(ADCSRA,2); //2,1,0 FOR PRESCALER
	CLEAR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

#elif Adc_u8DivisionFactorSelect==Adc_u8DivisionFactor4

	CLEAR_BIT(ADCSRA,2); //2,1,0 FOR PRESCALER
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

#elif Adc_u8DivisionFactorSelect==Adc_u8DivisionFactor8

	CLEAR_BIT(ADCSRA,2); //2,1,0 FOR PRESCALER
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

#elif Adc_u8DivisionFactorSelect==Adc_u8DivisionFactor16

	SET_BIT(ADCSRA,2); //2,1,0 FOR PRESCALER
	CLEAR_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

#elif Adc_u8DivisionFactorSelect==Adc_u8DivisionFactor32

	SET_BIT(ADCSRA,2); //2,1,0 FOR PRESCALER
	CLEAR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

#elif Adc_u8DivisionFactorSelect==Adc_u8DivisionFactor64

	SET_BIT(ADCSRA,2); //2,1,0 FOR PRESCALER
	SET_BIT(ADCSRA,1);
	CLEAR_BIT(ADCSRA,0);

#elif Adc_u8DivisionFactorSelect==Adc_u8DivisionFactor128

	SET_BIT(ADCSRA,2); //2,1,0 FOR PRESCALER
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,0);

#endif
	/*******************END OF PRESCALER SELECTION****************************/


	/*************to select the trigger edge source*********************/

#if Adc_u8AutoTriggerMode==Adc_u8FREE_RUNNING_MODE
	CLEAR_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
#elif Adc_u8AutoTriggerMode==Adc_u8ANALOG_COMPARATOR
	CLEAR_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif Adc_u8AutoTriggerMode==Adc_u8EXTERNAL_INTERRUPT_REQUEST0
	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
#elif Adc_u8AutoTriggerMode==Adc_u8Timer_OR_Counter0_Compare_Match
	CLEAR_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif Adc_u8AutoTriggerMode==Adc_u8Timer_OR_Counter0_Overflow
	SET_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
#elif Adc_u8AutoTriggerMode==Adc_u8Timer_OR_Counter_Compare_Match_B
	SET_BIT(SFIOR,7);
	CLEAR_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#elif Adc_u8AutoTriggerMode==Adc_u8Timer_OR_Counter1_Overflow
	SET_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	CLEAR_BIT(SFIOR,5);
#elif Adc_u8AutoTriggerMode==Adc_u8Timer_OR_Counter1_Capture_Event
	SET_BIT(SFIOR,7);
	SET_BIT(SFIOR,6);
	SET_BIT(SFIOR,5);
#endif

	/**********************************************************************************/

}


u16 ADC_u16ConvertChannel(u8 channel)
{

	channel &=0x1f;  //to make sure that 3 high bits are set to zeros(masking)
	u8  Reg_Value;
	u16 ADC_Result=0;
	Reg_Value=ADMUX;
	ADMUX=(Reg_Value&0xe0)|channel;    //b7afez 3lla awel 3 high bit w el ba2y be asfar 3ashan a7afez 3lla ADMUX(7,6,5)

	/**********************auto trigger mode*******************/

#if Adc_u8AutoTrigger==Adc_u8Disable

	SET_BIT(ADCSRA,6);    //TO START CONVERSION

#elif Adc_u8AutoTrigger==Adc_u8Enabale && (Adc_u8AutoTriggerMode == Adc_u8FREE_RUNNING_MODE)

	SET_BIT(ADCSRA,6);    //TO START CONVERSION

#elif Adc_u8AutoTrigger==Adc_u8Enabale

#endif

	/***************************************************/

	while (GET_BIT(ADCSRA,4)==0);   //TO MAKE SURE THAT THE CONVERSION WAS HAPPENED
	SET_BIT(ADCSRA,4);   //CLEAR CONVERSION FLAG

	/*******************conversion adjustment************/

#if Adc_u8Adjust==Adc_u8RightAdjust
	ADC_Result=ADCL;    //MOVE LOW PART FOR CONVERSION TO RETURNING VALUE
	ADC_Result |=(ADCH<<8);   //MOVE HIGH PART FOR CONVERSION TO RETURNING VALUE
#elif Adc_u8Adjust==Adc_u8LeftAdjust
	ADC_Result=ADCH;    //MOVE HIGH PART FOR CONVERSION TO RETURNING VALUE
#endif

	/*********************************************************/

	return ADC_Result;

}
