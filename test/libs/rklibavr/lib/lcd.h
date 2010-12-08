/*! \file lcd.h \brief Obs�uga znakowego wy�wietlacza LCD w trybie 4 bitowym. */
/*
  Copyright (c) 2004,5 Robert Krysztof
  robert.krysztof@wp.pl
  http://www.avr-gcc.prv.pl
*/
/** \defgroup lcd Wy�wietlacz LCD
 
 Obs�uga znakowego wy�wietlacza LCD w trybie 4 bitowym.
 
 \code
 #include "lcd.h"
 \endcode 
 
 Jako jedno ze standardowych urz�dze� wyj�ciowych 
 w systemach mikroprocesorowych jest stosowany 
 znakowy wy�wietlacz LCD. Z uwagi na szerokie 
 zastosowanie w rozmaitych projektach, procedury 
 jego obs�ugi powinny si� cechowa� �atwo�ci� stosowania
 (zar�wno w programach jak i w sprz�cie) oraz uniwersalno�ci�.
 Wy�wietlacz jest obs�ugiwany w trybie 4 bitowym. 
 Nale�y go pod��czy� do dowolnego portu mikrokontrolera
 z tym, �e linie kontrolne RS i EN musz� by� pod��czone
 do bit�w znajduj�cych si� w jednej "po��wce" bajtu 
 np. je�eli RS pod��czymy do linii nr 2 to EN mo�emy 
 pod��czy� do jednej linii: 0, 1 lub 3. 
 Nie jest mo�liwe pod��czenie jej do linii 4, 5, 6 lub 7 
 gdy� jest ona automatycznie przydzielana do pod��czenia 
 czterech bit�w danych wy�wietlacza. 
 Analogiczna zasada dotyczy wykorzystania g�rnej "po��wki" 
 portu do pod��czenia linii kontrolnych EN i RS -
 wtedy bity 0-3 portu s� wykorzystane do pod��czenia 
 linii danych wy�wietlacza. 
 
 \ref config:
 
 W pliku \c "config.h" znajduj�cym si� w katalogu projektu nale�y umie�ci� nast�puj�c� zawarto��:
 
 \code
#define LCD_PORT	PORTA	// port wy�wietlacza
#define LCD_RS 		5	// bit linii RS
#define LCD_EN 		4	// bit linii EN
#define LCD_X		16	// liczba znak�w w linii wy�wietlacza
#define LCD_Y		2	// liczba wierszy wy�wietlacza
// opcjonalne ustawienia - powoduj� zwi�kszenie d�ugo�ci kodu
// je�li nie s� wymagane nale�y je "zakomentowa�":
#define LCD_BIT_SWAP		// zamiana bit�w danych LCD D3<>D0, D2<>D1
#define LCD_WRAP		// "zawijanie" tekstu na wy�wietlaczu
#define LCD_WIN1250		// polskie znaki wg WIN1250
 \endcode
 
 \note Warto�ci z \c #define mo�na zmienia� w celu dostosowania 
 biblioteki do tworzonego urz�dzenia i oprogramowania.
 
 \par Wykorzytywane biblioteki:
 
 \ref delay
 
 \par Przyk�ad:
 
 Wykorzystanie definicji polskich znak�w diakrytycznych:
 
 \code
 LCD_PL_chars_init();	// inicjalizacja polskich znak�w
 LCD_putstr_P(PSTR("Tak mo"_z"na pisa"_c" bez WIN1250"));
 \endcode
 
 Rysowanie paska post�pu:
 
 \code
 LCD_progressbar_init(); // inicjalizacja generatora znak�w
 LCD_progressbar(1,67);	 // pasek post�pu w wierszu 1
 
 \endcode
*/

#ifndef __LCD_H__
#define __LCD_H__

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "config.h"
#include "global.h"
#include "delay.h"
#include "conv.h"

/*@{*/

#if ((LCD_EN>3)&(LCD_RS<=3))|((LCD_EN<=3)&(LCD_RS>3))
  #error "Bity LCD_EN i LCD_RS musza znajdowac sie w jednej polowce bajtu!!!"
#endif

#if (LCD_EN>3)&(LCD_RS>3)
  #define LCD_HALF_LO
#else
  #undef LCD_HALF_LO
#endif

#define LCD_PORT_O		LCD_PORT      
#define LCD_PORT_D		DDR(LCD_PORT)
#define LCD_PORT_I		PIN(LCD_PORT)

/**
 Wy��cza kursor
*/
#define LCD_cursor_off()	LCD_send(0x0C, 0)

/**
 W��cza kursor
*/
#define LCD_cursor_on()		LCD_send(0x0F, 0)

/**
 Przesuwa kursor w prawo
*/
#define LCD_cursor_right()	LCD_send(0x14, 0)

/**
 Przesuwa kursor w lewo
*/
#define LCD_cursor_left()	LCD_send(0x10, 0)

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define _a		"\008"

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define _c		"\001"

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define _e		"\002"

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define _l		"\003"

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define _n		"\004" 

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define _o		"\005" 

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define _s		"\006" 

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define _z		"\007"

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define LCD_a		0x08 

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define LCD_c		0x09

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define LCD_e		0x0a

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define LCD_l		0x0b

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define LCD_n		0x0c

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define LCD_o		0x0d

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define LCD_s		0x0e

/**
 Definicja polskiego znak�w diakrytycznego '�' na LCD
*/
#define LCD_z		0x0f

/**
 Kod polskiego znaku diakrytycznego '�' w std. WIN1250 
*/
#define WIN1250_a	0xb9

/**
 Kod polskiego znaku diakrytycznego '�' w std. WIN1250 
*/
#define WIN1250_c	0xe6 

/**
 Kod polskiego znaku diakrytycznego '�' w std. WIN1250 
*/
#define WIN1250_e	0xea 

/**
 Kod polskiego znaku diakrytycznego '�' w std. WIN1250 
*/
#define WIN1250_l	0xb3 

/**
 Kod polskiego znaku diakrytycznego '�' w std. WIN1250 
*/
#define WIN1250_n	0xf1 

/**
 Kod polskiego znaku diakrytycznego '�' w std. WIN1250 
*/
#define WIN1250_o	0xf3 

/**
 Kod polskiego znaku diakrytycznego '�' w std. WIN1250 
*/
#define WIN1250_s	0x9c 

/**
 Kod polskiego znaku diakrytycznego '�' w std. WIN1250 
*/
#define WIN1250_z	0xbf

/**
 Pozycja kursora na LCD 0...79
*/
extern volatile uint8_t LCD_pos;

/**
 Wystawienie danych 4 bitowych na szyn� i ich "zatrza�ni�cie"
*/
void LCD_clock(uint8_t data, uint8_t rs);

/**
 Inicjuje wy�wietlacz zgodnie z ustawieniami w pliku "config.h", w��cza interfejs 4-bitowy.
*/
void LCD_init(void);

/**
 Wykonuje kasowanie ekranu wy�wietlacza LCD. Umieszcza kursor na pozycji 0,0.
*/
void LCD_clear(void);

/**
 Wystawienie danych 8 bitowych jako 4 bit na szyn� i ich "zatrza�ni�cie".
 W programach u�ytkownika nie nale�y jej wywo�ywa� bez specjalnej potrzeby.
 \param data dane do wys�ania
 \param rs stan linii RS wy�wietlacza
 */
void LCD_send(uint8_t data, uint8_t rs);

/**
 Wystawienie danych 8 bitowych jako 4 bit na szyn�
 z lini� RS=0 i ich "zatrza�ni�cie"
 W programach u�ytkownika nie nale�y jej wywo�ywa� bez specjalnej potrzeby.
 \param data dane do wys�ania
*/
void LCD_send_0(uint8_t data);

/**
 Wystawienie danych 8 bitowych jako 4 bit na szyn�
 z lini� RS=1 i ich "zatrza�ni�cie"
 W programach u�ytkownika nie nale�y jej wywo�ywa� bez specjalnej potrzeby.
 \param data dane do wys�ania
*/
void LCD_send_1(uint8_t data);

/**
 Ustawienie pozycji kursora wy�wietlacza.
 */
void LCD_xy(uint8_t x, uint8_t y);

/**
 Wy�wietla znak na aktualnej pozycji kursora 
 i przesuwa kursor na nast�pn� pozycj�.
 \param ch znak do wy�wietlenia
 */
int LCD_putchar(char ch);

/**
 * Wy�wietlenie znaku ch na wsp�rz�dnych x,y
 \param x wsp�rz�dna pozioma
 \param y wsp�rz�dna pionowa
 \param ch znak do wy�wietlenia
 */
void LCD_putcharxy(uint8_t x, uint8_t y, char ch);

/**
 Wy�wietla na aktualnej pozycji kursora �a�cuch znajduj�cy
 si� w pami�ci SRAM i przesuwa kursor na nast�pn� pozycj�.
 \param s �a�cuch znak�w do wy�wietlenia
 */
void LCD_putstr(uint8_t* s);

/**
 Wy�wietla znakow� reprezentacj� liczby o wybranej postawie.
 \note korzysta z funkcji \b itoa() co oznacza do�� du�e zapotrzebowanie na pami�� programu,
 je�li nie ma specjalnej potrzeby aby j� zastosowa� lepiej skorzysta� z funkcji:
 LCD_putuint8_t(), LCD_puthexuint8_t(), LCD_puthexU16().
 \param value warto�� do wy�wietlenia
 \param radix podstawa np 2, 8, 10, 16
 */
void LCD_putint(int value, uint8_t radix);

/** 
 Wy�wietla dziesi�tn� reprezentacj� liczby 8 bitowej
 \param value warto�� do wy�wietlenia
*/
void LCD_putuint8_t(uint8_t value);

/** 
 Wy�wietla szesnastkow� reprezentacj� liczby 8 bitowej
 \param value warto�� do wy�wietlenia
*/
void LCD_puthexuint8_t(uint8_t value);

/** 
 Wy�wietla szesnastkow� reprezentacj� liczby 16 bitowej
 \param value warto�� do wy�wietlenia
*/
void LCD_puthexU16(u16 value);

/**
 �aduje definicje znak�w u�ytkownika do LCD
 z 64 elementowej tablicy umieszczonej w pami�ci programu.
 \param s tablica umieszczona w pami�ci programu
 */
void LCD_defchars_P(const char *s);

/**
 Wy�wietla na aktualnej pozycji kursora �a�cuch znajduj�cy
 si� w pami�ci programu (FLASH) i przesuwa kursor na nast�pn� pozycj�.
 \param s �a�cuch umieszczony w pami�ci programu
*/
void LCD_putstr_P(const char *s);

/**
 Wy�wietla na aktualnej pozycji kursora �a�cuch znajduj�cy
 si� w pami�ci EEPROM i przesuwa kursor na nast�pn� pozycj�.
 \param s �a�cuch umieszczony w pami�ci EEPROM
*/
void LCD_putstr_E(uint8_t *s);

/**
 Wy�wietla na wsp�rz�dnych x, y �a�cuch znajduj�cy si� 
 w pami�ci SRAM i przesuwa kursor na nast�pne pozycje. 
 \param x wsp�rz�dna pozioma
 \param y wsp�rz�dna pionowa
 \param s �a�cuch znak�w
 */
void LCD_putstrxy(uint8_t x, uint8_t y, char *s);

/**
 �aduje do pami�ci RAM generatora znak�w w LCD 
 definicje polskich znak�w diakrytycznych (kody 0-7: ���󜿟).
*/
void LCD_PL_chars_init(void);

/**
 �aduje do pami�ci RAM generatora znak�w w LCD definicje 
 znak�w s�u��cych do wy�wietlania paska post�pu (kody 0-7).
 \warning inne wcze�niej zdefniowane znaki np. polskie zostan� nadpisane
*/
void LCD_progressbar_init(void);

/**
 Wy�wietla poziomy pasek post�pu w wybranym wierszu wy�wietlacza.
 D�ugo�� paska okre�la zmienna value - 0: brak; 255: ca�y wiersz.
 \param y wiersz wy�wietlacza
 \param value d�ugo�� paska
*/
void LCD_progressbar(uint8_t y, uint8_t value);

/*@}*/

#endif
