#include "../../utils/utils.h"
#include "../interface_conf.h"
#include "status_icon.h"

status_icon_t *status_icon_create(uint8_t state_num, lv_obj_t *parent)
{
    // Create container
    lv_obj_t *obj = lv_obj_create(parent);
    obj_conf_style_t style = {
        .width = STATUSBAR_ICON_SIZE,
        .height = STATUSBAR_ICON_SIZE,
        .pos_flag = OBJ_POS_FLAG_NONE,
        .radius = 0,
        .border_width = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(obj, &style);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    // Create empty images and hide them
    lv_obj_t **img = (lv_obj_t **)lv_mem_alloc(sizeof(lv_obj_t *) * state_num);
    for (int i = 0; i < state_num; i++) {
        img[i] = lv_img_create(obj);
        lv_obj_align(img[i], LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_flag(img[i], LV_OBJ_FLAG_HIDDEN);
    }

    status_icon_t *icon = (status_icon_t *)lv_mem_alloc(sizeof(status_icon_t));
    icon->state_num = state_num;
    icon->current_state = 0;
    icon->_obj = obj;
    icon->_img = img;

    return icon;
}

void status_icon_destory(status_icon_t *icon)
{
    if (icon == NULL)
        return;

    lv_obj_del(icon->_obj);
    lv_mem_free(icon->_img);
    lv_mem_free(icon);
}

void status_icon_set_src(status_icon_t *icon, uint8_t state_index, const lv_img_dsc_t *src)
{
    if ((state_index > icon->state_num) || (state_index == 0)) {
        LV_LOG_WARN("state_index out of numbers");
        return;
    }

    lv_obj_t *img = icon->_img[state_index - 1];
    lv_img_set_src(img, src);
    if ((src->header.h != STATUSBAR_ICON_SIZE) && (src->header.w != STATUSBAR_ICON_SIZE)) {
        // Calculate the multiple of the size between the target and the image.
        float h_factor = (float)(STATUSBAR_ICON_SIZE) / src->header.h;
        float w_factor = (float)(STATUSBAR_ICON_SIZE) / src->header.w;
        // Scale the image to a suitable size.
        // So you don’t have to consider the size of the source image.
        if (h_factor < w_factor) {
            lv_img_set_zoom(img, (int)(h_factor * LV_IMG_ZOOM_NONE));
        }
        else {
            lv_img_set_zoom(img, (int)(w_factor * LV_IMG_ZOOM_NONE));
        }
    }
}

void status_icon_set_state(status_icon_t *icon, uint8_t state_index)
{
    if (state_index > icon->state_num) {
        LV_LOG_WARN("state_index out of numbers");
        return;
    }

    uint8_t current_state = icon->current_state;
    if (current_state != state_index) {
        if (current_state != 0)
            lv_obj_add_flag(icon->_img[current_state - 1], LV_OBJ_FLAG_HIDDEN);
        if (state_index != 0)
            lv_obj_clear_flag(icon->_img[state_index - 1], LV_OBJ_FLAG_HIDDEN);
    }

    icon->current_state = state_index;
}
