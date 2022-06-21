#ifndef SMART_PANNEL_H
#define SMART_PANNEL_H

#include "lvgl.h"
#include "interface/interface_conf.h"
#include "utils/utils.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef interface_state_t smart_pannel_state_t;

typedef struct {
    const char *left_title;
    const char *middle_title;
    const char *right_title;
    bool en_right_switch;
    bool en_bg_color;
    lv_color_t bg_color;
} app_navigate_bar_conf_t;

typedef struct {
    smart_pannel_state_t *state;
    // Background Screen
    void (*bg_screen_init)(lv_obj_t *obj);
    lv_event_cb_t bg_switch_callback;
    // Foreground Screen
    void (*fg_screen_init)(lv_obj_t *obj);
    lv_event_cb_t fg_back_callback;
    app_navigate_bar_conf_t *fg_init_conf;
} app_t;

void smart_pannel_init(void);
void smart_pannel_swtich_to_bg(void);
void smart_pannel_swtich_to_fg(void);
void smart_pannel_install_app(app_t *app);

#ifdef __cplusplus
}
#endif

#endif