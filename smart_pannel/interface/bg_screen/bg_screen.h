#ifndef BG_SCREEN_H
#define BG_SCREEN_H

#include "lvgl.h"
#include "bg_wallpaper/bg_wallpaper.h"
#include "bg_board/bg_board.h"
#include "status_bar/status_bar.h"

#ifdef __cplusplus
extern "C" {
#endif

void bg_init(void);
void bg_show(void);
void bg_change_state(bg_board_state_t state);
void bg_register_callback_switch(lv_event_cb_t callback);
void bg_register_callback_more(lv_event_cb_t callback);
void bg_show_label(bool en);
void bg_show_switch(bool en);
void bg_show_more(bool en);

#ifdef __cplusplus
}
#endif

#endif