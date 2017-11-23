#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "funcNetflix.h"

#define S 5
#define C 10
/*
2- mostrar cada uno
3- mostrar clientes con su serie
4- por cada serie los clientes que la estan viendo
5- todos los clientes que ven TBBT (100)
6- La serie menos popular

Crear una cuarta estructura que permita relacionar un cliente con una serie, de esta manera podremos obtener una relacion
muchos a muchos (Un cliente que ve muchas series)

7- Todas las series que ven los clientes de nombre "Juan"
*/


int main()
{

    eSerie series[S];
    eCliente clientes[C];
    eLoser loosers[S];

    cargarSeries(series);
    cargarClientes(clientes);

    char seguir='s', respuesta, titulo[30];
    int opcion=0;
    //Auxiliares
    int iBuscado, nro, i, idSerie;

    while(seguir=='s')
    {
        system("cls");
        printf("2- mostrar cada uno\n");
        printf("3- mostrar clientes con su serie\n");
        printf("4- por cada serie los clientes que la estan viendo\n");
        printf("5- todos los clientes que ven una serie\n");
        printf("6- La serie menos popular\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 2:
                mostrarSeries(series, S);
                printf("\n\n");
                mostrarClientes(clientes, C);
                break;
            case 3:
                mostrarClientesConSerie(clientes, series, C,S);
                break;
            case 4:
                mostrarSeriesConClientes(clientes,series,C,S);
                break;
            case 5:
                printf("Ingrese el Nombre de la Serie: ");
                fflush(stdin);
                gets(titulo);
                printf("\n");
                iBuscado = buscarSeriePorTitulo(series, titulo, S);
                if(iBuscado != -1)
                {
                    imprimirTitulosSerie();
                    imprimeSerie(series, iBuscado);
                    imprimirClientesDeUnaSerie(clientes, series[iBuscado].idSerie, C);
                }
                else
                    printf("La pelicula no existe");
                break;
            case 6:
                mostrarSerieLoser(clientes, series,C,S);
                break;
            case 7:
                seguir = 'n';
                break;
            default:
                break;
        }
        printf("\n\n");
        if(opcion!=7)
           system("pause"); //Para q no pida 2 veces la tecla al salir
    }







    return 0;
}

