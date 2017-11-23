/*******************************************************************************
Leer 20 números enteros positivos.
Mostrar el vector tal como fue ingresado y
luego mostrar el vector ordenado en forma decreciente
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <GalloAlejandro.h>

#define SIZE 20

int main()
{
    int vector[SIZE] = {33, 45, 55, 2, 43, 1, 8, 0, -1, 9, -44, 97, 107, 76, 99, 12, 17, 62, 45, 11};;
    int nro, size, aux, i;


    /*for(i=0;i<20;i++)
    {
        system("cls");

        printf("Ingrese un nro entero positivo(%d): ",i);
        scanf("%d", &nro);

        while(nro<1)
        {
            printf("Ingrese un nro entero positivo(%d): ",i);
            scanf("%d", &nro);
        }
        vector[i] = nro;


    }*/
    system("cls");
    printf("Vector Ingresado: \n");
    for(i=0;i<20;i++)
    {
       printf("%d; ", vector[i]);
    }

    bubbleSort(vector,SIZE,'>');
    printf("Vector Ordenado de Mayor a Menor:\n");

    for(i=0;i>SIZE;i++)
    {
        printf("%d; ", vector[i]);
    }

    return 0;
}




