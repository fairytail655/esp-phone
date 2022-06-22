#ifndef FG_SCREEN_H
#define FG_SCREEN_H

#include "interface/interface_conf.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void fg_init(void);
void fg_register_cb_back(lv_event_cb_t left_area_cb, lv_event_cb_t right_sw_cb);
void fg_show(void);
lv_obj_t *fg_regiser_obj(void);
void fg_switch_obj(uint8_t index);
void fg_set_nav_bar_color(lv_color_t color);
void fg_change_state(interface_state_t state);
void fg_set_left_text(const char *text);
void fg_set_middle_text(const char *text);
void fg_set_right_text(const char *text);
void fg_enabel_switch(void);
void fg_set_switch(interface_state_t state);

#ifdef __cplusplus
}
#endif

#endif