#include <avr/io.h>
#include "gpio.h"

#define SET_REGISTER_BIT(REG, BIT, VAL) ((REG) = (((REG) & (~(1 << (BIT)))) | ((VAL) << (BIT))))
#define GET_REGISTER_BIT(REG, BIT) (((REG) & (1 << (BIT))) >> (BIT))

void gpio_InitPort(tPORT port, tDirection initial_direction)
{
	unsigned char pin = 0;
	for(pin = 0; pin < 8; pin++)
	{
		gpio_InitPortPin(port, pin, initial_direction);
	}
}

void gpio_InitPortPin(tPORT port, unsigned char pin, tDirection initial_direction)
{
	/** Initialize Hardware **/
	switch(port)
	{
		case PORT_A: SET_REGISTER_BIT(DDRA, pin, initial_direction);break;
		case PORT_B: SET_REGISTER_BIT(DDRB, pin, initial_direction);break;
		case PORT_C: SET_REGISTER_BIT(DDRC, pin, initial_direction);break;
		case PORT_D: SET_REGISTER_BIT(DDRD, pin, initial_direction);break;
		default: /* should do no thing */ break;
	}
}

void gpio_update(void){}

void gpio_setPort(tPORT port, unsigned char state)
{
	unsigned char pin = 0;
	for(pin = 0; pin < 8; pin++)
	{
		gpio_setPortPin(port, pin, state);
	}
}

void gpio_setPortPin(tPORT port, unsigned char pin, unsigned char state)
{
	switch(port)
	{
		case PORT_A: SET_REGISTER_BIT(PORTA, pin, state);break;
		case PORT_B: SET_REGISTER_BIT(PORTB, pin, state);break;
		case PORT_C: SET_REGISTER_BIT(PORTC, pin, state);break;
		case PORT_D: SET_REGISTER_BIT(PORTD, pin, state);break;
		default: /* should do no thing **/ break;
	}
}

unsigned char gpio_getPortPin(tPORT port, unsigned char pin)
{
	unsigned char returned_value = 0 ;

	switch(port)
	{
		case PORT_A: returned_value = GET_REGISTER_BIT(PINA, pin);break;
		case PORT_B: returned_value = GET_REGISTER_BIT(PINB, pin);break;
		case PORT_C: returned_value = GET_REGISTER_BIT(PINC, pin);break;
		case PORT_D: returned_value = GET_REGISTER_BIT(PIND, pin);break;
		default: /* should do no thing */ break;
	}

	return 	returned_value;
}
