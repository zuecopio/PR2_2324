/*-----------------------------------------------------+
 |     C O N T R O L _ S E R V O . I N O               |
 +-----------------------------------------------------| 
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |     
 |     Descripción : Instrumentación y Sensorización   |
 +-----------------------------------------------------*/
 
#define SERVO_PIN 21  /* define the pwm pin       */
#define SERVO_CHN  0  /* define the pwm channel   */
#define SERVO_FRQ 50  /* define the pwm frequency */
#define SERVO_BIT 12  /* define the pwm precision */

void servo_set_pin(int pin);
void servo_set_angle(int angle);

void setup(void)
{
	servo_set_pin(SERVO_PIN);

} /* setup() */

void loop(void)
{
	for (int i = 0; i < 180; i++)
	{ 
		servo_set_angle(i);
		delay(10);
	}

	for (int i = 180; i > 0; i--)
	{  
		servo_set_angle(i);
		delay(10);
	}
  
} /* loop() */

void servo_set_pin(int pin)
{
	ledcSetup(SERVO_CHN, SERVO_FRQ, SERVO_BIT);
	ledcAttachPin(pin, SERVO_CHN);

} /* servo_set_pin() */

void servo_set_angle(int angle)
{
	if (angle > 180 || angle < 0)
	{
		return;
	}

	long pwm_value = map(angle, 0, 180, 103, 512);
	ledcWrite(SERVO_CHN, pwm_value);

} /* servo_set_angle() */

/*** end of file ***/
