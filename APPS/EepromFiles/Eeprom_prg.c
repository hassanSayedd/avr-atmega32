/*
 * Eeprom_prg.c
 *
 *  Created on: Oct 19, 2019
 *      Author: EngOm
 */

#include "Std_types.h"
#include "Bit_math.h"

#include "I2c_int.h"

#include "Eeprom_int.h"
#include "Eeprom_cfg.h"


void Eeprom_vidInit(void)
{
	I2c_vidInit();
}

void Eeprom_vidWriteByte(u8 Location,u8 Byte)
{
	I2c_vidSendStart();

	if(I2c_u8CheckStatus(0x08) == 1)
	{
		I2c_vidSendSLA_W(EEPROM_u8SLAVE_ADDRESS);

		if(I2c_u8CheckStatus(0x18) == 1)
		{
			I2c_vidSendData(Location);

			if(I2c_u8CheckStatus(0x28) == 1)
			{
				I2c_vidSendData(Byte);

				if(I2c_u8CheckStatus(0x28) == 1)
				{
					I2c_vidSendStop();
				}
			}
		}
	}
}

u8   Eeprom_u8ReadByte(u8 Location)
{
	u8 ReceivedByte;
	I2c_vidSendStart();

	if(I2c_u8CheckStatus(0x08) == 1)
	{
		I2c_vidSendSLA_W(EEPROM_u8SLAVE_ADDRESS);

		if(I2c_u8CheckStatus(0x18) == 1)
		{
			I2c_vidSendData(Location);

			if(I2c_u8CheckStatus(0x28) == 1)
			{
				I2c_vidSendStart();

				if(I2c_u8CheckStatus(0x10) == 1)
				{
					I2c_vidSendSLA_R(EEPROM_u8SLAVE_ADDRESS);

					if(I2c_u8CheckStatus(0x40) == 1)
					{
						ReceivedByte = I2c_u8ReceiveData();
						I2c_vidSendStop();
					}
				}
			}
		}
	}
	return ReceivedByte;
}

