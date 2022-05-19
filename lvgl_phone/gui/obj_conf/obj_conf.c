#include "obj_conf.h"

void obj_conf_style(lv_obj_t *obj, obj_conf_style_t *config)
{
    // Size
    lv_obj_set_size(obj, config->width, config->height);

    // Position
    switch (config->flag) {
        case OBJ_POS_FLAG_XY:
            lv_obj_set_pos(obj, config->x, config->y);
            break;
        case OBJ_POS_FLAG_ALIGN:
            lv_obj_set_align(obj, config->align);
            break;
        default:
            break;
    }

    // Shape
    lv_obj_set_style_radius(obj, config->radius, 0);
    lv_obj_set_style_border_width(obj, config->border_width, 0);
    lv_obj_set_style_pad_all(obj, config->padd_all, 0);

    // Background
    lv_obj_set_style_bg_color(obj, config->bg_color, 0);
    lv_obj_set_style_bg_opa(obj, config->bg_opa, 0);
}
