#ifndef FG_SCREEN_H
#define FG_SCREEN_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void fg_screen_init(void);
void fg_screen_show(void);
void fg_screen_set_nav_bar_color(lv_color_t color);
void fg_screen_change_state(int state);
void fg_screen_set_left_text(const char *text);
void fg_screen_set_middle_text(const char *text);
void fg_screen_set_right_text(const char *text);
void fg_screen_enabel_switch(void);
void fg_screen_set_switch(bool flag);

#ifdef __cplusplus
}
#endif

#endif