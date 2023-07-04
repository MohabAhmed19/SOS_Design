/*
 * Push_bottun.h
 *
 * Created: 4/6/2023 8:25:24 AM
 *  Author: mohab
 */ 


#ifndef PUSH_BOTTUN_H_
#define PUSH_BOTTUN_H_


#include "../../UTILITIES/bit_manipulation.h"
#include "../../UTILITIES/registers.h"
#include "../../UTILITIES/standard_types.h"
#include "../../MCAL/dio/DIO_interface.h"

#define Pressed 1
#define Not_pressed 0

uint8_t PB_init(uint8_t Port_number, uint8_t Pin_number);
uint8_t PB_state(uint8_t Port_number, uint8_t Pin_number, uint8_t *state);


#endif /* PUSH_BOTTUN_H_ */