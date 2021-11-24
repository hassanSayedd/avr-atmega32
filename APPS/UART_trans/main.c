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

#define F_CPU 8000000
#include <util/delay.h>

void ESP_vidWifiConnect(u8* Name,u8* Password);


int main(void)
{
	Uart_vidInit();
	ESP_vidWifiConnect("Name","123");
	Dio_vidSetPinDir(DIO_u8PIN_0,DIO_u8OUTPUT);
	Dio_vidSetPinVal(DIO_u8PIN_0,DIO_u8HIGH);

}

void ESP_vidWifiConnect(u8* Name,u8* Password)
{
	u8 Local_u8Result = 0;

	while(Local_u8Result == 0)
	{
		///* Connect to the WIFI /

		Uart_vidSendData("AT+CWJAP_CUR=\"");
		Uart_vidSendData(Name);
		Uart_vidSendData("\",\"");
		Uart_vidSendData(Password);
		Uart_vidSendData("\"\r\n");
		_delay_ms(20000);
		//Local_u8Result = voidEspValidateCmd();
		Local_u8Result = 1;
	}
}
