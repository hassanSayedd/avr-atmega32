/*
 * main.c
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
	Dio_vidSetPinDir(DIO_u8PIN_11,DIO_u8OUTPUT);
	SET_BIT(TCCR0,6);   //for fast pwm mode
	SET_BIT(TCCR0,3);   //for fast pwm mode
	SET_BIT(TCCR0,5);    //for clear OC0 on compare match and set OC0 at top
	CLEAR_BIT(TCCR0,4);  //for clear OC0 on compare match and set OC0 at top
	CLEAR_BIT(TCCR0,2);    //for prescaller = 1
	CLEAR_BIT(TCCR0,1);    //for prescaller = 1
	SET_BIT(TCCR0,0);      //for prescaller = 1
	s16 i;
	while(1)
	{
		for(i=0;i<255;i++)
		{
			OCR0=i;
			_delay_ms(5);
		}
		for(i=255;i>=0;i--)
		{
			OCR0=i;
			_delay_ms(5);
		}
	}
	return 0;
}

