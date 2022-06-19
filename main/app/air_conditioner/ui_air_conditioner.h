#ifndef UI_AIR_CONDITIONER_H
#define UI_AIR_CONDITIONER_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void ui_air_cond_init(lv_obj_t *obj);
void ui_air_cond_change_state(lv_state_t state);

#ifdef __cplusplus
}
#endif

#endif