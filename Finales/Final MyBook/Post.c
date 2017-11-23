#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ArrayList.h"
#include "Post.h"




void cargarArchivoEnListaPost(ArrayList* arrayPost)
{
    FILE* archivo = fopen("mensajes.csv","r");
    Post* newPost;
    int bSalteoPrimeraLinea=1;
    char id[30], popularidad[30], idUsr[30];//, mensaje[2000];
    char* mensaje = malloc(sizeof(char)*2000);


    if(archivo!=NULL)
    {
        while(!feof(archivo))
        {
            if(bSalteoPrimeraLinea)
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,idUsr,popularidad,mensaje);
                bSalteoPrimeraLinea=0;
                continue;
            }
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,idUsr,popularidad,mensaje);
            newPost = new_Post(atoi(id),mensaje,atoi(popularidad),atoi(idUsr));
            arrayPost->add(arrayPost,newPost);


        }
        fclose(archivo);
    }
    else
    {
        infoMessage("El archivo de Mensajes no pudo ser abierto");
    }
}


Post* new_Post(int id, char* mensaje, int popu, int idUsrPubli)
{
    Post* retPost = NULL;
    Post* post = malloc(sizeof(Post));
    char* mens = malloc(sizeof(char)*2000);

    if(post!=NULL)
    {
        post->id = id;
        strcpy(mens,mensaje);
        post->mensaje = mens;
        post->popularidad = popu;
        post->idUsrPublicacion = idUsrPubli;
        retPost = post;
    }

    return retPost;
}
