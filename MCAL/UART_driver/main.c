/*
 * main.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Ahmad Yehia
 */


#include"std_types.h"
#include"Bit_math.h"


#include "Uart_int.h"

#define F_CPU 8000000
#include <util/delay.h>

/************transmitter code*****************/

int main(void)
{
	// Initialize UART Module
	Uart_vidInit();

	while(1)
	{
		Uart_vidSendData('a');
		_delay_ms(1000);

		Uart_vidSendData('b');
		_delay_ms(1000);
	}
	return 0;
}



/************************** Receiver Code ***************/

/*
int main(void)
{
	u8 Received_Data;
	Uart_vidInit();
	Dio_vidSetPinDir(DIO_u8PIN_31,DIO_u8OUTPUT);

	while(1)
	{
		Received_Data = Uart_u8ReceiveData();
		if(Received_Data == 'a')
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8LOW);
		}
	}
	return 0;
}

*/
