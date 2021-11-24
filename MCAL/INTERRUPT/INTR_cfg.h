/*
 * INTR_cfg.h
 *
 *  Created on: 15 Jun 2020
 *      Author: express
 */

#ifndef INTR_CFG_H_
#define INTR_CFG_H_

// for intr0

/*************Interrupt 0 sense control*****************/

#define INTR_u8LowLevel_0         0
#define INTR_u8AnyLogicalChange_0 1
#define INTR_u8FallingEdge_0      10
#define INTR_u8RisingEdge_0       11

#define INTR_u8Int0SenseCont INTR_u8LowLevel_0

/*********************************************************/

// for intr1

/*************Interrupt 1 sense control*****************/

#define INTR_u8LowLevel_1         0
#define INTR_u8AnyLogicalChange_1 1
#define INTR_u8FallingEdge_1      10
#define INTR_u8RisingEdge_1       11

#define INTR_u8Int1SenseCont INTR_u8LowLevel_1

/*********************************************************/

// for intr2

/*************Interrupt 2 sense control*****************/

#define INTR_u8FallingEdge_2      0
#define INTR_u8RisingEdge_2       1

#define INTR_u8Int2SenseCont INTR_u8RisingEdge_2

/*********************************************************/

#endif /* INTR_CFG_H_ */
