#ifndef INTERFACE_CONF_H
#define INTERFACE_CONF_H

#include "lvgl.h"
#include "../phone_gui_conf.h"

#define GUI_EVENT_OBJ       lv_layer_top()


#define WALLPAPER_COLOR     lv_color_make(0x4C, 0x58, 0x7B)


#if     STATUSBAR_EN
#define STATUSBAR_WIDTH                     LV_HOR_RES
#define STATUSBAR_HEIGHT                    34
#define STATUSBAR_BG_COLOR                  lv_color_make(248, 248, 248)
#define STATUSBAR_ICON_SIZE                 24
#define STATUSBAR_AREA_OFFSET               10
#define STATUSBAR_AREA_LEFT_PERCENT         30
#define STATUSBAR_AREA_RIGHT_PERCENT        30
#define STATUSBAR_AREA_PAD                  3
#define STATUSBAR_CLOCK_FONT                &lv_font_montserrat_18
#else
#define STATUSBAR_WIDTH                     0
#define STATUSBAR_HEIGHT                    0
#endif


#endif