#define F_CPU		8000000 //cz�stotliwo�� zegara w Hz

//----------------------
// LCD
//----------------------

#define LCD_PORT	PORTB	//port wy�wietlacza
#define LCD_RS 		2	//bit linii RS
#define LCD_EN 		3	//bit linii EN
#define LCD_X		20	//liczba znak�w w linii wy�wietlacza
#define LCD_Y		4	//liczba wierszy wy�wietlacza
//#define LCD_BIT_SWAP		//zamiana bit�w danych LCD D3<>D0, D2<>D1
#define LCD_WRAP		//zawijanie tekstu
//#define LCD_WIN1250		//polskie znaki wg WIN1250


