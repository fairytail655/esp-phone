#include "smart_pannel.h"
#include "ui_heater_conf.h"
#include "ui_heater_fg.h"

static void btns_enable(bool en);
static void mode_btns_init(lv_obj_t *obj);
static void degree_btns_init(lv_obj_t *obj);
static void target_temp_inc(void);
static void target_temp_dec(void);
static void inc_btn_event(lv_event_t *e);
static void dec_btn_event(lv_event_t *e);
static void timer_btn_callback(struct _lv_timer_t *timer);

static lv_obj_t *_label_target_temp;
static lv_obj_t *_label_target_symb;
static lv_obj_t *_btn_inc, *_btn_dec;
static lv_obj_t *_label_inc, *_label_dec;
static lv_timer_t *_timer_btn;
static bool _inc_flag = true;
static lv_event_cb_t _inc_event_cb, _dec_event_cb;
static lv_obj_t *_mode_btns[3];
static lv_obj_t *_degree_btns[3];

void ui_heater_fg_init(lv_obj_t *obj)
{
    /* Temperature increase/decrease button */
    _btn_inc = lv_btn_create(obj);
    lv_obj_set_size(_btn_inc, FG_TEMP_BTN_W, FG_TEMP_BTN_H);
    lv_obj_align(_btn_inc, LV_ALIGN_TOP_RIGHT, -FG_TEMP_BTN_OFFSET, FG_TEMP_BTN_OFFSET);
    lv_obj_set_style_radius(_btn_inc, FG_TEMP_BTN_RADIUS, 0);
    lv_obj_set_style_pad_all(_btn_inc, 0, 0);
    lv_obj_set_style_border_width(_btn_inc, 2, 0);
    lv_obj_set_style_border_color(_btn_inc, lv_color_white(), 0);
    lv_obj_set_style_bg_color(_btn_inc, FG_TEMP_BTN_COLOR, 0);
    // lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_RELEASED, NULL);
    _label_inc = lv_label_create(_btn_inc);
    lv_obj_set_style_text_font(_label_inc, FG_TEMP_FONT_S, 0);
    lv_label_set_text(_label_inc, "+");
    lv_obj_center(_label_inc);
    lv_obj_set_style_text_color(_label_inc, FG_COLOR_L_2, INTERFACE_STATE_ON);
    lv_obj_set_style_text_color(_label_inc, FG_COLOR_D_2, INTERFACE_STATE_OFF);

    _btn_dec = lv_btn_create(obj);
    lv_obj_set_size(_btn_dec, FG_TEMP_BTN_W, FG_TEMP_BTN_H);
    lv_obj_align(_btn_dec, LV_ALIGN_TOP_LEFT, FG_TEMP_BTN_OFFSET, FG_TEMP_BTN_OFFSET);
    lv_obj_set_style_radius(_btn_dec, FG_TEMP_BTN_RADIUS, 0);
    lv_obj_set_style_pad_all(_btn_dec, 0, 0);
    lv_obj_set_style_border_width(_btn_dec, 2, 0);
    lv_obj_set_style_border_color(_btn_dec, lv_color_white(), 0);
    lv_obj_set_style_bg_color(_btn_dec, FG_TEMP_BTN_COLOR, 0);
    lv_obj_add_event_cb(_btn_dec, dec_btn_event, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(_btn_dec, dec_btn_event, LV_EVENT_RELEASED, NULL);
    _label_dec = lv_label_create(_btn_dec);
    lv_obj_set_style_text_font(_label_dec, FG_TEMP_FONT_S, 0);
    lv_label_set_text(_label_dec, "-");
    lv_obj_center(_label_dec);
    lv_obj_set_style_text_color(_label_dec, FG_COLOR_L_2, INTERFACE_STATE_ON);
    lv_obj_set_style_text_color(_label_dec, FG_COLOR_D_2, INTERFACE_STATE_OFF);
    _timer_btn = lv_timer_create(timer_btn_callback, FG_TEMP_BTN_PERIOD, NULL);
    lv_timer_pause(_timer_btn);

    /* Target temperature label "35°C"   */
    _label_target_temp = lv_label_create(obj);
    lv_obj_set_style_text_font(_label_target_temp, FG_TEMP_FONT_S, 0);
    lv_obj_align(_label_target_temp, LV_ALIGN_TOP_MID, 0, FG_TEMP_BTN_OFFSET);
    lv_obj_set_style_text_color(_label_target_temp, FG_COLOR_L_2, INTERFACE_STATE_ON);
    lv_obj_set_style_text_color(_label_target_temp, FG_COLOR_D_2, INTERFACE_STATE_OFF);

    _label_target_symb = lv_label_create(obj);
    lv_obj_set_style_text_font(_label_target_symb, FG_TEMP_SYMB_S, 0);
    lv_label_set_text(_label_target_symb, "°C");
    lv_obj_refr_size(_label_target_symb);
    int x_offset = lv_obj_get_width(_label_target_symb);
    lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
    lv_obj_set_style_text_color(_label_target_symb, FG_COLOR_L_2, INTERFACE_STATE_ON);
    lv_obj_set_style_text_color(_label_target_symb, FG_COLOR_D_2, INTERFACE_STATE_OFF);

    mode_btns_init(obj);
    degree_btns_init(obj);
}

void ui_heater_fg_register_cb(lv_event_cb_t inc, lv_event_cb_t dec)
{
    _inc_event_cb = inc;
    _dec_event_cb = dec;
}

void ui_heater_fg_change_state(smart_pannel_state_t state)
{
    // Increase/decrease button
    lv_obj_clear_state(_label_inc, ~state);
    lv_obj_add_state(_label_inc, state);
    lv_obj_clear_state(_label_dec, ~state);
    lv_obj_add_state(_label_dec, state);
    if (state == INTERFACE_STATE_ON) {
        lv_obj_add_flag(_btn_inc, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(_btn_dec, LV_OBJ_FLAG_CLICKABLE);
    }
    else {
        lv_obj_clear_flag(_btn_inc, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(_btn_dec, LV_OBJ_FLAG_CLICKABLE);
    }
    // Target temperature label
    lv_obj_clear_state(_label_target_temp, ~state);
    lv_obj_add_state(_label_target_temp, state);
    lv_obj_clear_state(_label_target_symb, ~state);
    lv_obj_add_state(_label_target_symb, state);
    // Btns
    if (state == INTERFACE_STATE_OFF)
        btns_enable(false);
    else
        btns_enable(true);
}

void ui_heater_fg_water_temp_set(int temp)
{
    if ((temp >= TEMP_MAX) ||
        (temp <= TEMP_MIN))
        return;

    lv_label_set_text_fmt(_label_target_temp, "%-d", temp);
    int x_offset = lv_obj_get_width(_label_target_symb);
    lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

static void btns_enable(bool en)
{
    if (!en) {
        for (int i = 0; i < 3; i++) {
            lv_obj_clear_flag(_mode_btns[i], LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_state(_mode_btns[i], LV_STATE_CHECKED);
            lv_obj_clear_flag(_degree_btns[i], LV_OBJ_FLAG_CLICKABLE);
            lv_obj_clear_state(_degree_btns[i], LV_STATE_CHECKED);
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            lv_obj_add_flag(_mode_btns[i], LV_OBJ_FLAG_CLICKABLE);
            lv_obj_add_flag(_degree_btns[i], LV_OBJ_FLAG_CLICKABLE);
        }
    }
}

static void mode_btns_init(lv_obj_t *obj)
{
    // Button Container
    lv_obj_t *temp2 = lv_obj_create(obj);
    obj_conf_style_t style = {
        .width = MODE_CONT_WIDTH,
        .height = MODE_CONT_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET,
        .align = LV_ALIGN_BOTTOM_MID,
        .x_offset = 0,
        .y_offset = -MODE_CONT_OFFSET-MODE_CONT_HEIGHT,
        .radius = 0,
        .border_width = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(temp2, &style);
    lv_obj_set_flex_flow(temp2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(temp2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(temp2, MODE_BTN_PAD, 0);
    lv_obj_clear_flag(temp2, LV_OBJ_FLAG_SCROLLABLE);

    // Buttons
    _mode_btns[0] = lv_btn_create(temp2);
    int height = style.height * MODE_BTN_H_PERCENT / 100;
    lv_obj_set_height(_mode_btns[0], height);
    lv_obj_set_flex_grow(_mode_btns[0], 1);
    lv_obj_add_flag(_mode_btns[0], LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_border_width(_mode_btns[0], 1, 0);
    lv_obj_set_style_border_color(_mode_btns[0], lv_color_white(), 0);
    lv_obj_set_style_radius(_mode_btns[0], MODE_BTN_RADIUS, 0);
    lv_obj_set_style_bg_color(_mode_btns[0], MODE_BTN_COLOR_ON, LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(_mode_btns[0], MODE_BTN_COLOR_OFF, 0);
    lv_obj_t *temp = lv_label_create(_mode_btns[0]);
    lv_obj_set_style_text_font(temp, MODE_BTN_FONT, 0);
    lv_obj_set_style_text_color(temp, MODE_BTN_FONT_COLOR, 0);
    lv_label_set_text(temp, "Save Mode");
    lv_obj_center(temp);

    _mode_btns[1] = lv_btn_create(temp2);
    lv_obj_set_height(_mode_btns[1], height);
    lv_obj_set_flex_grow(_mode_btns[1], 1);
    lv_obj_add_flag(_mode_btns[1], LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_border_width(_mode_btns[1], 1, 0);
    lv_obj_set_style_border_color(_mode_btns[1], lv_color_white(), 0);
    lv_obj_set_style_radius(_mode_btns[1], MODE_BTN_RADIUS, 0);
    lv_obj_set_style_bg_color(_mode_btns[1], MODE_BTN_COLOR_ON, LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(_mode_btns[1], MODE_BTN_COLOR_OFF, 0);
    temp = lv_label_create(_mode_btns[1]);
    lv_obj_set_style_text_font(temp, MODE_BTN_FONT, 0);
    lv_obj_set_style_text_color(temp, MODE_BTN_FONT_COLOR, 0);
    lv_label_set_text(temp, "High Capacity");
    lv_obj_center(temp);

    _mode_btns[2] = lv_btn_create(temp2);
    lv_obj_set_height(_mode_btns[2], height);
    lv_obj_set_flex_grow(_mode_btns[2], 1);
    lv_obj_add_flag(_mode_btns[2], LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_border_width(_mode_btns[2], 1, 0);
    lv_obj_set_style_border_color(_mode_btns[2], lv_color_white(), 0);
    lv_obj_set_style_radius(_mode_btns[2], MODE_BTN_RADIUS, 0);
    lv_obj_set_style_bg_color(_mode_btns[2], MODE_BTN_COLOR_ON, LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(_mode_btns[2], MODE_BTN_COLOR_OFF, 0);
    temp = lv_label_create(_mode_btns[2]);
    lv_obj_set_style_text_font(temp, MODE_BTN_FONT, 0);
    lv_obj_set_style_text_color(temp, MODE_BTN_FONT_COLOR, 0);
    lv_label_set_text(temp, "Bath");
    lv_obj_center(temp);
}

static void degree_btns_init(lv_obj_t *obj)
{
    // Button Container
    lv_obj_t *temp2 = lv_obj_create(obj);
    obj_conf_style_t style = {
        .width = MODE_CONT_WIDTH,
        .height = MODE_CONT_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET,
        .align = LV_ALIGN_BOTTOM_MID,
        .x_offset = 0,
        .y_offset = -MODE_CONT_OFFSET,
        .radius = 0,
        .border_width = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(temp2, &style);
    lv_obj_set_flex_flow(temp2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(temp2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(temp2, MODE_BTN_PAD, 0);
    lv_obj_clear_flag(temp2, LV_OBJ_FLAG_SCROLLABLE);

    // Buttons
    _degree_btns[0] = lv_btn_create(temp2);
    int height = style.height * MODE_BTN_H_PERCENT / 100;
    lv_obj_set_height(_degree_btns[0], height);
    lv_obj_set_style_border_width(_degree_btns[0], 1, 0);
    lv_obj_set_style_border_color(_degree_btns[0], lv_color_white(), 0);
    lv_obj_set_style_radius(_degree_btns[0], MODE_BTN_RADIUS, 0);
    lv_obj_set_flex_grow(_degree_btns[0], 1);
    lv_obj_add_flag(_degree_btns[0], LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_bg_color(_degree_btns[0], MODE_BTN_COLOR_ON, LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(_degree_btns[0], MODE_BTN_COLOR_OFF, 0);
    lv_obj_t *temp = lv_label_create(_degree_btns[0]);
    lv_obj_set_style_text_font(temp, MODE_BTN_FONT, 0);
    lv_obj_set_style_text_color(temp, MODE_BTN_FONT_COLOR, 0);
    lv_label_set_text(temp, "Bacteriostasis");
    lv_obj_center(temp);

    _degree_btns[1] = lv_btn_create(temp2);
    lv_obj_set_height(_degree_btns[1], height);
    lv_obj_set_flex_grow(_degree_btns[1], 1);
    lv_obj_add_flag(_degree_btns[1], LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_border_width(_degree_btns[1], 1, 0);
    lv_obj_set_style_border_color(_degree_btns[1], lv_color_white(), 0);
    lv_obj_set_style_radius(_degree_btns[1], MODE_BTN_RADIUS, 0);
    lv_obj_set_style_bg_color(_degree_btns[1], MODE_BTN_COLOR_ON, LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(_degree_btns[1], MODE_BTN_COLOR_OFF, 0);
    temp = lv_label_create(_degree_btns[1]);
    lv_obj_set_style_text_font(temp, MODE_BTN_FONT, 0);
    lv_obj_set_style_text_color(temp, MODE_BTN_FONT_COLOR, 0);
    lv_label_set_text(temp, "Fast Heat");
    lv_obj_center(temp);

    _degree_btns[2] = lv_btn_create(temp2);
    lv_obj_set_height(_degree_btns[2], height);
    lv_obj_set_flex_grow(_degree_btns[2], 1);
    lv_obj_add_flag(_degree_btns[2], LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_border_width(_degree_btns[2], 1, 0);
    lv_obj_set_style_border_color(_degree_btns[2], lv_color_white(), 0);
    lv_obj_set_style_radius(_degree_btns[2], MODE_BTN_RADIUS, 0);
    lv_obj_set_style_bg_color(_degree_btns[2], MODE_BTN_COLOR_ON, LV_STATE_CHECKED);
    lv_obj_set_style_bg_color(_degree_btns[2], MODE_BTN_COLOR_OFF, 0);
    temp = lv_label_create(_degree_btns[2]);
    lv_obj_set_style_text_font(temp, MODE_BTN_FONT, 0);
    lv_obj_set_style_text_color(temp, MODE_BTN_FONT_COLOR, 0);
    lv_label_set_text(temp, "Cloud");
    lv_obj_center(temp);
}

static void target_temp_inc(void)
{
    if (_inc_event_cb)
        _inc_event_cb(NULL);

    int x_offset = lv_obj_get_width(_label_target_symb);
    lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

static void target_temp_dec(void)
{
    if (_dec_event_cb)
        _dec_event_cb(NULL);

    int x_offset = lv_obj_get_width(_label_target_symb);
    lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

static void inc_btn_event(lv_event_t *e)
{
    switch (lv_event_get_code(e)) {
        case LV_EVENT_PRESSED:
            _inc_flag = true;
            target_temp_inc();
            lv_timer_reset(_timer_btn);
            lv_timer_resume(_timer_btn);
            break;
        case LV_EVENT_RELEASED:
            lv_timer_pause(_timer_btn);
            break;
        default:
            break;
    }
}

static void dec_btn_event(lv_event_t *e)
{
    switch (lv_event_get_code(e)) {
        case LV_EVENT_PRESSED:
            _inc_flag = false;
            target_temp_dec();
            lv_timer_reset(_timer_btn);
            lv_timer_resume(_timer_btn);
            break;
        case LV_EVENT_RELEASED:
            lv_timer_pause(_timer_btn);
            break;
        default:
            break;
    }
}

static void timer_btn_callback(struct _lv_timer_t *timer)
{
    if (_inc_flag) {
        target_temp_inc();
    }
    else {
        target_temp_dec();
    }
}
