#ifndef _CONFIG_H
#define _CONFIG_H

#include <avr/io.h>
#include <avr/common.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <util/delay.h> 
#include <util/twi.h> 

/* Project configuration */

//PORTA
#define LCD_PORT	PORTA
#define LCD_DDR		DDRA
#define LCD_DATA1 	A0
#define LCD_DATA2 	A1
#define LCD_DATA3	PA2
#define LCD_DATA4 	PA3
#define LCD_E 		PA4
#define LCD_RS		PA5
#define LCD_BACKLIGHT 	PA6

//PORTB
#define HVPORT PORTB
#define HV1 PB0
#define HV2 PB1
#define HV3 PB2
#define HV4 PB3

#define TEMP1	PB4
#define TEMP2	PB5
#define TEMP3	PB6
#define TEMP_PORT PORTB
#define TEMP_DDR DDRB
#define TEMP_PIN PINB

//PORTC
#define SERVO_PORT PORTC
#define SERVO_DDR DDRC
#define SERVO PC7

#define BUTTON1 	PC6
#define BUTTON2 	PC5
#define BUTTON3 	PC4
#define BUTTON4 	PC3
#define BUTTON5 	PC2
#define BUTTON_PIN 	PINC
#define BUTTON_PIN2 	PIND

//PORTD
#define RS_RX	PD0
#define RS_TX	PD1
#define USB_PLUS 	PD2
#define USB_MINUS 	PD4
#define BUTTON6 PD7

#define HEAT	PD6

// TWI - PCF8583


/* Global settings */

#define EEPROM_LOCATION (void *)37
// uart
#define UART_BAUDRATE_RAW 57600UL
#define UART_BAUDRATE (( F_CPU / ( UART_BAUDRATE_RAW << 4 ))-1)

/* Macros */
#define HEAT_TOGGLE() PORTD ^= _BV(HEAT) 



/* Start configuration */
void config_init();

#endif 
