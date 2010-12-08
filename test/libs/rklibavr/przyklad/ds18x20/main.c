#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <string.h>

#include "delay.h"
#include "uart.h"
#include "lcd.h"
#include "ds18x20.h"

uint8_t gSensorIDs[OW_ROMCODE_SIZE];

int main( void )
{
	uint16_t decicelsius;
	uint8_t diff, i, subzero, cel, cel_frac_bits;

	UART_init();
	LCD_init();

#ifndef OW_PORT
	OW_set_bus(&PORTD,6);
#endif
//	DS18X20_find_sensor(&diff, &gSensorIDs[0]);
	
	while(1)
	{
//		i = gSensorIDs[0]; // family-code for conversion-routine

		DS18X20_start_meas( DS18X20_POWER_PARASITE, NULL );
		delayms(DS18B20_TCONV_12BIT);
		DS18X20_read_meas_single(0x10, &subzero, &cel, &cel_frac_bits);
		decicelsius = DS18X20_temp_to_decicel(subzero, cel, cel_frac_bits);

//		UART_putstr_P(PSTR("\rdiff = "));
//		UART_putint(diff, 16);
//		UART_putstr_P(PSTR("\rgSensorIDs[0] = "));
//		UART_putint(i, 16);
		UART_putstr_P(PSTR("\rsubzero = "));
		UART_putint(subzero, 10);
		UART_putstr_P(PSTR("\rcel = "));
		UART_putint(cel, 10);
		UART_putstr_P(PSTR("\rcel_frac_bits = "));
		UART_putint(cel_frac_bits, 10);
		UART_putstr_P(PSTR("\rdecicelsius = "));
		
		UART_putchar((subzero)?'-':'+');
		UART_putint( (decicelsius/10) ,10);
		UART_putchar(',');
		UART_putchar( (decicelsius%10) + '0');
		UART_putchar('\r');
		LCD_xy(0,0);
		LCD_putchar((subzero)?'-':'+');
 		LCD_putint( (decicelsius/10) ,10);
		LCD_putchar(',');
		LCD_putchar( (decicelsius%10) + '0');
	}
		
}
