#include "lvgl.h"
#include "wallpaper/wallpaper.h"
#include "interface_conf.h"
#include "interface.h"

void interface_init(void)
{
    wallpaper_init();
#if STATUSBAR_EN
    status_bar_init(INTERFACE_EVENT_OBJ);
#endif
}
