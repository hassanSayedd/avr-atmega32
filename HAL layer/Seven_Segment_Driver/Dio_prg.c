/*
 * Dio_prog.c
 *
 *  Created on: Aug 17, 2019
 *      Author: express
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "DIO_priv.h"

void Dio_vidSetPinDir(u8 Pin,u8 Dir)
{
	u8 Loc_u8Port;
	u8 Loc_u8Pin;
	Loc_u8Port=Pin/8;
	Loc_u8Pin=Pin%8;
	switch(Loc_u8Port)
	{
	case 0:
		if (Dir==1)
		{
			SET_BIT(DDRA,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(DDRA,Loc_u8Pin);
		}
		break;
	case 1:
		if (Dir==1)
		{
			SET_BIT(DDRB,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(DDRB,Loc_u8Pin);
		}
		break;
	case 2:
		if (Dir==1)
		{
			SET_BIT(DDRC,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(DDRC,Loc_u8Pin);
		}
		break;
	case 3:
		if (Dir==1)
		{
			SET_BIT(DDRD,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(DDRD,Loc_u8Pin);
		}
		break;
	}

}

void Dio_vidSetPinVal(u8 Pin,u8 Val)
{
	u8 Loc_u8Port;
	u8 Loc_u8Pin;
	Loc_u8Port=Pin/8;
	Loc_u8Pin=Pin%8;
	switch(Loc_u8Port)
	{
	case 0:
		if (Val==1)
		{
			SET_BIT(PORTA,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(PORTA,Loc_u8Pin);
		}
		break;
	case 1:
		if (Val==1)
		{
			SET_BIT(PORTB,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(PORTB,Loc_u8Pin);
		}
		break;
	case 2:
		if (Val==1)
		{
			SET_BIT(PORTC,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(PORTC,Loc_u8Pin);
		}
		break;
	case 3:
		if (Val==1)
		{
			SET_BIT(PORTD,Loc_u8Pin);
		}
		else
		{
			CLEAR_BIT(PORTD,Loc_u8Pin);
		}
		break;
	}
}

u8 Dio_u8GetPinVal(u8 Pin)  //to get pin value from keypad to micro controller
{
	u8 Loc_u8Port;
	u8 Loc_u8pin;
	Loc_u8Port =Pin / 8;
	Loc_u8pin = Pin % 8;
	switch(Loc_u8Port)
	{
	case 0:
		return GET_BIT(PINA,Loc_u8pin);
		break ;
	case 1:
		return GET_BIT(PINB,Loc_u8pin);
		break ;
	case 2:
		return GET_BIT(PINC,Loc_u8pin);
		break ;
	case 3:
		return GET_BIT(PIND,Loc_u8pin);
		break ;
	}

}

void Dio_vidTglPinVal(u8 Pin)
{
	u8 Loc_u8Port;
	u8 Loc_u8Pin;
	Loc_u8Port=Pin/8;
	Loc_u8Pin=Pin%8;
	switch(Loc_u8Port)
	{
	case 0:
			TOGGLE_BIT(PORTA,Loc_u8Pin);
		break;
	case 1:
		TOGGLE_BIT(PORTB,Loc_u8Pin);
		break;
	case 2:
		TOGGLE_BIT(PORTC,Loc_u8Pin);
		break;
	case 3:
		TOGGLE_BIT(PORTD,Loc_u8Pin);
		break;
	}
}
