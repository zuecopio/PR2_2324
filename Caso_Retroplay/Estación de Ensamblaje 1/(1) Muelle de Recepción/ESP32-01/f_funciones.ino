/**
 * @file     f_funciones.ino
 *
 * @brief    Implementation of functions to change the state of device outputs.
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
 * @brief  Function to know the distance detected by the US.
 * @param  void
 * @return float
 */
float getUsDistance(void)
{
    unsigned long pingTime;
    float distance;
    
    // Make trigPin output high level lasting for 10μs to triger HC_SR04.
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Wait HC-SR04 returning to the high level and measure out this waitting time.
    pingTime = pulseIn(echoPin, HIGH, timeOut); 
    
    // Calculate the distance according to the time.
    distance = (float)pingTime * soundVelocity / 2 / 10000;
    
    // Return the distance value.
    return distance;
    
}   /* getUsDistance() */

/*** end of file ***/
