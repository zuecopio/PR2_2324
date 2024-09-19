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

#define DEVICE_RETROPLAY_ID            "02" //"retroplay-device-02"


//-----[ WIFI ]---------------------------------------------//

#define NET_SSID                       "UPV-PSK"
#define NET_PASSWD                     "giirob-pr2-2023"


//-----[ MQTT ]---------------------------------------------//

#define MQTT_SERVER_IP                 "mqtt.dsic.upv.es"
#define MQTT_SERVER_PORT                1883
#define MQTT_USERNAME                  "giirob"
#define MQTT_PASSWORD                  "UPV2024"

#define LINE_STATUS_TOPIC              "nave/02/ensamblaje/estacion/01/linea/02/estado"
#define LINE_ENTRANCE_STATUS_TOPIC     "nave/02/ensamblaje/estacion/01/linea/02/entrada/estado"
#define EMERGENCY_BUTTON_STATUS_TOPIC  "nave/02/ensamblaje/estacion/01/linea/02/botonEmergencia/estado"


//-----[ LINE ENTRANCE PRESENCE SENSOR ]--------------------//

typedef enum 
{
    LIBRE,
    OCUPADA,
    EMERGENCIA
} line_status_t;

line_status_t   LINE_STATUS = OCUPADA;  // The US sensor only checks for the presence of new PCs if the line is free -> LINE_STATUS = LIBRE.

#define trigPin               13        // Define TrigPin.
#define echoPin               14        // Define EchoPin.
#define MAX_DISTANCE          700       // Maximum sensor distance is rated at 400-500 cm.

int   soundVelocity = 340;              // Define sound speed = 340 m/s.
float timeOut = MAX_DISTANCE * 60; 
float distance = 0.0;


//-----[ EMERGENCY BUTTON ]---------------------------------//

#define EMERGENCY_BUTTON  1

struct Button
{
    const uint8_t PIN;
    bool pressed;
};

Button emergency_button = {EMERGENCY_BUTTON, false};

void IRAM_ATTR isr(void)
{
  emergency_button.pressed = true;
}

/*** end of file ***/
