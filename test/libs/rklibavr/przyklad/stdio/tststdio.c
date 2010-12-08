/* ------------------------------------------------------------------------- */
/*	Test biblioteki stdio						     */
/* ------------------------------------------------------------------------- */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include "uart.h"
#include "lcd.h"

/* ------------------------------------------------------------------------- */
/*			   Definicje funkcji				     */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{
  u16 liczba=0;
//  LCD_init();			// inicjalizacja wyswietlacza
  UART_init();			// inicjalizacja portu szeregowego

//  fdevopen(LCD_putchar, NULL, 0);
    fdevopen(UART_putchar, NULL, 0);

  while(1)			// p�tla niesko�czona
  {
    LCD_clear();
    liczba++;    
    printf_P(PSTR("Liczba %d"),liczba);
    delayms(100);
  }
}

/* ------------------------------------------------------------------------- */
/*                                Koniec programu                            */
/* ------------------------------------------------------------------------- */
