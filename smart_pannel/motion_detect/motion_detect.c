#include <math.h>
#include "lvgl.h"
#include "smart_pannel_conf.h"
#include "motion_detect.h"

static bool get_touch_pos(int *x, int *y);
static void timer_event(lv_timer_t *t);

static lv_obj_t *_event_obj;
static lv_event_code_t _event_id;
static motion_detect_touch_pos_t _touch_pos;
static int _x, _y;
static int _x_last, _y_last;
static bool _press_flag = false;

void motion_detect_init(lv_obj_t *event_obj, lv_event_code_t event_id)
{
    _event_obj = event_obj;
    _event_id = event_id;
    lv_timer_create(timer_event, MOTION_DET_SAMPLE_PERIOD, NULL);
}

void motion_detect_register_touch_pos(motion_detect_touch_pos_t touch_pos)
{
    _touch_pos = touch_pos;
}

static bool get_touch_pos(int *x, int *y)
{
    if (_touch_pos)
        return _touch_pos(x, y);
    else
        return false;
}

static void timer_event(lv_timer_t *t)
{
    static uint16_t press_keep_count = 0;
    bool res = get_touch_pos(&_x, &_y);

    if (res) {
        if (!_press_flag) {
            press_keep_count = 0;
            _press_flag = true;
            _x_last = _x;
            _y_last = _y;
        }
        else {
            if (press_keep_count < (MOTION_DET_KEEP_TIME_MAX / MOTION_DET_SAMPLE_PERIOD))
                press_keep_count++;
            else
                goto release;
        }
    }
    else {
        if (_press_flag) {
release:
            _press_flag = false;
            if (press_keep_count < (MOTION_DET_KEEP_TIME_MIN / MOTION_DET_SAMPLE_PERIOD)) {
                return;
            }

            motion_detect_type_t type;
            int distance_x, distance_y;
            distance_x = _x - _x_last;
            distance_y = _y - _y_last;
            if ((abs(distance_x) < MOTION_DET_DIS_THRESHOLD) &&
                (abs(distance_y) < MOTION_DET_DIS_THRESHOLD)) {
                return;
            }
            if (distance_x == 0) {
                if (distance_y < 0) {
                    type = MOTION_UP;
                    MOTION_DET_TRACE("up");
                }
                else if (distance_y > 0) {
                    type = MOTION_DOWN;
                    MOTION_DET_TRACE("down");
                }
                else {
                    return;
                }
            }
            else {
                float distance_tan;
                distance_tan = distance_y / 1.0 / distance_x;
                if ((distance_tan < MOTION_DET_DIS_TAN_MIN) ||
                    (distance_tan > MOTION_DET_DIS_TAN_MAX)) {
                    if (distance_y < 0) {
                        type = MOTION_UP;
                        MOTION_DET_TRACE("up");
                    }
                    else {
                        type = MOTION_DOWN;
                        MOTION_DET_TRACE("down");
                    }
                }
                else {
                    if (distance_x > 0) {
                        type = MOTION_RIGHT;
                        MOTION_DET_TRACE("right");
                    }
                    else {
                        type = MOTION_LEFT;
                        MOTION_DET_TRACE("left");
                    }
                }
            }

            lv_event_send(_event_obj, _event_id, (void *)type);
        }
    }
}
