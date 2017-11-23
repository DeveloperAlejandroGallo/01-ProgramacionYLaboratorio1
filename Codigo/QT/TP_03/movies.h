#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[200];
    int activo;
}eMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(eMovie lista[], char nombre[], int cantidad);



/** \brief Contructor de eMovie, obtiene el espacio necesario para poder crear una pelicula inicializada con los datos pasados por parametro
 *
 * \param titulo char* Titulo de la pelicula
 * \param genero char* Genero de la pelicula
 * \param duracion int duracion de la pelicula
 * \param descripcion char* descripcion  de la pelicula
 * \param puntaje int puntaje en IMDB  de la pelicula
 * \param linkImg char* link de IMBD  de la pelicula
 * \return eMovie* puntero a la nueva pelicula.
 *
 */
eMovie* new_movie(char* titulo, char* genero, int duracion, char* descripcion, int puntaje, char* linkImg);






//FUNC DE VISUALIZACION
void imprimoMenu();

void infoMessage(char message[]);

void imprimirTitulo(char titulo[]);

#endif // MOVIES_H_INCLUDED
