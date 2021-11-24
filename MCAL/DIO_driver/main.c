/*
 * main.c
 *
 *  Created on: 15 Jun 2020
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"

#define F_CPU 8000000
#include <util/delay.h>
int main(void)
{

	// code for lab 1  on lec 1
	Dio_vidSetPinDir(DIO_u8PIN_6,DIO_u8OUTPUT);
	Dio_vidSetPinVal(DIO_u8PIN_6,DIO_u8HIGH);
	while (1);

	//********************************************************


	/*
	// code for lab 2 on lec 1

	Dio_vidSetPinDir(DIO_u8PIN_0,DIO_u8OUTPUT);
	Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
	_delay_ms(1000);
	Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
	while(1);
	//***************************************************
	 */

	/*
	//code for lab 3 on lec 2
	Dio_vidSetPinDir(DIO_u8PIN_0,DIO_u8OUTPUT);
	while(1)
	{
		Dio_vidTglPinVal(DIO_u8PIN_0);
		_delay_ms(1000);
	}

	//******************************************************
	 */

	/*
	//when an key is pressed led will be turned off
	Dio_vidSetPinDir(DIO_u8PIN_0,DIO_u8HIGH);
	Dio_vidSetPinDir(DIO_u8PIN_24,DIO_u8INPUT);
	Dio_vidSetPinVal(DIO_u8PIN_24,DIO_u8HIGH); //to activate pull up resistor
	while(1)
	{
		if (Dio_u8GetPinVal(DIO_u8PIN_24)==1)
		{
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8LOW);
		}
	}
	 */


}
