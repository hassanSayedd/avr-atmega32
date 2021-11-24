/*
 * Lcd_cfg.h
 *
 *  Created on: Aug 23, 2019
 *      Author: express
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#define LCD_u8D0   DIO_u8PIN_0
#define LCD_u8D1   DIO_u8PIN_1
#define LCD_u8D2   DIO_u8PIN_2
#define LCD_u8D3   DIO_u8PIN_3
#define LCD_u8D4   DIO_u8PIN_4
#define LCD_u8D5   DIO_u8PIN_5
#define LCD_u8D6   DIO_u8PIN_6
#define LCD_u8D7   DIO_u8PIN_7
#define LCD_u8RS   DIO_u8PIN_8    //portb pin rakm 0
#define LCD_u8EN   DIO_u8PIN_9   //portb bin rakm 1

/**********************lcd mode******************************/

#define Lcd_u8FourBit  0
#define Lcd_u8EightBit 1

#define Lcd_u8Mode Lcd_u8FourBit
/*************************************************************/

#endif /* LCD_CFG_H_ */
