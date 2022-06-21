#include "lvgl.h"
#include "interface/interface.h"
#include "smart_pannel.h"

lv_ll_t _app_list;

static void bg_swtich_click_event(lv_event_t *e);
static void bg_more_click_event(lv_event_t *e);
static void fg_back_click_event(lv_event_t *e);

void smart_pannel_init(void)
{
    /* Background Screen */
    bg_init();
    bg_register_callback_switch(bg_swtich_click_event);
    bg_register_callback_more(bg_more_click_event);

    /* Foreground Screen */
    fg_init();
    fg_register_callback_back(fg_back_click_event);

    _lv_ll_init(&_app_list, sizeof(app_t *));
}

void smart_pannel_install_app(app_t *app)
{
    lv_obj_t *obj = NULL;

    /* Background Screen */
    obj = bg_board_regiser_obj();
    if (app->bg_screen_init != NULL)
        app->bg_screen_init(obj);

    /* Foreground Screen */
    obj = fg_regiser_obj();
    if (app->fg_screen_init != NULL)
        app->fg_screen_init(obj);

    app_t **new_app = (app_t **)_lv_ll_ins_tail(&_app_list);
    *new_app = app;
}

void smart_pannel_swtich_screen(void)
{
    bg_show();
}

static void bg_swtich_click_event(lv_event_t *e)
{
    LV_LOG_ERROR("a");
}

static void bg_more_click_event(lv_event_t *e)
{
    fg_show();
}

static void fg_back_click_event(lv_event_t *e)
{
    LV_LOG_ERROR("c");
}
