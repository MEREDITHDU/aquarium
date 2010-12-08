
#define EEPROM_LOCATION (void *)37

#define F_CPU 12000000UL		//freq 12 MHz
//#define F_CPU 8000000UL	

//#define UART_BAUDRATE_RAW 57600UL
#define UART_BAUDRATE_RAW 9600UL

#define UART_BAUDRATE (( F_CPU / ( UART_BAUDRATE_RAW << 4 ))-1)

#define OW_PORT         PORTC
#define OW_BIT          5

#define THERM_PORT PORTB
#define THERM_DDR DDRB
#define THERM_PIN PINB
#define THERM_DQ PB1

