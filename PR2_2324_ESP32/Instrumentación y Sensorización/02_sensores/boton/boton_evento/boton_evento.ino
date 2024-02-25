/*-----------------------------------------------------+
 |     B O T O N _ E V E N T O . I N O                 |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Instrumentación y Sensorización   |
 +-----------------------------------------------------*/
 
#include <EventButton.h>
EventButton button1(13);
#define PIN_LED    2
#define PIN_BUTTON 13

void onbutton1Pulsado(EventButton& eb)
{
	Serial.print("boton pulsado");
	digitalWrite(PIN_LED,LOW);
	Serial.println(eb.clickCount());

} /* onbutton1Pulsado() */

void onbutton1Liberado(EventButton& eb)
{
	Serial.print("boton liberado");
	digitalWrite(PIN_LED,HIGH);
	Serial.println(eb.clickCount());

} /* onbutton1Liberado() */

void setup(void)
{
	Serial.begin(115200);
	delay(500);
	Serial.println("ejemplo de manejo de pulsación por eventos");
	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_BUTTON, INPUT);
	button1.setClickHandler(onbutton1Pulsado);
	button1.setReleasedHandler(onbutton1Liberado);

} /* setup() */

void loop(void)
{
	button1.update();
	delay(10);

} /* loop() */

/*** end of file ***/
