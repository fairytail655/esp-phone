#ifndef UI_AIR_FG_H
#define UI_AIR_FG_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_air_fg_init(lv_obj_t *obj);
void ui_air_fg_register_cb(lv_event_cb_t inc, lv_event_cb_t dec);
void ui_air_fg_change_state(smart_pannel_state_t state);
void ui_air_fg_target_temp_set(int temp);

#ifdef __cplusplus
}
#endif

#endif