#include "FlashController.h"
#include "FPM_Selection.h"
#include "photoswitch.h"

#define FLASH_ON_TIME_MS    200

typedef enum
{
    FLASH_OFF_STATE,
    FLASH_ON_STATE
} FlashState_t;

static FlashState_t FlashState = FLASH_OFF_STATE;
static uint32_t LastTick = 0;
static uint32_t FlashPeriod = 3000;
static uint8_t CurrentFpm = 0;

void FlashController_Init(void)
{
    FPM_t fpm = FPM_GetSelected();
    CurrentFpm = (uint8_t)fpm;

    FlashPeriod = 60000UL / (uint32_t)fpm;
    FlashState = FLASH_OFF_STATE;
    LastTick = HAL_GetTick();

    /* Turn off LED initially */
    HAL_GPIO_WritePin(FPM_Indicator_MiA_GPIO_Port, FPM_Indicator_MiA_Pin, GPIO_PIN_RESET);
}

void FlashController_Task(void)
{
    uint32_t now = HAL_GetTick();

    /* DAY MODE: If it's daytime, turn off LED and exit */
    if (!Photoswitch_IsNight())
    {
        if (FlashState != FLASH_OFF_STATE)
        {
            HAL_GPIO_WritePin(FPM_Indicator_MiA_GPIO_Port, FPM_Indicator_MiA_Pin, GPIO_PIN_RESET);
            FlashState = FLASH_OFF_STATE;
        }
        LastTick = now;
        return;
    }

    /* Dynamic FPM update from DIP switch */
    uint8_t newFpm = (uint8_t)FPM_GetSelected();
    if (newFpm != CurrentFpm && newFpm > 0)
    {
        CurrentFpm = newFpm;
        FlashPeriod = 60000UL / CurrentFpm;



    }

    /* Flashing State Machine */
    switch (FlashState)
    {
    case FLASH_OFF_STATE:
        if ((now - LastTick) >= (FlashPeriod - FLASH_ON_TIME_MS))
        {
            HAL_GPIO_WritePin(FPM_Indicator_MiA_GPIO_Port, FPM_Indicator_MiA_Pin, GPIO_PIN_SET);
            LastTick = now;
            FlashState = FLASH_ON_STATE;
        }
        break;

    case FLASH_ON_STATE:
        if ((now - LastTick) >= FLASH_ON_TIME_MS)
        {
            HAL_GPIO_WritePin(FPM_Indicator_MiA_GPIO_Port, FPM_Indicator_MiA_Pin, GPIO_PIN_RESET);
            LastTick = now;
            FlashState = FLASH_OFF_STATE;
        }
        break;

    default:
        FlashState = FLASH_OFF_STATE;
        break;
    }
}
