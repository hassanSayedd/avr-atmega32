/*
 * main.c
 *
 *  Created on: 1 Jul 2020
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"

#include "ServoMotor_int.h"

#include <util/delay.h>

int main(void)
{
	//servo will rotate automatically from angle 0 to 180
	while(1)
	{
		for(u8 i=0;i<180;i++)
		{
			ServoMotor_vidControl(i,ServoMotor_ChannelA);
			_delay_ms(20);
		}
		for(u8 i=180;i>0;i--)
		{
			ServoMotor_vidControl(i,ServoMotor_ChannelA);
			_delay_ms(20);
		}
	}
}

