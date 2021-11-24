/*
 * main.c
 *
 *  Created on: Apr 27, 2020
 *      Author: express
 */


#include"Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "ADC_int.h"
#include "ADC_cfg.h"
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	ADC_vidInit();
	u16 digital=0,analog=0;
	while(1)
	{
		Dio_vidSetPinDir(DIO_u8PIN_0,DIO_u8INPUT);
		Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
		digital=ADC_u16ConvertChannel(0);
		analog=(digital*5)/256;
		if(analog>=3)
		{
			Dio_vidSetPinDir(DIO_u8PIN_2,DIO_u8OUTPUT);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8LOW);
			Dio_vidSetPinDir(DIO_u8PIN_1,DIO_u8OUTPUT);
			for(u8 i=1;i<2;i++)
			{
				Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8HIGH);
				_delay_ms(500);
				Dio_vidSetPinVal(DIO_u8PIN_1,DIO_u8LOW);
				_delay_ms(500);
			}
		}
		else
		{
			Dio_vidSetPinDir(DIO_u8PIN_2,DIO_u8OUTPUT);
			Dio_vidSetPinVal(DIO_u8PIN_2,DIO_u8HIGH);
		}
	}
	return 0;
}


