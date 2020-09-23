/*
 * jelly.c
 *
 * Created: 12/13/2019 5:31:31 PM
 * Author : mihir
 */ 

#define F_CPU 8000000UL
#include "init.h"
#include <util/delay.h>

int main(void)
{
 unsigned char input;
 /* Replace with your application code */
 init();
 while (1)
 {
	 input =UART_RxChar();
	 //all motors on
	 if(input == 'a')
	 {
		 setpin(PORTD, 5);
		 setpin(PORTD, 6);
		 setpin(PORTD, 7);
		 _delay_ms(500);
	 }
	 //motor 1 and 2 on
	 else if(input == 'b')
	 {
		 setpin(PORTD, 5);
		 setpin(PORTD, 6);
		 clearpin(PORTD, 7);
		 _delay_ms(500);
	 }
	 //motor 2 and 3 on
	 else if(input == 'c')
	 {
		 setpin(PORTD, 6);
		 setpin(PORTD, 7);
		 clearpin(PORTD, 5);
		 _delay_ms(500);
	 }
	 //motor 1 and 3 on
	 else if(input == 'd')
	 {
		 setpin(PORTD, 5);
		 setpin(PORTD, 7);
		 clearpin(PORTD, 6);
		 _delay_ms(500);
	 }
	 //all motors off
	 else
	 {
		 clearpin(PORTD, 5);
		 clearpin(PORTD, 6);
		 clearpin(PORTD, 7);
		 _delay_ms(500);
	 }
	 
 }
}

