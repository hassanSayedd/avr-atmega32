/*
 * ADC_priv.h
 *
 *  Created on: 17 Jun 2020
 *      Author: express
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

#define ADMUX   (*(volatile u8 *)0x27)
#define ADCSRA  (*(volatile u8 *)0x26)
#define ADCH    (*(volatile u8 *)0x25)
#define ADCL    (*(volatile u8 *)0x24)
#define SFIOR   (*(volatile u8 *)0x50)
#define SREG    (*(volatile u8 *)0x5F) //for GIE bit 7


#endif /* ADC_PRIV_H_ */
