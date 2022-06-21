#ifndef UI_HEATER_CONF_H
#define UI_HEATER_CONF_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

LV_FONT_DECLARE(my_font_bold_100);
LV_FONT_DECLARE(my_font_bold_60);

/* Background Screen */
#define BG_TITLE_Y_OFFSET         20
#define BG_TITLE_FONT             &lv_font_montserrat_16
#define BG_COLOR_L_2              lv_color_hex(0x04b4fc)
#define BG_COLOR_D_2              lv_color_hex(0x7e7e7e)
#define BG_TEMP_PAD               0
#define BG_TEMP_Y_OFFSET          20
#define BG_TEMP_FONT_L            &my_font_bold_100
#define BG_TEMP_FONT_S            &my_font_bold_60
#define BG_TEMP_SYMB_L            &lv_font_montserrat_24
#define BG_TEMP_SYMB_S            &lv_font_montserrat_20
#define BG_TEMP_BTN_W             100
#define BG_TEMP_BTN_H             60
#define BG_TEMP_BTN_OFFSET        20
#define BG_TEMP_BTN_RADIUS        10
#define BG_TEMP_BTN_COLOR         lv_color_hex(0xecf4fc)
#define BG_TEMP_BTN_PERIOD        1500
#define BG_TEMP_MAX               100
#define BG_TEMP_MIN               -100

#ifdef __cplusplus
}
#endif

#endif