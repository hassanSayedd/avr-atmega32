/*
 * SPI_cfg.h
 *
 *  Created on: Oct 11, 2019
 *      Author: mahmoud
 */

#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/************0 FOR DISABLE 1 FOR ENABLE*********************/

#define SPI_INTERRUPT_ENABLE             0

/**************************************************/

/********selecting clk polarity*********/

#define  LOW_mode                        0
#define  HIGH_mode                       1

#define  SPI_CLK_POLARITY               LOW_mode
/*********************************************************/


/***********selecting clk phase**********************/

#define SETUP_LEADING_SAMPLE_TRAINING    0
#define SAMPLE_LEADING_SETUP_TRAINING    1

#define SPI_CLOCK_PHASE              SETUP_LEADING_SAMPLE_TRAINING
/******************************************************/


/*************selecting data order*************/

#define SPI_DATA_LSB                     0
#define SPI_DATA_MSB                     1

#define SPI_DATA_ORDER               SPI_DATA_LSB
/***************************************************/


/************prescaller************************/

#define SPI_PRESCALLER                   64
/*************************************************/


/**********spi mode*******************/

#define SPI_MASTER                           1
#define SPI_SLAVE                            0

#define SPI_MODE                       SPI_SLAVE
/*****************************************************/


#endif /* SPI_CFG_H_ */
