#include "../lcd.h"
#include <stdlib.h>

void LCD_putint(int value, u08 radix)	// wysy�a na port szeregowy tekst 
					// przedstawiaj�cy value z podstaw� radix
{
  char string[18];			// bufor na wynik funkcji itoa
  itoa(value, string, radix);		// konwersja value na warto�� dziesi�tn�
  LCD_putstr(string);			// wy�lij string na LCD
}

