#include "bg_screen.h"

static lv_obj_t *_scr = NULL;

void bg_screen_init(void)
{
    _scr = lv_scr_act();
    bg_wallpaper_init(_scr);
    bg_board_init(_scr);
    status_bar_init(_scr);
}

lv_obj_t *bg_screen_get_scr(void)
{
    return _scr;
}

void bg_screen_show(void)
{
    lv_obj_clear_flag(_scr, LV_OBJ_FLAG_HIDDEN);
}

void bg_screen_hide(void)
{
    lv_obj_add_flag(_scr, LV_OBJ_FLAG_HIDDEN);
}
