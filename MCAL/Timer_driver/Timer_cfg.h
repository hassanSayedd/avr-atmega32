/*
 * Timer0_cfg.h
 *
 *  Created on: 25 Jun 2020
 *      Author: express
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/****************************************************TIMER 0 CONFIGURATION*************************************************/

//****************compare output mode for non-PWM Mode**************/

#define Timer0_OC0Disconnected               0
#define Timer0_ToggleOC0OnCmprMatch          1
#define Timer0_ClearOC0OnCmprMatch           10
#define Timer0_SetOC0OnCmprMatch             11

#define Timer0_NonPWMCmprOtptMode            Timer0_OC0Disconnected
/*******************************************************/

//****************compare output mode for fast PWM Mode**************/

#define Timer0_OC0Disconnected                           0
#define Timer0_ClrOC0OnCmprMatchAndSetOC0AtTOP           10
#define Timer0_SetOC0OnCmprMatchAndClearOC0AtTOP         11

#define Timer0_FastPWMCmprOtptMode    Timer0_ClrOC0OnCmprMatchAndSetOC0AtTOP
/*******************************************************/

//****************compare output mode for phase correct PWM Mode**************/

#define Timer0_OC0Disconnected                                  0
#define Timer0_ClrOC0UpCountingAndSetOC0DownCouning             10
#define Timer0_SetOC0UpCountingAndClrOC0DownCouning             11

#define Timer0_PhaseCorrectPWMCmprOtptMode    Timer0_ClrOC0UpCountingAndSetOC0DownCouning
/*******************************************************/

//***************prescaller****************/
#define Timer0_NoCLKSrc                  0
#define Timer0_DivisionFactor1           1
#define Timer0_DivisionFactor8           10
#define Timer0_DivisionFactor64          11
#define Timer0_DivisionFactor256         100
#define Timer0_DivisionFactor1024        101
#define Timer0_ExternalCLKFallingAge     110
#define Timer0_ExternalCLKrisingAge      111

#define Timer0_Prescaller    Timer0_DivisionFactor1024
/***********************************************************/

//************timer 0 Output Compare Match Interrupt*********/
#define Timer0_OutputCmprMatchIntrEnable          0
#define Timer0_OutputCmprMatchIntrDisable         1

#define Timer0_OutputCmprMatchIntr     Timer0_OutputCmprMatchIntrDisable
/********************************************************************/

//************timer 0 Overflow Interrupt*********/
#define Timer0_OverflowIntrEnable          0
#define Timer0_OverflowIntrDisable         1

#define Timer0_OverflowIntr     Timer0_OverflowIntrDisable


/******************************************************************************************************************************************************************************************************************/







/**************************************************TIMER 1 CONFIGURATION**********************************************************/

//****************timer 1 mode*********************************/

#define Timer1_NormalMode_TopMax					0
#define Timer1_PWMPhaseCorrect8Bit_TopMax		    1
#define Timer1_PWMPhaseCorrect9Bit_TopMax		    10
#define Timer1_PWMPhaseCorrect10Bit_TopMax		    11
#define Timer1_CTC_TopOCR1A						    100
#define Timer1_FastPWM8Bit_TopMax				    101
#define Timer1_FastPWM9Bit_TopMax				    110
#define Timer1_FastPWM10Bit_TopMax				    111
#define Timer1_PWMPhaseAndFreqCorrect_TopICR1	    1000
#define Timer1_PWMPhaseAndFreqCorrect_TopOCR1A	    1001
#define Timer1_PWMPhaseCorrect_TopICR1			    1010
#define Timer1_PWMPhaseCorrect_TopOCR1A			    1011
#define Timer1_CTC_TopICR1						    1100
#define Timer1_FastPWM_TopICR1					    1110
#define Timer1_FastPWM_TopOCR1A					    1111

#define Timer1_Mode 		Timer1_FastPWM_TopICR1

//*****************************************************************/

//****************compare output mode for non-PWM Mode**************/

#define Timer1_OC1AorBDisconnected               0
#define Timer1_ToggleOC1AorBOnCmprMatch          1
#define Timer1_ClearOC1AorBOnCmprMatch           10
#define Timer1_SetOC1AorBOnCmprMatch             11

#define Timer1_NonPWMCmprOtptMode            Timer1_OC1AorBDisconnected
/******************************************************/

//***************compare output mode for fast PWM Mode**************/

#define Timer1_OC1AorBDisconnected                           	 0
#define Timer1_TggleOC1AOnCmprMatchAndOC1BDisconnected           1 //this configuration only for Fast PWM top OCR1A mode
#define Timer1_ClrOC1AorBOnCmprMatchAndSetOC1AorBAtTOP           10
#define Timer1_SetOC1AorBOnCmprMatchAndClearOC1AorBAtTOP         11

#define Timer1_FastPWMCmprOtptMode    Timer1_ClrOC1AorBOnCmprMatchAndSetOC1AorBAtTOP
/******************************************************/

//***************compare output mode for phase correct PWM Mode**************/

#define Timer1_OC1AorBDisconnected                                  0
#define Timer1_TggleOC1AOnCmprMatchAndOC1BDisconnected              1 //this configuration only for PWM phase and freq Correct top OCR1A mode
#define Timer1_ClrOC1AorBUpCountingAndSetOC0DownCouning             10
#define Timer1_SetOC1AorBUpCountingAndClrOC0DownCouning             11

#define Timer1_PhaseCorrectPWMCmprOtptMode    Timer1_OC1AorBDisconnected
/*******************************************************/

//***************prescaller****************/
#define Timer1_NoCLKSrc                  0
#define Timer1_DivisionFactor1           1
#define Timer1_DivisionFactor8           10
#define Timer1_DivisionFactor64          11
#define Timer1_DivisionFactor256         100
#define Timer1_DivisionFactor1024        101
#define Timer1_ExternalCLKFallingAge     110
#define Timer1_ExternalCLKrisingAge      111

#define Timer1_Prescaller    Timer1_DivisionFactor8

/***********************************************************/

//************timer 1 Output Compare channel A Match Interrupt*********/
#define Timer1_OutputCmprMatchAIntrEnable          0
#define Timer1_OutputCmprMatchAIntrDisable         1

#define Timer1_OutputCmprMatchAIntr     Timer1_OutputCmprMatchAIntrDisable
/********************************************************************/

//************timer 1 Output Compare channel B Match Interrupt*********/
#define Timer1_OutputCmprMatchBIntrEnable          0
#define Timer1_OutputCmprMatchBIntrDisable         1

#define Timer1_OutputCmprMatchBIntr     Timer1_OutputCmprMatchBIntrDisable
/********************************************************************/

//************timer 1 Overflow Interrupt*********/
#define Timer1_OverflowIntrEnable          0
#define Timer1_OverflowIntrDisable         1

#define Timer1_OverflowIntr     Timer1_OverflowIntrDisable


//**************************************************************************************************************************************************************************************************************************************************************************/








//*********************************************TIMER 2 CONFIGURATION*********************************************/

//****************compare output mode for non-PWM Mode**************/

#define Timer2_OC2Disconnected               0
#define Timer2_ToggleOC2OnCmprMatch          1
#define Timer2_ClearOC2OnCmprMatch           10
#define Timer2_SetOC2OnCmprMatch             11

#define Timer2_NonPWMCmprOtptMode            Timer2_OC2Disconnected
/*******************************************************/

//****************compare output mode for fast PWM Mode**************/

#define Timer2_OC2Disconnected                           0
#define Timer2_ClrOC2OnCmprMatchAndSetOC2AtTOP           10
#define Timer2_SetOC2OnCmprMatchAndClearOC2AtTOP         11

#define Timer2_FastPWMCmprOtptMode    Timer2_ClrOC2OnCmprMatchAndSetOC2AtTOP
/*******************************************************/

//****************compare output mode for phase correct PWM Mode**************/

#define Timer2_OC2Disconnected                                  0
#define Timer2_ClrOC2UpCountingAndSetOC2DownCouning             10
#define Timer2_SetOC2UpCountingAndClrOC2DownCouning             11

#define Timer2_PhaseCorrectPWMCmprOtptMode    Timer2_ClrOC2UpCountingAndSetOC2DownCouning
/*******************************************************/

//***************prescaller****************/
#define Timer2_NoCLKSrc                  0
#define Timer2_DivisionFactor1           1
#define Timer2_DivisionFactor8           10
#define Timer2_DivisionFactor32          11
#define Timer2_DivisionFactor64			 100
#define Timer2_DivisionFactor128         101
#define Timer2_DivisionFactor256         110
#define Timer2_DivisionFactor1024        111

#define Timer2_Prescaller    Timer2_DivisionFactor1024
/***********************************************************/

//************timer 2 Output Compare Match Interrupt*********/
#define Timer2_OutputCmprMatchIntrEnable          0
#define Timer2_OutputCmprMatchIntrDisable         1

#define Timer2_OutputCmprMatchIntr     Timer2_OutputCmprMatchIntrEnable
/********************************************************************/

//************timer 2 Overflow Interrupt*********/
#define Timer2_OverflowIntrEnable          0
#define Timer2_OverflowIntrDisable         1

#define Timer2_OverflowIntr     Timer2_OverflowIntrDisable

/********************************************************************/

//*************timer 2 clock selection***********/
#define Timer2_InternalClk          0
#define Timer2_ExternalClk          1

#define Timer2_Clock     Timer2_InternalClk

/***********************************************************************/




/******************************************************************************************************************************************************************************************************************/


#endif /* TIMER_CFG_H_ */
