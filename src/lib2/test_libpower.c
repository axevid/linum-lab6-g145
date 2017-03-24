#include <stdio.h>

#include "libpower.h"

int main(void)
{

	printf("Effekten när spänningen är 50 V och resistansen är 300 ohm är %i\n", calc_power_r(50., float 300));
	printf("Den borde vara 8.3")

	printf("Effekten när spänningen är 50 V och strömmen är 0.2 A är %i\n", float calc_power_i(50, 0.2));
	printf("Den borde vara 10")
	return 0;
}
