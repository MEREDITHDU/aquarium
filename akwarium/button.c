#include "button.h"

int button_pressed(int button) {

	int result;

	if( button == BUTTON6 ) result = bit_is_clear(BUTTON_PIN2, button);
	else 			result = bit_is_clear(BUTTON_PIN, button);

	if(result) {
		if( button == BUTTON6 ) while( bit_is_clear(BUTTON_PIN2, button) ) usb_keepalive();
		else 			while( bit_is_clear(BUTTON_PIN, button) )  usb_keepalive();
	}

	return result;
}

		
