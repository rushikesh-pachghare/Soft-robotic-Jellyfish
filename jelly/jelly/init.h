/*
 * init.h
 *
 * Created: 12/13/2019 5:32:28 PM
 *  Author: mihir
 */ 


#ifndef INIT_H_
#define INIT_H_

#include <avr/io.h>

#define checkpin(reg,pin)((reg & (1<<pin)) ? 1:0)
#define setpin(reg,pin) (reg |=(1<<(pin)))
#define clearpin(reg,pin) (reg &= ~(1<<(pin)))
// Standard Input/Output functions
#include <stdio.h>

// Declare your global variables here

void init(void)
{
	// Declare your local variables here

	// Input/Output Ports initialization
	// Port B initialization
	// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
	// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T
	PORTB=0x00;
	DDRB=0x00;

	// Port C initialization
	// Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In
	// State6=T State5=T State4=T State3=T State2=T State1=T State0=T
	PORTC=0x00;
	DDRC=0x00;

	// Port D initialization
	// Func7=Out Func6=Out Func5=Out Func4=In Func3=In Func2=In Func1=In Func0=In
	// State7=0 State6=0 State5=0 State4=T State3=T State2=T State1=T State0=T
	PORTD=0x00;
	DDRD=0xE0;

	// Timer/Counter 0 initialization
	// Clock source: System Clock
	// Clock value: Timer 0 Stopped
	TCCR0=0x00;
	TCNT0=0x00;

	// Timer/Counter 1 initialization
	// Clock source: System Clock
	// Clock value: Timer1 Stopped
	// Mode: Normal top=0xFFFF
	// OC1A output: Discon.
	// OC1B output: Discon.
	// Noise Canceler: Off
	// Input Capture on Falling Edge
	// Timer1 Overflow Interrupt: Off
	// Input Capture Interrupt: Off
	// Compare A Match Interrupt: Off
	// Compare B Match Interrupt: Off
	TCCR1A=0x00;
	TCCR1B=0x00;
	TCNT1H=0x00;
	TCNT1L=0x00;
	ICR1H=0x00;
	ICR1L=0x00;
	OCR1AH=0x00;
	OCR1AL=0x00;
	OCR1BH=0x00;
	OCR1BL=0x00;

	// Timer/Counter 2 initialization
	// Clock source: System Clock
	// Clock value: Timer2 Stopped
	// Mode: Normal top=0xFF
	// OC2 output: Disconnected
	ASSR=0x00;
	TCCR2=0x00;
	TCNT2=0x00;
	OCR2=0x00;

	// External Interrupt(s) initialization
	// INT0: Off
	// INT1: Off
	MCUCR=0x00;

	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK=0x00;

	// USART initialization
	// Communication Parameters: 8 Data, 1 Stop, No Parity
	// USART Receiver: On
	// USART Transmitter: Off
	// USART Mode: Asynchronous
	// USART Baud Rate: 9600
	UCSRA=0x00;
	UCSRB=0x10;
	UCSRC=0x86;
	UBRRH=0x00;
	UBRRL=0x33;

	// Analog Comparator initialization
	// Analog Comparator: Off
	// Analog Comparator Input Capture by Timer/Counter 1: Off
	ACSR=0x80;
	SFIOR=0x00;

	// ADC initialization
	// ADC disabled
	ADCSRA=0x00;

	// SPI initialization
	// SPI disabled
	SPCR=0x00;

	// TWI initialization
	// TWI disabled
	TWCR=0x00;


}
void UART_TxChar(char ch)
{
	while (! (UCSRA & (1<<UDRE)));  /* Wait for empty transmit buffer */
	UDR = ch ;
}
unsigned char UART_RxChar()
{
	while ((UCSRA & (1 << RXC)) == 0);/* Wait till data is received */
	return(UDR);		/* Return the byte */
}



#endif /* INIT_H_ */