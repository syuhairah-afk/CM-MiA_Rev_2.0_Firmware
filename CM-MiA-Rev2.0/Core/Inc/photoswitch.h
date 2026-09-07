/*
 * photoswitch.h
 *
 *  Created on: Aug 12, 2026
 *      Author: user
 */

#ifndef INC_PHOTOSWITCH_H_
#define INC_PHOTOSWITCH_H_

#include "main.h"
#include <stdbool.h>

typedef enum
{
    LIGHT_MODE_DAY = 0,
    LIGHT_MODE_NIGHT = 1
} LightMode_t;

LightMode_t Photoswitch_GetMode(void);
bool Photoswitch_IsNight(void);


#endif /* INC_PHOTOSWITCH_H_ */
