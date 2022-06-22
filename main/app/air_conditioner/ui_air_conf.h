#ifndef UI_AIR_CONF_H
#define UI_AIR_CONF_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

LV_FONT_DECLARE(my_font_bold_100);
LV_FONT_DECLARE(my_font_bold_60);

#define TEMP_MAX                    100
#define TEMP_MIN                    -100

/* Background Screen */
#define BG_TITLE_Y_OFFSET           20
#define BG_TITLE_FONT               &lv_font_montserrat_20
#define BG_COLOR_L_2                lv_color_hex(0x04b4fc)
#define BG_COLOR_D_2                lv_color_hex(0x7e7e7e)
#define BG_TEMP_PAD                 0
#define BG_TEMP_Y_OFFSET            20
#define BG_TEMP_FONT_L              &my_font_bold_100
#define BG_TEMP_FONT_S              &my_font_bold_60
#define BG_TEMP_SYMB_L              &lv_font_montserrat_24
#define BG_TEMP_SYMB_S              &lv_font_montserrat_20
#define BG_TEMP_BTN_W               100
#define BG_TEMP_BTN_H               60
#define BG_TEMP_BTN_OFFSET          20
#define BG_TEMP_BTN_RADIUS          10
#define BG_TEMP_BTN_COLOR           lv_color_hex(0xecf4fc)
#define BG_TEMP_BTN_PERIOD          1000

/* Foreground Screen */
// Target Temp
#define FG_TITLE_FONT               &lv_font_montserrat_16
#define FG_COLOR_L_2                lv_color_hex(0x04b4fc)
#define FG_COLOR_D_2                lv_color_hex(0x7e7e7e)
#define FG_TEMP_PAD                 0
#define FG_TEMP_Y_OFFSET            20
#define FG_TEMP_FONT_L              &my_font_bold_100
#define FG_TEMP_FONT_S              &my_font_bold_60
#define FG_TEMP_SYMB_L              &lv_font_montserrat_24
#define FG_TEMP_SYMB_S              &lv_font_montserrat_20
#define FG_TEMP_BTN_W               100
#define FG_TEMP_BTN_H               60
#define FG_TEMP_BTN_OFFSET          20
#define FG_TEMP_BTN_RADIUS          10
#define FG_TEMP_BTN_COLOR           lv_color_hex(0xecf4fc)
#define FG_TEMP_BTN_PERIOD          1000
// Mode Area
#define MODE_CONT_WIDTH             (LV_HOR_RES - FG_TEMP_BTN_OFFSET * 2)
#define MODE_CONT_OFFSET            (FG_TEMP_BTN_OFFSET + FG_TEMP_BTN_H + 20)
#define MODE_CONT_HEIGHT            ((LV_VER_RES - NAVIGATE_BAR_HEIGHT -  MODE_CONT_OFFSET) / 3)
#define MODE_CONT_PAD               0
#define MODE_BTN_FONT               &lv_font_montserrat_16
#define MODE_BTN_FONT_COLOR         lv_color_hex(0x7e7e7e)
#define MODE_BTN_COLOR              lv_color_hex(0xa4b0be)
#define MODE_TITLE_FONT             &lv_font_montserrat_20
#define MODE_BTN_OPA                LV_OPA_40
#define MODE_BTN_RADIUS             15
#define MODE_BTN_PAD                20
#define MODE_BTN_H_PERCENT          70
#define MODE_BTN_COLOR_ON           lv_color_hex(0x04b4fc)
#define MODE_BTN_COLOR_OFF          lv_color_hex(0xe4e4ec)

#ifdef __cplusplus
}
#endif

#endif