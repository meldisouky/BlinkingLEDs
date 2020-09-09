#include <avr/io.h>
#include <avr/delay.h>
#include "led.h"
#include "gpio.h"

#define F_CPU (12000000)
#define DELAY_DURATION (200)
void led_Toggle(tLED led);
void led_flasing(tLED led);

void led_Init(tLED led, tLED_State initial_state)
{
	/** Initialize Hardware **/
	switch(led)
	{
		case LED_1 : gpio_InitPortPin(PORT_B, 0, GPIO_OUT);break;
		case LED_2 : gpio_InitPortPin(PORT_B, 1, GPIO_OUT);break;
		case LED_3 : gpio_InitPortPin(PORT_B, 2, GPIO_OUT);break;
		case LED_4 : gpio_InitPortPin(PORT_B, 3, GPIO_OUT);break;
		case LED_5 : gpio_InitPortPin(PORT_B, 4, GPIO_OUT);break;
		case LED_6 : gpio_InitPortPin(PORT_B, 5, GPIO_OUT);break;
		case LED_7 : gpio_InitPortPin(PORT_B, 6, GPIO_OUT);break;
		case LED_8 : gpio_InitPortPin(PORT_B, 7, GPIO_OUT);break;
		default: /** should do no thing **/ break;
	}

	/** Initialize Data **/
	led_setState(led, initial_state);
}

void led_Update(void)
{
	led_Toggle(LED_1);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_2);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_3);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_4);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_5);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_6);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_7);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_8);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_8);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_7);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_6);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_5);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_4);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_3);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_2);
	_delay_ms(DELAY_DURATION);
	led_Toggle(LED_1);
	_delay_ms(DELAY_DURATION);
	led_flasing(LED_2);
	led_flasing(LED_4);
	led_flasing(LED_6);
	led_flasing(LED_8);
	led_flasing(LED_1);
	led_flasing(LED_3);
	led_flasing(LED_5);
	led_flasing(LED_7);

}

void led_setState(tLED led, tLED_State state)
{
	switch(led)
	{
		case LED_1: gpio_setPortPin(PORT_B, 0, state);break;
		case LED_2: gpio_setPortPin(PORT_B, 1, state);break;
		case LED_3: gpio_setPortPin(PORT_B, 2, state);break;
		case LED_4: gpio_setPortPin(PORT_B, 3, state);break;
		case LED_5: gpio_setPortPin(PORT_B, 4, state);break;
		case LED_6: gpio_setPortPin(PORT_B, 5, state);break;
		case LED_7: gpio_setPortPin(PORT_B, 6, state);break;
		case LED_8: gpio_setPortPin(PORT_B, 7, state);break;
		default: /** should do no thing **/ break;
	}
}

tLED_State led_getState(tLED led)
{
	tLED_State returned_value = LED_OFF;
	switch(led)
	{
		case LED_1: returned_value = gpio_getPortPin(PORT_B, 0);break;
		case LED_2: returned_value = gpio_getPortPin(PORT_B, 1);break;
		case LED_3: returned_value = gpio_getPortPin(PORT_B, 2);break;
		case LED_4: returned_value = gpio_getPortPin(PORT_B, 3);break;
		case LED_5: returned_value = gpio_getPortPin(PORT_B, 4);break;
		case LED_6: returned_value = gpio_getPortPin(PORT_B, 5);break;
		case LED_7: returned_value = gpio_getPortPin(PORT_B, 6);break;
		case LED_8: returned_value = gpio_getPortPin(PORT_B, 7);break;
		default: /** should do no thing **/ break;
	}
	return returned_value;
}

void led_Toggle(tLED led)
{
	tLED_State led_state = led_getState(led);
	if (led_state == LED_ON)
	{
		led_setState(led, LED_OFF);
	}
	else
	{
		led_setState(led, LED_ON);
	}
}

void led_flasing(tLED led)
{
	led_setState(led, LED_ON);
	_delay_ms(DELAY_DURATION);
	led_setState(led, LED_OFF);
	_delay_ms(100);
	led_setState(led, LED_ON);
	_delay_ms(100);
	led_setState(led, LED_OFF);
	_delay_ms(100);
	led_setState(led, LED_ON);
	_delay_ms(100);
}
