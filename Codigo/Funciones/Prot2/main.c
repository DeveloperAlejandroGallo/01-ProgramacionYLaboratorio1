#include <stdio.h>
#include <stdlib.h>

//Prototipo de Funciones
//No devuelve y recibe
void suma(int n1, int n2);

int main()
{
    int nro1, nro2;

    printf("Ingrese 2 nros:\n");
    printf("Nro 1: ");
    scanf("%d", &nro1);
    printf("\nNro 2: ");
    scanf("%d", &nro2);

    suma(nro1, nro2);

    return 0;
}


void suma(int n1, int n2)
{
    printf("La suma c funcion es: %d\n", n1 + n2);
}
