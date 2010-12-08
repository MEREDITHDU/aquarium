#ifndef LCD_H
#define LCD_H

#include <avr/io.h>

#include "config.h" 
#include <util/delay.h>


#define LCD  PORTC
#define LCD_E PC4
#define LCD_RS PC5

#define CLR_E LCD &= ~_BV(LCD_E) //(LCD & ~0x10)|(0x00 & 0x10)
#define SET_E LCD |= _BV(LCD_E) //(LCD & ~0x10)|(0xff & 0x10)

#define CLR_RS LCD &= ~_BV(LCD_RS)//(LCD & ~0x20)|(0x00 & 0x20)
#define SET_RS LCD |= _BV(LCD_RS)//(LCD & ~0x20)|(0xff & 0x20)

#define LINE1 128
#define LINE2 192
#define LINE3 148
#define LINE4 212

#define LCD_CLEAR 0x01

#define BACKLIGHT 1 // portb, bit 1

void write_to_lcd(char x);
void write_command(char x);
void write_char(char x);
void write_text(char * s);
void lcd_init(void);


#endif
