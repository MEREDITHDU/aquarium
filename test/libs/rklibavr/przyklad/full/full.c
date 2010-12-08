/*--------------------------------------------------------------------- */
/*	Test klawiatury matrycowej, wy�wietlaczy LCD i LED,		*/
/*	magistrali I2C i zegara PCF8583. Symulacja prostego terminala.	*/
/*	Autor: Robert Krysztof						*/
/* 	WWW:	http://www.8051.prv.pl 					*/
/*	E-mail: robert.krysztof@wp.pl					*/
/* -------------------------------------------------------------------- */

/* -------------------------------------------------------------------- */
/* Uk�ad klawiatury:							*/
/* [ 7 ] [ 8 ] [ 9 ] [ESC]						*/
/* [ 4 ] [ 5 ] [ 6 ] [ENT]						*/
/* [ 1 ] [ 2 ] [ 3 ] [ ^ ]						*/
/* [ < ] [ 0 ] [ > ] [ v ]						*/
/* -------------------------------------------------------------------- */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "kbd.h"		// obs�uga klawiatury
#include "lcd.h"		// obs�uga wy�wietlacza LCD
#include "led7seg.h"		// obs�uga wy�wietlacza LED
#include "uart.h"		// obs�uga portu szeregowego
#include "pcf8583.h"		// obs�uga zegara I2C PCF8583

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
// makro zwracaj�ce kod ASCII wci�ni�tego klawisza

prog_char KBD_conv[] = {'7','4','1','D','8','5','2','0','9','6','3','C',ESC,ENT,'A','B'}; 
// tablica przekodowuj�ca kod klawisza na kod ASCII

prog_char CURSOR[] = {ESC,'[',0};
// pocz�tkowe kody ANSI do sterownia kursorem terminala

/* -------------------------------------------------------------------- */
/* -------------		Program glowny		--------------- */
/* -------------------------------------------------------------------- */

int main(void)
{             
  char c;			// odebrany znak
  UART_init();			// inicjalizacja portu szeregowego
  LCD_init();			// inicjalizacja wy�wietlacza LCD
  LCD_PL_chars_init();		// polskie znaki na wy�wietlaczu LCD
  KBD_init();			// inicjalizacja klawiatury
  LED7SEG_init();		// inicjalizacja wy�wietlacza
  sei();                       	// w��cz obs�ug� przerwa�

  while(1)			// p�tla niesko�czona
  {
    PCF8583_get_time(&godz,&min,&sek,&ssek);

    LED7SEG_putU08(sek);	// wy�wietlaj warto�� 

    if (UART_rxlen()>0)	// je�li odebrano znak
    {
      c=UART_getchar();
    	// tu mo�na wstawi� reakcje na komendy steruj�ce np. typu ESC[
      LCD_putchar(c);		// wy�wietl go na LCD
    }
    if (KBD_read())		// je�li naci�ni�to klawisz
    {
      if ((KBD_ascii>='A')&&(KBD_ascii<='D'))
        UART_putstr_P(CURSOR);	// sterowanie kursorem
      UART_putchar(KBD_ascii);	// wy�lij go na port szeregowy
      KBD_wait();		// czekaj na zwolnienie klawisza
    }
  }
}

/* -------------------------------------------------------------------- */
/*				Koniec programu				*/
/* -------------------------------------------------------------------- */
