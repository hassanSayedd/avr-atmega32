/*
 * Adc_cfg.h
 *
 *  Created on: Sep 19, 2019
 *      Author: Ahmad Yehia
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


/*************reference voltage selection*****************/

#define Adc_u8ExternalVolt      0
#define Adc_u8Internal_5Volt    1
#define Adc_u8Internal_2Volt    2

#define Adc_u8ReferenceVoltage  Adc_u8Internal_5Volt

/*********************************************************/

/******************result adjustment*****************************/

#define Adc_u8LeftAdjust  0
#define Adc_u8RightAdjust 1

#define Adc_u8Adjust  Adc_u8LeftAdjust

/********************************************************/

/******************auto trigger mode************************/

#define Adc_u8Enabale  0
#define Adc_u8Disable  1

#define Adc_u8AutoTrigger  Adc_u8Disable

/***********************************************************/

/***************Adc interrupt*****************************/

#define Adc_u8EnableInterrupt 0
#define Adc_u8DisableInterrupt 1

#define Adc_u8AdcInterrupt Adc_u8DisableInterrupt

/*************************************************************/

/****************************prescaler selection***********************/

#define Adc_u8DivisionFactor2       1
#define Adc_u8DivisionFactor4       10
#define Adc_u8DivisionFactor8       11
#define Adc_u8DivisionFactor16      100
#define Adc_u8DivisionFactor32      101
#define Adc_u8DivisionFactor64      110
#define Adc_u8DivisionFactor128     111

#define Adc_u8DivisionFactorSelect Adc_u8DivisionFactor2

/****************************************************************************/

/***************auto trigger source*******************************************/

#define Adc_u8FREE_RUNNING_MODE                0
#define Adc_u8ANALOG_COMPARATOR                1
#define Adc_u8EXTERNAL_INTERRUPT_REQUEST_0     10
#define Adc_u8Timer_OR_Counter0_Compare_Match  11
#define Adc_u8Timer_OR_Counter0_Overflow       100
#define Adc_u8Timer_OR_Counter_Compare_Match_B 101
#define Adc_u8Timer_OR_Counter1_Overflow       110
#define Adc_u8Timer_OR_Counter1_Capture_Event  111

#define Adc_u8AutoTriggerMode   Adc_u8EXTERNAL_INTERRUPT_REQUEST0

/******************************************************************************/



#endif /* ADC_CFG_H_ */
