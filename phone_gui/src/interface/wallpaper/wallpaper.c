#include "lvgl.h"
#include "../interface_conf.h"
#include "wallpaper.h"

static lv_obj_t *_wallpaper = NULL;

void wallpaper_init(void)
{
    _wallpaper = lv_scr_act();
    lv_obj_set_style_bg_opa(_wallpaper, LV_OPA_TRANSP, 0);

    lv_disp_set_bg_color(NULL, WALLPAPER_COLOR);
}

void wallpaper_set_image(const lv_img_dsc_t *src)
{
    int width = src->header.w;
    int height = src->header.h;

    if ((width != LV_HOR_RES) || (height != LV_VER_RES)) {
        LV_LOG_WARN("wallpaper(%d,%d) doesn't fit displayer(%d,%d)", width, height, LV_HOR_RES, LV_VER_RES);
        return;
    }

    lv_obj_set_style_bg_opa(_wallpaper, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_img_src(_wallpaper, (const void *)src, 0);
}

void wallpaper_set_color(lv_color_t color)
{
    lv_obj_set_style_bg_opa(_wallpaper, LV_OPA_TRANSP, 0);
    lv_obj_set_style_bg_img_src(_wallpaper, NULL, 0);
    lv_disp_set_bg_color(NULL, color);
}
