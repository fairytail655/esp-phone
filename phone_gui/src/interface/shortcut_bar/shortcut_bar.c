#include "../interface_conf.h"
#include "../../utils/utils.h"
#include "../app_icon_ll/app_icon_ll.h"
#include "shortcut_bar.h"

static lv_obj_t *_obj = NULL;
static app_icon_ll_t *_app_icon_ll = NULL;

void shortcut_bar_init(lv_obj_t *parent)
{
    // Main Area
     _obj= lv_obj_create(parent);
    obj_conf_style_t style = {
        .width = SHORTCUT_WIDTH,
        .height = SHORTCUT_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET,
        .align = LV_ALIGN_BOTTOM_MID,
        .x_offset = 0,
        .y_offset = -SHORTCUT_BOTTOM_OFFSET,
        .radius = SHORTCUT_MAIN_RADIUS,
        .border_width = 0,
        .pad_all = 0,
        .bg_color = SHORTCUT_BG_COLOR,
        .bg_opa = SHORTCUT_BG_OPA,
    };
    obj_conf_style(_obj, &style);
    // Cofig layout
    lv_obj_set_flex_flow(_obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_obj, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(_obj, 0, 0);
    lv_obj_clear_flag(_obj, LV_OBJ_FLAG_SCROLLABLE);

    _app_icon_ll = app_icon_ll_create(
        SHORTCUT_ICON_SIZE, SHORTCUT_ICON_PERCENT,
        _obj, parent
    );
}

void shortcut_bar_show(bool flag)
{
    if (flag)
        lv_obj_clear_flag(_obj, LV_OBJ_FLAG_HIDDEN);
    else
        lv_obj_add_flag(_obj, LV_OBJ_FLAG_HIDDEN);
}

void shortcut_bar_add_icon(uint8_t id, const lv_img_dsc_t *src)
{
    app_icon_ll_add(_app_icon_ll, id, src);
}

void shortcut_bar_del_icon(uint8_t id)
{
    app_icon_ll_del(_app_icon_ll, id);
}
