#ifndef PHONE_GUI_CONF_H
#define PHONE_GUI_CONF_H


/* GUI */
#define STATUSBAR_EN                        1
#define STATUSBAR_AREA_LEFT_EN              1
#define STATUSBAR_AREA_MID_EN               1
#define STATUSBAR_AREA_RIGHT_EN             1

#if STATUSBAR_AREA_MID_EN
#define STATUSBAR_CLOCK_EN                  1
#define STATUSBAR_CLOCK_FORMAT_24           1
#define STATUSBAR_CLOCK_SECOND_EN           1
#endif


/* Utils */
#define OBJ_CONF_BORDER_EN                  1


/* Log */
#define LOG_TRACE_GUI                       1

#if LOG_TRACE_GUI
    #define GUI_TRACE(...) LV_LOG_TRACE(__VA_ARGS__)
#else
    #define GUI_TRACE(...)
#endif


#endif