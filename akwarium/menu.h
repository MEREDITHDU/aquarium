
#ifndef __MENU
#define __MENU


#ifndef F_CPU
	
	#include <stdio.h>
	#include <malloc.h>

	#define LINE1 1
	#define LINE2 2
	#define LINE3 3
	#define LINE4 4

	//#error "INHERE"
	void write_command(int);
	void write_text(char*);
#else
	#include "config.h"
	#include "lcd.h"
	#include "uart.h"
#endif


#define MENU_UP 0
#define MENU_DOWN 1
#define MENU_LEFT 2
#define MENU_RIGHT 3


typedef struct menu_item {
	char content[21];
	int action;

	struct menu_item *prev;
	struct menu_item *next;
	struct menu_item *parent;
	struct menu_item *children;
} menu_item_t;
menu_item_t *menu;

// menu usage
int menu_frame, menu_active;
menu_item_t 	*menu_parent, 
		*menu_first, 
		*menu_last, 
		*menu_current;

void menu_init();
void menu_add_item(menu_item_t*, char*, int);
void menu_display(int);
void menu_print();
int menu_count (menu_item_t *) ;


#endif
