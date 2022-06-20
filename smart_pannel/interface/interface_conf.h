#ifndef INTERFACE_CONF_H
#define INTERFACE_CONF_H

#include "smart_pannel_conf.h"

#ifdef __cplusplus
extern "C" {
#endif

#define INTERFACE_STATE_ON                   0
#define INTERFACE_STATE_OFF                  LV_STATE_USER_1

/* Background Srceen */
// Wallpaper
#define BG_WALLPAPER_COLOR                  lv_color_hex(0xf4f4fc)
// Background Board
#define BG_BOARD_WIDTH                      440
#define BG_BOARD_HEIGHT                     380
#define BG_BOARD_RADIUS                     20
#define BG_SPOT_ZOOM			            0.7
#define BG_SPOT_GAP			                5
#define BG_SPOT_COLOR_1			            lv_color_hex(0xc4c4c4)
#define BG_SPOT_COLOR_2			            lv_color_hex(0x1ebcfc)
#define BG_BOARD_OBJ_OPA_ON                 20
#define BG_BOARD_OBJ_COLOR_ON               lv_color_hex(0x04b4fc)
#define BG_BOARD_OBJ_OPA_OFF                20
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

/* Foreground Screen */
// Navigate Bar
#define NAVIGATE_BAR_WIDTH                  LV_HOR_RES
#define NAVIGATE_BAR_HEIGHT                 40
#define NAVIGATE_BAR_COLOR                  BG_WALLPAPER_COLOR
#define NAVIGATE_BAR_FONT                   &lv_font_montserrat_20
#define NAVIGATE_BAR_LEFT_OFFSET_1          20
#define NAVIGATE_BAR_LEFT_OFFSET_2          10
#define NAVIGATE_BAR_RIGHT_OFFSET           20
#define NAVIGATE_BAR_SW_WIDTH               45
#define NAVIGATE_BAR_SW_HEIGHT              (int)(0.5 * NAVIGATE_BAR_HEIGHT)
// App Area
#define APP_AREA_HEIGHT                     (LV_VER_RES - NAVIGATE_BAR_HEIGHT)

#ifdef __cplusplus
}
#endif

#endif