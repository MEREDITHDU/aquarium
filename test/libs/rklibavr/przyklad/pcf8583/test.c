#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdlib.h> 

#include "uart.h"
#include "pcf8583.h"

/* ------------------------------------------------------------------------- */
/*			Deklaracje tablic i zmiennych			     */
/* ------------------------------------------------------------------------- */

u08 ssek,sek,min,godz,dzien,mies;   /* aktualny czas                       */
u16 rok;

/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{
  char s[UART_MAX_GETSTR];
  char c;
  UART_init();
  PCF8583_init();
  while(1)
  {
    c=UART_getchar();
    switch (c)
    {
      case '?':
        {
	  UART_putstr_P(PSTR("\rMenu:"));
	  UART_putstr_P(PSTR("\r1 - czytaj czas"));
	  UART_putstr_P(PSTR("\r2 - ustaw czas"));
	  UART_putstr_P(PSTR("\r3 - czytaj date"));
	  UART_putstr_P(PSTR("\r4 - ustaw date\r"));
        }; break;
      case '1':
        {
          PCF8583_get_time(&godz,&min,&sek,&ssek);
	  UART_putstr_P(PSTR("\rCzas: "));
	  UART_putint(godz,10);
	  UART_putstr_P(PSTR(":"));
	  UART_putint(min,10);
	  UART_putstr_P(PSTR(":"));
	  UART_putint(sek,10);
	  UART_putstr_P(PSTR(":"));
	  UART_putint(ssek,10);
        }; break;
      case '2':
        {
          UART_putstr_P(PSTR("\rUstawianie czasu"));
          UART_putstr_P(PSTR("\rpodaj godzine"));
	  UART_getstr(s);
          godz=strtol(s,0,10);
          UART_putstr_P(PSTR("\rpodaj minute"));
	  UART_getstr(s);
          min=strtol(s,0,10);
          UART_putstr_P(PSTR("\rpodaj sekunde"));
	  UART_getstr(s);
          sek=strtol(s,0,10);
	  ssek=0;
          PCF8583_set_time(godz,min,sek,0);
        }; break;
      case '3':
        {
          PCF8583_get_date(&dzien,&mies,&rok);
	  UART_putstr_P(PSTR("\rData: "));
	  UART_putint(rok,10);
	  UART_putstr_P(PSTR("-"));
	  UART_putint(mies,10);
	  UART_putstr_P(PSTR("-"));
	  UART_putint(dzien,10);
        }; break;
      case '4':
        {
          UART_putstr_P(PSTR("\rUstawianie daty"));
          UART_putstr_P(PSTR("\rpodaj dzien"));
	  UART_getstr(s);
          dzien=strtol(s,0,10);
          UART_putstr_P(PSTR("\rpodaj miesiac"));
	  UART_getstr(s);
          mies=strtol(s,0,10);
          UART_putstr_P(PSTR("\rpodaj rok"));
	  UART_getstr(s);
          rok=strtol(s,0,10);
          PCF8583_set_date(dzien,mies,rok);
        }; break;
    }
    UART_putstr_P(PSTR("\r? - pomoc..."));
  }
}

/* ------------------------------------------------------------------------- */
/*		Koniec programu zegar AVR                 		     */
/* ------------------------------------------------------------------------- */

