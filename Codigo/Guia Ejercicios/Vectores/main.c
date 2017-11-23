#include <stdio.h>
#include <stdlib.h>
#include "GalloAlejandro.h"
#define MAX 10

int main()
{
	int vector[MAX] = {88, 77, 34, 1232, 23, 44, 564, 75, 2 , 90};
	int i, j, maximo, minimo, flag, aux;

	//Buscar Max
	printf("El maximo nro es: %d\n\n",mayorDeVectorInt(vector, MAX));

	//Buscar Min
	printf("El minimo nro es: %d\n\n",menorDeVectorInt(vector, MAX));


    bubbleSortInt(vector, MAX);

	for(i=0;i<MAX;i++)
		printf("%d - %d\n",i,vector[i]);

    printf("\nFIN\n");
	system("pause");
    return 0;
}
