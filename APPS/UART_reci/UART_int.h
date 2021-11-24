/*
 * Uart_int.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Ahmad Yehia
 */

#ifndef UART_INT_H_
#define UART_INT_H_


void Uart_vidInit(void);

void Uart_vidSendChar(u8 Data);

void Uart_vidSendData(u8* Data);

u8   Uart_u8ReceiveData(void);

#endif /* UART_INT_H_ */
