#include <stdio.h>
#include "libresistance.h"

int main(void)
{
  float test1[2]={1.0f,1.0f};
  float test2[3]={1.0f,1.0f,1.0f};
  float test3[3]={1.0f,1.0f,0.0f};
  float test4[3]={1.0f,1.0f,1.0f};
  
  // float calc_resistance (int count, char conn, float * array);
  printf("Parallel resistance with 2 1 ohm resistors\n %f\n", calc_resistance(2,'P', test1));
  printf("it should be 0.5\n");
  
printf("Series resistance with 3 1 ohm resistors\n %f\n", calc_resistance(3,'S', test2));
  printf("it should be 3\n");
  printf("Series resistance with 2 1 ohm and 1 0 ohm resistors\n %f\n", calc_resistance(3,'S', test3));
  printf("it should be 2\n");

printf("*Parallel resistance with 2 1 ohm and 1 0 ohm resistors\n %f\n", calc_resistance(3,'P', test3));
  printf("it should be -1.0 (ERROR)\n");

printf("Parallel resistance with 3 1 ohm resistors\n %f\n", calc_resistance(3,'P', test2));
  printf("it should be 0.3333\n");

printf("Parallel resistance with null pointer\n %f\n", calc_resistance(3,'P', NULL));
  printf("it should return -1 (ERROR)\n");
  
  return 0;
}
