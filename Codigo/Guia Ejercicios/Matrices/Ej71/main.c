#include <stdio.h>
#include <stdlib.h>
#include "GalloAlejandro.h"

#define LINEAS 3
#define COCHES 12

int main()
{
	float matriz[LINEAS][COCHES]={{12.1,3,55,67,88.4,66,87,0,1,123,23.55,12},
                                                {11.77,35,5,63,84.4,66.77,83,0.45,1,13,2.55,12.5},
                                                {2.1,3.3,5.65,67.44,0.4,6.6,87.99,0,1,123,23.55,12}
                                               };
	int i,j;
    float acum;

	for(i=0;i<LINEAS;i++)
	{
	    acum =0 ;
	    for(j=0;j<COCHES;j++)
		{
			acum += matriz[i][j];
		}
		printf("Total Linea %d: %.2f\n",i+1,acum);

	}

	return 0;
}



