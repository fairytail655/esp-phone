#ifndef GUI_CONF_H
#define GUI_CONF_H

#include "lvgl.h"

#define WALLPAPER_COLOR     lv_color_make(0x4C, 0x58, 0x7B)
#define WALLPAPER_OPA       LV_OPA_TRANSP

#define OBJ_CONF_BORDER_EN

#define STATUS_BAR_EN
#ifdef STATUS_BAR_EN
#define STATUSBAR_WIDTH                     LV_HOR_RES
#define STATUSBAR_HEIGHT                    34
#define STATUSBAR_BG_COLOR                  lv_color_make(248, 248, 248)
#define STATUSBAR_AREA_OFFSET               10
#define STATUSBAR_AREA_LEFT_PERCENT         30
#define STATUSBAR_AREA_RIGHT_PERCENT        30
#define STATUSBAR_AREA_PAD                  3
#define STATUSBAR_ICON_SIZE                 24
#else
#define STATUSBAR_WIDTH                     0
#define STATUSBAR_HEIGHT                    0
#endif

#endif