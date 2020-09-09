#ifndef GPIO_H_
#define GPIO_H_

typedef enum
{
	PORT_A, 
	PORT_B,
	PORT_C,
	PORT_D	
}tPORT;

typedef enum
{
	GPIO_IN = 0,
	GPIO_OUT = 1	
}tDirection;

void gpio_InitPort(tPORT port, tDirection initial_direction);
void gpio_InitPortPin(tPORT port, unsigned char pin, tDirection initial_direction);
void gpio_update(void);
void gpio_setPort(tPORT port, unsigned char state);
void gpio_setPortPin(tPORT port, unsigned char pin, unsigned char state);
unsigned char gpio_getPortPin(tPORT port, unsigned char pin);
#endif