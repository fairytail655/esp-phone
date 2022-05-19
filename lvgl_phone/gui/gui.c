#include "lvgl.h"
#include "gui.h"

void gui_init(gui_t *gui)
{
    wallpaper_init(&gui->wallpaper);

    gui->wallpaper.show(lv_scr_act());
}
