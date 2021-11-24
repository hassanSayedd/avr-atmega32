/*
 * main.c
 *
 *  Created on: Sep 1, 2019
 *      Author: express
 */



#include "Std_types.h"
#include "Bit_math.h"
#include "LED_int.h"
#include "Dio_int.h"
#include "LED_cfg.h"
#define F_CPU 8000000
#include <avr/delay.h>


int main (void)
{
	LED_vidInit();
	while(1)
	{
		LED_vidControl(LED_u8Num1,ON);
		LED_vidControl(LED_u8Num2,ON);
		LED_vidControl(LED_u8Num3,ON);
		LED_vidControl(LED_u8Num4,ON);
		LED_vidControl(LED_u8Num5,ON);
		LED_vidControl(LED_u8Num6,ON);
		LED_vidControl(LED_u8Num7,ON);
		LED_vidControl(LED_u8Num8,ON);
		_delay_ms(1000);
		LED_vidControl(LED_u8Num1,OFF);
		LED_vidControl(LED_u8Num2,OFF);
		LED_vidControl(LED_u8Num3,OFF);
		LED_vidControl(LED_u8Num4,OFF);
		LED_vidControl(LED_u8Num5,OFF);
		LED_vidControl(LED_u8Num6,OFF);
		LED_vidControl(LED_u8Num7,OFF);
		LED_vidControl(LED_u8Num8,OFF);
		_delay_ms(1000);
	}
	return 0;
}
