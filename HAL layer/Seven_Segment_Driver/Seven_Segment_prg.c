/*
 * Seven_Segment_prg.c
 *
 *  Created on: Sep 2, 2019
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "Seven_Segment_cfg.h"
#include "Seven_Segment_int.h"


void Seven_seg_vidInit(u8 id)
{
	if (id==RIGHT)
	{
		Dio_vidSetPinDir(SEVEN_SEG_Right_u8PIN_A,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Right_u8PIN_B,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Right_u8PIN_C,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Right_u8PIN_D,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Right_u8PIN_E,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Right_u8PIN_F,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Right_u8PIN_G,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8OUTPUT);



		//FOR INTIALIZATION
		Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
	}
	else if (id==LEFT)
	{
		Dio_vidSetPinDir(SEVEN_SEG_Left_u8PIN_A,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Left_u8PIN_B,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Left_u8PIN_C,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Left_u8PIN_D,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Left_u8PIN_E,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Left_u8PIN_F,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Left_u8PIN_G,  DIO_u8OUTPUT);
		Dio_vidSetPinDir(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8OUTPUT);



		//FOR INTIALIZATION
		Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8LOW);
		Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);


	}
}

void Seven_seg_vidDisplay(u8 id,u8 num)
{
	if (id==RIGHT)
	{
		switch(num)
		{
		case 0:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 1:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 2:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 3:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 4:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 5:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 6:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 7:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 8:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;

		case 9:
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Right_u8PIN_DOT,DIO_u8LOW);
			break;
		}
	}

	else if (id==LEFT)
	{
		switch(num)
		{
		case 0:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 1:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 2:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 3:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 4:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 5:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 6:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 7:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 8:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;

		case 9:
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_A,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_B,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_C,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_D,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_E,  DIO_u8LOW);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_F,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_G,  DIO_u8HIGH);
			Dio_vidSetPinVal(SEVEN_SEG_Left_u8PIN_DOT,DIO_u8LOW);
			break;
		}
	}

}
