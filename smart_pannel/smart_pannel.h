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
    // Background Screen
    smart_pannel_bg_state_t bg_init_state;
    void (*bg_screen_init)(lv_obj_t *obj);
    lv_event_cb_t bg_switch_callback;
    // Foreground Screen
    void (*fg_screen_init)(lv_obj_t *obj);
    lv_event_cb_t fg_back_callback;
} app_t;

void smart_pannel_init(void);
void smart_pannel_swtich_screen(void);
void smart_pannel_install_app(app_t *app);

#ifdef __cplusplus
}
#endif

#endif