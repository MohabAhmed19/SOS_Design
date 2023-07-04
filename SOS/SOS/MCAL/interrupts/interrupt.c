/*
 * interrupt.c
 *
 * Created: 4/10/2023 12:07:40 AM
 *  Author: Mohab
 */ 

#include "interrupts.h"
#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/bit_manipulation.h"

uint8_t ex_int_init(uint8_t ex_int_number, uint8_t ex_int_mode)
{
	uint8_t error=0;
	set_bit(SREG,7);
	if(ex_int_number == Interrupt_0)
	{
		switch(ex_int_mode)
		{
			case low_level:
				clear_bit(MCUCR,0);
				clear_bit(MCUCR,1);
				break;
			case any_logical_change:
				set_bit(MCUCR,0);
				clear_bit(MCUCR,1);
				break;
			case falling_edge:
				clear_bit(MCUCR,0);
				set_bit(MCUCR,1);
				break;
			case rising_edge:
				set_bit(MCUCR,0);
				set_bit(MCUCR,1);
				break;
			default:
				error=1;
		}
		set_bit(GICR,6);
	}
	else if(ex_int_number == Interrupt_1)
	{
		switch(ex_int_mode)
		{
			case low_level:
			clear_bit(MCUCR,2);
			clear_bit(MCUCR,3);
			break;
			case any_logical_change:
			set_bit(MCUCR,2);
			clear_bit(MCUCR,3);
			break;
			case falling_edge:
			clear_bit(MCUCR,2);
			set_bit(MCUCR,3);
			break;
			case rising_edge:
			set_bit(MCUCR,2);
			set_bit(MCUCR,3);
			break;
			default:
			error=1;
		}
		set_bit(GICR,7);
	}
	else if(ex_int_number == Interrupt_2)
	{
		switch(ex_int_mode)
		{
			case falling_edge:
				clear_bit(MCUCSR,6);
				break;
			case rising_edge:
				set_bit(MCUCSR,6);
				break;
			default:
				error=1;
		}
		set_bit(GICR,5);
	}
	else
	{
		error=1;
	}
	return error;
}
