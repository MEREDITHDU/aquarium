/* ------------------------------------------------------------------------- */
/*	Test wy�wietlacza LCD						     */
/* ------------------------------------------------------------------------- */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "lcd.h"

/* ------------------------------------------------------------------------- */
/*			   Definicje funkcji				     */
/* ------------------------------------------------------------------------- */

void progressbar(void)
{
  u08 i;
  LCD_progressbar_init();	// inicjalizacja generatora znak�w
  for(i=0; i<255; i++)
  {
    LCD_progressbar(1,i);	// pasek post�pu w wierszu 1
    LCD_xy(12,0);		// ustaw kursor w wierszu 0 kol. 12
    LCD_putint(i,10);		// wy�wietl tam warto��
    LCD_putchar(')');		// zako�cz nawias
    delayms(20);		// czekaj 20ms
  }
}
 
void chartable(void)
{
  u08 x,y,z;
  u08 ch=0;			
  LCD_PL_chars_init();		// inicjalizacja polskich znak�w
  for(z=0;z<(256/(LCD_X*LCD_Y));z++)	// oblicz ilo�� "ekran�w"
  {				// i wszystkie wy�wietl
    for(y=0;y<LCD_Y;y++)	// we wszystkich wierszach
    {
      LCD_xy(0,y);		// ustaw kursor na pocz�tek wiersza
      for(x=0;x<LCD_X;x++)	// i w ka�dej kolumnie
        LCD_putchar(ch++);	// wy�wietl inny znak
    }
    delayms(500);		// przez chwil� wy�wietlaj "ekran"
  }
}

void delayms1000(void)
{
  delayms(1000);
}

/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{                
  sbi(DDRB,1);
  cbi(PORTB,1);
  delayms(100);
  LCD_init();			// inicjalizacja wy�wietlacza

  while(1)			// p�tla niesko�czona
  {
    LCD_PL_chars_init();	// inicjalizacja polskich znak�w

    LCD_putstr_P(PSTR(" Testowanie LCD"));
    LCD_xy(6,1);
    LCD_putstr_P(PSTR("DEMO"));
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("Zawijanie tekstu na wy�wietlaczu"));
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("Piszemy w j�zyku polskim :-)"));
    delayms(500);
    LCD_clear();
    LCD_putstr_P(PSTR("Po�wi�ci� �abie ��t� ba�k�! ;-)"));
    delayms(3000);
    LCD_clear();
    LCD_putstr_P(PSTR("Tak mo"_z"na pisa"_c" bez WIN1250"));
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("Tablica znak�w"));
    delayms(500);
    chartable();

    LCD_clear();
    LCD_putstr_P(PSTR("progressbar("));
    progressbar();
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("_cursor_on()"));
    LCD_cursor_on();
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("_right_left_"));
    delayms(200);
    LCD_cursor_right();
    delayms(200);
    LCD_cursor_right();
    delayms(200);
    LCD_cursor_left();
    delayms(200);
    LCD_cursor_left();
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("_cursor_off()"));
    LCD_cursor_off();
    delayms1000();

    LCD_clear();
  }
}

/* ------------------------------------------------------------------------- */
/*		Koniec programu Test LCD na AVR               		     */
/* ------------------------------------------------------------------------- */
