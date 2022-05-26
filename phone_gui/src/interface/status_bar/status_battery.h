#ifndef STATUS_BATTERY_H
#define STATUS_BATTERY_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void status_battery_init(lv_obj_t *parent);
void status_battery_set_percent(uint8_t percent);
void status_battery_set_charge(bool flag);

#ifdef __cplusplus
}
#endif

#endif