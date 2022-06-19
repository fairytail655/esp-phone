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
void bg_board_change_state(bg_board_state_t state);
lv_obj_t *bg_board_get_obj(void);

#ifdef __cplusplus
}
#endif

#endif