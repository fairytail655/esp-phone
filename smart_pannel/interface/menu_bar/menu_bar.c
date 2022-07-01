#include "interface/interface_conf.h"
#include "utils/utils.h"
#include "menu_bar.h"

static void bottom_event_cb(lv_event_t *e);

static const char *_day_str[] = {
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
};
static lv_obj_t *_menu_bar;
static lv_obj_t *_cal_contain;
static menu_time_t _time = {
    .hour = 12,
    .min = 0,
    .month = 3,
    .day = 14,
    .week = MENU_DAY_MONDAY,
};

static lv_anim_t _move_anim;
static int _y;

static lv_event_code_t _press_event_id;
static lv_event_code_t _pressing_event_id;
static lv_event_code_t _click_event_id;

void menu_init(lv_obj_t *obj)
{
    // Main Area
    _menu_bar = lv_obj_create(obj);
    obj_conf_style_t style = {
        .width = MENU_BAR_WIDTH,
        .height = MENU_BAR_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_XY,
        .x_offset = (LV_HOR_RES - MENU_BAR_WIDTH) / 2,
        .y_offset = MENU_BAR_Y_ORGIN,
        .border_width = 0,
        .pad_all = 0,
        .radius = MENU_BAR_RADIUS,
        .bg_color = MENU_BAR_BG_COLOR,
        .bg_opa = MENU_BAR_BG_OPA,
    };
    obj_conf_style(_menu_bar, &style);
    lv_obj_set_style_text_font(_menu_bar, MENU_BAR_FONT, 0);
    lv_obj_clear_flag(_menu_bar, LV_OBJ_FLAG_SCROLLABLE);
    menu_bar_show(false);
    _y = menu_bar_current_y();

    // Calendar
    _cal_contain= lv_label_create(_menu_bar);
    lv_label_set_text_fmt(
        _cal_contain, "%02d:%02d\t%02d-%02d\t%s", _time.hour, _time.min,
        _time.month, _time.day, _day_str[_time.week]
    );
    lv_obj_align(_cal_contain, LV_ALIGN_TOP_LEFT, MENU_BAR_CAL_X_OFFSET, MENU_BAR_CAL_Y_OFFSET);

    // bottom
    lv_obj_t *bottom = lv_obj_create(_menu_bar);
    style.height = MENU_BAR_BOTTOM_HEIGHT;
    style.pos_flag = OBJ_POS_FLAG_ALIGN;
    style.align = LV_ALIGN_BOTTOM_MID;
    style.bg_opa = LV_OPA_TRANSP;
    obj_conf_style(bottom, &style);
    lv_obj_add_flag(bottom, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(bottom, bottom_event_cb, LV_EVENT_PRESSED, obj);
    lv_obj_add_event_cb(bottom, bottom_event_cb, LV_EVENT_PRESSING, obj);
    lv_obj_add_event_cb(bottom, bottom_event_cb, LV_EVENT_CLICKED, obj);
    lv_obj_clear_flag(bottom, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_t *bottom_line = lv_line_create(bottom);
    static lv_point_t line_points[2];
    line_points[0].x = 0;
    line_points[0].y = 0;
    line_points[1].x = MENU_BAR_LINE_WIDTH;
    line_points[1].y = 0;
    lv_line_set_points(bottom_line, (const lv_point_t *)&line_points, 2);
    lv_obj_set_style_line_rounded(bottom_line, true, 0);
    lv_obj_set_style_line_width(bottom_line, MENU_BAR_LINE_HEIGHT, 0);
    lv_obj_set_style_line_color(bottom_line, MENU_BAR_LINE_COLOR, 0);
    lv_obj_center(bottom_line);

    _press_event_id = lv_event_register_id();
    _pressing_event_id = lv_event_register_id();
    _click_event_id = lv_event_register_id();
}

void menu_bar_set_anim_cb(void *f)
{
    lv_anim_set_ready_cb(&_move_anim, (lv_anim_ready_cb_t)f);
}

lv_event_code_t menu_bar_get_event_id_press(void)
{
    return _press_event_id;
}

lv_event_code_t menu_bar_get_event_id_pressing(void)
{
    return _pressing_event_id;
}

lv_event_code_t menu_bar_get_event_id_click(void)
{
    return _click_event_id;
}

void menu_bar_show(bool en)
{
    if (en)
        lv_obj_set_style_opa(_menu_bar, LV_OPA_COVER, 0);
    else
        lv_obj_set_style_opa(_menu_bar, LV_OPA_TRANSP, 0);
}

int menu_bar_current_y(void)
{
    lv_obj_refr_pos(_menu_bar);
    return lv_obj_get_y(_menu_bar);
}

int menu_bar_origin_y(void)
{
    return _y;
}

void menu_bar_move_y(int y)
{
    lv_obj_set_y(_menu_bar, y);
}

void menu_bar_start_anim(int y)
{
    lv_anim_set_values(&_move_anim, menu_bar_current_y(), y);
    lv_anim_start(&_move_anim);
}

static void bottom_event_cb(lv_event_t *e)
{
    lv_obj_t *obj = (lv_obj_t *)lv_event_get_user_data(e);
    lv_event_code_t code = lv_event_get_code(e);

    if (code == LV_EVENT_PRESSED) {
        LV_LOG_ERROR("obj press");
        lv_event_send(obj, _press_event_id, NULL);
    }
    else if (code == LV_EVENT_PRESSING) {
        LV_LOG_ERROR("obj pressing");
        lv_event_send(obj, _pressing_event_id, NULL);
    }
    else if (code == LV_EVENT_CLICKED) {
        LV_LOG_ERROR("obj click");
        lv_event_send(obj, _click_event_id, NULL);
    }
}
