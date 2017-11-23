/*
Escribir el programa necesario para calcular la suma de dos números.
Mostrar el resultado
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    float nro=0;
    for(i=0;i<5;i++)
    {
        printf("Ingrese el %d Nro:",i);
        scanf("%f",&nro);
        nro += nro;
    }
    printf("La suma de los nros es: %f",nro);

    return 0;
}
