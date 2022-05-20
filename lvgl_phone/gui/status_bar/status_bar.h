#ifndef STATUS_BAR_H
#define STATUS_BAR_H

#include "../gui_conf.h"
#ifdef STATUS_BAR_EN

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void (*show)(void);
    void (*hide)(void);
} status_bar_t;

void status_bar_init(status_bar_t *status_bar, lv_obj_t *parent);

#ifdef __cplusplus
}
#endif

#endif

#endif