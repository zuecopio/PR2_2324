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
