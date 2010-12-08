#define F_CPU		8000000	// czêstotliwoœæ zegara w Hz

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
// linie wierszy klawiatury mo¿na wspó³dzieliæ
// z liniami danych wyœwietlacza LCD
//-------------------------------------------------

//-------------------------------------------------
// LCD
//-------------------------------------------------
#define LCD_PORT	PORTB	//port wyœwietlacza
#define LCD_RS 		2	//bit linii RS
#define LCD_EN 		3	//bit linii EN
#define LCD_X		16	//liczba znaków w linii wyœwietlacza
#define LCD_Y		2	//liczba wierszy wyœwietlacza
//#define LCD_BIT_SWAP		//zamiana bitów danych LCD D3<>D0, D2<>D1
#define LCD_WRAP		//zawijanie tekstu
#define LCD_WIN1250		//polskie znaki wg WIN1250

//-------------------------------------------------
// UART
//-------------------------------------------------
#define UART_BAUD	1200		// prêdkoœæ transmisji
//#define UART_BUF_SIZE	16		// wielkoœæ buforów UART
					// automatycznie w³¹cza
					// obs³ugê UART na przerwaniach
#define UART_MAX_GETSTR	16	
#define UART_DE_PORT	PORTD		// port linii DE konwertera RS485
#define UART_DE_BIT	7		// bit portu linii DE konwertera RS485


