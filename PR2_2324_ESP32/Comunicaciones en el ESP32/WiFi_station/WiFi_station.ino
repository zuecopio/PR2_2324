/*-----------------------------------------------------+
 |     W I F I _ S T A T I O N . I N O                 |
 +-----------------------------------------------------|
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Comunicaciones en el ESP32:       |
 |                   Connect to your router using      |
 |                   ESP32.                            |
 +-----------------------------------------------------*/

#include <WiFi.h>

const char *ssid_Router     = "UPV-PSK";         /* Enter the router name     */
const char *password_Router = "giirob-pr2-2023"; /* Enter the router password */

void setup(void)
{
	Serial.begin(115200);
	delay(2000);
	Serial.println("Setup start");
	WiFi.begin(ssid_Router, password_Router);
	Serial.println(String("Connecting to ")+ssid_Router);
	
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}

	Serial.println("\nConnected, IP address: ");
	Serial.println(WiFi.localIP());
	Serial.println("\nPhysical address: ");
	Serial.println(WiFi.macAddress());

	Serial.println("Setup End");

} /* setup() */

void loop(void)
{
} /* loop() */

/*** end of file ***/