#ifndef APP_CONF_H
#define APP_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

LV_FONT_DECLARE(my_font_bold_100);
LV_FONT_DECLARE(my_font_bold_60);

/* Air Conditioner */
#define AIR_COND_TITLE_Y_OFFSET         20
#define AIR_COND_TITLE_FONT             &lv_font_montserrat_16
#define AIR_COND_COLOR_L_2              lv_color_hex(0x04b4fc)
#define AIR_COND_COLOR_D_2              lv_color_hex(0x7e7e7e)
#define AIR_COND_TEMP_PAD               0
#define AIR_COND_TEMP_Y_OFFSET          20
#define AIR_COND_TEMP_FONT_L            &my_font_bold_100
#define AIR_COND_TEMP_FONT_S            &my_font_bold_60
#define AIR_COND_TEMP_SYMB_L            &lv_font_montserrat_24
#define AIR_COND_TEMP_SYMB_S            &lv_font_montserrat_20
#define AIR_COND_TEMP_BTN_W             100
#define AIR_COND_TEMP_BTN_H             60
#define AIR_COND_TEMP_BTN_OFFSET        20
#define AIR_COND_TEMP_BTN_RADIUS        10
#define AIR_COND_TEMP_BTN_COLOR         lv_color_hex(0xecf4fc)
#define AIR_COND_TEMP_BTN_PERIOD        1500
#define AIR_COND_TEMP_MAX               100
#define AIR_COND_TEMP_MIN               -100

#ifdef __cplusplus
}
#endif

#endif