
#include "temp.h"


uint8_t therm_reset()
{
	uint8_t i;
	/*
	//Pull line low and wait for 480uS
	THERM_LOW();
	THERM_OUTPUT_MODE();
	delay_us(450);	//480 //this must be smaller when moving delay func to other .c file
	//Release line and wait for 60uS
	THERM_INPUT_MODE();
	delay_us(60); //60
	//Store line value and wait until the completion of 480uS period
	i=(THERM_PIN & (1<<THERM_DQ));
	delay_us(420); //420
	//Return the value read from the presence pulse (0=OK, 1=WRONG)
	*/

	THERM_LOW();
	THERM_OUTPUT_MODE();
	_delay_us(450);//500

	THERM_INPUT_MODE();
	_delay_us(20);//30

	i=(THERM_PIN & (1<<THERM_DQ));
	_delay_us(420);//420

	return i;
}

void therm_write_bit(uint8_t bit)
{
	/*
	//Pull line low for 1uS
	THERM_LOW();
	THERM_OUTPUT_MODE();
	delay_us(1);//1
	//If we want to write 1, release the line (if not will keep low)
	if(bit) THERM_INPUT_MODE();
	//Wait for 60uS and release the line
	delay_us(60);//60
	THERM_INPUT_MODE();
	*/

	THERM_LOW();
	THERM_OUTPUT_MODE();
	_delay_us(1);

	if(bit) THERM_INPUT_MODE();
	else {
		_delay_us(60);//60
		THERM_INPUT_MODE();
	}
}

uint8_t therm_read_bit(void)
{
	uint8_t bit=0;
	/*
	//Pull line low for 1uS
	THERM_LOW();
	THERM_OUTPUT_MODE();
	delay_us(1);//1
	//Release line and wait for 14uS
	THERM_INPUT_MODE();
	delay_us(14);//14
	//Read line value
	if(THERM_PIN&(1<<THERM_DQ)) bit=1;
	//Wait for 45uS to end and return read value
	delay_us(45);//45
	*/

	
	THERM_LOW();
	THERM_OUTPUT_MODE();
	_delay_us(1);//1

	THERM_INPUT_MODE();
	_delay_us(14);//1

	if(THERM_PIN&(1<<THERM_DQ)) bit=1;
	_delay_us(45);//45

	return bit;
}

uint8_t therm_read_byte(void)
{
	uint8_t i=8, n=0;
	while(i--) {
		//Shift one position right and store read value
		n>>=1;
		n|=(therm_read_bit()<<7);
		_delay_us(15);
	}
	return n;
}

void therm_write_byte(uint8_t byte)
{
	uint8_t i=8;
	while(i--) {
		//Write actual bit and shift one position right to make the next bit ready
		therm_write_bit(byte&1);
		byte>>=1;
	}
	_delay_us(100); //nowe
}

void therm_read_temperature(char *buffer)
{
	// Buffer length must be at least 12bytes long! ["+XXX.XXXX C"]
	uint8_t temperature[8];
	int8_t digit = 0;
	uint16_t decimal = 0;

	/*
	if( therm_reset() == 0) sprintf(buffer, "reset 1 error");
	therm_write_byte(THERM_CMD_READROM);
	_delay_ms(50);
	temperature[0]=therm_read_byte();
	temperature[1]=therm_read_byte();
	temperature[2]=therm_read_byte();
	temperature[3]=therm_read_byte();
	temperature[4]=therm_read_byte();
	temperature[5]=therm_read_byte();
	temperature[6]=therm_read_byte();
	temperature[7]=therm_read_byte();
	sprintf(buffer, "%c - %c", temperature[0] , temperature[7] );
	//sprintf(buffer, "%s", temperature);
	return;
	//*/


	//Reset, skip ROM and start temperature conversion
	if( therm_reset() == 0) sprintf(buffer, "reset 1 error");
	therm_write_byte(THERM_CMD_SKIPROM);
	therm_write_byte(THERM_CMD_CONVERTTEMP);
	//Wait until conversion is complete
	//_delay_ms(750);
	while(!therm_read_bit());

	//Reset, skip ROM and send command to read Scratchpad
	if( therm_reset() == 0) sprintf(buffer, "reset 2 error");
	therm_write_byte(THERM_CMD_SKIPROM);
	therm_write_byte(THERM_CMD_RSCRATCHPAD);
	//Read Scratchpad (only 2 first bytes)
	temperature[0]=therm_read_byte();
	temperature[1]=therm_read_byte();

	if( therm_reset() == 0) sprintf(buffer, "reset 3 error");
	
	digit|=(temperature[1]&0x7)<<4;
	//Store decimal digits
	decimal=temperature[0]&0xf;
	decimal*=THERM_DECIMAL_STEPS_12BIT;
	//Format temperature into a string [+XXX.XXXX C]
	sprintf(buffer, "%+d.%04u C", digit, decimal);
}

	


///////



//-- onewire
#define ONEWIRE_PIN PB2 
#define ONEWIRE_PORT PINB 
#define ONEWIRE_DDR DDRB

uint8_t onewire_reset() { 
	ONEWIRE_DDR |= (1<<ONEWIRE_PIN); 
	_delay_us(480); 
	ONEWIRE_DDR &= ~(1<<ONEWIRE_PIN); 
	_delay_us(70); 
	uint8_t ret = ~(ONEWIRE_PORT & (1<<ONEWIRE_PIN)); 
	_delay_us(410); 
	return ret; 
} 

void _onewire_write_bit(uint8_t value) { 
	uint8_t sreg = SREG; 
	cli(); 
	ONEWIRE_DDR |= (1<<ONEWIRE_PIN); 
	_delay_us(1); 
	if(value) 
	{ 
		ONEWIRE_DDR &= ~(1<<ONEWIRE_PIN); 
		_delay_us(59); 
	} 
	else 
	{ 
		_delay_us(59); 
		ONEWIRE_DDR &= ~(1<<ONEWIRE_PIN); 
	} 
	SREG = sreg; 
	_delay_us(30); 
} 

uint8_t _onewire_read_bit() { 
	uint8_t sreg = SREG; 
	cli(); 
	ONEWIRE_DDR |= (1<<ONEWIRE_PIN); 
	_delay_us(1); 
	ONEWIRE_DDR &= ~(1<<ONEWIRE_PIN); 
	_delay_us(15); 
	uint8_t ret = ONEWIRE_PORT & (1<<ONEWIRE_PIN); 
	SREG = sreg; 
	_delay_us(75); 
	return ret; 
} 

void onewire_write_byte(uint8_t value) { 
	uint8_t i;
	for(i = 0; i < 8; i++) 
	{ 
		_onewire_write_bit(value & 0x01); 
		value = value >> 1; 
	} 
} 

uint8_t onewire_read_byte() { 
	uint8_t ret = 0; 
	uint8_t i;
	for(i = 0; i < 8; i++) 
	{ 
		ret = ret >> 1; 
		if(_onewire_read_bit()) ret |= 0x80; 
	} 
	return ret; 
} 

//-- onewire

