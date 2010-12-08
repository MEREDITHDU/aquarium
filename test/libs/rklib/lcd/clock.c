#include "../lcd.h"

void LCD_clock(u08 data, u08 rs)
{
#ifdef LCD_HALF_LO
  LCD_PORT_D|=0x0F|_BV(LCD_EN)|_BV(LCD_RS); // inicjalizacja portu wy�wietlacza
#else
  LCD_PORT_D|=0xF0|_BV(LCD_EN)|_BV(LCD_RS); // inicjalizacja portu wy�wietlacza
#endif // LCD_HALF_LO
  if (rs==1)				// linia RS wy�wietlacza
    sbi(LCD_PORT_O,LCD_RS);		// ustaw lini� RS wy�wietlacza

#ifdef LCD_BIT_SWAP			// zamiana bit�w 3<->0 i 2<->1
  u08 data_out=0;
  data_out|=(data & _BV(3)) >> 3;	// 3 -> 0
  data_out|=(data & _BV(2)) >> 1;	// 2 -> 1
  data_out|=(data & _BV(1)) << 1;	// 1 -> 2
  data_out|=(data & _BV(0)) << 3;	// 0 -> 3
  // takie rozwi�zanie generuje szybszy i mniejszy kod od p�tli !!!
#endif // LCD_BIT_SWAP

#ifdef LCD_HALF_LO
# ifdef LCD_BIT_SWAP			// zamiana bit�w 3<->0 i 2<->1
  LCD_PORT_O=(data_out)      | (LCD_PORT_O & 0xF0);	// przygotowanie danych
# else
  LCD_PORT_O=(data)      | (LCD_PORT_O & 0xF0);	// przygotowanie danych
# endif // LCD_BIT_SWAP
#else
# ifdef LCD_BIT_SWAP			// zamiana bit�w 3<->0 i 2<->1
  LCD_PORT_O=(data_out << 4) | (LCD_PORT_O & 0x0F);	// przygotowanie danych
# else
  LCD_PORT_O=(data << 4) | (LCD_PORT_O & 0x0F);	// przygotowanie danych
# endif // LCD_BIT_SWAP
#endif // LCD_HALF_LO
						// i wys�anie danych na szyn�
  sbi(LCD_PORT_O,LCD_EN);	// ustaw lini� EN wy�wietlacza
  delay20us();		// czekaj chwil�
  cbi(LCD_PORT_O,LCD_EN);	// skasuj lini� EN wy�wietlacza
  delay20us();		// czekaj chwil�
  cbi(LCD_PORT_O,LCD_RS);	// skasuj lini� RS wy�wietlacza
}
