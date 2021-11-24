/*
 * main.c
 *
 *  Created on: Aug 3, 2019
 *      Author: express
 */


#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>
int main(void)
{
	DDRA=0xff;
	DDRB=0xff;
	DDRD=0xff;
	int  i,j,sig[10]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b1101101,0b011111101,0b00000111,0b111111111,0b01101111};
	while(1)
	{
		PORTA=0b00000001;
		PORTD=sig[1];
		PORTB=sig[0];
		_delay_ms(1000);
		PORTD=sig[0];
		for(i=9;i>=0;i--)
		{
			PORTB=sig[i];
			_delay_ms(1000);
		}
		PORTA=0b00000010;
		PORTD=sig[0];
		for(i=3;i>=0;i--)
		{
			PORTB=sig[i];
			_delay_ms(1000);
		}
		PORTA=0b00000100;
		PORTD=sig[1];
		PORTB=sig[0];
		_delay_ms(1000);
		PORTD=sig[0];
		for(i=9;i>=0;i--)
		{
			PORTB=sig[i];
			_delay_ms(1000);
		}
		PORTA=0b00000010;
		PORTD=sig[0];
		for(i=3;i>=0;i--)
		{
			PORTB=sig[i];
			_delay_ms(1000);
		}
	}
}
