/*
 * main.c
 *
 *  Created on: 15 Jun 2020
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "INTR_int.h"
#include "Dio_int.h"
#include <avr/interrupt.h>
#define F_CPU 8000000
#include <util/delay.h>
int main(void)
{
	INTR_vidInit(INTR_u8INT_0);
 	Dio_vidSetPinDir(DIO_u8PIN_31,DIO_u8OUTPUT);
	while (1)
	{
		Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8LOW);
	}
}

ISR (INT0_vect)
{
	Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8HIGH);
}
