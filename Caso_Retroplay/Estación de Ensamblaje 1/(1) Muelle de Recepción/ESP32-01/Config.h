/**
 * @file     Config.h
 *
 * @brief    Where the necessary definitions are created.
 *
 * @author   Marcos Belda Martinez'   <mbelmar@etsinf.upv.es>  (student)
 * @author   Angela Espert Cornejo'   <aespcor@etsinf.upv.es>  (student)
 * @author   Lourdes Frances Llimera' <lfralli@epsa.upv.es>    (student)
 * @author   Carla Hidalgo Aroca'     <chidaro@etsii.upv.es>   (student)
 *
 * @date     April, 2024
 * @section  PR2-GIIROB
 */

//-----[ COMM BAUDS ]---------------------------------------//

#define BAUDS 115200

#define LOGGER_ENABLED                 // Comentar para deshabilitar el logger por consola serie.

#define LOG_LEVEL TRACE                // Niveles en c_logger: TRACE, DEBUG, INFO, WARN, ERROR, FATAL, NONE.


//-----[ DEVIDE ]-------------------------------------------//

#define DEVICE_RETROPLAY_ID            "01" //"retroplay-device-01"


//-----[ WIFI ]---------------------------------------------//

#define NET_SSID                       "UPV-PSK"
#define NET_PASSWD                     "giirob-pr2-2023"


//-----[ MQTT ]---------------------------------------------//

#define MQTT_SERVER_IP                 "mqtt.dsic.upv.es"
#define MQTT_SERVER_PORT                1883
#define MQTT_USERNAME                  "giirob"
#define MQTT_PASSWORD                  "UPV2024"

#define MQTT_TOPIC_RECEPCION_STATUS    "nave/02/ensamblaje/estacion/01/muelle_recepcion/estado"


//-----[ RECEIVING DOCK PRESENCE SENSOR ]-------------------//

#define trigPin               13        // Define TrigPin.
#define echoPin               14        // Define EchoPin.
#define MAX_DISTANCE          700       // Maximum sensor distance is rated at 400-500 cm.

int   soundVelocity = 340;              // Define sound speed = 340 m/s.
float timeOut = MAX_DISTANCE * 60; 
float distance = 0.0;

/*** end of file ***/
