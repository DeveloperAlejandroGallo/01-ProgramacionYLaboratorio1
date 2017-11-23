#include <stdio.h>
#include <stdlib.h>
#include "miLibreria.h"

//Prototipo de Funciones
//Devuelve y Recibe
int suma(int n1, int n2);

int main()
{
    int nro1, nro2;

    printf("Ingrese 2 nros:\n");
    printf("Nro 1: ");
    scanf("%d", &nro1);
    printf("\nNro 2: ");
    scanf("%d", &nro2);

    printf("La suma directa es: %d\n", nro1 + nro2);

    printf("La suma c funcion es: %d\n", suma(nro1, nro2));



    return 0;
}

