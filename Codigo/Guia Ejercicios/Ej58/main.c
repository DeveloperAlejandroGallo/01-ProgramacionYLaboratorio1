#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vector[10];
    int i;

    for(i=0;i<10;i++)
    {
        vector[i] = 10 - i;
    }

    for(i=0;i<10;i++)
    {
        printf("Posicion (%d) = %d\n",i,vector[i] );
    }

    return 0;
}
