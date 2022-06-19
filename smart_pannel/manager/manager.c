#include "interface/interface.h"
#include "manager.h"

void manager_install_app(app_t *app)
{
    lv_obj_t *obj = bg_board_regiser_obj();
    bg_board_switch_obj(1);
    app->bg_screen_init(obj);
}
