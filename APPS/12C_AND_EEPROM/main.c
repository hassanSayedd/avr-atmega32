/*
 * main.c
 *
 *  Created on: Oct 19, 2019
 *      Author: EngOm
 */
/********************* Writing Application ********/

/*#include "Std_types.h"
#include "Bit_math.h"

#include "Eeprom_int.h"
#include "Lcd_int.h"

#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{

	Lcd_vidInit();

	u8 loopCounter;
	u8 MyName[10] = {'H','A','S','S','A','N',' ',' ',' ',' '};


	Eeprom_vidInit();

	for(loopCounter = 0;loopCounter < 10;loopCounter++)
	{
		Eeprom_vidWriteByte(loopCounter, MyName[loopCounter]);
		_delay_ms(5);
	}


	Lcd_vidWriteString("Done!!!");

	while(1);

	return 0;
}*/

/********** Reading Application **************/

#include "Std_types.h"
#include "Bit_math.h"

#include "Eeprom_int.h"
#include "Lcd_int.h"

#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{

	u8 loopCounter;
	u8 ReceivedByte;

	Lcd_vidInit();
	Eeprom_vidInit();

	for(loopCounter = 0;loopCounter < 10;loopCounter++)
	{
		ReceivedByte = Eeprom_u8ReadByte(loopCounter);
		Lcd_vidWriteChar(ReceivedByte);
		_delay_ms(5);
	}

	while(1);

	return 0;
}

