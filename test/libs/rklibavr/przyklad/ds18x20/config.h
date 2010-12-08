#define F_CPU		8000000 //czêstotliwoœæ zegara w Hz

//-------------------------------------------------
// 1Wire
//-------------------------------------------------

#define OW_PORT		PORTD
#define OW_BIT		6

/////////////////////////////////////////////////////////////////////////

//-------------------------------------------------
// UART
//-------------------------------------------------
#define UART_BAUD	19200		// prêdkoœæ transmisji
//#define UART_BUF_SIZE	16		// wielkoœæ buforów UART 
					// automatycznie w³¹cza 
					// obs³ugê UART na przerwaniach
#define UART_MAX_GETSTR	16	

//----------------------
// LCD 
//----------------------

#define LCD_PORT	PORTB	//port wyœwietlacza
#define LCD_RS 		2	//bit linii RS
#define LCD_EN 		3	//bit linii EN
#define LCD_X		16	//liczba znaków w linii wyœwietlacza
#define LCD_Y		2	//liczba wierszy wyœwietlacza
//#define LCD_BIT_SWAP		//zamiana bitów danych LCD D3<>D0, D2<>D1
#define LCD_WRAP		//zawijanie tekstu
#define LCD_WIN1250		//polskie znaki wg WIN1250
