#include <stdio.h>
//#include "AleGalloLib.h"

/** \brief  Suma 2 enteros
 *
 * \param Primer Operando a Sumar
 * \param Segundo Operando a Sumar
 * \return Retorna la suma de los parametros.
 *
 */
int sumar(int n1, int n2);

/** \brief  Resta 2 enteros
 *
 * \param Primer Operando a restar
 * \param Segundo Operando a restar
 * \return Retorna la resta de los parametros
 *
 */
int restar(int n1, int n2);

/** \brief  Divide el Primer entero por el segundo. Retorna 0 y un mensaje de error si el Divisor es 0.
 *
 * \param Primer Operando - Dividendo
 * \param Segundo Operando  - Divisor
 * \return Retorna la division (float), entre el Primer Operando y el Segundo
 *
 */
float dividir(int nro1, int nro2);

/** \brief  Multiplica 2 Enteros
 *
 * \param Primer Operando a multiplicar
 * \param Segundo Operando a multiplicar
 * \return Devuelve la multiplicacion entre el Primer y segundo operando
 *
 */
int multiplicar(int nro1, int nro2);

/** \brief Devuelve el Factorial de un entero.
 *
 * \param Operando a factorizar
 * \return Retorna la factorizacion del nro ingresado
 *
 */
int factorial(int nro);

/** \brief Obtiene un entero por teclado.
 *
 * \return Retorna el nro obtenido por teclado.
 *
 */
int obtenerNro();

/** \brief  devuelve el mayor int de un array.
 *
 * \param Array a analizar
 * \param Tamaño del array
 * \return Retorne el mayor entero.
 *
 */
int mayorDeUnArrayInt(int array[], int size);

/** \brief  devuelve el menor int de un array.
 *
 * \param Array a analizar
 * \param Tamaño del array
 * \return Retorne el menor entero.
 *
 */
int mayorDeUnArrayInt(int vector[], int posiciones);

/** \brief  Ordena un Array en el orden solicitado.
 *
 * \param Array a Ordenar
 * \param Tamaño del array
 * \param Orden solicitado: '>' o '<'
 * \return Sin retorno
 *
 */
void bubbleSort(int vect[], int posiciones, char orden);
/**************************************************************************************************/
//Implementacion
/**************************************************************************************************/


int sumar(int n1, int n2)
{
    return n1 + n2;
}

int restar(int n1, int n2)
{
    return n1 - n2;
}

float dividir(int nro1, int nro2)
{
    if(nro2 == 0)
    {
        printf("No se puede dividir por CERO!!!\n");
        return 0.0;
    }
    return (float)nro1 / (float)nro2;

}

int multiplicar(int nro1, int nro2)
{
    return nro1 * nro2;
}

int factorial(int nro)
{
    if(nro==0)
        return 1;
    else
        return nro * factorial(nro-1);
}

int obtenerNro()
{
	int nro;
	fflush(stdin);
	scanf("%d",&nro);

	return nro;
}


int mayorDeUnArrayInt(int vector[], int posiciones)
{
    int mayor, i=0;

    mayor = array[0];

    if(array[0] > mayor)
        mayor = array[0];
}


int menorDeUnArrayInt(int vector[], int posiciones)
{
    int menor, i=0;

    menor = vector[0];
    for(i=0;i<posiciones;i++)
    {

        if(vector[0] < menor)
            menor = vector[0];
    }

    return menor;
}

void bubbleSort(int vect[], int size, char orden)
{
    int i,j,aux;

    if(orden == '>')
    {
        for(i=1;i<size;i++)
        {
            for(j=0;j<size - i;i++)
            {
                if(orden == '>') // Ordenamiento de Mayor a menor
                {
                    if(vect[j] > vect[j+1])
                    {
                        aux = vect[j];
                        vect[j] = vect[j+1];
                        vect[j+1]=aux;
                    }
                }
                else if (orden == '<') // Ordenamiento de menor a mayor
                {
                    if(vect[j] < vect[j+1])
                    {
                        aux = vect[j];
                        vect[j] = vect[j+1];
                        vect[j+1]=aux;
                    }
                }
            }
        }

    }

}




