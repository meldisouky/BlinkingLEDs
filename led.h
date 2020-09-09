#ifndef _LED_H_
#define _LED_H_

typedef enum 
{
	LED_1, 
	LED_2, 
	LED_3, 
	LED_4, 
	LED_5, 
	LED_6,
	LED_7, 
	LED_8
}tLED;

typedef enum
{
	LED_OFF = 0, 
	LED_ON = 1
}tLED_State;

void led_Init(tLED led, tLED_State initial_state);
void led_Update(void);
void led_setState(tLED led, tLED_State state);
tLED_State led_getState(tLED led);
#endif