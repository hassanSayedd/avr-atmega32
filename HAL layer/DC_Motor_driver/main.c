/*
 * main.c
 *
 *  Created on: Sep 3, 2019
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Dc_Motor_int.h"
#include "Dio_int.h"
#include "Dc_Motor_cfg.h"
#define F_CPU 8000000
#include <util/delay.h>

int main (void)
{
	DcMotor_vidInit();
	while(1)
	{
		DcMotor_vidControl(RIGHT);
		_delay_ms(100);
		DcMotor_vidInit();
		_delay_ms(1000);
		DcMotor_vidControl(LEFT);
		_delay_ms(100);
		DcMotor_vidInit();
		_delay_ms(1000);

	}
	return 0;
}
