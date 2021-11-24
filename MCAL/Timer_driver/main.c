/*
 * main.c
 *
 *  Created on: Sep 6, 2019
 *      Author: express
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "Timer_int.h"
#include "Dio_int.h"

#include <avr/interrupt.h>
#include <util/delay.h>

u16 timerOFCount=0;

int main(void)
{
	/*

	////lab 1 lec 9 led blinking each 10 seconds
	 // in configuration file prescaller is 1024 so step time = 1024/(8*10^6)=1.28*10^-4 second
	 // so timer will overflow after 256*1.28*10^-4=0.032768 second (256 bec. timer 0 is 8 bit timer)
	 // then to reach 10 seconds we will wait to overflow 305 times (305*0.032768=9.8304)
	 // we also enabled overflow interrupt and wrote the code in ISR


	Timer_vidTimer0Init(Timer0_NormalMode);
	while(1);
	 */


	/*
	//lab 1 for lec 10
	Timer_vidTimer0Init(Timer0_FastPWM);
	Dio_vidSetPinDir(DIO_u8PIN_11,DIO_u8OUTPUT);
	while(1)
	{
		s16 i;
		for(i=0;i<256;i++)
		{
			Timer_vidSetTimer0CmprVal(i);
			_delay_ms(5);
		}
		for(i=255;i>=0;i--)
		{
			Timer_vidSetTimer0CmprVal(i);
			_delay_ms(5);
		}
	}
	 */

	/*
	//for servo
	Timer_vidTimer1Init(Timer1_FastPWM,Timer1_ChannelA); //we make it on mode Fast PWM and ICR1 top and prescaller factor = 8 and clear on compare match and set on top
	Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);
	Timer_vidSetTimer1TopVal(20000); //to make freq equal 50Hz (freq=f_CPU/(20000*prescaller))
	Timer_vidSetTimer1CmprValA(2000); //
	while(1);
	 */


	//for servo
	Timer_vidGeneratePWM(50,2610,Timer1_ChannelA);
	while(1);

}

ISR(TIMER0_OVF_vect)  //for lab1 lec 9
{

	if(timerOFCount == 305)
	{
		Dio_vidSetPinDir(DIO_u8PIN_0,DIO_u8OUTPUT);
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
		_delay_ms(300);
		timerOFCount=0;
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
	}
	timerOFCount++;
}
