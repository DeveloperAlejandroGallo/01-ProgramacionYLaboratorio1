#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "funcNetflix.h"

void cargarSeries(eSerie series[])
{
   int idSerie[5]={100,101,102,103,104};
    int estado[5]={1,1,1,1,1};
    char titulo[5][30]={"TBBT","BB","GOT","AHS","SCD"};
    int temporadas[5]={9,7,7,6,1};
    char genero[5][30]={"Comedia","Policial","Ciencia Ficcion","Terror","Comedia"};

    int i;
     for(i=0; i<5;i++)
    {
        series[i].idSerie = idSerie[i];
        strcpy(series[i].titulo, titulo[i]);
        series[i].estado = estado[i];
        series[i].temporadas = temporadas[i];
        strcpy(series[i].genero, genero[i]);
    }

}
void cargarClientes(eCliente clientes[])
{
    int id[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[10][30]={"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]={1,1,1,1,1,1,1,1,1,1};
    int idSerie[10]={100,100,101,103,103,101,102,103,100,100};
    int i;

    for(i=0; i<10;i++)
    {
        clientes[i].idCliente = id[i];
        strcpy(clientes[i].nombre, nombres[i]);
        clientes[i].estado = estado[i];
    }

}

void cargarClientesSeries(eCliente clientes[], eSerie series[], eClientesSeries clientesSeries[])
{
    int i;
    for(i=0;i<10;i++)
        {
            clientesSeries[i].idCliente = clientes[i].idCliente;
            clientesSeries[i].idSerie = series[i].idSerie;
        }
}
void imprimirTitulosSerie()
{
    printf("**SERIES**\n");
    printf("%3s\t%20s\t%4s\t%20s\n","ID","TITULO","TEMP","GENERO");
}

void imprimirTitulosCliente()
{
    printf("**CLIENTES**\n");
    printf("%3s\t%30s\t%20s\n","ID","NOMBRE","SERIE");
}

void mostrarSeries(eSerie series[],int S)
{
    int i;
    imprimirTitulosSerie();
    for(i=0;i<S;i++)
        imprimeSerie(series, i);

}

void imprimeSerie(eSerie series[], int i)
{
    printf("%3d\t%20s\t%4d\t%20s\n",series[i].idSerie,series[i].titulo,series[i].temporadas,series[i].genero);
}

void mostrarClientes(eCliente clientes[],int C)
{
    int i;
    imprimirTitulosCliente();
    for(i=0;i<C;i++)
        imprimeCliente(clientes, i);

}

void imprimeCliente(eCliente clientes[], int i)
{
    printf("%3d\t%30s\t%20d\n",clientes[i].idCliente,clientes[i].nombre,1);
}

void mostrarClientesConSerie(eCliente clientes[],eSerie series[],eClientesSeries clientesSeries[],int C,int S, int CS)
{
    int i,j;
    char nombreSerie[20];
    imprimirTitulosCliente();
    for(i=0;i<C;i++)
    {
        for(j=0;j<CS;j++)
        {
            if(clientesSeries[j].idCliente == clientes[i].idCliente)
            {
                nombreDeSerie(series,clientesSeries[j].idSerie, S,/*var out*/nombreSerie);
                printf("%3d\t%30s\t%20s\n",clientes[i].idCliente,clientes[i].nombre, nombreSerie);
            }
        }
    }
}

void nombreDeSerie(eSerie series[], int idSerie, int S,char nombreSerie[])
{
    int i;

    for(i=0;i<S;i++)
    {
        if(series[i].idSerie == idSerie)
        {
            strcpy(nombreSerie,series[i].titulo);
            i=S; //Para finalizar el ciclo.
        }
    }
}


void mostrarSeriesConClientes(eCliente clientes[],eSerie series[], eClientesSeries clientesSeries[] ,int C,int S, int CS)
{
    int i,j;
    printf("**SERIES CON CLIENTES**\n");
    for(i=0;i<S;i++)
    {
        printf("********************************\n");
        printf("Clientes Viendo %s\n",series[i].titulo);
        printf("********************************\n");
        imprimirClientesDeUnaSerie(clientes, series[i].idSerie, clientesSeries, C, CS);
        printf("\n\n");
    }
}

void imprimirClientesDeUnaSerie(eCliente clientes[], int idSerie, eClientesSeries clientesSeries[], int C, int CS)
{
    int i,j;

    for(i=0;i<C;i++)
    {
        for(j=0;j<CS;j++)
        {
            if(clientesSeries[i].idCliente == clientes[i].idCliente && clientesSeries[j].idSerie == idSerie)
                    printf("%30s\n",clientes[i].nombre);

        }
    }
}

int cantidadClientesViendoUnaSerie(eCliente clientes[], eClientesSeries clientesSeries[],int idSerie, int C, int CS)
{
    int i,j, cuenta=0;

    for(i=0;i<C;i++)
    {
        for(j=0;j<CS;j++)
        {
            if(clientesSeries[i].idCliente == clientes[i].idCliente && clientesSeries[j].idSerie == idSerie)
                cuenta++;
        }
    }

    return cuenta;
}


int buscarSeriePorTitulo(eSerie series[], char titulo[], int S)
{
    int i, indice=-1; //Se inicializa en -1 para devolver este valor si no fue encontrado.

    for(i=0;i<S;i++)
    {
        if(stricmp(series[i].titulo,titulo)==0)
        {
            indice = i;
            i=S;
        }
    }
    return indice;
}

int buscarSerieXId(eSerie series[], int idSerie, int S)
{
    int i, indice=-1; //Se inicializa en -1 para devolver este valor si no fue encontrado.

    for(i=0;i<S;i++)
    {
        if(series[i].idSerie == idSerie)
        {
            indice = i;
            i=S;
        }
    }
    return indice;
}


void mostrarSerieLoser(eCliente clientes[],eSerie series[],int C,int S)
{
    int indiceBuscado;
    eLoser loosers[S];

    cargarLoosers(series,clientes,loosers,C,S);
    orderLooserByCantDesc(loosers, S);
    indiceBuscado = buscarSerieXId(series,loosers[0].idSerie, S);
    printf("La Serie Looser es: %s",series[indiceBuscado].titulo);
}



void cargarLoosers(eSerie series[], eCliente clientes[], eLoser loosers[], eClientesSeries clientesSeries[],int C, int S, int CS)
{
    int i;

    for(i=0;i<S;i++)
    {
        loosers[i].idSerie = series[i].idSerie;
        loosers[i].cont = cantidadClientesViendoUnaSerie(clientes,clientesSeries,  series[i].idSerie, C, CS);
    }
}

void orderLooserByCantDesc(eLoser loosers[], int S)
{
    int i,j;
    eLoser auxLooser;

    for(i=0;i<S-1;i++)
    {
        for(j=i+1;j<S;j++)
        {
            if(loosers[i].cont>loosers[j].cont)
            {
                auxLooser = loosers[i];
                loosers[i] = loosers[j];
                loosers[j] = auxLooser;
            }
        }
    }
}
