/*
 * lcd.c
 *
 *  Created on: Sep 19, 2026
 *      Author: HP
 */

#include "lcd.h"

void delay_ms(uint32_t ms){
	for(volatile uint32_t i=0; i<ms*4000; i++);
}

void lcd_send_nibble(uint8_t data) {
	i2c_write_byte(data & ~PIN_EN);
	delay_ms(2);
    i2c_write_byte(data | PIN_EN);
    delay_ms(1);
    i2c_write_byte(data & ~PIN_EN);
    delay_ms(2);
}

void lcd_send(uint8_t value, uint8_t mode) {
    uint8_t high = (value & 0xF0) | mode | LCD_BACKLIGHT;
    uint8_t low  = ((value << 4) & 0xF0) | mode | LCD_BACKLIGHT;
    lcd_send_nibble(high);
    lcd_send_nibble(low);
}

void lcd_command(uint8_t cmd) { lcd_send(cmd, 0); }
void lcd_data(uint8_t data)   { lcd_send(data, PIN_RS); }


void lcd_init(void) {
    delay_ms(100);
    lcd_send_nibble(0x30 | LCD_BACKLIGHT);
    delay_ms(5);
    lcd_send_nibble(0x30 | LCD_BACKLIGHT);
    delay_ms(1);
    lcd_send_nibble(0x30 | LCD_BACKLIGHT);
    delay_ms(1);
    lcd_send_nibble(0x20 | LCD_BACKLIGHT);
    delay_ms(10); // Force 4-bit interface mode

    lcd_command(0x28); // 2 lines, 5x8 matrix fonts
    lcd_command(0x0C); // Display ON, Cursor invisible
    lcd_command(0x06); // Move cursor right automatically
    lcd_command(0x01); // Wipe display memory clean
    delay_ms(5);
}

void lcd_set_cursor(uint8_t row, uint8_t col) {
    uint8_t address = (row == 0) ? (0x80 + col) : (0xC0 + col);
    lcd_command(address);
}

void lcd_print_string(char *str) {
    while (*str) {
        lcd_data((uint8_t)*str++);
    }
}
