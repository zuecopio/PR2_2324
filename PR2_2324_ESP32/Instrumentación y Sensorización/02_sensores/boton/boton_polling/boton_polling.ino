/*-----------------------------------------------------+
 |     B O T O N _ P O L L I N G . I N O               |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Instrumentación y Sensorización   |
 +-----------------------------------------------------*/
 
#define PIN_LED    2
#define PIN_BUTTON 13
// the setup function runs once when you press reset or power the board

void setup(void)
{
	// initialize digital pin PIN_LED as an output.
	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_BUTTON, INPUT);

} /* setup() */

// the loop function runs over and over again forever
void loop(void)
{
	if (digitalRead(PIN_BUTTON) == LOW)
	{
		digitalWrite(PIN_LED,HIGH);
	}
	else
	{
		digitalWrite(PIN_LED,LOW);
	}

	delay(100);
  
} /* loop() */

/*** end of file ***/
