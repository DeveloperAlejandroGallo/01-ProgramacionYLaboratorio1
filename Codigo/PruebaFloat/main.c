#include <stdio.h>
#include <stdlib.h>
#include "datos.h"

//Se que debemos poner las funciones en las librerias pero las funciones q devuelven float no lo devuelven correctamente al estar en librerias.
//Se declara en el Main ya que el float tiene inconvenientes al estar en una libreria.
float getFloat(char mensaje[]);
int esNumericoFlotante(char str[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);
float pedirDatoFloatValido(char mensaje[]);




int main()
{
    float nro;
    nro = pedirDatoFloatValido("Ingrese un nro float: ");
    printf("\nEl nro es %f",nro);
    system("pause");
    return 0;
}






/*******************************************************************************
FUNCIONES DE VALIDACION DE FLOAT SE DEJAN EN EL MAIN PORQUE TIENEN INCONVENINETES DESDE LIBRERIA
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
