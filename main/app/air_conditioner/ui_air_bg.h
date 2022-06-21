#ifndef UI_AIR_H
#define UI_AIR_H

#include "smart_pannel.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_air_bg_init(lv_obj_t *obj);
void ui_air_bg_change_state(smart_pannel_state_t state);
void ui_air_bg_indoor_temp_set(int *temp);
void ui_air_bg_indoor_temp_inc(void);
void ui_air_bg_indoor_temp_dec(void);
void ui_air_bg_target_temp_set(int *temp);
void ui_air_bg_target_temp_inc(void);
void ui_air_bg_target_temp_dec(void);

#ifdef __cplusplus
}
#endif

#endif