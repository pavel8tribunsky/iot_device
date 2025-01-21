/*
 */

#include "board_specific.h"

#include <stdint.h>
#include <stm32f4xx_hal.h>

volatile uint32_t time = 0;

void bsp_indication_run(void) {
  if ((HAL_GetTick() - time) > 500) {
    time = HAL_GetTick();
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
  }
}