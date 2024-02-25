/*-----------------------------------------------------+
 |     B T . I N O                                     |
 +-----------------------------------------------------|
 |     Autor       : Marcos Belda Martínez             |
 |     Asignatura  : PR2-GIIROB                        |
 |     Descripción : Comunicaciones en el ESP32:       |
 |                   ESP32 communicates with the phone |
 |                   by BLE and sends incoming data via|
 |                   a serial port.                    |
 +-----------------------------------------------------*/

#include "BLEDevice.h"
#include "BLEServer.h"
#include "BLEUtils.h"
#include "BLE2902.h"
#include "String.h"

BLECharacteristic * pCharacteristic;
bool deviceConnected = false;
uint8_t txValue = 0;
long lastMsg    = 0;
String rxload   = "Test\n";

#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E" 
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

class MyServerCallbacks : public BLEServerCallbacks
{
	void onConnect(BLEServer* pServer)
	{
		deviceConnected = true;
	};

	void onDisconnect(BLEServer* pServer)
	{
		deviceConnected = false;
	}
};

class MyCallbacks : public BLECharacteristicCallbacks
{
	void onWrite(BLECharacteristic *pCharacteristic)
	{
		std::string rxValue = pCharacteristic->getValue();
		
		if (rxValue.length() > 0)
		{
			rxload = "";
			
			for (int i = 0; i < rxValue.length(); i++)
			{
				rxload +=(char)rxValue[i];
			}
		}
	}
};

void setupBLE(String BLEName)
{
	const char * ble_name = BLEName.c_str();
	BLEDevice::init(ble_name);
	BLEServer * pServer = BLEDevice::createServer();
	pServer->setCallbacks(new MyServerCallbacks());
	BLEService * pService = pServer->createService(SERVICE_UUID); 
	pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX,BLECharacteristic::PROPERTY_NOTIFY);
	pCharacteristic->addDescriptor(new BLE2902());
	BLECharacteristic * pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_RX,BLECharacteristic::PROPERTY_WRITE);
	pCharacteristic->setCallbacks(new MyCallbacks()); 
	pService->start();
	pServer->getAdvertising()->start();
	Serial.println("Waiting a client connection to notify...");

} /* setupBLE() */

void setup(void)
{
	Serial.begin(115200);
	setupBLE("ESP32S3_Bluetooth");

} /* setup() */

void loop(void)
{
	long now = millis();
	
	if (now - lastMsg > 100)
	{
		if (deviceConnected & & rxload.length()>0)
		{
			Serial.println(rxload);
			rxload = "";
		}

		if (Serial.available()>0)
		{
			String str = Serial.readString();
			const char * newValue = str.c_str();
			pCharacteristic->setValue(newValue);
			pCharacteristic->notify();
		}

		lastMsg = now;
	}

} /* loop() */
