/***********************************************************************************/
/* Author    : Mustafa Mohammed Abdou                                              */
/* Date      : 26 Feb 2020                                                         */
/* Version   : V01                                                                 */
/* Hint      : typef for standard types                                            */
/***********************************************************************************/

/* HEADER FILE GUARD */
#ifndef STANDARD_TYPES_H
#define STANDARD_TYPES_H

#define nullPtr ((void*)0)

typedef unsigned char uint8_t;          /* 1-BYTE UNSIGNED DATA (0 - 255)                */
typedef signed char   sint8_t;          /* 1-BYTE SIGNED DATA   (0 - 127) or (-1 - -128) */

typedef unsigned short int  uint16_t;   /* 2-BYTES UNSIGNED DATA   */
typedef signed short int    sint16_t;   /* 2-BYTES SIGNED DATA     */

typedef unsigned long int  uint32_t;     /* 4-BYTES UNSIGNED DATA  */
typedef signed long int    sint32_t;     /* 4-BYTES SIGNED DATA    */


typedef float  float32;                 /* 4-BYTES FLOATING DATA */
typedef double double64;                /* 8-BYTES FLOATING DATA */

/*typedef enum err_state
{
	SUCCESS,FAIL
}err_state;*/
typedef enum pin_dir
{
	INPUT,OUTPUT
}pin_dir;

typedef enum pin_state
{
	LOW,HIGH
}pin_state;

/***** MACRO FOR EACH PORT ACTS AS PORT ID  ***********/
#define DIO_PORTA         0
#define DIO_PORTB         1
#define DIO_PORTC         2
#define DIO_PORTD         3


/*********** MACRO FOR EACH PIN ACTS AS PIN ID **********/
#define DIO_PIN0          0
#define DIO_PIN1          1
#define DIO_PIN2          2
#define DIO_PIN3          3
#define DIO_PIN4          4
#define DIO_PIN5          5
#define DIO_PIN6          6
#define DIO_PIN7          7

/********** MACROS FOR PIN DIRECTIONS ******************/
#define DIO_PIN_OUTPUT    1
#define DIO_PIN_INPUT     0

/********** MACROS FOR PORT DIRECTIONS *****************/
#define DIO_PORT_OUTPUT   0xFF
#define DIO_PORT_INPUT    0x00


/********* MACROS FOR OUTPUT PIN VALUES ***************/
#define DIO_PIN_HIGH      1
#define DIO_PIN_LOW       0


/*********** MACROS FOR OUTPUT PORT DIRECTIONS *********/
#define DIO_PORT_HIGH     0xFF
#define DIO_PORT_LOW      0x00

#endif /* STANDARD_TYPES_H */
