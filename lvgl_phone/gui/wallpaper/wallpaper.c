#include "wallpaper.h"

static void show(lv_obj_t *obj);

void wallpaper_init(wallpaper_t *wallpaper)
{
    wallpaper->show = show;
}

static void show(lv_obj_t *obj)
{
    lv_obj_set_style_bg_opa(obj, WALLPAPER_OPA, 0);
    lv_disp_set_bg_color(NULL, WALLPAPER_COLOR);
}
