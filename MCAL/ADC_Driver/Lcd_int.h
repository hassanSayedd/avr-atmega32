/*
 * Lcd_int.h
 *
 *  Created on: Aug 23, 2019
 *      Author: express
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

void Lcd_vidInit(void);
void Lcd_vidWriteChar(u8 characters);
void Lcd_vidSendCommand(u8 Cmd);
void Lcd_vidWriteString(u8 *str);
void Lcd_vidGoTo(u8 column,u8 row);
#endif /* LCD_INT_H_ */
