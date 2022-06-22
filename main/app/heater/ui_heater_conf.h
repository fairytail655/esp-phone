#ifndef ui_heater_CONF_H
#define ui_heater_CONF_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

LV_FONT_DECLARE(my_font_bold_100);
LV_FONT_DECLARE(my_font_bold_60);
LV_IMG_DECLARE(img_fire_on);
LV_IMG_DECLARE(img_fire_off);
LV_IMG_DECLARE(img_rest_on);
LV_IMG_DECLARE(img_rest_off);

#define TEMP_MAX                    100
#define TEMP_MIN                    -100

/* Background Screen */
#define BG_TITLE_Y_OFFSET           20
#define BG_TITLE_FONT               &lv_font_montserrat_16
#define BG_COLOR_L_2                lv_color_hex(0x04b4fc)
#define BG_COLOR_D_2                lv_color_hex(0x7e7e7e)
#define BG_TEMP_PAD                 0
#define BG_TEMP_Y_OFFSET            20
#define BG_TEMP_FONT_L              &my_font_bold_100
#define BG_TEMP_FONT_S              &my_font_bold_60
#define BG_TEMP_SYMB_L              &lv_font_montserrat_24
#define BG_TEMP_SYMB_S              &lv_font_montserrat_20
#define BG_CONT_WIDTH               400
#define BG_CONT_HEIGHT              70
#define BG_CONT_OFFSET              40
#define BG_CONT_PAD                 20
#define BG_BTN_RADIUS               15
#define BG_BTN_OPA                  LV_OPA_40
#define BG_BTN_COLOR                lv_color_hex(0xa4b0be)
#define BG_BTN_FONT                 &lv_font_montserrat_18
#define BG_BTN_FONT_COLOR_ON        lv_color_black()
#define BG_BTN_FONT_COLOR_OFF       lv_color_hex(0x7e7e7e)
#define BG_BTN_IMG_OFFSET           20

/* Foreground Screen */
// Target Temp
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
#define MODE_CONT_OFFSET            50
#define MODE_CONT_HEIGHT            100
#define MODE_BTN_FONT               &lv_font_montserrat_16
#define MODE_BTN_FONT_COLOR         BG_BTN_FONT_COLOR_OFF
#define MODE_BTN_COLOR              BG_BTN_COLOR
#define MODE_BTN_OPA                BG_BTN_OPA
#define MODE_BTN_RADIUS             BG_BTN_RADIUS
#define MODE_BTN_PAD                20
#define MODE_BTN_H_PERCENT          70
#define MODE_BTN_COLOR_ON           lv_color_hex(0x04b4fc)
#define MODE_BTN_COLOR_OFF          lv_color_hex(0xe4e4ec)

#ifdef __cplusplus
}
#endif

#endif