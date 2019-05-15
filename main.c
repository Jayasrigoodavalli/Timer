/*
 * GccApplication2.c
 *
 * Created: 15-May-19 10:31:49 AM
 * Author : JAYASREE
 */ 

#include <avr/io.h>
#define LED PB4


int main(void)
{
	uint8_t timerOverflowCount=0;
	DDRB=0XFF;//Configure PORTB as o/p
	TCNT0=0X00;;
	TCCR0=(1<<CS00)|(1<<CS02);
    /* Replace with your application code */
    while (1) 
    {
		while((TIFR&0X01)==0);
		TCNT0=0X00;
		TIFR=0X01;//Clear timer1 overflow flag
		timerOverflowCount++;
		if(timerOverflowCount>=5)
		{
			PORTB^=(0X01<<LED);             
			timerOverflowCount=0;
		}
    }
}

