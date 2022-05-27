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

/* Navigate bar */
#if NAVIGATEBAR_EN
#define NAVIGATEBAR_WIDTH                   LV_HOR_RES
#define NAVIGATEBAR_HEIGHT                  50
#define NAVIGATEBAR_BG_COLOR                lv_color_make(255, 255, 255)
#define NAVIGATEBAR_BG_OPA                  LV_OPA_20
#define NAVIGATEBAR_BTN_PRESS_OPA           LV_OPA_50
#else
#define NAVIGATEBAR_HEIGHT                  0
#endif

/* App icon ll */
#define APP_ICON_ZOOM_PERCENT               90

/* Shortcut bar */
#define SHORTCUT_ICON_SIZE                  100
#define SHORTCUT_ICON_PERCENT               72
#define SHORTCUT_LEFT_RIGHT_GAP             40
#define SHORTCUT_BOTTOM_GAP                 20
#define SHORTCUT_HEIGHT                     SHORTCUT_ICON_SIZE
#define SHORTCUT_WIDTH                      ((int)(4.5 * SHORTCUT_ICON_SIZE))
#define SHORTCUT_BOTTOM_OFFSET              (NAVIGATEBAR_HEIGHT + SHORTCUT_BOTTOM_GAP)
#define SHORTCUT_MAIN_RADIUS                20
#define SHORTCUT_BG_COLOR                   lv_color_make(248, 248, 248)
#define SHORTCUT_BG_OPA                     LV_OPA_60

#endif