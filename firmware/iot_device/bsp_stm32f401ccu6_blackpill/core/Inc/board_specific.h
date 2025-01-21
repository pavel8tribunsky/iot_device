/*
 */

#ifndef __INC_BSP_H__
#define __INC_BSP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "main.h"

void bsp_indication_run(void);
void bsp_onewire_transmit(uint16_t data);
uint16_t bsp_onewire_receive(void);
void bsp_onewire_set_baudrate(uint32_t baudrate);

#ifdef __cplusplus
}
#endif

#endif /* __INC_BSP_H__ */