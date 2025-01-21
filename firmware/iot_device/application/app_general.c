/*
 */

#include "app_general.h"

#include "board_specific.h"
#include "ds18x20.h"

ds18x20_t ds18b20 = {0};

static void _ac_init(void);
static void _ac_run(void);

void app_init(void) { _ac_init(); }

void app_run(void) {
  _ac_run();
  bsp_indication_run();
}

static void _ac_init(void) {
  ds18x20_callback_assign(&ds18b20, bsp_onewire_transmit, bsp_onewire_receive,
                          bsp_onewire_set_baudrate);
  ds18x20_init(&ds18b20);
}

static void _ac_run(void) { ds18x20_temp_get_all(&ds18b20); }
