#define F_CPU		8000000 //cz�stotliwos� zegara w Hz

//-------------------------------------------------
// UART
//-------------------------------------------------
#define UART_BAUD	19200ul		// pr�dko�� transmisji
#define UART_BUF_SIZE	8		// wielko�� bufor�w UART 
					// automatycznie w��cza 
					// obs�ug� UART na przerwaniach
#define UART_MAX_GETSTR	8	


//----------------------
// LCD 
//----------------------

#define LCD_PORT	PORTB	//port wyswietlacza
#define LCD_RS 		2	//bit linii RS
#define LCD_EN 		3	//bit linii EN
#define LCD_X		16	//liczba znak�w w linii wyswietlacza
#define LCD_Y		2	//liczba wierszy wyswietlacza
//#define LCD_BIT_SWAP		//zamiana bit�w danych LCD D3<>D0, D2<>D1
#define LCD_WRAP		//zawijanie tekstu
//#define LCD_WIN1250		//polskie znaki wg WIN1250
