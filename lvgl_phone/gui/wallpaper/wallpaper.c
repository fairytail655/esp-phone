#include "wallpaper.h"

static void show(void);

void wallpaper_init(lv_obj_t *parent)
{
    lv_obj_set_style_bg_opa(parent, WALLPAPER_OPA, 0);
    lv_disp_set_bg_color(NULL, WALLPAPER_COLOR);
}
