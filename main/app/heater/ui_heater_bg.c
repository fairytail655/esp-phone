#include "smart_pannel.h"
#include "ui_heater_conf.h"
#include "ui_heater_bg.h"

static void heat_btn_init(lv_obj_t *obj);
static void heat_btn_event(lv_event_t *e);
static void rest_btn_event(lv_event_t *e);

static lv_obj_t *_label_water_temp;
static lv_obj_t *_label_water_symb;
static lv_obj_t *_btn_heat, *_btn_rest;
static lv_obj_t *_label_heat, *_label_rest;
static lv_obj_t *_img_heat, *_img_rest;

static lv_event_cb_t _heat_click_cb;
static lv_event_cb_t _rest_click_cb;

void ui_heater_bg_init(lv_obj_t *obj)
{
    lv_obj_t *temp = lv_label_create(obj);
    lv_obj_set_style_text_font(temp, BG_TITLE_FONT, 0);
    lv_obj_align(temp, LV_ALIGN_TOP_MID, 0, BG_TITLE_Y_OFFSET);
    lv_label_set_text(temp, "Heater");

    /* Water temperature label "35°C" */
    temp = lv_obj_create(obj);
    obj_conf_style_t style = {
        .width = LV_SIZE_CONTENT,
        .height = LV_SIZE_CONTENT,
        .pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET,
        .align = LV_ALIGN_CENTER,
        .x_offset = 0,
        .y_offset = -BG_TEMP_Y_OFFSET,
        .border_width = 0,
        .radius = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(temp, &style);
    lv_obj_set_flex_flow(temp, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(temp, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_row(temp, BG_TEMP_PAD, 0);
    lv_obj_clear_flag(temp, LV_OBJ_FLAG_SCROLLABLE);

    _label_water_temp = lv_label_create(temp);
    lv_obj_set_style_text_font(_label_water_temp, BG_TEMP_FONT_L, 0);
    lv_obj_center(_label_water_temp);
    lv_obj_set_style_text_color(_label_water_temp, BG_COLOR_L_2, INTERFACE_STATE_ON);
    lv_obj_set_style_text_color(_label_water_temp, BG_COLOR_D_2, INTERFACE_STATE_OFF);

    lv_obj_t *label = lv_label_create(temp);
    lv_obj_set_style_text_font(label, BG_TITLE_FONT, 0);
    lv_label_set_text(label, "Water Temperature");

    _label_water_symb = lv_label_create(obj);
    lv_obj_set_style_text_font(_label_water_symb, BG_TEMP_SYMB_L, 0);
    lv_label_set_text(_label_water_symb, "°C");
    lv_obj_refr_size(_label_water_symb);
    int x_offset = lv_obj_get_width(_label_water_symb);
    lv_obj_align_to(_label_water_symb, _label_water_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
    lv_obj_set_style_text_color(_label_water_symb, BG_COLOR_L_2, INTERFACE_STATE_ON);
    lv_obj_set_style_text_color(_label_water_symb, BG_COLOR_D_2, INTERFACE_STATE_OFF);

    /* Button */
    heat_btn_init(obj);
}

void ui_heater_bg_register_cb(lv_event_cb_t heat, lv_event_cb_t rest)
{
    _heat_click_cb = heat;
    _rest_click_cb = rest;
}

void ui_heater_bg_change_state(smart_pannel_state_t state)
{
    // water temperature label
    lv_obj_clear_state(_label_water_temp, ~state);
    lv_obj_add_state(_label_water_temp, state);
    lv_obj_clear_state(_label_water_symb, ~state);
    lv_obj_add_state(_label_water_symb, state);
}

void ui_heater_bg_water_temp_set(int temp)
{
    if ((temp >= TEMP_MAX) ||
        (temp <= TEMP_MIN))
        return;

    lv_label_set_text_fmt(_label_water_temp, "%-d", temp);
    int x_offset = lv_obj_get_width(_label_water_symb);
    lv_obj_align_to(_label_water_symb, _label_water_temp, LV_ALIGN_TOP_RIGHT, x_offset, 0);
}

void ui_heater_bg_heat_set_state(interface_state_t state)
{
    if (state == INTERFACE_STATE_OFF)
        lv_img_set_src(_img_heat, &img_fire_off);
    else
        lv_img_set_src(_img_heat, &img_fire_on);
    lv_obj_clear_state(_label_heat, ~state);
    lv_obj_add_state(_label_heat, state);
}

void ui_heater_bg_rest_set_state(interface_state_t state)
{
    if (state == INTERFACE_STATE_OFF)
        lv_img_set_src(_img_rest, &img_rest_off);
    else
        lv_img_set_src(_img_rest, &img_rest_on);
    lv_obj_clear_state(_label_rest, ~state);
    lv_obj_add_state(_label_rest, state);
}

void ui_heater_bg_heat_enabel(bool flag)
{
    if (flag)
        lv_obj_add_flag(_btn_heat, LV_OBJ_FLAG_CLICKABLE);
    else
        lv_obj_clear_flag(_btn_heat, LV_OBJ_FLAG_CLICKABLE);
}

void ui_heater_bg_rest_enabel(bool flag)
{
    if (flag)
        lv_obj_add_flag(_btn_rest, LV_OBJ_FLAG_CLICKABLE);
    else
        lv_obj_clear_flag(_btn_rest, LV_OBJ_FLAG_CLICKABLE);
}

static void heat_btn_init(lv_obj_t *obj)
{
    // Container
    lv_obj_t *container = lv_obj_create(obj);
    obj_conf_style_t style = {
        .width = BG_CONT_WIDTH,
        .height = BG_CONT_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET,
        .align = LV_ALIGN_BOTTOM_MID,
        .x_offset = 0,
        .y_offset = -BG_CONT_OFFSET,
        .radius = 0,
        .border_width = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(container, &style);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(container, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(container, MODE_BTN_PAD, 0);
    lv_obj_clear_flag(container, LV_OBJ_FLAG_SCROLLABLE);

    // Heating button
    _btn_heat = lv_obj_create(container);
    style.height = BG_CONT_HEIGHT;
    style.radius = BG_BTN_RADIUS;
    style.border_width = 1;
    style.bg_color = BG_BTN_COLOR;
    style.bg_opa = BG_BTN_OPA;
    obj_conf_style(_btn_heat, &style);
    lv_obj_set_style_border_color(_btn_heat, lv_color_white(), 0);
    lv_obj_set_flex_grow(_btn_heat, 1);
    lv_obj_add_flag(_btn_heat, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(_btn_heat, heat_btn_event, LV_EVENT_CLICKED, NULL);
    _label_heat = lv_label_create(_btn_heat);
    lv_obj_set_style_text_font(_label_heat, BG_BTN_FONT, 0);
    lv_obj_set_style_text_color(_label_heat, BG_BTN_FONT_COLOR_ON, INTERFACE_STATE_ON);
    lv_obj_set_style_text_color(_label_heat, BG_BTN_FONT_COLOR_OFF, INTERFACE_STATE_OFF);
    lv_label_set_text(_label_heat, "Heating");
    lv_obj_align(_label_heat, LV_ALIGN_RIGHT_MID, -30, 0);
    _img_heat = lv_img_create(_btn_heat);
    lv_img_set_src(_img_heat, &img_fire_on);
    lv_obj_align(_img_heat, LV_ALIGN_LEFT_MID, BG_BTN_IMG_OFFSET, 0);

    // Rest button
    _btn_rest = lv_obj_create(container);
    style.height = BG_CONT_HEIGHT;
    style.radius = BG_BTN_RADIUS;
    style.border_width = 1;
    style.bg_color = BG_BTN_COLOR;
    style.bg_opa = BG_BTN_OPA;
    obj_conf_style(_btn_rest, &style);
    lv_obj_set_style_border_color(_btn_rest, lv_color_white(), 0);
    lv_obj_set_flex_grow(_btn_rest, 1);
    lv_obj_add_flag(_btn_rest, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(_btn_rest, rest_btn_event, LV_EVENT_CLICKED, NULL);
    _label_rest = lv_label_create(_btn_rest);
    lv_obj_set_style_text_font(_label_rest, BG_BTN_FONT, 0);
    lv_obj_set_style_text_color(_label_rest, BG_BTN_FONT_COLOR_ON, INTERFACE_STATE_ON);
    lv_obj_set_style_text_color(_label_rest, BG_BTN_FONT_COLOR_OFF, INTERFACE_STATE_OFF);
    lv_label_set_text(_label_rest, "Rest Time:\n\t\t\t20");
    lv_obj_align(_label_rest, LV_ALIGN_RIGHT_MID, -30, 0);
    _img_rest = lv_img_create(_btn_rest);
    lv_img_set_src(_img_rest, &img_rest_on);
    lv_obj_align(_img_rest, LV_ALIGN_LEFT_MID, BG_BTN_IMG_OFFSET, 0);
}

static void heat_btn_event(lv_event_t *e)
{
    if (_heat_click_cb)
        _heat_click_cb(e);
}

static void rest_btn_event(lv_event_t *e)
{
    if (_rest_click_cb)
        _rest_click_cb(e);
}
