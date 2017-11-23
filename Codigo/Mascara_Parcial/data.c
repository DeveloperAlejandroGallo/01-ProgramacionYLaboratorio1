#include <stdin.h>


/*******************************************************************************************
FUNCIONES DE VISUALIZACION
*******************************************************************************************/
/** \brief Imprime el menu principal
 *
 * \return void
 *
 */
void printMenu()
{
        printTitle("MENU");
        printf(" 1- ALTA USUARIO\n");
        printf(" 2- MODIFICAR DATOS USUARIO\n");
        printf(" 3- BAJA USUARIO\n");
        printf(" 4- PUBLICAR PRODUCTO\n");
        printf(" 5- MODIFICAR PUBLICACION\n");
        printf(" 6- CANCELAR PUBLICACION\n");
        printf(" 7- COMPRAR PRODUCTO\n");
        printf(" 8- LISTAR PUBLICACINES USUARIO\n");
        printf(" 9- LISTAR PUBLICACIONES\n");
        printf("10- LISTAR USUARIOS\n");
        printf(" 0- SALIR\n\n");
        printf("ELECCION: ");

}

/** \brief Imprime un mensaje de informacion
 *
 * \param message[] char Mensaje a mostrar
 * \return void
 *
 */
void infoMessage(char message[])
{
    printf("\nInfo ===> %s\n", message);
}


/** \brief Imprime un Titulo con formato
 *
 * \param titulo[] char titulo a mostrar
 * \return void
 *
 */
void printTitle(char titulo[])
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




