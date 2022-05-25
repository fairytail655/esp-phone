#include "gui/gui_conf.h"
#include "obj_conf.h"

void obj_conf_style(lv_obj_t *obj, obj_conf_style_t *config)
{
    // Size
    lv_obj_set_size(obj, config->width, config->height);

    // Position
    switch (config->pos_flag) {
        case OBJ_POS_FLAG_XY:
            lv_obj_set_pos(obj, config->x_offset, config->y_offset);
            break;
        case OBJ_POS_FLAG_ALIGN:
            lv_obj_set_align(obj, config->align);
            break;
        case OBJ_POS_FLAG_ALIGN_OFFSET:
            lv_obj_align(obj, config->align, config->x_offset, config->y_offset);
            break;
        case OBJ_POS_FLAG_ALIGN_TO:
            lv_obj_align_to(obj, config->alignt_to, config->align, config->x_offset, config->y_offset);
            break;
        default:
            break;
    }

    // Shape
    lv_obj_set_style_radius(obj, config->radius, 0);
    lv_obj_set_style_pad_all(obj, config->padd_all, 0);
    lv_obj_set_style_border_width(obj, config->border_width, 0);
#if OBJ_CONF_BORDER_EN
    if (config->border_width == 0)
        lv_obj_set_style_border_width(obj, 1, 0);
    lv_obj_set_style_border_color(obj, lv_palette_main(LV_PALETTE_RED), 0);
#endif

    // Background
    lv_obj_set_style_bg_opa(obj, config->bg_opa, 0);
    if (config->bg_opa != LV_OPA_TRANSP)
        lv_obj_set_style_bg_color(obj, config->bg_color, 0);
}
