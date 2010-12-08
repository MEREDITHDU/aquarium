#define F_CPU		8000000	// cz�stotliwo�� zegara w Hz

//-------------------------------------------------
// KBD
//-------------------------------------------------
#define KBD_PORT_col1	PORTB
#define KBD_BIT_col1	7
#define KBD_PORT_col2	PORTB
#define KBD_BIT_col2	6
#define KBD_PORT_col3	PORTB
#define KBD_BIT_col3	5
#define KBD_PORT_col4	PORTB
#define KBD_BIT_col4	4
//-------------------------------------------------
#define KBD_PORT_row1	PORTB
#define KBD_BIT_row1	0
#define KBD_PORT_row2	PORTD
#define KBD_BIT_row2	6
#define KBD_PORT_row3	PORTD
#define KBD_BIT_row3	3
#define KBD_PORT_row4	PORTD
#define KBD_BIT_row4	2
// linie wierszy klawiatury mo�na wsp�dzieli�
// z liniami danych wy�wietlacza LCD
//-------------------------------------------------

//-------------------------------------------------
// LCD
//-------------------------------------------------
#define LCD_PORT	PORTB	//port wy�wietlacza
#define LCD_RS 		2	//bit linii RS
#define LCD_EN 		3	//bit linii EN
#define LCD_X		16	//liczba znak�w w linii wy�wietlacza
#define LCD_Y		2	//liczba wierszy wy�wietlacza
//#define LCD_BIT_SWAP		//zamiana bit�w danych LCD D3<>D0, D2<>D1
#define LCD_WRAP		//zawijanie tekstu
#define LCD_WIN1250		//polskie znaki wg WIN1250

//-------------------------------------------------
// UART
//-------------------------------------------------
#define UART_BAUD	1200		// pr�dko�� transmisji
//#define UART_BUF_SIZE	16		// wielko�� bufor�w UART
					// automatycznie w��cza
					// obs�ug� UART na przerwaniach
#define UART_MAX_GETSTR	16	
#define UART_DE_PORT	PORTD		// port linii DE konwertera RS485
#define UART_DE_BIT	7		// bit portu linii DE konwertera RS485


