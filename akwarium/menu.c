
#include "menu.h"
#include "string.h"

void menu_init() {
	
	menu = menu_parent = menu_first = menu_last = 0;

	menu_add_item( 0, "TEXT1", 0 );
	menu_add_item( 0, "TEXT2", 0 );
		menu_add_item( menu_last, "XXX4", 0 ); 

	menu_add_item( 0, "TEXT3", 0 );
	menu_add_item( 0, "TEXT4", 0 );
	menu_add_item( 0, "TEXT5", 0 );
	menu_add_item( 0, "TEXT6", 0 );

	menu_parent = 0;
	menu_current = menu_first = menu;

	menu_frame = 0;	
	menu_active = 0;
}

void menu_add_item(menu_item_t *element, char *content, int action) {

	menu_item_t *parent = element;
	menu_item_t *prev   = element;

	menu_item_t *new_element = malloc(sizeof(menu_item_t));
	new_element->prev = 0;
	new_element->parent = 0;

	// inserting into children list
	if(element != 0) { 

		new_element->parent = element;
		element = element->children;

		// is first subelement
		if(element == 0) { 
			new_element->prev = 0;
			parent->children = new_element;
		}
		// is next position in sublist 
		else { 
			while(element != 0) { prev = element; element = element->next; }
			new_element->prev = prev;
			prev->next = new_element; 
		}

		element = new_element;
	}
	// inserting top level, menu is null
	else if(menu == 0) { 
		// list pointers
		new_element->prev = 0;
		new_element->parent = 0;

		menu = element = new_element;

	}
	// inserting top level, menu is not null
	else {
		element = menu;
		while(element != 0) { prev = element; element = element->next; }

		// list pointers
		element = new_element;
		element->parent = 0;
		element->prev = prev;
		prev->next = element;
	}


	char buf[21];
	int i, len = 21;
	strcpy(buf, "   ");
	len -= 3;
	strncat( buf, content, len );
	for(i=len; i>0; i--) strcat(buf, " ");

	strcpy( element->content, buf);
	element->action   = action;
	element->next 	  = 0;
	element->children = 0 ;

	menu_last = element;
}

void menu_display(int cmd) {

	if(menu_current == 0) menu_current = menu;

	int c = menu_count(menu_first);

	if(cmd == MENU_DOWN) {
		if(menu_current->next) menu_current = menu_current->next;

		if(menu_active < c-1) menu_active++;
		if((menu_active == 4+menu_frame) && (menu_frame < (c-4))) menu_frame++;
	} 
	else if(cmd == MENU_UP) {

		if(menu_current->prev) menu_current = menu_current->prev;

		if(menu_active > 0) menu_active--;
		if(menu_active < menu_frame ) menu_frame--;
	} 
	else if(cmd == MENU_RIGHT) {
		if(menu_current->children) menu_current = menu_current->children;

		menu_active = 0;
		menu_frame = 0;
	} 
	else if(cmd == MENU_LEFT) {
		if(menu_current->parent) menu_current = menu_current->parent;

		menu_active = 0;
		menu_frame = 0;
	} 


	menu_first = menu_current;

	uart_send("display_1"); UART_NL;
	while(menu_first->prev != 0) {
		uart_send("x");
		menu_first = menu_first->prev; 
	}

	uart_send("display_2"); UART_NL;
	//menu_print();	
}

void menu_print() {

	menu_item_t* m = menu_first;

	int i, line = menu_frame;
	while(line--) if(m->next != 0)  m = m->next;

	char buf[21];


//	system("clear");

	for(i=0; i<4; i++) {
	

		if(m == 0) { return; }


		strncpy( buf, m->content, 20);
		//strcpy( buf, "m->content");

		uart_send("buf");

		/*
		if(i + menu_frame == menu_active)
			buf[0] = buf[1] = buf[18] = buf[19] = '|';
		*/

		lcd_write(i, "buf                 ");

		m = m->next;
	}

}

int menu_count (menu_item_t *element) {
	int counter = 0;

	if(element == 0) element = menu;

	while(element != 0) {
		counter++;
		element = element->next;
	}

	return counter;
}

#ifndef F_CPU
	void write_command(int cmd) { }
	void write_text(char* str) { printf("%s\n", str); }
#endif
