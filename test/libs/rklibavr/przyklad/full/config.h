#define F_CPU		8000000	// cz�stotliwo�� zegara w Hz

//-------------------------------------------------
// KBD
//-------------------------------------------------
#define KBD_PORT_col1	PORTD
#define KBD_BIT_col1	5
#define KBD_PORT_col2	PORTD
#define KBD_BIT_col2	6
#define KBD_PORT_col3	PORTB
#define KBD_BIT_col3	0
#define KBD_PORT_col4	PORTB
#define KBD_BIT_col4	1
//-------------------------------------------------
#define KBD_PORT_row1	PORTB
#define KBD_BIT_row1	4
#define KBD_PORT_row2	PORTB
#define KBD_BIT_row2	5
#define KBD_PORT_row3	PORTB
#define KBD_BIT_row3	6
#define KBD_PORT_row4	PORTB
#define KBD_BIT_row4	7
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
#define LCD_BIT_SWAP		//zamiana bit�w danych LCD D3<>D0, D2<>D1
#define LCD_WRAP		//zawijanie tekstu
#define LCD_WIN1250		//polskie znaki wg WIN1250

//-------------------------------------------------
// UART
//-------------------------------------------------
#define UART_BAUD	19200ul		// pr�dko�� transmisji
#define UART_BUF_SIZE	8		// wielko�� bufor�w UART 
					// automatycznie w��cza 
					// obs�ug� UART na przerwaniach
#define UART_MAX_GETSTR	8

//----------------------
// I2C
//----------------------
#define I2C_PORT 	PORTD	//port do kt�rego s� pod��czone linie magistrali
#define I2C_SDA		5	//bit powy�szego portu u�ywany jako linia SDA
#define I2C_SCL		6	//bit powy�szego portu u�ywany jako linia SCL

//-------------------------------------------------
// LED7SEG
//-------------------------------------------------
#define LED7SEG_COMMON_K		// wy�wietlacze ze wsp�ln� katod�

#define LED7SEG_DIGIT_SHIFT		// wybieranie cyfr przez rejestr przesuwny

#define LED7SEG_DATA_PORT	PORTD	// port danych rejestru przesuwnego
#define LED7SEG_DATA_BIT	3	// bit danych rejestru przesuwnego

#define LED7SEG_CLK_PORT	PORTD	// port zegara rejestru przesuwnego
#define LED7SEG_CLK_BIT		4	// bit zegara rejestru przesuwnego

/*
    +----------------+
    |  ----------    |   ----------
    | |          |   |  |          |
CLK-*-|>         |   +--|>         |
      |   74164  |      |   74164  |
DATA--|          |   +--|          |   
      |          |   |  |          |
       ----------    |   ----------
        ||||||||-----+    ||||||||
        segmenty           cyfry
*/

// ----- definicje dotycz�ce cyfr wy�wietlacza -----

#define LED7SEG_DIGITS		4	// liczba cyfr na wyswietlaczu

#define LED7SEG_DIGIT1_PORT	PORTD	// port cyfry 1
#define LED7SEG_DIGIT1_BIT	6	// bit cyfry 1
#define LED7SEG_DIGIT2_PORT	PORTD	// port cyfry 2
#define LED7SEG_DIGIT2_BIT	5	// bit cyfry 2
#define LED7SEG_DIGIT3_PORT	PORTD	// port cyfry 3
#define LED7SEG_DIGIT3_BIT	4	// bit cyfry 3
#define LED7SEG_DIGIT4_PORT	PORTD	// port cyfry 4
#define LED7SEG_DIGIT4_BIT	3	// bit cyfry 4

// ----- definicje dotycz�ce segment�w wy�wietlacza -----

				// bity segment�w na wy�wietlaczu:
#define LED7SEG_A		1	// bit segmentu A
#define LED7SEG_B		2	// bit segmentu B
#define LED7SEG_C		6	// bit segmentu C
#define LED7SEG_D		4	// bit segmentu D
#define LED7SEG_E		3	// bit segmentu E
#define LED7SEG_F		0	// bit segmentu F
#define LED7SEG_G		5	// bit segmentu G
#define LED7SEG_H		7	// bit segmentu H (kropki)

