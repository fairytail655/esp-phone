#include "../interface_conf.h"
#include "../../utils/utils.h"
#include "navigate_bar.h"

static lv_obj_t *_event_obj;
static lv_obj_t *_bar;

static void btn_left_event_cb(lv_event_t *e);
static void btn_middle_event_cb(lv_event_t *e);
static void btn_right_event_cb(lv_event_t *e);

void navigate_bar_init(lv_obj_t *parent)
{
    _event_obj = parent;

    // Main area
    _bar = lv_obj_create(parent);
    obj_conf_style_t style = {
        .width = NAVIGATEBAR_WIDTH,
        .height = NAVIGATEBAR_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN,
        .align = LV_ALIGN_BOTTOM_MID,
        .radius = 0,
        .border_width = 0,
        .padd_all = 0,
        .bg_color = NAVIGATEBAR_BG_COLOR,
        .bg_opa = NAVIGATEBAR_BG_OPA,
    };
    lv_obj_set_flex_flow(_bar, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_bar, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(_bar, 0, 0);

    style.width = LV_SIZE_CONTENT;
    style.pos_flag = OBJ_POS_FLAG_NONE;
    style.bg_opa = LV_OPA_TRANSP;

    // Left button
    lv_obj_t *btn_left = lv_btn_create(_bar);
    obj_conf_style(btn_left, &style);
	LV_IMG_DECLARE(img_navigate_left);
	lv_obj_set_style_bg_img_src(btn_left, &img_navigate_left, 0);
    lv_obj_set_flex_grow(btn_left, 1);
    lv_obj_add_event_cb(btn_left, btn_left_event_cb, LV_EVENT_PRESSED, NULL);
    // Modify opacity when button pressed
    lv_obj_set_style_bg_opa(btn_left, NAVIGATEBAR_BTN_PRESS_OPA, LV_STATE_PRESSED);

    // Middle button
    lv_obj_t *btn_middle = lv_btn_create(_bar);
    obj_conf_style(btn_middle, &style);
	LV_IMG_DECLARE(img_navigate_middle);
	lv_obj_set_style_bg_img_src(btn_middle, &img_navigate_middle, 0);
    lv_obj_set_flex_grow(btn_middle, 1);
    lv_obj_add_event_cb(btn_middle, btn_middle_event_cb, LV_EVENT_PRESSED, NULL);
    // Modify opacity when button pressed
    lv_obj_set_style_bg_opa(btn_middle, NAVIGATEBAR_BTN_PRESS_OPA, LV_STATE_PRESSED);

    // Right button
    lv_obj_t *btn_right = lv_btn_create(_bar);
    obj_conf_style(btn_right, &style);
	LV_IMG_DECLARE(img_navigate_right);
	lv_obj_set_style_bg_img_src(btn_right, &img_navigate_right, 0);
    lv_obj_set_flex_grow(btn_right, 1);
    lv_obj_add_event_cb(btn_right, btn_right_event_cb, LV_EVENT_PRESSED, NULL);
    // Modify opacity when button pressed
    lv_obj_set_style_bg_opa(btn_right, NAVIGATEBAR_BTN_PRESS_OPA, LV_STATE_PRESSED);
}

static void btn_left_event_cb(lv_event_t *e)
{
    LV_LOG_ERROR("left button");
}

static void btn_middle_event_cb(lv_event_t *e)
{
    LV_LOG_ERROR("middle button");
}

static void btn_right_event_cb(lv_event_t *e)
{
    LV_LOG_ERROR("right button");
}
