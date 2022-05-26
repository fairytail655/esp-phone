#ifndef WALLPAPER_H
#define WALLPAPER_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void wallpaper_init(void);
void wallpaper_set_image(const lv_img_dsc_t *src);
void wallpaper_set_color(lv_color_t color);

#ifdef __cplusplus
}
#endif

#endif
