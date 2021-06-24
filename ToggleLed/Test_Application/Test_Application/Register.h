/*
 * Register.h
 *
 * Created: 6/24/2021 3:12:29 PM
 *  Author: lenovo
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

// PORT A
#define PORTA_DIR *((volatile unsigned char*)(0x3A))
#define PORTA_DATA *((volatile unsigned char*)(0x3B))
#define PINA_INPUT *((volatile unsigned char*)(0x39))

// PORT B
#define PORTB_DIR *((volatile unsigned char*)(0x37))
#define PORTB_DATA *((volatile unsigned char*)(0x38))
#define PINB_INPUT *((volatile unsigned char*)(0x36))

// PORT C
#define PORTC_DIR *((volatile unsigned char*)(0x34))
#define PORTC_DATA *((volatile unsigned char*)(0x35))
#define PINC_INPUT *((volatile unsigned char*)(0x33))

// PORT D
#define PORTD_DIR *((volatile unsigned char*)(0x31))
#define PORTD_DATA *((volatile unsigned char*)(0x32))
#define PIND_INPUT *((volatile unsigned char*)(0x30))


#endif /* REGISTER_H_ */