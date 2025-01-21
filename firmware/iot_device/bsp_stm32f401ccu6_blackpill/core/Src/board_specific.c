/*
 */

#include "board_specific.h"

#include <stdint.h>
#include <stm32f4xx_hal.h>

#include "usart.h"

#define BSP_PCLK2 84000000
#define BSP_PCLK2_DIV8 (84000000 >> 3)
#define BSP_PCLK2_DIV8_9600_BAUD ((BSP_PCLK2_DIV8 << 4) / 9600)
#define BSP_PCLK2_DIV8_115200_BAUD ((BSP_PCLK2_DIV8 << 4) / 115200)

volatile uint32_t time = 0;

void bsp_indication_run(void) {
  if ((HAL_GetTick() - time) > 500) {
    time = HAL_GetTick();
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
  }
}

void bsp_onewire_transmit(uint16_t data) {
  uint8_t byte = (uint8_t)data;
  HAL_UART_Transmit(&huart2, &byte, 1, 100);
}

uint16_t bsp_onewire_receive(void) {
  uint8_t byte = 0;
  HAL_UART_Receive(&huart2, &byte, 1, 100);
  return (uint16_t)byte;
}

void bsp_onewire_set_baudrate(uint32_t baudrate) {
  switch (baudrate) {
    case 9600:
      USART6->BRR = BSP_PCLK2_DIV8_9600_BAUD;
      break;
    default:  // 115200
      USART6->BRR = BSP_PCLK2_DIV8_115200_BAUD;
      break;
  }
}