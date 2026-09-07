/*
 * photoswitch.c
 *
 *  Created on: Aug 12, 2026
 *      Author: user
 */


#include "photoswitch.h"

#define PHOTOSWITCH_PORT    GPIOB
#define PHOTOSWITCH_PIN     GPIO_PIN_0

LightMode_t Photoswitch_GetMode(void)
{
    GPIO_PinState pinState = HAL_GPIO_ReadPin(PHOTOSWITCH_PORT, PHOTOSWITCH_PIN);

    if (pinState == GPIO_PIN_SET)
    {
        return LIGHT_MODE_NIGHT;
    }
    else
    {
    return LIGHT_MODE_DAY;
    }
}

bool Photoswitch_IsNight(void)
{
	 return (Photoswitch_GetMode() == LIGHT_MODE_NIGHT);
}
