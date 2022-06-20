#include "smart_pannel.h"
#include "ui_air_bg.h"
#include "air_conditioner.h"

static void bg_more_click_event(lv_event_t *e);
static void fg_back_click_event(lv_event_t *e);

void air_conditioner_init(void)
{
    app_t app_air_cond = {
        .bg_screen_init = ui_air_bg_init,
        .fg_screen_init = NULL,
        .fg_screen_back_callback = fg_back_click_event,
    };
    smart_pannel_install_app(&app_air_cond);

    ui_air_bg_register_callback_more_click(bg_more_click_event);
}

static void bg_more_click_event(lv_event_t *e)
{
    smart_pannel_toggle_screen(false);
}

static void fg_back_click_event(lv_event_t *e)
{
    smart_pannel_toggle_screen(true);
}
