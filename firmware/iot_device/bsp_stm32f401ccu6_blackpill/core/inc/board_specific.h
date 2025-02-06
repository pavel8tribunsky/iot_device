/*
 */

#include "w25qxx.h"

extern w25q_t spi_flash;

void bsp_spi1_ncs_set(uint8_t mode);
uint8_t bsp_spi1_receive(uint8_t *rx_buff, uint16_t len, uint32_t tout);
uint8_t bsp_spi1_receive(uint8_t *rx_buff, uint16_t len, uint32_t tout);
uint8_t bsp_spi1_transmit(uint8_t *tx_buff, uint16_t len, uint32_t tout);
uint8_t bsp_spi1_txrx(uint8_t *tx_buff, uint8_t *rx_buff, uint16_t len,
                      uint32_t tout);