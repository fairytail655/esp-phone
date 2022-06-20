#ifndef BG_BOARD_H
#define BG_BOARD_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    BG_BOARD_STATE_ON = 0,
    BG_BOARD_STATE_OFF,
} bg_board_state_t;

void bg_board_init(lv_obj_t *scr);
lv_obj_t *bg_board_regiser_obj(void);
void bg_board_switch_obj(uint8_t index);
void bg_board_obj_change_state(lv_obj_t *obj, bg_board_state_t state);

#ifdef __cplusplus
}
#endif

#endif