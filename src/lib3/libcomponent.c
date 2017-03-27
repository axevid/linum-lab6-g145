#include <stdio.h>
#include <stdlib.h>
#include "libcomponent.h"

int e_resistance(float orig_resistance, float *res_array)
{
	/* Build Array of sorted E12 values.*/
	int e12Array[62];
	e12Array[0] = 0;
	e12Array[1] = 10;
	e12Array[2] = 12;
	e12Array[3] = 15;
	e12Array[4] = 18;
	e12Array[5] = 22;
	e12Array[6] = 27;
	e12Array[7] = 33;
	e12Array[8] = 39;
	e12Array[9] = 47;
	e12Array[10] = 56;
	e12Array[11] = 68;
	e12Array[12] = 82;
	
	for (int i = 13; i < 62; i +=1)
		e12Array[i] = e12Array[i-12] * 10;

 	/* Print e12Array - only for debugging. 
	for (int i = 0; i < 62; i +=1)
		printf("E12-%-2d: %d\n", i + 1, e12Array[i]);
	*/

	/* Reset res_array to zeros. */	
	for (int i = 0; i < 3; i += 1)
		res_array[i] = 0;
		
	int minDiff = orig_resistance;
	int maxIndex = 61;
	int count = 0;

	/* Reduce maxIndex to reduce iterations in nested for-loops. */
	for (int i = 0; e12Array[i] < orig_resistance && maxIndex < 61; i += 1)
		maxIndex += 1;

	/* Algorithm for finding optimal choice of E12-resistors. */
	for (int i = 0; i <= maxIndex; i++)
	{
		for (int j = i; j <= maxIndex; j++)
		{
			for (int k = j; k <= maxIndex; k++)
			{ 	
				int diff = abs(orig_resistance - e12Array[i] - e12Array[j] - e12Array[k]);
				if (diff < minDiff)
				{
					res_array[0] = e12Array[k];		
					res_array[1] = e12Array[j];		
					res_array[2] = e12Array[i];		
					count = (i != 0) + (k != 0) + (j != 0);
					minDiff = diff;
					if (minDiff == 0)
						return count;					
				}
			}
		}
	}
	return count;	
}
