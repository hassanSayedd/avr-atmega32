/*
 * Bit_math.h
 *
 *  Created on: Aug 17, 2019
 *      Author: express
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit) reg |=(1<<bit)
#define CLEAR_BIT(reg,bit) reg &=(~(1<<bit))
#define GET_BIT(Reg,Bit) ((Reg>>Bit)&0x01)

#define TOGGLE_BIT(REG,BIT)  (REG^=(1<<BIT))

#endif /* BIT_MATH_H_ */
//3 functions likes macro to set bit or reset bit or get bit
