/*-----------------------------------------------------+
 |     L E D _ R G B _ R A N D O M . I N O             |
 +-----------------------------------------------------| 
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |     
 |     Descripción : Instrumentación y Sensorización   |
 +-----------------------------------------------------*/

const byte ledPins[] = {38, 39, 40};    
const byte chns[]    = {0, 1, 2};          
int red, green, blue;

void setup (void)
{
	for (int i = 0; i < 3; i++)
	{   
		ledcSetup (chns[i], 1000, 8);
		ledcAttachPin (ledPins[i], chns[i]);
	}

} /* setup() */

void loop (void)
{
	red = random (0, 256);
	green = random (0, 256);
	blue = random (0, 256);
	setColor( red, green, blue);
	delay (200);

} /* loop() */

void setColor (byte r, byte g, byte b)
{
	ledcWrite (chns[0], 255 - r); 
	ledcWrite (chns[1], 255 - g);
	ledcWrite (chns[2], 255 - b);

} /* setColor() */

/*** end of file ***/
