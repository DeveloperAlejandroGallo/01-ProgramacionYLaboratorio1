/*
3.	Escribir  un programa que realice las siguientes acciones
•	Limpie la pantalla
•	Asigne a 2 variables numero1 y numero2 valores distintos de cero
•	Efectúe el producto de dichas variables
•	Muestre el resultado pos pantalla
•	Obtenga el cuadrado de numero1 y lo muestre par pantalla

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro1, nro2;

    printf("Hello world!\n");
    system("cls");

    printf("Ingrese el 1er Nro: ",nro1);
    scanf("%d",&nro1);

    while(nro1 == 0)
    {
        printf("Ingrese el 1er Nro: ",nro1);
        scanf("%d",&nro1);
    }

    printf("Ingrese el 2do Nro: ",nro2);
    scanf("%d",&nro2);

    while(nro2 == 0)
    {
        printf("Ingrese el 2do Nro: ",nro1);
        scanf("%d",&nro1);
    }


    printf("El producto de los Nros es: %d \nY el cuadrado del primer nro es: %d",nro1*nro2,nro1*nro1);

    return 0;
}
