#ifndef GUI_H
#define GUI_H

#include "wallpaper/wallpaper.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    wallpaper_t wallpaper;
} gui_t;

void gui_init(gui_t *gui);

#ifdef __cplusplus
}
#endif

#endif
