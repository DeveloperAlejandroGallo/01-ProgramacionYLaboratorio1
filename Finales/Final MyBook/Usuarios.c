#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"
#include "ArrayList.h"
#include "Usuarios.h"

void cargarArchivoEnListaUsr(ArrayList* arrayUsuarios)
{
    FILE* archivo = fopen("usuarios.csv","r");
    Usuario* newUser;
    int bSalteoPrimeraLinea=1;
    char id[30], popularidad[30];
    char* nick = malloc(sizeof(char)*30);


    if(archivo!=NULL)
    {
        while(!feof(archivo))
        {
            if(bSalteoPrimeraLinea)
            {
                fscanf(archivo,"%[^,],%[^,],%[^\n]\n",id,nick,popularidad);
                bSalteoPrimeraLinea=0;
                continue;
            }
            fscanf(archivo,"%[^,],%[^,],%[^\n]\n",id,nick,popularidad);
            newUser = new_Usuario(atoi(id),nick,atoi(popularidad));

            arrayUsuarios->add(arrayUsuarios,newUser);
        }
        fclose(archivo);
    }
    else
    {
        infoMessage("El Archivo de Usuarios no pudo ser abierto");
    }
}


Usuario* new_Usuario(int id, char* nick, int popu)
{
    Usuario* retUsr = NULL;
    Usuario* usuario = malloc(sizeof(Usuario));
    char* sNick = malloc(sizeof(char)*30);

    if(usuario!=NULL)
    {
        usuario->id = id;
        strcpy(sNick,nick);
        usuario->nick  = sNick;
        usuario->popularidad = popu;
        retUsr = usuario;
    }

    return retUsr;
}
