#ifndef BG_SCREEN_H
#define BG_SCREEN_H

#include "lvgl.h"
#include "bg_wallpaper/bg_wallpaper.h"
#include "bg_board/bg_board.h"
#include "status_bar/status_bar.h"

#ifdef __cplusplus
extern "C" {
#endif

void bg_screen_init(void);
lv_obj_t *bg_screen_get_scr(void);
void bg_screen_show(void);
void bg_screen_hide(void);

#ifdef __cplusplus
}
#endif

#endif