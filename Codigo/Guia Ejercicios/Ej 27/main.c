/*
Ingresar por teclado 3 números correspondientes a los lados de un triángulo.
Teniendo en cuenta que la suma de los dos lados menores tiene que ser
superior al lado mayor para que formen un triángulo, indicar si los números
indicados forman un triángulo y si lo forman que tipo de triángulo es
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int lado1, lado2, lado3, mayor, posicion, sumaMenores;


    printf("Ingrese los 3 lados del triangulo:\n");
    printf("Lado 1: ");
    scanf("%d",&lado1);
    mayor = lado1;
    posicion = 1;
    printf("Lado 2: ");
    scanf("%d",&lado2);
    if(lado2 > mayor)
    {
        mayor = lado2;
        posicion = 2;
    }
    printf("Lado 3: ");
    scanf("%d",&lado3);
    if(lado3 > mayor)
    {
        mayor = lado3;
        posicion = 3;

    }
    switch(posicion)
    {
    case 1:
        sumaMenores = lado2 + lado3;
        break;
    case 2:
        sumaMenores = lado1 + lado3;
        break;
    case 3:
        sumaMenores = lado1 + lado2;
        break;

    }

    if(sumaMenores <= mayor)
    {
        printf("No es triangulo");
    }
    else
    {
        if(lado1 == lado2 )
            if(lado2 == lado3)
             printf("Equilatero");
            else
             printf("isoseles");
        else
            if (lado1 == lado3)
                if(lado3 == lado2)
                 printf("Equilatero");
                else
                 printf("isoseles");
            else
                if(lado2 == lado3)
                    if(lado3 == lado1)
                     printf("Equilatero");
                    else
                     printf("isoseles");
                else
                    printf("Escaleno");
    }



    return 0;
}
