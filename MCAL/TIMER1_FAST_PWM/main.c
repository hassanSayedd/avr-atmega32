/*
 * maCCR1Bin.c
 *
 *  Created on: Sep 6, 2019
 *      Author: express
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
int main(void)
{
	Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);
	SET_BIT(TCCR1A,7);    //SET ON TOP AND CLEAR ON COMARE MATCH
	CLEAR_BIT(TCCR1A,6);  //SET ON TOP AND CLEAR ON COMARE MATCH
	SET_BIT(TCCR1A,1);    //FOR FAST PWM MODE AND ICR1 IS THE TOP
	CLEAR_BIT(TCCR1A,0);  //FOR FAST PWM MODE AND ICR1 IS THE TOP
	SET_BIT(TCCR1B,4);   //FOR FAST PWM MODE AND ICR1 IS THE TOP
	SET_BIT(TCCR1B,3);   //FOR FAST PWM MODE AND ICR1 IS THE TOP

	CLEAR_BIT(TCCR1B,2);      //FOR PRESCALLER
	SET_BIT(TCCR1B,1);        //FOR PRESCALLER
	CLEAR_BIT(TCCR1B,0);      //FOR PRESCALLER

	OCR1A=1000;   //FOR 1 mSEC T(on)
	ICR1=200000;  //FOR 50 HZ

	while(1);
	return 0;
}

