/*
 * APP.c
 *
 * Created: 6/1/2023 6:38:33 PM
 *  Author: mohab
 */ 

#include "APP.h"
#include "../HAL/led/LED.h"
#include "../HAL/push_button/Push_bottun.h"
#include "../SERVICE/SOS/SOS.h"

void toggle_led_300(void)
{
	LED_toggle(DIO_PORTB, DIO_PIN3);
}

void toggle_led_500(void)
{
	LED_toggle(DIO_PORTB, DIO_PIN4);
}

void (*ptr_func_task_define[10]) (void) = {toggle_led_300, toggle_led_500};

//void (*ptr_func_task_define[1]) (void) = toggle_led_500;

//ptr_func_task_define[0]=toggle_led_300;

//ptr_func_task_define[1]=toggle_led_500;



void APP_init(void)
{
	sos_init();
	sos_create_task(0, 1, 300);
	sos_create_task(1, 2, 500);
}

void APP(void)
{
	sos_run();	
}