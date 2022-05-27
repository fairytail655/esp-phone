#ifndef NAVIGATE_BAR_H
#define NAVIGATE_BAR_H

#define NAVIGATE_BAR_LEFT_BTN   0
#define NAVIGATE_BAR_MID_BTN    1
#define NAVIGATE_BAR_RIGHT_BTN  2

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void navigate_bar_init(lv_obj_t *parent);
lv_event_code_t navigate_bar_get_event_id(void);
void navigate_bar_show(void);
void navigate_bar_hide(void);

#ifdef __cplusplus
}
#endif

#endif