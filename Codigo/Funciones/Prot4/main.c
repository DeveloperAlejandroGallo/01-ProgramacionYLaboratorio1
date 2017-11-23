#include <stdio.h>
#include <stdlib.h>

//Prototipo de Funciones
//Devuelve No recibe
void suma();

//Variables Globales


int main()
{
   suma();

    return 0;
}


void suma()
{


    int Nro1, Nro2;

    printf("Ingrese 2 nros:\n");
    printf("Nro 1: ");
    scanf("%d", &Nro1);
    printf("\nNro 2: ");
    scanf("%d", &Nro2);
     printf("La suma c funcion es: %d\n", Nro1 + Nro2);
}


