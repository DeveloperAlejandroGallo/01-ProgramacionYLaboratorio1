#include <stdio.h>
#include <stdlib.h>

int esPrimo(int nro);

int main()
{
    int i;
    printf("Somos Primos: ");
    for(i=2;i<=100;i++)
    {
        if(esPrimo(i)==1)
            printf(" %d",i);
    }

    return 0;
}

int esPrimo(int nro)
{
    int i, si=1;
    for(i=nro-1;i!=1;i--)
    {
        if(nro % i == 0)
        {
            si = 0;
            break;
        }
    }

    return si;
}
