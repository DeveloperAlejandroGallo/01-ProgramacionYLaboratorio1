#include <stdio.h>
#include <stdlib.h>

int main()
{

    int* x, aux, p;
    int i;
    //El puntero a void se puede convertir en cualquier tipo de puntero casteandolo.

    //La funcion malloc recibe una cantidad en bytes. Que es la cantidad de memoria que necesito.
    p=(int*)malloc(sizeof(int)); //Casteo el puntero a puntero a entero con una cantidad de memoria reservada igual a int.

    //Vector de 5 enteros.
    x=(int*)malloc(sizeof(int) * 5);

    if(x==NULL)
    {
        printf("No se puede reservar memoria!!!!");
        exit(1);
    }

    //Lleno el array
    for(i=0;i<5;i++)
    {
        scanf("%d", (x + i));
    }

    //Muestro el array
    for(i=0;i<5;i++)
    {
        printf("%d",*(x + i));
    }

    //Agrando el vector a 10. tengo que ponerle el tamaño nvo total.
    //Si no alcanza la memoria para poner todos los bytes juntos devuelve NULL.
    //Siempre usar un auxiliar para ralocar mem, ya que podemos perder ella ref.

    aux = (int*)realloc(x, sizeof(int)*10);
    if(aux != NULL)
        x=aux;
    printf("\nPRIMERO\n");
    for(i=i;i<10;i++)
    {
        scanf("%d\n", (x + i));
    }

    for(i=0;i<10;i++)
    {
        printf("%d\n",*(x + i));
    }

    //calloc inicializa en cero un vector de nros.
    //Primer param es la cantidad total

    calloc(10,sizeof(int));
    //Al final de cada programa hacer free.
    for(i=0;i<10;i++)
    {
        printf("%d\n",*(x + i));
    }
    free(x);
}
