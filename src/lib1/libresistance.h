/**
 * @file   libresistance.h
 * @author Jouni Metso <antero.metso@gmail.com>
 * @version 1.0
 * @brief  Function prototype for calc_resistance function.
 * @see See libresistance.c for better description of the function.
*/
#ifndef __LIBRESISTANCE_H__
#define __LIBRESISTANCE_H__

/**  @brief Calculates the equivalent resistance for a simple resistor network.
 *
 *   Write a library, libresistance.so, with functions to calculate the 
 *   total resistance for different coupled resistances. The resistances to 
 *   be connected in parallel or in series. You do not count on mixed couplings.
 *
 *   A value of 0 will be returned if resistance is zero when operating 
 *   in parallel, ie R1 || R2 = 0 if R1 or R2 is 0Ohm.
 *
 *   The library will not crash if a null pointer is sent to the function, 
 *   ie if the array = 0.
 *   If the arguments are incorrect, the function will return -1.
 *
 *   The return value is the resulting resistance. 
 *
 */
float calc_resistance (int count, char conn, float * array);

#endif
