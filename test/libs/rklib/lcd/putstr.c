#include "../lcd.h"

void LCD_putstr(u08* s)
{
  register u08 c;
  while ((c = *s++))		// dop�ki nie napotkasz 0
    LCD_putchar(c);
}

