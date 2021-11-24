/*
 * I2c_prg.c
 *
 *  Created on: Oct 19, 2019
 *      Author: EngOm
 */

#include "Std_types.h"
#include "Bit_math.h"

#include "I2c_int.h"
#include "I2c_priv.h"
#include "I2c_cfg.h"


void I2c_vidInit(void)
{
	/* Enable I2c Driver */
	SET_BIT(TWCR,2);

	/* Disable Acknowledge */
	CLEAR_BIT(TWCR,6);

	/* Set SCL = 100KHz */
	TWBR = 8;
	CLEAR_BIT(TWSR,1);
	CLEAR_BIT(TWSR,0);

	/* Set My Address = 1 and Disable General Call */
	TWAR = I2C_u8MY_ADDRESS<<1;
	CLEAR_BIT(TWAR,0);

	/* Disable Interrupt */
	CLEAR_BIT(TWCR,0);
}

void I2c_vidSendStart(void)
{
	/* Clear Flag, Send Start, Enable I2c Driver */
	TWCR = (1<<7) | (1<<5) | (1<<2);

	/* wait until the Start condition is transmitted */
	while(GET_BIT(TWCR,7) == 0);
}

void I2c_vidSendSLA_W(u8 SLA)
{
	/* Load Slave Address */
	TWDR = (SLA << 1);

	/* Clear Flag, Enable I2c Driver */
	TWCR = (1<<7) | (1<<2);

	/* wait until the SLA + W is transmitted */
	while(GET_BIT(TWCR,7) == 0);
}

void I2c_vidSendSLA_R(u8 SLA)
{
	/* Load Slave Address */
	TWDR = (SLA << 1) | 0x01;

	/* Clear Flag, Enable I2c Driver */
	TWCR = (1<<7) | (1<<2);

	/* wait until the SLA + R is transmitted */
	while(GET_BIT(TWCR,7) == 0);
}

void I2c_vidSendData(u8 Data)
{
	/* Load Data */
	TWDR = Data;

	/* Clear Flag, Enable I2c Driver */
	TWCR = (1<<7) | (1<<2);

	/* wait until the Data is transmitted */
	while(GET_BIT(TWCR,7) == 0);
}

u8   I2c_u8ReceiveData(void)
{
	/* Clear Flag, Enable I2c Driver */
	TWCR = (1<<7) | (1<<2);

	/* wait until the Data is Received */
	while(GET_BIT(TWCR,7) == 0);

	/* Return the received Data */
	return TWDR;
}

void I2c_vidSendStop(void)
{
	/* Clear Flag, Send Stop, Enable I2c Driver */
	TWCR = (1<<7) | (1<<4) | (1<<2);
}

u8   I2c_u8CheckStatus(u8 ExpectedStatus)
{
	u8 ReturnStatus;

	if(ExpectedStatus == (TWSR & 0xF8))
	{
		ReturnStatus = 1;
	}
	else
	{
		ReturnStatus = 0;
	}

	return ReturnStatus;
}
