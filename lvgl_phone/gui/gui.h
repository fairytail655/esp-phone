#ifndef GUI_H
#define GUI_H

#include "wallpaper/wallpaper.h"
#include "status_bar/status_bar.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    wallpaper_t wallpaper;
#ifdef STATUS_BAR_EN
    status_bar_t status_bar;
#endif
} gui_t;

void gui_init(gui_t *gui);

#ifdef __cplusplus
}
#endif

#endif
