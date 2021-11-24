/*
 * I2c_int.h
 *
 *  Created on: Oct 19, 2019
 *      Author: EngOm
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_

void I2c_vidInit(void);  //feha moshkla

void I2c_vidSendStart(void);

void I2c_vidSendSLA_W(u8 SLA);

void I2c_vidSendSLA_R(u8 SLA);

void I2c_vidSendData(u8 Data);

u8   I2c_u8ReceiveData(void);

void I2c_vidSendStop(void);

u8   I2c_u8CheckStatus(u8 ExpectedStatus);

#endif /* I2C_INT_H_ */
