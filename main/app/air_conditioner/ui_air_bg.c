#include "smart_pannel.h"
#include "../app_conf.h"
#include "ui_air_bg.h"

static smart_pannel_bg_state_t _state;
static int _indoor_temperature = 26;
static int _target_temperature = 23;
static lv_obj_t *_label_indoor_temp, *_label_target_temp;
static lv_obj_t *_label_indoor_symb, *_label_target_symb;
static lv_obj_t *_btn_inc, *_btn_dec;
static lv_obj_t *_label_inc, *_label_dec;
static lv_timer_t *_timer_btn;
static bool _inc_flag = true;

static lv_event_cb_t _more_click_event;

static void img_switch_click_event(lv_event_t * e);
static void img_more_click_event(lv_event_t * e);
static void inc_btn_event(lv_event_t *e);
static void dec_btn_event(lv_event_t *e);
static void timer_btn_callback(struct _lv_timer_t *timer);

void ui_air_bg_init(lv_obj_t *obj, smart_pannel_bg_state_t state)
{
    lv_obj_t *temp = lv_label_create(obj);
    lv_obj_set_style_text_font(temp, AIR_COND_TITLE_FONT, 0);
    lv_obj_align(temp, LV_ALIGN_TOP_MID, 0, AIR_COND_TITLE_Y_OFFSET);
    lv_label_set_text(temp, "Air Conditioner");

    /* Indooor temperature label "26°C" */
    temp = lv_obj_create(obj);
    obj_conf_style_t style = {
        .width = LV_SIZE_CONTENT,
        .height = LV_SIZE_CONTENT,
        .pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET,
        .align = LV_ALIGN_CENTER,
        .x_offset = 0,
        .y_offset = -AIR_COND_TEMP_Y_OFFSET,
        .border_width = 0,
        .radius = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(temp, &style);
    lv_obj_set_flex_flow(temp, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(temp, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(temp, AIR_COND_TEMP_PAD, 0);
    lv_obj_clear_flag(temp, LV_OBJ_FLAG_SCROLLABLE);

    _label_indoor_temp = lv_label_create(temp);
    lv_obj_set_style_text_font(_label_indoor_temp, AIR_COND_TEMP_FONT_L, 0);
    lv_label_set_text_fmt(_label_indoor_temp, "%-d", _indoor_temperature);
    lv_obj_center(_label_indoor_temp);
    lv_obj_set_style_text_color(_label_indoor_temp, AIR_COND_COLOR_L_2, SMART_PANNEL_BG_STATE_ON);
    lv_obj_set_style_text_color(_label_indoor_temp, AIR_COND_COLOR_D_2, SMART_PANNEL_BG_STATE_OFF);

    lv_obj_t *label = lv_label_create(temp);
    lv_obj_set_style_text_font(label, AIR_COND_TITLE_FONT, 0);
    lv_label_set_text(label, "Indoor Temperature");

    _label_indoor_symb = lv_label_create(obj);
    lv_obj_set_style_text_font(_label_indoor_symb, AIR_COND_TEMP_SYMB_L, 0);
    lv_label_set_text(_label_indoor_symb, "°C");
    lv_obj_refr_size(_label_indoor_symb);
    int x_offset = lv_obj_get_width(_label_indoor_symb);
    lv_obj_align_to(_label_indoor_symb, _label_indoor_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
    lv_obj_set_style_text_color(_label_indoor_symb, AIR_COND_COLOR_L_2, SMART_PANNEL_BG_STATE_ON);
    lv_obj_set_style_text_color(_label_indoor_symb, AIR_COND_COLOR_D_2, SMART_PANNEL_BG_STATE_OFF);

    /* Temperature increase/decrease button */
    _btn_inc = lv_btn_create(obj);
    lv_obj_set_size(_btn_inc, AIR_COND_TEMP_BTN_W, AIR_COND_TEMP_BTN_H);
    lv_obj_align(_btn_inc, LV_ALIGN_BOTTOM_RIGHT, -AIR_COND_TEMP_BTN_OFFSET, -AIR_COND_TEMP_BTN_OFFSET);
    lv_obj_set_style_radius(_btn_inc, AIR_COND_TEMP_BTN_RADIUS, 0);
    lv_obj_set_style_pad_all(_btn_inc, 0, 0);
    lv_obj_set_style_border_width(_btn_inc, 2, 0);
    lv_obj_set_style_border_color(_btn_inc, lv_color_white(), 0);
    lv_obj_set_style_bg_color(_btn_inc, AIR_COND_TEMP_BTN_COLOR, 0);
    // lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_RELEASED, NULL);
    _label_inc = lv_label_create(_btn_inc);
    lv_obj_set_style_text_font(_label_inc, AIR_COND_TEMP_FONT_S, 0);
    lv_label_set_text(_label_inc, "+");
    lv_obj_center(_label_inc);
    lv_obj_set_style_text_color(_label_inc, AIR_COND_COLOR_L_2, SMART_PANNEL_BG_STATE_ON);
    lv_obj_set_style_text_color(_label_inc, AIR_COND_COLOR_D_2, SMART_PANNEL_BG_STATE_OFF);

    _btn_dec = lv_btn_create(obj);
    lv_obj_set_size(_btn_dec, AIR_COND_TEMP_BTN_W, AIR_COND_TEMP_BTN_H);
    lv_obj_align(_btn_dec, LV_ALIGN_BOTTOM_LEFT, AIR_COND_TEMP_BTN_OFFSET, -AIR_COND_TEMP_BTN_OFFSET);
    lv_obj_set_style_radius(_btn_dec, AIR_COND_TEMP_BTN_RADIUS, 0);
    lv_obj_set_style_pad_all(_btn_dec, 0, 0);
    lv_obj_set_style_border_width(_btn_dec, 2, 0);
    lv_obj_set_style_border_color(_btn_dec, lv_color_white(), 0);
    lv_obj_set_style_bg_color(_btn_dec, AIR_COND_TEMP_BTN_COLOR, 0);
    lv_obj_add_event_cb(_btn_dec, dec_btn_event, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(_btn_dec, dec_btn_event, LV_EVENT_RELEASED, NULL);
    _label_dec = lv_label_create(_btn_dec);
    lv_obj_set_style_text_font(_label_dec, AIR_COND_TEMP_FONT_S, 0);
    lv_label_set_text(_label_dec, "-");
    lv_obj_center(_label_dec);
    lv_obj_set_style_text_color(_label_dec, AIR_COND_COLOR_L_2, SMART_PANNEL_BG_STATE_ON);
    lv_obj_set_style_text_color(_label_dec, AIR_COND_COLOR_D_2, SMART_PANNEL_BG_STATE_OFF);
    _timer_btn = lv_timer_create(timer_btn_callback, AIR_COND_TEMP_BTN_PERIOD, NULL);
    lv_timer_pause(_timer_btn);

    /* Target temperature label "23°C"   */
    _label_target_temp = lv_label_create(obj);
    lv_obj_set_style_text_font(_label_target_temp, AIR_COND_TEMP_FONT_S, 0);
    lv_label_set_text_fmt(_label_target_temp, "%-d", _target_temperature);
    lv_obj_align(_label_target_temp, LV_ALIGN_BOTTOM_MID, 0, -AIR_COND_TEMP_BTN_OFFSET);
    lv_obj_set_style_text_color(_label_target_temp, AIR_COND_COLOR_L_2, SMART_PANNEL_BG_STATE_ON);
    lv_obj_set_style_text_color(_label_target_temp, AIR_COND_COLOR_D_2, SMART_PANNEL_BG_STATE_OFF);

    _label_target_symb = lv_label_create(obj);
    lv_obj_set_style_text_font(_label_target_symb, AIR_COND_TEMP_SYMB_S, 0);
    lv_label_set_text(_label_target_symb, "°C");
    lv_obj_refr_size(_label_target_symb);
    x_offset = lv_obj_get_width(_label_target_symb);
    lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
    lv_obj_set_style_text_color(_label_target_symb, AIR_COND_COLOR_L_2, SMART_PANNEL_BG_STATE_ON);
    lv_obj_set_style_text_color(_label_target_symb, AIR_COND_COLOR_D_2, SMART_PANNEL_BG_STATE_OFF);

    _state = state;
}

void ui_air_bg_register_callback_more_click(lv_event_cb_t func)
{
    _more_click_event = func;
}

void ui_air_bg_change_state(lv_state_t state)
{
    if (state == _state)
        return;

    // if (state == SMART_PANNEL_BG_STATE_ON) {
    //     // Switch button
    //     LV_IMG_DECLARE(img_switch_on);
    //     lv_img_set_src(_img_switch, &img_switch_on);
    // }
    // else if (state == SMART_PANNEL_BG_STATE_OFF) {
    //     // Switch button
    //     LV_IMG_DECLARE(img_switch_off);
    //     lv_img_set_src(_img_switch, &img_switch_off);
    // }
    // ON/OFF label
    // lv_obj_add_state(_label_on, state);
    // lv_obj_clear_state(_label_on, _state);
    // lv_obj_add_state(_label_off, state);
    // lv_obj_clear_state(_label_off, _state);
    // lv_obj_refresh_style(label_switch, LV_PART_ANY, LV_STYLE_PROP_ANY);
    // Indoor temperature label
    lv_obj_clear_state(_label_indoor_temp, _state);
    lv_obj_add_state(_label_indoor_temp, state);
    lv_obj_clear_state(_label_indoor_symb, _state);
    lv_obj_add_state(_label_indoor_symb, state);
    // Increase/decrease button
    lv_obj_clear_state(_label_inc, _state);
    lv_obj_add_state(_label_inc, state);
    lv_obj_clear_state(_label_dec, _state);
    lv_obj_add_state(_label_dec, state);
    if (state == SMART_PANNEL_BG_STATE_ON) {
        lv_obj_add_flag(_btn_inc, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(_btn_dec, LV_OBJ_FLAG_CLICKABLE);
    }
    else {
        lv_obj_clear_flag(_btn_inc, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_clear_flag(_btn_dec, LV_OBJ_FLAG_CLICKABLE);
    }
    // Target temperature label
    lv_obj_clear_state(_label_target_temp, _state);
    lv_obj_add_state(_label_target_temp, state);
    lv_obj_clear_state(_label_target_symb, _state);
    lv_obj_add_state(_label_target_symb, state);

    _state = state;
}

void ui_air_bg_indoor_temp_set(int temp)
{
    if ((temp >= AIR_COND_TEMP_MAX) || (temp <= AIR_COND_TEMP_MIN))
        return;

    lv_label_set_text_fmt(_label_indoor_temp, "%-d", temp);
    int x_offset = lv_obj_get_width(_label_indoor_symb);
    lv_obj_align_to(_label_indoor_symb, _label_indoor_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

void ui_air_bg_indoor_temp_inc(void)
{
    if (_indoor_temperature >= AIR_COND_TEMP_MAX)
        return;

    lv_label_set_text_fmt(_label_indoor_temp, "%-d", ++_indoor_temperature);
    int x_offset = lv_obj_get_width(_label_indoor_symb);
    lv_obj_align_to(_label_indoor_symb, _label_indoor_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

void ui_air_bg_indoor_temp_dec(void)
{
    if (_indoor_temperature <= AIR_COND_TEMP_MIN)
        return;

    lv_label_set_text_fmt(_label_indoor_temp, "%-d", --_indoor_temperature);
    int x_offset = lv_obj_get_width(_label_indoor_symb);
    lv_obj_align_to(_label_indoor_symb, _label_indoor_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

void ui_air_bg_target_temp_set(int temp)
{
    if ((temp >= AIR_COND_TEMP_MAX) || (temp <= AIR_COND_TEMP_MIN))
        return;

    lv_label_set_text_fmt(_label_target_temp, "%-d", temp);
    int x_offset = lv_obj_get_width(_label_target_symb);
    lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

void ui_air_bg_target_temp_inc(void)
{
    if (_target_temperature >= AIR_COND_TEMP_MAX)
        return;

    lv_label_set_text_fmt(_label_target_temp, "%-d", ++_target_temperature);
    int x_offset = lv_obj_get_width(_label_target_symb);
    lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

void ui_air_bg_target_temp_dec(void)
{
    if (_target_temperature <= AIR_COND_TEMP_MIN)
        return;

    lv_label_set_text_fmt(_label_target_temp, "%-d", --_target_temperature);
    int x_offset = lv_obj_get_width(_label_target_symb);
    lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

static void img_switch_click_event(lv_event_t * e)
{
    if (_state == SMART_PANNEL_BG_STATE_ON) {
        ui_air_bg_change_state(SMART_PANNEL_BG_STATE_OFF);
    }
    else {
        ui_air_bg_change_state(SMART_PANNEL_BG_STATE_ON);
    }
}

static void img_more_click_event(lv_event_t * e)
{
    if (_more_click_event)
        _more_click_event(e);
}

static void inc_btn_event(lv_event_t *e)
{
    switch (lv_event_get_code(e)) {
        case LV_EVENT_PRESSED:
            _inc_flag = true;
            ui_air_bg_indoor_temp_inc();
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
            ui_air_bg_indoor_temp_dec();
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
        ui_air_bg_indoor_temp_inc();
    }
    else {
        ui_air_bg_indoor_temp_dec();
    }
}