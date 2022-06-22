#ifndef ui_heater_FG_H
#define ui_heater_FG_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_heater_fg_init(lv_obj_t *obj);
void ui_heater_fg_register_cb(lv_event_cb_t inc, lv_event_cb_t dec);
void ui_heater_fg_change_state(smart_pannel_state_t state);
void ui_heater_fg_water_temp_set(int temp);

#ifdef __cplusplus
}
#endif

#endif