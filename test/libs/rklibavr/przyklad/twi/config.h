#define F_CPU		8000000 	// cz�stotliwo�� zegara w Hz
//#define OPTIMIZE_SPEED		// optymalizacja niekt�rych funkcji pod wzgl�dem szybko�ci

//----------------------
// I2C
//----------------------
#define I2C_PORT 	PORTC	//port do kt�rego s� pod��czone linie magistrali
#define I2C_SDA		1	//bit powy�szego portu u�ywany jako linia SDA
#define I2C_SCL		0	//bit powy�szego portu u�ywany jako linia SCL

/////////////////////////////////////////////////////////////////////////

//----------------------
// PCF8583
//----------------------

#define PCF8583_A0	1	//stan linii A0 uk�adu (adres na magistrali)

/////////////////////////////////////////////////////////////////////////

//----------------------
// UART
//----------------------
#define UART_BAUD	19200	// pr�dko�� transmisji
//#define UART_BUF_SIZE	16	// wielko�� bufor�w UART (automatycznie w��cza obs�ug� UART na przerwaniach)
#define UART_MAX_GETSTR	8	
