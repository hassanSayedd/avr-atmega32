/*
 * SPI_prg.c
 *
 *  Created on: Oct 11, 2019
 *      Author: mahmoud
 */

#include "STD_types.h"
#include "Bit_math.h"
#include "Dio_int.h"
#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_cfg.h"


void SPI_vidInit(void)
{

	SET_BIT(SPCR,6);   //enable SPI

	/**************master or slave selecting mode*******************/
#if SPI_MODE ==SPI_MASTER
	Dio_vidSetPinDir(MOSI,DIO_OUTPUT);
	Dio_vidSetPinDir(CLK,DIO_OUTPUT);
	Dio_vidSetPinDir(SS,DIO_OUTPUT);
	Dio_vidSetPinDir(MISO,DIO_INPUT);

	SET_BIT(SPCR,4);  //INTAL AS MASTER

#elif SPI_MODE==SPI_SLAVE

	Dio_vidSetPinDir(MOSI,DIO_INPUT);
	Dio_vidSetPinDir(CLK,DIO_INPUT);
	Dio_vidSetPinDir(SS,DIO_INPUT);
	Dio_vidSetPinVal(SS,DIO_HIGH);
	Dio_vidSetPinDir(MISO,DIO_OUTPUT);

	CLEAR_BIT(SPCR,4);  //INTAL AS MASTER

#endif
	/*****************************************************************/

	/**********LSB OR MSB******************/
#if SPI_DATA_ORDER==SPI_DATA_LSB
	SET_BIT(SPCR,5);

#elif SPI_DATA_ORDER==SPI_DATA_MSB
	CLEAR_BIT(SPCR,5);

#else
#error  " error in SPI_DATA_ORDER-CFG"
#endif
	/***********************************************/

	/**********CLK POLARITY***************/
#if SPI_CLK_POLARITY== LOW_mode
	CLEAR_BIT(SPCR,3);

#elif SPI_CLK_POLARITY==HIGH_mode
	SET_BIT(SPCR,3);

#else
#error  "error in spi_clock_porlaity"

#endif
	/******************************************************/

	/*************CLK PHASE****************/
#if SPI_CLOCK_PHASE==SETUP_LEADING_SAMPLE_TRAINING
	SET_BIT(SPCR,2);

#elif SPI_CLOCK_PHASE==SAMPLE_LEADING_SETUP_TRAINING
	CLEAR_BIT(SPCR,2);

#else
#error "SPI_CLOCK_PHASE"
#endif
	/****************************************************/

	/***************INTERRUPT ENABLE***************/
#if SPI_INTERRUPT_ENABLE==0
	CLEAR_BIT(SPCR,7);
#elif SPI_INTERRUPT_ENABLE==1
	SET_BIT(SREG,7); // to enable GIE
	SET_BIT(SPCR,7);
#else
#error "error in interrupt"
#endif
	/********************************************/


	/*************PRESCALLER************/
#if SPI_PRESCALLER==2
	CLEAR_BIT(SPCR,1);
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPSR,0);
#elif SPI_PRESCALLER==16
	CLEAR_BIT(SPCR,1);
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPSR,0);
#elif SPI_PRESCALLER==64
	SET_BIT(SPCR,1);
	CLEAR_BIT(SPCR,0);
	CLEAR_BIT(SPSR,0);
#elif SPI_PRESCALLER==128
	SET_BIT(SPCR,1);
	SET_BIT(SPCR,0);
	CLEAR_BIT(SPSR,0);

#else
#error "error in prescaller"
#endif
	/****************************************/
}



u8 SPI_u8TranCiever(u8 data)
{
	SPDR=data;
	while(!(GET_BIT(SPSR,7)));  //wait until SPI_INTERRUPT FLAG
	return (SPDR);

}
