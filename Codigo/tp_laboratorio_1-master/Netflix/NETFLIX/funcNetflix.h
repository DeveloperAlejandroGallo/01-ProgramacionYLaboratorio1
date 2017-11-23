#ifndef FUNCNETFLIX_H_INCLUDED
#define FUNCNETFLIX_H_INCLUDED


typedef struct
{
    int idSerie;
    char titulo[20];
    int temporadas;
    char genero[20];
    int estado;
}eSerie;

typedef struct
{
    int idCliente;
    char nombre[30];
    int estado;
 }eCliente;

typedef struct
{
    int idCliente;
    int idSerie;
}eClientesSeries;

typedef struct
{
    int idSerie;
    int cont;
} eLoser;

void cargarSeries(eSerie[]);
void cargarClientes(eCliente[]);

void mostrarSeries(eSerie[],int);
void mostrarClientes(eCliente[], int);
void mostrarClientesConSerie(eCliente[], eSerie[], eClientesSeries[], int, int, int);
void mostrarSeriesConClientes(eCliente clientes[],eSerie series[], eClientesSeries clientesSeries[] ,int C,int S, int CS);
void mostrarSerieLoser(eCliente[], eSerie[], int, int);
void mostrarClientesTBBT(eCliente[], eSerie[], int, int);

void cargarClientesSeries(eCliente[], eSerie[], eClientesSeries []);
#endif // FUNCNETFLIX_H_INCLUDED
