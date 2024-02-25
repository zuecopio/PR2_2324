/*-----------------------------------------------------+
 |     M Q T T . I N O                                 |
 +-----------------------------------------------------|
 |     Alumno      : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Comunicaciones en el ESP32        |
 +-----------------------------------------------------*/

#include <WiFi.h>
#include <PubSubClient.h>
#define LED_BUILTIN 2

// WiFi
const char * ssid     = "UPV-PSK";         /* Enter the router name     */
const char * password = "giirob-pr2-2023"; /* Enter the router password */

// MQTT Broker
const char * mqtt_broker   = "broker.emqx.io";
const char * topic1        = "emqx/Grupo_A1_10/salida";
const char * topic2        = "emqx/Grupo_A1_10/estado_LED";
const char * mqtt_username = "emqx";
const char * mqtt_password = "public";
const int mqtt_port        = 1883;

String str;

WiFiClient espClient;
PubSubClient client(espClient);

void setup(void)
{
	pinMode(LED_BUILTIN, OUTPUT);

	// Set software serial baud to 115200;
	Serial.begin(115200);
	// Connecting to a WiFi network
	WiFi.begin(ssid, password);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.println("Connecting to WiFi..");
	}

	Serial.println("Connected to the Wi-Fi network");
	//connecting to a mqtt broker
	client.setServer(mqtt_broker, mqtt_port);
	client.setCallback(callback);

	while (!client.connected())
	{
		String client_id = "esp32-client-";
		client_id += String(WiFi.macAddress());
		Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());

		if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
		{
			Serial.println("Public EMQX MQTT broker connected");
		}
		else
		{
			Serial.print("failed with state ");
			Serial.print(client.state());
			delay(2000);
		}
	}

	// Publish and subscribe
	client.publish(topic2, "Hi, I'm ESP32 ^^");
	client.subscribe(topic2);

} /* setup() */

void callback(char * topic2, byte * payload, unsigned int length)
{
	Serial.print("Message arrived in topic: ");
	Serial.println(topic2);
	Serial.print("Message:");

	for (int i = 0; i < length; i++)
	{
		str += ((char) payload[i]);
	}

	Serial.print(str);

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
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(LED_BUILTIN, HIGH);
			delay(200);
			digitalWrite(LED_BUILTIN, LOW);
			delay(200);
		}
	}
	else if (str == "BLINK2")
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(LED_BUILTIN, HIGH);
			delay(500);
			digitalWrite(LED_BUILTIN, LOW);
			delay(500);
		}
	}
	else if (str == "BLINK3")
	{
		for (int i = 0; i < 10; i++)
		{
			digitalWrite(LED_BUILTIN, HIGH);
			delay(1000);
			digitalWrite(LED_BUILTIN, LOW);
			delay(1000);
		}
	}

	str = "";

	Serial.println();
	Serial.println("-----------------------");

} /* callback() */

void loop(void)
{
	client.loop();

} /* loop() */

/*** end of file ***/