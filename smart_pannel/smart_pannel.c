#include "lvgl.h"
#include "interface/interface.h"
#include "smart_pannel.h"

void smart_pannel_init(void)
{
    bg_screen_init();
    fg_screen_init();
    bg_screen_show();
}
