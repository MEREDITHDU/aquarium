#include "../lcd.h"

void LCD_send(u08 data, u08 rs)
{
  LCD_clock(data >> 4  , rs);	// bardziej znacz�ca cz��
  LCD_clock(data & 0x0F, rs);	// mniej znacz�ca cz��
}

