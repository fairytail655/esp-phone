#ifndef FG_SCREEN_H
#define FG_SCREEN_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void fg_init(void);
void fg_register_callback_back(lv_event_cb_t callback);
void fg_show(void);
lv_obj_t *fg_regiser_obj(void);
void fg_switch_obj(uint8_t index);
void fg_set_nav_bar_color(lv_color_t color);
void fg_change_state(int state);
void fg_set_left_text(const char *text);
void fg_set_middle_text(const char *text);
void fg_set_right_text(const char *text);
void fg_enabel_switch(void);
void fg_set_switch(bool flag);

#ifdef __cplusplus
}
#endif

#endif