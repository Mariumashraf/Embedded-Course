/*
 * Test_Application.c
 *
 * Created: 6/24/2021 2:28:22 PM
 * Author : lenovo
 */ 

//#include <avr/io.h>
#include "Register.h"
//#include "delay.h"


int main(void)
{
   // PORTA_DIR = 0x01; //Initialization
	
	//DDRA = 0x01;
	//PORTA = 0x01;
	PORTA_DIR = 0x01;
	PORTC_DIR = 0x00;
	PORTC_DATA = 0x01;
	
    while (1) 
    {
		
		PORTA_DATA = PINC_INPUT;
		
		/*if(PINC_INPUT == 1){
		PORTA_DATA = 0x01;
		_delay_ms(3000);
		PORTA_DATA = 0x00;
		}*/
    }
}

