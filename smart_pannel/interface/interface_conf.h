#ifndef INTERFACE_CONF_H
#define INTERFACE_CONF_H

#include "smart_pannel_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Background Srceen */
// Background Board
#define BG_BOARD_WIDTH                      440
#define BG_BOARD_HEIGHT                     380
#define BG_BOARD_RADIUS                     20
#define BG_BOARD_COLOR_ON                   0x89b0c7
#define BG_BOARD_COLOR_OFF                  0xe3e6ed
// Status Bar
#define STATUS_BAR_WIDTH                     LV_HOR_RES
#define STATUS_BAR_HEIGHT                    34
#define STATUS_BAR_BG_COLOR                  lv_color_make(248, 248, 248)
#define STATUS_BAR_ICON_SIZE                 24
#define STATUS_BAR_AREA_OFFSET               10
#define STATUS_BAR_AREA_LEFT_PERCENT         30
#define STATUS_BAR_AREA_RIGHT_PERCENT        30
#define STATUS_BAR_AREA_PAD                  3
#define STATUS_BAR_CLOCK_FONT                &lv_font_montserrat_18
#define STATUS_BAR_BATTERY_FONT              &lv_font_montserrat_14

#ifdef __cplusplus
}
#endif

#endif