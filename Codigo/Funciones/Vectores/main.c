#include <stdio.h>
#include <stdlib.h>
#include <GalloAlejandro.h>

#define SIZE 5
int main()
{

    int vector [SIZE];
    int vector2 [] = {1,2,3,4,5,6,7,8,9,0};
    int vector3 [SIZE] = {1};
    int i=0, indice, valor;

    //Inicializo vector
    printf("Vector1: ");
    for(i=0; i<SIZE;i++)
    {
        printf("%d, ",vector[i]);
    }

    printf("\n\nVector2: ");
    for(i=0; i<SIZE;i++)
    {
        printf("%d, ",vector2[i]);
    }

    printf("\n\Vector3: ");
    for(i=0; i<SIZE;i++)
    {
        printf("%d, ",vector3[i]);
    }
    return 0;
}
