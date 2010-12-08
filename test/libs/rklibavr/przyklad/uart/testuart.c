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
	// tablica zawiaraj¹ca znaki nowej linii
prog_char ANSI_CLEAR[] = {27,'[','H',27,'[','2','J',0};
	// j.w. ale czyszcz¹cza ekran terminala

char text_E[] __attribute__((section(".eeprom"))) = "Tekst z pamiêci EEPROM";

char text_P[] __attribute__((section(".progmem"))) = "Tekst z pamiêci FLASH";

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
  char s[UART_MAX_GETSTR+1];	// bufor na ³añcuch znaków
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
    PRINT("Dwójkowo: ");
    UART_putint(liczba,2);
    NEWLINE();
    PRINT("Ósemkowo: ");
    UART_putint(liczba,8);
    NEWLINE();
    PRINT("Dziesiêtnie: ");
    UART_putint(liczba,10);
    NEWLINE();
    PRINT("Szesnaskowo: ");
    UART_putint(liczba,16);
    NEWLINE();
/*
    NEWLINE();
    PRINT("Testowanie funkcji UART_getchar() i UART_putchar()");
    NEWLINE();
    PRINT("Wyœlij cokolwiek z terminala, znak \"t\" koñczy...");
    NEWLINE();
    do
    {
      c=UART_getchar();		// pobierz znak z wejscia
      UART_putchar(c);		// zrób echo
    }
    while (c != 't');		// a¿ nie napotkasz znaku "t"
    NEWLINE();
*/
    PRINT("Testowanie funkcji UART_getstr() i UART_putstr()");
    NEWLINE();
    PRINT("Wyœlij cokolwiek z terminala i naciœnij ENTER");
    NEWLINE();
    PRINT("...napis \"koniec\" koñczy...");
    NEWLINE();
    do
    {
      UART_getstr(s);		// pobierz tekst z wejscia
      UART_putstr(s);		// zrób echo
      NEWLINE();
    }
    while (strncmp_P(s,PSTR("koniec"),6)!=0);	// a¿ nie napotkasz "koniec"
  }
}

/*--------------------------------------------------------------------- */
/*			Koniec programu					*/
/*--------------------------------------------------------------------- */
