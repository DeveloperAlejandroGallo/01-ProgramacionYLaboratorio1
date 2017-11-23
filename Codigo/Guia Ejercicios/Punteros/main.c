#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Variable:
    Direccion de Memoria: Se obtiene con el &
    Direccion de fantasia
    Valor la variable

    Cualquier variable que guarda una direccion de memoria, se llama puntero o referencia (en objetos).
    */

    //Tengo que declarar punteros por tipos de variable a la q voy a apuntar.

    //Declaracion de un puntero:

    int x = 5;
    int* p;

    p = &x; //Le paso la direccion de mem de x

    //Para obtener o escribir en la dir de memoria del puntero uso el Operador de Indireccion *

    *p = 22; // Al valor apuntado por p le asigno 10
    change(p);
    printf("Valor de x: %d\n", x);
    printf("Valor al que apunta *p: %d\n", *p); //El valor al que apunta p
    printf("Direccion de memoria de p: %x\n", p); //La dir de memoria
    printf("Direccion de memoria de &x: %x\n", &x); //La dir de memoria

    /********************************************************/
    //Aritmetica de puntero
    // Cuando hago un puntero mas 1,
    int vec[5], i;
    //Escribo en la posicion 1 del vector
    //*(vec + 1)  = 14;
    //printf("valor del vector %d",*(vec + 1));

    for(i=0;i<5;i++)
    {
       printf("nro: ");
        scanf("%d",vec + i );
    }

    for(i=0;i<5;i++)
        printf(" %d",*(vec + i));

    return 0;
}

void change(int* p)
{
    *p = 10;
}
