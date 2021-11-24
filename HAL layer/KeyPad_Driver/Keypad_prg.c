/*
 * Keypad_prg.c
 *
 *  Created on: Aug 24, 2019
 *      Author: express
 */

#include "std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "Keypad_cfg.h"
#include "Keypad_int.h"
void Keypad_vidInit(void)
{
	Dio_vidSetPinDir(KEYPAD_u8R1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(KEYPAD_u8R4,DIO_u8OUTPUT);


	Dio_vidSetPinDir(KEYPAD_u8C1,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C2,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C3,DIO_u8INPUT);
	Dio_vidSetPinDir(KEYPAD_u8C4,DIO_u8INPUT);


	Dio_vidSetPinVal(KEYPAD_u8C1,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C2,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C3,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8C4,DIO_u8HIGH);
}


u8 Keypad_u8GetKey(void)
{
	//1-generate pattern
	Dio_vidSetPinVal(KEYPAD_u8R1,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8R2,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R3,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4,DIO_u8HIGH);

	if(Dio_u8GetPinVal(KEYPAD_u8C1)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 1;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 2;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 3;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==0)
		return '+';



	//1-generate pattern
	Dio_vidSetPinVal(KEYPAD_u8R1,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R2,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8R3,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4,DIO_u8HIGH);

	if(Dio_u8GetPinVal(KEYPAD_u8C1)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 4;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 5;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 6;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==0)
		return '-';



	//1-generate pattern
	Dio_vidSetPinVal(KEYPAD_u8R1,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R2,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R3,DIO_u8LOW);
	Dio_vidSetPinVal(KEYPAD_u8R4,DIO_u8HIGH);

	if(Dio_u8GetPinVal(KEYPAD_u8C1)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 7;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 8;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 9;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==0)
		return '*';




	//1-generate pattern
	Dio_vidSetPinVal(KEYPAD_u8R1,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R2,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R3,DIO_u8HIGH);
	Dio_vidSetPinVal(KEYPAD_u8R4,DIO_u8LOW);

	if(Dio_u8GetPinVal(KEYPAD_u8C1)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return '#';
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return 0;
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==0 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==1)
		return '=';
	else if(Dio_u8GetPinVal(KEYPAD_u8C1)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C2)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C3)==1 &&
			Dio_u8GetPinVal(KEYPAD_u8C4)==0)
		return '/';
	return KEYPAD_u8NO_KEY;

}
