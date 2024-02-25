/*-----------------------------------------------------+
 |     B O T O N _ I N T E R . I N O                   |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Instrumentación y Sensorización   |
 +-----------------------------------------------------*/

#define PIN_LED    2
#define PIN_BUTTON 13

struct Button
{
	const uint8_t PIN;
	uint32_t numberKeyPresses;
	bool pressed;
};

Button button1 = {PIN_BUTTON, 0, false};

void IRAM_ATTR isr()
{
	button1.numberKeyPresses += 1;
	button1.pressed = true;
}

void setup(void)
{
	Serial.begin(115200);
	delay(500);
	Serial.println("ejemplo de manejo de pulsación por interrupciones");
	pinMode(PIN_LED, OUTPUT);
	pinMode(button1.PIN, INPUT_PULLUP);
	attachInterrupt(button1.PIN, isr, FALLING);

} /* setup() */

void loop(void)
{
	if (button1.pressed)
	{
		Serial.printf("El botón se ha pulsado %u veces\n", button1.numberKeyPresses);
		button1.pressed = false;
	}
  
	//Detach Interrupt after 1 Minute
	static uint32_t lastMillis = 0;
	if (millis() - lastMillis > 60000)
	{
		lastMillis = millis();
		detachInterrupt(button1.PIN);
		Serial.println("gestión de interrupción finalizada\n");
	}
	//delay(1000);

} /* loop() */

/*** end of file ***/
