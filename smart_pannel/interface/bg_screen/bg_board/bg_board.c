#include "interface/interface_conf.h"
#include "utils/utils.h"
#include "bg_board.h"

typedef struct {
    lv_obj_t *obj;
    lv_obj_t *spot;
} bg_board_app_t;

static lv_obj_t *_obj = NULL;
static lv_obj_t *_spot_obj = NULL;
static uint8_t _app_index = 0;
static lv_ll_t _app_ll;

lv_obj_t *bg_board_init(lv_obj_t *scr)
{
    _obj = lv_obj_create(scr);
    lv_obj_set_size(_obj, BG_BOARD_WIDTH, BG_BOARD_HEIGHT);
    lv_obj_set_style_radius(_obj, BG_BOARD_RADIUS, 0);
    lv_obj_set_style_border_width(_obj, 0, 0);
    lv_obj_set_align(_obj, LV_ALIGN_CENTER);
    LV_IMG_DECLARE(img_bg_board);
    lv_obj_set_style_bg_img_src(_obj, &img_bg_board, 0);
    lv_obj_set_style_bg_img_recolor(_obj, BG_BOARD_OBJ_COLOR_ON, INTERFACE_STATE_ON);
    lv_obj_set_style_bg_img_recolor_opa(_obj, BG_BOARD_OBJ_OPA_ON, INTERFACE_STATE_ON);
    lv_obj_set_style_bg_img_recolor(_obj, BG_BOARD_OBJ_COLOR_OFF, INTERFACE_STATE_OFF);
    lv_obj_set_style_bg_img_recolor_opa(_obj, BG_BOARD_OBJ_OPA_OFF, INTERFACE_STATE_OFF);
    lv_obj_clear_flag(_obj, LV_OBJ_FLAG_SCROLLABLE);

	_spot_obj = lv_obj_create(scr);
    int height = (LV_VER_RES - BG_BOARD_HEIGHT) / 2;
	lv_obj_set_height(_spot_obj, height);
	lv_obj_set_width(_spot_obj, LV_SIZE_CONTENT);
	lv_obj_set_style_radius(_spot_obj, 0, 0);
    lv_obj_set_align(_spot_obj, LV_ALIGN_BOTTOM_MID);
	lv_obj_set_style_border_width(_spot_obj, 0, 0);
	lv_obj_set_style_pad_all(_spot_obj, 0, 0);
	// Background
	lv_obj_set_style_bg_opa(_spot_obj, LV_OPA_TRANSP, 0);
	// layout
	lv_obj_set_flex_flow(_spot_obj, LV_FLEX_FLOW_ROW);
	lv_obj_set_flex_align(_spot_obj, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
	lv_obj_set_style_pad_column(_spot_obj, BG_SPOT_GAP, 0);

    _lv_ll_init(&_app_ll, sizeof(bg_board_app_t));

    INTERFACE_TRACE("bg_board init finish");

    return _obj;
}

lv_obj_t *bg_board_regiser_obj(void)
{
    bg_board_app_t *app = (bg_board_app_t *)_lv_ll_ins_tail(&_app_ll);

    lv_obj_t *obj = lv_obj_create(_obj);
    obj_conf_style_t style = {
        .width = BG_BOARD_WIDTH,
        .height = BG_BOARD_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN,
        .align = LV_ALIGN_CENTER,
        .border_width = 0,
        .pad_all = 0,
        .radius = BG_BOARD_RADIUS,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(obj, &style);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_t *spot = lv_img_create(_spot_obj);
	LV_IMG_DECLARE(img_spot);
    lv_img_set_src(spot, &img_spot);
    lv_obj_set_style_img_recolor(spot, BG_SPOT_COLOR_1, 0);
    lv_obj_set_style_img_recolor_opa(spot, LV_OPA_COVER, 0);
    lv_obj_set_style_transform_zoom(spot, (int)(LV_IMG_ZOOM_NONE * BG_SPOT_ZOOM), 0);
    lv_obj_set_style_img_recolor(spot, BG_SPOT_COLOR_2, LV_STATE_USER_1);
    lv_obj_set_style_img_recolor_opa(spot, LV_OPA_COVER, LV_STATE_USER_1);
    lv_obj_set_style_transform_zoom(spot, LV_IMG_ZOOM_NONE, LV_STATE_USER_1);

    app->obj = obj;
    app->spot = spot;

    return obj;
}

void bg_board_switch_obj(uint8_t index)
{
    int app_count = _lv_ll_get_len(&_app_ll);
    if (index > app_count) {
        INTERFACE_TRACE("bg_board switch obj out of index");
        return;
    }

    bg_board_app_t *app = NULL;
    bg_board_app_t *app_target = NULL;
    bg_board_app_t *app_last = NULL;
    for (int i = 0; i < app_count; i++) {
        if (i == 0) {
            app = (bg_board_app_t *)_lv_ll_get_head(&_app_ll);
        }
        else {
            app = (bg_board_app_t *)_lv_ll_get_next(&_app_ll, app);
        }
        if (i == (_app_index - 1)) {
            app_last = app;
        }
        else if (i == (index - 1)) {
            app_target = app;
        }
    }

    if (app_last) {
        lv_obj_add_flag(app_last->obj, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_state(app_last->spot, LV_STATE_USER_1);
    }
    if (app_target) {
        lv_obj_clear_flag(app_target->obj, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_state(app_target->spot, LV_STATE_USER_1);
    }

    _app_index = index;
}

void bg_board_change_state(bg_board_state_t state)
{
    if (state == BG_BOARD_STATE_OFF) {
        lv_obj_clear_state(_obj, INTERFACE_STATE_ON);
        lv_obj_add_state(_obj, INTERFACE_STATE_OFF);
    }
    else {
        lv_obj_clear_state(_obj, INTERFACE_STATE_OFF);
        lv_obj_add_state(_obj, INTERFACE_STATE_ON);
    }
}
