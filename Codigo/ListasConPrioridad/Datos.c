#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Datos.h"

#define LARGO_NAME 50
#define ANCHO_PANTA 80
/** \brief Pide un dato string por pantalla
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el dato
 * \param dato[] char cadena donde se devuelve el dato
 * \return void
 *
 */
void pedirDato(char mensaje[],char dato[])
{
    printf("%s",mensaje);
	fflush(stdin);
    gets (dato);
}


void pedirNDato(char mensaje[],char dato[], int cant)
{
    strcpy(dato,"");
    printf("%s",mensaje);
	fflush(stdin);
    fgets(dato, cant, stdin);
    limpiarSaltoDeLinea(dato);
}


void limpiarSaltoDeLinea(char cadena[])
{
    if(cadena[strlen(cadena)-1]=='\n')
    {
        cadena[strlen(cadena)-1]='\0';
    }
}



/** \brief Verifica si toda la cadena dato es numerica
 *
 * \param dato[] char cadena que posee el dato a analizar
 * \return int 0: Invalido - 1: Valido
 *
 */
int esSoloNumero(char dato[])
{
    int i=0;
    int bValid=1;

    while(dato[i] != '\0')
   {
       if(dato[i] < '0' || dato[i] > '9')
           {
               bValid = 0;
               break;
           }
       i++;
   }

   return bValid;
}


/** \brief  Valida si el dato string ingresado es solo letras mayusculas y minusculas.
 *
 * \param dato[] char - Cadena a analizar
 * \return int 0: Invalido - 1: Valido
 *
 */
int esSoloLetras(char dato[])
{
   int i=0;
    int bValid=1;

    while(dato[i] != '\0')
   {
       if(dato[i]!=' ')
        {
           if(dato[i] < 'A' || (dato[i] > 'Z' && dato[i] < 'a') || dato[i] > 'z' ) // Comparo por ASCII
               {
                   bValid = 0;
                   break;
               }
        }
       i++;
   }

   return bValid;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/** \brief Pide un dato numerico valido, hasta que lo sea.
 *
 * \param mensaje[] char - Mensaje a mostrar para pedir el dato
 * \return int - El nro validado ingresado.
 *
 */
int pedirDatoNumericoValidado(char mensaje[])
{
    int valido;
	char dato[100]; //Cadena donde recibe el dato

    pedirDato(mensaje,dato);
    valido = esSoloNumero(dato);
	while(valido == 0)
    {
		pedirDato("ERROR: No es numerico. Por favor Reingresar: ", dato);
		valido = esSoloNumero(dato);
    }
	return atoi(dato);
}


/** \brief Pide un dato string por consola, validadnod la entrada para que sena solo letras
 *
 * \param mensaje[] char Mensaje a mostrar para pedir el dato
 * \param name[] char Dato devuelto como estring de 50
 * \return void
 *
 */
void pedirDatoSoloLetrasValido(char mensaje[], char cString[])
{
	int valido;
	char dato[200]; //Cadena donde recibe el dato

    pedirDato(mensaje,dato);
    valido = esSoloLetras(dato);
	while(valido == 0)
    {
		pedirDato("ERROR: Deben ser solo letras. Por favor Reingresar: ", dato);
		valido = esSoloLetras(dato);
    }
	strncpy(cString,dato,LARGO_NAME);

	if(strlen(dato)>=50)
        cString[49] = '\0';  //Para evitar perder el final de la cadena cuando el nombre ingresado es mayor a lo esperado.
}

/** \brief Pide la respuesta y la espera en una letra
 *
 * \param mensaje[] char Mensaje con el cual pide la respuesta
 * \return char Letra de la respuesta
 *
 */
char pedirRespuesta(char mensaje[])
{
    char respuesta;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&respuesta);

    return respuesta;
}


/*******************************************************************************************
FUNCIONES DE VISUALIZACION
*******************************************************************************************/

void imprimoMenu()
{
        system("cls");
        imprimirTitulo("MENU");
        printf("1- Tramite Urgente\n");
        printf("2- Tramite Regular\n");
        printf("3- Proximo Cliente\n");
        printf("4- Listar\n");
        printf("5- Informar\n");
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
