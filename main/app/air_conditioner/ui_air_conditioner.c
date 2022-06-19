#include "smart_pannel.h"
#include "../app_conf.h"
#include "ui_air_conditioner.h"

static lv_obj_t *label_switch;
static lv_obj_t *_label_on, *_label_off;
static lv_obj_t *_img_switch;
static lv_state_t _state = APP_STATE_ON;

static void img_switch_click_event(lv_event_t * e);

void ui_air_cond_init(lv_obj_t *obj)
{
    label_switch = lv_obj_create(obj);
    obj_conf_style_t style = {
        .width = LV_SIZE_CONTENT,
        .height = LV_SIZE_CONTENT,
        .pos_flag = OBJ_POS_FLAG_XY,
        .x_offset = AIR_COND_SWITCH_X,
        .y_offset = AIR_COND_SWITCH_Y,
        .border_width = 0,
        .radius = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(label_switch, &style);
    lv_obj_set_flex_flow(label_switch, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(label_switch, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(label_switch, AIR_COND_SWITCH_PAD, 0);
    lv_obj_clear_flag(label_switch, LV_OBJ_FLAG_SCROLLABLE);

    _label_on = lv_label_create(label_switch);
    lv_obj_set_style_text_font(_label_on, AIR_COND_SWITCH_FONT_L, APP_STATE_ON);
    lv_obj_set_style_text_color(_label_on, AIR_COND_COLOR_L_1, APP_STATE_ON);
    lv_obj_set_style_text_font(_label_on, AIR_COND_SWITCH_FONT_S, APP_STATE_OFF);
    lv_obj_set_style_text_color(_label_on, AIR_COND_COLOR_D_1, APP_STATE_OFF);
    lv_label_set_text(_label_on, "ON");

    lv_obj_t *temp = lv_label_create(label_switch);
    lv_obj_set_style_text_font(temp, AIR_COND_SWITCH_FONT_L, 0);
    lv_label_set_text(temp, "/");

    _label_off = lv_label_create(label_switch);
    lv_obj_set_style_text_font(_label_off, AIR_COND_SWITCH_FONT_S, APP_STATE_ON);
    lv_obj_set_style_text_color(_label_off, AIR_COND_COLOR_D_1, APP_STATE_ON);
    lv_obj_set_style_text_font(_label_off, AIR_COND_SWITCH_FONT_L, APP_STATE_OFF);
    lv_obj_set_style_text_color(_label_off, AIR_COND_COLOR_L_1, APP_STATE_OFF);
    lv_label_set_text(_label_off, "OFF");

    temp = lv_label_create(obj);
    lv_obj_set_style_text_font(temp, AIR_COND_SWITCH_FONT_S, 0);
    lv_obj_align(temp, LV_ALIGN_TOP_MID, 0, AIR_COND_SWITCH_Y);
    lv_label_set_text(temp, "Air Conditioner");

    _img_switch = lv_img_create(obj);
    lv_obj_refr_size(obj);
    int x = lv_obj_get_width(obj);
    x = x - AIR_COND_SWITCH_X - AIR_COND_SWITCH_ICON_SIZE;
    lv_obj_set_pos(_img_switch, x, AIR_COND_SWITCH_Y);
    LV_IMG_DECLARE(img_switch_on);
    lv_img_set_src(_img_switch, &img_switch_on);
    // Calculate the multiple of the size between the target and the image.
    float h_factor, w_factor;
    h_factor = (float)AIR_COND_SWITCH_ICON_SIZE / img_switch_on.header.h;
    w_factor = (float)AIR_COND_SWITCH_ICON_SIZE / img_switch_on.header.w;
    // Scale the image to a suitable size.
    // So you don’t have to consider the size of the source image.
    if (h_factor < w_factor) {
        lv_img_set_zoom(_img_switch, (int)(h_factor * LV_IMG_ZOOM_NONE));
    }
    else {
        lv_img_set_zoom(_img_switch, (int)(w_factor * LV_IMG_ZOOM_NONE));
    }
    lv_obj_set_style_transform_zoom(_img_switch, (int)(LV_IMG_ZOOM_NONE * AIR_COND_SWITCH_ZOOM_PERCENT / 100.0), LV_STATE_PRESSED);
    lv_obj_set_style_transform_zoom(_img_switch, LV_IMG_ZOOM_NONE, LV_STATE_DEFAULT);
    lv_obj_add_flag(_img_switch, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(_img_switch, img_switch_click_event, LV_EVENT_CLICKED, NULL);
}

void ui_air_cond_change_state(lv_state_t state)
{
    if (state == _state)
        return;

    if (state == APP_STATE_ON) {
        // switch button
        LV_IMG_DECLARE(img_switch_on);
        lv_img_set_src(_img_switch, &img_switch_on);
    }
    else if (state == APP_STATE_OFF) {
        // switch button
        LV_IMG_DECLARE(img_switch_off);
        lv_img_set_src(_img_switch, &img_switch_off);
    }
    // on/off label
    lv_obj_add_state(_label_on, state);
    lv_obj_clear_state(_label_on, _state);
    lv_obj_add_state(_label_off, state);
    lv_obj_clear_state(_label_off, _state);
    lv_obj_refresh_style(label_switch, LV_PART_ANY, LV_STYLE_PROP_ANY);

    _state = state;
}

static void img_switch_click_event(lv_event_t * e)
{
    if (_state == APP_STATE_ON) {
        ui_air_cond_change_state(APP_STATE_OFF);
    }
    else {
        ui_air_cond_change_state(APP_STATE_ON);
    }
}
