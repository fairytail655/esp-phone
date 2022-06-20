#ifndef SMART_PANNEL_H
#define SMART_PANNEL_H

#include "lvgl.h"
#include "interface/interface_conf.h"
#include "utils/utils.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void (*bg_screen_init)(lv_obj_t *obj);
    void (*fg_screen_init)(lv_obj_t *obj);
} app_t;

void smart_pannel_init(void);
void smart_pannel_install_app(app_t *app);
void smart_pannel_set_default_app(int index);

#ifdef __cplusplus
}
#endif

#endif