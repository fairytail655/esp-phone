#ifndef SHORTCUT_BAR_H
#define SHORTCUT_BAR_H

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

void shortcut_bar_init(lv_obj_t *parent);
void shortcut_bar_show(bool flag);
void shortcut_bar_add_icon(uint8_t id, const lv_img_dsc_t *src);
void shortcut_bar_del_icon(uint8_t id);

#ifdef __cplusplus
}
#endif

#endif