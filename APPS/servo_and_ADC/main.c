/*
 * main.c
 *
 *  Created on: Sep 19, 2019
 *      Author: Ahmad Yehia
 */



#include<avr/io.h>
#include"std_types.h"
#include"Bit_math.h"
#include"Dio_int.h"
#include"Adc_int.h"

int main(void){
	ADC_vidInit();

	// TO USE CHANNEL A AND TO MAKE IT SET ON TOP ,CLEAR AT COMPARE
	SET_BIT(TCCR1A,7);
	CLEAR_BIT(TCCR1A,6);

	// TO MAKE THIS TIMER MODE FAST_PWM AND ICR1 IS THE TOP VALUE
	SET_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);
	SET_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);
	// Fclk=Fcpu/8
	CLEAR_BIT(TCCR1B,2);
	SET_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,0);
	// TOP VALUE
	ICR1=20000;
	// COMPARE VALUE
	OCR1A=450;        // 450 give zero // 2450 is 180
	Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);

	while(1)
	{
		// all this code is try and error code
		u16 Digital=ADC_u16ConvertChannel(0);
		u16 Analog=(Digital*125)/64;    // 500/256 =125/64
		Analog=Analog*4+450;            //
		OCR1A=Analog;
	}
	return 0;
}
