/*
 * main.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Ahmad Yehia
 */


#include"std_types.h"
#include"Bit_math.h"

#include "Dio_int.h"
#include "Uart_int.h"
#include "Lcd_int.h"

#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
	Uart_vidInit();
	Lcd_vidInit();
	u8 Local_u8Response[100] = {0};
	u8 i = 0;
	u8 Dummy = 0;
	u8 Result = 0;

	Lcd_vidWriteString("fe el awl");
	_delay_ms(2000);

	while (Dummy != 255)
	{
		Lcd_vidInit();
		Dummy = Uart_u8ReceiveData();
		Local_u8Response[i] = Dummy;
		i++;
	}

	Lcd_vidWriteString(Local_u8Response);

}
