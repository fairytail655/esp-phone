#ifndef PHONE_GUI_CONF_H
#define PHONE_GUI_CONF_H

/* Interface */
// Status bar
#define STATUSBAR_EN                        1
#define STATUSBAR_AREA_LEFT_EN              1
#define STATUSBAR_AREA_MID_EN               1
#define STATUSBAR_AREA_RIGHT_EN             1
#if STATUSBAR_AREA_MID_EN
#define STATUSBAR_CLOCK_EN                  1
#define STATUSBAR_CLOCK_FORMAT_24           1
#define STATUSBAR_CLOCK_SECOND_EN           1
#endif
// Navigate bar
#define NAVIGATEBAR_EN                      1
// Shortcut bar
#define SHORTCUTBAR_EN                      1

/* Utils */
#define OBJ_CONF_BORDER_EN                  0

/* Log */
#define LOG_TRACE_GUI                       1

#if LOG_TRACE_GUI
    #define INTERFACE_TRACE(...) LV_LOG_TRACE(__VA_ARGS__)
#else
    #define INTERFACE_TRACE(...)
#endif

#endif