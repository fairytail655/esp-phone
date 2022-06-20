#include "utils/utils.h"
#include "interface/interface_conf.h"
#include "fg_screen.h"

static lv_obj_t *_scr;
static lv_obj_t *_navigate_bar;
static lv_obj_t *_label_left, *_label_mid, *_label_right;
static lv_obj_t *_switch;
static lv_obj_t *_app_area;
static uint8_t _app_index = 0;
static lv_ll_t _app_ll;

void fg_screen_init(void)
{
    _scr = lv_obj_create(NULL);
    // lv_scr_load(_scr);

    /* Navigate bar */
    // Main Area
    _navigate_bar = lv_obj_create(_scr);
    obj_conf_style_t style = {
        .width = NAVIGATE_BAR_WIDTH,
        .height = NAVIGATE_BAR_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN,
        .align = LV_ALIGN_TOP_MID,
        .radius = 0,
        .border_width = 0,
        .pad_all = 0,
        .bg_color = NAVIGATE_BAR_COLOR,
        .bg_opa = LV_OPA_COVER,
    };
    obj_conf_style(_navigate_bar, &style);
    lv_obj_set_style_text_font(_navigate_bar, NAVIGATE_BAR_FONT, 0);

    // Left Area
    lv_obj_t *label = lv_label_create(_navigate_bar);
    lv_label_set_text(label, LV_SYMBOL_LEFT);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, NAVIGATE_BAR_LEFT_OFFSET_1, 0);
    _label_left = lv_label_create(_navigate_bar);
    lv_obj_align_to(_label_left, label, LV_ALIGN_OUT_RIGHT_MID, NAVIGATE_BAR_LEFT_OFFSET_2, 0);
    lv_obj_add_flag(_label_left, LV_OBJ_FLAG_HIDDEN);

    // Middle Area
    _label_mid = lv_label_create(_navigate_bar);
    lv_obj_center(_label_mid);
    lv_obj_add_flag(_label_mid, LV_OBJ_FLAG_HIDDEN);

    // Right Area
    _label_right = lv_label_create(_navigate_bar);
    lv_obj_align(_label_right, LV_ALIGN_RIGHT_MID, NAVIGATE_BAR_RIGHT_OFFSET, 0);
    lv_obj_add_flag(_label_right, LV_OBJ_FLAG_HIDDEN);
    _switch = lv_switch_create(_navigate_bar);
    lv_obj_set_size(_switch, NAVIGATE_BAR_SW_WIDTH, NAVIGATE_BAR_SW_HEIGHT);
    lv_obj_align(_switch, LV_ALIGN_RIGHT_MID, -NAVIGATE_BAR_RIGHT_OFFSET, 0);
    // lv_obj_add_flag(_switch, LV_OBJ_FLAG_HIDDEN);

    /* App area */
    _app_area = lv_img_create(_scr);
    LV_IMG_DECLARE(img_app_area);
    lv_img_set_src(_app_area, &img_app_area);
    lv_obj_align(_app_area, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_style_img_recolor(_app_area, BG_BOARD_OBJ_COLOR_ON, INTERFACE_STATE_ON);
    lv_obj_set_style_img_recolor_opa(_app_area, BG_BOARD_OBJ_OPA_ON, INTERFACE_STATE_ON);
    lv_obj_set_style_img_recolor(_app_area, BG_BOARD_OBJ_COLOR_OFF, INTERFACE_STATE_OFF);
    lv_obj_set_style_img_recolor_opa(_app_area, BG_BOARD_OBJ_OPA_OFF, INTERFACE_STATE_OFF);
    _lv_ll_init(&_app_ll, sizeof(lv_obj_t *));
}

lv_obj_t *fg_screen_regiser_obj(void)
{
    lv_obj_t **app = (lv_obj_t **)_lv_ll_ins_tail(&_app_ll);

    lv_obj_t *obj = lv_obj_create(_app_area);
    obj_conf_style_t style = {
        .width = BG_BOARD_WIDTH,
        .height = BG_BOARD_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN,
        .align = LV_ALIGN_CENTER,
        .border_width = 0,
        .pad_all = 0,
        .radius = BG_BOARD_RADIUS,
    };
    obj_conf_style(obj, &style);
    lv_obj_set_style_bg_color(obj, BG_BOARD_OBJ_COLOR_ON, 0);
    lv_obj_set_style_bg_opa(obj, BG_BOARD_OBJ_OPA_ON, 0);
    lv_obj_set_style_bg_color(obj, BG_BOARD_OBJ_COLOR_OFF, LV_STATE_USER_1);
    lv_obj_set_style_bg_opa(obj, BG_BOARD_OBJ_OPA_OFF, LV_STATE_USER_1);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    *app = obj;

    return obj;
}

void fg_screen_switch_obj(uint8_t index)
{
    int app_count = _lv_ll_get_len(&_app_ll);
    if (index > app_count) {
        INTERFACE_TRACE("bg_board switch obj out of index");
        return;
    }

    lv_obj_t **app = NULL;
    lv_obj_t **app_target = NULL;
    lv_obj_t **app_last = NULL;
    for (int i = 0; i < app_count; i++) {
        if (i == 0) {
            app = (lv_obj_t **)_lv_ll_get_head(&_app_ll);
        }
        else {
            app = (lv_obj_t **)_lv_ll_get_next(&_app_ll, app);
        }
        if (i == (_app_index - 1)) {
            app_last = app;
        }
        else if (i == (index - 1)) {
            app_target = app;
        }
    }

    if (app_last) {
        lv_obj_add_flag(*app_last, LV_OBJ_FLAG_HIDDEN);
    }
    if (app_target) {
        lv_obj_clear_flag(*app_target, LV_OBJ_FLAG_HIDDEN);
    }

    _app_index = index;
}

void fg_screen_show(void)
{
    lv_scr_load(_scr);
}

void fg_screen_set_nav_bar_color(lv_color_t color)
{
    lv_obj_set_style_bg_color(_navigate_bar, color, 0);
}

void fg_screen_change_state(int state)
{
    if (state == INTERFACE_STATE_ON) {
        lv_obj_add_state(_app_area, INTERFACE_STATE_ON);
        lv_obj_clear_state(_app_area, INTERFACE_STATE_OFF);
    }
    else {
        lv_obj_add_state(_app_area, INTERFACE_STATE_OFF);
        lv_obj_clear_state(_app_area, INTERFACE_STATE_ON);
    }
}

void fg_screen_set_left_text(const char *text)
{
    if (text == NULL) {
        lv_obj_add_flag(_label_left, LV_OBJ_FLAG_HIDDEN);
        return;
    }

    lv_label_set_text(_label_left, text);
    lv_obj_clear_flag(_label_left, LV_OBJ_FLAG_HIDDEN);
}

void fg_screen_set_middle_text(const char *text)
{
    if (text == NULL) {
        lv_obj_add_flag(_label_mid, LV_OBJ_FLAG_HIDDEN);
        return;
    }

    lv_label_set_text(_label_mid, text);
    lv_obj_clear_flag(_label_left, LV_OBJ_FLAG_HIDDEN);
}

void fg_screen_set_right_text(const char *text)
{
    if (text == NULL) {
        lv_obj_add_flag(_label_right, LV_OBJ_FLAG_HIDDEN);
        return;
    }

    lv_label_set_text(_label_right, text);
    lv_obj_clear_flag(_label_right, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(_switch, LV_OBJ_FLAG_HIDDEN);
}

void fg_screen_enabel_switch(void)
{
    lv_obj_add_flag(_label_right, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(_switch, LV_OBJ_FLAG_HIDDEN);
}

void fg_screen_set_switch(bool flag)
{
    if (flag) {
        lv_obj_add_state(_switch, LV_STATE_CHECKED);
    }
    else
        lv_obj_clear_state(_switch, LV_STATE_CHECKED);
}
