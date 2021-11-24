/*
 * main.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Ahmad Yehia
 */



#include"std_types.h"
#include"Bit_math.h"
#include "SPI_int.h"
#include "Dio_int.h"

#define F_CPU 8000000
#include <util/delay.h>

/************transmitter code*****************/

/*int main(void)
{
	u8 data;
	// Initialize SPI Module
	SPI_vidInit();

	while(1)
	{
		data=SPI_u8TranCiever('a');
		_delay_ms(1000);

		data=SPI_u8TranCiever('b');
		_delay_ms(1000);
	}
	return 0;
}
*/


/************************** Receiver Code ***************/


int main(void)
{
	u8 Received_Data;
	SPI_vidInit();
	Dio_vidSetPinDir(DIO_u8PIN_31,DIO_OUTPUT);

	while(1)
	{
		Received_Data = SPI_u8TranCiever(DUMMY_DATA);
		if(Received_Data == 'a')
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_HIGH);
		}
		else
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_LOW);
		}
	}
	return 0;
}



