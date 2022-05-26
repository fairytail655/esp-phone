#include <stdint.h>
#include "../interface_conf.h"
#include "../../utils/utils.h"
#include "status_clock.h"

static uint8_t _day = 0, _hour = 12, _min = 0, _sec = 0;
static lv_obj_t *_label_day, *_label_hour, *_label_min, *_label_sec;
static const char *_day_str[] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"
};

void status_clock_init(lv_obj_t *parent)
{
    // Parent layout
    lv_obj_set_flex_flow(parent, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(parent, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(parent, LV_OBJ_FLAG_SCROLLABLE);

    // Main area
    lv_obj_t *obj = lv_obj_create(parent);
    obj_conf_style_t style = {
        .pos_flag = OBJ_POS_FLAG_ALIGN,
        .align = LV_ALIGN_CENTER,
        .radius = 0,
        .border_width = 0,
        .padd_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    lv_obj_update_layout(parent);
    style.width = lv_obj_get_width(parent);
    style.height = lv_obj_get_height(parent);
    obj_conf_style(obj, &style);
    // Config layout
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(obj, 5, 0);
    lv_obj_set_style_pad_column(obj, 5, 0);
    lv_obj_set_style_text_font(obj, STATUSBAR_CLOCK_FONT, 0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    // Day of week area
    _label_day = lv_label_create(obj);
    lv_obj_set_style_bg_opa(_label_day, LV_OPA_TRANSP, 0);
    lv_label_set_text(_label_day, _day_str[_day]);

    // Time area
    lv_obj_t *time = lv_obj_create(obj);
    style.width = LV_SIZE_CONTENT;
    style.height = LV_SIZE_CONTENT;
    obj_conf_style(time, &style);
    // Config layout
    lv_obj_set_flex_flow(time, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(time, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(time, 0, 0);
    lv_obj_set_style_pad_row(time, 0, 0);
    // Hour
    _label_hour = lv_label_create(time);
    lv_obj_set_style_bg_opa(_label_hour, LV_OPA_TRANSP, 0);
    lv_label_set_text_fmt(_label_hour, "%02d", _hour);
    // Dot
    lv_obj_t *label_dot_1 = lv_label_create(time);
    lv_obj_set_style_bg_opa(label_dot_1, LV_OPA_TRANSP, 0);
    lv_label_set_text(label_dot_1, ":");
    // Minute
    _label_min = lv_label_create(time);
    lv_obj_set_style_bg_opa(_label_min, LV_OPA_TRANSP, 0);
    lv_label_set_text_fmt(_label_min, "%02d", _min);
#if STATUSBAR_CLOCK_SECOND_EN
    // Dot
    lv_obj_t *label_dot_2 = lv_label_create(time);
    lv_obj_set_style_bg_opa(label_dot_2, LV_OPA_TRANSP, 0);
    lv_label_set_text(label_dot_2, ":");
    // Second
    _label_sec = lv_label_create(time);
    lv_obj_set_style_bg_opa(_label_sec, LV_OPA_TRANSP, 0);
    lv_label_set_text_fmt(_label_sec, "%02d", _sec);
#endif

    GUI_TRACE("status_clock init finished");
}

void status_clock_set_time(uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
    if ((day > 7) || (day < 1)) {
        LV_LOG_WARN("day [%d] out of range", day);
        return;
    }
    else if (_day != day) {
        _day = day;
        lv_label_set_text_fmt(_label_day, "%s", _day_str[day - 1]);
    }

#if STATUSBAR_CLOCK_FORMAT_24
    if (_hour > 23) {
#else
    if (_hour > 12) {
#endif
        LV_LOG_WARN("hour [%d] out of range", _hour);
        return;
    }
    else if (_hour != hour) {
        _hour = hour;
        lv_label_set_text_fmt(_label_hour, "%02d", hour);
    }

    if (_min > 59) {
        LV_LOG_WARN("minute [%d] out of range", _min);
        return;
    }
    if (_min != min) {
        _min = min;
        lv_label_set_text_fmt(_label_min, "%02d", min);
    }

#if STATUSBAR_CLOCK_SECOND_EN
    if (_sec > 59) {
        LV_LOG_WARN("minute [%d] out of range", _sec);
        return;
    }
    if (_sec != sec) {
        _sec = sec;
        lv_label_set_text_fmt(_label_sec, "%02d", sec);
    }
#else
    (void)_sec;
#endif

    GUI_TRACE("status_clock set time: %s-%02d:%02d:%02d", _day_str[day - 1], hour, min, sec);
}
