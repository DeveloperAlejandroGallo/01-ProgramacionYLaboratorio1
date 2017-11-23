#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Datos.h"
#include "Usuarios.h"


void cargarArrayUsuarios(ArrayList* arrayUsuarios)
{
    FILE* archivo = fopen("usuarios.dat","r");
    Usuario* newUser;
    int bSalteoPrimeraLinea=1;
    char id[30];
    char* nombre = malloc(sizeof(char)*30);
    char* email = malloc(sizeof(char)*30);
    char* sexo = malloc(sizeof(char)*10);
    char* pais = malloc(sizeof(char)*10);
    char* passw = malloc(sizeof(char)*30);
    char* ip = malloc(sizeof(char)*16);

    if(archivo!=NULL)
    {
        while(!feof(archivo))
        {
            if(bSalteoPrimeraLinea)
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,email, sexo, pais, passw, ip);
                bSalteoPrimeraLinea=0;
                continue;
            }
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,email, sexo, pais, passw, ip);
            newUser = new_Usuario(atoi(id),nombre,email, sexo, pais, passw, ip);

            arrayUsuarios->add(arrayUsuarios,newUser);
        }
        fclose(archivo);
    }
    else
    {
        infoMessage("El Archivo de Usuarios no pudo ser abierto");
    }
}


Usuario* new_Usuario(int id, char* nombre,char* email,char* sexo,char* pais,char* passw,char* ip)
{
    Usuario* retUsr = NULL;
    Usuario* usuario = malloc(sizeof(Usuario));
    char* sNombre = malloc(sizeof(char)*30);
    char* sEmail = malloc(sizeof(char)*30);
    char* sSexo = malloc(sizeof(char)*10);
    char* sPais = malloc(sizeof(char)*10);
    char* sPassw = malloc(sizeof(char)*30);
    char* sIp = malloc(sizeof(char)*16);

    if(usuario!=NULL)
    {
        usuario->id = id;
        strcpy(sNombre,nombre);
        strcpy(sEmail,email);
        strcpy(sSexo,sexo);
        strcpy(sPais,pais);
        strcpy(sPassw,passw);
        strcpy(sIp,ip);
        usuario->nombre = sNombre;
        usuario->email = sEmail;
        usuario->sexo = sSexo;
        usuario->pais = sPais;
        usuario->password = sPassw;
        usuario->ip_address = sIp;
        retUsr = usuario;
    }

    return retUsr;
}


int ordenPorNombre(void* usr1, void* usr2)
{
    int ret;
    if( stricmp( ((Usuario*)usr1)->nombre , ((Usuario*)usr2)->nombre  ) == 0 )
        ret = 1;
    else
        ret = stricmp( ((Usuario*)usr1)->nombre , ((Usuario*)usr2)->nombre  );

    return ret;
}

int ordenPorNacionalidadYNombre(void* usr1, void* usr2)
{
    int ret;
    if( stricmp( ((Usuario*)usr1)->pais , ((Usuario*)usr2)->pais  ) == 0 )
        ret = ordenPorNombre(usr1, usr2);
    else
        ret = stricmp( ((Usuario*)usr1)->pais , ((Usuario*)usr2)->pais ) ;

    return ret;
}



void imprimirUsuarios(ArrayList* arrayUsuarios)
{
    int i;
    Usuario* auxUsr;
    printf("%5s|%10s%|%35s|%6s|%4s\n","ID","NOMBRE","EMAIL","SEXO","PAIS");
    for(i=0; i < arrayUsuarios->len(arrayUsuarios); i++)
    {
        auxUsr = arrayUsuarios->get(arrayUsuarios,i);
        printf("%5d|%10s%|%35s|%6s|%4s\n",auxUsr->id,auxUsr->nombre,auxUsr->email, auxUsr->sexo, auxUsr->pais);
    }
}



int usuarioYPasswValidos(ArrayList* usuarios, char nombre[],char passw[],int *idUsr,char pais[])
{
    int i, ret = 0;
    Usuario* auxUsr;

    for(i=0; i < usuarios->len(usuarios); i++)
    {
        auxUsr = usuarios->get(usuarios,i);
        if(stricmp(nombre,auxUsr->nombre) == 0 && stricmp(passw,auxUsr->password) == 0 )
        {
            idUsr = auxUsr->id;
            strcpy(pais,auxUsr->pais);
            ret = 1;
            break;
        }
    }

    return ret;
}

