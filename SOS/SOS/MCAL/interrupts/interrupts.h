/*
 * interrupts.h
 *
 * Created: 4/7/2023 12:23:35 AM
 *  Author: Omar Taha
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/bit_manipulation.h"

#define low_level 3
#define any_logical_change 4
#define falling_edge 5
#define rising_edge 6

#define Interrupt_0 0
#define Interrupt_1 1
#define Interrupt_2 2

uint8_t ex_int_init(uint8_t ex_int_number, uint8_t ex_int_mode);

/************************************************************************/
/* External Interrupts                                                  */
/************************************************************************/
#define EXT_INT_0	__vector_1
#define EXT_INT_1	__vector_2
#define EXT_INT_2	__vector_3
#define TIMER0_OVF	__vector_11
#define TIMER2_OVF	__vector_5

//ISR function macro
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)



/************************************************************************/
/* Timer 0 Interrupts                                                   */
/************************************************************************/
/*#define TIMER0_OVF_INT __vector_11*/



#endif /* INTERRUPTS_H_ */