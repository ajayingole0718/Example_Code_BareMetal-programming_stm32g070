/*
 * lcd.h
 *
 *  Created on: Sep 19, 2026
 *      Author: HP
 */

#ifndef LCD_H_
#define LCD_H_
#include "i2c.h"

#define PIN_RS        (1U << 0)
#define PIN_EN        (1U << 2)
#define LCD_BACKLIGHT (1U << 3)

void delay_ms(uint32_t ms);
void lcd_send_nibble(uint8_t data);
void lcd_send(uint8_t value, uint8_t mode);
void lcd_command(uint8_t cmd);
void lcd_data(uint8_t data);
void lcd_init(void);
void lcd_set_cursor(uint8_t row, uint8_t col);
void lcd_print_string(char *str);
#endif /* LCD_H_ */
