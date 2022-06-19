#include "lvgl.h"
#include "interface/interface_conf.h"
#include "bg_wallpaper.h"

static lv_obj_t *_wallpaper = NULL;

void bg_wallpaper_init(lv_obj_t *scr)
{
    _wallpaper = scr;
    lv_obj_set_style_bg_opa(_wallpaper, LV_OPA_TRANSP, 0);

    lv_disp_set_bg_color(NULL, BG_WALLPAPER_COLOR);
}

void bg_wallpaper_set_image(const lv_img_dsc_t *src)
{
    int width = src->header.w;
    int height = src->header.h;

    if ((width != LV_HOR_RES) || (height != LV_VER_RES)) {
        LV_LOG_WARN(
            "background wallpaper(%d,%d) doesn't fit displayer(%d,%d)",
            width, height, LV_HOR_RES, LV_VER_RES
        );
        return;
    }

    lv_obj_set_style_bg_opa(_wallpaper, LV_OPA_COVER, 0);
    lv_obj_set_style_bg_img_src(_wallpaper, (const void *)src, 0);
}

void bg_wallpaper_set_color(lv_color_t color)
{
    lv_obj_set_style_bg_opa(_wallpaper, LV_OPA_TRANSP, 0);
    lv_obj_set_style_bg_img_src(_wallpaper, NULL, 0);
    lv_disp_set_bg_color(NULL, color);
}
