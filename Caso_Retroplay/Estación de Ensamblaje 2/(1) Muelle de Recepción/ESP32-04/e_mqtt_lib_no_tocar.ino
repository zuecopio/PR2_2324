/**
 * @file     e_mqtt_lib_no_tocar.ino
 *
 * @brief    Implementation of MQTT functions.
 *
 * @date     April, 2024
 * @section  PR2-GIIROB
 */

#define MQTT_CONNECTION_RETRIES 3

PubSubClient mqttClient(espWifiClient);

// MQTT CONFIG
const char * mqttServerIP   = MQTT_SERVER_IP;
unsigned int mqttServerPort = MQTT_SERVER_PORT;
String mqttClientID;

/******************************************************************************/
/*!
 * @brief  MQTT loop function.
 * @param  void
 * @return void
 */
void mqtt_loop(void)
{
    if (!mqttClient.connected())
    {
        mqtt_reconnect(MQTT_CONNECTION_RETRIES);
        suscribirseATopics();
    }

    mqttClient.loop();

}   /* mqtt_loop() */

/******************************************************************************/
/*!
 * @brief  MQTT connect function.
 * @param  clientID  (String)
 * @return void
 */
void mqtt_connect(String clientID)
{
    // Configuramos cliente MQTT.
    mqttClientID = String(clientID);
    mqttClient.setServer(mqttServerIP, mqttServerPort);

    // Configuramos 'mqttCallback' como la función que se invocará al 
    // recibir datos por las suscripciones realizadas.
    mqttClient.setCallback(mqttCallback);

    // Conectamos.
    mqtt_reconnect(MQTT_CONNECTION_RETRIES);

}   /* mqtt_connect() */

/******************************************************************************/
/*!
 * @brief  MQTT reconnect function.
 * @param  retries  (int)
 * @return void
 */
void mqtt_reconnect(int retries)
{
    if (!WiFi.isConnected())
    {
        return;
    }

    if (!mqttClient.connected())
    {
        warnln("Disconnected from the MQTT broker");
    }

    // Loop until we're reconnected, or a number of retries ...
    int r = 0;
    while ((!mqttClient.connected()) && (r < retries))
    {
        r++;

        trace("Attempting an MQTT connection to: 'mqtt://");
        trace(mqttServerIP);
        trace(":");
        trace(mqttServerPort);
        trace("' with client-id: '");
        trace(mqttClientID);
        traceln("' ... ");

        // Attempt to connect
        // boolean connect (clientID, [username, password], [willTopic, willQoS, willRetain, willMessage], [cleanSession])

        #ifdef MQTT_USERNAME
        if (mqttClient.connect(mqttClientID.c_str(), MQTT_USERNAME, MQTT_PASSWORD))
        {
        #else
        if (mqttClient.connect(mqttClientID.c_str()))
        {
        #endif
            debugln("-=- Connected to MQTT Broker");
            // Damos tiempo a que la conexión se establezca por completo.
            delay(1000);
        }
        else
        {
            debug("-X- failed, rc=");
            debugln(mqttClient.state());
            debugln("-R-   re-trying in 5 seconds");
            // Wait 5 seconds before retrying
            delay(5000);
        }
    }

}   /* mqtt_reconnect() */

/******************************************************************************/
/*!
 * @brief  MQTT callback function.
 * @param  topic    (char *)
 * @param  message  (byte *)
 * @param  length   (unsigned int)
 * @return void
 */
void mqttCallback(char * topic, byte * message, unsigned int length)
{
    // Función que se invocará automáticamente al recibir datos
    // por algún topic sobre el que nos hayamos suscrito.

    // Cargamos los datos recibidos en una variable.
    String incomingMessage;
    for (int i = 0; i < length; i++)
    {
        incomingMessage += (char)message[i];
    }

    traceln("<<~~ RECEIVING an MQTT message:");
    traceln(topic);
    traceln(incomingMessage);

    alRecibirMensajePorTopic(topic, incomingMessage);

}   /* mqttCallback() */

/******************************************************************************/
/*!
 * @brief  MQTT publish function.
 * @param  topic            (const char *)
 * @param  outgoingMessage  (String)
 * @return void
 */
void mqtt_publish(const char * topic, String outgoingMessage)
{
    if (!mqttClient.connected())
    {
        errorln("Cannot send message through the topic ... the MQTT Client is disconnected!!")
        return;
    }

    traceln("~~>> PUBLISHING an MQTT message:");
    traceln(topic);
    traceln(outgoingMessage);
    mqttClient.publish(topic, outgoingMessage.c_str());

}   /* mqtt_publish() */

/******************************************************************************/
/*!
 * @brief  MQTT subscribe function.
 * @param  topic  (const char *)
 * @return void
 */
void mqtt_subscribe(const char * topic)
{
    if (!mqttClient.connected())
    {
        errorln("Cannot subscribe to topic ... the MQTT Client is disconnected!!")
        return;
    }

    trace("Subscribed to topic: ");
    traceln(topic);
    mqttClient.subscribe(topic);

}   /* mqtt_subscribe() */

/*** end of file ***/
