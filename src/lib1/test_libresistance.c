#include <stdio.h>
#include "libresistance.h"

int main(void)
{
  float test1[2]={1.0f,1.0f};
  
  // float calc_resistance (int count, char conn, float * array);
  printf("Parallel resistance with 2 1 ohm resistors\n %f\n", calc_resistance(2,'P', test1));
  printf("it should be 0.5\n");
  printf("Series resistance with 2 1 ohm resistors\n %f\n", calc_resistance(2,'S', test1));
  printf("it should be 2\n");
  
  return 0;
}
