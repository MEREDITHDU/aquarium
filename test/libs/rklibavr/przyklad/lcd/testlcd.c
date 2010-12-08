/* ------------------------------------------------------------------------- */
/*	Test wyœwietlacza LCD						     */
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
  LCD_progressbar_init();	// inicjalizacja generatora znaków
  for(i=0; i<255; i++)
  {
    LCD_progressbar(1,i);	// pasek postêpu w wierszu 1
    LCD_xy(12,0);		// ustaw kursor w wierszu 0 kol. 12
    LCD_putint(i,10);		// wyœwietl tam wartoœæ
    LCD_putchar(')');		// zakoñcz nawias
    delayms(20);		// czekaj 20ms
  }
}
 
void chartable(void)
{
  u08 x,y,z;
  u08 ch=0;			
  LCD_PL_chars_init();		// inicjalizacja polskich znaków
  for(z=0;z<(256/(LCD_X*LCD_Y));z++)	// oblicz iloœæ "ekranów"
  {				// i wszystkie wyœwietl
    for(y=0;y<LCD_Y;y++)	// we wszystkich wierszach
    {
      LCD_xy(0,y);		// ustaw kursor na pocz¹tek wiersza
      for(x=0;x<LCD_X;x++)	// i w ka¿dej kolumnie
        LCD_putchar(ch++);	// wyœwietl inny znak
    }
    delayms(500);		// przez chwilê wyœwietlaj "ekran"
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
  LCD_init();			// inicjalizacja wyœwietlacza

  while(1)			// pêtla nieskoñczona
  {
    LCD_PL_chars_init();	// inicjalizacja polskich znaków

    LCD_putstr_P(PSTR(" Testowanie LCD"));
    LCD_xy(6,1);
    LCD_putstr_P(PSTR("DEMO"));
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("Zawijanie tekstu na wyœwietlaczu"));
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("Piszemy w jêzyku polskim :-)"));
    delayms(500);
    LCD_clear();
    LCD_putstr_P(PSTR("Poœwiêciæ ¿abie ¿ó³t¹ bañkê! ;-)"));
    delayms(3000);
    LCD_clear();
    LCD_putstr_P(PSTR("Tak mo"_z"na pisa"_c" bez WIN1250"));
    delayms1000();

    LCD_clear();
    LCD_putstr_P(PSTR("Tablica znaków"));
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
