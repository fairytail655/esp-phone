#include "lvgl.h"
#include "gui.h"

void gui_init(void)
{
    wallpaper_init(lv_scr_act());
#if STATUSBAR_EN
    status_bar_init(lv_layer_top());
#endif
}
