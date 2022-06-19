#ifndef SMART_PANNEL_CONF_H
#define SMART_PANNEL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Interface */
// Status bar
#define STATUS_BAR_EN                        1
#define STATUS_BAR_AREA_LEFT_EN              1
#define STATUS_BAR_AREA_MID_EN               1
#define STATUS_BAR_AREA_RIGHT_EN             1
#if STATUS_BAR_AREA_MID_EN
#define STATUS_BAR_CLOCK_EN                  1
#define STATUS_BAR_CLOCK_FORMAT_24           1
#define STATUS_BAR_CLOCK_SECOND_EN           1
#endif

/* Utils */
#define OBJ_CONF_BORDER_EN                  0

/* Log */
#define LOG_TRACE_GUI                       1

#if LOG_TRACE_GUI
    #define INTERFACE_TRACE(...)            LV_LOG_TRACE(__VA_ARGS__)
#else
    #define INTERFACE_TRACE(...)
#endif

#ifdef __cplusplus
}
#endif

#endif