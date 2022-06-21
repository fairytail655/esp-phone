#ifndef SMART_PANNEL_H
#define SMART_PANNEL_H

#include "lvgl.h"
#include "interface/interface_conf.h"
#include "utils/utils.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    SMART_PANNEL_BG_STATE_OFF = 0,
    SMART_PANNEL_BG_STATE_ON = LV_STATE_USER_1,
} smart_pannel_bg_state_t;

typedef struct {
    void (*bg_screen_init)(lv_obj_t *obj, int smart_pannel_bg_state_t);
    void (*fg_screen_init)(lv_obj_t *obj);
    lv_event_cb_t fg_screen_back_callback;
} app_t;

void smart_pannel_init(void);
void smart_pannel_install_app(app_t *app);
void smart_pannel_set_default_app(int index);
void smart_pannel_toggle_screen(bool en_bg_screen);

#ifdef __cplusplus
}
#endif

#endif