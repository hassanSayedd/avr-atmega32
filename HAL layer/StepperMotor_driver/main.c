/*
 * main.c
 *
 *  Created on: Sep 3, 2019
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "StepperMotor_int.h"
#include "Dio_int.h"
#include "StepperMotor_cfg.h"
#define F_CPU 8000000
#include <util/delay.h>
#include <avr/io.h>

int main (void)
{
	StepperMotor_vidInit();
	while(1)
	{
	StepperMotor_vidControl(LEFT,360);
	}
	_delay_ms(1000);
	StepperMotor_vidControl(LEFT,180);
	return 0;
}
