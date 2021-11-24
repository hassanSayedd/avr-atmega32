/*
 * Timer0_prg.c
 *
 *  Created on: 25 Jun 2020
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Timer_cfg.h"
#include "Timer_int.h"
#include "Timer_priv.h"
//#include <avr/io.h>

void Timer_vidTimer0Init(u8 mode)
{
	if(mode == Timer0_NormalMode)
	{
		CLEAR_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);

		//compare Output mode
#if Timer0_NonPWMCmprOtptMode == Timer0_OC0Disconnected
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif Timer0_NonPWMCmprOtptMode == Timer0_ToggleOC0OnCmprMatch
		CLEAR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);

#elif Timer0_NonPWMCmprOtptMode == Timer0_ClearOC0OnCmprMatch
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);

#elif Timer0_NonPWMCmprOtptMode == Timer0_SetOC0OnCmprMatch
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);

#endif
		/******************************************************/

	}
	else if(mode == Timer0_PWMPhaseCorrect)
	{
		CLEAR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		//compare Output mode
#if Timer0_PhaseCorrectPWMCmprOtptMode == Timer0_OC0Disconnected
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);

#elif Timer0_PhaseCorrectPWMCmprOtptMode == Timer0_ClrOC0UpCountingAndSetOC0DownCouning
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);

#elif Timer0_PhaseCorrectPWMCmprOtptMode == Timer0_SetOC0UpCountingAndClrOC0DownCouning
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);

#endif
		/*******************************************************/

	}
	else if(mode == Timer0_CTC)
	{
		SET_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);

		//compare Output mode
#if Timer0_NonPWMCmprOtptMode == Timer0_OC0Disconnected
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);
#elif Timer0_NonPWMCmprOtptMode == Timer0_ToggleOC0OnCmprMatch
		CLEAR_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);

#elif Timer0_NonPWMCmprOtptMode == Timer0_ClearOC0OnCmprMatch
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);

#elif Timer0_NonPWMCmprOtptMode == Timer0_SetOC0OnCmprMatch
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);

#endif
		/********************************************************/

	}
	else if(mode == Timer0_FastPWM)
	{
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		//compare Output mode
#if Timer0_FastPWMCmprOtptMode == Timer0_OC0Disconnected
		CLEAR_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);

#elif Timer0_FastPWMCmprOtptMode == Timer0_ClrOC0OnCmprMatchAndSetOC0AtTOP
		SET_BIT(TCCR0,5);
		CLEAR_BIT(TCCR0,4);

#elif Timer0_FastPWMCmprOtptMode == Timer0_SetOC0OnCmprMatchAndClearOC0AtTOP
		SET_BIT(TCCR0,5);
		SET_BIT(TCCR0,4);

#endif
		/*****************************************************/
	}

	//prescaller sellection

#if Timer0_Prescaller == Timer0_NoCLKSrc
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);

#elif Timer0_Prescaller ==Timer0_DivisionFactor1
	CLEAR_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);

#elif Timer0_Prescaller ==Timer0_DivisionFactor8
	CLEAR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);

#elif Timer0_Prescaller ==Timer0_DivisionFactor64
	CLEAR_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);

#elif Timer0_Prescaller ==Timer0_DivisionFactor256
	SET_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);

#elif Timer0_Prescaller ==Timer0_DivisionFactor1024
	SET_BIT(TCCR0,2);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);

#elif Timer0_Prescaller ==Timer0_ExternalCLKFallingAge
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,0);

#elif Timer0_Prescaller ==Timer0_ExternalCLKrisingAge
	SET_BIT(TCCR0,2);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,0);

#endif

	/**********************************************************/

	//******************output compare match interrupt

#if Timer0_OutputCmprMatchIntr == Timer0_OutputCmprMatchIntrEnable
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,1);

#elif Timer0_OutputCmprMatchIntr == Timer0_OutputCmprMatchIntrDisable
	CLEAR_BIT(TIMSK,1);

#endif
	/**************************************************************/

	//*****************overflow interrupt
#if Timer0_OverflowIntr == Timer0_OverflowIntrEnable
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,0);

#elif Timer0_OverflowIntr == Timer0_OverflowIntrDisable
	CLEAR_BIT(TIMSK,0);

#endif

}

void Timer_vidTimer1Init(u8 mode,u8 channel)
{

	//timer 1 mode selection

#if Timer1_Mode == Timer1_NormalMode_TopMax
	CLEAR_BIT(TCCR1B,4);
	CLEAR_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_PWMPhaseCorrect8Bit_TopMax
	CLEAR_BIT(TCCR1B,4);
	CLEAR_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_PWMPhaseCorrect9Bit_TopMax
	CLEAR_BIT(TCCR1B,4);
	CLEAR_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_PWMPhaseCorrect10Bit_TopMax
	CLEAR_BIT(TCCR1B,4);
	CLEAR_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_CTC_TopOCR1A
	CLEAR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_FastPWM8Bit_TopMax
	CLEAR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_FastPWM9Bit_TopMax
	CLEAR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_FastPWM10Bit_TopMax
	CLEAR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_PWMPhaseAndFreqCorrect_TopICR1
	SET_BIT(TCCR1B,4);
	CLEAR_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_PWMPhaseAndFreqCorrect_TopOCR1A
	SET_BIT(TCCR1B,4);
	CLEAR_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_PWMPhaseCorrect_TopICR1
	SET_BIT(TCCR1B,4);
	CLEAR_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_PWMPhaseCorrect_TopOCR1A
	SET_BIT(TCCR1B,4);
	CLEAR_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_CTC_TopICR1
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_FastPWM_TopICR1
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

#elif Timer1_Mode ==	Timer1_FastPWM_TopOCR1A
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1A,0);

#endif
	/***************************************************/


	//compare output mode for Non PWM

	if(mode == Timer1_NonPWM && channel == Timer1_ChannelA)
	{
#if Timer1_NonPWMCmprOtptMode == Timer1_OC1AorBDisconnected
		CLEAR_BIT(TCCR1A,7); //for channel A
		CLEAR_BIT(TCCR1A,6); //for channel A

#elif Timer1_NonPWMCmprOtptMode == Timer1_ToggleOC1AorBOnCmprMatch
		CLEAR_BIT(TCCR1A,7); //for channel A
		SET_BIT(TCCR1A,6); //for channel A

#elif Timer1_NonPWMCmprOtptMode == Timer1_ClearOC1AorBOnCmprMatch
		SET_BIT(TCCR1A,7); //for channel A
		CLEAR_BIT(TCCR1A,6); //for channel A

#elif Timer1_NonPWMCmprOtptMode == Timer1_SetOC1AorBOnCmprMatch
		SET_BIT(TCCR1A,7); //for channel A
		SET_BIT(TCCR1A,6); //for channel A

#endif
	}

	/************************************************/

	//compare output mode for Fast PWM

	else if (mode == Timer1_FastPWM && channel == Timer1_ChannelA)
	{
#if Timer1_FastPWMCmprOtptMode == Timer1_OC1AorBDisconnected
		CLEAR_BIT(TCCR1A,7); //for channel A
		CLEAR_BIT(TCCR1A,6); //for channel A

#elif Timer1_FastPWMCmprOtptMode == Timer1_TggleOC1AOnCmprMatchAndOC1BDisconnected
		CLEAR_BIT(TCCR1A,7); //for channel A
		SET_BIT(TCCR1A,6); //for channel A

#elif Timer1_FastPWMCmprOtptMode == Timer1_ClrOC1AorBOnCmprMatchAndSetOC1AorBAtTOP
		SET_BIT(TCCR1A,7); //for channel A
		CLEAR_BIT(TCCR1A,6); //for channel A

#elif Timer1_FastPWMCmprOtptMode == Timer1_SetOC1AorBOnCmprMatchAndClearOC1AorBAtTOP
		SET_BIT(TCCR1A,7); //for channel A
		SET_BIT(TCCR1A,6); //for channel A

#endif
	}

	//************************************/

	//compare Output mode for Phase and Frequency Correct PWM

	else if (mode == Timer1_PhaseAndFreqCorrect && channel == Timer1_ChannelA)
	{
#if Timer1_PhaseCorrectPWMCmprOtptMode == Timer1_OC1AorBDisconnected
		CLEAR_BIT(TCCR1A,7); //for channel A
		CLEAR_BIT(TCCR1A,6); //for channel A

#elif Timer1_PhaseCorrectPWMCmprOtptMode == Timer1_TggleOC1AOnCmprMatchAndOC1BDisconnected
		CLEAR_BIT(TCCR1A,7); //for channel A
		SET_BIT(TCCR1A,6); //for channel A

#elif Timer1_PhaseCorrectPWMCmprOtptMode == Timer1_ClrOC1AorBUpCountingAndSetOC0DownCouning
		SET_BIT(TCCR1A,7); //for channel A
		CLEAR_BIT(TCCR1A,6); //for channel A

#elif Timer1_PhaseCorrectPWMCmprOtptMode == Timer1_SetOC1AorBUpCountingAndClrOC0DownCouning
		SET_BIT(TCCR1A,7); //for channel A
		SET_BIT(TCCR1A,6); //for channel A

#endif
	}

	if(mode == Timer1_NonPWM && channel == Timer1_ChannelB)
	{
#if Timer1_NonPWMCmprOtptMode == Timer1_OC1AorBDisconnected
		CLEAR_BIT(TCCR1A,5); //for channel B
		CLEAR_BIT(TCCR1A,4); //for channel B

#elif Timer1_NonPWMCmprOtptMode == Timer1_ToggleOC1AorBOnCmprMatch
		CLEAR_BIT(TCCR1A,5); //for channel B
		SET_BIT(TCCR1A,4); //for channel B

#elif Timer1_NonPWMCmprOtptMode == Timer1_ClearOC1AorBOnCmprMatch
		SET_BIT(TCCR1A,5); //for channel B
		CLEAR_BIT(TCCR1A,4); //for channel B

#elif Timer1_NonPWMCmprOtptMode == Timer1_SetOC1AorBOnCmprMatch
		SET_BIT(TCCR1A,5); //for channel B
		SET_BIT(TCCR1A,4); //for channel B

#endif
	}

	/************************************************/

	//compare output mode for Fast PWM

	else if (mode == Timer1_FastPWM && channel == Timer1_ChannelB)
	{
#if Timer1_FastPWMCmprOtptMode == Timer1_OC1AorBDisconnected
		CLEAR_BIT(TCCR1A,5); //for channel B
		CLEAR_BIT(TCCR1A,4); //for channel B

#elif Timer1_FastPWMCmprOtptMode == Timer1_TggleOC1AOnCmprMatchAndOC1BDisconnected
		CLEAR_BIT(TCCR1A,5); //for channel B
		SET_BIT(TCCR1A,4); //for channel B

#elif Timer1_FastPWMCmprOtptMode == Timer1_ClrOC1AorBOnCmprMatchAndSetOC1AorBAtTOP
		SET_BIT(TCCR1A,5); //for channel B
		CLEAR_BIT(TCCR1A,4); //for channel B

#elif Timer1_FastPWMCmprOtptMode == Timer1_SetOC1AorBOnCmprMatchAndClearOC1AorBAtTOP
		SET_BIT(TCCR1A,5); //for channel B
		SET_BIT(TCCR1A,4); //for channel B

#endif
	}

	//************************************/

	//compare Output mode for Phase and Frequency Correct PWM

	else if (mode == Timer1_PhaseAndFreqCorrect && channel == Timer1_ChannelB)
	{
#if Timer1_PhaseCorrectPWMCmprOtptMode == Timer1_OC1AorBDisconnected
		CLEAR_BIT(TCCR1A,5); //for channel B
		CLEAR_BIT(TCCR1A,4); //for channel B

#elif Timer1_PhaseCorrectPWMCmprOtptMode == Timer1_TggleOC1AOnCmprMatchAndOC1BDisconnected
		CLEAR_BIT(TCCR1A,5); //for channel B
		SET_BIT(TCCR1A,4); //for channel B

#elif Timer1_PhaseCorrectPWMCmprOtptMode == Timer1_ClrOC1AorBUpCountingAndSetOC0DownCouning
		SET_BIT(TCCR1A,5); //for channel B
		CLEAR_BIT(TCCR1A,4); //for channel B

#elif Timer1_PhaseCorrectPWMCmprOtptMode == Timer1_SetOC1AorBUpCountingAndClrOC0DownCouning
		SET_BIT(TCCR1A,5); //for channel B
		SET_BIT(TCCR1A,4); //for channel B

#endif
	}

	//prescaller sellection

#if Timer1_Prescaller == Timer1_NoCLKSrc
	CLEAR_BIT(TCCR1B,2);
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,0);

#elif Timer1_Prescaller ==Timer1_DivisionFactor1
	CLEAR_BIT(TCCR1B,2);
	CLEAR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,0);

#elif Timer1_Prescaller ==Timer1_DivisionFactor8
	CLEAR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,0);

#elif Timer1_Prescaller ==Timer1_DivisionFactor64
	CLEAR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,0);

#elif Timer1_Prescaller ==Timer1_DivisionFactor256
	SET_BIT(TCCR1B,2);
	CLEAR_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,0);

#elif Timer1_Prescaller ==Timer1_DivisionFactor1024
	SET_BIT(TCCR1B,2);
	CLEAR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,0);

#elif Timer1_Prescaller ==Timer1_ExternalCLKFallingAge
	SET_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,0);

#elif Timer1_Prescaller ==Timer1_ExternalCLKrisingAge
	SET_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,0);

#endif

	//******************output compare match for channel A interrupt

#if Timer1_OutputCmprMatchAIntr == Timer1_OutputCmprMatchAIntrEnable
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,4);

#elif Timer1_OutputCmprMatchAIntr == Timer1_OutputCmprMatchAIntrDisable
	CLEAR_BIT(TIMSK,4);

#endif
	/**************************************************************/

	//******************output compare match for channel B interrupt

#if Timer1_OutputCmprMatchBIntr == Timer1_OutputCmprMatchBIntrEnable
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,3);

#elif Timer1_OutputCmprMatchBIntr == Timer1_OutputCmprMatchBIntrDisable
	CLEAR_BIT(TIMSK,3);

#endif
	/**************************************************************/

	//*****************overflow interrupt
#if Timer1_OverflowIntr == Timer1_OverflowIntrEnable
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,2);

#elif Timer1_OverflowIntr == Timer1_OverflowIntrDisable
	CLEAR_BIT(TIMSK,2);

#endif

}

void Timer_vidTimer2Init(u8 mode)
{
	if(mode == Timer2_NormalMode)
	{
		CLEAR_BIT(TCCR2,3);
		CLEAR_BIT(TCCR2,6);

		//compare Output mode
#if Timer2_NonPWMCmprOtptMode == Timer2_OC2Disconnected
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif Timer2_NonPWMCmprOtptMode == Timer2_ToggleOC2OnCmprMatch
		CLEAR_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);

#elif Timer2_NonPWMCmprOtptMode == Timer2_ClearOC2OnCmprMatch
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);

#elif Timer2_NonPWMCmprOtptMode == Timer2_SetOC2OnCmprMatch
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);

#endif
		/******************************************************/

	}
	else if(mode == Timer2_PWMPhaseCorrect)
	{
		CLEAR_BIT(TCCR2,3);
		SET_BIT(TCCR2,6);

		//compare Output mode
#if Timer2_PhaseCorrectPWMCmprOtptMode == Timer2_OC0Disconnected
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);

#elif Timer2_PhaseCorrectPWMCmprOtptMode == Timer2_ClrOC2UpCountingAndSetOC2DownCouning
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);

#elif Timer2_PhaseCorrectPWMCmprOtptMode == Timer2_SetOC2UpCountingAndClrOC2DownCouning
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);

#endif
		/*******************************************************/

	}
	else if(mode == Timer2_CTC)
	{
		SET_BIT(TCCR2,3);
		CLEAR_BIT(TCCR2,6);

		//compare Output mode
#if Timer2_NonPWMCmprOtptMode == Timer2_OC2Disconnected
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);
#elif Timer2_NonPWMCmprOtptMode == Timer2_ToggleOC2OnCmprMatch
		CLEAR_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);

#elif Timer2_NonPWMCmprOtptMode == Timer2_ClearOC2OnCmprMatch
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);

#elif Timer2_NonPWMCmprOtptMode == Timer2_SetOC2OnCmprMatch
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);

#endif
		/********************************************************/

	}
	else if(mode == Timer2_FastPWM)
	{
		SET_BIT(TCCR2,3);
		SET_BIT(TCCR2,6);

		//compare Output mode
#if Timer2_FastPWMCmprOtptMode == Timer2_OC2Disconnected
		CLEAR_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);

#elif Timer2_FastPWMCmprOtptMode == Timer2_ClrOC2OnCmprMatchAndSetOC2AtTOP
		SET_BIT(TCCR2,5);
		CLEAR_BIT(TCCR2,4);

#elif Timer2_FastPWMCmprOtptMode == Timer2_SetOC2OnCmprMatchAndClearOC2AtTOP
		SET_BIT(TCCR2,5);
		SET_BIT(TCCR2,4);

#endif
		/*****************************************************/
	}

	//prescaller sellection

#if Timer2_Prescaller == Timer2_NoCLKSrc
	CLEAR_BIT(TCCR2,2);
	CLEAR_BIT(TCCR2,1);
	CLEAR_BIT(TCCR2,0);

#elif Timer2_Prescaller ==Timer2_DivisionFactor1
	CLEAR_BIT(TCCR2,2);
	CLEAR_BIT(TCCR2,1);
	SET_BIT(TCCR2,0);

#elif Timer2_Prescaller ==Timer2_DivisionFactor8
	CLEAR_BIT(TCCR2,2);
	SET_BIT(TCCR2,1);
	CLEAR_BIT(TCCR2,0);

#elif Timer2_Prescaller ==Timer2_DivisionFactor32
	CLEAR_BIT(TCCR2,2);
	SET_BIT(TCCR2,1);
	SET_BIT(TCCR2,0);

#elif Timer2_Prescaller ==Timer2_DivisionFactor64
	SET_BIT(TCCR2,2);
	CLEAR_BIT(TCCR2,1);
	CLEAR_BIT(TCCR2,0);

#elif Timer2_Prescaller ==Timer2_DivisionFactor128
	SET_BIT(TCCR2,2);
	CLEAR_BIT(TCCR2,1);
	SET_BIT(TCCR2,0);

#elif Timer2_Prescaller ==Timer2_DivisionFactor256
	SET_BIT(TCCR2,2);
	SET_BIT(TCCR2,1);
	CLEAR_BIT(TCCR2,0);

#elif Timer2_Prescaller ==Timer2_DivisionFactor1024
	SET_BIT(TCCR2,2);
	SET_BIT(TCCR2,1);
	SET_BIT(TCCR2,0);

#endif

	/**********************************************************/

	//******************output compare match interrupt

#if Timer2_OutputCmprMatchIntr == Timer2_OutputCmprMatchIntrEnable
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,7);

#elif Timer2_OutputCmprMatchIntr == Timer2_OutputCmprMatchIntrDisable
	CLEAR_BIT(TIMSK,7);

#endif
	/**************************************************************/

	//*****************overflow interrupt
#if Timer2_OverflowIntr == Timer2_OverflowIntrEnable
	SET_BIT(SREG,7);
	SET_BIT(TIMSK,6);

#elif Timer2_OverflowIntr == Timer2_OverflowIntrDisable
	CLEAR_BIT(TIMSK,6);

#endif
	/**************************************************/

	//*****************CLOCK selection
#if Timer2_Clock == Timer2_InternalClk
	CLEAR_BIT(ASSR,3);

#elif Timer2_Clock == Timer2_ExternalClk
	SET_BIT(ASSR,3);

#endif
	/*********************************************/


}

//****************************************************/

void Timer_vidSetTimer0IntialVal(u8 value)
{
	TCNT0=value;
}

void Timer_vidSetTimer1IntialVal(u16 value)
{
	TCNT1 =value;
}

void Timer_vidSetTimer2IntialVal(u8 value)
{
	TCNT2=value;
}

//********************************************************/

void Timer_vidSetTimer0CmprVal(u8 value)
{
	OCR0=value;
}

void Timer_vidSetTimer1CmprValA(u16 value) //for chanel A
{
	OCR1A=value;
}

void Timer_vidSetTimer1CmprValB(u16 value) //for channel B
{
	OCR1B=value;
}

void Timer_vidSetTimer2CmprVal(u8 value)
{
	OCR2=value;
}

void Timer_vidSetTimer1TopVal(u16 value)
{
	ICR1=value;
}


void Timer_vidGeneratePWM(u32 freq,u16 time_on,u8 channel)
{
	if(channel == Timer1_ChannelA)
	{
		SET_BIT(TCCR1A,7); //for channel A   (for clear on compare match and set on top)
		CLEAR_BIT(TCCR1A,6); //for channel A (for clear on compare match and set on top)
	}
	else if (channel == Timer1_ChannelB)
	{
		SET_BIT(TCCR1A,5); //for channel B    (for clear on compare match and set on top)
		CLEAR_BIT(TCCR1A,4); //for channel B  (for clear on compare match and set on top)
	}

	//for initialization of timer 1
	SET_BIT(TCCR1B,4);   //for PWM and ICR1 is top
	SET_BIT(TCCR1B,3);   //for PWM and ICR1 is top
	SET_BIT(TCCR1A,1);   //for PWM and ICR1 is top
	CLEAR_BIT(TCCR1A,0); //for PWM and ICR1 is top


	CLEAR_BIT(TCCR1B,2);  //for prescaller factor = 8
	SET_BIT(TCCR1B,1);    //for prescaller factor = 8
	CLEAR_BIT(TCCR1B,0);  //for prescaller factor = 8

	CLEAR_BIT(TIMSK,4);  //to disable all interrupt sources from timer1
	CLEAR_BIT(TIMSK,3);  //to disable all interrupt sources from timer1
	CLEAR_BIT(TIMSK,2);  //to disable all interrupt sources from timer1
	//********************************************************************/

	ICR1=(u16)(1000000/freq); //frequency range from 1 Hz to 1 MHZ

	if(channel == Timer1_ChannelA)
	{
		SET_BIT(DDRD,5);
		OCR1A=time_on;
	}
	else if (channel == Timer1_ChannelB)
	{
		SET_BIT(DDRD,4);
		OCR1B=time_on;
	}

}
