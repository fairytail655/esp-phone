#include "interface/interface_conf.h"
#include "bg_board.h"

static lv_obj_t *bg_board_obj = NULL;

void bg_board_init(lv_obj_t *scr)
{
    bg_board_obj = lv_obj_create(scr);
    if (bg_board_obj == NULL)
        return;

    lv_obj_set_size(bg_board_obj, BG_BOARD_WIDTH, BG_BOARD_HEIGHT);
    lv_obj_set_style_radius(bg_board_obj, BG_BOARD_RADIUS, 0);
    lv_obj_set_style_border_width(bg_board_obj, 0, 0);
    lv_obj_set_align(bg_board_obj, LV_ALIGN_CENTER);
    lv_obj_set_style_bg_color(bg_board_obj, lv_color_hex(BG_BOARD_COLOR_OFF), 0);
    LV_IMG_DECLARE(img_bg_board);
    lv_obj_set_style_bg_img_src(bg_board_obj, &img_bg_board, 0);
}

void bg_board_change_state(bg_board_state_t state)
{
    if (bg_board_obj == NULL)
        return;

    if (state == BG_BOARD_STATE_ON) {
        lv_obj_set_style_bg_color(bg_board_obj, lv_color_hex(BG_BOARD_COLOR_ON), 0);
    }
    else if (state == BG_BOARD_STATE_OFF) {
        lv_obj_set_style_bg_color(bg_board_obj, lv_color_hex(BG_BOARD_COLOR_OFF), 0);
    }
}

lv_obj_t *bg_board_get_obj(void)
{
    return bg_board_obj;
}
