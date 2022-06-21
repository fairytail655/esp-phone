#include "lvgl.h"
#include "interface/interface.h"
#include "interface/interface_conf.h"
#include "motion_detect/motion_detect.h"
#include "smart_pannel.h"

static lv_ll_t _app_list;
static app_t *_active_app;

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

    /* Motion Detect */
    motion_detect_init();
}

void smart_pannel_install_app(app_t *app)
{
    app_t **new_app = (app_t **)_lv_ll_ins_tail(&_app_list);
    lv_obj_t *obj = NULL;

    /* Background Screen */
    obj = bg_board_regiser_obj();
    if (app->bg_screen_init != NULL) {
        app->bg_screen_init(obj);
        bg_change_state(*app->state);
        if (app->bg_switch_callback != NULL)
            app->bg_switch_callback(NULL);
    }

    /* Foreground Screen */
    obj = fg_regiser_obj();
    if (app->fg_screen_init != NULL) {
        app->fg_screen_init(obj);
        fg_change_state(*app->state);
        if (app->fg_init_conf->left_title)
            fg_set_left_text(app->fg_init_conf->left_title);
        if (app->fg_init_conf->middle_title)
            fg_set_middle_text(app->fg_init_conf->middle_title);
        if (app->fg_init_conf->right_title)
            fg_set_middle_text(app->fg_init_conf->right_title);
        if (app->fg_init_conf->en_bg_color)
            fg_set_nav_bar_color(app->fg_init_conf->bg_color);
        else
            fg_set_nav_bar_color(NAVIGATE_BAR_COLOR);
    }

    *new_app = app;
    if (_lv_ll_get_len(&_app_list) == 1) {
        _active_app = app;
        bg_board_switch_obj(1);
    }
}

void smart_pannel_swtich_to_bg(void)
{
    bg_show();
}

void smart_pannel_swtich_to_fg(void)
{
    fg_show();
}

static void bg_swtich_click_event(lv_event_t *e)
{
    smart_pannel_state_t state = *(_active_app->state);
    state = (state == INTERFACE_STATE_ON) ? INTERFACE_STATE_OFF : INTERFACE_STATE_ON;
    *(_active_app->state) = state;

    lv_event_cb_t callbadck = _active_app->bg_switch_callback;
    if (callbadck)
        callbadck(NULL);
}

static void bg_more_click_event(lv_event_t *e)
{
    fg_show();
}

static void fg_back_click_event(lv_event_t *e)
{
    lv_event_cb_t callbadck = _active_app->fg_back_callback;
    if (callbadck)
        callbadck(NULL);
}

static app_t *get_next_app(void)
{
    app_t *res = _lv_ll_get_next(&_app_list, _active_app);
    if (res == NULL) {
        res = _lv_ll_get_head(&_app_list);
    }

    return res;
}

static app_t *get_prev_app(void)
{
    app_t *res = _lv_ll_get_prev(&_app_list, _active_app);
    if (res == NULL) {
        res = _lv_ll_get_tail(&_app_list);
    }

    return res;
}
