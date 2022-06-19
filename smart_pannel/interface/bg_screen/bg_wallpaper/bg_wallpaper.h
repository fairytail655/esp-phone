#ifndef BG_WALLPAPER_H
#define BG_WALLPAPER_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void bg_wallpaper_init(lv_obj_t *scr);
void bg_wallpaper_set_image(const lv_img_dsc_t *src);
void bg_wallpaper_set_color(lv_color_t color);

#ifdef __cplusplus
}
#endif

#endif
