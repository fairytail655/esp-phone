#include "smart_pannel.h"
#include "ui_heater_conf.h"
#include "ui_heater_fg.h"

static int *_target_temperature;
static lv_obj_t *_label_target_temp;
static lv_obj_t *_label_target_symb;
static lv_obj_t *_btn_inc, *_btn_dec;
static lv_obj_t *_label_inc, *_label_dec;
static lv_timer_t *_timer_btn;
static bool _inc_flag = true;

void ui_heater_fg_init(lv_obj_t *obj)
{
    // /* Temperature increase/decrease button */
    // _btn_inc = lv_btn_create(obj);
    // lv_obj_set_size(_btn_inc, BG_TEMP_BTN_W, BG_TEMP_BTN_H);
    // lv_obj_align(_btn_inc, LV_ALIGN_TOP_RIGHT, -BG_TEMP_BTN_OFFSET, BG_TEMP_BTN_OFFSET);
    // lv_obj_set_style_radius(_btn_inc, BG_TEMP_BTN_RADIUS, 0);
    // lv_obj_set_style_pad_all(_btn_inc, 0, 0);
    // lv_obj_set_style_border_width(_btn_inc, 2, 0);
    // lv_obj_set_style_border_color(_btn_inc, lv_color_white(), 0);
    // lv_obj_set_style_bg_color(_btn_inc, BG_TEMP_BTN_COLOR, 0);
    // // lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_CLICKED, NULL);
    // lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_PRESSED, NULL);
    // lv_obj_add_event_cb(_btn_inc, inc_btn_event, LV_EVENT_RELEASED, NULL);
    // _label_inc = lv_label_create(_btn_inc);
    // lv_obj_set_style_text_font(_label_inc, BG_TEMP_FONT_S, 0);
    // lv_label_set_text(_label_inc, "+");
    // lv_obj_center(_label_inc);
    // lv_obj_set_style_text_color(_label_inc, BG_COLOR_L_2, INTERFACE_STATE_ON);
    // lv_obj_set_style_text_color(_label_inc, BG_COLOR_D_2, INTERFACE_STATE_OFF);

    // _btn_dec = lv_btn_create(obj);
    // lv_obj_set_size(_btn_dec, BG_TEMP_BTN_W, BG_TEMP_BTN_H);
    // lv_obj_align(_btn_dec, LV_ALIGN_BOTTOM_LEFT, BG_TEMP_BTN_OFFSET, -BG_TEMP_BTN_OFFSET);
    // lv_obj_set_style_radius(_btn_dec, BG_TEMP_BTN_RADIUS, 0);
    // lv_obj_set_style_pad_all(_btn_dec, 0, 0);
    // lv_obj_set_style_border_width(_btn_dec, 2, 0);
    // lv_obj_set_style_border_color(_btn_dec, lv_color_white(), 0);
    // lv_obj_set_style_bg_color(_btn_dec, BG_TEMP_BTN_COLOR, 0);
    // lv_obj_add_event_cb(_btn_dec, dec_btn_event, LV_EVENT_PRESSED, NULL);
    // lv_obj_add_event_cb(_btn_dec, dec_btn_event, LV_EVENT_RELEASED, NULL);
    // _label_dec = lv_label_create(_btn_dec);
    // lv_obj_set_style_text_font(_label_dec, BG_TEMP_FONT_S, 0);
    // lv_label_set_text(_label_dec, "-");
    // lv_obj_center(_label_dec);
    // lv_obj_set_style_text_color(_label_dec, BG_COLOR_L_2, INTERFACE_STATE_ON);
    // lv_obj_set_style_text_color(_label_dec, BG_COLOR_D_2, INTERFACE_STATE_OFF);
    // _timer_btn = lv_timer_create(timer_btn_callback, BG_TEMP_BTN_PERIOD, NULL);
    // lv_timer_pause(_timer_btn);

    // /* Target temperature label "23°C"   */
    // _label_target_temp = lv_label_create(obj);
    // lv_obj_set_style_text_font(_label_target_temp, BG_TEMP_FONT_S, 0);
    // lv_label_set_text_fmt(_label_target_temp, "%-d", _target_temperature);
    // lv_obj_align(_label_target_temp, LV_ALIGN_BOTTOM_MID, 0, -BG_TEMP_BTN_OFFSET);
    // lv_obj_set_style_text_color(_label_target_temp, BG_COLOR_L_2, INTERFACE_STATE_ON);
    // lv_obj_set_style_text_color(_label_target_temp, BG_COLOR_D_2, INTERFACE_STATE_OFF);

    // _label_target_symb = lv_label_create(obj);
    // lv_obj_set_style_text_font(_label_target_symb, BG_TEMP_SYMB_S, 0);
    // lv_label_set_text(_label_target_symb, "°C");
    // lv_obj_refr_size(_label_target_symb);
    // x_offset = lv_obj_get_width(_label_target_symb);
    // lv_obj_align_to(_label_target_symb, _label_target_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
    // lv_obj_set_style_text_color(_label_target_symb, BG_COLOR_L_2, INTERFACE_STATE_ON);
    // lv_obj_set_style_text_color(_label_target_symb, BG_COLOR_D_2, INTERFACE_STATE_OFF);
}
