#include <avr/io.h>
#include "uart.h"
#include "rtc.h"

/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{
  uint8_t last_second=0;   // przechowuje ostatnio wy�wietlon� sekund�

  RTC_time.year=2004;          // zainicjuj rok
  RTC_time.month=4;            // zainicjuj miesi�c
  RTC_time.day=8;             // zainicjuj dzie�
  RTC_time.hour=12;            // zainicjuj godzin�
  UART_init();
  RTC_init();

  sei();                // w��cz obs�ug� przerwa�

  while(1)              // p�tla niesko�czona
  {
    if ((last_second)!=(RTC_time.second))      // je�li zmieni�a si� sekunda
    {
      last_second=RTC_time.second;     // zapami�taj obecn� sekund�
      UART_putint(RTC_time.year,10);	// wy�wietl rok
      UART_putchar('-');
      UART_putint(RTC_time.month,10);	// wy�wietl miesi�c
      UART_putchar('-');
      UART_putint(RTC_time.day,10);	// wy�wietl dzien
      UART_putchar(' ');
      UART_putint(RTC_time.hour,10);	// wy�wietl godzin�
      UART_putchar(':');
      UART_putint(RTC_time.minute,10);	// wy�wietl minut�
      UART_putchar(':');
      UART_putint(RTC_time.second,10);	// sekund�
      UART_putchar('\r');
    }
  }
}

/* ------------------------------------------------------------------------- */
/*				Koniec programu                		     */
/* ------------------------------------------------------------------------- */


