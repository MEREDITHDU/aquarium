#include "temp.h"


void temp_input_mode()  { TEMP_DDR  &= ~(1 << temp_selected_dq); }
void temp_output_mode() { TEMP_DDR  |=  (1 << temp_selected_dq); }
void temp_low_state()   { TEMP_PORT &= ~(1 << temp_selected_dq); }
void temp_high_state()  { TEMP_PORT |=  (1 << temp_selected_dq); }
/*
#define TEMP_INPUT_MODE() TEMP_DDR&=~(1<<temp_selected_dq)
#define TEMP_OUTPUT_MODE() TEMP_DDR|=(1<<temp_selected_dq)
#define TEMP_LOW() TEMP_PORT&=~(1<<temp_selected_dq)
#define TEMP_HIGH() TEMP_PORT|=(1<<temp_selected_dq)
*/

void temp_set_device(int8_t devicenum) {
	switch(devicenum) {
		case 1: temp_selected_dq = TEMP1; break;
		case 2: temp_selected_dq = TEMP2; break;
		case 3: temp_selected_dq = TEMP3; break;
	}
}

void temp_delay(uint16_t delay) {
	while(delay--) asm volatile("nop");
}

uint8_t temp_reset() {
	uint8_t i;
	//Pull line low and wait for 480uS
	temp_low_state();
	temp_output_mode();
	temp_delay(us(480));
	//Release line and wait for 60uS
	temp_input_mode();
	temp_delay(us(60));
	//Store line value and wait until the completion of 480uS period
	i=(TEMP_PIN & (1<<temp_selected_dq));
	temp_delay(us(420));
	//Return the value read from the presence pulse (0=OK, 1=WRONG)
	return i;
}

void temp_write_bit(uint8_t bit) {
	//Pull line low for 1uS
	temp_low_state();
	temp_output_mode();
	temp_delay(us(1));
	//If we want to write 1, release the line (if not will keep low)
	if(bit) temp_input_mode();
	//Wait for 60uS and release the line
	temp_delay(us(60));
	temp_input_mode();
}

uint8_t temp_read_bit(void) {
	uint8_t bit=0;
	//Pull line low for 1uS
	temp_low_state();
	temp_output_mode();
	temp_delay(us(1));
	//Release line and wait for 14uS
	temp_input_mode();
	temp_delay(us(14));
	//Read line value
	if(TEMP_PIN&(1<<temp_selected_dq)) bit=1;
	//Wait for 45uS to end and return read value
	temp_delay(us(45));
	return bit;
}

uint8_t temp_read_byte(void) {
	uint8_t i=8, n=0;
	while(i--) {
		//Shift one position right and store read value
		n>>=1;
		n|=(temp_read_bit()<<7);
	}
	return n;
}

void temp_write_byte(uint8_t byte) {
	uint8_t i=8;
	while(i--)
	{
		//Write actual bit and shift one position right to make the next bit ready
		temp_write_bit(byte&1);
		byte>>=1;
	}
}

void temp_read(int8_t device, char *buffer) {
	temp_set_device( device );

	// Buffer length must be at least 12bytes long! ["+XXX.XXXX C"]
	uint8_t temperature[2];
	int8_t digit;
	uint16_t decimal;
	//Reset, skip ROM and start temperature conversion
	temp_reset();
	temp_write_byte(TEMP_CMD_SKIPROM);
	temp_write_byte(TEMP_CMD_CONVERTTEMP);
	//Wait until conversion is complete
	while(!temp_read_bit()) ;//usb_keepalive();
	//Reset, skip ROM and send command to read Scratchpad
	temp_reset();
	temp_write_byte(TEMP_CMD_SKIPROM);
	temp_write_byte(TEMP_CMD_RSCRATCHPAD);
	//Read Scratchpad (only 2 first bytes)
	temperature[0]=temp_read_byte();
	temperature[1]=temp_read_byte();
	temp_reset();
	//Store temperature integer digits and decimal digits
	digit=temperature[0]>>4;
	digit|=(temperature[1]&0x7)<<4;
	//Store decimal digits
	decimal=temperature[0]&0xf;
	decimal*=TEMP_DECIMAL_STEPS_12BIT;
	//Format temperature into a string [+XXX.XXXX C]
	sprintf(buffer, "%+d.%04u C", digit, decimal);
}

void temp_read2(int8_t device, int8_t *digi, uint16_t *deci) {
	temp_set_device( device );

	// Buffer length must be at least 12bytes long! ["+XXX.XXXX C"]
	uint8_t temperature[2];
	int8_t digit;
	uint16_t decimal;
	//Reset, skip ROM and start temperature conversion
	temp_reset();
	temp_write_byte(TEMP_CMD_SKIPROM);
	temp_write_byte(TEMP_CMD_CONVERTTEMP);
	//Wait until conversion is complete
	while(!temp_read_bit());
	//Reset, skip ROM and send command to read Scratchpad
	temp_reset();
	temp_write_byte(TEMP_CMD_SKIPROM);
	temp_write_byte(TEMP_CMD_RSCRATCHPAD);
	//Read Scratchpad (only 2 first bytes)
	temperature[0]=temp_read_byte();
	temperature[1]=temp_read_byte();
	temp_reset();
	//Store temperature integer digits and decimal digits
	digit=temperature[0]>>4;
	digit|=(temperature[1]&0x7)<<4;
	//Store decimal digits
	decimal=temperature[0]&0xf;
	decimal*=TEMP_DECIMAL_STEPS_12BIT;
	//results
	*digi = digit;
	*deci = decimal;
}

