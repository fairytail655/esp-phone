#include "../../utils/utils.h"
#include "../interface_conf.h"
#include "status_icon.h"
#include "status_bar.h"

#define ICON_WIFI_ID        -1

typedef struct {
    int id;
    status_icon_t *icon;
    status_bar_area_t area;
} icon_node_t;

static icon_node_t *icon_ll_search(int id, status_bar_area_t *area);
static void area_icon_count_inc(status_bar_area_t area);
static void area_icon_count_dec(status_bar_area_t area);
static bool area_icon_count_check(status_bar_area_t area);
static void wifi_icon_init(void);

static lv_obj_t *_obj;
static lv_obj_t *_area_left, *_area_right, *_area_middle;
static uint16_t _area_left_width = 0, _area_right_width = 0;
static lv_ll_t _icon_ll;
#if STATUSBAR_AREA_LEFT_EN
static uint8_t _area_left_icon_count = 0, _area_left_icon_num_max;
#endif
#if STATUSBAR_AREA_RIGHT_EN
static uint8_t _area_right_icon_count = 0, _area_right_icon_num_max;
#endif
static const char *_area_str[] = {"left", "middle", "right"};

void status_bar_init(lv_obj_t *parent)
{
    // Main area
    obj_conf_style_t style = {
        .width = STATUSBAR_WIDTH,
        .height = STATUSBAR_HEIGHT,
        .pos_flag = OBJ_POS_FLAG_ALIGN,
        .align = LV_ALIGN_TOP_MID,
        .border_width = 0,
        .padd_all = 0,
        .radius = 0,
        .bg_color = STATUSBAR_BG_COLOR,
        .bg_opa = LV_OPA_COVER,
    };
    _obj = lv_obj_create(parent);
    obj_conf_style(_obj, &style);
    lv_obj_clear_flag(_obj, LV_OBJ_FLAG_SCROLLABLE);

    // Initialize contents of status_bar
    _lv_ll_init(&_icon_ll, sizeof(icon_node_t));

#if STATUSBAR_AREA_LEFT_EN
    // Left area
    _area_left = lv_obj_create(_obj);
    style.width = STATUSBAR_WIDTH * STATUSBAR_AREA_LEFT_PERCENT / 100;
    style.pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET;
    style.align = LV_ALIGN_LEFT_MID;
    style.x_offset = STATUSBAR_AREA_OFFSET;
    style.bg_opa = LV_OPA_TRANSP;
    obj_conf_style(_area_left, &style);
    _area_left_width = style.width;
    _area_left_icon_num_max = style.width / (STATUSBAR_ICON_SIZE + STATUSBAR_AREA_PAD);
    INTERFACE_TRACE("left area can contain %d icons", _area_left_icon_num_max);
    // Config layout
    lv_obj_set_flex_flow(_area_left, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_area_left, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(_area_left, STATUSBAR_AREA_PAD, 0);
    lv_obj_clear_flag(_area_left, LV_OBJ_FLAG_SCROLLABLE);
    // Init wifi
    wifi_icon_init();
#endif

#if STATUSBAR_AREA_RIGHT_EN
    // Right area
    _area_right = lv_obj_create(_obj);
    style.width = STATUSBAR_WIDTH * STATUSBAR_AREA_RIGHT_PERCENT / 100;
    style.pos_flag = OBJ_POS_FLAG_ALIGN_OFFSET;
    style.align = LV_ALIGN_RIGHT_MID;
    style.x_offset = -STATUSBAR_AREA_OFFSET;
    style.bg_opa = LV_OPA_TRANSP;
    obj_conf_style(_area_right, &style);
    _area_right_width = style.width;
    _area_right_icon_num_max = style.width / (STATUSBAR_ICON_SIZE + STATUSBAR_AREA_PAD);
    INTERFACE_TRACE("left area can contain %d icons", _area_right_icon_num_max);
    // Config layout
    lv_obj_set_flex_flow(_area_right, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_area_right, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_column(_area_right, STATUSBAR_AREA_PAD, 0);
    lv_obj_clear_flag(_area_right, LV_OBJ_FLAG_SCROLLABLE);
    // Init battery
    status_battery_init(_area_right);
#endif

#if STATUSBAR_AREA_MID_EN
    // Middle area
    _area_middle = lv_obj_create(_obj);
    int width_max = _area_left_width > _area_right_width ? _area_left_width : _area_right_width;
    style.width = STATUSBAR_WIDTH - (width_max + STATUSBAR_AREA_OFFSET) * 2;
    style.pos_flag = OBJ_POS_FLAG_ALIGN;
    style.align = LV_ALIGN_CENTER;
    style.bg_opa = LV_OPA_TRANSP;
    obj_conf_style(_area_middle, &style);
    // Config layout
    lv_obj_set_flex_flow(_area_middle, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(_area_middle, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(_area_middle, LV_OBJ_FLAG_SCROLLABLE);
#if STATUSBAR_CLOCK_EN
    // Init clock
    status_clock_init(_area_middle);
    status_clock_set_day(1);
    status_clock_set_hour(12);
    status_clock_set_min(0);
#if STATUSBAR_CLOCK_SECOND_EN
    status_clock_set_sec(0);
#endif
#endif
#endif

    INTERFACE_TRACE("status bar init finished");
}

void status_bar_add_icon(status_bar_area_t area, int id, const lv_img_src_t **state_src, uint8_t state_num)
{
    if (!area_icon_count_check(area)) {
        LV_LOG_WARN("the icon in the [%s] area is full", _area_str[area]);
        return;
    }

    status_icon_t *icon;
    switch (area) {
#if STATUSBAR_AREA_LEFT_EN
        case STATUS_BAR_AREA_LEFT:
            icon = status_icon_create(state_num, _area_left);
            break;
#endif
#if STATUSBAR_AREA_RIGHT_EN
        case STATUS_BAR_AREA_RIGHT:
            icon = status_icon_create(state_num, _area_right);
            break;
#endif
#if STATUSBAR_AREA_MID_EN
        // case STATUS_BAR_AREA_MIDDLE:
        //     icon = status_icon_create(state_num, _area_middle);
        //     break;
#endif
        default:
            LV_LOG_WARN("icon don't support be in the [%s] area", _area_str[area]);
            return;
    }
    area_icon_count_inc(area);
    for (int i = 0; i < state_num; i++) {
        status_icon_set_src(icon, i+1, (const lv_img_dsc_t *)state_src[i]);
    }
    status_icon_set_state(icon, 1);

    icon_node_t *icon_node = (icon_node_t *)_lv_ll_ins_tail(&_icon_ll);
    if (icon_node == NULL) {
        LV_LOG_WARN("icon_node malloc error");
        return;
    }
    icon_node->id = id;
    icon_node->area = area;
    icon_node->icon = icon;

    INTERFACE_TRACE("status_bar add an icon(%d) in the [%s] area with id(%d)", state_num, _area_str[area], id);
}

void status_bar_del_icon(int id)
{
    status_bar_area_t area;
    icon_node_t *node = icon_ll_search(id, &area);
    if (node == NULL) {
        LV_LOG_WARN("icon(id:%d) is already deleted.", id);
        return;
    }

    status_icon_destory(node->icon);
    _lv_ll_remove(&_icon_ll, node);
    area_icon_count_dec(area);
    INTERFACE_TRACE("status_bar delete icon(id:%d) in the [%s] area", id, _area_str[area]);
}

void status_bar_set_wifi_state(status_bar_wifi_state_t state)
{
    icon_node_t *node = icon_ll_search(ICON_WIFI_ID, NULL);
    if (node == NULL) {
        LV_LOG_WARN("wifi icon doesn't exist");
        return;
    }

    status_icon_set_state(node->icon, state);

    INTERFACE_TRACE("wifi state set [%d]", state);
}

static void wifi_icon_init(void)
{
    LV_IMG_DECLARE(img_wifi_1);
    LV_IMG_DECLARE(img_wifi_2);
    LV_IMG_DECLARE(img_wifi_3);
    LV_IMG_DECLARE(img_wifi_disconnect);
    LV_IMG_DECLARE(img_wifi_close);

    const lv_img_dsc_t *wifi_img[] = {
        &img_wifi_close, &img_wifi_disconnect,
        &img_wifi_1, &img_wifi_2, &img_wifi_3
    };
    status_bar_add_icon(STATUS_BAR_AREA_LEFT, ICON_WIFI_ID, (const lv_img_dsc_t **)wifi_img, 5);

    INTERFACE_TRACE("wifi icon init finished");
}

static icon_node_t *icon_ll_search(int id, status_bar_area_t *area)
{
    icon_node_t *node = _lv_ll_get_tail(&_icon_ll);
    while (node != NULL) {
        if (node->id == id)
            break;
        node = _lv_ll_get_prev(&_icon_ll, node);
    }

    if (area != NULL)
        *area = node->area;
    return node;
}

static void area_icon_count_inc(status_bar_area_t area)
{
    switch (area) {
#if STATUSBAR_AREA_LEFT_EN
        case STATUS_BAR_AREA_LEFT:
            if (_area_left_icon_count < _area_left_icon_num_max)
                _area_left_icon_count++;
            break;
#endif
#if STATUSBAR_AREA_RIGHT_EN
        case STATUS_BAR_AREA_RIGHT:
            if (_area_right_icon_count < _area_right_icon_num_max)
                _area_right_icon_count++;
            break;
#endif
        default:
            LV_LOG_WARN("icon don't support be in the [%s] area", _area_str[area]);
            break;
    }
}

static void area_icon_count_dec(status_bar_area_t area)
{
    switch (area) {
#if STATUSBAR_AREA_LEFT_EN
        case STATUS_BAR_AREA_LEFT:
            if (_area_left_icon_count > 0)
                _area_left_icon_count--;
            break;
#endif
#if STATUSBAR_AREA_RIGHT_EN
        case STATUS_BAR_AREA_RIGHT:
            if (_area_right_icon_count > 0)
                _area_right_icon_count--;
            break;
#endif
        default:
            LV_LOG_WARN("icon don't support be in the [%s] area", _area_str[area]);
            break;
    }
}

static bool area_icon_count_check(status_bar_area_t area)
{
    bool res = false;
    switch (area) {
#if STATUSBAR_AREA_LEFT_EN
        case STATUS_BAR_AREA_LEFT:
            if (_area_left_icon_count < _area_left_icon_num_max)
                res = true;
            break;
#endif
#if STATUSBAR_AREA_RIGHT_EN
        case STATUS_BAR_AREA_RIGHT:
            if (_area_right_icon_count < _area_right_icon_num_max)
                res = true;
            break;
#endif
        default:
            LV_LOG_WARN("icon don't support be in the [%s] area", _area_str[area]);
            break;
    }

    return res;
}
