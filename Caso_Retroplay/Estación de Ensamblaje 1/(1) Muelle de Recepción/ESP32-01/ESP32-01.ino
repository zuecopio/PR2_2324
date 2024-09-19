/**
 * @file     ESP32-01.ino
 *
 * @brief    Plantilla Dispositivo IoT.
 * 
 * @version  0.6   (2024/02/21) JSON Management
 * @version  0.5.1 (2024/02/20) SSL fork
 * @version  0.5   (2024/02/19) Mejora en comunicaciones y reconexiones
 * @version  0.4   (2024/02/15) Reestructuración y simplificación
 * @version  0.3   (2024/02/14) Añadido funciones de log
 * @version  0.2   (2023/12/28) Dividido en sub-ficheros
 * @version  0.1   (2023/11/29) Prototipo Inicial Funcional
 *
 * @author   Joan Fons' <jjfons@dsic.upv.es> (teacher)
 * 
 * @date     April, 2024
 * @section  PR2-GIIROB
 */

#include "Config.h"

#include <WiFi.h>
#ifdef SSL_ROOT_CA
#include <WiFiClientSecure.h>
#endif
#include <PubSubClient.h>
#include <ArduinoJson.h>

// ID de Dispositivo : se proporciona el ID asignado en la planta de Retroplay.
String deviceID = String("retroplay-device-") + String(DEVICE_RETROPLAY_ID);        

/******************************************************************************/
/*!
 * @brief  Arduino setup function.
 * @param  void
 * @return void
 */
void setup(void)
{
    // Este setup configura conceptos 'core', inicializa la wifi y la conexión con 
    // el bróker MQTT, y ejecuta algunos métodos que hay que completar. 
    // En concreto los alumnos deberán implementar los métodos:
    //  - suscribirseATopics()  -> topics MQTT a suscribir para recibir mensajes 
    //                            (g_comunicaciones.ino)
    //  - on_setup()            -> añadir la configuración de pines, inicialización
    //                            de variables, etc. (s_setup.ino)
    //  - on_loop()             -> tareas a realizar dentro del 'loop' (w_loop.ino)

    #ifdef LOGGER_ENABLED
    // Inicializamos comunicaciones serial
    Serial.begin(BAUDS);
    delay(1000);
    Serial.println();
    #endif

    // Nos conectamos a la wifi
    wifi_connect();

    // Nos conectamos al broker MQTT, indicando un 'client-id'
    mqtt_connect(deviceID);

    // TODO: completar esta función (g_comunicaciones.ino)
    suscribirseATopics();

    // TODO: completar esta función (s_setup.ino)
    on_setup();

}   /* setup() */

/******************************************************************************/
/*!
 * @brief  Arduino loop function.
 * @param  void
 * @return void
 */
void loop(void)
{
    // NO QUITAR (jjfons)
    wifi_loop();
    mqtt_loop();

    // TODO: completar esta función (w_loop.ino)
    on_loop();

}   /* loop() */

/*** end of file ***/
