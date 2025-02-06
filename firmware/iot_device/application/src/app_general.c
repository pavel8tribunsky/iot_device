/*
 */

#include "app_general.h"

#include "board_specific.h"

#include "stm32f4xx_hal.h"

void app_init(void) {
  w25q_iface_t spif = {0};

  spif.get_tick = HAL_GetTick;
  spif.gpio.set_ncs = bsp_spi1_ncs_set;
  spif.spi.receive = bsp_spi1_receive;
  spif.spi.transmit = bsp_spi1_transmit;
  spif.spi.transmit_receive = bsp_spi1_txrx;

  w25q_init(&spi_flash, &spif);
}

void app_run(void) {
  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
  HAL_Delay(500);
}