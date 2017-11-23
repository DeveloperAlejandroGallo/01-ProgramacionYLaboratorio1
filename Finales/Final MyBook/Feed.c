#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"
#include "ArrayList.h"
#include "Feed.h"
#include "Post.h"
#include "Usuarios.h"



void armarArrayFinal(ArrayList* arrayPost,ArrayList* arrayUsrs,ArrayList* arrayFeeds)
{
    int i,j, encontrado;
    Feed* newFeed;
    Post* auxPost;
    Usuario* auxUsr;


    for(i=0; i < arrayPost->len(arrayPost); i++)
    {
        auxPost = (Post*)arrayPost->get(arrayPost,i);
        j=0;
        encontrado=0;
        while(encontrado==0 && j < arrayUsrs->len(arrayUsrs) )
        {
            auxUsr = (Usuario*)arrayUsrs->get(arrayUsrs,j);
            if(auxUsr->id== auxPost->idUsrPublicacion)
            {
                encontrado =1;
                newFeed = new_Feed(auxPost->id,auxPost->mensaje,auxPost->popularidad,auxUsr->id,auxUsr->nick,auxUsr->popularidad);
                arrayFeeds->add(arrayFeeds,newFeed);
                //Si no encuentra el id del usr del msg no lo graba.
            }
            j++;
        }
    }
}


Feed* new_Feed(int id, char* mensaje, int popuMsg, int idUsr, char* nick, int popuUsr)
{
    Feed* retFeed=NULL;
    Feed* feed = malloc(sizeof(Feed));

    if(feed!=NULL)
    {
        feed->idMensaje = id;
        feed->mensaje = mensaje;
        feed->popularidadMsg = popuMsg;
        feed->idUsuarioMsg =  idUsr;
        feed->nick = nick;
        feed->popularidadUsr = popuUsr;
        retFeed = feed;
    }

    return retFeed;
}


int ordenPorPopuaridad(void* feed1, void* feed2)
{
    int ret;
    if( ((Feed*)feed1)->popularidadMsg == ((Feed*)feed2)->popularidadMsg)
    {
        if(((Feed*)feed1)->popularidadUsr >= ((Feed*)feed2)->popularidadUsr)
            ret = 1;
        else
            ret = -1;

    }
    else
    {
        if(((Feed*)feed1)->popularidadMsg > ((Feed*)feed2)->popularidadMsg)
            ret = 1;
        else
            ret = -1;
    }

    return ret;

}


void guardarArchivoFeeds(ArrayList* arrayFeeds)
{
    FILE* archivo;
    Feed* auxFeed=NULL;
    int i;

    archivo = fopen("feeds.csv","w");
    if(archivo!=NULL)
    {
        fprintf(archivo,"%s\n","id_mensaje,mensaje,followers_msj,id_usuario,nick,followers_usr");
        for(i=0; i < arrayFeeds->len(arrayFeeds);i++)
        {
            auxFeed = (Feed*)arrayFeeds->get(arrayFeeds,i);
            fprintf(archivo,"%d,%s,%d,%d,%s,%d\n",auxFeed->idMensaje,auxFeed->mensaje,auxFeed->popularidadMsg,auxFeed->idUsuarioMsg,auxFeed->nick,auxFeed->popularidadUsr);
        }
        fclose(archivo);
    }

}
