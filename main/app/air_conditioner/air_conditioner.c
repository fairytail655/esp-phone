#include "smart_pannel.h"
#include "ui_air_bg.h"
#include "ui_air_fg.h"
#include "air_conditioner.h"

static void fg_back_click_event(lv_event_t *e);
static void bg_switch_click_event(lv_event_t *e);

static smart_pannel_state_t state = INTERFACE_STATE_ON;
static app_navigate_bar_conf_t conf = {
    .left_title = "Air Conditioner",
    .middle_title = NULL,
    .right_title = NULL,
    .en_bg_color = false,
    .en_right_switch = true,
};
static app_t app_air_cond = {
    .state = &state,
    .bg_screen_init = ui_air_bg_init,
    .bg_switch_callback = bg_switch_click_event,
    .fg_screen_init = ui_air_fg_init,
    .fg_back_callback = fg_back_click_event,
    .fg_init_conf = &conf,
};
static int indoor_temperature = 26;
static int target_temperature = 23;

void air_conditioner_init(void)
{
    smart_pannel_install_app(&app_air_cond);
    ui_air_bg_indoor_temp_set(&indoor_temperature);
    ui_air_bg_target_temp_set(&target_temperature);
}

static void bg_switch_click_event(lv_event_t *e)
{
    ui_air_bg_change_state(state);
}

static void fg_back_click_event(lv_event_t *e)
{
    smart_pannel_swtich_to_bg();
}
