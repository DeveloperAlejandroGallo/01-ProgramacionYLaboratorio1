#include <stdio.h>
#include <stdlib.h>

void mostrarMatriz(int k, int matrix[][k]);

int main()
{

    int matriz[3][4];
    int i,j;

    for(i=0; i<3;i++)
    {
        for(j=0; j<4;j++)
        {
            matriz[i][j] = 0;
        }
    }

    for(i=0; i<3;i++)
    {
        matriz[i][2] = 1;
    }
    mostrarMatriz(4, matriz);



    return 0;
}


void mostrarMatriz(int k, int matrix[][k])
{
    int i, j;

    for(i=0; i<3;i++)
    {
        for(j=0; j<k;j++)
        {
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}
