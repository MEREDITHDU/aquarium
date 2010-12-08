
#include "servo.h"

void servo_move(int direction) {

	DDRB |= _BV(SERVO_PIN); 

	switch(direction) {

		case 0: //left

			SERVO_PORT |= _BV(SERVO_PIN);
			_delay_us(2570);
			//_delay_us(1.5);
			SERVO_PORT &= ~(_BV(SERVO_PIN));

			break;

		case 1: //right

			SERVO_PORT |= _BV(SERVO_PIN);
			_delay_us(570);
			//_delay_ms(0.5);
			SERVO_PORT &= ~(_BV(SERVO_PIN));
			break;

			_delay_ms(15);
			SERVO_PORT |= _BV(SERVO_PIN);
			_delay_ms(0.5);
			SERVO_PORT &= ~(_BV(SERVO_PIN));

			break;

		case 2: // right

			SERVO_PORT |= _BV(SERVO_PIN);
			_delay_ms(2.5);
			SERVO_PORT &= ~(_BV(SERVO_PIN));
			break;

			_delay_ms(15);
			SERVO_PORT |= _BV(SERVO_PIN);
			_delay_ms(2.5);
			SERVO_PORT &= ~(_BV(SERVO_PIN));
			break;
	
	}
}
