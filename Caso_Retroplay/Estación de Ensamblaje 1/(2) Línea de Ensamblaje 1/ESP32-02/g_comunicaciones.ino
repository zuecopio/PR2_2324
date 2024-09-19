/**
 * @file     g_comunicaciones.ino
 *
 * @brief    Implementation of communication functions.
 *
 * @author   Marcos Belda Martinez'   <mbelmar@etsinf.upv.es>  (student)
 * @author   Angela Espert Cornejo'   <aespcor@etsinf.upv.es>  (student)
 * @author   Lourdes Frances Llimera' <lfralli@epsa.upv.es>    (student)
 * @author   Carla Hidalgo Aroca'     <chidaro@etsii.upv.es>   (student)
 *
 * @date     April, 2024
 * @section  PR2-GIIROB
 */

/******************************************************************************/
/*!
 * @brief  Topic subscription function.
 * @param  void
 * @return void
 */
void suscribirseATopics(void)
{
    mqtt_subscribe(LINE_STATUS_TOPIC);
    
}   /* suscribirseATopics() */

/******************************************************************************/
/*!
 * @brief  Function to manage messages received by different topics.
 * @param  topic            (char *)
 * @param  incomingMessage  (String)
 * @return void
 */
void alRecibirMensajePorTopic(char * topic, String incomingMessage)
{  
    // Create a JSON document.
    JsonDocument doc;
    // Parse the JSON input.
    DeserializationError err = deserializeJson(doc, incomingMessage);
    // Parsing succeeded?
    if (err)
    {
        warn(F("deserializeJson() returned ")); warnln(err.f_str());
        return;
    }

    String estado = doc["estado"];
    info("(JSON) Message received: "); infoln(estado);

    // If a message is received on the topic ...
    if (strcmp(topic, LINE_STATUS_TOPIC) == 0)
    {
        if (estado == "libre")
        {
            LINE_STATUS = LIBRE;
        }
    }

    // If a message is received on the topic ...
    if (strcmp(topic, LINE_STATUS_TOPIC) == 0)
    {
        if (estado == "ocupada")
        {
            LINE_STATUS = OCUPADA;
        }
    }

    // If a message is received on the topic ...
    if (strcmp(topic, LINE_STATUS_TOPIC) == 0)
    {
        if (estado == "emergencia")
        {
            LINE_STATUS = EMERGENCIA;
        }
    }
    
}   /* alRecibirMensajePorTopic() */

/******************************************************************************/
/*!
 * @brief  Function to send a message by a topic.
 * @param  topic            (const char *)
 * @param  outgoingMessage  (String)
 * @return void
 */
void enviarMensajePorTopic(const char * topic, String outgoingMessage)
{
    mqtt_publish(topic, outgoingMessage.c_str());

}   /* enviarMensajePorTopic() */

/*** end of file ***/
