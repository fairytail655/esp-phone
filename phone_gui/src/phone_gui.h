#ifndef PHONE_GUI_H
#define PHONE_GUI_H

#include "lvgl.h"

typedef enum {
    PHONE_GUI_WIFI_CLOSED = 1,
    PHONE_GUI_WIFI_DISCONNECT,
    PHONE_GUI_WIFI_1,
    PHONE_GUI_WIFI_2,
    PHONE_GUI_WIFI_3,
} phone_gui_wifi_t;

class PhoneGui {
public:
    PhoneGui(void);
    ~PhoneGui(void);
    void begin(void);
    // Wallpaper
    void setWallpaperImage(const lv_img_dsc_t *src);
    void setWallpaperColor(lv_color_t color);
    // Status bar
    void setWifiLevel(phone_gui_wifi_t level);
    void setClockTime(uint8_t day, uint8_t hour, uint8_t min, uint8_t sec);
};

#endif