/*
#file for resistance calc
# Description:
# Library 1, libresistance.so
#
# Write a library, libresistance.so, with functions to calculate the 
# total resistance for different coupled resistances. The resistances to 
# be connected in parallel or in series. You do not count on mixed couplings.
#
# float calc_resistance (int count, char conn, float *array);
#
# Where:
#    count: Number of components.
#    conn: serial or parallel connected komponeter [P | S].
#    * Array: A pointer to an array of component values ​​is equal to count.
#    A value of 0 will be returned if resistance is zero when operating 
#    in parallel, ie R1 || R2 = 0 if R1 or R2 is 0Ohm.
#
#    The library will not crash if a null pointer is sent to the function, 
#    ie if the array = 0.
#     If the arguments are incorrect, the function will return -1.
#
# The return value is the resulting resistance.
#
*/
#define PARALLEL 'P'
#define SERIAL   'S'

#include <stdio.h>
#include "libresistance.h"
float calc_resistance (int count, char conn, float *array) {
  float tmp = 0.0f;
  float equivalent_resistance = 0.0f;
  int i = 0;
  
  if (array == NULL)
    {
      return(-1); /* handle null pointer */
    }
  else
    if (count==0) return(-1); /* Error condition */
    else  
      {
	// Proceed
	switch(conn) {
	case PARALLEL: /* parallel resistance */
	  /* Code */

	  if (count==1 && array[0]!=0 ) return(array[0]);
	  if (count==1 && array[0]==0 ) return(-1);
	  
	  for(i=0;i<count;i++) if (array[i] == 0) return(-1); /* check for null pointer */
	  tmp=0;
	  for (i=0;i<count;i++) tmp=tmp+1/array[i];
	  equivalent_resistance = 1/tmp;
	  break;
	  
	case SERIAL: /* series resistance */
	  /* Code */
	  
	  if (count==1) return(array[0]);
	 
	  equivalent_resistance = 0;
	  
	  for (i = 0; i < count; i++) {
	    equivalent_resistance = equivalent_resistance + array[i];
	  }
	  
	  break;
	default:
	  
	  return(-1);
	  
	  break;
	}
	
      }  
  
  return(equivalent_resistance);  
}

