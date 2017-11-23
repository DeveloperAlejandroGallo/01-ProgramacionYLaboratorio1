#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Datos.h"
#include "Temas.h"
#include "Estadisticas.h"


void cargarArrayEstadisticas(ArrayList* arrayEstadisticas)
{
    FILE* archivo = fopen("estadisticas.dat","r");
    Estadistica* newEstadistica;
    int bSalteoPrimeraLinea=1;
    char idUsr[30],idTema[30], cantReprod[30];
    char* paisUsr = malloc(sizeof(char)*4);


    if(archivo!=NULL)
    {
        while(!feof(archivo))
        {
            if(bSalteoPrimeraLinea)
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",idUsr,paisUsr,idTema,cantReprod);
                bSalteoPrimeraLinea=0;
                continue;
            }
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",idUsr,paisUsr,idTema,cantReprod);
            newEstadistica = new_Estadistica(atoi(idUsr),paisUsr,atoi(idTema),atoi(cantReprod));

            arrayEstadisticas->add(arrayEstadisticas,newEstadistica);
        }
        fclose(archivo);
    }

}


Estadistica* new_Estadistica(int idUsr, char* pais,int idTema, int cantReprod)
{
    Estadistica* retEstadistica= NULL;
    Estadistica* estad = malloc(sizeof(Estadistica));
    char* sPaisUsr = malloc(sizeof(char)*4);


    if(estad!=NULL)
    {
        estad->idUsuario = idUsr;
        strcpy(sPaisUsr,pais);
        estad->pais = sPaisUsr;
        estad->idTema = idTema;
        estad->cantReproducciones = cantReprod;
        retEstadistica = estad;
    }

    return retEstadistica;
}


void guardarEstadisticas(ArrayList* arrayEstad)
{
    FILE* archivo = fopen("estadisticas.dat","r");
    int conTitulo,i;
    Estadistica* auxEst;

    if(archivo==NULL)
        conTitulo = 1;
    else
    {
        conTitulo = 0;
        fclose(archivo);
    }

    archivo = fopen("estadisticas.dat","a");

    if(archivo!=NULL)
    {
        if(conTitulo)
            fprintf(archivo,"%s,%s,%s,%s","id_usuario","pais","id_tema","reproducciones");

        for(i=0; i< arrayEstad->len(arrayEstad); i++)
        {
            auxEst = arrayEstad->get(arrayEstad,i);
            fprintf(archivo,"%d,%s,%d,%d",auxEst->idUsuario,auxEst->pais,auxEst->idTema,auxEst->cantReproducciones);
        }
        fclose(archivo);
    }

}


void agregarTemaAEstadistica(ArrayList* arrayEstadistic,int idUsr,char pais[],int idTema)
{
    Estadistica* auxEst;
    int i, encontrado=0;

    for(i=0; i < arrayEstadistic->len(arrayEstadistic); i++)
    {
        auxEst = arrayEstadistic->get(arrayEstadistic,i);
        if(auxEst->idUsuario==idUsr && auxEst->idTema == idTema)
        {
            auxEst->cantReproducciones++;
            arrayEstadistic->set(arrayEstadistic,i, auxEst);
            encontrado=1;
            break;
        }
    }
    if(!encontrado)
    {
        auxEst = new_Estadistica(idUsr,pais,idTema,1);
        arrayEstadistic->add(arrayEstadistic,auxEst);
    }

}
