/*
 * SOS.c
 *
 * Created: 6/1/2023 3:23:20 PM
 *  Author: mohab
 */ 
#include "SOS.h"
#include "../../UTILITIES/bit_manipulation.h"
#include "../../UTILITIES/standard_types.h"
#include "../../UTILITIES/registers.h"
#include "../../MCAL/interrupts/interrupts.h"


static str_sos_task_t* task[10];



static int OVF=0;

static uint8_t state=0;

enu_system_status_t sos_init()
{
	LED_init(DIO_PORTB ,DIO_PIN3);
	LED_init(DIO_PORTB ,DIO_PIN4);
	PB_init(DIO_PORTC, DIO_PIN4);
	PB_init(DIO_PORTB, DIO_PIN2);
	TMR0_init();
	ex_int_init( EXT_INT_2, rising_edge);
}

enu_creat_status_t sos_create_task(uint8_t ar_task_ID, uint8_t ar_task_priorty, uint8_t ar_task_priodicity)
{
	task[ar_task_ID]->task_ID = ar_task_ID;
	task[ar_task_ID]->task_priodicity = ar_task_priodicity;
	task[ar_task_ID]->task_priority = ar_task_priorty;
	task[ar_task_ID]->ptr_func_task = *ptr_func_task_define[ar_task_ID];
}

enu_delete_status_t sos_delete_task(uint8_t ar_task_ID)
{
	task[ar_task_ID]->ptr_func_task = '\0';
}

enu_modify_status_t sos_modify_task(uint8_t ar_task_ID, uint8_t ar_task_priorty, uint8_t ar_task_priodicity)
{
	task[ar_task_ID]->task_ID = ar_task_ID;
	task[ar_task_ID]->task_priodicity = ar_task_priodicity;
	task[ar_task_ID]->task_priority = ar_task_priorty;
}

void sos_run(void)
{
	TMR0_start();
	while(1)
	{
		PB_state(DIO_PORTC, DIO_PIN4, &state);
		if(state==1)
		{
			while(1)
			{
				if((OVF%(3125*3))==0)
				{
					task[0]->ptr_func_task();
				}
				if((OVF%(3125*5))==0)
				{
					task[1]->ptr_func_task();
				}
				if(state==0)
				{
					break;
				}
			}
		}
	}
}


ISR(TIMER0_OVF)
{
	OVF++;
}


ISR(EXT_INT_2)
{
	PB_state(DIO_PORTC, DIO_PIN4, &state);
}