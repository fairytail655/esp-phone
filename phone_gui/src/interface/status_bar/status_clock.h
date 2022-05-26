#ifndef STATUS_CLOCK_H
#define STATUS_CLOCK_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void status_clock_init(lv_obj_t *parent);
void status_clock_set_time(uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);

#ifdef __cplusplus
}
#endif

#endif