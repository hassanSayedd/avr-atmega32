/*
 * I2c_priv.h
 *
 *  Created on: Oct 19, 2019
 *      Author: EngOm
 */

#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_

#define TWBR    (*((volatile u8*) 0x20 ))
#define TWCR    (*((volatile u8*) 0x56 ))
#define TWDR    (*((volatile u8*) 0x23 ))
#define TWSR    (*((volatile u8*) 0x21 ))
#define TWAR    (*((volatile u8*) 0x22 ))

#endif /* I2C_PRIV_H_ */
