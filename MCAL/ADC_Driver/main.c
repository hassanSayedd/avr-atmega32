/*
 * main.c
 *
 *  Created on: Sep 6, 2019
 *      Author: express
 */


#include "Std_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "ADC_int.h"
#include "Lcd_int.h"
#include "Seven_Segment_int.h"

#define F_CPU 8000000
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{

	/*
	// lab 2 for lec 7 (voltmeter)
	ADC_vidInit();
	Seven_seg_vidInit(LEFT);
	u16 digital,analog;
	Lcd_vidInit();
	u8 * value;
	u8 array[10]={'0 1 2 3 4 5 6 7 8 9'};



	//**********initialization for int0*********************
	SET_BIT(SREG,7);     //GIE ->1
	SET_BIT(MCUCR,0);  //ISC->LOW LEVEL sense control
	SET_BIT(MCUCR,1);  //ISC->LOW LEVEL sense control
	Dio_vidSetPinDir(DIO_u8PIN_26,DIO_u8INPUT); //zorar el interrupt
	Dio_vidSetPinVal(DIO_u8PIN_26,DIO_u8HIGH);
	SET_BIT(GICR,6);    //PIE->1


	while(1)
	{
		Lcd_vidGoTo(1,0);
		Lcd_vidWriteString("voltage=");
		digital=ADC_u16ConvertChannel(0);
		analog=(digital*5)/1024;
		Seven_seg_vidDisplay(LEFT,analog);
		if(GET_BIT(PINC,2)==1)
		{
			digital=ADC_u16ConvertChannel(0);
			analog=(digital*5)/1024;
			Lcd_vidWriteChar(0x30+analog);
			Lcd_vidWriteString(" volt ");
		}

		else if(GET_BIT(PINC,2)==0)
		{
			digital=ADC_u16ConvertChannel(0);
			analog=(digital*(5))/1024;
			Lcd_vidWriteChar(0x30+analog);   //tab3t awel rakm
			analog=(digital*(50))/1024;
			//analog=analog%1000;

			Lcd_vidWriteChar(0x30+(analog%10));   //tab3t tany rakm
			analog=(digital*(5000))/1024;
			analog=analog%1000;
			analog=analog%100;

			Lcd_vidWriteChar(0x30+(analog/10));   //tab3t talet rakm
			Lcd_vidWriteChar(0x30+(analog%10));    //a5er rakm

			Lcd_vidWriteString(" mV");
		}
	}
	 */


	/*
	//lab 1 for lec 7
	ADC_vidInit();
	Dio_vidSetPinDir(DIO_u8PIN_31,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_30,DIO_u8OUTPUT);
	Dio_vidSetPinDir(DIO_u8PIN_29,DIO_u8OUTPUT);
	u16 digital;
	f32 analog;

	while(1)
	{
		digital = ADC_u16ConvertChannel(0);
		analog = (digital*5)/1024;
		if(analog>=0 && analog <1.5)
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_30,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_29,DIO_u8LOW);
		}
		else if(analog>=1.5 && analog <3)
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_30,DIO_u8HIGH);
			Dio_vidSetPinVal(DIO_u8PIN_29,DIO_u8LOW);
		}
		else if(analog>=3)
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_30,DIO_u8LOW);
			Dio_vidSetPinVal(DIO_u8PIN_29,DIO_u8HIGH);
		}
	}
	 */


	/*
	//lab 2 for lec 8
	ADC_vidInit();
	Lcd_vidInit();
	Lcd_vidWriteString("Temperature : ");
	u32 digital=ADC_u16ConvertChannel(0);
	f32 analog=(digital*5000)/1024;
	u8 temp=analog/10;
	u8 temp1,temp2;
	while(1)
	{
		Lcd_vidGoTo(0,13);
		digital=ADC_u16ConvertChannel(0);
		analog=(digital*5000)/256;
		temp=analog/10;
		temp1=temp/10;
		temp1=temp1+48;
		temp2=temp%10;
		temp2=temp2+48;
		Lcd_vidWriteChar((u8) temp1);
		Lcd_vidWriteChar((u8) temp2);
		_delay_ms(1000);
	}
	 */


	//lab 3 for lec 8

	/*

	//LDR value =(R*5V-R*analog)/analog  where R=5kohm (1st one)
	//msh sha8al
	ADC_vidInit();
	u32 digital=ADC_u16ConvertChannel(0);
	f32 analog=(digital*5000)/1024;
	u32 LDR=(5000*5-5000*analog)/analog;
	Dio_vidSetPinDir(DIO_u8PIN_31,DIO_u8OUTPUT);
	while(1)
	{
		digital=ADC_u16ConvertChannel(0);
		analog=(digital*5)/1024;
		LDR=(5*5000-5000*analog)/analog;
		if(LDR>=9000)
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8HIGH);
		}
		else
		{
			Dio_vidSetPinVal(DIO_u8PIN_31,DIO_u8LOW);
		}

	}
	 */


	return 0;
}


ISR(INT0_vect)
{

}
