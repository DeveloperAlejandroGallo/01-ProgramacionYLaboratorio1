#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad=0;
    char letra;
    float importe;

    printf("Hello world!\n");
    printf("Ingrese su edad:");
    scanf("%d",edad);
    printf("\nIngrese la primera letra de su apellido: ");
    scanf("%c",letra);
    printf("\nIngrese el importe a depositar: ");
    scanf("%f",importe);
    printf("\nUd tiene %d anios, su apellido comienza con %c y el importe a depositar es %.2f",edad,letra,importe);
    return 0;
}
