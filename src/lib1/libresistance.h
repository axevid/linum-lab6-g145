/*
# Header file for libresistance
*/
#ifndef __LIBRESISTANCE_H__
#define __LIBRESISTANCE_H__

/* defines for parallel and serial command characters */
#define PARALLEL 'P'
#define SERIAL   'S'

/* prototype for calc_resistance */ 
float calc_resistance (int count, char conn, float * array);

#endif
