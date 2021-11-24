/*
 * LED_prg.c
 *
 *  Created on: Sep 1, 2019
 *      Author: express
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "LED_cfg.h"
#include "LED_int.h"
#include <avr/io.h>



void LED_vidInit(void)
{
	Dio_vidSetPinDir(LED_u8Num1,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LED_u8Num2,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LED_u8Num3,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LED_u8Num4,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LED_u8Num5,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LED_u8Num6,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LED_u8Num7,DIO_u8OUTPUT);
	Dio_vidSetPinDir(LED_u8Num8,DIO_u8OUTPUT);
}


void LED_vidControl(u8 id,u8 state)
{
	Dio_vidSetPinVal(id,state);

}

