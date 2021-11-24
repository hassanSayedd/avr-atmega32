/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: express
 */


#define F_CPU 8000000
#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "Lcd_int.h"
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>  //for int0

u8 first_reading=1;
u8 state=0;
u32 Ovf_Counter=0;

f32 Ton=0;
f32 Toff=0;

int main (void)
{
	f32 T_total=0;
	u8 Freq=0;
	u8 Duty_Cycle=0;

	Lcd_vidInit();

	CLEAR_BIT(TCCR1A,1);  //FOR normal mode
	CLEAR_BIT(TCCR1A,0);  //FOR normal mode
	CLEAR_BIT(TCCR1B,4);  //FOR normal mode
	CLEAR_BIT(TCCR1B,3);  //FOR normal mode

	SET_BIT(TCCR1B,6); //RISING edge detecting

	CLEAR_BIT(TCCR1B,2);   //FOR NO PRESCALING FACTOR
	CLEAR_BIT(TCCR1B,1);   //FOR NO PRESCALING FACTOR
	SET_BIT(TCCR1B,0);     //FOR NO PRESCALING FACTOR

	SET_BIT(TIMSK,5);
	SET_BIT(TIMSK,2);

	SET_BIT(SREG,7);  //ENABLE GLOBAL INTERRUPT ENABLE

	Dio_vidSetPinDir(DIO_u8PIN_30,DIO_u8INPUT);


	while(1)
	{
		T_total=Ton+Toff;
		Freq=(u8) ((f32)1/T_total);
		Duty_Cycle= (u8) ( (Ton/T_total) *100);
		Lcd_vidGoTo(0,0);
		Lcd_vidWriteString("Freq= ");
		Lcd_vidWriteChar( (u8) ((Freq / 100)   +0x30));
		Lcd_vidWriteChar( (u8) (((Freq % 100)/10)+0x30));
		Lcd_vidWriteChar( (u8) (((Freq % 100)%10)+0x30));

		Lcd_vidWriteString(" Hz");

		Lcd_vidGoTo(1,0);
		Lcd_vidWriteString("Duty= ");
		Lcd_vidWriteChar( (u8) ((Duty_Cycle / 100)   +0x30));
		Lcd_vidWriteChar( (u8) ((Duty_Cycle % 100)/10+0x30));
		Lcd_vidWriteChar( (u8) ((Duty_Cycle % 100)%10+0x30));

		Lcd_vidWriteString(" %");

	}

	return 0;
}

ISR(TIMER1_CAPT_vect)
{
	if ( first_reading == 1)
	{
		first_reading=0;
		TCNT1=0;
		CLEAR_BIT(TCCR1B,6);

		state = 1;
		Ovf_Counter=0;
	}

	else
	{
		if (state==1)
		{
			SET_BIT(TCCR1B,6);
			state=0;
			Ton = (f32) ( (ICR1 +  (u32) ((u32)65535 * Ovf_Counter ))* (f32) ( (f32) 1/8000000)) ;
			Ovf_Counter=0;
			TCNT1=0;
		}
		else
		{
			CLEAR_BIT(TCCR1B,6);
			state=1;
			Toff = (f32) ( (ICR1 +  (u32) ( (u32)65535 * Ovf_Counter))* (f32) ( (f32) 1/8000000)) ;;
			Ovf_Counter=0;
			TCNT1=0;
		}
	}

}



ISR(TIMER1_OVF_vect)
{
	Ovf_Counter++;
}
