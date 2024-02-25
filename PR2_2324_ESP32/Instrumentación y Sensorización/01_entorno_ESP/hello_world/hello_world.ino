/*-----------------------------------------------------+
 |     H E L L O _ W O R L D . I N O                   |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Instrumentación y Sensorización   |
 +-----------------------------------------------------*/
 
// El GPIO2 del ESP32-S3 WROOM está conectado a un LED
// por lo que asignamos el nombre LED_BUILTIN a 2 .
#define LED_BUILTIN 2

// función de inicialización de HW
void setup (void)
{
	// inicializamos el pin LED_BUILTIN como pin de salida.
	pinMode (LED_BUILTIN, OUTPUT);

} /* setup() */

// función loop que se ejecuta continuamente
void loop (void)
{
	digitalWrite (LED_BUILTIN, HIGH); // encender LED (HIGH valor de tensión a alto)
	delay (1000); // espera un segundo
	digitalWrite (LED_BUILTIN, LOW); // Apagar LED con valor de tensión a bajo
	delay (1000); // espera un segundo

} /* loop() */

/*** end of file ***/
