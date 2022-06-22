#ifndef MOTION_DETECT_H
#define MOTION_DETECT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	MOTION_UP = 0,
	MOTION_DOWN,
	MOTION_LEFT,
	MOTION_RIGHT,
} motion_detect_type_t;
typedef bool (*motion_detect_touch_pos_t)(int *x, int *y);

void motion_detect_init(lv_obj_t *event_obj, lv_event_code_t event_id);
void motion_detect_register_touch_pos(motion_detect_touch_pos_t touch_pos);
lv_obj_t *motion_detect_event_obj(void);
lv_event_code_t motion_detect_event_id(void);

#ifdef __cplusplus
}
#endif

#endif