/*
 * MyDIO_priv.h
 *
 *  Created on: 7 Jun 2020
 *      Author: express
 */

#ifndef INTR_PRIV_H_
#define INTR_PRIV_H_

#define MCUCR   (*(volatile u8 *)0x55) //for interrupt mode timer(0,1)
#define MCUCSR  (*(volatile u8 *)0x54) //for interrupt mode timer(2)
#define GICR    (*(volatile u8 *)0x5B) //for PIE
#define GIFR    (*(volatile u8 *)0x5A) //for interrupt flag
#define SREG    (*(volatile u8 *)0x5F) //for GIE bit 7

#define DDRB    (*(volatile u8 *)0x37)
#define PORTB   (*(volatile u8 *)0x38)
#define PINB    (*(volatile u8 *)0x36)

#define DDRD    (*(volatile u8 *)0x31)
#define PORTD   (*(volatile u8 *)0x32)
#define PIND    (*(volatile u8 *)0x30)


#endif /* INTR_PRIV_H_ */
