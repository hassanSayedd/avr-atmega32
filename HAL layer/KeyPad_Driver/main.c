/*
 * main.c
 *
 *  Created on: Aug 24, 2019
 *      Author: express
 */

//#include <avr/io.h>
#include "std_types.h"
#include "Bit_math.h"
#include "dio_int.h"
#include "Keypad_int.h"
#include "Lcd_int.h"

int main (void)
{
	/*
	//lab 1 lec 4
	Keypad_vidInit();
	Lcd_vidInit();
	Lcd_vidWriteString("you pressed : ");
	Lcd_vidGoTo(1,0);
	while(1)
	{
		u8 i;
		i=Keypad_u8GetKey();
		if(!(i>=0 && i<=9))
		{
			continue;
		}
		Lcd_vidWriteChar((u8)i+48);
		Lcd_vidGoTo(1,0);
	}
	*/

	/*
	//code keybad linked with leds
	u8 pressed_key;
	Keypad_vidInit();
	Dio_vidSetPinDir(DIO_u8PIN_24,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_25,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_26,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_27,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_28,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_30,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_31,DIO_u8OUTPUT);
	while(1)
	{
		pressed_key=Keypad_u8GetKey();
		if(pressed_key==1)
			Dio_vidSetPinVal(DIO_u8PIN_24,DIO_u8HIGH);
		else if(pressed_key==2)
			Dio_vidSetPinVal(DIO_u8PIN_25,DIO_u8HIGH);
		else if(pressed_key==3)
			Dio_vidSetPinVal(DIO_u8PIN_26,DIO_u8HIGH);
		else if(pressed_key==4)
			Dio_vidSetPinVal(DIO_u8PIN_27,DIO_u8HIGH);
		else if(pressed_key==5)
			Dio_vidSetPinVal(DIO_u8PIN_28,DIO_u8HIGH);
		else if(pressed_key==6)
			Dio_vidSetPinVal(DIO_u8PIN_29,DIO_u8HIGH);
		else if(pressed_key==7)
			Dio_vidSetPinVal(DIO_u8PIN_30,DIO_u8HIGH);
		else if(pressed_key==8)
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8HIGH);
		else if(pressed_key==0)
		{
			Dio_vidSetPinVal(DIO_u8PIN_24,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_25,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_26,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_27,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_28,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_29,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_30,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8HIGH);

		}
		else
		{
			Dio_vidSetPinVal(DIO_u8PIN_24,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_25,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_26,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_27,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_28,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_29,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_30,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8LOW);

		}
	}
	 */
	return 0;
}
