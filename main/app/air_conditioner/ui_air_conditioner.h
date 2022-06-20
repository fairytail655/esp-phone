#ifndef UI_AIR_CONDITIONER_H
#define UI_AIR_CONDITIONER_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_air_cond_bg_init(lv_obj_t *obj);
void ui_air_cond_bg_change_state(lv_state_t state);
void ui_air_cond_bg_indoor_temp_inc(void);
void ui_air_cond_bg_indoor_temp_dec(void);
void ui_air_cond_bg_target_temp_inc(void);
void ui_air_cond_bg_target_temp_dec(void);

#ifdef __cplusplus
}
#endif

#endif