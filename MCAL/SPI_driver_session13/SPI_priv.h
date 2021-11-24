/*
 * SPI_priv.h
 *
 *  Created on: Oct 11, 2019
 *      Author: mahmoud
 */

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_


#define SPDR  *((volatile u8 *)  0x2F  )
#define SPSR  *((volatile u8 *)  0x2E  )
#define SPCR  *((volatile u8 *)  0x2D  )
#define SREG  (*(volatile u8 *) 0x5F  ) //for GIE bit 7

#define   SS           DIO_u8PIN_12
#define   MOSI         DIO_u8PIN_13
#define   MISO         DIO_u8PIN_14
#define   CLK          DIO_u8PIN_15


#endif /* SPI_PRIV_H_ */
