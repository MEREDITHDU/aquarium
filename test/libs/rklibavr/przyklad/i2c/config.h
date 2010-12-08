#define F_CPU		8000000 	// cz�stotliwo�� zegara w Hz
#define OPTIMIZE_SPEED		// optymalizacja niekt�rych funkcji pod wzgl�dem szybko�ci

//----------------------
// I2C
//----------------------
#define I2C_PORT 	PORTC	//port do kt�rego s� pod��czone linie magistrali
#define I2C_SDA		1	//bit powy�szego portu u�ywany jako linia SDA
#define I2C_SCL		0	//bit powy�szego portu u�ywany jako linia SCL

/////////////////////////////////////////////////////////////////////////

//----------------------
// PCF8583
//----------------------

#define PCF8583_A0	1	//stan linii A0 uk�adu (adres na magistrali)

/////////////////////////////////////////////////////////////////////////

//----------------------
// LCD 
//----------------------

#define LCD_PORT	PORTB	//port wy�wietlacza
#define LCD_RS 		2	//bit linii RS
#define LCD_EN 		3	//bit linii EN
#define LCD_X		16	//liczba znak�w w linii wy�wietlacza
#define LCD_Y		2	//liczba wierszy wy�wietlacza
//#define LCD_BIT_SWAP		//zamiana bit�w danych LCD D3<>D0, D2<>D1
#define LCD_WRAP		//zawijanie tekstu
//#define LCD_WIN1250		//polskie znaki wg WIN1250

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
