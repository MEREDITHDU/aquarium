#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/boot.h>

#define ADDRESS     0x0e00UL

#define boot_word_read()	0

void BOOTLOADER_SECTION bootloader(void)
{
  unsigned long address;
  unsigned short boot_word;
//  unsigned char buffer[8];

  cli();

  // Erase page.
  boot_page_erase((unsigned long)ADDRESS);
  while(boot_rww_busy())
  {
    boot_rww_enable();
  }

  // Write data to buffer a word at a time. Note incrementing address by 2.
  // SPM_PAGESIZE is defined in the microprocessor IO header file.
  for(address = ADDRESS; address < ADDRESS + SPM_PAGESIZE; address += 2)
  {
    boot_word=boot_word_read();
    boot_page_fill(address, boot_word);
  }

  // Write page.
  boot_page_write((unsigned long)ADDRESS);
  while(boot_rww_busy())
  {
    boot_rww_enable();
  }

  sei();

  // Read back the values and display.
  // (The show() function is undefined and is used here as an example only.)
  // for(unsigned long i = ADDRESS; i < ADDRESS + 256; i++)
  // {
  //   show(utoa(pgm_read_byte(i), buffer, 16));
  // }
}

int main(void)
{
  bootloader();
  while(1);
}
