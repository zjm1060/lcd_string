/*
 * gpio.c
 *
 *  Created on: 2017Äê8ÔÂ2ÈÕ
 *      Author: zjm09
 */
#include "includes.h"

#include "gpio.h"

struct _gpio_file_name{
	int pin;
	int dir;
	int fd;
}gpio_file_name[] = {
		[GPIO_LCD_A0] = {
				.pin = PORT2PIN(PA,6),
				.dir = 1,
		},
		[GPIO_LCD_RES] = {
				.pin = PORT2PIN(PA,5),
				.dir = 1,
		},
		[GPIO_LCD_BLK] = {
				.pin = PORT2PIN(PA,4),
				.dir = 1,
		},
};

void export_gpio(int pin,int *fd)
{
	char cmd[512];

	snprintf(cmd,sizeof(cmd),"/sys/class/gpio/gpio%d/value",pin);
	if(!access(cmd,F_OK))
		goto op;

	snprintf(cmd,sizeof(cmd),"echo %d > /sys/class/gpio/export",pin);
	system(cmd);

	snprintf(cmd,sizeof(cmd),"/sys/class/gpio/gpio%d/value",pin);

	op:
	*fd = open(cmd,O_RDWR);
	if(*fd < 0){
		perror("gpio");
		exit(1);
	}
}

void set_gpio_direction(int pin,int dir)
{
	char cmd[512];
	snprintf(cmd,sizeof(cmd),"echo %s > /sys/class/gpio/gpio%d/direction",dir?"out":"in",pin);
	system(cmd);
}

void set_gpio(int pin,int v)
{

}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))
void gpio_init(void)
{
	for (int i = 0; i < ARRAY_SIZE(gpio_file_name); ++i) {
		export_gpio(gpio_file_name[i].pin,&gpio_file_name[i].fd);
		set_gpio_direction(gpio_file_name[i].pin,gpio_file_name[i].dir);
	}
}

void gpio_set(int fun,int v)
{
	if(v)
		write(gpio_file_name[fun].fd,"\x31",1);
	else
		write(gpio_file_name[fun].fd,"\x30",1);
}

int gpio_get(int fun)
{
	char c;

	lseek(gpio_file_name[fun].fd,0,SEEK_SET);
	int n = read(gpio_file_name[fun].fd,&c,1);

	return c=='0'?0:1;
}
