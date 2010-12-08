/*! \file pcf8583.h \brief Dost�p do zegara czasu rzeczywistego z magistral� I2C typu PCF8583. */
/*
  Copyright (c) 2004 Robert Krysztof
  robert.krysztof@wp.pl
  http://www.avr-gcc.prv.pl
*/
/** \defgroup pcf8583 Zegar I2C PCF8583
 
 Dost�p do zegara czasu rzeczywistego z magistral� I2C typu PCF8583.
 
 \code
 #include "pcf8583.h"
 \endcode 
 
 \ref config:
 
 W pliku \c "config.h" znajduj�cym si� w katalogu projektu nale�y umie�ci� nast�puj�c� zawarto��:
    	     
 \code
#define I2C_PORT	PORTD	//port do kt�rego s� pod��czone linie magistrali
#define I2C_SDA		5	//bit powy�szego portu u�ywany jako linia SDA
#define I2C_SCL 	6	//bit powy�szego portu u�ywany jako linia SCL
 \endcode
 
 \note Warto�ci z \c #define mo�na zmienia� w celu dostosowania 
 biblioteki do tworzonego urz�dzenia i oprogramowania.
 
 \par Wykorzytywane biblioteki:
 
 \ref i2c
*/

#ifndef __PCF8583_H__
#define __PCF8583_H__

#include "config.h"
#include "conv.h"
#include "i2c.h"

/*@{*/

#ifndef PCF8583_A0
/**
 Stan linii A0 uk�adu okre�laj�cy adres. Mo�na zmieni� w pliku \c "config.h"
*/
#define PCF8583_A0	0
#endif // PCF8583_A0

/**
 Bajt statusu uk�adu
*/
extern volatile u08 PCF8583_status;

/**
 Bajt alarmu uk�adu
*/
extern volatile u08 PCF8583_alarm;

/**
 Czyta bajt z uk�adu
 \param address adres kom�rki w uk�adzie
 \return odczytany bajt
*/
u08 PCF8583_read(u08 address);

/**
 Zapisuje bajt do uk�adu
 \param address adres kom�rki w uk�adzie 
 \param data bajt do wpisania
*/
void PCF8583_write(u08 address, u08 data);

/**
 Czyta bajt z uk�adu w formacie BCD
 \param address adres kom�rki w uk�adzie 
 \return odczytany bajt
*/
u08 PCF8583_read_bcd(u08 address);

/**
 Zapisuje bajt do uk�adu w formacie BCD
 \param address adres kom�rki w uk�adzie 
 \param data bajt do wpisania
*/
void PCF8583_write_bcd(u08 address,u08 data);

/**
 Czyta status uk�adu
 \return status uk�adu
*/
u08 PCF8583_get_status(void);

/**
 Inicjalizuje uk�ad
*/
void PCF8583_init(void);

/**
 Zatrzymuje uk�ad
*/
void PCF8583_stop(void);

/**
 Startuje uk�ad
*/
void PCF8583_start(void);

/**
 Odwiesza uk�ad
*/
void PCF8583_hold_off(void);

/**
 Zawiesza uk�ad
*/
void PCF8583_hold_on(void);

/**
 Wy��cza alarm
*/
void PCF8583_alarm_off(void);

/**
 Za��cza alarm
*/
void PCF8583_alarm_on(void);

/**
 Zapisuje s�owo do uk�adu
 \param address adres kom�rki w uk�adzie 
 \param data s�owo do wpisania
*/
void PCF8583_write_word(u08 address,u16 data);

/**
 Ustawia dat� w uk�adzie
 \param address adres kom�rki w uk�adzie
 \param day dzie�
 \param year rok
*/
void PCF8583_write_date(u08 address,u08 day,u16 year);

/**
 Czyta czas z uk�adu
 \param hour godzina
 \param min minuta
 \param sec sekunda
 \param hsec setne cz�ci sekundy
*/
void PCF8583_get_time(u08 *hour,u08 *min,u08 *sec,u08 *hsec);

/**
 Ustawia czas w uk�adzie
 \param hour godzina
 \param min minuta
 \param sec sekunda
 \param hsec setne cz�ci sekundy
*/
void PCF8583_set_time(u08 hour,u08 min,u08 sec,u08 hsec);

/**
 Czyta dat� z uk�adu
 \param day dzie�
 \param month miesi�c
 \param year rok
*/
void PCF8583_get_date(u08 *day,u08 *month,u16 *year);

/**
 Ustawia dat� w uk�adzie
 \param day dzie�
 \param month miesi�c
 \param year rok
*/
void PCF8583_set_date(u08 day,u08 month,u16 year);

/**
 Czyta czas alarmu z uk�adu
 \param hour godzina
 \param min minuta
 \param sec sekunda
 \param hsec setne cz�ci sekundy
*/
void PCF8583_get_alarm_time(u08 *hour,u08 *min,u08 *sec,u08 *hsec);

/**
 Ustawia czas alarmu w uk�adzie
 \param hour godzina
 \param min minuta
 \param sec sekunda
 \param hsec setne cz�ci sekundy
*/
void PCF8583_set_alarm_time(u08 hour,u08 min,u08 sec,u08 hsec);

/**
 Czyta dat� alarmu z uk�adu
 \param day dzie�
 \param month miesi�c
*/
void PCF8583_get_alarm_date(u08 *day,u08 *month);

/**
 Ustawia dat� alarmu w uk�adzie
 \param day dzie�
 \param month miesi�c
*/
void PCF8583_set_alarm_date(u08 day,u08 month);

/*@}*/

#endif // __PCF8583_H__
