/*--------------------------------------------------------------------- */
/*	Demo biblioteki UART						*/
/*	Autor: Robert Krysztof						*/
/* 	WWW:	http://www.8051.prv.pl 					*/
/*	E-mail: robert.krysztof@wp.pl					*/
/*--------------------------------------------------------------------- */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include "uart.h"

/*--------------------------------------------------------------------- */
/*			Deklaracje tablic i zmiennych			*/
/*--------------------------------------------------------------------- */

prog_char ANSI_NEWLINE[] = {'\n','\r',0}; 
	// tablica zawiaraj�ca znaki nowej linii
prog_char ANSI_CLEAR[] = {27,'[','H',27,'[','2','J',0};
	// j.w. ale czyszcz�cza ekran terminala

char text_E[] __attribute__((section(".eeprom"))) = "Tekst z pami�ci EEPROM";

char text_P[] __attribute__((section(".progmem"))) = "Tekst z pami�ci FLASH";

/*--------------------------------------------------------------------- */
/*		  Definicje stalych i makroinstrukcji			*/
/*--------------------------------------------------------------------- */

#define PRINT(p)	UART_putstr_P(PSTR(p))
#define CLEAR()		UART_putstr_P(ANSI_CLEAR)
#define NEWLINE()	UART_putstr_P(ANSI_NEWLINE)

/*--------------------------------------------------------------------- */
/* ----------------		Program glowny 	    ------------------- */
/*--------------------------------------------------------------------- */

int main(void)
{            
  char c;			// bufor na znak
  char s[UART_MAX_GETSTR+1];	// bufor na �a�cuch znak�w
  s16 liczba=0x5555;		// liczba do testowania
  UART_init();			// inicjalizacja portu szeregowego
            
  PRINT("Test biblioteki UART .....\n\r");
  while(1)
  { 
    CLEAR();
    PRINT("Testowanie funkcji UART_putstr_P() i UART_putstr_E()");
    NEWLINE();
    UART_putstr_P(text_P);
    NEWLINE();
    UART_putstr_E(text_E);
    NEWLINE();

    NEWLINE();
    PRINT("Testowanie funkcji UART_putint()");
    NEWLINE();
    PRINT("Dw�jkowo: ");
    UART_putint(liczba,2);
    NEWLINE();
    PRINT("�semkowo: ");
    UART_putint(liczba,8);
    NEWLINE();
    PRINT("Dziesi�tnie: ");
    UART_putint(liczba,10);
    NEWLINE();
    PRINT("Szesnaskowo: ");
    UART_putint(liczba,16);
    NEWLINE();
/*
    NEWLINE();
    PRINT("Testowanie funkcji UART_getchar() i UART_putchar()");
    NEWLINE();
    PRINT("Wy�lij cokolwiek z terminala, znak \"t\" ko�czy...");
    NEWLINE();
    do
    {
      c=UART_getchar();		// pobierz znak z wejscia
      UART_putchar(c);		// zr�b echo
    }
    while (c != 't');		// a� nie napotkasz znaku "t"
    NEWLINE();
*/
    PRINT("Testowanie funkcji UART_getstr() i UART_putstr()");
    NEWLINE();
    PRINT("Wy�lij cokolwiek z terminala i naci�nij ENTER");
    NEWLINE();
    PRINT("...napis \"koniec\" ko�czy...");
    NEWLINE();
    do
    {
      UART_getstr(s);		// pobierz tekst z wejscia
      UART_putstr(s);		// zr�b echo
      NEWLINE();
    }
    while (strncmp_P(s,PSTR("koniec"),6)!=0);	// a� nie napotkasz "koniec"
  }
}

/*--------------------------------------------------------------------- */
/*			Koniec programu					*/
/*--------------------------------------------------------------------- */
