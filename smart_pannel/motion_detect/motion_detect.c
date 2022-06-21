#include "lvgl.h"
#include "smart_pannel_conf.h"
#include "motion_detect.h"

static bool get_touch_pos(int *x, int *y);
static void timer_event(lv_timer_t *t);

static bool _press_flag = false;

void motion_detect_init(void)
{
    lv_timer_create(timer_event, MOTION_DET_SAMPLE_PERIOD, NULL);
}

static bool get_touch_pos(int *x, int *y)
{
    lv_indev_t *indev = lv_indev_get_act();
    lv_point_t click_point;

    lv_indev_get_point(indev, &click_point);
    *x = click_point.x;
    *y = click_point.y;

    return true;
}

static void timer_event(lv_timer_t *t)
{
    int x, y;
    get_touch_pos(&x, &y);
    LV_LOG_ERROR("%d, %d", x, y);
}
