#pragma once

#include <avr/io.h> 
#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>
#include "config.h"
//#include <iom32v.h>
//#include <macros.h>
//custom headsers
#include "therm_ds18b20.h"
#include "pir.h"
#include "led.h"
#include "ping.h"
//#include "timer.h"
#include "avrlibdefs.h"
#include "avrlibtypes.h"
#include "a2d.h"
#include "uart.h"
#include "timer.h"
#include "i2c.h"
#include "servo.h"
#include "lcd.h"
#include "pushbutton.h"

//delay functions
#define F_CPU 16000000UL 		//Your clock speed in Hz (8Mhz here)

//-----------------delays---------------------------------------------------------
 #define delay_ns(__ns) \
    if((unsigned long) (F_CPU/1000000000.0 * __ns) != F_CPU/1000000000.0 * __ns)\
          __builtin_avr_delay_cycles((unsigned long) ( F_CPU/1000000000.0 * __ns)+1);\
    else __builtin_avr_delay_cycles((unsigned long) ( F_CPU/1000000000.0 * __ns))
  #define delay_us(__us) \
    if((unsigned long) (F_CPU/1000000.0 * __us) != F_CPU/1000000.0 * __us)\
          __builtin_avr_delay_cycles((unsigned long) ( F_CPU/1000000.0 * __us)+1);\
    else __builtin_avr_delay_cycles((unsigned long) ( F_CPU/1000000.0 * __us))
  #define delay_ms(__ms) \
    if((unsigned long) (F_CPU/1000.0 * __ms) != F_CPU/1000.0 * __ms)\
          __builtin_avr_delay_cycles((unsigned long) ( F_CPU/1000.0 * __ms)+1);\
    else __builtin_avr_delay_cycles((unsigned long) ( F_CPU/1000.0 * __ms))
  #define delay_s(__s) \
    if((unsigned long) (F_CPU/1.0 * __s) != F_CPU/1.0 * __s)\
          __builtin_avr_delay_cycles((unsigned long) ( F_CPU/1.0 * __s)+1);\
    else __builtin_avr_delay_cycles((unsigned long) ( F_CPU/1.0 * __s))
//--------------------------------------------------------------------------------


#define PORT_ON( port_letter, number )			port_letter |= (1<<number)
#define PORT_OFF( port_letter, number )			port_letter &= ~(1<<number)
#define PORT_ALL_ON( port_letter, number )		port_letter |= (number)
#define PORT_ALL_OFF( port_letter, number )		port_letter &= ~(number)
#define FLIP_PORT( port_letter, number )		port_letter ^= (1<<number)
#define PORT_IS_ON( port_letter, number )		( port_letter & (1<<number) )
#define PORT_IS_OFF( port_letter, number )		!( port_letter & (1<<number) )
