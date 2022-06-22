#ifndef SMART_PANNEL_H
#define SMART_PANNEL_H

#include "lvgl.h"
#include "interface/interface_conf.h"
#include "utils/utils.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef interface_state_t smart_pannel_state_t;
typedef bool (*smart_pannel_touch_pos_t)(int *x, int *y);

typedef struct {
    bool en_switch_label;
    bool en_switch_btn;
    bool en_more_btn;
} app_bg_conf_t;

typedef struct {
    const char *left_title;
    const char *middle_title;
    const char *right_title;
    bool en_right_switch;
    bool en_bg_color;
    lv_color_t bg_color;
} app_fg_conf_t;

typedef struct {
    smart_pannel_state_t *state;
    // Background Screen
    app_bg_conf_t *bg_init_conf;
    void (*bg_screen_init)(lv_obj_t *obj);
    lv_event_cb_t bg_switch_cb;
    lv_event_cb_t bg_more_cb;
    // Foreground Screen
    void (*fg_screen_init)(lv_obj_t *obj);
    lv_event_cb_t fg_back_cb;
    lv_event_cb_t fg_switch_cb;
    app_fg_conf_t *fg_init_conf;
} app_t;

void smart_pannel_init(void);
void smart_pannel_swtich_to_bg(void);
void smart_pannel_swtich_to_fg(void);
void smart_pannel_install_app(app_t *app);
void smart_pannel_register_touch_pos(smart_pannel_touch_pos_t touch_pos);

#ifdef __cplusplus
}
#endif

#endif