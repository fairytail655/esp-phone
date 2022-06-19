#include "lvgl.h"
#include "bg_screen/bg_board/bg_board.h"

void interface_init(void)
{
    lv_obj_t *bg_scr = lv_scr_act();

    bg_board_init(bg_scr);
}
