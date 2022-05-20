#ifndef STATUS_ICON_H
#define STATUS_ICON_H

#include "../gui_conf.h"

#if STATUSBAR_EN

#include "stdint.h"
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t state_num;
    uint8_t current_state;
    lv_obj_t *_obj;
    lv_obj_t **_img;
} status_icon_t;

status_icon_t *status_icon_create(uint8_t state_num, lv_obj_t *parent);
void status_icon_destory(status_icon_t *icon);
void status_icon_set_src(status_icon_t *icon, uint8_t state_index, const lv_img_dsc_t *src);
void status_icon_set_state(status_icon_t *icon, uint8_t state_index);

#ifdef __cplusplus
}
#endif

#endif

#endif
