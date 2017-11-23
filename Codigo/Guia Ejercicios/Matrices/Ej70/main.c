#include <stdio.h>
#include <stdlib.h>
#include "GalloAlejandro.h"

#define FILAS 6
#define COLS 5

int main()
{
	int matriz[FILAS][COLS]={0};
	int i,j;

	for(i=0;i<FILAS;i++)
	{
		for(j=0;j<COLS;j++)
		{
		    //matriz[i][j] = 0;
			printf("Posicion [%d,%d]: %d\n",i,j,matriz[i][j]);
		}
	}



	return 0;
}



