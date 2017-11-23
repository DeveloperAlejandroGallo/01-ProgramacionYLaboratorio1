#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "movies.h"
#include "datos.h"



/*******************************************************************************************
Constructor
*******************************************************************************************/

eMovie* new_movie(char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImg)
{
    eMovie* x;

    x = (eMovie*) malloc(sizeof(eMovie));

    if(x != NULL)
    {
        strcpy(x->titulo,titulo);
        strcpy(x->genero,genero);
        x->duracion = duracion;
        strcpy(x->descripcion,descripcion);
        x->puntaje=puntaje;
        strcpy(x->linkImagen,linkImg);
        x->activo = 1;

    }

    return x;
}


void pedirDatosPelicula(eMovie* unaPeli)
{
    char
    auxTitulo[50],
    auxGenero[20],
    auxDescripcion[500],
    auxLinkImg[200];
    int auxDuracion, auxPuntaje, auxActivo;

    pedirNDato("Titulo: ", unaPeli->titulo,50);
    pedirNDato("Genero: ", unaPeli->genero,20);
    unaPeli->duracion = pedirDatoNumericoValidado("Duracion: ");
    pedirNDato("Descripcion: ", unaPeli->descripcion,500);
    unaPeli->puntaje = pedirDatoNumericoValidado("Puntaje: ");
    pedirNDato("Link Imagen: ", unaPeli->linkImagen,200);
    unaPeli->activo =1;

    //pPeli = new_movie(auxTitulo,auxGenero,auxDuracion,auxDescripcion, auxPuntaje,auxLinkImg);


}


int agregarPelicula(eMovie pMovie)
{
    FILE* archPeli;
    archPeli = fopen("Peliculas.dat","ab+"); // append binario, lo crea si no existe
    if(archPeli==NULL)
    {
        printf("Error abriendo el archivo");
        return 0;
    }

    fwrite(&pMovie,sizeof(eMovie),1,archPeli); // escribo una pelicula al final

    fclose(archPeli);
    return 1;
}



eMovie* leerPelicula(char* titulo)
{
    FILE* archPeli;
    archPeli=fopen("Peliculas.dat","rb"); // lectura binaria
    if(archPeli==NULL)
    {
        printf("Error al abrir el archivo Peliculas.dat");
        return NULL;
    }

    eMovie* pPeli = malloc(sizeof(eMovie));
    int flagFound=0;
    while(fread(pPeli,sizeof(eMovie),1,archPeli)!=0)
    {
        if(strcmp(titulo,pPeli->titulo)==0)
        {
            flagFound=1;
            break;
        }
    }
    fclose(archPeli);
    if(flagFound)
        return pPeli;
    free(pPeli);
    return NULL;
};



void generarPagina(eMovie vectorPelis[], char* html, int cantidad)
{
    int i;
    FILE* archivoHTML;
    archivoHTML = fopen(html,"w");
    if(archivoHTML!=NULL)
    {
		//cabecera de pagina
		fprintf(archivoHTML,"%s\n","<!DOCTYPE html>");
		fprintf(archivoHTML,"%s\n","<html lang='en'>");
		fprintf(archivoHTML,"%s\n","<head>");
		fprintf(archivoHTML,"%s\n","    <meta charset='utf-8'>");
		fprintf(archivoHTML,"%s\n","    <meta http-equiv='X-UA-Compatible' content='IE=edge'>");
		fprintf(archivoHTML,"%s\n","    <meta name='viewport' content='width=device-width, initial-scale=1'>");
		fprintf(archivoHTML,"%s\n","    <title>Lista peliculas</title>");
		fprintf(archivoHTML,"%s\n","    <link href='css/bootstrap.min.css' rel='stylesheet'>");
		fprintf(archivoHTML,"%s\n","    <link href='css/custom.css' rel='stylesheet'>");
		fprintf(archivoHTML,"%s\n","</head>");
		fprintf(archivoHTML,"%s\n","<body>");
		fprintf(archivoHTML,"%s\n","    <div class='container'>");
		//Inicio de repetitivo
		for(i=0;i<cantidad;i++)
        {
            if(vectorPelis[i].activo==1)
            {
				fprintf(archivoHTML,"%s\n","<div class='row'>");
				fprintf(archivoHTML,"%s\n","<article class='col-md-4 article-intro'>");
				fprintf(archivoHTML,"%s\n","<a href='#'>");
				fprintf(archivoHTML,"%s","<img class='img-responsive img-rounded'  src='");

				fprintf(archivoHTML,"%s",vectorPelis[i].linkImagen);


				fprintf(archivoHTML,"%s\n","' alt=''>");
				fprintf(archivoHTML,"%s\n","</a>");
				fprintf(archivoHTML,"%s\n","<h3>");
				fprintf(archivoHTML,"%s","<a href='#'>");

				fprintf(archivoHTML,"%s",vectorPelis[i].titulo);

				fprintf(archivoHTML,"%s","</a>");
				fprintf(archivoHTML,"%s\n","</h3>");
				fprintf(archivoHTML,"%s\n","<ul>");
				fprintf(archivoHTML,"%s","<li>Género:");
				fprintf(archivoHTML,"%s",vectorPelis[i].genero);
				fprintf(archivoHTML,"%s\n","</li>");
				fprintf(archivoHTML,"%s","<li>Puntaje:");
				fprintf(archivoHTML,"%d",vectorPelis[i].puntaje);
				fprintf(archivoHTML,"%s\n","</li>");
				fprintf(archivoHTML,"%s","<li>Duración:");
				fprintf(archivoHTML,"%d",vectorPelis[i].duracion);
				fprintf(archivoHTML,"%s\n","</li>");
				fprintf(archivoHTML,"%s\n","</ul>");
				fprintf(archivoHTML,"%s","<p>");

				fprintf(archivoHTML,"%s",vectorPelis[i].descripcion);

				fprintf(archivoHTML,"%s\n","</p>");
				fprintf(archivoHTML,"%s\n","</article>");
				fprintf(archivoHTML,"%s\n","</div>");
            }
        }
		//Pie de pagina
		fprintf(archivoHTML,"%s\n","    </div>");
		fprintf(archivoHTML,"%s\n","    <script src='js/jquery-1.11.3.min.js'></script>");
		fprintf(archivoHTML,"%s\n","    <script src='js/bootstrap.min.js'></script>");
		fprintf(archivoHTML,"%s\n","	<script src='js/ie10-viewport-bug-workaround.js'></script>");
		fprintf(archivoHTML,"%s\n","	<script src='js/holder.min.js'></script>");
		fprintf(archivoHTML,"%s\n","</body>");
		fprintf(archivoHTML,"%s\n","</html>");

        fclose(archivoHTML);

    }
    else
        infoMessage("El Archivo no pudo ser creado;");
}

/*******************************************************************************************
FUNCIONES DE VISUALIZACION
*******************************************************************************************/

void imprimoMenu()
{
        imprimirTitulo("MENU");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Listar Titulos\n");
        printf("6- Salir\n\n");
        printf("ELECCION: ");

}


void infoMessage(char message[])
{
    printf("\nInfo ===> %s\n", message);
}



void imprimirTitulo(char titulo[])
{

        int i, largo, mitadPalabra, mitadPantalla;

        largo = strlen(titulo);
        mitadPalabra = largo / 2 + 1; //Como meto la division en entero me queda solo la parte entera
        mitadPantalla = ANCHO_PANTA / 2;

        system("cls");
        for(i=0;i<ANCHO_PANTA;i++) printf("*");
        printf("\n");
        printf("*");
        for(i=0;i<mitadPantalla-mitadPalabra;i++) printf(" ");
        printf("%s",titulo);
        for(i=0;i<mitadPantalla-mitadPalabra;i++) printf(" ");
        printf("*");
        printf("\n");
        for(i=0;i<ANCHO_PANTA;i++) printf("*");
        printf("\n");


    }
