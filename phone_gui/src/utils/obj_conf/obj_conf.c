#include "../../phone_gui_conf.h"
#include "obj_conf.h"

void obj_conf_style(lv_obj_t *obj, obj_conf_style_t *style)
{
    // Size
    lv_obj_set_size(obj, style->width, style->height);

    // Position
    switch (style->pos_flag) {
        case OBJ_POS_FLAG_XY:
            lv_obj_set_pos(obj, style->x_offset, style->y_offset);
            break;
        case OBJ_POS_FLAG_ALIGN:
            lv_obj_set_align(obj, style->align);
            break;
        case OBJ_POS_FLAG_ALIGN_OFFSET:
            lv_obj_align(obj, style->align, style->x_offset, style->y_offset);
            break;
        case OBJ_POS_FLAG_ALIGN_TO:
            lv_obj_align_to(obj, style->alignt_to, style->align, style->x_offset, style->y_offset);
            break;
        default:
            break;
    }

    // Shape
    lv_obj_set_style_radius(obj, style->radius, 0);
    lv_obj_set_style_pad_all(obj, style->padd_all, 0);
    lv_obj_set_style_border_width(obj, style->border_width, 0);
#if OBJ_CONF_BORDER_EN
    if (style->border_width == 0)
        lv_obj_set_style_border_width(obj, 1, 0);
    lv_obj_set_style_border_color(obj, lv_palette_main(LV_PALETTE_RED), 0);
#endif

    // Background
    lv_obj_set_style_bg_opa(obj, style->bg_opa, 0);
    if (style->bg_opa != LV_OPA_TRANSP)
        lv_obj_set_style_bg_color(obj, style->bg_color, 0);
}
