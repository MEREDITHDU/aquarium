#include "../lcd.h"

/*
	definicje znak�w i funkcja wska�nika post�pu na LCD
*/
prog_char __PBARchars[] = {		
	32 , 32 , 32 , 32 , 32 , 32 , 32 , 32,
	16 , 16 , 16 , 16 , 16 , 16 , 16 , 16,
	24 , 24 , 24 , 24 , 24 , 24 , 24 , 24,
	28 , 28 , 28 , 28 , 28 , 28 , 28 , 28,
	30 , 30 , 30 , 30 , 30 , 30 , 30 , 30,
	31 , 31 , 31 , 31 , 31 , 31 , 31 , 31
	};

void LCD_progressbar_init(void)	// �aduje odpowiedni zestaw znak�w
{				// UWAGA! inne wcze�niej zdefniowane
  LCD_defchars_P(__PBARchars);	// znaki np. polskie zostan� nadpisane
}

