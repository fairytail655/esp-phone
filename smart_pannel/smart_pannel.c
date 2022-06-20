#include "lvgl.h"
#include "interface/interface.h"
#include "smart_pannel.h"

void smart_pannel_init(void)
{
    bg_screen_init();
    fg_screen_init();
    bg_screen_show();
}

void smart_pannel_install_app(app_t *app)
{
    lv_obj_t *obj = NULL;

    obj = bg_board_regiser_obj();
    if (app->bg_screen_init != NULL)
        app->bg_screen_init(obj);

    obj = fg_screen_regiser_obj();
    if (app->fg_screen_init != NULL)
        app->fg_screen_init(obj);
}

void smart_pannel_set_default_app(int index)
{
    bg_board_switch_obj(index);
}
