#include "lvgl.h"
#include "interface/interface.h"
#include "interface/interface_conf.h"
#include "motion_detect/motion_detect.h"
#include "smart_pannel.h"

static void switch_app_bg_fg_next(void);
static void switch_app_bg_fg_prev(void);
static void switch_app_bg_fg_index(int index);
static void bg_swtich_click_event(lv_event_t *e);
static void bg_more_click_event(lv_event_t *e);
static void fg_back_click_event(lv_event_t *e);
static void fg_switch_click_event(lv_event_t *e);
static void motion_detect_event(lv_event_t *e);
static void move_animation_event_cb(struct _lv_anim_t *a);
static void bottom_press_event_cb(lv_event_t *e);
static void bottom_pressing_event_cb(lv_event_t *e);
static void bottom_click_event_cb(lv_event_t *e);

static lv_ll_t _app_list;
static int _active_app_index = 1;
static app_t **_active_app_node;
static lv_event_code_t _motion_detect_event_id;
static lv_obj_t *_motion_detect_event_obj;
static smart_pannel_touch_pos_t _touch_pos = NULL;
static bool _bg_screen_active_flag = true;
static int touch_x_last, touch_y_last, touch_y_origin;
static bool hide_flag = false;

void smart_pannel_init(void)
{
    /* Background Screen */
    bg_init();
    bg_register_cb_switch(bg_swtich_click_event);
    bg_register_cb_more(bg_more_click_event);

    /* Foreground Screen */
    fg_init();
    fg_register_cb_back(fg_back_click_event, fg_switch_click_event);

    /* Motion Detect */
    _motion_detect_event_id = lv_event_register_id();
    _motion_detect_event_obj = lv_layer_top();
    motion_detect_init(_motion_detect_event_obj, _motion_detect_event_id);
    lv_obj_add_event_cb(
        _motion_detect_event_obj, motion_detect_event, _motion_detect_event_id, NULL
    );

    /* Menu Bar */
    menu_init(lv_layer_top());
    lv_obj_add_event_cb(
        lv_layer_top(), bottom_press_event_cb, menu_bar_get_event_id_press(), NULL
    );
    lv_obj_add_event_cb(
        lv_layer_top(), bottom_pressing_event_cb, menu_bar_get_event_id_pressing(), NULL
    );
    lv_obj_add_event_cb(
        lv_layer_top(), bottom_click_event_cb, menu_bar_get_event_id_click(), NULL
    );
    menu_bar_set_anim_cb((void *)move_animation_event_cb);

    _lv_ll_init(&_app_list, sizeof(app_t *));

}

void smart_pannel_install_app(app_t *app)
{
    app_t **new_app = (app_t **)_lv_ll_ins_tail(&_app_list);
    lv_obj_t *obj = NULL;

    /* Background Screen */
    obj = bg_board_regiser_obj();
    if (app->bg_screen_init != NULL) {
        app->bg_screen_init(obj);
    }

    /* Foreground Screen */
    obj = fg_regiser_obj();
    if (app->fg_screen_init != NULL) {
        app->fg_screen_init(obj);
    }

    *new_app = app;
    if (_lv_ll_get_len(&_app_list) == _active_app_index) {
        switch_app_bg_fg_index(_active_app_index);
    }
}

void smart_pannel_swtich_to_bg(void)
{
    _bg_screen_active_flag = true;
    bg_show();
}

void smart_pannel_swtich_to_fg(void)
{
    _bg_screen_active_flag = false;
    fg_show();
}

void smart_pannel_register_touch_pos(smart_pannel_touch_pos_t touch_pos)
{
    _touch_pos = touch_pos;
    motion_detect_register_touch_pos(touch_pos);
}

static void switch_app_bg_fg_next(void)
{
    app_t **app_node = NULL;
    if (_active_app_index < _lv_ll_get_len(&_app_list)) {
        app_node = _lv_ll_get_next(&_app_list, _active_app_node);
        ++_active_app_index;
    }
    else {
        app_node = _lv_ll_get_head(&_app_list);
        _active_app_index = 1;
    }
    if (app_node == NULL) {
        return;
    }

    app_t *app = *app_node;
    /* Background Screen */
    if (app->bg_screen_init) {
        bg_change_state(*app->state);
        bg_board_switch_obj(_active_app_index);
        if (app->bg_screen_init == NULL) {
            bg_show_more(false);
        }
        else {
            bg_show_more(true);
        }
    }

    /* Foreground Screen */
    if (app->fg_screen_init) {
        fg_change_state(*app->state);
        fg_switch_obj(_active_app_index);
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

    _active_app_node = app_node;
}

static void switch_app_bg_fg_prev(void)
{
    app_t **app_node = NULL;
    if (_active_app_index > 1) {
        app_node = _lv_ll_get_prev(&_app_list, _active_app_node);
        --_active_app_index;
    }
    else {
        app_node = _lv_ll_get_tail(&_app_list);
        _active_app_index = _lv_ll_get_len(&_app_list);
    }
    if (app_node == NULL) {
        return;
    }

    app_t *app = *app_node;
    /* Background Screen */
    if (app->bg_screen_init) {
        bg_change_state(*app->state);
        bg_board_switch_obj(_active_app_index);
        if (app->bg_screen_init == NULL) {
            bg_show_more(false);
        }
        else {
            bg_show_more(true);
        }
    }

    /* Foreground Screen */
    if (app->fg_screen_init) {
        fg_change_state(*app->state);
        fg_switch_obj(_active_app_index);
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

    _active_app_node = app_node;
}

static void switch_app_bg_fg_index(int index)
{
    app_t **app_node = NULL;
    for (int i = 0; (i < _lv_ll_get_len(&_app_list) && i < index); i++) {
        if (i == 0) {
            app_node = _lv_ll_get_head(&_app_list);
        }
        else {
            app_node = _lv_ll_get_next(&_app_list, app_node);
        }
    }
    if (app_node == NULL) {
        return;
    }

    app_t *app = *app_node;
    /* Background Screen */
    if (app->bg_screen_init) {
        bg_change_state(*app->state);
        bg_board_switch_obj(index);
        if (app->bg_screen_init == NULL) {
            bg_show_more(false);
        }
        else {
            bg_show_more(true);
        }
    }

    /* Foreground Screen */
    if (app->fg_screen_init) {
        fg_change_state(*app->state);
        fg_switch_obj(index);
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

    _active_app_node = app_node;
    _active_app_index = index;
}

static void bg_swtich_click_event(lv_event_t *e)
{
    app_t *app = *_active_app_node;
    smart_pannel_state_t state = *app->state;
    state = (state == INTERFACE_STATE_ON) ? INTERFACE_STATE_OFF : INTERFACE_STATE_ON;
    *(app->state) = state;
    bg_change_state(state);
    fg_change_state(state);

    lv_event_cb_t callbadck = app->bg_switch_cb;
    if (callbadck)
        callbadck(e);
}

static void bg_more_click_event(lv_event_t *e)
{
    lv_event_cb_t callbadck = (*_active_app_node)->bg_more_cb;
    if (callbadck)
        callbadck(e);

    smart_pannel_swtich_to_fg();
}

static void fg_back_click_event(lv_event_t *e)
{
    lv_event_cb_t callbadck = (*_active_app_node)->fg_back_cb;
    if (callbadck)
        callbadck(e);
}

static void fg_switch_click_event(lv_event_t *e)
{
    app_t *app = *_active_app_node;
    smart_pannel_state_t state = *app->state;
    state = (state == INTERFACE_STATE_ON) ? INTERFACE_STATE_OFF : INTERFACE_STATE_ON;
    *(app->state) = state;
    bg_change_state(state);
    fg_change_state(state);

    lv_event_cb_t callbadck = (*_active_app_node)->fg_switch_cb;
    if (callbadck)
        callbadck(e);
}

static void motion_detect_event(lv_event_t *e)
{
    motion_detect_type_t type = (motion_detect_type_t)lv_event_get_param(e);

    switch (type) {
        case MOTION_UP:
            MAIN_TRACE("main up");
            break;
        case MOTION_DOWN:
            MAIN_TRACE("main down");
            break;
        case MOTION_RIGHT:
            MAIN_TRACE("main right");
            if (_bg_screen_active_flag) {
                switch_app_bg_fg_prev();
            }
            break;
        case MOTION_LEFT:
            MAIN_TRACE("main left");
            if (_bg_screen_active_flag) {
                switch_app_bg_fg_next();
            }
            break;
        default:
            break;
    }
}

static void move_animation_event_cb(struct _lv_anim_t *a)
{
    if (hide_flag) {
        hide_flag = false;
        // gui.menubar.hide();
        menu_bar_show(false);
    }
}

static void bottom_press_event_cb(lv_event_t *e)
{
    if (_touch_pos) {
        _touch_pos(&touch_x_last, &touch_y_last);
        touch_y_origin = touch_y_last;
    }
    // gui.menubar.show();
    menu_bar_show(true);
}

static void bottom_pressing_event_cb(lv_event_t *e)
{
    int touch_x, touch_y, touch_y_distance;
    int menubar_y, menubar_y_next;

    if (_touch_pos) {
        _touch_pos(&touch_x, &touch_y);
        touch_y_distance = touch_y - touch_y_last;
        menubar_y = menu_bar_current_y();
        menubar_y_next = menubar_y + touch_y_distance;
        if (((touch_y_distance > 0) && (menubar_y < 0)) ||
            ((touch_y_distance < 0) && (menubar_y > menu_bar_origin_y()))) {
            if (menubar_y_next > 0) {
                // gui.menubar.moveY(0);
                menu_bar_move_y(0);
            }
            else if (menubar_y_next < menu_bar_origin_y()) {
                // gui.menubar.moveY(gui.menubar.originY());
                menu_bar_move_y(menu_bar_origin_y());
            }
            else {
                // gui.menubar.moveY(menubar_y_next);
                menu_bar_move_y(menubar_y_next);
            }
        }
        touch_y_last = touch_y;
    }
}

static void bottom_click_event_cb(lv_event_t *e)
{
    int distance;

    if (_touch_pos) {
        _touch_pos(&touch_x_last, &touch_y_last);
        distance = touch_y_last - touch_y_origin;
        if (distance < 0) {
            if (distance < -(MENU_BAR_HEIGHT / 4)) {
                // gui.menubar.startMoveAnim(gui.menubar.originY());
                menu_bar_start_anim(menu_bar_origin_y());
                hide_flag = true;
            }
            else {
                // gui.menubar.startMoveAnim(0);
                menu_bar_start_anim(0);
                hide_flag = false;
            }
        }
        else {
            if (distance > (MENU_BAR_HEIGHT / 4)) {
                // gui.menubar.startMoveAnim(0);
                menu_bar_start_anim(0);
                hide_flag = false;
            }
            else {
                // gui.menubar.startMoveAnim(gui.menubar.originY());
                menu_bar_start_anim(menu_bar_origin_y());
                hide_flag = true;
            }
        }
    }
}
