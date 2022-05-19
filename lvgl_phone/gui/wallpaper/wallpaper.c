#include "wallpaper.h"

static void show(void);

void wallpaper_init(wallpaper_t *wallpaper, lv_obj_t *parent)
{
    wallpaper->show = show;

    lv_obj_set_style_bg_opa(parent, WALLPAPER_OPA, 0);
    lv_disp_set_bg_color(NULL, WALLPAPER_COLOR);
}

static void show(void)
{

}
