#include "../interface_conf.h"
#include "wallpaper.h"

static lv_obj_t *_wallpaper;

void wallpaper_init(void)
{
    _wallpaper = lv_scr_act();
    lv_obj_set_style_bg_opa(_wallpaper, WALLPAPER_OPA, 0);

    lv_disp_set_bg_color(NULL, WALLPAPER_COLOR);
}
