#ifndef INTERFACE_CONF_H
#define INTERFACE_CONF_H

#include "smart_pannel_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Background Srceen */
// Wallpaper
#define BG_WALLPAPER_COLOR                  lv_color_hex(0xf4f4fc)
// #define BG_WALLPAPER_COLOR                  lv_color_hex(0x0)
// Background Board
#define BG_BOARD_WIDTH                      440
#define BG_BOARD_HEIGHT                     380
#define BG_BOARD_RADIUS                     20
#define BG_SPOT_ZOOM			            0.7
#define BG_SPOT_GAP			                5
#define BG_SPOT_COLOR_1			            lv_color_hex(0xc4c4c4)
#define BG_SPOT_COLOR_2			            lv_color_hex(0x1ebcfc)
#define BG_BOARD_OBJ_OPA_ON                 LV_OPA_TRANSP
#define BG_BOARD_OBJ_COLOR_ON               lv_color_hex(0x89b0c7)
#define BG_BOARD_OBJ_OPA_OFF                LV_OPA_10
#define BG_BOARD_OBJ_COLOR_OFF              lv_color_hex(0x0)
// Status Bar
#define STATUS_BAR_WIDTH                     LV_HOR_RES
#define STATUS_BAR_HEIGHT                    24
#define STATUS_BAR_BG_COLOR                  BG_WALLPAPER_COLOR
#define STATUS_BAR_ICON_SIZE                 20
#define STATUS_BAR_AREA_OFFSET               10
#define STATUS_BAR_AREA_LEFT_PERCENT         30
#define STATUS_BAR_AREA_RIGHT_PERCENT        30
#define STATUS_BAR_AREA_PAD                  3
#define STATUS_BAR_CLOCK_FONT                &lv_font_montserrat_14
#define STATUS_BAR_BATTERY_FONT              &lv_font_montserrat_12

#ifdef __cplusplus
}
#endif

#endif