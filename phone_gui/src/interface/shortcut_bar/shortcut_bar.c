#include "../interface_conf.h"
#include "../../utils/utils.h"
#include "../app_icon_ll/app_icon_ll.h"
#include "shortcut_bar.h"

static app_icon_ll_t *_app_icon_ll = NULL;

void shortcut_bar_init(lv_obj_t *parent)
{
    // Main Area
    lv_obj_t *obj = lv_obj_create(parent);
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
    obj_conf_style(obj, &style);
    // Cofig layout
    lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(obj, 0, 0);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    _app_icon_ll = app_icon_ll_create(
        SHORTCUT_ICON_SIZE, SHORTCUT_ICON_PERCENT,
        obj, parent
    );
    app_icon_ll_add(_app_icon_ll, 1, NULL);
}
