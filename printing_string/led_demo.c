#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <linux/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>


#include "led_functions.h"
extern uint8_t* font_table[];
//int fd;
//struct spi_ioc_transfer trx;
//uint32_t scratch32;
 


int main(void) {
	int looper;
	printf("Welcome to OLED Demo...\r\n");
	
	gpio_configure_for_display();
	spi_configure_for_display();
	
	display_do_init();
	
	for(looper=0; looper<10; ++looper) {
		display_write_string("Hi am Anand");
		usleep(500000);
		display_clear();

		display_write_string("Welcome to moschip");
		usleep(500000);
		display_clear();

	}
	
	return 0;
}
