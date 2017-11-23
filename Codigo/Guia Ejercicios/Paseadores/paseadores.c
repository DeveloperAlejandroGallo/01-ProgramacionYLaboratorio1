#include <string.h>
#include "paseadores.h"



//void cargar10DatosEnEstructuras(ePaseador paseadores[], ePerro perros[], eRaza razas[])
//{
//    int cant=10;
//
//    int IdsPaseadores[10] = {10,20,30,40,50,60,70,80,90};
//
//    char NombresPaseadores [10][LARGO_NAME]  = {"Juan","Pablo","David","Dario","Emanuel", "Emiliano","Noelia","Laura","Rober","Ale"};
//
//    int Edades[10] = {1, 2, 3, 18, 22, 23, 24, 25, 35, 80};
//
//    int IdsPerros [10] = {1,2,3,4,5,6,7,8,9,10};
//    char NombresPerros[10] [LARGO_NAME]= {"Puchi","Firu","Toto","Lassie","Rintintin","Cuki","Moca","Jet","Flash","Rayo"};
//
//    int IdsRazas = {100,200,300,400,500};
//    char DescripcionesRazas  = {"Doberman","Coli","Dogo","Rothwailer","beagle"};
//
//
//
//    int i;
//
//    inicializarEstructuras(paseadores, QTY_PASEADORES, perros, QTY_PERROS, razas, QTY_RAZAS);
//
//    //Paseadores
//    for(i=0;i<cant;i++)
//    {
//        paseadores[i].idPaseador = IdsPaseadores[i];
//        strcpy(paseadores[i].nombre, NombresPaseadores[i]);
//    }
//
//     //Perros
//    for(i=0;i<cant;i++)
//    {
//        perros[i].idPerro = IdsPerros[i];
//        strcpy(perros[i].nombre , NombresPerros[i]);
//        perros[i].idRaza=IdsRazas[i];
//    }
//
//
//    //Razas
//    for(i=0;i<cant;i++)
//    {
//        razas[i].idRaza = IdsRazas[i];
//        strcpy(razas[i].descripcion,DescripcionesRazas[i]);
//    }
//
//
//}
//
//void inicializarEstructuras(ePaseador paseadores[], int cantPaseadores, ePerro perros[], int cantPerros; eRaza razas[], int cantRazas, ePaseadoresPerros paseos[], int cantPaseos)
//{
//int i;
////Paseadores
//    for(i=0;i<cantPaseadores;i++)
//    {
//        paseadores[i].idPaseador = 0;
//        paseadores[i].nombre = "";
//    }
//
// //Perros
//    for(i=0;i<cantPerros;i++)
//    {
//        perros[i].idPerro = 0;
//        perros[i].nombre = "";
//        perros[i].idRaza=0;
//    }
//
//
//    //Razas
//    for(i=0;i<cantPaseadores;i++)
//    {
//        razas[i].idRaza = 0;
//        razas[i].descripcion = "";
//    }
//
//}

/*******************************************************************/

void cuantosPaseosHizoUnPerro(int idPerro, char nombrePerro[], ePaseadoresPerros paseos[],int cPaseos)
{
    int  i, contador=0;

    for(i=0; i<cPaseos;i++)
    {
        if(paseos[i].idPerro == idPerro)
            contador++;
    }

    printf("%s realizo %d paseos.\n",nombrePerro,contador);


}



int buscoIdPerro(char nombre[50], ePerro perros[], int cPerros)
{
        int i, buscado=0;
        for(i=0;i<cPerros;i++)
        {
            if(stricmp(perros[i].nombre,nombre)==1)
            {
                buscado = i;
                break;
            }
        }
        return buscado;
}


void paseadorQueMasPasea(ePaseador paseadores[], int cPaseadores,ePaseadoresPerros paseos[], int cPaseos)
{
    int i, contador=0, idMayor;
    ePaseadorCantPaseos paseadorPaseos[cPaseadores];

    for(i=0;i<cPaseadores;i++)
    {
        contador = cuantoPaseos(paseadores[i].idPaseador,paseos, cPaseos);
        if(contador > 0)
        {
            strcmp(paseadorPaseos[i].nombre,paseadores[i].nombre);
            paseadorPaseos[i].cantidad = contador;
        }

    }
    idMayor = idMayorCantidadPaseos(paseadorPaseos, cPaseadores);
    printf("%s fue el que mayor paseos ralizo. Total: %d",paseadorPaseos[i].nombre, paseadorPaseos[i].cantidad);

}



int cuantoPaseos(int idPaseador, ePaseadoresPerros paseos[],int cPaseos)
{
    int i, contador=0;

    for(i=0;i<cPaseos;i++)
    {
        if(paseos[i].idPaseador==idPaseador)
            contador++;
    }
    return contador;
}




int idMayorCantidadPaseos(ePaseadorCantPaseos paseadorPaseos[], int cPaseadores)
{
    int i, mayor, id;

    mayor = paseadorPaseos[0].cantidad;
    id=0;
    for(i=0;i<cPaseadores;i++)
    {
        if(paseadorPaseos[i].cantidad > mayor)
            {
                mayor = paseadorPaseos[i].cantidad ;
                id = i;
            }
    }

    return id;
}


















