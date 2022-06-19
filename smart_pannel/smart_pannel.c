#include "lvgl.h"
#include "interface/interface.h"
#include "smart_pannel.h"

void smart_pannel_init(void)
{
    lv_obj_t *bg_scr = lv_scr_act();

    bg_board_init(bg_scr);
}
