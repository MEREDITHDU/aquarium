//#define F_CPU		8000000 	// cz�stotliwo�� zegara w Hz
#define F_CPU		7372800 	// cz�stotliwo�� zegara w Hz
//#define OPTIMIZE_SPEED		// optymalizacja niekt�rych funkcji pod wzgl�dem szybko�ci

//----------------------
// UART
//----------------------
#define UART_BAUD	19200		// pr�dko�� transmisji
//#define UART_BUF_SIZE	16		// wielko�� bufor�w UART 
					// automatycznie w��cza 
					// obs�ug� UART na przerwaniach
#define UART_MAX_GETSTR	8	

#define PS2KBD_PORT	PORTD
#define PS2KBD_CLOCK	2
#define PS2KBD_DATA	3
