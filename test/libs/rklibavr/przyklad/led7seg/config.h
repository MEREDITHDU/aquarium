//#define LED7SEG_F_MUX		250	// czêstotliwoœæ multipleksowania w Hz

//#define LED7SEG_SIG_OVERFLOW0	abcd()	// dodatkowa funkcja wykonywana jako obs³uga przerwania
					// od przepe³nienia licznika 0 po obs³u¿eniu wyœwietlania

#define LED7SEG_KBD_ROW1_PORT	PORTB	// port odczytu 1 wiersza klawiatury
#define LED7SEG_KBD_ROW1_BIT	0	// bit portu odczytu 1 wiersza klawiatury
#define LED7SEG_KBD_ROW2_PORT	PORTD	// port odczytu 2 wiersza klawiatury
#define LED7SEG_KBD_ROW2_BIT	6	// bit portu odczytu 2 wiersza klawiatury
#define LED7SEG_KBD_ROW3_PORT	PORTD	// port odczytu 3 wiersza klawiatury
#define LED7SEG_KBD_ROW3_BIT	3	// bit portu odczytu 3 wiersza klawiatury
#define LED7SEG_KBD_ROW4_PORT	PORTD	// port odczytu 4 wiersza klawiatury
#define LED7SEG_KBD_ROW4_BIT	2	// bit portu odczytu 4 wiersza klawiatury

//#define LED7SEG_DIGITS_H	// Odkomentowaæ gdy wybieranie cyfr stanem wysokim
//#define LED7SEG_SEGMENTS_H	// Odkomentowaæ gdy wybieranie segmentów stanem wysokim

//#define LED7SEG_DIGIT_SHIFT		// wybieranie cyfr przez rejestr przesuwny
/*
    +----------------+
    |  ----------    |   ----------
    | |          |   |  |          |
CLK-+-|>         |   +--|>         |
      |   74164  |      |   74164  |
DATA--|          |   +--|          |   
      |          |   |  |          |
       ----------    |   ----------
        |||||||+-----+    ||||||||
        segmenty           cyfry
*/

//#define LED7SEG_DATA_PORT	PORTB	// port danych rejestru przesuwnego
//#define LED7SEG_DATA_BIT	6	// bit danych rejestru przesuwnego

//#define LED7SEG_CLK_PORT	PORTB	// port zegara rejestru przesuwnego
//#define LED7SEG_CLK_BIT		5	// bit zegara rejestru przesuwnego

// ----- definicje dotycz¹ce cyfr wyœwietlacza -----


/* 
	definicje potrzebne w przypadku sterowania cyframi 
	bez u¿ycia zewnêtrznego rejestru przesuwnego
*/
#define LED7SEG_DIGIT1_PORT	PORTB	// port cyfry 1
#define LED7SEG_DIGIT1_BIT	7	// bit cyfry 1
#define LED7SEG_DIGIT2_PORT	PORTB	// port cyfry 2
#define LED7SEG_DIGIT2_BIT	6	// bit cyfry 2
#define LED7SEG_DIGIT3_PORT	PORTB	// port cyfry 3
#define LED7SEG_DIGIT3_BIT	5	// bit cyfry 3
#define LED7SEG_DIGIT4_PORT	PORTB	// port cyfry 4
#define LED7SEG_DIGIT4_BIT	4	// bit cyfry 4

//#define LED7SEG_DIGIT5_PORT	PORTD	// port cyfry 5
//#define LED7SEG_DIGIT5_BIT	2	// bit cyfry 5
//#define LED7SEG_DIGIT6_PORT	PORTD	// port cyfry 6
//#define LED7SEG_DIGIT6_BIT	1	// bit cyfry 6
//#define LED7SEG_DIGIT7_PORT	PORTD	// port cyfry 7
//#define LED7SEG_DIGIT7_BIT	0	// bit cyfry 7
//#define LED7SEG_DIGIT8_PORT	PORTD	// port cyfry 8
//#define LED7SEG_DIGIT8_BIT	7	// bit cyfry 8

// ----- definicje dotycz¹ce segmentów wyœwietlacza -----

#define LED7SEG_SEGMENTS	PORTA	// port segmentów wyswietlacza
/*
	je¿eli nie jest zdefiniowane LED7SEG_SEGMENTS;
	dane przeznaczone do sterowania segmentami
	s¹ kierowane na rejestr przesuwny
       ---------- 
      |          |
CLK---|>         |
      |   74164  |
DATA--|          |
      |          |
       ----------
        ||||||||
        segmenty
*/
				// bity segmentów na wyœwietlaczu:
#define LED7SEG_A		1	// bit segmentu A
#define LED7SEG_B		2	// bit segmentu B
#define LED7SEG_C		6	// bit segmentu C
#define LED7SEG_D		4	// bit segmentu D
#define LED7SEG_E		3	// bit segmentu E
#define LED7SEG_F		0	// bit segmentu F
#define LED7SEG_G		5	// bit segmentu G
#define LED7SEG_H		7	// bit segmentu H (kropki)

