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
#include<linux/i2c-dev.h>
 extern int file;
#include "led_functions.h"
extern uint8_t* font_table[];
//int fd;
//struct spi_ioc_transfer trx;
//uint32_t scratch32;
int i=1; 


int main(void) {
	int looper;
	char buf[5];
	printf("Welcome to OLED Demo...\r\n");
	
	gpio_configure_for_display();
	spi_configure_for_display();
	
	display_do_init();



	///////////////////////////////////////////////////////
	
	int adapter_nr = 1; /* probably dynamically determined */
	char bus_filename[250];
	char accel_x_h,accel_x_l,accel_y_h,accel_y_l,accel_z_h,accel_z_l,temp_h,temp_l;
	uint16_t fifo_len = 0;
	int16_t x_accel = 0;
	int16_t y_accel = 0;
	int16_t z_accel = 0;
	int16_t temp = 0;
	float x_accel_g, y_accel_g, z_accel_g, temp_f;

	snprintf(bus_filename, 250, "/dev/i2c-1", adapter_nr);
	file = open(bus_filename, O_RDWR);
	if (file < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		exit(1);
	}


	if (ioctl(file, I2C_SLAVE, MPU6050_I2C_ADDR) < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		exit(1);
	}

	i2c_write(REG_PWR_MGMT_1, 0x01);
	i2c_write(REG_ACCEL_CONFIG, 0x00);
	i2c_write(REG_SMPRT_DIV, 0x07);
	i2c_write(REG_CONFIG, 0x00);
	i2c_write(REG_FIFO_EN, 0x88);
	i2c_write(REG_USER_CTRL, 0x44);

	while(fifo_len != 1025) {
		accel_x_h = i2c_read(REG_FIFO_COUNT_L);
		accel_x_l = i2c_read(REG_FIFO_COUNT_H);
		fifo_len = merge_bytes(accel_x_h,accel_x_l);

		if(fifo_len == 1025) {
			printf("fifo overflow !\n");
			i2c_write(REG_USER_CTRL, 0x44);
			continue;
		}

		if(fifo_len >= 8) {
			accel_x_h = i2c_read(REG_FIFO);
			accel_x_l = i2c_read(REG_FIFO);
			accel_y_h = i2c_read(REG_FIFO);
			accel_y_l = i2c_read(REG_FIFO);
			accel_z_h = i2c_read(REG_FIFO);
			accel_z_l = i2c_read(REG_FIFO);
			temp_h = i2c_read(REG_FIFO);

			temp_l= i2c_read(REG_FIFO);

			x_accel= two_complement_to_int(accel_x_h,accel_x_l);
			x_accel_g = ((float) x_accel)/16384;

			y_accel= two_complement_to_int(accel_y_h,accel_y_l);
			y_accel_g = ((float) y_accel)/16384;

			z_accel= two_complement_to_int(accel_z_h,accel_z_l);
			z_accel_g = ((float) z_accel)/16384;

			temp = two_complement_to_int(temp_h, temp_l);
			temp_f = (float)temp/340 + 36.53; // calculated as described in the MPU60%) register map document

			printf("x_accel %.3fg	y_accel %.3fg	z_accel %.3fg	temp=%.1fc         \r", x_accel_g, y_accel_g, z_accel_g, temp_f);
			//char *a=(char)x_accel_g,*b=(char)y_accel_g,*c=(char)z_accel_g;
	        gcvt(x_accel_g,5,buf);
 set_cursor(0,0);
 if(i==1){
i++;	
display_write_string("H E L L O   G U Y S");
set_cursor(2,0);

display_write_string("WELCOME TO MOSCHIP");
sleep(2);
display_clear();
	//	sleep(1);
 }

 set_cursor(0,0);
display_write_string("GYRO VALUE"); 

		//display_clear();

 set_cursor(1,0);
 display_write_string("x val");
 set_cursor(1,30);
		display_write_string(buf);
		usleep(300000);
		//display_clear();
	        gcvt(y_accel_g,5,buf);

 set_cursor(2,0);
 display_write_string("y val");
 set_cursor(2,30);
		display_write_string(buf);
		usleep(300000);
	//	display_clear();
	
 set_cursor(3,0);

 display_write_string("z val");
 set_cursor(3,30);
	        gcvt(z_accel_g,5,buf);
		display_write_string(buf);
		//usleep(500000);
		//display_write_string(temp_f);
		usleep(300000);

		display_clear();
		}
		else
		{
			usleep(10000);
		}

	



	}
}
