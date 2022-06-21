#include "interface/interface_conf.h"
#include "utils/utils.h"
#include "bg_screen.h"

static bg_board_state_t _state;
static lv_obj_t *_scr = NULL;

static lv_obj_t *_label_switch;
static lv_obj_t *_label_on, *_label_off;
static lv_obj_t *_img_switch, *_img_more;

static lv_event_cb_t _switch_callback = NULL;
static lv_event_cb_t _more_callback = NULL;

static void img_switch_click_event(lv_event_t * e);
static void img_more_click_event(lv_event_t * e);

void bg_init(void)
{
    _scr = lv_scr_act();
    bg_wallpaper_init(_scr);
    lv_obj_t *obj_bg_board = bg_board_init(_scr);
    status_bar_init(_scr);

    /* Label "ON/OFF" */
    _label_switch = lv_obj_create(_scr);
    obj_conf_style_t style = {
        .width = LV_SIZE_CONTENT,
        .height = LV_SIZE_CONTENT,
        .pos_flag = OBJ_POS_FLAG_ALIGN_TO,
        .align = LV_ALIGN_TOP_LEFT,
        .alignt_to = obj_bg_board,
        .x_offset = LABEL_SWITCH_X_OFFSET,
        .y_offset = LABEL_SWITCH_Y_OFFEST,
        .border_width = 0,
        .radius = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(_label_switch, &style);
    lv_obj_set_flex_flow(_label_switch, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_label_switch, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(_label_switch, LABEL_SWITCH_PAD, 0);
    lv_obj_clear_flag(_label_switch, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_flag(_label_switch, LV_OBJ_FLAG_FLOATING);

    _label_on = lv_label_create(_label_switch);
    lv_obj_set_style_text_font(_label_on, LABEL_SWITCH_FONT_L, BG_BOARD_STATE_ON);
    lv_obj_set_style_text_color(_label_on, LABEL_COLOR_L_1, BG_BOARD_STATE_ON);
    lv_obj_set_style_text_font(_label_on, LABEL_SWITCH_FONT_S, BG_BOARD_STATE_OFF);
    lv_obj_set_style_text_color(_label_on, LABEL_COLOR_D_1, BG_BOARD_STATE_OFF);
    lv_label_set_text(_label_on, "ON");

    lv_obj_t *temp = lv_label_create(_label_switch);
    lv_obj_set_style_text_font(temp, LABEL_SWITCH_FONT_L, 0);
    lv_label_set_text(temp, "/");

    _label_off = lv_label_create(_label_switch);
    lv_obj_set_style_text_font(_label_off, LABEL_SWITCH_FONT_S, BG_BOARD_STATE_ON);
    lv_obj_set_style_text_color(_label_off, LABEL_COLOR_D_1, BG_BOARD_STATE_ON);
    lv_obj_set_style_text_font(_label_off, LABEL_SWITCH_FONT_L, BG_BOARD_STATE_OFF);
    lv_obj_set_style_text_color(_label_off, LABEL_COLOR_L_1, BG_BOARD_STATE_OFF);
    lv_label_set_text(_label_off, "OFF");

    /* Switch button */
    _img_switch = lv_img_create(_scr);
    LV_IMG_DECLARE(img_switch_off);
    lv_img_set_src(_img_switch, &img_switch_off);
    lv_obj_align_to(
        _img_switch, obj_bg_board, LV_ALIGN_TOP_RIGHT, -BTN_SWITCH_ICON_X_OFFSET, BTN_SWITCH_ICON_Y_OFFSET
    );
    // Calculate the multiple of the size between the target and the image.
    float h_factor, w_factor;
    h_factor = (float)BTN_SWITCH_ICON_SIZE / img_switch_off.header.h;
    w_factor = (float)BTN_SWITCH_ICON_SIZE / img_switch_off.header.w;
    // Scale the image to a suitable size.
    // So you don’t have to consider the size of the source image.
    if (h_factor < w_factor) {
        lv_img_set_zoom(_img_switch, (int)(h_factor * LV_IMG_ZOOM_NONE));
    }
    else {
        lv_img_set_zoom(_img_switch, (int)(w_factor * LV_IMG_ZOOM_NONE));
    }
    lv_obj_set_style_transform_zoom(_img_switch, (int)(LV_IMG_ZOOM_NONE * BTN_SWITCH_ZOOM_PERCENT / 100.0), LV_STATE_PRESSED);
    lv_obj_set_style_transform_zoom(_img_switch, LV_IMG_ZOOM_NONE, LV_STATE_DEFAULT);
    lv_obj_add_flag(_img_switch, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(_img_switch, img_switch_click_event, LV_EVENT_CLICKED, NULL);

    /* More button */
    _img_more = lv_img_create(_scr);
    LV_IMG_DECLARE(img_more);
    lv_img_set_src(_img_more, &img_more);
    lv_obj_align_to(_img_more, _img_switch, LV_ALIGN_BOTTOM_MID, 0, BTN_SWITCH_Y_OFFSET);
    // Calculate the multiple of the size between the target and the image.
    h_factor = (float)BTN_SWITCH_ICON_SIZE / img_more.header.h;
    w_factor = (float)BTN_SWITCH_ICON_SIZE / img_more.header.w;
    // Scale the image to a suitable size.
    // So you don’t have to consider the size of the source image.
    if (h_factor < w_factor) {
        lv_img_set_zoom(_img_more, (int)(h_factor * LV_IMG_ZOOM_NONE));
    }
    else {
        lv_img_set_zoom(_img_more, (int)(w_factor * LV_IMG_ZOOM_NONE));
    }
    lv_obj_set_style_transform_zoom(_img_more, (int)(LV_IMG_ZOOM_NONE * BTN_SWITCH_ZOOM_PERCENT / 100.0), LV_STATE_PRESSED);
    lv_obj_set_style_transform_zoom(_img_more, LV_IMG_ZOOM_NONE, LV_STATE_DEFAULT);
    lv_obj_add_flag(_img_more, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(_img_more, img_more_click_event, LV_EVENT_CLICKED, NULL);
}

void bg_change_state(bg_board_state_t state)
{
    // Background Board
    bg_board_change_state(state);
    // Switch button
    if (state == BG_BOARD_STATE_ON) {
        LV_IMG_DECLARE(img_switch_on);
        lv_img_set_src(_img_switch, &img_switch_on);
    }
    else if (state == BG_BOARD_STATE_OFF) {
        LV_IMG_DECLARE(img_switch_off);
        lv_img_set_src(_img_switch, &img_switch_off);
    }
    /* ON/OFF label */
    lv_obj_add_state(_label_on, state);
    lv_obj_clear_state(_label_on, ~state);
    lv_obj_add_state(_label_off, state);
    lv_obj_clear_state(_label_off, ~state);
    lv_obj_refresh_style(_label_switch, LV_PART_ANY, LV_STYLE_PROP_ANY);

    _state = state;
}

void bg_show(void)
{
    lv_scr_load(_scr);
}

void bg_register_callback_switch(lv_event_cb_t callback)
{
    _switch_callback  = callback;
}

void bg_register_callback_more(lv_event_cb_t callback)
{
    _more_callback  = callback;
}

void bg_show_label(bool en)
{
    if (en)
        lv_obj_clear_flag(_label_switch, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(_label_switch, LV_OBJ_FLAG_HIDDEN);
}

void bg_show_switch(bool en)
{
    if (en)
        lv_obj_clear_flag(_img_switch, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(_img_switch, LV_OBJ_FLAG_HIDDEN);
}

void bg_show_more(bool en)
{
    if (en)
        lv_obj_clear_flag(_img_more, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(_img_more, LV_OBJ_FLAG_HIDDEN);
}

static void img_switch_click_event(lv_event_t * e)
{
    if (_state == BG_BOARD_STATE_ON) {
        bg_change_state(BG_BOARD_STATE_OFF);
    }
    else {
        bg_change_state(BG_BOARD_STATE_ON);
    }
    if (_switch_callback)
        _switch_callback(e);
}

static void img_more_click_event(lv_event_t * e)
{
    if (_more_callback)
        _more_callback(e);
}
