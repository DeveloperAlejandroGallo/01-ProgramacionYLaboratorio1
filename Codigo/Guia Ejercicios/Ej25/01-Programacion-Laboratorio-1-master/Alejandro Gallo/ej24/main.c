#include <stdio.h>
#include <stdlib.h>
/*Diseñar en un programa que permita registrar de los empleados de una fábrica (no se sabe cuántos) su peso
y saber cuántos pesan hasta 80 kg. inclusive y cuantos pesan más de 80 kg.*/

int main()
{
    int
    menos80=0,
    mas80=0,
    peso;

    printf("Ingrese un Peso, o 0(cero) para finalizar: ");
    scanf("%d",&peso);

    while(peso!=0)
    {
        system("cls");
        if(peso>80)
            mas80++;
        else
            menos80++;
        printf("Ingrese un Peso, o 0(cero) para finalizar: ");
        scanf("%d",&peso);
    }

    printf("Pesan menos de 80: %d\n",menos80);
    printf("Pesan mas de 80: %d\n",mas80);

    return 0;
}
