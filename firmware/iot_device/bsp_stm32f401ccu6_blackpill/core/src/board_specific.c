/*
 */

#include "board_specific.h"

#include "stm32f4xx_hal.h"

#include "spi.h"

w25q_t spi_flash = {0};

void bsp_spi1_ncs_set(uint8_t mode) {
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (GPIO_PinState)mode);
}

uint8_t bsp_spi1_receive(uint8_t *rx_buff, uint16_t len, uint32_t tout) {
  return HAL_SPI_Receive(&hspi1, rx_buff, len, tout) ? 0 : 1;
}

uint8_t bsp_spi1_transmit(uint8_t *tx_buff, uint16_t len, uint32_t tout) {
  return HAL_SPI_Transmit(&hspi1, tx_buff, len, tout) ? 0 : 1;
}

uint8_t bsp_spi1_txrx(uint8_t *tx_buff, uint8_t *rx_buff, uint16_t len,
                      uint32_t tout) {
  return HAL_SPI_TransmitReceive(&hspi1, tx_buff, rx_buff, len, tout) ? 0 : 1;
}