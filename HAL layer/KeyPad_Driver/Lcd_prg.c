/*
 * Lcd_prg.c
 *
 *  Created on: Aug 23, 2019
 *      Author: express
 */

#define F_CPU 8000000
#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd_cfg.h"
#include "Lcd_int.h"
void Lcd_vidInit(void)
{
#if Lcd_u8Mode==Lcd_u8EightBit
	Dio_vidSetPinDir(LCD_u8D0,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D4,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RS,DIO_u8OUTPUT);
	//Dio_vidSetPinDir(LCD_u8RW,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8EN,DIO_u8OUTPUT);
	Lcd_vidSendCommand(0x38); //for 2 lines and 5*7 pixels for 1 digit (8 bit mode)
	_delay_ms(2);
	Lcd_vidSendCommand(0x0c); //display on ,cursor off
	_delay_ms(2);
	Lcd_vidSendCommand(0x01); //to clear display
	_delay_ms(2);

#elif Lcd_u8Mode==Lcd_u8FourBit
	Dio_vidSetPinDir(LCD_u8D4,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D5,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D6,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8D7,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LCD_u8RS,DIO_u8OUTPUT);
	//Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinDir(LCD_u8EN,DIO_u8OUTPUT);
	Lcd_vidSendCommand(0x32);
	_delay_ms(2);
	Lcd_vidSendCommand(0x28); //for 2 lines and 5*7 pixels for 1 digit (4 bit mode)
	_delay_ms(2);
	Lcd_vidSendCommand(0x0c); //display on ,cursor off
	_delay_ms(2);
	Lcd_vidSendCommand(0x01); //to clear display
	_delay_ms(2);
#endif

}

void Lcd_vidWriteChar(u8 Character)
{

#if Lcd_u8Mode==Lcd_u8EightBit
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8HIGH);
	//Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8D0,GET_BIT(Character,0));
	Dio_vidSetPinVal(LCD_u8D1,GET_BIT(Character,1));
	Dio_vidSetPinVal(LCD_u8D2,GET_BIT(Character,2));
	Dio_vidSetPinVal(LCD_u8D3,GET_BIT(Character,3));
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Character,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Character,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Character,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Character,7));
	_delay_ms(4);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

#elif Lcd_u8Mode==Lcd_u8FourBit
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8HIGH);
	//Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Character,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Character,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Character,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Character,7));
	_delay_ms(4);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Character,0));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Character,1));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Character,2));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Character,3));
	_delay_ms(4);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

#endif
}

void Lcd_vidSendCommand(u8 Cmd)
{

#if Lcd_u8Mode==Lcd_u8EightBit
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8LOW);
	//Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8D0,GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D1,GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D2,GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D3,GET_BIT(Cmd,3));
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Cmd,7));
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

#elif Lcd_u8Mode==Lcd_u8FourBit
	Dio_vidSetPinVal(LCD_u8RS,DIO_u8LOW);
	//Dio_vidSetPinVal(LCD_u8RW,DIO_u8LOW);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Cmd,4));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Cmd,5));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Cmd,6));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Cmd,7));
	_delay_ms(4);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8HIGH);
	Dio_vidSetPinVal(LCD_u8D4,GET_BIT(Cmd,0));
	Dio_vidSetPinVal(LCD_u8D5,GET_BIT(Cmd,1));
	Dio_vidSetPinVal(LCD_u8D6,GET_BIT(Cmd,2));
	Dio_vidSetPinVal(LCD_u8D7,GET_BIT(Cmd,3));
	_delay_ms(2);
	Dio_vidSetPinVal(LCD_u8EN,DIO_u8LOW);

#endif
}

void Lcd_vidWriteString(u8 *str)
{
	u8 i;
	for(i=0;i<32;i++)
	{
		if(i==16)
			Lcd_vidGoTo(1,0);
		if ( str[i] == '\0' )
			break;
		else
			Lcd_vidWriteChar(str[i]);
	}
}

/*void Lcd_vidGoTo(u8 column ,u8 row)
{
	u8 i;
	if(column==0)
	{
		Lcd_vidSendCommand(0x80); //force cursor to beginning 1st row
		for(i=0;i<row;i++)
			Lcd_vidSendCommand(0x14); //shift cursor to right
	}
	else if(column==1)
	{
		Lcd_vidSendCommand(0xC0); //force cursor to beginning 2nd row
		for(i=0;i<row;i++)
			Lcd_vidSendCommand(0x14); //shift cursor to right
	}
}*/

void Lcd_vidGoTo(u8 column ,u8 row)
{
	switch (column)
	{

	case 0:
		if(row==0)
			Lcd_vidSendCommand(0x80);
		else if(row==1)
			Lcd_vidSendCommand(0x81);
		else if(row==2)
			Lcd_vidSendCommand(0x82);
		else if(row==3)
			Lcd_vidSendCommand(0x83);
		else if(row==4)
			Lcd_vidSendCommand(0x84);
		else if(row==5)
			Lcd_vidSendCommand(0x85);
		else if(row==6)
			Lcd_vidSendCommand(0x86);
		else if(row==7)
			Lcd_vidSendCommand(0x87);
		else if(row==8)
			Lcd_vidSendCommand(0x88);
		else if(row==9)
			Lcd_vidSendCommand(0x89);
		else if(row==10)
			Lcd_vidSendCommand(0x8a);
		else if(row==11)
			Lcd_vidSendCommand(0x8b);
		else if(row==12)
			Lcd_vidSendCommand(0x8c);
		else if(row==13)
			Lcd_vidSendCommand(0x8d);
		else if(row==14)
			Lcd_vidSendCommand(0x8e);
		else if(row==15)
			Lcd_vidSendCommand(0x8f);
		break ;
	case 1:
		if(row==0)
			Lcd_vidSendCommand(0xc0);
		else if(row==1)
			Lcd_vidSendCommand(0xc1);
		else if(row==2)
			Lcd_vidSendCommand(0xc2);
		else if(row==3)
			Lcd_vidSendCommand(0xc3);
		else if(row==4)
			Lcd_vidSendCommand(0xc4);
		else if(row==5)
			Lcd_vidSendCommand(0xc5);
		else if(row==6)
			Lcd_vidSendCommand(0xc6);
		else if(row==7)
			Lcd_vidSendCommand(0xc7);
		else if(row==8)
			Lcd_vidSendCommand(0xc8);
		else if(row==9)
			Lcd_vidSendCommand(0xc9);
		else if(row==10)
			Lcd_vidSendCommand(0xca);
		else if(row==11)
			Lcd_vidSendCommand(0xcb);
		else if(row==12)
			Lcd_vidSendCommand(0xcc);
		else if(row==13)
			Lcd_vidSendCommand(0xcd);
		else if(row==14)
			Lcd_vidSendCommand(0xce);
		else if(row==15)
			Lcd_vidSendCommand(0xcf);
		break ;
	}
}

