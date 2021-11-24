/*
 * DC_Motor_prg.c
 *
 *  Created on: Sep 3, 2019
 *      Author: express
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "Dc_Motor_cfg.h"
#include "Dc_Motor_int.h"

void DcMotor_vidInit(void)
{
	Dio_vidSetPinVal(DCMOTOR_u8NEGETIVE,DIO_u8LOW);
	Dio_vidSetPinVal(DCMOTOR_u8POSITIVE,DIO_u8LOW);

	Dio_vidSetPinDir(DCMOTOR_u8POSITIVE,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DCMOTOR_u8NEGETIVE,DIO_u8OUTPUT);

}

void DcMotor_vidControl(u8 dir)
{
	if(dir==RIGHT)
	{
		Dio_vidSetPinVal(DCMOTOR_u8POSITIVE,POSITIVE);
		Dio_vidSetPinVal(DCMOTOR_u8NEGETIVE,NEGETIVE);

	}
	else if (dir==LEFT)
	{
		Dio_vidSetPinVal(DCMOTOR_u8POSITIVE,NEGETIVE);
		Dio_vidSetPinVal(DCMOTOR_u8NEGETIVE,POSITIVE);
	}
}
