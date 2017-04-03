#include <stdio.h>
#include "libresistance.h"

int main(void)
{
  float test1[2]={1.0f,1.0f};
  float test2[3]={1.0f,1.0f,1.0f};
  float test3[3]={1.0f,1.0f,0.0f};
  float test4[3]={2.0f,4.0f,6.0f};
  float test5[3]={5.0f};
  
  // float calc_resistance (int count, char conn, float * array)
    printf("Parallel resistance with 0 1 ohm resistors with array of 3 1 ohm resistors \n %f\n", calc_resistance(0,'P', test1));
  printf("it should return 0  because array is not a null pointer\n");

    printf("Parallel resistance with 0 resistors with null pointer as array \n %f\n", calc_resistance(0,'P', NULL));
  printf("it should return -1 (ERROR)  because array is a null pointer\n");


printf("Parallel resistance with 2 1 ohm resistors\n %f\n", calc_resistance(2,'P', test1));
  printf("it should be 0.5\n");
  
printf("Series resistance with 3 1 ohm resistors\n %f\n", calc_resistance(3,'S', test2));
  printf("it should be 3\n");
  printf("Series resistance with 2 1 ohm and 1 0 ohm resistors\n %f\n", calc_resistance(3,'S', test3));
  printf("it should be 2\n");
  printf("*Parallel resistance with 1 0 ohm resistors\n %f\n", calc_resistance(1,'P', 0));
  printf("it should be -1 (ERROR)\n");
  printf("Series resistance with 1 5 ohm resistor\n %f\n", calc_resistance(1,'S', test5));
  printf("it should be 5\n");

printf("Series resistance with 1 5 ohm resistors and count of 2\n %f\n", 
calc_resistance(2,'S',test5));
  printf("it should always return -1 (ERROR) but it does not\n");

printf("Series resistance with 1 5 ohm resistors and count of -1\n %f\n", 
calc_resistance(2,'S',test5));
  printf("it should always return -1 (ERROR) but it does not\n");

printf("*Parallel resistance with 2 1 ohm and 1 0 ohm resistors\n %f\n", calc_resistance(3,'P', test3));
  printf("it should be -1.0 (ERROR)\n");

printf("Parallel resistance with 3 1 ohm resistors\n %f\n", calc_resistance(3,'P', test2));
  printf("it should be 0.3333\n");

printf("Parallel resistance with 1 5 ohm resistors\n %f\n", 
calc_resistance(1,'P',test5));
  printf("it should be 5\n");

printf("Parallel resistance with 1 5 ohm resistors and count of 2\n %f\n", 
calc_resistance(2,'P',test5));
  printf("it should always return -1 (ERROR), but it does not.\n");

printf("**Parallel resistance with 2 ohm resistor 4 ohm resistor and 6 ohm resistor \n %f\n", 
calc_resistance(3,'P',test4));
  printf("it should return 1.0909\n");


printf("Parallel resistance with null pointer\n %f\n", calc_resistance(3,'P', NULL));
  printf("it should return -1 (ERROR)\n");
  
  return 0;
}
