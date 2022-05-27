#include "../interface_conf.h"
#include "../../utils/utils.h"
#include "app_table.h"

lv_obj_t *_table;

void app_table_init(lv_obj_t *parent)
{
    // Main area
    _table = lv_obj_create(parent);
}
