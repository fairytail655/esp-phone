#include "smart_pannel.h"
#include "ui_heater_bg.h"
#include "ui_heater_fg.h"
#include "ui_heater_conf.h"
#include "heater.h"

static void water_temp_inc_event(lv_event_t *e);
static void water_temp_dec_event(lv_event_t *e);
static void switch_click_event(lv_event_t *e);
static void bg_heat_click_event(lv_event_t *e);
static void bg_rest_click_event(lv_event_t *e);
static void fg_back_click_event(lv_event_t *e);

static smart_pannel_state_t state = INTERFACE_STATE_ON;
static smart_pannel_state_t heat_state = INTERFACE_STATE_OFF;
static smart_pannel_state_t rest_state = INTERFACE_STATE_OFF;
static app_fg_conf_t conf = {
    .left_title = "Heater",
    .middle_title = "More",
    .right_title = NULL,
    .en_bg_color = false,
    .en_right_switch = true,
};
static app_t app_air_cond = {
    .state = &state,
    .bg_screen_init = ui_heater_bg_init,
    .bg_switch_cb = switch_click_event,
    .bg_more_cb = NULL,
    .fg_screen_init = ui_heater_fg_init,
    .fg_back_cb = fg_back_click_event,
    .fg_switch_cb = switch_click_event,
    .fg_init_conf = &conf,
};
static int water_temperature = 35;

void heater_init(void)
{
    smart_pannel_install_app(&app_air_cond);
    ui_heater_bg_register_cb(bg_heat_click_event, bg_rest_click_event);
    ui_heater_fg_register_cb(water_temp_inc_event, water_temp_dec_event);

    ui_heater_bg_water_temp_set(water_temperature);
    ui_heater_bg_change_state(state);
    ui_heater_bg_heat_set_state(heat_state);
    ui_heater_bg_rest_set_state(rest_state);
    ui_heater_fg_change_state(state);

    ui_heater_fg_water_temp_set(water_temperature);
}

static void water_temp_inc_event(lv_event_t *e)
{
    if (water_temperature < TEMP_MAX) {
        ui_heater_bg_water_temp_set(++water_temperature);
        ui_heater_fg_water_temp_set(water_temperature);
    }
}

static void water_temp_dec_event(lv_event_t *e)
{
    if (water_temperature > TEMP_MIN) {
        ui_heater_bg_water_temp_set(--water_temperature);
        ui_heater_fg_water_temp_set(water_temperature);
    }
}

static void switch_click_event(lv_event_t *e)
{
    ui_heater_bg_change_state(state);
    ui_heater_fg_change_state(state);
    if (state == INTERFACE_STATE_OFF) {
        ui_heater_bg_heat_set_state(state);
        ui_heater_bg_rest_set_state(state);
        ui_heater_bg_heat_enabel(false);
        ui_heater_bg_rest_enabel(false);
    }
    else {
        ui_heater_bg_heat_enabel(true);
        ui_heater_bg_rest_enabel(true);
    }
}

static void bg_heat_click_event(lv_event_t *e)
{
    heat_state = (heat_state == INTERFACE_STATE_OFF) ? INTERFACE_STATE_ON : INTERFACE_STATE_OFF;
    ui_heater_bg_heat_set_state(heat_state);
}

static void bg_rest_click_event(lv_event_t *e)
{
    rest_state = (rest_state == INTERFACE_STATE_OFF) ? INTERFACE_STATE_ON : INTERFACE_STATE_OFF;
    ui_heater_bg_rest_set_state(rest_state);
}

static void fg_back_click_event(lv_event_t *e)
{
    smart_pannel_swtich_to_bg();
}
