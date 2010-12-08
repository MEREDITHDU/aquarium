#include "../lcd.h"

void LCD_progressbar(u08 y, u08 value)
{
  register u08 xx, yy, z;
  LCD_xy(0,y);				// ustaw kursor na pocz�tek wiersza
  value=(value*6)/LCD_X;		// rozpoczyna obliczanie
  xx = (value/6);			// ile mamy "pe�nych" znak�w 
  for(yy = 1; yy<=xx; yy++)
    LCD_putchar(255);			// wy�wietl "pe�ne" znaki
  z = value%6;				// oblicz kt�ry znak ma by� u�yty
  LCD_putchar(z);                       // i wy�wietl go 
  for(yy = yy; yy<LCD_X; yy++)
    LCD_putchar(' ');			// reszt� wyczy��
}
