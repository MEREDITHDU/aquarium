#define F_CPU		8000000 //czêstotliwoœæ zegara w Hz

//-------------------------------------------------------------------------------
// Here is definitions of remote codes for TEAC RC-200S
//-------------------------------------------------------------------------------

#define REMOTE_STD 	2

#define REMOTE_code1  0x9ece
#define REMOTE_code2  0x9e4e
#define REMOTE_code3  0x9e8e
#define REMOTE_code4  0x9e0e
#define REMOTE_code5  0x9ef6
#define REMOTE_code6  0x9e76
#define REMOTE_code7  0x9eb6
#define REMOTE_code8  0x9e36
#define REMOTE_code9  0x9e56
#define REMOTE_code10 0x9e96
#define REMOTE_code11 0x9ed6
#define REMOTE_code12 0x9e16
#define REMOTE_code13 0x9ede
#define REMOTE_code14 0x9e1e
#define REMOTE_code15 0x9e5e
#define REMOTE_code16 0x9e9e
#define REMOTE_code17 0x9e7e
#define REMOTE_code18 0x9ebe
#define REMOTE_code19 0x9eee
#define REMOTE_code20 0x9e2e
#define REMOTE_code21 0x9e46
#define REMOTE_code22 0x9ee6
#define REMOTE_code23 0x9e66
#define REMOTE_code24 0x9e86
#define REMOTE_code25 0x9ec6
#define REMOTE_code26 0x9ea6
#define REMOTE_code27 0x9e26
#define REMOTE_code28 0x9e06

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

//-------------------------------------------------
// UART
//-------------------------------------------------
#define UART_BAUD	19200		// prêdkoœæ transmisji
