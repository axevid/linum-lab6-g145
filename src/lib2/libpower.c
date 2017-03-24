// # file for power calc

#include <libpower.h>
#include <math.h>

float calc_power_r(float volt, float resistance) {
	float p
	p = powf(volt, 2.)/resistance
	return p

}

float calc_power_i(float volt, float current){
	float p;
	p = volt * current;
	return p
}