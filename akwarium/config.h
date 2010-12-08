#ifndef _CONFIG_H
#define _CONFIG_H

#include <avr/io.h>
#include <avr/interrupt.h>

/* Project configuration */


/* Global settings */
#define EEPROM_LOCATION (void *)37
#define F_CPU 12000000UL		//freq 12 MHz

#define UART_BAUDRATE_RAW 57600UL
#define UART_BAUDRATE (( F_CPU / ( UART_BAUDRATE_RAW << 4 ))-1)

/* Pinouts */ 
#define OW_PORT         PORTC
#define OW_BIT          5

#define THERM_PORT PORTB
#define THERM_DDR DDRB
#define THERM_PIN PINB
#define THERM_DQ PB1

//#define LED_ON  { DDRD  &= ~_BV(PD6); PORTD |= _BV(PD6); }
#define LED_ON  { DDRD  &= ~_BV(PD6); PORTD |= _BV(PD6); }
#define LED_OFF { DDRD  &= ~_BV(PD6); PORTD &= ~_BV(PD6); }

#define LED2_ON  { DDRD  |= _BV(PD6); PORTD |= _BV(PD6); }
#define LED2_OFF { DDRD  |= _BV(PD6); PORTD &= ~_BV(PD6); }


/* Start configuration */
void init_uc();

#endif 
