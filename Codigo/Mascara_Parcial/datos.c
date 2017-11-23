#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "datos.h"




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


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void pedirString(char mensaje[],char dato[])
{
    printf("%s",mensaje);
    scanf ("%s", dato);
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
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    pedirString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
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
 * \param name[] char Dato devuelto como string de 50
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
        cString[49] = '\0';  //Para evitar perder el final de la cadena cuando el string ingresado es mayor a lo esperado.
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



/** \brief Pide una respuesta con mensaje, y un largo especifico. Solo se toman los N caracteres especificados y los devuelve en cadenaFinal
 *
 * \param mensaje[] char Mensaje
 * \param cadenaFinal[] int largo Largo de la cadena receptora
 * \param cadenaFinal[] char cadena que contendra la respuesta
 * \return void
 *
 */
void pedirRespuestaCadenaConLargo(char mensaje[], int largo, char cadenaFinal[])
{
    int i;
    char dato[256];

    pedirDato(mensaje,dato);
    strncpy(cadenaFinal,dato,largo);

    if(strlen(dato)>=largo)
        cadenaFinal[largo-1] = '\0';

}



/** \brief Pone letra capital a cada nombre
 *
 * \param auxString[] char Nombre completo
 * \return void
 *
 */
void formatearNombre(char auxString[])
{
    int i=0;

    while(auxString[i] != '\0')
    {
        if(auxString[i]!=' ')
            auxString[i] = tolower(auxString[i]);
        i++;
    }

     i=0;
    auxString[0] = toupper(auxString[0]);
    while(auxString[i] != '\0')
    {
        if(auxString[i] == ' ')
            auxString[i+1] = toupper(auxString[i+1]);

        i++;
    }
}





/** \brief Busca el mayor entre 3 nros
 *
 * \param nro1 Numero 1
 * \param nro2 Numero 2
 * \param nro3 Numero 3
 * \return int
 *
 */
int buscarMayorDe3(nro1,nro2,nro3)
{
    int max;

        if(nro1 > nro2)
        {
            if(nro1 > nro3)
                max = nro1;
            else
                max = nro3;
        }
        else
            if (nro2 > nro3)
                max = nro2;
            else
                max = nro3;

        return max;

}






/*******************************************************************************************
FUNCIONES DE VISUALIZACION
*******************************************************************************************/
/** \brief Imprime el menu principal
 *
 * \return void
 *
 */
void imprimoMenu()
{
        imprimirTitulo("MENU");
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






