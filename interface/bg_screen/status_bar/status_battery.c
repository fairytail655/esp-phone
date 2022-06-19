#include "../interface_conf.h"
#include "../../utils/utils.h"
#include "status_icon.h"
#include "status_battery.h"

lv_obj_t *_percent_label = NULL;
status_icon_t *_icon = NULL;

void status_battery_init(lv_obj_t *parent)
{
    // Main area
    lv_obj_t *obj = lv_obj_create(parent);
    obj_conf_style_t style = {
        .width = LV_SIZE_CONTENT,
        .height = LV_SIZE_CONTENT,
        .pos_flag = OBJ_POS_FLAG_NONE,
        .radius = 0,
        .border_width = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(obj, &style);
    // Config layout
	lv_obj_set_flex_flow(obj, LV_FLEX_FLOW_ROW);
	lv_obj_set_flex_align(obj, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
	lv_obj_set_style_pad_column(obj, 2, 0);

    // Display percent
    _percent_label = lv_label_create(obj);
    lv_obj_set_style_text_font(_percent_label, STATUSBAR_BATTERY_FONT, 0);

    // Display state icon
    LV_IMG_DECLARE(img_battery_empty);
    LV_IMG_DECLARE(img_battery_1);
    LV_IMG_DECLARE(img_battery_2);
    LV_IMG_DECLARE(img_battery_3);
    LV_IMG_DECLARE(img_battery_full);
    LV_IMG_DECLARE(img_battery_charge);
    const lv_img_dsc_t *battery_img[] = {
        &img_battery_empty, &img_battery_1, &img_battery_2,
        &img_battery_3, &img_battery_full, &img_battery_charge,
    };
    _icon = status_icon_create(6, obj);
    for (int i = 0; i < 6; i++) {
        status_icon_set_src(_icon, i + 1, battery_img[i]);
    }

    status_battery_set_percent(100, false);

    INTERFACE_TRACE("status battery init finished");
}

void status_battery_set_percent(uint8_t percent, bool flag)
{
    percent = (percent < 1) ? 1 : percent;
    percent = (percent > 100) ? 100 : percent;
    lv_label_set_text_fmt(_percent_label, "%d%%", percent);
    if (!flag)
        status_icon_set_state(_icon, (percent + 19) / 20);

    INTERFACE_TRACE("status battery set percent/flag [%d/%d]", percent, flag);
}

void status_battery_set_charge(void)
{
    status_icon_set_state(_icon, 6);

    INTERFACE_TRACE("status battery set charge", flag);
}
