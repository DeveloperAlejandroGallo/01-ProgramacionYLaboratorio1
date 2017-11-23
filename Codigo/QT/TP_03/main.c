#include <stdio.h>
#include <stdlib.h>
#include "movies.h"


int main()
{
    char seguir='s', auxStr[20];
    int opcion=0,
        cantEscritos,
        largo,
        contador,
        i,
        listSize=1,
        bEncontrado;

    FILE* archivoPeliculas;

    eMovie unaPeli; //estructura estatica para cargar las peliculas
    eMovie* unaPeliAux;
    eMovie* vectorPelis = (eMovie*)malloc(sizeof(eMovie)*listSize);//Inicio con 1 posicion;
    eMovie* vectorPelisAux;


    /*Carga del archivo*/
    contador = 0;
    archivoPeliculas = fopen("Peliculas.dat", "rb");

    if(archivoPeliculas != NULL)
    {
        printf("\nPELICULAS:\n");
        while(fread((void*)(vectorPelis + contador),sizeof(eMovie),1,archivoPeliculas)==1)
        {
            printf("Titulo: %s\n",(vectorPelis + contador)->titulo);
            contador++;
            listSize++;
            vectorPelisAux = (eMovie*)realloc(vectorPelis,sizeof(eMovie)*listSize);
            if(vectorPelisAux != NULL)
                vectorPelis = vectorPelisAux;
        }
        fclose(archivoPeliculas);
    }

    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1://Alta de pelicula
                imprimirTitulo("Alta de Pelicula");
                pedirDatosPelicula(&unaPeli);
                vectorPelisAux = (eMovie*)realloc(vectorPelis,sizeof(eMovie)*listSize);
                listSize++;
                if(vectorPelisAux == NULL)
                {
                    infoMessage("No hay mas lugar para el vector");
                    free(vectorPelis);
                    free(vectorPelisAux);
                    exit(1);
                }
                vectorPelis = vectorPelisAux;
                vectorPelis[contador]=unaPeli;
                contador++;
                infoMessage("Pelicula dada de alta");
                break;
            case 2://Borrar pelicula
                imprimirTitulo("Baja de Pelicula");
                printf("\nTITULOS:\n");
                for(i=0;i<contador;i++)
                {
                    if(vectorPelis[i].activo == 1)
                        printf("-> %s\n",vectorPelis[i].titulo);
                }
                pedirNDato("\nQue pelicula desea eliminar?: ",auxStr,50 );

                for(i=0;i<contador;i++)
                {
                    if(strcmp(vectorPelis[i].titulo,auxStr)==0)
                    {
                        bEncontrado = 1;
                        break;
                    }
                }
                if(bEncontrado == 1)
                {
                    vectorPelis[i].activo=0;
                    printf("\nPelicula %s dada de baja", vectorPelis[i].titulo);
                }
                else
                {
                    infoMessage("No existe la pelicula");
                }


                break;
            case 3://Modificar Pelicula
                imprimirTitulo("Modificar Pelicula");

                printf("\nTITULOS:\n");
                for(i=0;i<contador;i++)
                {
                    printf("-> %s\n",vectorPelis[i].titulo);
                }
                pedirNDato("\nQue pelicula desea modificar?: ",auxStr,50 );

                for(i=0;i<contador;i++)
                {
                    if(strcmp(vectorPelis[i].titulo,auxStr)==0)
                    {
                        bEncontrado = 1;
                        break;
                    }
                }
                if(bEncontrado == 1)
                {
                    pedirDatosPelicula(&unaPeli);
                    vectorPelis[i]=unaPeli;
                }
                else
                {
                    infoMessage("No existe la pelicula");
                }

               break;

            case 4: //Generar pag web
                generarPagina(vectorPelis, "template/index.html", contador);
                break;
            case 5://Listar
                imprimirTitulo("Listar Titulos");
                printf("\nTITULOS:\n");
                for(i=0;i<contador;i++)
                {
                    printf("-> %s\n",vectorPelis[i].titulo);
                }
                break;
            case 6://EXIT
                archivoPeliculas = fopen("Peliculas.dat","wb");
                if(archivoPeliculas == NULL)
                {
                    infoMessage("El archivo no pude ser creado");
                    exit(1);
                }

                for(i=0;i<contador;i++)
                {
                    if((vectorPelis + i)->activo==1)
                    {//verificar la cantidad de escritos
                        fwrite((vectorPelis + i),sizeof(eMovie),1,archivoPeliculas);

                    }

                }
                fclose(archivoPeliculas);
                free(vectorPelis);
                seguir = 'n';
                break;
        }
        printf("\n\n");
        if(opcion!=6)
            system("pause"); //Para q no pida 2 veces la tecla al salir
    }
    //exit(0);
    return 0;
}
