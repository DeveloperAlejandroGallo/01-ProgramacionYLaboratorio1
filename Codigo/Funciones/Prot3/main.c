#include <stdio.h>
#include <stdlib.h>

//Prototipo de Funciones
//Devuelve No recibe
int suma();

//Variables Globales
int Nro1, Nro2;

int main()
{


    printf("Ingrese 2 nros:\n");
    printf("Nro 1: ");
    scanf("%d", &Nro1);
    printf("\nNro 2: ");
    scanf("%d", &Nro2);

    printf("La suma c funcion es: %d\n",suma());

    return 0;
}


int suma()
{
    return Nro1 + Nro2;
}
