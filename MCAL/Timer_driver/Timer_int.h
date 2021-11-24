/*
 * Timer0_int.h
 *
 *  Created on: 25 Jun 2020
 *      Author: express
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

#define Timer0_NormalMode             1
#define Timer0_PWMPhaseCorrect        2
#define Timer0_CTC                    3
#define Timer0_FastPWM                4

#define Timer1_NonPWM				  5
#define Timer1_FastPWM                6
#define Timer1_PhaseAndFreqCorrect    7
#define Timer1_ChannelA               8
#define Timer1_ChannelB               9

#define Timer2_NormalMode             10
#define Timer2_PWMPhaseCorrect        11
#define Timer2_CTC                    12
#define Timer2_FastPWM                13


void Timer_vidTimer0Init(u8 mode);
void Timer_vidTimer1Init(u8 mode,u8 channel);
void Timer_vidTimer2Init(u8 mode);

void Timer_vidSetTimer0IntialVal(u8 value);
void Timer_vidSetTimer1IntialVal(u16 value);
void Timer_vidSetTimer2IntialVal(u8 value);

void Timer_vidSetTimer0CmprVal(u8 value);
void Timer_vidSetTimer1CmprValA(u16 value);  //for channel A
void Timer_vidSetTimer1CmprValB(u16 value);  //for channel B
void Timer_vidSetTimer2CmprVal(u8 value);

void Timer_vidSetTimer1TopVal(u16 value);

void Timer_vidGeneratePWM(u32 freq,u16 time_on,u8 channel); //frequency range from 1 Hz to 1 MHz & time in microSeconds up to 64 milliSecond(65535 microSecond)

#endif /* TIMER_INT_H_ */
