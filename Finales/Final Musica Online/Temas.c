#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Datos.h"
#include "Temas.h"


void cargarArrayTemas(ArrayList* arrayTemas)
{
    FILE* archivo = fopen("temas.dat","r");
    Tema* newTema;
    int bSalteoPrimeraLinea=1;
    char id[30];
    char* nombre = malloc(sizeof(char)*30);
    char* artista = malloc(sizeof(char)*30);


    if(archivo!=NULL)
    {
        while(!feof(archivo))
        {
            if(bSalteoPrimeraLinea)
            {
                fscanf(archivo,"%[^,],%[^,],%[^\n]\n",id,nombre,artista);
                bSalteoPrimeraLinea=0;
                continue;
            }
            fscanf(archivo,"%[^,],%[^,],%[^\n]\n",id,nombre,artista);
            newTema = new_Tema(atoi(id),nombre,artista);

            arrayTemas->add(arrayTemas,newTema);
        }
        fclose(archivo);
    }
    else
    {
        infoMessage("El Archivo de Temas no pudo ser abierto");
    }
}


Tema* new_Tema(int id, char* nombre,char* artista)
{
    Tema* retTema= NULL;
    Tema* tema = malloc(sizeof(Tema));
    char* sNombre = malloc(sizeof(char)*30);
    char* sArtista = malloc(sizeof(char)*30);


    if(tema!=NULL)
    {
        tema->id = id;
        strcpy(sNombre,nombre);
        strcpy(sArtista,artista);
        tema->nombre = sNombre;
        tema->artista = sArtista;
        retTema = tema;
    }

    return retTema;
}


int ordenarPorArtistaYTema(void* tema1, void* tema2)
{
    int ret;
    if( stricmp( ((Tema*)tema1)->artista, ((Tema*)tema2)->artista ) == 0 )
    {
        ret = ordenarPorTema(tema1, tema2);
    }
    else
        ret = stricmp( ((Tema*)tema1)->artista, ((Tema*)tema2)->artista );

    return ret;
}


int ordenarPorTema(void* tema1, void* tema2)
{
    int ret;
    if( stricmp( ((Tema*)tema1)->nombre, ((Tema*)tema2)->nombre ) == 0 )
    {
        ret = 1;
    }
    else
        ret = stricmp( ((Tema*)tema1)->nombre, ((Tema*)tema2)->nombre );

    return ret;
}


void imprimirTemas(ArrayList* arrayTemas)
{
    int i;
    Tema* auxTema;
    printf("%5s|%30s%|%25s\n","ID","ARTISTA","NOMBRE");
    for(i=0; i < arrayTemas->len(arrayTemas); i++)
    {
        auxTema = arrayTemas->get(arrayTemas,i);
        printf("%5d|%30s%|%25s\n",auxTema->id,auxTema->artista,auxTema->nombre);
        if(i % 60 == 0)
            system("pause");
    }
}

int existeTema(ArrayList* arrayTemas,char tema[],int* idTema)
{
    int i,ret=0;
    Tema* auxTema;

    for(i=0; i < arrayTemas->len(arrayTemas); i++)
    {
        auxTema = arrayTemas->get(arrayTemas,i);
        if(strcmp(auxTema->nombre,tema))
        {
            idTema =  auxTema->id;
            ret = 1;
            break;
        }
    }

    return ret;
}
