
#ifndef __TEMP
#define __TEMP

#include "config.h"
#include "usb.h"

#define LOOP_CYCLES 8 				//Number of cycles that the loop takes
#define us(num) (num/(LOOP_CYCLES*(1/(F_CPU/1000000.0))))

/* Utils 
#define TEMP_INPUT_MODE() TEMP_DDR&=~(1<<temp_selected_dq)
#define TEMP_OUTPUT_MODE() TEMP_DDR|=(1<<temp_selected_dq)
#define TEMP_LOW() TEMP_PORT&=~(1<<temp_selected_dq)
#define TEMP_HIGH() TEMP_PORT|=(1<<temp_selected_dq)
*/

int8_t temp_selected_dq;

/* List of these commands translated into C defines */
#define TEMP_CMD_CONVERTTEMP 0x44
#define TEMP_CMD_RSCRATCHPAD 0xbe
#define TEMP_CMD_WSCRATCHPAD 0x4e
#define TEMP_CMD_CPYSCRATCHPAD 0x48
#define TEMP_CMD_RECEEPROM 0xb8
#define TEMP_CMD_RPWRSUPPLY 0xb4
#define TEMP_CMD_SEARCHROM 0xf0
#define TEMP_CMD_READROM 0x33
#define TEMP_CMD_MATCHROM 0x55
#define TEMP_CMD_SKIPROM 0xcc
#define TEMP_CMD_ALARMSEARCH 0xec

/* Constants */
#define TEMP_DECIMAL_STEPS_12BIT 625 //.0625


void temp_input_mode() ;
void temp_output_mode();
void temp_low_state()  ;
void temp_high_state() ;

void 	temp_delay(uint16_t delay);
uint8_t temp_reset();
void 	temp_write_bit(uint8_t bit);
uint8_t temp_read_bit(void);
uint8_t temp_read_byte(void);
void 	temp_write_byte(uint8_t byte);

void temp_set_device(int8_t devicenum);

void temp_read( int8_t device, char *buffer);
void temp_read2(int8_t device, int8_t *digi, uint16_t *deci);



#endif
