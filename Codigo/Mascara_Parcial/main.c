#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"


#define QTY_PERS 20


/*****************************************************************************/
//Se que debemos poner las funciones en las librerias pero las funciones que 
//devuelven float no lo devuelven correctamente al estar en librerias.
float getFloat(char mensaje[]);
float pedirDatoFloatValido(char mensaje[]);
/*******************************************************************/

int main()
{
	char exit = 'n', option;
	
	
    while(exit=='n')
    {
        printMenu();
        scanf("%d",&option);	

        switch(opcion)
        {
            case 1: 
			printTitle("ALTA");
			//Validar si hay espacio
			//Pedir Dato nombre o ID
			//ValidarDatoIngresado
			//Pedir Datos Nvos y dar de alta
			break;
			
			case 2:
			printTitle("BAJA");
			//Pedir id o nombre
			//Vaidar existencia
			//Mostrar
			//Preguntar si da de baja
			//Baja Logica
			
			case 3:
			printTitle("MODIFICACION");
			//Pido dato
			//Valido Existencia
			//Muestro 
			//Pido datos nuevos.
			//Guardo datos nvos
			case 0://salir
				exit = 'y';
				break
			
		}
		if(option != 0)
			system("pause"); 
	}
	return 0;
}



/*******************************************************************************
FUNCIONES QUE RETORNAN FLOAT SE DEJAN EN EL MAIN PORQUE TIENEN INCONVENIENTES DESDE LIBRERIA
********************************************************************************/

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Mensaje para pedir el dato
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/** \brief Pide un dato float hasta que sea correcto
 *
 * \param mensaje[] char Mensaje con el que solicita el dato
 * \return float cadena convertida a float
 *
 */
float pedirDatoFloatValido(char mensaje[])
{
    int valido;
    char dato[200];

    pedirDato(mensaje, dato);
    valido = esNumericoFlotante(dato);
    while(valido == 0)
    {
        pedirDato("Error debe ser numero. Por favor reingresar: ", dato);
        valido = esNumericoFlotante(dato);
    }

    return strtof(dato, NULL );
}
