#ifndef LCD_H
#define LCD_H

#include <avr/io.h>

#include "config.h" 
#include <util/delay.h>


#define LCD   LCD_PORT

#define CLR_E LCD &= ~_BV(LCD_E)
#define SET_E LCD |=  _BV(LCD_E)

#define CLR_RS LCD &= ~_BV(LCD_RS)
#define SET_RS LCD |=  _BV(LCD_RS)

#define LINE1 128
#define LINE2 192
#define LINE3 148
#define LINE4 212

#define LCD_CLEAR 0x01

void write_to_lcd(char x);
void write_command(char x);
void write_char(char x);
void write_text(char * s);

void lcd_write(int device, char * s);
void lcd_init(void);

void lcd_backlight_on(); 
void lcd_backlight_fadeon(); 
void lcd_backlight_off(); 
void lcd_backlight_fadeoff(); 


#endif
