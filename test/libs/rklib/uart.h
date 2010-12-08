/** \file uart.h \brief Sterownik interfejsu UART. */
/*
  Copyright (c) 2004 Robert Krysztof
  robert.krysztof@wp.pl
  http://www.avr-gcc.prv.pl
*/
/** \defgroup uart Port szeregowy
 
 Obs�uga portu szeregowego UART0.
 
 \code
 #include "uart.h"
 \endcode 
 
 \ref config:
 
 W pliku \c "config.h" znajduj�cym si� w katalogu projektu nale�y umie�ci� nast�puj�c� zawarto��:
    	     
\code
#define UART_BAUD	19200		// pr�dko�� transmisji w bit/s
#define UART_MAX_GETSTR	8		// maksymalna d�ugo�� tekstu dla UART_getstr()
#define UART_BUF_SIZE	8		// wielko�� bufor�w UART (musi by� pot�g� 2)
#define UART_DE_PORT	PORTD		// port linii DE konwertera RS485
#define UART_DE_BIT	7		// bit portu linii DE konwertera RS485
 \endcode
 
 \note Warto�ci z \c #define mo�na zmienia� w celu dostosowania 
 biblioteki do tworzonego urz�dzenia i oprogramowania.
 
 \note \c UART_BUF_SIZE automatycznie w��cza obs�ug� UART na przerwaniach 
 (je�li nie chcemy u�ywa� przerwa� to mo�na po prostu nie definiowa� \c UART_BUF_SIZE)
 
 \note \c UART_DE_PORT i \c UART_DE_BIT s� opcjonalne - mog� si� przyda� 
 w przypadku realizacji komunikacji na dwuprzewodowym interfejsie 
 RS485 i s�u�� do prze��czania kierunku transmisji.

 \par Wykorzystywane przerwania (tylko gdy zdefiniowano UART_BUF_SIZE):
 
 \c SIG_UART_RECV, \c SIG_UART_DATA, \c SIG_UART_TRANS (gdy zdefiniowano \c UART_DE_PORT)

\par Przyk�adowy program

\p "config.h"
\include uart/config.h

\p program g��wny:
\include uart/testuart.c
*/

#ifndef __UART_H__
#define __UART_H__

/*@{*/

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>		// obs�uga uk�adu Watchdog
#include "config.h"
#include "global.h"
#include "conv.h"

#ifdef UART_BUF_SIZE	// je�eli UART ma pracowa� na przerwaniach

#define UART_TMASK		(UART_BUF_SIZE-1)
#define UART_RMASK		(UART_BUF_SIZE-1)

#include <avr/signal.h>		// konieczne dla przerwa�
#include <avr/interrupt.h>	// konieczne dla przerwa�

extern volatile uint8_t UART_tbuf[UART_BUF_SIZE];  // TX buffer
extern volatile uint8_t UART_rbuf[UART_BUF_SIZE];  // RX buffer

extern volatile uint8_t UART_t_in;            // TX buffer in index
extern volatile uint8_t UART_t_out;           // TX buffer out index

extern volatile uint8_t UART_r_in;            // RX buffer in index
extern volatile uint8_t UART_r_out;           // RX buffer out index

/** 
 Istnieje gdy zdefiniowano \c UART_BUF_SIZE
 \return ilo�� znak�w w buforze odbiorczym.
*/
char UART_rxlen(void); 

#else        // je�li UART pracuje bez u�ycia przerwa�

/** 
 Istnieje gdy nie zdefiniowano \c UART_BUF_SIZE
 \return 0 gdy nie ma znaku w buforze odbiorczym.
*/
#define UART_rxlen()	bit_is_set(_USR_,RXC)

#endif  //UART_BUF_SIZE


// ---------------------------------------------------------------

/** 
 Inicjalizacja UART
*/
void UART_init(void);

/** 
 Wysy�a znak na UART
 \param c znak (bajt) do wys�ania
*/
int UART_putchar (char c);

/**
 Czeka i odbiera znak z UART
 \return odebrany znak z UART
*/
int UART_getchar (void);

/**
 Wysy�a �a�cuch z SRAM na UART
 \param s �a�cuch znak�w w pami�ci SRAM
*/
void UART_putstr (char *s);

/**
 Wysy�a �a�cuch s z FLASH na UART
 \param s �a�cuch znak�w w pami�ci FLASH 
*/
void UART_putstr_P (const char *s);

/** 
 Wysy�a �a�cuch s z EEPROM na UART
 \param s �a�cuch znak�w w pami�ci EEPROM
*/
void UART_putstr_E(u08 *s);

/** 
 Pobiera �a�cuch z UART.
 �a�cuch musi by� zako�czony znakiem "\n" lub "\r"
 i jego d�ugo�� nie mo�e przekroczy� warto�ci
 zdefiniowanej w UART_MAX_GETSTR.
 \param s wska�nik do tablicy gdzie ma by� odebrany �a�cuch
*/
void UART_getstr (char *s);

/** 
 Wysy�a na port szeregowy znakow� reprezentacj� liczby o wybranej postawie
 \note korzysta z funkcji \b itoa() co oznacza do�� du�e zapotrzebowanie na pami�� programu,
 je�li nie ma specjalnej potrzeby aby j� zastosowa� lepiej skorzysta� z funkcji:
 UART_putU08(), UART_puthexU08(), UART_puthexU16().
 \param value warto�� do wys�ania
 \param radix podstawa np 2, 8, 10, 16
*/
void UART_putint(int value, u08 radix);

/** 
 Wysy�a na port szeregowy dziesi�tn� reprezentacj� liczby 8 bitowej
 \param value warto�� do wys�ania
*/
void UART_putU08(u08 value);

/** 
 Wysy�a na port szeregowy szesnastkow� reprezentacj� liczby 8 bitowej
 \param value warto�� do wys�ania
*/
void UART_puthexU08(u08 value);

/** 
 Wysy�a na port szeregowy szesnastkow� reprezentacj� liczby 16 bitowej
 \param value warto�� do wys�ania
*/
void UART_puthexU16(u16 value);

/*@}*/

#endif //__UART_H__
