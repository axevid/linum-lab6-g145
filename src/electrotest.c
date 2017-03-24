/*
# file for mainprog
# Electrotest.c - main file for Ex.6 
# Created 20170322 by A.M. 
*/

/*Ange spänningskälla i V: 50
Ange koppling[S | P]: S
Antal komponenter: 3
Komponent 1 i ohm: 300
Komponent 2 i ohm: 500
Komponent 3 i ohm: 598
Ersättningsresistans:
1398,0 ohm
Effekt:
1.78 W
Ersättningsresistanser i E12-serien kopplade i serie:
1200
180
18
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

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

  printf("Ersättningsresistans: \n");

} // end of int main(void)
