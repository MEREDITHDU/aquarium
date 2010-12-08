#define F_CPU		8000000 	// czêstotliwoœæ zegara w Hz
//#define OPTIMIZE_SPEED		// optymalizacja niektórych funkcji pod wzglêdem szybkoœci

//----------------------
// I2C
//----------------------
#define I2C_PORT 	PORTC	//port do którego s¹ pod³¹czone linie magistrali
#define I2C_SDA		1	//bit powy¿szego portu u¿ywany jako linia SDA
#define I2C_SCL		0	//bit powy¿szego portu u¿ywany jako linia SCL

/////////////////////////////////////////////////////////////////////////

//----------------------
// PCF8583
//----------------------

#define PCF8583_A0	1	//stan linii A0 uk³adu (adres na magistrali)

/////////////////////////////////////////////////////////////////////////

//----------------------
// UART
//----------------------
#define UART_BAUD	19200	// prêdkoœæ transmisji
//#define UART_BUF_SIZE	16	// wielkoœæ buforów UART (automatycznie w³¹cza obs³ugê UART na przerwaniach)
#define UART_MAX_GETSTR	8	
