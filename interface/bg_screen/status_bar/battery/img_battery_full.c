#include "lvgl.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif
#ifndef LV_ATTRIBUTE_IMG_IMG_BATTERY_FULL
#define LV_ATTRIBUTE_IMG_IMG_BATTERY_FULL
#endif
const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_IMG_IMG_BATTERY_FULL uint8_t img_battery_full_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x6d, 0x7e, 0x6d, 0xf5, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf3, 0x6d, 0xd2, 0x49, 0x1a, 0x00, 0x00, 
  0x6d, 0xfc, 0x6d, 0x1b, 0x6d, 0x42, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x0c, 0x6d, 0xa9, 0x6d, 0x75, 0x00, 0x00, 
  0x6d, 0xff, 0x00, 0x00, 0x6d, 0xb0, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x20, 0x6d, 0x90, 0x6d, 0x80, 0x00, 0x00, 
  0x6d, 0xff, 0x00, 0x00, 0x6d, 0xb0, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x20, 0x6d, 0x90, 0x6d, 0xff, 0x6d, 0xff, 
  0x6d, 0xff, 0x00, 0x00, 0x6d, 0xb0, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x20, 0x6d, 0x90, 0x6d, 0xff, 0x6d, 0xff, 
  0x6d, 0xff, 0x00, 0x00, 0x6d, 0xb0, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x20, 0x6d, 0x90, 0x6d, 0xff, 0x6d, 0xff, 
  0x6d, 0xff, 0x00, 0x00, 0x6d, 0xb0, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x20, 0x6d, 0x90, 0x6d, 0xff, 0x6d, 0xff, 
  0x6d, 0xff, 0x00, 0x00, 0x6d, 0xb0, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x6d, 0xff, 0x49, 0x20, 0x6d, 0x90, 0x6d, 0x80, 0x00, 0x00, 
  0x6d, 0xfc, 0x6d, 0x1b, 0x6d, 0x42, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x60, 0x6d, 0x0c, 0x6d, 0xa9, 0x6d, 0x75, 0x00, 0x00, 
  0x6d, 0x7e, 0x6d, 0xf4, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf0, 0x6d, 0xf3, 0x6d, 0xd2, 0x49, 0x1a, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xaa, 0x52, 0x7e, 0xaa, 0x52, 0xf5, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf3, 0xaa, 0x52, 0xd2, 0x6a, 0x52, 0x1a, 0x00, 0x00, 0x00, 
  0xaa, 0x52, 0xfc, 0xab, 0x5a, 0x1b, 0x8a, 0x52, 0x42, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0xab, 0x5a, 0x0c, 0xaa, 0x52, 0xa9, 0xaa, 0x52, 0x75, 0x00, 0x00, 0x00, 
  0xaa, 0x52, 0xff, 0x00, 0x00, 0x00, 0xaa, 0x52, 0xb0, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0x8a, 0x52, 0x20, 0xaa, 0x52, 0x90, 0xaa, 0x52, 0x80, 0x00, 0x00, 0x00, 
  0xaa, 0x52, 0xff, 0x00, 0x00, 0x00, 0xaa, 0x52, 0xb0, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0x8a, 0x52, 0x20, 0xaa, 0x52, 0x90, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 
  0xaa, 0x52, 0xff, 0x00, 0x00, 0x00, 0xaa, 0x52, 0xb0, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0x8a, 0x52, 0x20, 0xaa, 0x52, 0x90, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 
  0xaa, 0x52, 0xff, 0x00, 0x00, 0x00, 0xaa, 0x52, 0xb0, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0x8a, 0x52, 0x20, 0xaa, 0x52, 0x90, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 
  0xaa, 0x52, 0xff, 0x00, 0x00, 0x00, 0xaa, 0x52, 0xb0, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0x8a, 0x52, 0x20, 0xaa, 0x52, 0x90, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 
  0xaa, 0x52, 0xff, 0x00, 0x00, 0x00, 0xaa, 0x52, 0xb0, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0xaa, 0x52, 0xff, 0x8a, 0x52, 0x20, 0xaa, 0x52, 0x90, 0xaa, 0x52, 0x80, 0x00, 0x00, 0x00, 
  0xaa, 0x52, 0xfc, 0xab, 0x5a, 0x1b, 0x8a, 0x52, 0x42, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0x8a, 0x52, 0x60, 0xab, 0x5a, 0x0c, 0xaa, 0x52, 0xa9, 0xaa, 0x52, 0x75, 0x00, 0x00, 0x00, 
  0xaa, 0x52, 0x7e, 0xaa, 0x52, 0xf4, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf0, 0xaa, 0x52, 0xf3, 0xaa, 0x52, 0xd2, 0x6a, 0x52, 0x1a, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x52, 0xaa, 0x7e, 0x52, 0xaa, 0xf5, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf3, 0x52, 0xaa, 0xd2, 0x52, 0x6a, 0x1a, 0x00, 0x00, 0x00, 
  0x52, 0xaa, 0xfc, 0x5a, 0xab, 0x1b, 0x52, 0x8a, 0x42, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x5a, 0xab, 0x0c, 0x52, 0xaa, 0xa9, 0x52, 0xaa, 0x75, 0x00, 0x00, 0x00, 
  0x52, 0xaa, 0xff, 0x00, 0x00, 0x00, 0x52, 0xaa, 0xb0, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0x8a, 0x20, 0x52, 0xaa, 0x90, 0x52, 0xaa, 0x80, 0x00, 0x00, 0x00, 
  0x52, 0xaa, 0xff, 0x00, 0x00, 0x00, 0x52, 0xaa, 0xb0, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0x8a, 0x20, 0x52, 0xaa, 0x90, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 
  0x52, 0xaa, 0xff, 0x00, 0x00, 0x00, 0x52, 0xaa, 0xb0, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0x8a, 0x20, 0x52, 0xaa, 0x90, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 
  0x52, 0xaa, 0xff, 0x00, 0x00, 0x00, 0x52, 0xaa, 0xb0, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0x8a, 0x20, 0x52, 0xaa, 0x90, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 
  0x52, 0xaa, 0xff, 0x00, 0x00, 0x00, 0x52, 0xaa, 0xb0, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0x8a, 0x20, 0x52, 0xaa, 0x90, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 
  0x52, 0xaa, 0xff, 0x00, 0x00, 0x00, 0x52, 0xaa, 0xb0, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0xaa, 0xff, 0x52, 0x8a, 0x20, 0x52, 0xaa, 0x90, 0x52, 0xaa, 0x80, 0x00, 0x00, 0x00, 
  0x52, 0xaa, 0xfc, 0x5a, 0xab, 0x1b, 0x52, 0x8a, 0x42, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x52, 0x8a, 0x60, 0x5a, 0xab, 0x0c, 0x52, 0xaa, 0xa9, 0x52, 0xaa, 0x75, 0x00, 0x00, 0x00, 
  0x52, 0xaa, 0x7e, 0x52, 0xaa, 0xf4, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf0, 0x52, 0xaa, 0xf3, 0x52, 0xaa, 0xd2, 0x52, 0x6a, 0x1a, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
#if LV_COLOR_DEPTH == 32
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x53, 0x53, 0x53, 0x7e, 0x53, 0x53, 0x53, 0xf5, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf3, 0x53, 0x53, 0x53, 0xd2, 0x4e, 0x4e, 0x4e, 0x1a, 0x00, 0x00, 0x00, 0x00, 
  0x53, 0x53, 0x53, 0xfc, 0x55, 0x55, 0x55, 0x1b, 0x51, 0x51, 0x51, 0x42, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x55, 0x55, 0x55, 0x0c, 0x53, 0x53, 0x53, 0xa9, 0x53, 0x53, 0x53, 0x75, 0x00, 0x00, 0x00, 0x00, 
  0x53, 0x53, 0x53, 0xff, 0x00, 0x00, 0x00, 0x00, 0x53, 0x53, 0x53, 0xb0, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x50, 0x50, 0x50, 0x20, 0x53, 0x53, 0x53, 0x90, 0x54, 0x54, 0x54, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x53, 0x53, 0x53, 0xff, 0x00, 0x00, 0x00, 0x00, 0x53, 0x53, 0x53, 0xb0, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x50, 0x50, 0x50, 0x20, 0x53, 0x53, 0x53, 0x90, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 
  0x53, 0x53, 0x53, 0xff, 0x00, 0x00, 0x00, 0x00, 0x53, 0x53, 0x53, 0xb0, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x50, 0x50, 0x50, 0x20, 0x53, 0x53, 0x53, 0x90, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 
  0x53, 0x53, 0x53, 0xff, 0x00, 0x00, 0x00, 0x00, 0x53, 0x53, 0x53, 0xb0, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x50, 0x50, 0x50, 0x20, 0x53, 0x53, 0x53, 0x90, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 
  0x53, 0x53, 0x53, 0xff, 0x00, 0x00, 0x00, 0x00, 0x53, 0x53, 0x53, 0xb0, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x50, 0x50, 0x50, 0x20, 0x53, 0x53, 0x53, 0x90, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 
  0x53, 0x53, 0x53, 0xff, 0x00, 0x00, 0x00, 0x00, 0x53, 0x53, 0x53, 0xb0, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x53, 0x53, 0x53, 0xff, 0x50, 0x50, 0x50, 0x20, 0x53, 0x53, 0x53, 0x90, 0x54, 0x54, 0x54, 0x80, 0x00, 0x00, 0x00, 0x00, 
  0x53, 0x53, 0x53, 0xfc, 0x55, 0x55, 0x55, 0x1b, 0x51, 0x51, 0x51, 0x42, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x52, 0x52, 0x52, 0x60, 0x55, 0x55, 0x55, 0x0c, 0x53, 0x53, 0x53, 0xa9, 0x53, 0x53, 0x53, 0x75, 0x00, 0x00, 0x00, 0x00, 
  0x53, 0x53, 0x53, 0x7e, 0x53, 0x53, 0x53, 0xf4, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf0, 0x53, 0x53, 0x53, 0xf3, 0x53, 0x53, 0x53, 0xd2, 0x4e, 0x4e, 0x4e, 0x1a, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
#endif
};

const lv_img_dsc_t img_battery_full = {
  .header.always_zero = 0,
  .header.w = 20,
  .header.h = 20,
  .data_size = 400 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = img_battery_full_map,
};
