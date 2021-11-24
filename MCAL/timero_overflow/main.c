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
#include <avr/interrupt.h>

u16 timer_u16OverFlowCount=0;
void MyDelay_ms(u16 delay_time);
u16 Timer_u16OVFCounter=0,DesiredTime=0,Timer_u16EndFlag;

int main(void)
{
	Dio_vidSetPinDir(DIO_u8PIN_31,DIO_u8OUTPUT);
	while(1)
	{
		Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8HIGH);
		MyDelay_ms(500);
		Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8LOW);
		MyDelay_ms(500);
	}
	return 0;
}

void MyDelay_ms(u16 delay_time)
{
	DesiredTime=delay_time;
	/*fe record 3lla el mobile eb2a esm3o ******/
	TCNT0=192;            // 3ashan ashel el fraction

	/******select timer mode **************/
	CLEAR_BIT(TCCR0,6);    //TO SELECT NORMAL MODE
	CLEAR_BIT(TCCR0,3);    //TO SELECT NORMAL MODE


	/***************Fclk=Fcpu "no prescaling"*********/
	CLEAR_BIT(TCCR0,2);      //PRESCALLER FACTOR
	CLEAR_BIT(TCCR0,1);     //PRESCALLER FACTOR
	SET_BIT(TCCR0,0);      //PRESCALLER FACTOR



	SET_BIT(TIMSK,0);  //TO ENABLE timer over flow INTERRUPT ENABLE (PIE)
	SET_BIT(SREG,7);  //TO ENABLE GLOBAL INTERRUPT ENABLE (GIE)

	Timer_u16EndFlag=0;
	while(Timer_u16EndFlag==0);
	/***************Fclk=0 "no TIMER"*********/
	CLEAR_BIT(TCCR0,2);      //PRESCALLER FACTOR
	CLEAR_BIT(TCCR0,1);     //PRESCALLER FACTOR
	CLEAR_BIT(TCCR0,0);      //PRESCALLER FACTOR



	CLEAR_BIT(TIMSK,0);  //TO disable timer over flow INTERRUPT ENABLE (PIE)
}

ISR(TIMER0_OVF_vect)
{
	static u16 ms_counter=0;
	timer_u16OverFlowCount++;

	if(timer_u16OverFlowCount==32)
	{
		/***this block will execute EACH 1 msec*******/
		timer_u16OverFlowCount=0;
		ms_counter++;
		TCNT0=192;
		if(ms_counter==DesiredTime)
		{
			ms_counter=0;
			Timer_u16EndFlag=1;
		}
	}
}
