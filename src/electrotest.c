/*
# file for mainprog
# Electrotest.c - main file for Ex.6 
# Created 20170322 by A.M. 
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "./lib1/libresistance.h" // quick&dirty, use includepath instead.
int returnValue;
float spanningskalla;
char koppling;
int antalKomponenter;
float *ohms;  
int i;
float j;

int main(void) 
{
    printf("Ange spänningskälla i V: ");
  returnValue=scanf("%f",&spanningskalla);
  if (returnValue !=1) return (EXIT_FAILURE);
  
  printf("Ange koppling[S | P]: ");
  returnValue=scanf(" %1c",&koppling);
  if (returnValue !=1|| (koppling!='S' && koppling!='P' && koppling !='s' && koppling !='p') ) return (EXIT_FAILURE);
  
  printf("Antal komponenter: ");
  returnValue=scanf("%d",&antalKomponenter);
  if (returnValue !=1 || antalKomponenter < 0) return (EXIT_FAILURE);

  ohms = malloc(sizeof(float)*antalKomponenter); // malloc failure test skipped
  for(i=0; i< antalKomponenter;i++)
    {
      printf("Komponent %d i ohm: ",i+1);
      returnValue=scanf("%f",&j);
      if (returnValue !=1|| j<0) return (EXIT_FAILURE);
      ohms[i]=j;
    } // end of for i
 
  printf("Ersättningsresistans: %f\n",
	 calc_resistance(antalKomponenter,koppling, ohms));

  printf("Effekt: %f\n",-1.0f);
  printf("Ersättningsresistanser i E12-serien kopplade i serie: \n");
  return (0);
} // end of int main(void)
