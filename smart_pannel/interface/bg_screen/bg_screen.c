#include "interface/interface_conf.h"
#include "utils/utils.h"
#include "bg_screen.h"

static lv_obj_t *_scr = NULL;

static lv_obj_t *_label_switch;
static lv_obj_t *_label_on, *_label_off;
static lv_obj_t *_img_switch;
static bg_board_state_t _state = BG_BOARD_STATE_OFF;

void bg_screen_init(void)
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

    _label_on = lv_label_create(_label_switch);
    lv_obj_set_style_text_font(_label_on, LABEL_SWITCH_FONT_L, 0);
    lv_obj_set_style_text_color(_label_on, LABEL_COLOR_L_1, LV_STATE_USER_1);
    lv_obj_set_style_text_font(_label_on, LABEL_SWITCH_FONT_S, 0);
    lv_obj_set_style_text_color(_label_on, LABEL_COLOR_D_1, 0);
    lv_label_set_text(_label_on, "ON");

    lv_obj_t *temp = lv_label_create(_label_switch);
    lv_obj_set_style_text_font(temp, LABEL_SWITCH_FONT_L, 0);
    lv_label_set_text(temp, "/");

    _label_off = lv_label_create(_label_switch);
    lv_obj_set_style_text_font(_label_off, LABEL_SWITCH_FONT_S, LV_STATE_USER_1);
    lv_obj_set_style_text_color(_label_off, LABEL_COLOR_D_1, LV_STATE_USER_1);
    lv_obj_set_style_text_font(_label_off, LABEL_SWITCH_FONT_L, 0);
    lv_obj_set_style_text_color(_label_off, LABEL_COLOR_L_1, 0);
    lv_label_set_text(_label_off, "OFF");

    // /* Switch button */
    // _img_switch = lv_img_create(obj);
    // lv_obj_refr_size(obj);
    // int x = lv_obj_get_width(obj);
    // x = x - LABEL_SWITCH_X - LABEL_SWITCH_ICON_SIZE;
    // lv_obj_set_pos(_img_switch, x, LABEL_SWITCH_Y);
    // LV_IMG_DECLARE(img_switch_on);
    // lv_img_set_src(_img_switch, &img_switch_on);
    // // Calculate the multiple of the size between the target and the image.
    // float h_factor, w_factor;
    // h_factor = (float)LABEL_SWITCH_ICON_SIZE / img_switch_on.header.h;
    // w_factor = (float)LABEL_SWITCH_ICON_SIZE / img_switch_on.header.w;
    // // Scale the image to a suitable size.
    // // So you don’t have to consider the size of the source image.
    // if (h_factor < w_factor) {
    //     lv_img_set_zoom(_img_switch, (int)(h_factor * LV_IMG_ZOOM_NONE));
    // }
    // else {
    //     lv_img_set_zoom(_img_switch, (int)(w_factor * LV_IMG_ZOOM_NONE));
    // }
    // lv_obj_set_style_transform_zoom(_img_switch, (int)(LV_IMG_ZOOM_NONE * LABEL_SWITCH_ZOOM_PERCENT / 100.0), LV_STATE_PRESSED);
    // lv_obj_set_style_transform_zoom(_img_switch, LV_IMG_ZOOM_NONE, LV_STATE_DEFAULT);
    // lv_obj_add_flag(_img_switch, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(_img_switch, img_switch_click_event, LV_EVENT_CLICKED, NULL);

    // /* More button */
    // temp = lv_img_create(obj);
    // lv_obj_refr_pos(_img_switch);
    // int y = lv_obj_get_y(_img_switch);
    // y += LABEL_SWITCH_ICON_SIZE + LABEL_SWITCH_OFFSET;
    // lv_obj_set_pos(temp, lv_obj_get_x(_img_switch), y);
    // LV_IMG_DECLARE(img_more);
    // lv_img_set_src(temp, &img_more);
    // // Calculate the multiple of the size between the target and the image.
    // h_factor = (float)LABEL_SWITCH_ICON_SIZE / img_switch_on.header.h;
    // w_factor = (float)LABEL_SWITCH_ICON_SIZE / img_switch_on.header.w;
    // // Scale the image to a suitable size.
    // // So you don’t have to consider the size of the source image.
    // if (h_factor < w_factor) {
    //     lv_img_set_zoom(temp, (int)(h_factor * LV_IMG_ZOOM_NONE));
    // }
    // else {
    //     lv_img_set_zoom(temp, (int)(w_factor * LV_IMG_ZOOM_NONE));
    // }
    // lv_obj_set_style_transform_zoom(temp, (int)(LV_IMG_ZOOM_NONE * LABEL_SWITCH_ZOOM_PERCENT / 100.0), LV_STATE_PRESSED);
    // lv_obj_set_style_transform_zoom(temp, LV_IMG_ZOOM_NONE, LV_STATE_DEFAULT);
    // lv_obj_add_flag(temp, LV_OBJ_FLAG_CLICKABLE);
    // lv_obj_add_event_cb(temp, img_more_click_event, LV_EVENT_CLICKED, NULL);
}

lv_obj_t *bg_screen_get_scr(void)
{
    return _scr;
}

void bg_screen_show(void)
{
    lv_scr_load(_scr);
}
