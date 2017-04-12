/** 
 * @file libresistance.c
 * @author Jouni Metso 
 * @date 04/12/2017
 * @brief C-source for calc_resistance function.
 *
 *
 */


#define PARALLEL 'P'
#define SERIAL   'S'

#include <stdio.h>
#include "libresistance.h"
/**
 * @brief Library for calculating the resistance for simple resistor networks.
 *
 * Write a library, libresistance.so, with functions to calculate the 
 * total resistance for different coupled resistances. The resistances to 
 * be connected in parallel or in series. You do not count on mixed couplings.
 */
/*! @fn float calc_resistance (int count, char conn, float *array)
 *  @brief Calculates the equivalent resistance for a simple resiston network.
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
 *  @param count Number of components.
 *  @param conn  Serial or parallel connected komponets [P | S].
 *  @param *array A pointer to an array of component values ​​of size of count.
 *  @return Equivalent resistance of the resistor network. 
 *
 */ 

float calc_resistance (int count, char conn, float *array) {
  float tmp = 0.0f;
  float equivalent_resistance = 0.0f;
  int i = 0;
  
  if (array == NULL)
    {
      return(-1); /// Return -1 in case the array argument is a null pointer.
    }
  else
    if (count==0) return(-1); /// Return -1 if count parameter is zero.
    else  
      {
	// Proceed
	switch(conn) {
	case PARALLEL: /// If paraller resistance is selected:
	  /* Code */

	  if (count==1 && array[0]!=0 ) return(array[0]); ///  If there is only one resistor, its value is the equivalent resistance.
	  if (count==1 && array[0]==0 ) return(-1); /// If the only resistor in the network has zero resistance, return -1.
	  
	  for(i=0;i<count;i++) if (array[i] == 0) return(-1); /// If any of the resistors has a zero resistance, return -1.
	  /** Calculate parallel resistance */
	  tmp=0;
	  for (i=0;i<count;i++) tmp=tmp+1/array[i];
	  equivalent_resistance = 1/tmp;
	  break;
	  
	case SERIAL: /// If serial resistance is selected:
	  /* Code */
	  
	  if (count==1) return(array[0]); /// If there is only one resistor, its value is the equivalent resistance.
	 
	  /// Otherwise, the equivalent resistance is calculated as the sum of resistances.
	  equivalent_resistance = 0;
	  
	  for (i = 0; i < count; i++) {
	    equivalent_resistance = equivalent_resistance + array[i];
	  }
	  
	  break;
	default:
	  
	  return(-1); /// If the type of the resistor network is unknown, return -1.
	  
	  break;
	}
	
      }  
  
  return(equivalent_resistance);  /// In the end, the code returns equivalent resistance 
}

