#include "lvgl.h"
#include "gui.h"

void gui_init(gui_t *gui)
{
    wallpaper_init(&gui->wallpaper, lv_scr_act());
#if STATUSBAR_EN
    status_bar_init(&gui->status_bar, lv_layer_top());
#endif
}
