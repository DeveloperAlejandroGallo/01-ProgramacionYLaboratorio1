#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nro;

    printf("Ingrese in nro!\n");
    scanf("%d",&nro);
    printf("\nEl factorial del nro es: %d ",factorial(nro));
    return 0;
}



int factorial(int nro)
{
    if(nro==0)
        return 1;
    else
        return nro * factorial(nro-1);
}
