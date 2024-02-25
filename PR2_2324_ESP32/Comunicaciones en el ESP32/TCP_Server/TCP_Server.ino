/*-----------------------------------------------------+
 |     T C P _ S E R V E R . I N O                     |
 +-----------------------------------------------------|
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Comunicaciones en el ESP32:       |
 |                   Use ESP32's WiFi server feature   |
 |                   to wait for other WiFi devices to |
 |                   connect. And communicate with     |
 |                   them once a connection has been   |
 |                   established.                      |
 +-----------------------------------------------------*/

#include <WiFi.h>
#define port 80
#define LED_BUILTIN 2

const char * ssid     = "UPV-PSK";         /* Enter the router name     */
const char * password = "giirob-pr2-2023"; /* Enter the router password */
WiFiServer server (port);

void setup (void)
{
	Serial.begin(115200);
	Serial.printf("\nConnecting to ");
	Serial.println(ssid);
	WiFi.disconnect();
	WiFi.begin(ssid, password);
	delay(1000);
	
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}

	Serial.println("");
	Serial.println("WiFi connected.");
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());			
	Serial.printf("IP port: %d\n",port);			
	server.begin(port); /* Para activar el puerto, pone a alguien a escuchar en el puerto 80 */
	WiFi.setAutoConnect(true);
	WiFi.setAutoReconnect(true);

	pinMode(LED_BUILTIN, OUTPUT);

} /* setup() */

void loop (void)
{
	// listen for incoming clients
	WiFiClient client = server.available();
	String str;
	
	// if you get a client
	if (client)
	{                                       
		Serial.println("Client connected.");

		// loop while the client's connected
		while (client.connected())
		{

			if (client.available())
			{ 
				str = client.readStringUntil('\n');
				Serial.println(str);	 /* print it out the serial monitor   */
				while (client.read()>0); /* clear the wifi receive area cache */
			}

			if (Serial.available())
			{    
				str = Serial.readStringUntil('\n'); /* if there's bytes to read from the serial monitor, */
				client.print(str);                  /* print it out the client.                          */
				while(Serial.read()>0);             /* clear the wifi receive area cache                 */
			}

			if (str == "ON")
			{
				digitalWrite(LED_BUILTIN, HIGH);
			}
			else if (str == "OFF")
			{
				digitalWrite(LED_BUILTIN, LOW);
			}
			else if (str == "BLINK1")
			{
				digitalWrite(LED_BUILTIN, HIGH);
				delay(200);
				digitalWrite(LED_BUILTIN, LOW);
				delay(200);
			}
			else if (str == "BLINK2")
			{
				digitalWrite(LED_BUILTIN, HIGH);
				delay(500);
				digitalWrite(LED_BUILTIN, LOW);
				delay(500);
			}
			else if (str == "BLINK3")
			{
				digitalWrite(LED_BUILTIN, HIGH);
				delay(1000);
				digitalWrite(LED_BUILTIN, LOW);
				delay(1000);
			}
		}

		// stop the client connecting
		client.stop();
		Serial.println("Client Disconnected.");
  	}

} /* loop() */

/**** end of file ***/