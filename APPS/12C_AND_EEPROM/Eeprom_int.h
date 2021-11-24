/*
 * Eeprom_int.h
 *
 *  Created on: Oct 19, 2019
 *      Author: EngOm
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

void Eeprom_vidInit(void);

void Eeprom_vidWriteByte(u8 Location,u8 Byte);

u8   Eeprom_u8ReadByte(u8 Location);


#endif /* EEPROM_INT_H_ */
