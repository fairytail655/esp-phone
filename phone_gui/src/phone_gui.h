#ifndef PHONE_GUI_H
#define PHONE_GUI_H

#include "lvgl.h"
#include "phone_gui_conf.h"

typedef enum {
    PHONE_GUI_WIFI_CLOSED = 1,
    PHONE_GUI_WIFI_DISCONNECT,
    PHONE_GUI_WIFI_1,
    PHONE_GUI_WIFI_2,
    PHONE_GUI_WIFI_3,
} phone_gui_wifi_t;

typedef enum {
    PHONE_GUI_BAT_EMPTY = 0,
    PHONE_GUI_BAT_1,
    PHONE_GUI_BAT_2,
    PHONE_GUI_BAT_3,
    PHONE_GUI_BAT_FULL,
} phone_gui_battery_t;

class PhoneGui {
public:
    PhoneGui(void);
    ~PhoneGui(void);
    void begin(void);
    // Wallpaper
    void setWallpaperImage(const lv_img_dsc_t *src);
    void setWallpaperColor(lv_color_t color);
#if STATUSBAR_EN
    // Status bar
#if STATUSBAR_AREA_LEFT_EN
    void setWifiLevel(phone_gui_wifi_t level);
#endif
#if STATUSBAR_CLOCK_EN
    void setClockTime(uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);
#endif
    void setBatteryPercent(uint8_t percent);
    void setBatteryLevel(phone_gui_battery_t level);
    void setBatteryCharge(bool flag);
#endif
};

#endif