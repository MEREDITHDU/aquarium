#include "../lcd.h"

void LCD_clear(void)
{
  LCD_send_0(0x01);	// wyczy�� LCD
  delayms(10);	// czekaj chwil�
  LCD_xy(0,0);		// ustaw kursor na pocz�tek
}

