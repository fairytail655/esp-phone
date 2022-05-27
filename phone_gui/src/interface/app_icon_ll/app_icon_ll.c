#include "../../utils/utils.h"
#include "../interface_conf.h"
#include "app_icon_ll.h"

typedef struct {
    int id;
    lv_obj_t *obj;
} app_icon_node_t;

static app_icon_node_t *icon_ll_search(lv_ll_t *ll,  int id);
static void event_cb(lv_event_t *e);

app_icon_ll_t *app_icon_ll_create(
    uint8_t size,
    uint8_t image_percent,
    lv_obj_t *parent,
    lv_obj_t *event_obj
)
{
    app_icon_ll_t *icon_ll = (app_icon_ll_t *)lv_mem_alloc(sizeof(app_icon_ll_t));
    if (icon_ll == NULL) {
        LV_LOG_ERROR("app_icon_ll malloc error");
        return NULL;
    }

    _lv_ll_init(&icon_ll->ll, sizeof(app_icon_node_t));
    icon_ll->size = size;
    icon_ll->image_percent = image_percent;
    icon_ll->parent = parent;
    icon_ll->event_obj = event_obj;

    return icon_ll;
}

void app_icon_ll_add(app_icon_ll_t *icon_ll, uint8_t id, const lv_img_dsc_t *src)
{
    // Main area
    lv_obj_t *obj = lv_obj_create(icon_ll->parent);
    obj_conf_style_t style = {
        .width = icon_ll->size,
        .height = icon_ll->size,
        .pos_flag = OBJ_POS_FLAG_NONE,
        .radius = 0,
        .border_width = 0,
        .pad_all = 0,
        .bg_opa = LV_OPA_TRANSP,
    };
    obj_conf_style(obj, &style);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

    // Image
    lv_obj_t *img = lv_img_create(obj);
    if (src == NULL) {
        LV_IMG_DECLARE(img_icon_default);
        src = &img_icon_default;
    }
    lv_obj_set_align(img, LV_ALIGN_CENTER);
    lv_img_set_src(img, src);
    // Calculate the multiple of the size between the target and the image.
    float h_factor, w_factor;
    int image_size = icon_ll->size * icon_ll->image_percent;
    h_factor = (image_size / 100.0) / src->header.h;
    w_factor = (image_size / 100.0) / src->header.w;
    // Scale the image to a suitable size.
    // So you don’t have to consider the size of the source image.
    if (h_factor < w_factor) {
        lv_img_set_zoom(img, (int)(h_factor * LV_IMG_ZOOM_NONE));
    }
    else {
        lv_img_set_zoom(img, (int)(w_factor * LV_IMG_ZOOM_NONE));
    }
    lv_obj_set_style_transform_zoom(img, (int)(LV_IMG_ZOOM_NONE * APP_ICON_ZOOM_PERCENT / 100.0), LV_STATE_PRESSED);
    lv_obj_set_style_transform_zoom(img, LV_IMG_ZOOM_NONE, LV_STATE_DEFAULT);
    lv_obj_add_flag(img, LV_OBJ_FLAG_CLICKABLE);

    app_icon_node_t *node = _lv_ll_ins_tail(&icon_ll->ll);
    node->id = id;
    node->obj = obj;

    lv_obj_add_event_cb(img, event_cb, LV_EVENT_CLICKED, (void *)id);
}

void app_icon_ll_del(app_icon_ll_t *icon_ll, uint8_t id)
{
    app_icon_node_t *node = icon_ll_search(&icon_ll->ll, id);
    if (node == NULL) {
        LV_LOG_WARN("icon node doesn't exist");
        return;
    }

    lv_obj_del(node->obj);
    _lv_ll_remove(&icon_ll->ll, node);
}

static app_icon_node_t *icon_ll_search(lv_ll_t *ll,  int id)
{
    app_icon_node_t *node = _lv_ll_get_tail(ll);
    while (node != NULL) {
        if (node->id == id)
            break;
        node = _lv_ll_get_prev(ll, node);
    }

    return node;
}

static void event_cb(lv_event_t *e)
{
    LV_LOG_ERROR("app[%d] clicked", (int)(e->user_data));
}
