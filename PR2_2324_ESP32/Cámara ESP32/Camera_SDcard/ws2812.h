/*-----------------------------------------------------+
 |     W S 2 8 1 2 . H                                 |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Cámara y visión en el ESP32       |
 +-----------------------------------------------------*/

#ifndef __WS2812_H
#define __WS2812_H

#include "Freenove_WS2812_Lib_for_ESP32.h"

#define WS2812_PIN  48

void ws2812Init(void);
void ws2812SetColor(int color);

#endif /* __WS2812_H */

/*** end of file ***/