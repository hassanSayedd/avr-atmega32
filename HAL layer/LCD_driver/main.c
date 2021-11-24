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

int main (void)
{
	/*
	//lab1 lec 3
	Lcd_vidInit();
	Lcd_vidGoTo(0,0);
	Lcd_vidWriteString("     hassan     ");
	Lcd_vidGoTo(1,0);
	Lcd_vidWriteString("   el gamed ");
	while(1);
	 */


	/*
	//lab 2 lec 3 moving name
	  u8 i;
	while(1)
	{
		Lcd_vidInit();
		Lcd_vidWriteString("hassan");
		_delay_ms(300);
		for(i=0;i<16;i++)
		{
			Lcd_vidSendCommand(0x1C);
			_delay_ms(300);
		}
		Lcd_vidInit();
		Lcd_vidGoTo(1,0);
		Lcd_vidWriteString("n");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidGoTo(1,0);
		Lcd_vidWriteString("an");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidGoTo(1,0);
		Lcd_vidWriteString("san");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidGoTo(1,0);
		Lcd_vidWriteString("ssan");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidGoTo(1,0);
		Lcd_vidWriteString("assan");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidGoTo(1,0);
		Lcd_vidWriteString("hassan");
		_delay_ms(300);
		for(i=0;i<16;i++)
		{
			Lcd_vidSendCommand(0x1C);
			_delay_ms(300);
		}
		Lcd_vidInit();
		Lcd_vidWriteString("n");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidWriteString("an");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidWriteString("san");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidWriteString("ssan");
		_delay_ms(300);
		Lcd_vidInit();
		Lcd_vidWriteString("assan");
		_delay_ms(300);
	}*/

	/*
	//sine shape
	 u8 i;
	Lcd_vidInit();
	while(1)
	{
		Lcd_vidSendCommand(0x01);
		Lcd_vidWriteChar('n');
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidWriteChar('a');
		Lcd_vidGoTo(1,1);
		Lcd_vidWriteChar('n');
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidWriteString("s n");
		Lcd_vidGoTo(1,1);
		Lcd_vidWriteChar('a');
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidWriteString("s a");
		Lcd_vidGoTo(1,1);
		Lcd_vidWriteString("s n");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidWriteString("a s n");
		Lcd_vidGoTo(1,1);
		Lcd_vidWriteString("s a");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidWriteString("h s a");
		Lcd_vidGoTo(1,1);
		Lcd_vidWriteString("a s n");
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,2);
		Lcd_vidWriteString("a s n");
		Lcd_vidGoTo(1,1);
		Lcd_vidWriteString("h s a");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,2);
		Lcd_vidWriteString("h s a");
		Lcd_vidGoTo(1,3);
		Lcd_vidWriteString("a s n");
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,4);
		Lcd_vidWriteString("a s n");
		Lcd_vidGoTo(1,3);
		Lcd_vidWriteString("h s a");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,4);
		Lcd_vidWriteString("h s a");
		Lcd_vidGoTo(1,5);
		Lcd_vidWriteString("a s n");
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,6);
		Lcd_vidWriteString("a s n");
		Lcd_vidGoTo(1,5);
		Lcd_vidWriteString("h s a");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,6);
		Lcd_vidWriteString("h s a");
		Lcd_vidGoTo(1,7);
		Lcd_vidWriteString("a s n");
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,8);
		Lcd_vidWriteString("a s n");
		Lcd_vidGoTo(1,7);
		Lcd_vidWriteString("h s a");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,8);
		Lcd_vidWriteString("h s a");
		Lcd_vidGoTo(1,9);
		Lcd_vidWriteString("a s n");
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,10);
		Lcd_vidWriteString("a s n");
		Lcd_vidGoTo(1,9);
		Lcd_vidWriteString("h s a");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,10);
		Lcd_vidWriteString("h s a");
		Lcd_vidGoTo(1,11);
		Lcd_vidWriteString("a s n");
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,12);
		Lcd_vidWriteString("a s n");
		Lcd_vidGoTo(1,11);
		Lcd_vidWriteString("h s a");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,12);
		Lcd_vidWriteString("h s ");
		Lcd_vidGoTo(1,13);
		Lcd_vidWriteString("a s");
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,14);
		Lcd_vidWriteString("a ");
		Lcd_vidGoTo(1,13);
		Lcd_vidWriteString("h s");
		_delay_ms(300);

		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(0,14);
		Lcd_vidWriteString("h ");
		Lcd_vidGoTo(1,15);
		Lcd_vidWriteString("a ");
		_delay_ms(300);
		Lcd_vidSendCommand(0x01);
		Lcd_vidGoTo(1,15);
		Lcd_vidWriteString("h ");
		_delay_ms(300);

	}*/

	/*

	//CUSTOM CARCHTER
		Lcd_vidInit();
		Lcd_vidSendCommand(0x40);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x01);
		Lcd_vidWriteChar(0b000111111);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x03);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);
		Lcd_vidSendCommand(0x48);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x0E);
		Lcd_vidWriteChar(0x02);
		Lcd_vidWriteChar(0x1F);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);

		Lcd_vidSendCommand(0x50);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0b000111111);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x03);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);

		Lcd_vidSendCommand(0x58);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0x07);
		Lcd_vidWriteChar(0b00010100);
		Lcd_vidWriteChar(0b00001010);
		Lcd_vidWriteChar(0b00001111);
		Lcd_vidWriteChar(0x00);

		Lcd_vidSendCommand(0x60);
		Lcd_vidWriteChar(0x00);
		Lcd_vidWriteChar(0b00011011);
		Lcd_vidWriteChar(0b00010101);
		Lcd_vidWriteChar(0b00010001);
		Lcd_vidWriteChar(0b00011011);
		Lcd_vidWriteChar(0b00001010);
		Lcd_vidWriteChar(0b00000100);
		Lcd_vidWriteChar(0x00);
		Lcd_vidGoTo(1,15);
		Lcd_vidWriteChar(0x00);
		Lcd_vidGoTo(1,14);
		Lcd_vidWriteChar(0x01);
		Lcd_vidGoTo(1,13);
		Lcd_vidWriteChar(0x02);
		Lcd_vidGoTo(1,12);
		Lcd_vidWriteChar(0x03);
		Lcd_vidGoTo(1,11);
		Lcd_vidWriteChar(0x04);
		return 0;*/


	return 0;
}
