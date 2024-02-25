/*-----------------------------------------------------+
 |     W S 2 8 1 2 . C P P                             |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Cámara y visión en el ESP32       |
 +-----------------------------------------------------*/

#include "ws2812.h"

Freenove_ESP32_WS2812 strip = Freenove_ESP32_WS2812(1, WS2812_PIN, 1, TYPE_GRB);

void ws2812Init(void)
{
  strip.begin();
  strip.setBrightness(10);
  ws2812SetColor(0);

} /* ws2812Init() */

void ws2812SetColor(int color)
{
  if (color==0)
  {
    strip.setLedColorData(0, 0, 0, 0);
  }
  else if (color==1)
  {
    strip.setLedColorData(0, 255, 0, 0);
  }
  else if (color==2)
  {
    strip.setLedColorData(0, 0, 255, 0);
  }
  else if (color==3)
  {
    strip.setLedColorData(0, 0, 0, 255);
  }

  strip.show();

} /* ws2812SetColor() */

/*** end of file ***/