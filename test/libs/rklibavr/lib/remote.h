/*! \file remote.h \brief Obs�uga r�nych pilot�w zdalnego sterowania. */
/*
  Copyright (c) 2004 Robert Krysztof
  robert.krysztof@wp.pl
  http://www.avr-gcc.prv.pl
*/
/** \defgroup remote Zdalne sterowanie
 
 Obs�uga r�nych pilot�w zdalnego sterowania.
 
 \code
 #include "remote.h"
 \endcode 
 \ref config:
 
 W pliku \c "config.h" znajduj�cym si� w katalogu projektu nale�y umie�ci� nast�puj�c� zawarto��:
    	     
 \code
 #define REMOTE_PORT	PORTD
 #define REMOTE_BIT	PD2
 #define REMOTE_STD	1
 \endcode
 
 \note Warto�ci z \c #define mo�na zmienia� w celu dostosowania 
 biblioteki do tworzonego urz�dzenia i oprogramowania.
*/

/* ********************************************************************
**
**  Copyright (C) 2003  Jesper Hansen <jesperh@telia.com> and 
**			Romuald Bialy (MIS) <romek_b@o2.pl>.
**
***********************************************************************
**
**  This program is free software; you can redistribute it and/or
**  modify it under the terms of the GNU General Public License
**  as published by the Free Software Foundation; either version 2
**  of the License, or (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program; if not, write to the Free Software Foundation, 
**  Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
**
*********************************************************************** */

#ifndef __REMOTE_H__
#define __REMOTE_H__

#include <avr/io.h>
#include <avr/signal.h>
#include <avr/pgmspace.h>

#include "config.h"
#include "global.h"
/*@{*/

#ifndef REMOTE_PORT
 #define REMOTE_PORT	PORTD	///< Port, do kt�rego jest pod��czone wyj�cie odbiornika IR
 #define REMOTE_BIT	PD2	///< Bit portu REMOTE_PORT, do kt�rego jest pod��czone wyj�cie odbiornika IR
#endif

/** 
 Sprawdza czy s� dane na wej�ciu dekodera.
 \return 1 je�li s�, 0 gdy nie ma
*/
int REMOTE_active(void);

/** 
 Dekoduje dane z wyj�cia odbiornika IR
 \return 16 bitowy kod rozkazu
*/
u16 REMOTE_get(void);

/** 
 Sprawdza standard kodowania i dekoduje dane z wyj�cia odbiornika IR
 \param std standard kodowania (jak w REMOTE_STD)
 \return 16 bitowy kod rozkazu
*/
u16 REMOTE_check(u08 std);

#ifndef REMOTE_STD
/**
 Standard kodowania
 \li \b 1 : Format REC-80 u�ywany przez firm� Panasonic
 \li \b 2 : Format NEC
 \li \b 3 : Format SONY (12 bitowy)
 \li \b 4 : Format SONY (15 bitowy)
 \li \b 5 : Format RC-5 u�ywany przez firm� Philips
 \note Mo�na zmieni� w pliku "config.h" projektu
*/
 #define REMOTE_STD	1
#else
 #if (REMOTE_STD < 1) || (REMOTE_STD > 5)
  #error Invalid Remote Standard!
 #endif
#endif

/*@}*/

#endif // __REMOTE_H__
