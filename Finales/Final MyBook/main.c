#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"
#include "ArrayList.h"
#include "Post.h"
#include "Usuarios.h"
#include "Feed.h"

#define ASC 1
#define DESC 0

int main()
{
    ArrayList* arrayPost = al_newArrayList();
    ArrayList* arrayUsrs = al_newArrayList();
    ArrayList* arrayFeeds = al_newArrayList();

    imprimirTitulo("FEED - MyBook\n");
	cargarArchivoEnListaPost(arrayPost);
	cargarArchivoEnListaUsr(arrayUsrs);
	armarArrayFinal(arrayPost, arrayUsrs, arrayFeeds);
	arrayFeeds->sort(arrayFeeds, ordenPorPopuaridad, DESC);
	guardarArchivoFeeds(arrayFeeds);
	infoMessage("Archivo Feeds.csv Creado!");

    return 0;
}
