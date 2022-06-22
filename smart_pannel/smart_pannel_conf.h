#ifndef SMART_PANNEL_CONF_H
#define SMART_PANNEL_CONF_H

#ifdef __cplusplus
extern "C" {
#endif

/* Interface */
// Status bar
#define STATUS_BAR_EN                       1
#define STATUS_BAR_AREA_LEFT_EN             1
#define STATUS_BAR_AREA_MID_EN              1
#define STATUS_BAR_AREA_RIGHT_EN            1
#if STATUS_BAR_AREA_MID_EN
#define STATUS_BAR_CLOCK_EN                 1
#define STATUS_BAR_CLOCK_DATE_EN            1
#define STATUS_BAR_CLOCK_SECOND_EN          0
#define STATUS_BAR_CLOCK_FORMAT_24          1
#endif

/* Utils */
#define OBJ_CONF_BORDER_EN                  1

/* Motion Detect */
#define MOTION_DET_SAMPLE_PERIOD            20
#define MOTION_DET_KEEP_TIME_MIN            100
#define MOTION_DET_KEEP_TIME_MAX            3000
#define MOTION_DET_DIS_THRESHOLD            50
#define MOTION_DET_DIS_TAN_MIN              -1
#define MOTION_DET_DIS_TAN_MAX              1

/* Log */
#define LOG_TRACE_INTERRFACE                0
#define LOG_TRACE_MOTION_DET                0
#define LOG_TRACE_MAIN                      1

#if LOG_TRACE_INTERRFACE
    #define INTERFACE_TRACE(...)            LV_LOG_USER(__VA_ARGS__)
#else
    #define INTERFACE_TRACE(...)
#endif

#if LOG_TRACE_MOTION_DET
    #define MOTION_DET_TRACE(...)           LV_LOG_USER(__VA_ARGS__)
#else
    #define MOTION_DET_TRACE(...)
#endif

#if LOG_TRACE_MAIN
    #define MAIN_TRACE(...)                 LV_LOG_USER(__VA_ARGS__)
#else
    #define MAIN_TRACE(...)
#endif

#ifdef __cplusplus
}
#endif

#endif