#ifndef MANAGER_H
#define MANAGER_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void (*bg_screen_init)(lv_obj_t *obj);
} app_t;

void manager_install_app(app_t *app);

#ifdef __cplusplus
}
#endif

#endif