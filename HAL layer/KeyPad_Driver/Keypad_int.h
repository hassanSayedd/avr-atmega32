/*
 * Keypad_int.h
 *
 *  Created on: Aug 24, 2019
 *      Author: express
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

void Keypad_vidInit(void);
u8 Keypad_u8GetKey(void);
#define KEYPAD_u8NO_KEY 0xff

#endif /* KEYPAD_INT_H_ */
