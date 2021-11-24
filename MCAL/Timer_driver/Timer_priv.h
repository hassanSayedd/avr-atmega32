/*
 * Timer0_priv.h
 *
 *  Created on: 25 Jun 2020
 *      Author: express
 */

#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_

//***************for timer 0 **********************

#define TCCR0   (*(volatile u8 *)0x53) //TIMER/COUNTER CONTROL RIGISTER
#define TCNT0   (*(volatile u8 *)0x52)
#define OCR0    (*(volatile u8 *)0x5C)

//****************************************************

//*************for timer 1*************************

#define TCCR1A   (*(volatile u8 *)0x4F)
#define TCCR1B   (*(volatile u8 *)0x4E)

#define TCNT1H   (*(volatile u8 *)0x4D)
#define TCNT1L   (*(volatile u8 *)0x4C)
#define TCNT1    (*(volatile u16 *)0x4C)

#define OCR1AH   (*(volatile u8 *)0x4B)
#define OCR1AL   (*(volatile u8 *)0x4A)
#define OCR1A    (*(volatile u16 *)0x4A)

#define OCR1BH   (*(volatile u8 *)0x49)
#define OCR1BL   (*(volatile u8 *)0x48)
#define OCR1B    (*(volatile u16 *)0x48)

#define ICR1H    (*(volatile u8 *)0x47)
#define ICR1L    (*(volatile u8 *)0x46)
#define ICR1     (*(volatile u16 *)0x46)

//*****************************************************

//***************for timer 2 **********************

#define TCCR2   (*(volatile u8 *)0x45)
#define TCNT2   (*(volatile u8 *)0x44)
#define OCR2    (*(volatile u8 *)0x43)
#define ASSR    (*(volatile u8 *)0x42)


//****************************************************

//***********for all timers***************
#define TIMSK   (*(volatile u8 *)0x59)
#define TIFR    (*(volatile u8 *)0x58)
#define SFIOR   (*(volatile u8 *)0x50)

#define SREG    (*(volatile u8 *)0x5F) //for GIE bit 7
#define DDRD    (*(volatile u8 *)0x31)

#endif /* TIMER_PRIV_H_ */
