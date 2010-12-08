/*--------------------------------------------------------------------- */
/*	Test klawiatury matrycowej, wyœwietlaczy LCD i LED,		*/
/*	magistrali I2C i zegara PCF8583. Symulacja prostego terminala.	*/
/*	Autor: Robert Krysztof						*/
/* 	WWW:	http://www.8051.prv.pl 					*/
/*	E-mail: robert.krysztof@wp.pl					*/
/* -------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* Uk³ad klawiatury:							*/
/* [ 7 ] [ 8 ] [ 9 ] [ESC]						*/
/* [ 4 ] [ 5 ] [ 6 ] [ENT]						*/
/* [ 1 ] [ 2 ] [ 3 ] [ ^ ]						*/
/* [ < ] [ 0 ] [ > ] [ v ]						*/
/* -------------------------------------------------------------------- */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "kbd.h"		// obs³uga klawiatury
#include "lcd.h"		// obs³uga wyœwietlacza LCD
#include "led7seg.h"		// obs³uga wyœwietlacza LED
#include "uart.h"		// obs³uga portu szeregowego
#include "pcf8583.h"		// obs³uga zegara I2C PCF8583

/* -------------------------------------------------------------------- */
/*			Deklaracje tablic i zmiennych			*/
/* -------------------------------------------------------------------- */

u08 ssek, sek,min,godz,dzien;   /* aktualny czas                       */

/* -------------------------------------------------------------------- */
/*		  Definicje stalych i makroinstrukcji			*/
/* -------------------------------------------------------------------- */

#define ENT	13
#define ESC	27

#define KBD_ascii	pgm_read_byte(&KBD_conv[KBD_key-1])
// makro zwracaj¹ce kod ASCII wciœniêtego klawisza

prog_char KBD_conv[] = {'7','4','1','D','8','5','2','0','9','6','3','C',ESC,ENT,'A','B'}; 
// tablica przekodowuj¹ca kod klawisza na kod ASCII

prog_char CURSOR[] = {ESC,'[',0};
// pocz¹tkowe kody ANSI do sterownia kursorem terminala

/* -------------------------------------------------------------------- */
/* -------------		Program glowny		--------------- */
/* -------------------------------------------------------------------- */

int main(void)
{             
  char c;			// odebrany znak
  UART_init();			// inicjalizacja portu szeregowego
  LCD_init();			// inicjalizacja wyœwietlacza LCD
  LCD_PL_chars_init();		// polskie znaki na wyœwietlaczu LCD
  KBD_init();			// inicjalizacja klawiatury
  LED7SEG_init();		// inicjalizacja wyœwietlacza
  sei();                       	// w³¹cz obs³ugê przerwañ

  while(1)			// pêtla nieskoñczona
  {
    PCF8583_get_time(&godz,&min,&sek,&ssek);

    LED7SEG_putU08(sek);	// wyœwietlaj wartoœæ 

    if (UART_rxlen()>0)	// jeli odebrano znak
    {
      c=UART_getchar();
    	// tu mo¿na wstawiæ reakcje na komendy steruj¹ce np. typu ESC[
      LCD_putchar(c);		// wyœwietl go na LCD
    }
    if (KBD_read())		// jeœli naciœniêto klawisz
    {
      if ((KBD_ascii>='A')&&(KBD_ascii<='D'))
        UART_putstr_P(CURSOR);	// sterowanie kursorem
      UART_putchar(KBD_ascii);	// wyœlij go na port szeregowy
      KBD_wait();		// czekaj na zwolnienie klawisza
    }
  }
}

/* -------------------------------------------------------------------- */
/*				Koniec programu				*/
/* -------------------------------------------------------------------- */
