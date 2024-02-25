#include <Arduino.h>
#include "src/ESP32QRCodeReader.h"

////////////////////////////////////////////////////////////// 
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char *ssid = "UPV-PSK"; //Enter the router name
const char *password = "giirob-pr2-2023"; //Enter the router password

// MQTT Broker
const char *mqtt_broker = "mqtt.dsic.upv.es";
const char *topic = "PR2/DATOS/Grupo_X_Y/prueba_string";
const char *mqtt_username = "giirob";
const char *mqtt_password = "UPV2024";
const int mqtt_port = 1883;

String str;

WiFiClient espClient;
PubSubClient client(espClient);
//////////////////////////////////////////////////////////////

ESP32QRCodeReader reader(CAMERA_MODEL_ESP32S3_EYE);

void onQrCodeTask(void *pvParameters)
{
  struct QRCodeData qrCodeData;

  while (true)
  {
    //Serial.println("buscando código QR");
    if (reader.receiveQrCode(&qrCodeData, 100))
    {
      Serial.println("Found QRCode");
      if (qrCodeData.valid)
      {
        Serial.print("Payload: ");
        Serial.println((const char *)qrCodeData.payload);
        // Publish and subscribe
        client.publish(topic, (const char *)qrCodeData.payload);
        client.subscribe(topic);
      }
      else
      {
        Serial.print("Invalid: ");
        Serial.println((const char *)qrCodeData.payload);
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void setup()
{
  int result;
  Serial.begin(115200);
  Serial.println();

  //////////////////////////////////////////////////////////////
  // Connecting to a WiFi network
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
		delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the Wi-Fi network");
    //connecting to a mqtt broker
    client.setServer(mqtt_broker, mqtt_port);
    
    //client.setCallback(callback);

    while (!client.connected()) {
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress());
        Serial.printf("The client %s connects to the public MQTT broker\n", client_id.c_str());
        if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
            Serial.println("Public EMQX MQTT broker connected");
        } else {
            Serial.print("failed with state ");
            Serial.print(client.state());
            delay(2000);
        }
    }
    
    // Publish and subscribe
    client.publish(topic, "Hi, I'm ESP32 ^^");
    client.subscribe(topic);
  //////////////////////////////////////////////////////////////

  result=reader.setup();
  //reader.setDebug(true);
  //Serial.print("modo_debug ");
  Serial.println(reader.debug);
  if (result==SETUP_CAMERA_INIT_ERROR) Serial.println("Error init camara");
  else Serial.println("camara iniciada");
  Serial.println("Setup QRCode Reader");

  reader.beginOnCore(1);

  Serial.println("Begin on Core 1");

  xTaskCreate(onQrCodeTask, "onQrCode", 4 * 1024, NULL, 4, NULL);
}


void loop()
{
  //////////////////////////////////////////////////////////////
  client.loop();
  //////////////////////////////////////////////////////////////
  delay(100);
}