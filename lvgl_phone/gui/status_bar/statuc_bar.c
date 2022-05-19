#include "status_bar.h"
#include "../obj_conf/obj_conf.h"

#ifdef STATUS_BAR_EN

static lv_obj_t *_obj;

static void show(void);
static void hide(void);

void status_bar_init(status_bar_t *status_bar, lv_obj_t *parent)
{
    status_bar->show = show;
    status_bar->hide = hide;

    obj_conf_style_t style = {
        .align = LV_ALIGN_TOP_MID,
        .bg_color = STATUSBAR_BG_COLOR,
        .bg_opa = LV_OPA_COVER,
        .border_width = 0,
        .flag = OBJ_POS_FLAG_ALIGN,
        .height = STATUSBAR_HEIGHT,
        .padd_all = 0,
        .radius = 0,
        .width = STATUSBAR_WIDTH
    };
    _obj = lv_obj_create(parent);
    obj_conf_style(_obj, &style);
}

static void show(void)
{

}

static void hide(void)
{

}

#endif
