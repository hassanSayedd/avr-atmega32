/*
 * main.c
 *
 *  Created on: Sep 2, 2019
 *      Author: express
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "Seven_Segment_int.h"

#define F_CPU 8000000
#include <avr/delay.h>


int main (void)
{


	//code for lab 5 lec 1
	Seven_seg_vidInit(RIGHT);
	u8 i;
	while(1)
	{
		for(i=0 ; i<=9 ;i++)
		{
			Seven_seg_vidDisplay(RIGHT,i);
			_delay_ms(400);
		}
	}


	return 0;
}
