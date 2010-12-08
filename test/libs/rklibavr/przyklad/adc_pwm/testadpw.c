/*-------------------------------------------------------------------------- */
/*	Test wyjœcia przetwornika ADC_PWM 				     */
/*	Autor:  Robert Krysztof						     */
/*	E-mail: robert.krysztof@wp.pl					     */
/* 	WWW:	http://www.8051.prv.pl 					     */
/* ------------------------------------------------------------------------- */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include "adc_pwm.h"
#include "uart.h"
#include "delay.h"

/* ------------------------------------------------------------------------- */
/*		  Definicje stalych i makroinstrukcji			     */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/*			   Definicje funkcji				     */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* ----------------		 Program glowny 	    ---------------- */
/* ------------------------------------------------------------------------- */

int main(void)
{  
  u16 pomiar;			// zmierzona wartoœæ          
  UART_init();			// inicjalizacja UART
  ADC_PWM_init();		// inicjalizacja wyjœcia PWM
  UART_putstr_P(PSTR("Przetwornik ADC_PWM"));	//wypisz tekst powitalny
  while(1)			// pêtla nieskoñczona
  {
    pomiar=ADC_PWM_read();	// czytaj pomiar
    UART_putint(pomiar,10);	// wyœwietl na UART
  }
}

/* ------------------------------------------------------------------------- */
/*				Koniec programu               		     */
/* ------------------------------------------------------------------------- */
