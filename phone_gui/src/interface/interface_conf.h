#ifndef INTERFACE_CONF_H
#define INTERFACE_CONF_H

#include "lvgl.h"
#include "../phone_gui_conf.h"

/* Event */
#define INTERFACE_EVENT_OBJ                 lv_layer_top()


/* Wallpaper */
#define WALLPAPER_COLOR                     lv_color_make(0x4C, 0x58, 0x7B)


/* Status bar */
// Main area
#define STATUSBAR_WIDTH                     LV_HOR_RES
#define STATUSBAR_HEIGHT                    34
#define STATUSBAR_BG_COLOR                  lv_color_make(248, 248, 248)
#define STATUSBAR_ICON_SIZE                 24
#define STATUSBAR_AREA_OFFSET               10
#define STATUSBAR_AREA_LEFT_PERCENT         30
#define STATUSBAR_AREA_RIGHT_PERCENT        30
#define STATUSBAR_AREA_PAD                  3
// Clock
#define STATUSBAR_CLOCK_FONT                &lv_font_montserrat_18
// Battery
#define STATUSBAR_BATTERY_FONT              &lv_font_montserrat_14

#endif