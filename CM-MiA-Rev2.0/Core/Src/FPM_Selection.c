/*
 * FPM_Selection.c
 *
 *  Created on: Aug 11, 2026
 *      Author: user
 */


#include "FPM_Selection.h"

#define DIP1_GPIO_Port 	GPIOA
#define DIP1_Pin 		GPIO_PIN_0

#define DIP2_GPIO_Port	GPIOB
#define DIP2_Pin		GPIO_PIN_5

#define DIP3_GPIO_Port	GPIOC
#define DIP3_Pin		GPIO_PIN_13


static const FPM_t FpmTable[8] =
{
		FPM_20,
		FPM_25,
		FPM_28,
		FPM_30,
		FPM_33,
		FPM_35,
		FPM_38,
		FPM_40
};

FPM_t FPM_GetSelected(void)
{
	uint8_t index = 0;

	index |= HAL_GPIO_ReadPin(DIP1_GPIO_Port, DIP1_Pin)<<0;
	index |= HAL_GPIO_ReadPin(DIP2_GPIO_Port, DIP2_Pin)<<1;
	index |= HAL_GPIO_ReadPin(DIP3_GPIO_Port, DIP3_Pin)<<2;

	return FpmTable[index];

}
