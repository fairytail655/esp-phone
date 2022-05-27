#include "interface/interface.h"
#include "phone_gui.h"

PhoneGui::PhoneGui(void)
{
    _day = 1;
    _hour = 12;
    _min = 0;
    _sec = 0;
    _battery_percent = 100;
    _battery_charging = false;
}

PhoneGui::~PhoneGui(void)
{

}

void PhoneGui::begin(void)
{
    interface_init();
}

void PhoneGui::setWallpaperImage(const lv_img_dsc_t *src)
{
    wallpaper_set_image(src);
}

void PhoneGui::setWallpaperColor(lv_color_t color)
{
    wallpaper_set_color(color);
}

#if STATUSBAR_EN
#if STATUSBAR_AREA_LEFT_EN
void PhoneGui::setWifiLevel(phone_gui_wifi_t level)
{
    status_bar_set_wifi_state((status_bar_wifi_state_t)level);
}
#endif

#if STATUSBAR_CLOCK_EN
void PhoneGui::setClockTime(uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
    if (_day != day) {
        _day = day;
        status_clock_set_day(day);
    }
    if (_hour != hour) {
        _hour = hour;
        status_clock_set_hour(hour);
    }
    if (_min != min) {
        _min = min;
        status_clock_set_min(min);
    }
#if STATUSBAR_CLOCK_SECOND_EN
    if (_sec != sec) {
        _sec = sec;
        status_clock_set_day(sec);
    }
#else
    (void)sec;
#endif
}
#endif

void PhoneGui::setBatteryPercent(uint8_t percent)
{
    if (percent != _battery_percent) {
        _battery_percent = percent;
        status_battery_set_percent(percent, _battery_charging);
    }
}

void PhoneGui::enableBatteryCharge(void)
{
    if (!_battery_charging) {
        _battery_charging = true;
        status_battery_set_charge();
    }
}

void PhoneGui::disableBatteryCharge(void)
{
    if (_battery_charging) {
        _battery_charging = false;
        status_battery_set_percent(_battery_percent, _battery_charging);
    }
}
#endif
