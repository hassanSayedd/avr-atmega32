/*
 * Dio_int.h
 *
 *  Created on: Aug 17, 2019
 *      Author: express
 */
//interface file any one want to interface to any device must include this header file


#ifndef INTR_INT_H_
#define INTR_INT_H_

void INTR_vidInit(u8 intr_type);

#define INTR_u8INT_0       0
#define INTR_u8INT_1       1
#define INTR_u8INT_2       2

#endif /* INTR_INT_H_ */
