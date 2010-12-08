/** \file twi.h \brief Sterownik interfejsu TWI. */
/*
  Copyright (c) 2004 Robert Krysztof
  robert.krysztof@wp.pl
  http://www.avr-gcc.prv.pl

  Based on:
  Title: Interrupt driven Two Wire Interface
  Author: kkempeneers (Koen Kempeneers)
  Registered at AVRfreaks.net November 11, 2003
*/
/** \defgroup twi Interfejs TWI
	
	Obs�uga interfejsu TWI
 \code
 #include "twi.h"
 \endcode 

 \par Wykorzystywane przerwania:
 
 \c SIG_2WIRE_SERIAL
*/
#ifndef __TWI_H__
#define __TWI_H__

#include <avr/io.h>
#include <compat/twi.h>
#include <avr/signal.h>
#include <avr/interrupt.h>

#include "config.h"
#include "global.h"

/*@{*/

/** Bit definitions for the tw_status register */
#define TWI_BUSY 7

extern volatile unsigned char TWI_address;	///< Adres sprz�towy uk�adu
extern volatile unsigned char *TWI_data;	///< Wska�nik do danych TWI 
extern volatile unsigned char TWI_ddr;	///< Kierukek danych TWI
extern volatile unsigned char TWI_bytes;	///< Ilo�� bajt�w TWI
extern volatile unsigned char TWI_stop;	///< Znacznik zako�czenia transmisji

extern volatile unsigned char TWI_stat;	///< Status TWI
extern volatile unsigned char TWI_retry_cnt; ///< Licznik powt�rze� TWI

/** 
 Inicjalizacja TWI
*/
void TWI_init(void);

/** 
 Zapisuje dane do uk�adu z interfejsem TWI
 \param address 7-bitowy adres sprz�towy uk�adu
 \param *data wska�nik do bloku danych
 \param bytes wielko�� bloku do wys�ania
 \return 0 (zero)
*/
int TWI_write(unsigned char address, unsigned char *data, unsigned char bytes);

/** 
 Czyta dane z uk�adu z interfejsem TWI
 \param address 7-bitowy adres sprz�towy uk�adu
 \param *data wska�nik do bloku danych
 \param bytes wielko�� bloku do odczytu
 \return 0 (zero)
*/
int TWI_read(unsigned char address, unsigned char *data, unsigned char bytes);

/*@}*/

#endif //__TWI_H__

