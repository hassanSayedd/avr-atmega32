/*
 * Bit_math.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Ahmad Yehia
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg,Bit) Reg|=(1<<Bit)
#define CLEAR_BIT(Reg,Bit) Reg&=(~(1<<Bit))
#define GET_BIT(Reg,Bit) ((Reg>>Bit)&0x01)
#define TOGGLE_BIT(Reg,Bit) (Reg^=(1<<Bit))   // no space in the macroooooo
#endif /* BIT_MATH_H_ */
