#ifndef ui_heater_H
#define ui_heater_H

#include "smart_pannel.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_heater_bg_init(lv_obj_t *obj);
void ui_heater_bg_register_cb(lv_event_cb_t heat, lv_event_cb_t rest);
void ui_heater_bg_change_state(smart_pannel_state_t state);
void ui_heater_bg_water_temp_set(int temp);
void ui_heater_bg_heat_set_state(interface_state_t state);
void ui_heater_bg_rest_set_state(interface_state_t state);
void ui_heater_bg_heat_enabel(bool flag);
void ui_heater_bg_rest_enabel(bool flag);

#ifdef __cplusplus
}
#endif

#endif