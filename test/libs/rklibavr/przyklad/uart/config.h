#define F_CPU		8000000 //cz�stotliwo�� zegara w Hz

/////////////////////////////////////////////////////////////////////////

//-------------------------------------------------
// UART
//-------------------------------------------------
#define UART_BAUD	19200		// pr�dko�� transmisji
//#define UART_BUF_SIZE	16		// wielko�� bufor�w UART 
					// automatycznie w��cza 
					// obs�ug� UART na przerwaniach
#define UART_MAX_GETSTR	8	
#define UART_DE_PORT	PORTD		// port linii DE konwertera RS485
#define UART_DE_BIT	7		// bit portu linii DE konwertera RS485
