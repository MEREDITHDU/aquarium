//
//wszystkie funkcje s¹ typu 'return int'
//b8-b15 s¹ bitami b³êdu, 0 - brak b³êdu, inna wartoœæ - kod b³êdu wg. TWI
//b0-b7  zwraca wartoœæ funkcji, jeœli jest wymagana
//

#include <util/twi.h>
#include <util/delay.h>

#define SLA_W 0xa2
#define SLA_R 0xa3

#define PCF_ST_CNT_FL _BV(7)
#define PCF_ERR_MSK 0xff00

#define PCF_CTRL 0x00
#define PCF_MILI 0x01
#define PCF_SEC 0x02
#define PCF_MIN 0x03
#define PCF_HOUR 0x04
#define PCF_DAY 0x05
#define PCF_YEAR 0x05
#define PCF_MONTH 0x06
#define PCF_YEAR_BCD 0x10

unsigned int PCF_Write(unsigned char adr, unsigned char dat);
unsigned int PCF_Read(unsigned char adr);
unsigned int PCF_Start(void);
unsigned int PCF_Stop(void);
unsigned int PCF_Read_Mili(void);
unsigned int PCF_Read_Sec(void);
unsigned int PCF_Read_Min(void);
unsigned int PCF_Read_Hour(void);
unsigned int PCF_Read_Day(void);
unsigned int PCF_Read_Month(void);
unsigned int PCF_Read_Year(void);
unsigned int PCF_Set_Mili(unsigned char a);
unsigned int PCF_Set_Sec(unsigned char a);
unsigned int PCF_Set_Min(unsigned char a);
unsigned int PCF_Set_Hour(unsigned char a);
unsigned int PCF_Set_Day(unsigned char a);
unsigned int PCF_Set_Month(unsigned char a);
unsigned int PCF_Set_Year(unsigned int a);
