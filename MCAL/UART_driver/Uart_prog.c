/*
 * Uart_prog.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Ahmad Yehia
 */


#include"std_types.h"
#include"Bit_math.h"

#include "Uart_int.h"
#include "Uart_cfg.h"
#include "Uart_Priv.h"


void Uart_vidInit(void)
{
	u8 Reg_Value = 0;

	/* Enable RxEN */
	SET_BIT(UCSRB,4);

	/* Enable TxEN */
	SET_BIT(UCSRB,3);

	/* Asynchronous Mode */
	CLEAR_BIT(Reg_Value,6);

	/* No Parity */
	CLEAR_BIT(Reg_Value,5);
	CLEAR_BIT(Reg_Value,4);

	/* 1-bit Stop */
	CLEAR_BIT(Reg_Value,3);

	/* Character Size = 8-bit Data */
	CLEAR_BIT(UCSRB,2);
	SET_BIT(Reg_Value,2);
	SET_BIT(Reg_Value,1);

	/* Assign Reg_Value into UCSRC */
	SET_BIT(Reg_Value,7);  // To write the data into UCSRC
	UCSRC = Reg_Value;

	/* BaudRate = 115200bps */

	//BoudRate = F_CPU/16*(UBRR+1)  as we chooses asynchronous normal speed and this equation from data sheet page 141
	//then UBRR=(F_CPU/(16*BoudRate))-1=( (8*1000000)/(16*9600) )-1=3

	UBRRH = 0;   //zero means that i write the data in UBRH not UCSRC as the 2 reg has the same address (data sheet) and also i write zero to 4 MSB for the BoudRate
	UBRRL = 3;  //8 LSB for the BAUDRATE


}


//the next 2 functions don't handle any kind of error so we didn't use any bit that handle errors

void Uart_vidSendChar(u8 Data)
{
	/* Wait till UDR register is Empty */
	while(GET_BIT(UCSRA,5) == 0);

	/* Send Data */
	UDR = Data;
}

void Uart_vidSendData(u8 * data)
{
	u32 i=0;
	while(data[i] != '\0')
	{
		Uart_vidSendChar(data[i]);
		i++;
	}
}

u8   Uart_u8ReceiveData(void)
{
	u16 timeout=0;
	u8 ReturnData=0;
	/* Wait till Data is received */
	while(GET_BIT(UCSRA,7) == 0)
	{
		timeout++;
		if (timeout>4000)
		{
			ReturnData=255;
			break;
		}
	}

	/* Read and return the received Data */
	if(ReturnData == 0)
	{
		return UDR;
	}
	else
	{
		return ReturnData;
	}
}
