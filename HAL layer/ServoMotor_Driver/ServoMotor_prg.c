/*
 * ServoMotor_prg.c
 *
 *  Created on: 1 Jul 2020
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Timer_int.h"
#include "ServoMotor_cfg.h"
#include "ServoMotor_int.h"


void ServoMotor_vidInit(u8 channel)
{
	if (channel == ServoMotor_ChannelA)
	{
		Timer_vidGeneratePWM(ServoMotor_Frequency,450,Timer1_ChannelA);
	}
	else if (channel == ServoMotor_ChannelB)
	{
		Timer_vidGeneratePWM(ServoMotor_Frequency,450,Timer1_ChannelB);
	}
}

void ServoMotor_vidControl(u8 angle,u8 channel)
{
	//for time_on=450 angle is zero
	//for time_on=2610 angle is 180
	//so each 1 degree time_on=(2610-450)/180=12

	u16 time_on=450+12*angle;
	if (channel == ServoMotor_ChannelA)
	{
		Timer_vidGeneratePWM(ServoMotor_Frequency,time_on,Timer1_ChannelA);
	}
	else if (channel == ServoMotor_ChannelB)
	{
		Timer_vidGeneratePWM(ServoMotor_Frequency,time_on,Timer1_ChannelB);
	}
}
