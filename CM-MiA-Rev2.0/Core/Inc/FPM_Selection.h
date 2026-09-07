/*
 * FPM_Selection.h
 *
 *  Created on: Aug 11, 2026
 *      Author: user
 */

#ifndef INC_FPM_SELECTION_H_
#define INC_FPM_SELECTION_H_

#include "main.h"
#include <stdint.h>

typedef enum
{
	FPM_20 = 20,
	FPM_25 = 25,
	FPM_28 = 28,
	FPM_30 = 30,
	FPM_33 = 33,
	FPM_35 = 35,
	FPM_38 = 38,
	FPM_40 = 40
}FPM_t;

FPM_t FPM_GetSelected(void);


#endif /* INC_FPM_SELECTION_H_ */
