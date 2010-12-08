/* ------------------------------------------------------------------------- */
/*	Test wyœwietlacza LCD						     */
/* ------------------------------------------------------------------------- */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "lcd.h"

/* ------------------------------------------------------------------------- */
/*			   Definicje funkcji				     */
/* ------------------------------------------------------------------------- */

void delayms1(void)
{
  delayms(1);
}

/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{
  LCD_init();			// inicjalizacja wyœwietlacza

  while(1)			// pêtla nieskoñczona
  {
    LCD_putstr_P(PSTR(" Testowanie LCD"));
    LCD_xy(6,1);
    LCD_putstr_P(PSTR("DEMO"));
    LCD_xy(0,2);
    LCD_putstr_P(PSTR(" Testowanie LCD"));
    LCD_xy(6,3);
    LCD_putstr_P(PSTR("DEMO"));
    delayms1();

    LCD_clear();
    LCD_putstr_P(PSTR("Zawijanie tekstu na wyswietlaczu"));
    delayms1();

    LCD_clear();
    LCD_putstr_P(PSTR("_cursor_on()"));
    LCD_cursor_on();
    delayms1();

    LCD_clear();
    LCD_putstr_P(PSTR("_right_left_"));
    delayms1();
    LCD_cursor_right();
    delayms1();
    LCD_cursor_right();
    delayms1();
    LCD_cursor_left();
    delayms1();
    LCD_cursor_left();
    delayms1();

    LCD_clear();
    LCD_putstr_P(PSTR("_cursor_off()"));
    LCD_cursor_off();
    delayms1();

    LCD_clear();
  }
}

/* ------------------------------------------------------------------------- */
/*		Koniec programu Test LCD na AVR               		     */
/* ------------------------------------------------------------------------- */


