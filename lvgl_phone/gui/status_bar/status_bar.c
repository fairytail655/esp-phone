#include "status_bar.h"
#include "../obj_conf/obj_conf.h"

#ifdef STATUS_BAR_EN

static lv_obj_t *_obj;
static lv_obj_t *_area_left, *_area_right, *_area_middle;

static void show(void);
static void hide(void);

void status_bar_init(status_bar_t *status_bar, lv_obj_t *parent)
{
    status_bar->show = show;
    status_bar->hide = hide;

    // Main area
    obj_conf_style_t style = {
        .width = STATUSBAR_WIDTH,
        .height = STATUSBAR_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN,
        .align = LV_ALIGN_TOP_MID,
        .border_width = 1,
        .padd_all = 0,
        .radius = 0,
        .bg_color = STATUSBAR_BG_COLOR,
        .bg_opa = LV_OPA_COVER,
    };
    _obj = lv_obj_create(parent);
    obj_conf_style(_obj, &style);
    lv_obj_clear_flag(_obj, LV_OBJ_FLAG_SCROLLABLE);

    // Left area
    _area_left = lv_obj_create(_obj);
    style.width = STATUSBAR_WIDTH * STATUSBAR_AREA_LEFT_PERCENT / 100;
    style.pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET;
    style.align = LV_ALIGN_LEFT_MID;
    style.x_offset = STATUSBAR_AREA_OFFSET;
    style.bg_opa = LV_OPA_TRANSP;
    obj_conf_style(_area_left, &style);
    // Config layout
    lv_obj_set_flex_flow(_area_left, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_area_left, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(_area_left, STATUSBAR_AREA_PAD, 0);
    lv_obj_clear_flag(_area_left, LV_OBJ_FLAG_SCROLLABLE);

    // Right area
    _area_right = lv_obj_create(_obj);
    style.width = STATUSBAR_WIDTH * STATUSBAR_AREA_RIGHT_PERCENT / 100;
    style.align = LV_ALIGN_RIGHT_MID;
    style.x_offset = -STATUSBAR_AREA_OFFSET;
    style.bg_opa = LV_OPA_TRANSP;
    obj_conf_style(_area_right, &style);
    // Config layout
    lv_obj_set_flex_flow(_area_right, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_area_right, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(_area_right, STATUSBAR_AREA_PAD, 0);
    lv_obj_clear_flag(_area_right, LV_OBJ_FLAG_SCROLLABLE);

    // Middle area
    _area_middle = lv_obj_create(_obj);
    style.width = STATUSBAR_WIDTH - lv_obj_get_width(_area_left) - lv_obj_get_width(_area_right);
    style.pos_flag = OBJ_POS_FLAG_ALIGN;
    style.align = LV_ALIGN_CENTER;
    style.bg_opa = LV_OPA_TRANSP;
    obj_conf_style(_area_middle, &style);
    lv_obj_clear_flag(_area_middle, LV_OBJ_FLAG_SCROLLABLE);
}

static void show(void)
{

}

static void hide(void)
{

}

#endif
