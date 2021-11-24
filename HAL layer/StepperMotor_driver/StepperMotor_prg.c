/*
 * StepperMotor_prg.c
 *
 *  Created on: Sep 3, 2019
 *      Author: express
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "StepperMotor_int.h"
#include "StepperMotor_cfg.h"
#define F_CPU 8000000
#include <util/delay.h>


void StepperMotor_vidInit(void)
{
	Dio_vidSetPinVal(StepperMotor_u8Blue,DIO_u8LOW);
	Dio_vidSetPinVal(StepperMotor_u8Orange,DIO_u8LOW);
	Dio_vidSetPinVal(StepperMotor_u8Pink,DIO_u8LOW);
	Dio_vidSetPinVal(StepperMotor_u8Yellow,DIO_u8LOW);

	Dio_vidSetPinDir(StepperMotor_u8Blue,DIO_u8OUTPUT);
	Dio_vidSetPinDir(StepperMotor_u8Orange,DIO_u8OUTPUT);
	Dio_vidSetPinDir(StepperMotor_u8Yellow,DIO_u8OUTPUT);
	Dio_vidSetPinDir(StepperMotor_u8Pink,DIO_u8OUTPUT);

}


void StepperMotor_vidControl(u8 dir,u8 angle)
{
	u32 i;
	u8 RIGHT_PATTERN=0b00000001;
	u8 LEFT_PATTERN=0b00001000;

	/*
	 //de 45 w e5watha bs
	 if(dir==RIGHT)
	{
		switch (angle)
		{
		case 45:
			for(i=0;i<=256;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
				_delay_ms(2);
				RIGHT_PATTERN<<=1;
				if (RIGHT_PATTERN==0b00010000)
				{
					RIGHT_PATTERN=0b00000001;
				}
			}
			break ;
		case 90:
			for(i=0;i<=512;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
				_delay_ms(2);
				RIGHT_PATTERN<<=1;
				if (RIGHT_PATTERN==0b00010000)
				{
					RIGHT_PATTERN=0b00000001;
				}
			}
			break ;
		case 135:
			for(i=0;i<=768;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
				_delay_ms(2);
				RIGHT_PATTERN<<=1;
				if (RIGHT_PATTERN==0b00010000)
				{
					RIGHT_PATTERN=0b00000001;
				}
			}
			break ;
		case 180:
			for(i=0;i<=1024;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
				_delay_ms(2);
				RIGHT_PATTERN<<=1;
				if (RIGHT_PATTERN==0b00010000)
				{
					RIGHT_PATTERN=0b00000001;
				}
			}
			break ;
		case 225:
			for(i=0;i<=1280;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
				_delay_ms(2);
				RIGHT_PATTERN<<=1;
				if (RIGHT_PATTERN==0b00010000)
				{
					RIGHT_PATTERN=0b00000001;
				}
			}
			break ;
		case 270:
			for(i=0;i<=1536;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
				_delay_ms(2);
				RIGHT_PATTERN<<=1;
				if (RIGHT_PATTERN==0b00010000)
				{
					RIGHT_PATTERN=0b00000001;
				}
			}
			break ;
		case 315:
			for(i=0;i<=1792;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
				_delay_ms(2);
				RIGHT_PATTERN<<=1;
				if (RIGHT_PATTERN==0b00010000)
				{
					RIGHT_PATTERN=0b00000001;
				}
			}
			break ;
		case 360:
			for(i=0;i<=2048;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
				_delay_ms(2);
				RIGHT_PATTERN<<=1;
				if (RIGHT_PATTERN==0b00010000)
				{
					RIGHT_PATTERN=0b00000001;
				}
			}
			break ;
		}

	}
	else if (dir==LEFT)
	{
		switch (angle)
		{
		case 45:
			for(i=0;i<=256;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
				_delay_ms(2);
				LEFT_PATTERN>>=1;
				if (LEFT_PATTERN==0b00000000)
				{
					LEFT_PATTERN=0b00001000;
				}
			}
			break ;
		case 90:
			for(i=0;i<=512;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
				_delay_ms(2);
				LEFT_PATTERN>>=1;
				if (LEFT_PATTERN==0b00000000)
				{
					LEFT_PATTERN=0b00001000;
				}
			}
			break ;
		case 135:
			for(i=0;i<=768;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
				_delay_ms(2);
				LEFT_PATTERN>>=1;
				if (LEFT_PATTERN==0b00000000)
				{
					LEFT_PATTERN=0b00001000;
				}
			}
			break ;
		case 180:
			for(i=0;i<=1024;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
				_delay_ms(2);
				LEFT_PATTERN>>=1;
				if (LEFT_PATTERN==0b00000000)
				{
					LEFT_PATTERN=0b00001000;
				}
			}
			break ;
		case 225:
			for(i=0;i<=1280;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
				_delay_ms(2);
				LEFT_PATTERN>>=1;
				if (LEFT_PATTERN==0b00000000)
				{
					LEFT_PATTERN=0b00001000;
				}
			}
			break ;
		case 270:
			for(i=0;i<=1536;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
				_delay_ms(2);
				LEFT_PATTERN>>=1;
				if (LEFT_PATTERN==0b00000000)
				{
					LEFT_PATTERN=0b00001000;
				}
			}
			break ;
		case 315:
			for(i=0;i<=1792;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
				_delay_ms(2);
				LEFT_PATTERN>>=1;
				if (LEFT_PATTERN==0b00000000)
				{
					LEFT_PATTERN=0b00001000;
				}
			}
			break ;
		case 360:
			for(i=0;i<=2048;i++)
			{
				Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
				Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
				Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
				Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
				_delay_ms(2);
				LEFT_PATTERN>>=1;
				if (LEFT_PATTERN==0b00000000)
				{
					LEFT_PATTERN=0b00001000;
				}
			}
			break ;
		}
	}*/



	//ay angel ana 3awzha
	if(dir==RIGHT)
	{
		for(i=((5.688888888888888888888888888888888888888888888888888888888888888888888888888888888888*angle)+1);i>=1;i--)
		{
			Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(RIGHT_PATTERN,0));
			Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(RIGHT_PATTERN,1));
			Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(RIGHT_PATTERN,2));
			Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(RIGHT_PATTERN,3));
			_delay_ms(2);
			RIGHT_PATTERN<<=1;
			if (RIGHT_PATTERN==0b00010000)
			{
				RIGHT_PATTERN=0b00000001;
			}
		}
	}

	else if(dir==LEFT)
	{
		for(i=((5.688888888888888888888888888888888888888888888888888888888888888888888888888888888888888*angle)+1);i>=1;i--)
		{

			Dio_vidSetPinVal(StepperMotor_u8Orange,GET_BIT(LEFT_PATTERN,0));
			Dio_vidSetPinVal( StepperMotor_u8Yellow,GET_BIT(LEFT_PATTERN,1));
			Dio_vidSetPinVal( StepperMotor_u8Pink,GET_BIT(LEFT_PATTERN,2));
			Dio_vidSetPinVal( StepperMotor_u8Blue,GET_BIT(LEFT_PATTERN,3));
			_delay_ms(2);
			LEFT_PATTERN>>=1;
			if (LEFT_PATTERN==0b00000000)
			{
				LEFT_PATTERN=0b00001000;
			}
		}
	}
}
