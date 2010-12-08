#include <avr/io.h>

#include "config.h"
#include <util/delay.h>

#define SERVO_PORT PORTB
#define SERVO_PIN  PB0

void servo_move(int);
