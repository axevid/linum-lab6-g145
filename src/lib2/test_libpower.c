#include <stdio.h>
#include "libpower.h"

int main(void)
{

	printf("Effekten när spänningen är 50 V och resistansen är 300 ohm är %f\n", calc_power_r(50., 300.));
	printf("Den borde vara 8.3\n");

	printf("Effekten när spänningen är 50 V och strömmen är 0.2 A är %f\n", calc_power_i(50., 0.2));
	printf("Den borde vara 10\n");
	return 0;
}
