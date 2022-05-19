#ifndef OBJ_CONF_H
#define OBJ_CONF_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    OBJ_POS_FLAG_NONE = 0,
    OBJ_POS_FLAG_XY,
    OBJ_POS_FLAG_ALIGN,
} obj_pos_flag_t;

typedef struct {
    uint16_t width;
    uint16_t height;
    obj_pos_flag_t flag;
    lv_align_t align;
    uint16_t x;
    uint16_t y;
    uint16_t radius;
    uint16_t border_width;
    uint16_t padd_all;
    lv_color_t bg_color;
    uint16_t bg_opa;
} obj_conf_style_t;

void obj_conf_style(lv_obj_t *obj, obj_conf_style_t *config);

#ifdef __cplusplus
}
#endif

#endif
