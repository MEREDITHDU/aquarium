//#define F_CPU		8000000 	// czêstotliwoœæ zegara w Hz
#define F_CPU		7372800 	// czêstotliwoœæ zegara w Hz
//#define OPTIMIZE_SPEED		// optymalizacja niektórych funkcji pod wzglêdem szybkoœci

//----------------------
// UART
//----------------------
#define UART_BAUD	19200		// prêdkoœæ transmisji
//#define UART_BUF_SIZE	16		// wielkoœæ buforów UART 
					// automatycznie w³¹cza 
					// obs³ugê UART na przerwaniach
#define UART_MAX_GETSTR	8	

#define PS2KBD_PORT	PORTD
#define PS2KBD_CLOCK	2
#define PS2KBD_DATA	3
