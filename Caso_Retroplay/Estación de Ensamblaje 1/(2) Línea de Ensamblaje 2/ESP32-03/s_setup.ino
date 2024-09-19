/**
 * @file     s_setup.ino
 *
 * @brief    Implementation of setup function.
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
 * @brief  Students setup function.
 * @param  void
 * @return void
 */
void on_setup(void)
{
    // LINE ENTRANCE PRESENCE SENSOR
    //
    // Set trigPin to output mode.
    pinMode(trigPin, OUTPUT);
    // Set echoPin to input mode.
    pinMode(echoPin, INPUT);  

    // EMERGENCY BUTTON
    //
    // Set EMERGENCY_BUTTON to input_pullup mode.
    pinMode(emergency_button.PIN, INPUT_PULLUP);
    // Create interrupt handler.
    attachInterrupt(emergency_button.PIN, isr, FALLING);

}   /* on_setup() */

/*** end of file ***/
