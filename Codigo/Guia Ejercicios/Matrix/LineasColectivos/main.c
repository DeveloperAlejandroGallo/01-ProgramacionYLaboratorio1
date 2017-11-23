#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define LINEAS 4  //Una fila para totales coche
#define COCHES 13 //Una columna para totales linea


void calcularTotales(float recaudacion[LINEAS][COCHES]);
void mostrarMatriz(float matrix[LINEAS][COCHES]);

int main()
{
    float recaudacion[LINEAS][COCHES];
    int i,j, linea, coche;
    char salir = 'n';

    for(i=0; i<LINEAS;i++)
    {
        for(j=0; j<COCHES;j++)
        {
            recaudacion[i][j] = 0;
        }
    }

    do
    {
        printf("Ingrese la linea(1-3): ");
        scanf("%d", &linea);
        printf("Ingrese el coche (1-12): ");
        scanf("%d", &coche);
        printf("Ingrese el importe: ");
        scanf("%f", &recaudacion[linea-1][coche-1]);
        printf("Desea Salir?: ");
        fflush(stdin);
        salir = getche();
        system("cls");
    }while(salir != 's');

    calcularTotales(recaudacion);

    mostrarMatriz(recaudacion);


    return 0;
}


void calcularTotales(float recaudacion[LINEAS][COCHES])
{
    int i, j;
    float acum;
    for(i=0; i<LINEAS-1; i++)
    {
        acum = 0;
        for(j=0;j<COCHES-1;j++)
        {
            acum += recaudacion[i][j];
        }
        recaudacion[i][COCHES-1] = acum;
    }


    for(j=0;j<COCHES;j++)
    {
        acum = 0;
        for(i=0;i<LINEAS;i++)
        {
            acum += recaudacion[i][j];
        }
        recaudacion[LINEAS-1][j] = acum;
    }

}


void mostrarMatriz(float matrix[LINEAS][COCHES])
{
    int i, j;

    for(i=0; i<LINEAS;i++)
    {
        for(j=0; j<COCHES;j++)
        {
            printf(" %.2f", matrix[i][j]);
        }
        printf("\n");
    }
}
