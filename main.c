/*
 * main.c
 *
 *  Created on: 2020Äê9ÔÂ16ÈÕ
 *      Author: zjm09
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gpio.h"
#include "lcd.h"

int main(int argc,char *argv[])
{
	char tmp_string[1024];
	gpio_init();
	Init_LCD();

	memset(tmp_string, 0, sizeof(tmp_string));

	if(argc == 2){
		strncpy(tmp_string, argv[1], sizeof(tmp_string));
	}else{
		fread(tmp_string, 1, sizeof(tmp_string), stdin);
	}

	LCD_Clear();
	lcd_printf(0, 0, tmp_string);
	LCD_Refresh();

	return 0;
}



