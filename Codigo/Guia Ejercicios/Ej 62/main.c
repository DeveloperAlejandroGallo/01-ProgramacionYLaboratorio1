#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GalloAlejandro.h"

#define MAX 100

int main()
{
    int r, i;
    int vecA[MAX],
         vecB[MAX],
         vecC[MAX];

    srand(time(NULL));
    printf("vecA - vecB - vecC\n");

    for(i=0;i<MAX; i++)
    {
        vecA[i] = (rand() % 100 ) + 1;
        vecB[i] = (rand() % 100 ) + 1;
        if(vecA[i]<vecB[i])
            vecC[i]= vecA[i];
        else
            vecC[i] = vecB[i];

        printf("%d   - %d   - %d  \n",vecA[i],vecB[i], vecC[i]);

    }

    return 0;
}
