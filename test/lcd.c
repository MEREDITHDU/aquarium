
#include "lcd.h"

// procedura zapisu bajtu do wyświetlacza LCD
// bez rozróżnienia instrukcja/dana
void write_to_lcd(char x)
{
	SET_E; // ustaw na E stan wysoki
	LCD = ((LCD & 0xF0) | ((x & 0xF0) >> 4)); // zapis pierwszej połówki bajtu
	_delay_ms(1);
	CLR_E; // opadające zbocze na E -> zapis do wyświetlacza
	_delay_ms(1);	
	
	SET_E; // ustaw na E stan wysoki
	LCD = ((LCD & 0xF0) | (x & 0x0F)); // zapis drugiej połowki bajtu
	_delay_ms(1);
	CLR_E; // opadające zbocze na E -> zapis do wyświetlacza
	_delay_ms(1);
}

// procedura zapisu instrukcji do wyświetlacza LCD
void write_command(char x)
{
	CLR_RS; // niski stan na RS -> zapis instrukcji
	write_to_lcd(x); // zapis do LCD
}

// procedura zapisu danej do wyświetlacza LCD
void write_char(char x)
{
	SET_RS; // wysoki stan na RS -> zapis danej
	write_to_lcd(x); // zapis do LCD
}

// procedura zapisu tekstu do wyświetlacza LCD
void write_text(char * s)
{
	while(*s) // do napotkania 0
	{
		write_char(*s); // zapisz znak wskazywany przez s na LCD
		s++; // zwiększ s (przygotuj nastepny znak)
	}
}


void lcd_init(void)
{
	_delay_ms(15); // czekaj 15ms na ustabilizowanie się napięcia zasilającego
	
	CLR_E;
	CLR_RS;
	
	SET_E;	LCD = (LCD & 0xf0)|(0x03 & 0x0f);  _delay_ms(1); CLR_E; 

	_delay_ms(10);

	SET_E; LCD = (LCD & 0xf0)|(0x03 & 0x0f); _delay_ms(1); CLR_E;

	SET_E; LCD = (LCD & 0xf0)|(0x03 & 0x0f); _delay_ms(1); CLR_E; 

	write_command(0x38); // czyść LCD
	write_command(0x06); // czyść LCD
	write_command(0x0F); // czyść LCD
	write_command(0x01); // czyść LCD
	write_command(0x80); // czyść LCD

	write_command(0x02);
	write_command(0x01);
	write_command(0x0C);

}


