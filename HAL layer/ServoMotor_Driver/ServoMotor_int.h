/*
 * ServoMotor_int.h
 *
 *  Created on: 1 Jul 2020
 *      Author: express
 */

#ifndef SERVOMOTOR_INT_H_
#define SERVOMOTOR_INT_H_

#define ServoMotor_ChannelA  			1     //pin 5 at port D
#define ServoMotor_ChannelB				2     //pin 4 at port D

void ServoMotor_vidInit(u8 channel);

void ServoMotor_vidControl(u8 angle,u8 channel);


#endif /* SERVOMOTOR_INT_H_ */
