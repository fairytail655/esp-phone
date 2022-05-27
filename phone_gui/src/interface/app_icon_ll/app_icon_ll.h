#ifndef APP_ICON_LL_H
#define APP_ICON_LL_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t size;
    uint8_t image_percent;
    lv_obj_t *parent;
    lv_obj_t *event_obj;
    lv_ll_t ll;
} app_icon_ll_t;

app_icon_ll_t *app_icon_ll_create(
    uint8_t size,
    uint8_t image_percent,
    lv_obj_t *parent,
    lv_obj_t *event_obj
);

void app_icon_ll_add(app_icon_ll_t *icon_ll, uint8_t id, const lv_img_dsc_t *src);

#ifdef __cplusplus
}
#endif

#endif