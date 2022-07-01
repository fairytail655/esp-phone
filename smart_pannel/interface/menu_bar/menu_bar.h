#ifndef MENU_BAR_H
#define MENU_BAR_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef bool (*menu_touch_pos_t)(int *x, int *y);

typedef enum {
    MENU_DAY_SUNDAY = 0,
    MENU_DAY_MONDAY,
    MENU_DAY_TUESDAY,
    MENU_DAY_WEDNESDAY,
    MENU_DAY_THURSDAY,
    MENU_DAY_FRIDAY,
    MENU_DAY_SATURDAY,
} menu_day_t;

typedef struct {
    uint8_t hour;
    uint8_t min;
    uint8_t month;
    uint8_t day;
    menu_day_t week;
} menu_time_t;

void menu_init(lv_obj_t *obj);
void menu_bar_set_anim_cb(void *f);
lv_event_code_t menu_bar_get_event_id_press(void);
lv_event_code_t menu_bar_get_event_id_pressing(void);
lv_event_code_t menu_bar_get_event_id_click(void);
void menu_bar_show(bool en);
int menu_bar_current_y(void);
int menu_bar_origin_y(void);
void menu_bar_move_y(int y);
void menu_bar_start_anim(int y);

#ifdef __cplusplus
}
#endif

#endif