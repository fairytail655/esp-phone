#ifndef WALLPAPER_H
#define WALLPAPER_H

#include "lvgl.h"
#include "../gui_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void (*show)(lv_obj_t *obj);
} wallpaper_t;

void wallpaper_init(wallpaper_t *wallpaper);

#ifdef __cplusplus
}
#endif

#endif
