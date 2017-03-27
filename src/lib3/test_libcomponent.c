#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"

int main(int argc, const char* argv[])
{
	float* res_array = malloc(3 * sizeof(float));
	if (res_array == NULL) 
	{
  		printf("Memory allocation failed.\n");
  		return(-1);
	}	
	
	int count = e_resistance(1398.0, res_array);
	
	printf("Ersättningsresistanser i E12-serien kopplade i serie:\n");
	for (int i = 0; i < count; i += 1)
		printf("%.0f\n", res_array[i]);
	
	free(res_array);
	exit(0);
}
