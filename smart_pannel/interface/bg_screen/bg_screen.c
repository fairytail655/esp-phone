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
    lv_scr_load(_scr);
}
