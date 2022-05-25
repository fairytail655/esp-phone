#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include "../gui_conf.h"
#if STATUSBAR_EN

#include <stdint.h>
#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    STATUS_BAR_AREA_LEFT = 0,
    STATUS_BAR_AREA_MIDDLE,
    STATUS_BAR_AREA_RIGHT,
} status_bar_area_t;

typedef enum {
    STATUS_BAR_WIFI_STATE_CLOSE = 1,
    STATUS_BAR_WIFI_STATE_DISCONNECT,
    STATUS_BAR_WIFI_STATE_1,
    STATUS_BAR_WIFI_STATE_2,
    STATUS_BAR_WIFI_STATE_3,
} status_bar_wifi_state_t;

void status_bar_init(lv_obj_t *parent);
void status_bar_set_wifi_state(status_bar_wifi_state_t state);
void status_bar_set_clock_time(uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);
void status_bar_add_icon(status_bar_area_t area, int id, const lv_img_src_t **state_src, uint8_t state_num);
void status_bar_del_icon(int id);

#ifdef __cplusplus
}
#endif

#endif

#endif