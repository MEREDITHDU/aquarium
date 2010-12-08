/*! \file debug.h \brief Funkcje debuguj�ce. */
/*
  Copyright (c) 2004 Robert Krysztof
  robert.krysztof@wp.pl
  http://www.avr-gcc.prv.pl
*/
//*****************************************************************************
//
// File Name	: 'debug.h'
// Title	: Helpful debugging functions
// Author	: Pascal Stang - Copyright (C) 2003
//
// Description	: This file contains a set of functions which may be useful
//		for general debugging.
//
// This code is distributed under the GNU Public License
//		which can be found at http://www.gnu.org/licenses/gpl.txt
//
//*****************************************************************************

/** \defgroup debug Funkcje debuguj�ce
 
 Zawiera r�ne funkcje przydatne przy "odpluskwianiu" program�w i sprz�tu.
 \code
 #include "debug.h"
 \endcode 
*/

#ifndef DEBUG_H
#define DEBUG_H

#include <avr/io.h>
#include "global.h"
#include "uart.h"

/*@{*/

/**
 Wypisuje obszar pami�ci jako sformatowan� tablic� szesnastkow� wraz ze znakami ASCII
 \param buffer wska�nik do obszaru pami�ci
 \param length d�ugo�� obszaru do wy�wietlenia
*/
void DEBUG_hextable(u08 *buffer, u16 length);

/*@}*/

#endif
