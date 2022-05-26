#include "interface/interface.h"
#include "phone_gui.h"

PhoneGui::PhoneGui(void)
{

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

void PhoneGui::setWifiLevel(phone_gui_wifi_t level)
{
    status_bar_set_wifi_state((status_bar_wifi_state_t)level);
}

void PhoneGui::setClockTime(uint8_t day, uint8_t hour, uint8_t min, uint8_t sec)
{
    status_bar_set_clock_time(day, hour, min, sec);
}
