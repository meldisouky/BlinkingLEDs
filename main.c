/*
 */

#include <avr/io.h>
#include "led.h"

int main(void)
{
    led_Init(LED_1, LED_OFF);
    led_Init(LED_2, LED_OFF);
    led_Init(LED_3, LED_OFF);
    led_Init(LED_4, LED_OFF);
    led_Init(LED_5, LED_OFF);
    led_Init(LED_6, LED_OFF);
    led_Init(LED_7, LED_OFF);
    led_Init(LED_8, LED_OFF);

    while(1)
    {
        led_Update();
    }

    return 0;
}
